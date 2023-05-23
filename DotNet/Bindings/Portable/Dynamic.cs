//
// The MIT License (MIT)
//
// Copyright (c) 2021 Eli Aloni (A.K.A elix22)
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

using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;
using System.Runtime.InteropServices;
using Urho.Physics;
using Urho.Gui;
using Urho.Urho2D;
using Urho.Resources;
using Urho.IO;

namespace Urho
{

    public unsafe class Dynamic
    {
        public IntPtr Handle { get; private set; } = IntPtr.Zero;

        public Variant variant
        {
            get{
                if(Handle != IntPtr.Zero)
                {
                    Dynamic_GetRetVariant(Handle, out Variant v);
                    return v;
                }
                else{
                    return new Variant();
                }
            }
        }

        // public object ReferenceObject { get; private set; } = null;
        public VariantType DynamicType { get; private set; } = VariantType.None;

        private bool Managed = false;

        public VariantType Type{
            get
            {
                return DynamicType;
            }
        }

        public Dynamic(IntPtr handle)
        {
            Handle = handle;
            DynamicType = variant.Type;
            Managed = true;
        }

        public Dynamic(VariantType type, string value)
        {
            Handle = Dynamic_CreateFromType( type,  value);
            DynamicType = variant.Type;
        }
        
        public Dynamic(Variant v)
        {
            Handle = Dynamic_CreateVariant(ref v);     
            DynamicType = variant.Type;
        }

        public Dynamic(byte[] data)
        {
            DynamicType = VariantType.Buffer;

            fixed (byte* bptr = data)
            {
                Handle = Dynamic_CreateBuffer(bptr, data.Length);
                
            }
        }

        public override string ToString()
        {
            return variant.ToString();
        }

        public Dynamic(bool v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Bool;
            Handle = Dynamic_CreateBool(v);
            
        }


        public Dynamic(int v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Int;
            Handle = Dynamic_CreateInt(v);
            
        }

        public Dynamic(uint v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Int;
            Handle = Dynamic_CreateUInt(v);
            
        }


        public Dynamic(System.Int64 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Int64;
            Handle = Dynamic_CreateInt64(v);
            
        }

        public Dynamic(System.UInt64 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Int64;
            Handle = Dynamic_CreateUInt64(v);
            
        }


        public Dynamic(float v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Float;
            Handle = Dynamic_CreateFloat(v);
            
        }

        public Dynamic(double v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Double;
            Handle = Dynamic_CreateDouble(v);
            
        }


        public Dynamic(Vector2 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Vector2;
            Handle = Dynamic_CreateVector2(v);
            
        }

        public Dynamic(IntVector2 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Intvector2;
            Handle = Dynamic_CreateIntVector2(v);
            
        }


        public Dynamic(Vector3 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Vector3;
            Handle = Dynamic_CreateVector3(v);
            
        }

        public Dynamic(IntVector3 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Intvector3;
            Handle = Dynamic_CreateIntVector3(v);
            
        }


        public Dynamic(Rect v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Rect;
            Handle = Dynamic_CreateRect(v);
            
        }

        public Dynamic(IntRect v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Intrect;
            Handle = Dynamic_CreateIntRect(v);
            
        }


        public Dynamic(Vector4 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Vector4;
            Handle = Dynamic_CreateVector4(v);
            
        }

        public Dynamic(Quaternion v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Quaternion;
            Handle = Dynamic_CreateQuaternion(v);
            
        }
        public Dynamic(Color v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Color;
            Handle = Dynamic_CreateColor(v);
            
        }

        public Dynamic(string v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.String;
            Handle = Dynamic_CreateString(v);
            
        }

        public Dynamic(Matrix3 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Matrix3;
            Handle = Dynamic_CreateMatrix3(v);
            
        }

        public Dynamic(Matrix4 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Matrix4;
            Handle = Dynamic_CreateMatrix4(v);
            
        }

        public Dynamic(Matrix3x4 v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Matrix3x4;
            Handle = Dynamic_CreateMatrix3x4(v);
            
        }

        public Dynamic(ResourceRef v)
        {
            // ReferenceObject = v;
            DynamicType = VariantType.Resourceref;
            Handle = Dynamic_CreateResourceRef(v.type,(string)v.Name);
        }


        public static implicit operator Dynamic(ResourceRef resourceRef)
        {
            return new Dynamic(resourceRef);
        }

        public static implicit operator ResourceRef(Dynamic v)
        {
            if (v.Handle != IntPtr.Zero && v.DynamicType == VariantType.Resourceref)
            {
                ResourceRef *resourceRef= Dynamic_GetResourceRef(v.Handle);
                return *resourceRef;
            }
            else return new ResourceRef();
        }

        public ResourceRef GetResourceRef()
        {
            if (Handle != IntPtr.Zero && DynamicType == VariantType.Resourceref)
            {
                ResourceRef *resourceRef= Dynamic_GetResourceRef(Handle);
                return *resourceRef;
            }
            else return new ResourceRef();
        }

        public Dynamic(ResourceRefList resourceRefList)
        {
            DynamicType = VariantType.Resourcereflist;
            Handle = Dynamic_CreateResourceRefList(resourceRefList.Type.Code,resourceRefList.Names.Handle);
            
        }

        public static implicit operator Dynamic(ResourceRefList resourceRefList)
        {
            return new Dynamic(resourceRefList);
        }

        // TBD elix22 , this is definitely wrong , needs to be fixed 
        public static implicit operator ResourceRefList(Dynamic v)
        {
            if (v.Handle != IntPtr.Zero && v.DynamicType == VariantType.Resourcereflist)
                return v;
            else return new ResourceRefList();
        }

        public ResourceRefList GetResourceRefList()
        {
            if (Handle != IntPtr.Zero && DynamicType == VariantType.Resourcereflist)
                return this;
            else return new ResourceRefList();     
        }

        public Dynamic(VariantVector variantVector)
        {
            // ReferenceObject = variantVector;
            DynamicType = VariantType.Variantvector;
            Handle = Dynamic_CreateVariantVector(variantVector.Count);
            
            for(int i =0 ; i < variantVector.Count ; i++)
            {
                Variant v = variantVector[i].variant;
                Dynamic_VariantVector_AddVariant(Handle,ref v,i);
            }
        }

        public static implicit operator Dynamic(VariantVector variantVector)
        {
            return new Dynamic(variantVector);
        }

        public static implicit operator VariantVector(Dynamic v)
        {
            if (v.Handle != IntPtr.Zero && v.DynamicType == VariantType.Variantvector)
                return v;
            else return new VariantVector();
        }

        public VariantVector GetVariantVector()
        {
            if (Handle != IntPtr.Zero && DynamicType == VariantType.Variantvector)
                return this;
            else return new VariantVector();     
        }

         public Dynamic(DynamicMap dynamicMap)
         {
            // ReferenceObject = dynamicMap;
            DynamicType = VariantType.Variantmap;
            Handle =  dynamicMap.Handle;
            
            Managed = true;
         }

        public static implicit operator Dynamic(DynamicMap dynamicMap)
        {
            return new Dynamic(dynamicMap);
        }
        
        public static implicit operator DynamicMap(Dynamic v)
        {
             return v.variant.GetVariantMap();
        }

        public DynamicMap GetVariantMap()
        {
            if (Handle != IntPtr.Zero && DynamicType == VariantType.Variantmap)
                return variant.GetVariantMap();
            else return new DynamicMap();
        }

        public static implicit operator Dynamic(bool b)
        {
            return new Dynamic(b);
        }

        public static implicit operator Variant(Dynamic v)
        {
            return v.variant;
        }

        public static implicit operator bool(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (bool)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value._bool;
            else
                return false;
        }

        public static implicit operator Dynamic(int i)
        {
            return new Dynamic(i);
        }

        public static implicit operator int(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (int)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value._int;
            else return 0;
        }

        public static implicit operator Dynamic(uint i)
        {
            return new Dynamic(i);
        }

        public static implicit operator uint(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (uint)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value._uint;
            else return 0;

        }


        public static implicit operator Dynamic(System.Int64 i)
        {
            return new Dynamic(i);
        }

        public static implicit operator System.Int64(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (System.Int64)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.int64;
            else return 0;
        }


        public static implicit operator Dynamic(System.UInt64 i)
        {
            return new Dynamic(i);
        }

        public static implicit operator System.UInt64(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (System.UInt64)v.ReferenceObject;
            // else
             if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.uint64;
            else return 0;

        }

        public static implicit operator Dynamic(float val)
        {
            return new Dynamic(val);
        }

        public static implicit operator float(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (float)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value._float;
            else return 0.0f;

        }

        public static implicit operator Dynamic(double val)
        {
            return new Dynamic(val);
        }

        public static implicit operator double(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (double)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value._double;
            else return 0.0;

        }

        public static implicit operator Dynamic(Vector2 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Vector2(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Vector2)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.vector2;
            else return new Vector2();
        }

        public static implicit operator Dynamic(IntVector2 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator IntVector2(Dynamic v)
        {

            // if (v != null && v.ReferenceObject != null)
            //     return (IntVector2)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.intVector2;
            else return new IntVector2();
        }

        public static implicit operator Dynamic(Vector3 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Vector3(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Vector3)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.vector3;
            else return new Vector3();
        }

        public static implicit operator Dynamic(IntVector3 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator IntVector3(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (IntVector3)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.intVector3;
            else return new IntVector3();
        }

        public static implicit operator Dynamic(IntRect val)
        {
            return new Dynamic(val);
        }

        public static implicit operator IntRect(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (IntRect)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.intRect;
            else return new IntRect();
        }


        public static implicit operator Dynamic(Rect val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Rect(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Rect)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.rect;
            else return new Rect();
        }

        public static implicit operator Dynamic(Vector4 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Vector4(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Vector4)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.vector4;
            else return new Vector4();

        }

        public static implicit operator Dynamic(Quaternion val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Quaternion(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Quaternion)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.quaternion;
            else return new Quaternion();
        }

        public static implicit operator Dynamic(Color val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Color(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Color)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return v.variant.Value.color;
            else return new Color();
        }

        public static implicit operator Dynamic(string val)
        {
            return new Dynamic(val);
        }

        public static implicit operator string(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (string)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
                return Marshal.PtrToStringAnsi(Dynamic_GetString(v.Handle));
            else return new string("");


        }

        public static implicit operator Dynamic(Matrix3 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Matrix3(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Matrix3)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
            {
#if __WEB__
                return *Dynamic_GetMatrix3(v.Handle);
#else   
                return Dynamic_GetMatrix3(v.Handle);
#endif
            }
            else return new Matrix3();
        }

        public static implicit operator Dynamic(Matrix4 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Matrix4(Dynamic v)
        {
            // if (v != null && v.ReferenceObject != null)
            //     return (Matrix4)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
            {
#if __WEB__
                return *Dynamic_GetMatrix4(v.Handle);
#else
                return Dynamic_GetMatrix4(v.Handle);
#endif
            }
            else return new Matrix4();
        }


        public static implicit operator Dynamic(Matrix3x4 val)
        {
            return new Dynamic(val);
        }

        public static implicit operator Matrix3x4(Dynamic v)
        {

            // if (v != null && v.ReferenceObject != null)
            //     return (Matrix3x4)v.ReferenceObject;
            // else 
            if (v.Handle != IntPtr.Zero && v.variant.Type != VariantType.None)
            {
#if __WEB__
                return *Dynamic_GetMatrix3x4(v.Handle);
#else
                return Dynamic_GetMatrix3x4(v.Handle);
#endif
            }
            else return new Matrix3x4();
        }

        ~Dynamic()
        {
            if (Handle != IntPtr.Zero  && Managed == false)
            {
                // Log.Info("~Dynamic() :" + DynamicType.ToString());
                Dynamic_Dispose(Handle);
                Handle = IntPtr.Zero;
            }
        }

        public static implicit operator Dynamic(byte[] data)
        {
            return new Dynamic(data);
        }


        public static implicit operator byte[](Dynamic v)
        {
            int size;
            var bytesPtr = Dynamic_GetBuffer(v.Handle, out size);
            if (bytesPtr == IntPtr.Zero)
                return new byte[0];
            byte[] result = new byte[size];
            Marshal.Copy(bytesPtr, result, 0, size);
            return result;
        }



        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateBuffer(byte* data, int size);


        /////////////////////////////////////////////////////////////////////

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateFromType(VariantType type, string value);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateVariant(ref Variant v);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateBool(bool v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateInt(int i);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateUInt(uint i);

        ////
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateInt64(System.Int64 i);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateUInt64(System.UInt64 i);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateFloat(float f);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateVector2(Vector2 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateVector3(Vector3 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateVector4(Vector4 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateQuaternion(Quaternion v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateColor(Color v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateDouble(double v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateString(string s);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_GetString(IntPtr h);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateIntVector2(IntVector2 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateIntVector3(IntVector3 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateIntRect(IntRect v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateRect(Rect v);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateMatrix3(Matrix3 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
        static extern Matrix3* Dynamic_GetMatrix3(IntPtr v);
#else
        static extern Matrix3 Dynamic_GetMatrix3(IntPtr v);
#endif


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateMatrix4(Matrix4 v);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
         static extern Matrix4*  Dynamic_GetMatrix4(IntPtr v);
#else
        static extern Matrix4 Dynamic_GetMatrix4(IntPtr v);
#endif

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateMatrix3x4(Matrix3x4 v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
          static extern Matrix3x4* Dynamic_GetMatrix3x4(IntPtr v);
#else
        static extern Matrix3x4 Dynamic_GetMatrix3x4(IntPtr v);
#endif

        ////////////////////////////////////////////////////////////////////


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void Dynamic_Dispose(IntPtr handle);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_GetBuffer(IntPtr v, out int count);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
         static extern IntPtr Dynamic_CreateResourceRef(int type ,string name);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern ResourceRef * Dynamic_GetResourceRef(IntPtr v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateResourceRefList(int type,IntPtr StringVectorHandle);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void Dynamic_ResourceRefList_AddName(IntPtr handle,string name);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Dynamic_CreateVariantVector(int count);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void Dynamic_VariantVector_AddVariant(IntPtr handle,ref Variant v,int index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void Dynamic_GetRetVariant(IntPtr handle, out Variant var);


    }

}