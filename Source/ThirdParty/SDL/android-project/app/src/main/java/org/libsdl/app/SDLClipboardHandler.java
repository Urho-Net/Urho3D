package org.libsdl.app;

import java.io.IOException;
import java.io.InputStream;
import java.util.Hashtable;
import java.lang.reflect.Method;
import java.lang.Math;
import java.util.List;

public interface SDLClipboardHandler {

    public boolean clipboardHasText();
    public String clipboardGetText();
    public void clipboardSetText(String string);

}