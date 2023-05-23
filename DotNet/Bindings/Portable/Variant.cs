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

    public class VariantVector
    {
        public List<Dynamic> variants = new List<Dynamic>();

        public int Count
        {
            get
            {
                return variants.Count;
            }
        }

        public Dynamic this[int index]
        {
            get => variants[(int)index];
            set => variants[(int)index] = value;
        }

        public void Add(Variant variant)
        {
            variants.Add(new Dynamic(variant));
        }

        public Dynamic[] ToArray()
        {
            return variants.ToArray();
        }
    }


    [StructLayout(LayoutKind.Sequential)]
    public struct VariantStorage
    {
        public UIntPtr Storage0;
        public UIntPtr Storage1;
        public UIntPtr Storage2;
        public UIntPtr Storage3;
    }

    [StructLayout(LayoutKind.Explicit)]
    public unsafe struct VariantValue
    {
        [FieldOffset(0)] public bool _bool;
        [FieldOffset(0)] public int _int;
        [FieldOffset(0)] public uint _uint;
        [FieldOffset(0)] public System.Int64 int64;
        [FieldOffset(0)] public System.UInt64 uint64;
        [FieldOffset(0)] public float _float;
        [FieldOffset(0)] public double _double;
        [FieldOffset(0)] public Vector2 vector2;
        [FieldOffset(0)] public Vector3 vector3;
        [FieldOffset(0)] public Vector4 vector4;
        [FieldOffset(0)] public Color color;
        [FieldOffset(0)] public Rect rect;
        [FieldOffset(0)] public IntVector2 intVector2;
        [FieldOffset(0)] public IntVector3 intVector3;
        [FieldOffset(0)] public IntRect intRect;
        [FieldOffset(0)] public Matrix3 matrix3;
        [FieldOffset(0)] public Matrix4 matrix4;
        [FieldOffset(0)] public Matrix3x4 matrix3x4;
        [FieldOffset(0)] public Quaternion quaternion;
        [FieldOffset(0)] public IntPtr intPtr;
        [FieldOffset(0)] public VariantStorage variantStorage;
    }



    [StructLayout(LayoutKind.Explicit)]
    public unsafe struct Variant
    {
        [FieldOffset(0)]
        public VariantType Type;
        [FieldOffset(8)]
        public VariantValue Value;


        public bool IsZero()
        {
            return Type == VariantType.None;
        }
        public static implicit operator DynamicMap(Variant v)
        {
            IntPtr nativeDynamicMap = Variant_GetVariantMap(ref v);
            EventDataContainer src = new EventDataContainer(nativeDynamicMap);
            List<StringHash> Keys = src.Keys;
            DynamicMap dst = new DynamicMap();
            for (int i = 0; i < src.Count; i++)
            {
                dst[Keys[i]] = new Dynamic(src.get_Variant(Keys[i].Code));
            }
            return dst;
            // return new DynamicMap(nativeDynamicMap);
        }

        public static bool operator ==(Variant obj1, Variant obj2)
        {
            return Variant_EqualityOperator(ref obj1, ref obj2);
        }

        public static bool operator !=(Variant obj1, Variant obj2)
        {
            return Variant_EqualityOperator(ref obj1, ref obj2) == false;
        }
        public DynamicMap GetVariantMap()
        {
            return (DynamicMap)this;
        }

        public static implicit operator int(Variant v)
        {
            return v.Value._int;
        }

        public static implicit operator uint(Variant v)
        {
            return v.Value._uint;
        }

        public static implicit operator bool(Variant v)
        {
            return v.Value._bool;
        }


        public static implicit operator float(Variant v)
        {
            return v.Value._float;
        }

        public static implicit operator Vector2(Variant v)
        {
            return v.Value.vector2;
        }

        public static implicit operator Vector3(Variant v)
        {
            return v.Value.vector3;
        }

        public static implicit operator Vector4(Variant v)
        {
            return v.Value.vector4;
        }

        public static implicit operator Quaternion(Variant v)
        {
            return v.Value.quaternion;
        }


        public static implicit operator Color(Variant v)
        {
            return v.Value.color;
        }

        public static implicit operator double(Variant v)
        {
            return v.Value._double;
        }

        public static implicit operator IntPtr(Variant v)
        {
            return v.Value.intPtr;
        }

        public static implicit operator string(Variant v)
        {
            IntPtr nativeCString = Variant_GetString(ref v);
            string result = Marshal.PtrToStringAnsi(nativeCString);
            return result;
        }

        public override string ToString()
        {
            IntPtr nativeCString = Variant_ToString(ref this);
            string result = Marshal.PtrToStringAnsi(nativeCString);
            return result;
        }

        public string TypeName
        {
            get
            {
                IntPtr nativeCString = Variant_GetTypeName(ref this);
                string result = Marshal.PtrToStringAnsi(nativeCString);
                return result;
            }
        }


        public static implicit operator byte[](Variant v)
        {
            int size;
            var bytesPtr = Variant_GetBuffer(ref v, out size);
            if (bytesPtr == IntPtr.Zero)
                return new byte[0];
            byte[] result = new byte[size];
            Marshal.Copy(bytesPtr, result, 0, size);
            return result;
        }

        public ResourceRef GetResourceRef()
        {
            return (ResourceRef)this;
        }
        public static implicit operator ResourceRef(Variant v)
        {

            ResourceRef resourceRef = new ResourceRef();
            if (v.Type == VariantType.Resourceref)
            {
                resourceRef.Name = new UrhoString(Marshal.PtrToStringAnsi(Variant_GetResourceRefName(ref v)));
                resourceRef.type = (int)Variant_GetResourceRefType(ref v);
            }
            return resourceRef;
        }

        public ResourceRefList GetResourceRefList()
        {
            return (ResourceRefList)this;
        }

        public static implicit operator ResourceRefList(Variant v)
        {
            ResourceRefList resourceRefList = new ResourceRefList();
            if (v.Type == VariantType.Resourcereflist)
            {
                resourceRefList.Type.Code = Variant_ResourceRefList_GetType(ref v);
                int size = Variant_ResourceRefList_Names_GetSize(ref v);
                for (int i = 0; i < size; i++)
                {
                    IntPtr nativeCString = Variant_ResourceRefList_Names_GetNameAt(ref v, i);
                    string result = Marshal.PtrToStringAnsi(nativeCString);
                    resourceRefList.Names.Add(result);
                }
            }

            return resourceRefList;
        }

        public VariantVector GetVariantVector()
        {
            return (VariantVector)this;
        }

        public static implicit operator VariantVector(Variant v)
        {
            VariantVector variantVector = new VariantVector();
            if (v.Type == VariantType.Variantvector)
            {
                int size = Variant_VariantVector_GetSize(ref v);
                for (int i = 0; i < size; i++)
                {
                    IntPtr variantPtr = Variant_VariantVector_GetVariant(ref v, i);
                    Variant_GetRetVariant(variantPtr , out Variant variant);
                    variantVector.Add(variant);
                }
            }
            return variantVector;
        }

        public static implicit operator StringVector(Variant v)
        {
            StringVector stringVector = new StringVector();
            if (v.Type == VariantType.Stringvector)
            {
                int size = Variant_StringVector_GetSize(ref v);
                for (int i = 0; i < size; i++)
                {
                    IntPtr nativeCString = Variant_StringVector_GetString(ref v, i);
                    string result = Marshal.PtrToStringAnsi(nativeCString);
                    stringVector.Add(result);
                }
            }
            return stringVector;
        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Variant_GetTypeName(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Variant_GetVariantMap(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Variant_GetString(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Variant_ToString(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Variant_GetBuffer(ref Variant v, out int count);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Variant_GetResourceRefName(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern uint Variant_GetResourceRefType(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Variant_VariantVector_GetVariant(ref Variant v, int index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern int Variant_VariantVector_GetSize(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Variant_StringVector_GetString(ref Variant v, int index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern int Variant_StringVector_GetSize(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern int Variant_ResourceRefList_GetType(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern int Variant_ResourceRefList_Names_GetSize(ref Variant v);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Variant_ResourceRefList_Names_GetNameAt(ref Variant v, int index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern bool Variant_EqualityOperator(ref Variant variant1, ref Variant variant2);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void Variant_GetRetVariant(IntPtr handle, out Variant var);

    }

}