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

    public class AttributesVector
    {
        public IntPtr Handle { get; private set; } = IntPtr.Zero;

        public List<AttributeInfo> attributes  = new  List<AttributeInfo>();

        public AttributesVector(IntPtr handle)
        {
            Handle = handle;
            FillAttributes();
        }

        private void FillAttributes()
        {

            for(uint index = 0 ; index < Count ; index++)
            {
                AttributeInfo attributeInfo = new AttributeInfo();
                attributeInfo.Type = AttributeVector_Attribute_GetType(Handle, index);
                IntPtr nativeString = AttributeVector_Attribute_GetName(Handle, index);
                string result = Marshal.PtrToStringAnsi(nativeString);
                attributeInfo.Name = result;
                attributeInfo.Mode = (AttributeMode)AttributeVector_Attribute_GetMode(Handle, index);

                attributeInfo.DefaultValue = new Dynamic(AttributeVector_Attribute_GetDefaultValue(Handle, index));

                StringVector  enumNames = new StringVector();
                AttributeVector_Attribute_GetEnumNames(Handle, (int)index , enumNames.Handle);
           
                for(int i = 0 ; i < enumNames.Count;i++)
                {
                    attributeInfo.EnumNames.Add(enumNames[i]);
                }

                enumNames.Dispose();

                attributes.Add(attributeInfo);
            }
        }

        public int Count
        {
            get
            {
                return AttributeVector_GetSize(Handle);
            }
        }

        public AttributeInfo At(uint index)
        {
            // return this[index];
            return attributes[(int)index];
        }
        public AttributeInfo this[uint index]
        {
            get
            {
                return attributes[(int)index];
            }
        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern int AttributeVector_GetSize(IntPtr handle);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern VariantType AttributeVector_Attribute_GetType(IntPtr handle, uint index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr AttributeVector_Attribute_GetName(IntPtr handle, uint index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern uint AttributeVector_Attribute_GetMode(IntPtr handle, uint index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void AttributeVector_Attribute_GetEnumNames(IntPtr handle,int index , IntPtr stringVector);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern  Variant AttributeVector_Attribute_GetDefaultValue(IntPtr handle, uint index);
    }

    /// <summary>
    /// Urho3D execution context. Provides access to subsystems, object factories and attributes, and event receivers.
    /// </summary>
    public unsafe partial class Context : RefCounted
    {
        public List<string> Categories
        {
            get
            {
                List<string> categories = new List<string>();
                int size = GetCetegoriesSize();
                for (int i = 0; i < size; i++)
                {
                    categories.Add(GetCategory(i));
                }
                return categories;
            }
        }

        public List<string> GetObjectsByCategory(string category)
        {
            List<string> objects = new List<string>();
            PopulateByCategory(category);
            int size = GetObjectCountInLastPopulatedCetegory();
            for (int i = 0; i < size; i++)
            {

                objects.Add(GetObjectInLastPopulatedCetegory(i));
            }
            ClearLastPopulatedCategory();
            return objects;
        }

        public AttributesVector GetAttributes(StringHash type)
        {
            return new AttributesVector(Context_GetAttributes(Handle, type.Code));
        }

        public AttributesVector GetAttributes(string type)
        {
            return new AttributesVector(Context_GetAttributes(Handle, new StringHash(type).Code));
        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr Context_GetAttributes(IntPtr handle, int type);
    }

}