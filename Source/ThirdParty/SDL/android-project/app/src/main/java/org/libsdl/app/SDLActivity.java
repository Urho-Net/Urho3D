// Modified by Lasse Oorni and Yao Wei Tjong for Urho3D

package org.libsdl.app;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.lang.reflect.Method;

import android.app.*;
import android.content.*;
import android.text.InputType;
import android.view.*;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputMethodManager;
import android.widget.RelativeLayout;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.os.*;
import android.util.Log;
import android.util.SparseArray;
import android.graphics.*;
import android.graphics.drawable.Drawable;
import android.media.*;
import android.hardware.*;
import android.content.pm.ActivityInfo;
import android.util.DisplayMetrics;

/**
 SDL Activity
 */
public class SDLActivity {
    private static final String TAG = "SDL";

    // Keep track of the paused state
    public static boolean mIsPaused, mIsSurfaceReady, mHasFocus;
    public static boolean mExitCalledFromJava;

    // If we want to separate mouse and touch events.
    //  This is only toggled in native code when a hint is set!
    public static boolean mSeparateMouseAndTouch;

    // Main components
    protected static Activity mSingleton;
    protected static SDLSurface mSurface;
    protected static View mTextEdit;
    protected static ViewGroup mLayout;

    // This is what SDL runs in. It invokes SDL_main(), eventually
    protected static Thread mSDLThread;


    // Urho3D: flag to load the .so and a new method load them
    private static boolean mIsSharedLibraryLoaded = false;

    // Urho3D - avoid hardcoding of the library list
    protected void onLoadLibrary(List<String> libraryNames) {
        for (final String name : libraryNames) {
            SDL.loadLibrary(name);
        }
        // mMainSharedLib = "lib" + libraryNames.get(libraryNames.size() - 1) + ".so";
    }

    public static void initialize() {
        // The static nature of the singleton and Android quirkyness force us to initialize everything here
        // Otherwise, when exiting the app and returning to it, these variables *keep* their pre exit values
        Log.v(TAG, "initialize");
        mSingleton = null;
        mSurface = null;
        mTextEdit = null;
        mLayout = null;
        mSDLThread = null;
        mExitCalledFromJava = false;
        mIsPaused = false;
        mIsSurfaceReady = false;
        mHasFocus = true;
    }

    public static SDLSurface createSurface(Activity activity) {
        Log.v(TAG, "createSurface()");
        SDL.initialize();
        mSingleton = activity;

        if (!mIsSharedLibraryLoaded) {
            System.loadLibrary("Urho3D");
            mIsSharedLibraryLoaded = true;

            SDL.setupJNI();
        }

        // Set up the surface
        mSurface = new SDLSurface(activity.getApplication());

        return mSurface;
    }

        /**
     * This method is called by SDL using JNI.
     */
    public static void setSurfaceViewFormat(int format) {}

     /**
     * This method is called by SDL using JNI.
     */
    public static void setWindowStyle(boolean fullscreen) {}

       /**
     * This method is called by SDL using JNI.
     * This is a static method for JNI convenience, it calls a non-static method
     * so that is can be overridden
     */
    public static void setOrientation(int w, int h, boolean resizable, String hint)
    {
        setOrientationBis(w, h, resizable, hint);
    }

    /**
     * This can be overridden
     */
    public static void setOrientationBis(int w, int h, boolean resizable, String hint)
    {
        int orientation = -1;

        if (hint.contains("LandscapeRight") && hint.contains("LandscapeLeft")) {
            orientation = ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE;
        } else if (hint.contains("LandscapeRight")) {
            orientation = ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE;
        } else if (hint.contains("LandscapeLeft")) {
            orientation = ActivityInfo.SCREEN_ORIENTATION_REVERSE_LANDSCAPE;
        } else if (hint.contains("Portrait") && hint.contains("PortraitUpsideDown")) {
            orientation = ActivityInfo.SCREEN_ORIENTATION_SENSOR_PORTRAIT;
        } else if (hint.contains("Portrait")) {
            orientation = ActivityInfo.SCREEN_ORIENTATION_PORTRAIT;
        } else if (hint.contains("PortraitUpsideDown")) {
            orientation = ActivityInfo.SCREEN_ORIENTATION_REVERSE_PORTRAIT;
        }

        /* no valid hint */
        if (orientation == -1) {
            if (resizable) {
                /* no fixed orientation */
            } else {
                if (w > h) {
                    orientation = ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE;
                } else {
                    orientation = ActivityInfo.SCREEN_ORIENTATION_SENSOR_PORTRAIT;
                }
            }
        }

        Log.v(TAG, "setOrientation() orientation=" + orientation + " width=" + w +" height="+ h +" resizable=" + resizable + " hint=" + hint);
        if (orientation != -1) {
            mSingleton.setRequestedOrientation(orientation);
        }
    }

      /**
     * This method is called by SDL using JNI.
     */
    public static void minimizeWindow() {}

      /**
     * This method is called by SDL using JNI.
     */
    public static boolean shouldMinimizeOnFocusLoss() {
        return false;
    }

          /**
     * This method is called by SDL using JNI.
     */
    public static boolean isScreenKeyboardShown()
    {
        return false;
    }

       /**
     * This method is called by SDL using JNI.
     */
    public static boolean supportsRelativeMouse()
    {
        return false;
    }

        /**
     * This method is called by SDL using JNI.
     */
    public static boolean setRelativeMouseEnabled(boolean enabled)
    {
        return true;
    }

       /**
     * This method is called by SDL using JNI.
     */
    public static boolean isAndroidTV() {
        // UiModeManager uiModeManager = (UiModeManager) getContext().getSystemService(UI_MODE_SERVICE);
        // if (uiModeManager.getCurrentModeType() == Configuration.UI_MODE_TYPE_TELEVISION) {
        //     return true;
        // }
        // if (Build.MANUFACTURER.equals("MINIX") && Build.MODEL.equals("NEO-U1")) {
        //     return true;
        // }
        // if (Build.MANUFACTURER.equals("Amlogic") && Build.MODEL.equals("X96-W")) {
        //     return true;
        // }
        return false;
    }

       /**
     * This method is called by SDL using JNI.
     */
    public static boolean isTablet() {
        // DisplayMetrics metrics = new DisplayMetrics();
        // Activity activity = (Activity)getContext();
        // activity.getWindowManager().getDefaultDisplay().getMetrics(metrics);

        // double dWidthInches = metrics.widthPixels / (double)metrics.xdpi;
        // double dHeightInches = metrics.heightPixels / (double)metrics.ydpi;

        // double dDiagonal = Math.sqrt((dWidthInches * dWidthInches) + (dHeightInches * dHeightInches));

        // // If our diagonal size is seven inches or greater, we consider ourselves a tablet.
        // return (dDiagonal >= 7.0);
        return false;
    }

      // Called by JNI from SDL.
      public static void manualBackButton() {}

    /**
     * This method is called by SDL using JNI.
     */
    public static void initTouch() {}
       /**
     * This method is called by SDL using JNI.
     */
    public static boolean isChromebook() {
        return false;
    }

        /**
     * This method is called by SDL using JNI.
     */
    public static boolean clipboardHasText() {
        return false;
    }

    /**
     * This method is called by SDL using JNI.
     */
    public static String clipboardGetText() {
        return "";
    }

    /**
     * This method is called by SDL using JNI.
     */
    public static void clipboardSetText(String string) {
    }

        /**
     * This method is called by SDL using JNI.
     */
    public static boolean getManifestEnvironmentVariables() {
        return true;
    }

      /**
     * This method is called by SDL using JNI.
     */
    public static DisplayMetrics getDisplayDPI() {
        return getContext().getResources().getDisplayMetrics();
    }

       /**
     * This method is called by SDL using JNI.
     */
    public static int createCustomCursor(int[] colors, int width, int height, int hotSpotX, int hotSpotY) {
        return 1;
    }

       /**
     * This method is called by SDL using JNI.
     */
    public static boolean setCustomCursor(int cursorID) {
        return true;
    }

       /**
     * This method is called by SDL using JNI.
     */
    public static boolean setSystemCursor(int cursorID) {
        return true;
    }
     /**
     * This method is called by SDL using JNI.
     */
    public static boolean isDeXMode() {
        return true;
    }

    // This method is called by SDLControllerManager's API 26 Generic Motion Handler.
    public static View getContentView()
    {
        return null;
    }


    /**
     * This method is called by SDL before starting the native application thread.
     * It can be overridden to provide the arguments after the application name.
     * The default implementation returns an empty array. It never returns null.
     * @return arguments for the native application.
     */
    protected String[] getArguments() {
        // Urho3D - the default implementation returns the "app_process" as the first argument instead of empty array
        return new String[]{"app_process"};
    }

    // Events
    public static void onPause() {
        Log.v(TAG, "onPause()");

        if (!SDLActivity.mIsSharedLibraryLoaded) {  // Urho3D
            return;
        }

        SDLActivity.handlePause();
    }

    public static void onResume() {
        Log.v(TAG, "onResume()");

        if (!SDLActivity.mIsSharedLibraryLoaded) {  // Urho3D
            return;
        }

        SDLActivity.handleResume();
    }


    public static void onWindowFocusChanged(boolean hasFocus) {
        Log.v(TAG, "onWindowFocusChanged(): " + hasFocus);

        if (!SDLActivity.mIsSharedLibraryLoaded) {  // Urho3D
            return;
        }

        SDLActivity.mHasFocus = hasFocus;
        if (hasFocus) {
            SDLActivity.handleResume();
        }
    }

    public static void onLowMemory() {
        Log.v(TAG, "onLowMemory()");

        if (!SDLActivity.mIsSharedLibraryLoaded) {  // Urho3D
            return;
        }

        SDLActivity.nativeLowMemory();
    }

    public static void onDestroy() {
        Log.v(TAG, "onDestroy()");

        SDLActivity.mExitCalledFromJava = true;


        if (!SDLActivity.mIsSharedLibraryLoaded) {  // Urho3D
            return;
        }

        if (SDLActivity.mSDLThread != null) {

            // Send Quit event to "SDLThread" thread
            SDLActivity.nativeSendQuit();

            // Wait for "SDLThread" thread to end
            try {
                SDLActivity.mSDLThread.join();
            } catch(Exception e) {
                Log.v(TAG, "Problem stopping SDLThread: " + e);
            }
        }

        SDLActivity.nativeQuit();
        // Reset everything in case the user re opens the app
        SDLActivity.initialize();
     
    }

    public static boolean dispatchKeyEvent(KeyEvent event) {

        if (!SDLActivity.mIsSharedLibraryLoaded) {  // Urho3D
            return false;
        }

        int keyCode = event.getKeyCode();
        // Ignore certain special keys so they're handled by Android
        // Urho3D: also ignore the Home key
        if (keyCode == KeyEvent.KEYCODE_VOLUME_DOWN ||
                keyCode == KeyEvent.KEYCODE_VOLUME_UP ||
                keyCode == KeyEvent.KEYCODE_HOME ||
                keyCode == KeyEvent.KEYCODE_CAMERA ||
                keyCode == 168 || /* API 11: KeyEvent.KEYCODE_ZOOM_IN */
                keyCode == 169 /* API 11: KeyEvent.KEYCODE_ZOOM_OUT */
                ) {
            return false;
        }
        return true;
    }

    /** Called by onPause or surfaceDestroyed. Even if surfaceDestroyed
     *  is the first to be called, mIsSurfaceReady should still be set
     *  to 'true' during the call to onPause (in a usual scenario).
     */
    public static void handlePause() {
        if (!SDLActivity.mIsPaused && SDLActivity.mIsSurfaceReady) {
            SDLActivity.mIsPaused = true;
            SDLActivity.nativePause();
            mSurface.handlePause();
        }
    }

    /** Called by onResume or surfaceCreated. An actual resume should be done only when the surface is ready.
     * Note: Some Android variants may send multiple surfaceChanged events, so we don't need to resume
     * every time we get one of those events, only if it comes after surfaceDestroyed
     */
    public static void handleResume() {
        if (SDLActivity.mIsPaused && SDLActivity.mIsSurfaceReady && SDLActivity.mHasFocus) {
            SDLActivity.mIsPaused = false;
            SDLActivity.nativeResume();
            mSurface.handleResume();
        }
    }
    /* The native thread has finished */
    public static void handleNativeExit() throws Exception {
        SDLActivity.mSDLThread = null;
        Log.d(TAG, "handleNativeExit");
        if (mSingleton != null && FinishActivityOnNativeExit){
            mSingleton.finish();
        }
    }

    public static boolean FinishActivityOnNativeExit = true;

    // Messages from the SDLMain thread
    static final int COMMAND_CHANGE_TITLE = 1;
    static final int COMMAND_UNUSED = 2;
    static final int COMMAND_TEXTEDIT_HIDE = 3;
    static final int COMMAND_SET_KEEP_SCREEN_ON = 5;

    protected static final int COMMAND_USER = 0x8000;

    /**
     * This method is called by SDL if SDL did not handle a message itself.
     * This happens if a received message contains an unsupported command.
     * Method can be overwritten to handle Messages in a different class.
     * @param command the command of the message.
     * @param param the parameter of the message. May be null.
     * @return if the message was handled in overridden method.
     */
    protected boolean onUnhandledMessage(int command, Object param) {
        return false;
    }

    /**
     * A Handler class for Messages from native SDL applications.
     * It uses current Activities as target (e.g. for the title).
     * static to prevent implicit references to enclosing object.
     */
    protected static class SDLCommandHandler extends Handler {
        @Override
        public void handleMessage(Message msg) {
            Context context = getContext();
            if (context == null) {
                Log.e(TAG, "error handling message, getContext() returned null");
                return;
            }
            switch (msg.arg1) {
                case COMMAND_CHANGE_TITLE:
                    if (context instanceof Activity) {
                        ((Activity) context).setTitle((String)msg.obj);
                    } else {
                        Log.e(TAG, "error handling message, getContext() returned no Activity");
                    }
                    break;
                case COMMAND_TEXTEDIT_HIDE:
                    if (mTextEdit != null) {
                        mTextEdit.setVisibility(View.GONE);

                        InputMethodManager imm = (InputMethodManager) context.getSystemService(Context.INPUT_METHOD_SERVICE);
                        imm.hideSoftInputFromWindow(mTextEdit.getWindowToken(), 0);
                    }
                    break;
                case COMMAND_SET_KEEP_SCREEN_ON:
                {
                    Window window = ((Activity) context).getWindow();
                    if (window != null) {
                        if ((msg.obj instanceof Integer) && (((Integer) msg.obj).intValue() != 0)) {
                            window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
                        } else {
                            window.clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
                        }
                    }
                    break;
                }
                default:
                    Log.e(TAG, "error handling message, command is " + msg.arg1);
            }
        }
    }

    // Handler for the messages
    static Handler commandHandler = new SDLCommandHandler();

    // Send a message from the SDLMain thread
    public static boolean sendCommand(int command, Object data) {
        Message msg = commandHandler.obtainMessage();
        msg.arg1 = command;
        msg.obj = data;
        return commandHandler.sendMessage(msg);
    }

    // C functions we call
    // Urho3D: added parameter
    public static native int nativeSetupJNI();
    public static native int nativeInit(Object arguments, String filesDir);
    public static native void nativeLowMemory();
    public static native void nativeSendQuit();
    public static native void nativeQuit();
    public static native void nativePause();
    public static native void nativeResume();
    public static native void onNativeDropFile(String filename);
    public static native void nativeSetScreenResolution(int surfaceWidth, int surfaceHeight, int deviceWidth, int deviceHeight, int format, float rate);
    public static native void onNativeResize();
    // TBD ELI public static native void onNativeResize(int x, int y, int format, float rate);
    public static native int onNativePadDown(int device_id, int keycode);
    public static native int onNativePadUp(int device_id, int keycode);
    public static native void onNativeJoy(int device_id, int axis,
                                          float value);
    public static native void onNativeHat(int device_id, int hat_id,
                                          int x, int y);
    public static native void onNativeKeyDown(int keycode);
    public static native void onNativeKeyUp(int keycode);
    public static native void onNativeKeyboardFocusLost();
    public static native void onNativeMouse(int button, int action, float x, float y,boolean b);
    public static native void onNativeTouch(int touchDevId, int pointerFingerId,
                                            int action, float x,
                                            float y, float p);
    public static native void onNativeAccel(float x, float y, float z);
    public static native void onNativeSurfaceChanged();
    public static native void onNativeSurfaceDestroyed();
    public static native int nativeAddJoystick(int device_id, String name,
                                               int is_accelerometer, int nbuttons,
                                               int naxes, int nhats, int nballs);
    public static native int nativeRemoveJoystick(int device_id);
    public static native String nativeGetHint(String name);

    /**
     * This method is called by SDL using JNI.
     */
    public static boolean setActivityTitle(String title) {
        // Called from SDLMain() thread and can't directly affect the view
        return true; //  SDLActivity.sendCommand(COMMAND_CHANGE_TITLE, title);
    }

    /**
     * This method is called by SDL using JNI.
     */
    public static boolean sendMessage(int command, int param) {
        return true; //  SDLActivity.sendCommand(command, Integer.valueOf(param));
    }

    /**
     * This method is called by SDL using JNI.
     */
    public static Context getContext() {
        return mSingleton;
    }

    /**
     * This method is called by SDL using JNI.
     * @return result of getSystemService(name) but executed on UI thread.
     */
    public Object getSystemServiceFromUiThread(final String name) {
        final Object lock = new Object();
        final Object[] results = new Object[2]; // array for writable variables
        synchronized (lock) {
            mSingleton.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    synchronized (lock) {
                        results[0] = mSingleton.getSystemService(name);
                        results[1] = Boolean.TRUE;
                        lock.notify();
                    }
                }
            });
            if (results[1] == null) {
                try {
                    lock.wait();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        }
        return results[0];
    }

    static class ShowTextInputTask implements Runnable {
        /*
         * This is used to regulate the pan&scan method to have some offset from
         * the bottom edge of the input region and the top edge of an input
         * method (soft keyboard)
         */
        static final int HEIGHT_PADDING = 15;

        public int x, y, w, h;

        public ShowTextInputTask(int x, int y, int w, int h) {
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
        }

        @Override
        public void run() {
            RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(w, h + HEIGHT_PADDING);
            params.leftMargin = x;
            params.topMargin = y;

            if (mTextEdit == null) {
                ViewParent parent = mSurface.getParent();
                if (parent instanceof ViewGroup){
                    mTextEdit = new DummyEdit(getContext());
                    ((ViewGroup)parent).addView(mTextEdit, params);
                } else {
                    return;
                }
            } else {
                mTextEdit.setLayoutParams(params);
            }

            mTextEdit.setVisibility(View.VISIBLE);
            mTextEdit.requestFocus();

            InputMethodManager imm = (InputMethodManager) getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
            imm.showSoftInput(mTextEdit, 0);
        }
    }

    /**
     * This method is called by SDL using JNI.
     */
    public static boolean showTextInput(int x, int y, int w, int h) {
        // Transfer the task to the main thread as a Runnable
        return SDLActivity.commandHandler.post(new ShowTextInputTask(x, y, w, h));
    }

    /**
     * This method is called by SDL using JNI.
     */
    public static Surface getNativeSurface() {
        return SDLActivity.mSurface.getNativeSurface();
    }



    // Input

    /**
     * This method is called by SDL using JNI.
     * @return an array which may be empty but is never null.
     */
    public static int[] inputGetInputDeviceIds(int sources) {
        int[] ids = InputDevice.getDeviceIds();
        int[] filtered = new int[ids.length];
        int used = 0;
        for (int i = 0; i < ids.length; ++i) {
            InputDevice device = InputDevice.getDevice(ids[i]);
            if ((device != null) && ((device.getSources() & sources) != 0)) {
                filtered[used++] = device.getId();
            }
        }
        return Arrays.copyOf(filtered, used);
    }

    // APK expansion files support

    /** com.android.vending.expansion.zipfile.ZipResourceFile object or null. */
    private static Object expansionFile;

    /** com.android.vending.expansion.zipfile.ZipResourceFile's getInputStream() or null. */
    private static Method expansionFileMethod;

    /**
     * This method was called by SDL using JNI.
     * @deprecated because of an incorrect name
     */
    @Deprecated
    public InputStream openAPKExtensionInputStream(String fileName) throws IOException {
        return openAPKExpansionInputStream(fileName);
    }

    /**
     * This method is called by SDL using JNI.
     * @return an InputStream on success or null if no expansion file was used.
     * @throws IOException on errors. Message is set for the SDL error message.
     */
    public static InputStream openAPKExpansionInputStream(String fileName) throws IOException {
        // Get a ZipResourceFile representing a merger of both the main and patch files
        if (expansionFile == null) {
            String mainHint = nativeGetHint("SDL_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION");
            if (mainHint == null) {
                return null; // no expansion use if no main version was set
            }
            String patchHint = nativeGetHint("SDL_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION");
            if (patchHint == null) {
                return null; // no expansion use if no patch version was set
            }

            Integer mainVersion;
            Integer patchVersion;
            try {
                mainVersion = Integer.valueOf(mainHint);
                patchVersion = Integer.valueOf(patchHint);
            } catch (NumberFormatException ex) {
                ex.printStackTrace();
                throw new IOException("No valid file versions set for APK expansion files", ex);
            }

            try {
                // To avoid direct dependency on Google APK expansion library that is
                // not a part of Android SDK we access it using reflection
                expansionFile = Class.forName("com.android.vending.expansion.zipfile.APKExpansionSupport")
                        .getMethod("getAPKExpansionZipFile", Context.class, int.class, int.class)
                        .invoke(null, mSingleton, mainVersion, patchVersion);

                expansionFileMethod = expansionFile.getClass()
                        .getMethod("getInputStream", String.class);
            } catch (Exception ex) {
                ex.printStackTrace();
                expansionFile = null;
                expansionFileMethod = null;
                throw new IOException("Could not access APK expansion support library", ex);
            }
        }

        // Get an input stream for a known file inside the expansion file ZIPs
        InputStream fileStream;
        try {
            fileStream = (InputStream)expansionFileMethod.invoke(expansionFile, fileName);
        } catch (Exception ex) {
            // calling "getInputStream" failed
            ex.printStackTrace();
            throw new IOException("Could not open stream from APK expansion file", ex);
        }

        if (fileStream == null) {
            // calling "getInputStream" was successful but null was returned
            throw new IOException("Could not find path in APK expansion file");
        }

        return fileStream;
    }

    // Messagebox

    /** Result of current messagebox. Also used for blocking the calling thread. */
    protected final int[] messageboxSelection = new int[1];

    /** Id of current dialog. */
    protected int dialogs = 0;

    /**
     * This method is called by SDL using JNI.
     * Shows the messagebox from UI thread and block calling thread.
     * buttonFlags, buttonIds and buttonTexts must have same length.
     * @param buttonFlags array containing flags for every button.
     * @param buttonIds array containing id for every button.
     * @param buttonTexts array containing text for every button.
     * @param colors null for default or array of length 5 containing colors.
     * @return button id or -1.
     */
    public int messageboxShowMessageBox(
            final int flags,
            final String title,
            final String message,
            final int[] buttonFlags,
            final int[] buttonIds,
            final String[] buttonTexts,
            final int[] colors) {

        messageboxSelection[0] = -1;

        // sanity checks

        if ((buttonFlags.length != buttonIds.length) && (buttonIds.length != buttonTexts.length)) {
            return -1; // implementation broken
        }

        // collect arguments for Dialog

        final Bundle args = new Bundle();
        args.putInt("flags", flags);
        args.putString("title", title);
        args.putString("message", message);
        args.putIntArray("buttonFlags", buttonFlags);
        args.putIntArray("buttonIds", buttonIds);
        args.putStringArray("buttonTexts", buttonTexts);
        args.putIntArray("colors", colors);

        // trigger Dialog creation on UI thread

        mSingleton.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mSingleton.showDialog(dialogs++, args);
            }
        });

        // block the calling thread

        synchronized (messageboxSelection) {
            try {
                messageboxSelection.wait();
            } catch (InterruptedException ex) {
                ex.printStackTrace();
                return -1;
            }
        }

        // return selected value

        return messageboxSelection[0];
    }

    protected Dialog onCreateDialog(int ignore, Bundle args) {

        // TODO set values from "flags" to messagebox dialog

        // get colors

        int[] colors = args.getIntArray("colors");
        int backgroundColor;
        int textColor;
        int buttonBorderColor;
        int buttonBackgroundColor;
        int buttonSelectedColor;
        if (colors != null) {
            int i = -1;
            backgroundColor = colors[++i];
            textColor = colors[++i];
            buttonBorderColor = colors[++i];
            buttonBackgroundColor = colors[++i];
            buttonSelectedColor = colors[++i];
        } else {
            backgroundColor = Color.TRANSPARENT;
            textColor = Color.TRANSPARENT;
            buttonBorderColor = Color.TRANSPARENT;
            buttonBackgroundColor = Color.TRANSPARENT;
            buttonSelectedColor = Color.TRANSPARENT;
        }

        // create dialog with title and a listener to wake up calling thread

        final Dialog dialog = new Dialog(mSingleton);
        dialog.setTitle(args.getString("title"));
        dialog.setCancelable(false);
        dialog.setOnDismissListener(new DialogInterface.OnDismissListener() {
            @Override
            public void onDismiss(DialogInterface unused) {
                synchronized (messageboxSelection) {
                    messageboxSelection.notify();
                }
            }
        });

        // create text

        TextView message = new TextView(mSingleton);
        message.setGravity(Gravity.CENTER);
        message.setText(args.getString("message"));
        if (textColor != Color.TRANSPARENT) {
            message.setTextColor(textColor);
        }

        // create buttons

        int[] buttonFlags = args.getIntArray("buttonFlags");
        int[] buttonIds = args.getIntArray("buttonIds");
        String[] buttonTexts = args.getStringArray("buttonTexts");

        final SparseArray<Button> mapping = new SparseArray<Button>();

        LinearLayout buttons = new LinearLayout(mSingleton);
        buttons.setOrientation(LinearLayout.HORIZONTAL);
        buttons.setGravity(Gravity.CENTER);
        for (int i = 0; i < buttonTexts.length; ++i) {
            Button button = new Button(mSingleton);
            final int id = buttonIds[i];
            button.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    messageboxSelection[0] = id;
                    dialog.dismiss();
                }
            });
            if (buttonFlags[i] != 0) {
                // see SDL_messagebox.h
                if ((buttonFlags[i] & 0x00000001) != 0) {
                    mapping.put(KeyEvent.KEYCODE_ENTER, button);
                }
                if ((buttonFlags[i] & 0x00000002) != 0) {
                    mapping.put(111, button); /* API 11: KeyEvent.KEYCODE_ESCAPE */
                }
            }
            button.setText(buttonTexts[i]);
            if (textColor != Color.TRANSPARENT) {
                button.setTextColor(textColor);
            }
            if (buttonBorderColor != Color.TRANSPARENT) {
                // TODO set color for border of messagebox button
            }
            if (buttonBackgroundColor != Color.TRANSPARENT) {
                Drawable drawable = button.getBackground();
                if (drawable == null) {
                    // setting the color this way removes the style
                    button.setBackgroundColor(buttonBackgroundColor);
                } else {
                    // setting the color this way keeps the style (gradient, padding, etc.)
                    drawable.setColorFilter(buttonBackgroundColor, PorterDuff.Mode.MULTIPLY);
                }
            }
            if (buttonSelectedColor != Color.TRANSPARENT) {
                // TODO set color for selected messagebox button
            }
            buttons.addView(button);
        }

        // create content

        LinearLayout content = new LinearLayout(mSingleton);
        content.setOrientation(LinearLayout.VERTICAL);
        content.addView(message);
        content.addView(buttons);
        if (backgroundColor != Color.TRANSPARENT) {
            content.setBackgroundColor(backgroundColor);
        }

        // add content to dialog and return

        dialog.setContentView(content);
        dialog.setOnKeyListener(new Dialog.OnKeyListener() {
            @Override
            public boolean onKey(DialogInterface d, int keyCode, KeyEvent event) {
                Button button = mapping.get(keyCode);
                if (button != null) {
                    if (event.getAction() == KeyEvent.ACTION_UP) {
                        button.performClick();
                    }
                    return true; // also for ignored actions
                }
                return false;
            }
        });

        return dialog;
    }
}

/**
 Simple nativeInit() runnable
 */
class SDLMain implements Runnable {
    @Override
    public void run() {
        // Runs SDL_main()
        // Urho3D: pass filesDir
        String path = ((Activity)SDLActivity.getContext()).getFilesDir().getAbsolutePath();
        Log.v("SDLMain", "Init with path: " + path);
        SDLActivity.nativeInit(new String[]{"app_process"}, path);
    }
}


/* This is a fake invisible editor view that receives the input and defines the
 * pan&scan region
 */
class DummyEdit extends View implements View.OnKeyListener {
    InputConnection ic;

    public DummyEdit(Context context) {
        super(context);
        setFocusableInTouchMode(true);
        setFocusable(true);
        setOnKeyListener(this);
    }

    @Override
    public boolean onCheckIsTextEditor() {
        return true;
    }

    @Override
    public boolean onKey(View v, int keyCode, KeyEvent event) {

        // This handles the hardware keyboard input
        // Urho3D: unite input with other platforms
        if (event.getAction() == KeyEvent.ACTION_DOWN) {
            SDLActivity.onNativeKeyDown(keyCode);
            ic.commitText(String.valueOf((char) event.getUnicodeChar()), 1);
        } else if (event.getAction() == KeyEvent.ACTION_UP) {
            SDLActivity.onNativeKeyUp(keyCode);
        }

        return true;
    }

    //
    @Override
    public boolean onKeyPreIme (int keyCode, KeyEvent event) {
        // As seen on StackOverflow: http://stackoverflow.com/questions/7634346/keyboard-hide-event
        // FIXME: Discussion at http://bugzilla.libsdl.org/show_bug.cgi?id=1639
        // FIXME: This is not a 100% effective solution to the problem of detecting if the keyboard is showing or not
        // FIXME: A more effective solution would be to change our Layout from AbsoluteLayout to Relative or Linear
        // FIXME: And determine the keyboard presence doing this: http://stackoverflow.com/questions/2150078/how-to-check-visibility-of-software-keyboard-in-android
        // FIXME: An even more effective way would be if Android provided this out of the box, but where would the fun be in that :)
        if (event.getAction()==KeyEvent.ACTION_UP && keyCode == KeyEvent.KEYCODE_BACK) {
            if (SDLActivity.mTextEdit != null && SDLActivity.mTextEdit.getVisibility() == View.VISIBLE) {
                SDLActivity.onNativeKeyboardFocusLost();
            }
        }
        return super.onKeyPreIme(keyCode, event);
    }

    @Override
    public InputConnection onCreateInputConnection(EditorInfo outAttrs) {
        ic = new SDLInputConnection(this, true);

        outAttrs.inputType = InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_VISIBLE_PASSWORD;
        outAttrs.imeOptions = EditorInfo.IME_FLAG_NO_EXTRACT_UI
                | 33554432 /* API 11: EditorInfo.IME_FLAG_NO_FULLSCREEN */;

        return ic;
    }
}

class SDLInputConnection extends BaseInputConnection {

    public SDLInputConnection(View targetView, boolean fullEditor) {
        super(targetView, fullEditor);

    }

    @Override
    public boolean sendKeyEvent(KeyEvent event) {

        /*
         * This handles the keycodes from soft keyboard (and IME-translated
         * input from hardkeyboard)
         */
        int keyCode = event.getKeyCode();
        if (event.getAction() == KeyEvent.ACTION_DOWN) {
            if (event.isPrintingKey() || keyCode == KeyEvent.KEYCODE_SPACE) {
                commitText(String.valueOf((char) event.getUnicodeChar()), 1);
            }
            SDLActivity.onNativeKeyDown(keyCode);
            return true;
        } else if (event.getAction() == KeyEvent.ACTION_UP) {

            SDLActivity.onNativeKeyUp(keyCode);
            return true;
        }
        return super.sendKeyEvent(event);
    }

    @Override
    public boolean commitText(CharSequence text, int newCursorPosition) {

        nativeCommitText(text.toString(), newCursorPosition);

        return super.commitText(text, newCursorPosition);
    }

    @Override
    public boolean setComposingText(CharSequence text, int newCursorPosition) {

        nativeSetComposingText(text.toString(), newCursorPosition);

        return super.setComposingText(text, newCursorPosition);
    }

    public native void nativeCommitText(String text, int newCursorPosition);

    public native void nativeSetComposingText(String text, int newCursorPosition);

    @Override
    public boolean deleteSurroundingText(int beforeLength, int afterLength) {
        // Workaround to capture backspace key. Ref: http://stackoverflow.com/questions/14560344/android-backspace-in-webview-baseinputconnection
        if (beforeLength == 1 && afterLength == 0) {
            // backspace
            return super.sendKeyEvent(new KeyEvent(KeyEvent.ACTION_DOWN, KeyEvent.KEYCODE_DEL))
                    && super.sendKeyEvent(new KeyEvent(KeyEvent.ACTION_UP, KeyEvent.KEYCODE_DEL));
        }

        return super.deleteSurroundingText(beforeLength, afterLength);
    }
}





