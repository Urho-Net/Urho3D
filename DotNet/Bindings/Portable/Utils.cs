using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho
{

    public static class Utils
    {

            [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
            public static extern void VoidPtr_Free (IntPtr ptr);

            [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
            internal static extern void delete_vector3_pointer(IntPtr vector3Pointer);

    }

}