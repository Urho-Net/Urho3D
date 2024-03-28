// Modified by Eli Aloni for Urho3D
package org.libsdl.app;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import android.annotation.TargetApi;
import android.content.Context;
import android.os.*;
import android.view.*;
import android.util.Log;

public  class SDLHaptic 
{
    public int device_id;
    public String name;
    public Vibrator vib;
}