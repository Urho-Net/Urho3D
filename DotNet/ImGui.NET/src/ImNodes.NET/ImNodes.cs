using System;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Text;
using ImGuiNET;

namespace imnodesNET
{
    public static unsafe partial class imnodes
    {
        public static float EditorContextGetZoom()
        {
            return imnodesNative.imnodes_EditorContextGetZoom();
        }
        
        public static void EditorContextSetZoom(float zoom_scale,Vector2 zoom_center)
        {
            imnodesNative.imnodes_EditorContextSetZoom( zoom_scale,  zoom_center);
        }
    }

}