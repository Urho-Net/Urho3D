using System;
using System.Numerics;
using System.Runtime.InteropServices;
using ImGuiNET;

namespace imnodesNET
{
    public static unsafe partial class imnodesNative
    {
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern float imnodes_EditorContextGetZoom();

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern  void imnodes_EditorContextSetZoom(float zoom_scale, Vector2 zoom_center);
        
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr imnodes_CreateContext();

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void imnodes_DestroyContext(IntPtr ctx);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void imnodes_SnapNodeToGrid(int node_id);
    }

}