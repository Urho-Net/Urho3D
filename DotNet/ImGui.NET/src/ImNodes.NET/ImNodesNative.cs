using System;
using System.Numerics;
using System.Runtime.InteropServices;
using ImGuiNET;

namespace imnodesNET
{
    public static unsafe partial class imnodesNative
    {
        [DllImport("cimnodes", CallingConvention = CallingConvention.Cdecl)]
        public static extern float imnodes_EditorContextGetZoom();

        [DllImport("cimnodes", CallingConvention = CallingConvention.Cdecl)]
        public static extern  void imnodes_EditorContextSetZoom(float zoom_scale, Vector2 zoom_center);
    }

}