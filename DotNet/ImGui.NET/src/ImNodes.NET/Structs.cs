using System;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Text;
using ImGuiNET;

namespace imnodesNET
{
   
    public struct ImNodesEditorContext
    {

    }


   
    public unsafe struct ImNodesContext
    {
       
    }
    
    public unsafe struct ImNodesEditorContextPtr
    {
        public ImNodesEditorContext* NativePtr;
        public ImNodesEditorContextPtr(ImNodesEditorContext* ptr)
        {
            NativePtr = ptr;
        }
    }

    public unsafe struct ImNodesContextPtr
    {
        public ImNodesContext* NativePtr;

        public ImNodesContextPtr(ImNodesContext* ptr)
        {
            NativePtr = ptr;
        }
    }
    
}


