using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;

namespace Urho
{
    public partial class VertexBuffer
    {
        public unsafe void SetData(PositionNormal[] data)
        {
            if (data == null || data.Length == 0)
            {
                SetData((void*)IntPtr.Zero);
                return;
            }

            fixed (PositionNormal* p = &data[0]) SetData(p);
        }

        public unsafe void SetData(PositionNormalColor[] data)
        {
            if (data == null || data.Length == 0)
            {
                SetData((void*)IntPtr.Zero);
                return;
            }

            fixed (PositionNormalColor* p = &data[0]) SetData(p);
        }

        public unsafe void SetData(PositionNormalColorTexcoord[] data)
        {
            if (data == null || data.Length == 0)
            {
                SetData((void*)IntPtr.Zero);
                return;
            }

            fixed (PositionNormalColorTexcoord* p = &data[0]) SetData(p);
        }

        public unsafe void SetData(PositionNormalColorTexcoordTangent[] data)
        {
            if (data == null || data.Length == 0)
            {
                SetData((void*)IntPtr.Zero);
                return;
            }

            fixed (PositionNormalColorTexcoordTangent* p = &data[0]) SetData(p);
        }

        public unsafe void SetData(float[] data)
        {
            if (data == null || data.Length == 0)
            {
                SetData((void*)IntPtr.Zero);
                return;
            }

            fixed (float* p = &data[0]) SetData(p);
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct PositionNormal
        {
            public Vector3 Position;
            public Vector3 Normal;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct PositionColor
        {
            public Vector3 Position;
            public uint Color;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct PositionNormalColor
        {
            public Vector3 Position;
            public Vector3 Normal;
            public uint Color;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct PositionNormalColorTexcoord
        {
            public Vector3 Position;
            public Vector3 Normal;
            public uint Color;
            public Vector2 TexCoord;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct PositionNormalColorTexcoordTangent
        {
            public Vector3 Position;
            public Vector3 Normal;
            public uint Color;
            public Vector2 TexCoord;
            public Vector4 Tangent;
        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern uint VertexBuffer_GetElementMask(IntPtr handle);

        public uint GetElementMask()
        {
            Runtime.ValidateRefCounted(this);
            return VertexBuffer_GetElementMask(handle);
        }

        /// <summary>
        /// Set size, vertex elements and dynamic mode. Previous data will be lost.
        /// </summary>
        unsafe public bool SetSize(uint vertexCount, List<VertexElement> elements, bool dynamic = false)
        {
            var elementsArray = elements.ToArray();
            bool result = false;
            fixed (VertexElement* ptr = elementsArray)
            {
                result = SetSize(vertexCount, ptr, elements.Count, dynamic);
            }
            return result;
        }
    }
}
