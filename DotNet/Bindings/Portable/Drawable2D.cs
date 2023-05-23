// 
// Drawable2D.cs
// 
using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho.Urho2D
{
    /// <summary>
    /// Base class for 2D visible components.
    /// </summary>
    public unsafe partial class Drawable2D : Drawable
    {
        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_SetSourceBatchesVertices(IntPtr handle, Vertex2D* data , int count);

        public virtual bool UpdateSourceBatches() { return false; }

        public void SetSourceBatchesVertices(Vertex2D [] vertices , int count)
        {
            Runtime.ValidateRefCounted (this);
            if(vertices != null && count > 0 && count <= vertices.Length )
            {
                 fixed (Vertex2D* ptr = vertices)
                 {
                    Drawable2D_SetSourceBatchesVertices (handle, ptr,count);
                 }
            }
        }
        public void SetSourceBatchesVertices(Vertex2D [] vertices)
        {
            Runtime.ValidateRefCounted (this);
            if(vertices != null && vertices.Length > 0)
            {
                 fixed (Vertex2D* ptr = vertices)
                 {
                    Drawable2D_SetSourceBatchesVertices (handle, ptr,(int)vertices.Length);
                 }
            }

        }
    }

}