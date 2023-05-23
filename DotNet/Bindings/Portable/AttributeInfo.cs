using System;
using System.Collections.Generic;
using System.Threading;
using System.Runtime.InteropServices;

namespace Urho
{

    [StructLayout(LayoutKind.Sequential)]
    public partial class AttributeInfo
    {
        public IntPtr Handle { get; private set; } = IntPtr.Zero;

        public AttributeInfo()
        {

        }
        public AttributeInfo(IntPtr handle)
        {
            Handle = handle;
        }

        VariantType type_ = VariantType.None;
        public VariantType Type
        {
            get
            {
                if (Handle != IntPtr.Zero)
                {
                    return AttributeInfo_GetType(Handle);
                }
                else
                    return type_;
            }

            set
            {
                type_ = value;
            }
        }

        string name_ = "";
        public string Name
        {
            get
            {
                if (Handle != IntPtr.Zero)
                {
                    IntPtr nativeString = AttributeInfo_GetName(Handle);
                    string result = Marshal.PtrToStringAnsi(nativeString);
                    return result;
                }
                else
                {
                    return name_;
                }
            }

            set
            {
                name_ = value;
            }
        }

        public List<string> EnumNames = new List<string>();

        public AttributeMode Mode;

		public Dynamic DefaultValue = new Dynamic(0);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern VariantType AttributeInfo_GetType(IntPtr handle);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr AttributeInfo_GetName(IntPtr handle);

    }
}
