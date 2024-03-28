// Copyright (c) 2020-2021 Eli Aloni (A.K.A elix22).
// Copyright (c) 2008-2021 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


package com.urho3d.plugin;

import android.content.Context;
import org.libsdl.app.SDLActivity;
import java.io.File;
import java.util.Arrays;
import android.util.SparseArray;
import java.util.ArrayList;
import java.io.FilenameFilter;
import java.util.Comparator;
import android.os.Bundle;
import android.util.Log;
import android.app.Activity;
import android.os.Handler;
import android.os.Message;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.lang.reflect.*;
import java.lang.reflect.Method;  
import 	java.lang.Class;
import java.util.Arrays;
import java.util.List;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.OnUserEarnedRewardListener;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.google.android.gms.ads.rewarded.RewardItem;
import com.google.android.gms.ads.rewarded.RewardedAd;
import com.google.android.gms.ads.rewarded.RewardedAdLoadCallback;
import com.google.android.gms.ads.RequestConfiguration;

import android.widget.Toast;
import androidx.annotation.NonNull;

import android.app.Activity;
import com.github.urho3d.launcher.MainActivity;


public class AdmobPlugin
{
    private static final String TAG = "AdmobPlugin";

    private static AdmobPlugin singelton = null;

    private static final String AD_UNIT_ID = "ca-app-pub-3940256099942544/9793981313";

    private RewardedAd rewardedAd;
    boolean isLoading;

    boolean isInitialized = false;

    private  Activity urhoActivity;

    public static native void OnNativePluginEvent(String json);

    public static AdmobPlugin GetSingelton()
    {
        return singelton;
    }

    public static void LoadPlugin()
    {
       if(singelton == null)
       {
          singelton = new AdmobPlugin();
       }
    }

    protected  class AdmobPluginHandler extends Handler 
    {
      public void handleMessage(Message msg) {
          processCommand((String)msg.obj);
      }
    }

    Handler admobPluginHandler = null;

    static void postCommand(String data) 
    {
      AdmobPlugin admobPlugin = (AdmobPlugin)(AdmobPlugin.GetSingelton());
      if(admobPlugin != null && admobPlugin.admobPluginHandler != null)
      {
        if(admobPlugin.isInitialized == false)
        {
          admobPlugin.Initialize();
        }

        Message msg = admobPlugin.admobPluginHandler.obtainMessage();
        msg.obj = data;
        admobPlugin.admobPluginHandler.sendMessage(msg);
      }
      else if(admobPlugin != null)
      {
        try 
        {
            JSONObject js = new JSONObject(data);
            String methodName = js.getString("method");
            if(methodName.equals("Start"))
            {
              Method  method = AdmobPlugin.class.getDeclaredMethod(methodName,  JSONObject.class) ;
              if(method != null)
              {
                  method.setAccessible(true);
                  method.invoke(singelton, js);
              }
            }
            
        } catch (ClassCastException e) {
            Log.e(TAG, "onUnhandledMessage ClassCastException", e);
        } catch (JSONException e) {
            Log.e(TAG, "onUnhandledMessage JSONException", e);
        } catch (SecurityException e) {
            Log.e(TAG, "onUnhandledMessage SecurityException", e);
        } catch (Exception e) {
            Log.e(TAG, "onUnhandledMessage Exception", e);
        }
      }
    }

    private void processCommand(String data) 
    {
      try 
      {
          JSONObject js = new JSONObject(data);
          String methodName = js.getString("method");

          Method  method = AdmobPlugin.class.getDeclaredMethod(methodName,  JSONObject.class) ;
          if(method != null)
          {
              method.setAccessible(true);
              method.invoke(this, js);
          }

          
      } catch (ClassCastException e) {
          Log.e(TAG, "onUnhandledMessage ClassCastException", e);
      } catch (JSONException e) {
          Log.e(TAG, "onUnhandledMessage JSONException", e);
      } catch (SecurityException e) {
          Log.e(TAG, "onUnhandledMessage SecurityException", e);
      } catch (Exception e) {
          Log.e(TAG, "onUnhandledMessage Exception", e);
      }
    }


    private void OnPluginEvent(String source , String event, JSONObject params) {
        try {
            params.put("source", source);
            params.put("event", event);
            OnNativePluginEvent(params.toString());
        } catch (JSONException e) 
        {
            Log.e(TAG, "JSONException " + e);
        }
    }

    private void OnPluginEvent(String source, String event) {
        OnPluginEvent(source, event, new JSONObject());
    }

    public AdmobPlugin()
    {
        singelton = this;
        new Thread()
        {
            public void run()
            {
                urhoActivity = MainActivity.GetSingelton();

                urhoActivity.runOnUiThread(new Runnable()
                {
                    public void run()
                    {
                        admobPluginHandler = new AdmobPluginHandler();
                    }
                });
            }
        }.start();
    }

    void Start(JSONObject js)
    {
        Log.d(TAG,"AdmobPluginJava Start");
        singelton.Initialize(); 
    }

    public void Initialize()
    {
      if(isInitialized == false)
      {
        isInitialized = true;

        new Thread()
        {
            public void run()
            {
                urhoActivity = MainActivity.GetSingelton();

                urhoActivity.runOnUiThread(new Runnable()
                {
                    public void run()
                    {
                       
                        isLoading = false;

                        MobileAds.initialize(urhoActivity, new OnInitializationCompleteListener() {
                            @Override
                            public void onInitializationComplete(InitializationStatus initializationStatus) {
                              Log.d(TAG,"AdmobPluginJava onInitializationComplete :"+initializationStatus);
                              OnPluginEvent("AdmobPlugin", "OnStarted");
                            }
                          });
                    }
                });
            }
        }.start();
      }
    }

    public void loadRewardedAd(String adUnitId) {
        if (rewardedAd == null) {
          isLoading = true;
          AdRequest adRequest = new AdRequest.Builder().build();
          if(adUnitId.equals(""))
          {
            adUnitId = AD_UNIT_ID;
          }

         // Log.d(TAG, "loadRewardedAd("+adUnitId+")");

          RewardedAd.load(
              urhoActivity,
              adUnitId,
              adRequest,
              new RewardedAdLoadCallback() {
                @Override
                public void onAdFailedToLoad(@NonNull LoadAdError loadAdError) {
                  // Handle the error.
                  Log.d(TAG, loadAdError.getMessage());
                  rewardedAd = null;
                  AdmobPlugin.this.isLoading = false;
                  Log.d(TAG, "onAdFailedToLoad");
                 // Toast.makeText(urhoActivity, "onAdFailedToLoad", Toast.LENGTH_SHORT).show();

                  OnPluginEvent("AdmobPlugin", "onAdFailedToLoad");
                }
    
                @Override
                public void onAdLoaded(@NonNull RewardedAd rewardedAd) {
                  AdmobPlugin.this.rewardedAd = rewardedAd;
                  Log.d(TAG, "onAdLoaded");
                  AdmobPlugin.this.isLoading = false;
                 // Toast.makeText(urhoActivity, "onAdLoaded", Toast.LENGTH_SHORT).show();

                  OnPluginEvent("AdmobPlugin", "onAdLoaded");
                }
              });
        }
    }

    public void showRewardedVideo() 
    {

        if (rewardedAd == null) {
          Log.d(TAG, "The rewarded ad wasn't ready yet.");
          return;
        }

        rewardedAd.setFullScreenContentCallback(
            new FullScreenContentCallback() {
              @Override
              public void onAdShowedFullScreenContent() {
                // Called when ad is shown.
                Log.d(TAG, "onAdShowedFullScreenContent");
               // Toast.makeText(urhoActivity, "onAdShowedFullScreenContent", Toast.LENGTH_SHORT).show();

                OnPluginEvent("AdmobPlugin", "onAdShowedFullScreenContent");
              }
    
              @Override
              public void onAdFailedToShowFullScreenContent(AdError adError) {
                // Called when ad fails to show.
                Log.d(TAG, "onAdFailedToShowFullScreenContent");
                // Don't forget to set the ad reference to null so you
                // don't show the ad a second time.
                rewardedAd = null;
               // Toast.makeText(urhoActivity, "onAdFailedToShowFullScreenContent", Toast.LENGTH_SHORT).show();

                OnPluginEvent("AdmobPlugin", "onAdFailedToShowFullScreenContent");
              }
    
              @Override
              public void onAdDismissedFullScreenContent() {
                // Called when ad is dismissed.
                // Don't forget to set the ad reference to null so you
                // don't show the ad a second time.
                rewardedAd = null;
                Log.d(TAG, "onAdDismissedFullScreenContent");
               // Toast.makeText(urhoActivity, "onAdDismissedFullScreenContent", Toast.LENGTH_SHORT).show();
                
                OnPluginEvent("AdmobPlugin", "onAdDismissedFullScreenContent");

              }
            });
        Activity activityContext = urhoActivity;
        rewardedAd.show(
            activityContext,
            new OnUserEarnedRewardListener() {
              @Override
              public void onUserEarnedReward(@NonNull RewardItem rewardItem) {
                // Handle the reward.
                Log.d(TAG, "The user earned the reward.");
                int rewardAmount = rewardItem.getAmount();
                String rewardType = rewardItem.getType();
                
                try {
                JSONObject params = new JSONObject();
                params.put("rewardType", rewardType);
                params.put("rewardAmount", rewardAmount);
                OnPluginEvent("AdmobPlugin" , "onUserEarnedReward", params);
                }
                catch (JSONException e) 
                {
                    Log.e(TAG, "JSONException " + e);
                }

              }
            });
      }

      void setTestDeviceIds(String testDeviceId)
      {
        Log.d(TAG, "setTestDeviceIds("+testDeviceId+")");

        List<String> testDeviceIds = Arrays.asList(testDeviceId);
        RequestConfiguration configuration =
            new RequestConfiguration.Builder().setTestDeviceIds(testDeviceIds).build();
        MobileAds.setRequestConfiguration(configuration);
      }

      void showRewardedVideo(JSONObject js)
      {
         showRewardedVideo();
      }
  
      void loadRewardedAd(JSONObject js)
      {

        String adUnitId = "";
        String testDeviceId = "";

        try 
        {
            if(!js.isNull("adUnitId"))
              adUnitId =  js.getString("adUnitId");

            if(!js.isNull("testDeviceId"))
              testDeviceId =  js.getString("testDeviceId");
              
        }
        catch (Exception e) 
        {
            Log.e(TAG, "onUnhandledMessage Exception", e);
        }


        if(!testDeviceId.equals(""))
        {
          setTestDeviceIds(testDeviceId);
        }

        loadRewardedAd(adUnitId);
      }
}