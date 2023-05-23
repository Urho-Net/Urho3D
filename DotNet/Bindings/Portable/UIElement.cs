//
// UIElement C# sugar
//
// Authors:
//   Miguel de Icaza (miguel@xamarin.com)
//
// Copyrigh 2015 Xamarin INc
//
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Reflection;

namespace Urho.Gui
{

    public partial class UIElement
    {

        public Application Application => Application.Current;
        public T CreateChild<T>(StringHash code, string name = "", uint index = UInt32.MaxValue) where T : UIElement
        {
            Runtime.ValidateRefCounted(this);
            var ptr = UIElement_CreateChild(handle, code.Code, name, index);
            return Runtime.LookupObject<T>(ptr);
        }

        //TODO: test
        public T CreateChild<T>(string name = "", uint index = UInt32.MaxValue) where T : UIElement
        {
            Runtime.ValidateRefCounted(this);
            var hash = Runtime.LookupStringHash(typeof(T));
            var ptr = UIElement_CreateChild(handle, hash.Code, name, index);
            return Runtime.LookupObject<T>(ptr);
        }

        public BorderImage CreateBorderImage(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<BorderImage>(BorderImage.TypeStatic, name, index);
        }

        public Button CreateButton(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Button>(Button.TypeStatic, name, index);
        }

        public Menu CreateMenu(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Menu>(Menu.TypeStatic, name, index);
        }

        public DropDownList CreateDropDownList(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<DropDownList>(DropDownList.TypeStatic, name, index);
        }

        public CheckBox CreateCheckBox(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<CheckBox>(CheckBox.TypeStatic, name, index);
        }

        public Cursor CreateCursor(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Cursor>(Cursor.TypeStatic, name, index);
        }

        public LineEdit CreateLineEdit(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<LineEdit>(LineEdit.TypeStatic, name, index);
        }

        public Slider CreateSlider(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Slider>(Slider.TypeStatic, name, index);
        }

        public Window CreateWindow(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Window>(Window.TypeStatic, name, index);
        }

        public View3D CreateView3D(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<View3D>(View3D.TypeStatic, name, index);
        }

        public ScrollBar CreateScrollBar(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<ScrollBar>(ScrollBar.TypeStatic, name, index);
        }

        public ScrollView CreateScrollView(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<ScrollView>(ScrollView.TypeStatic, name, index);
        }

        public ListView CreateListView(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<ListView>(ListView.TypeStatic, name, index);
        }

        public Sprite CreateSprite(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Sprite>(Sprite.TypeStatic, name, index);
        }

        public Text CreateText(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<Text>(Text.TypeStatic, name, index);
        }

        public ToolTip CreateToolTip(string name = "", uint index = UInt32.MaxValue)
        {
            return CreateChild<ToolTip>(ToolTip.TypeStatic, name, index);
        }

        public virtual void OnVGRenderUpdate(float timeStep)
        {

        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void UIElement_SetVar_IntPtr(IntPtr handle, int key, IntPtr value);

        /// <summary>
        /// Set a user variable.
        /// </summary>
        public void SetVar(StringHash key, IntPtr value)
        {
            Runtime.ValidateRefCounted(this);
            UIElement_SetVar_IntPtr(handle, key.Code, value);
        }

		public void SetVar(string key, IntPtr value)
        {
            Runtime.ValidateRefCounted(this);
            SetVar(new StringHash(key), value);
        }

		public void SetVar(string key, Variant value)
		{
			Runtime.ValidateRefCounted(this);
            SetVar(new StringHash(key), new Dynamic(value).Handle);
		}

		public void SetVar(StringHash key, Variant value)
        {
            Runtime.ValidateRefCounted(this);
            SetVar(key, new Dynamic(value).Handle);
        }


        public void SetVar(string key, VariantVector value)
        {
            Runtime.ValidateRefCounted(this);
            SetVar(key, new Dynamic(value).Handle);
        }

        public void SetVar(StringHash key, VariantVector value)
        {
            Runtime.ValidateRefCounted(this);
            SetVar(key, new Dynamic(value).Handle);
        }


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        unsafe internal static extern Variant * UIElement_GetTags(IntPtr handle);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr UIElement_GetVars(IntPtr handle);


       public DynamicMap Vars
        {
            get
            {
				Runtime.ValidateRefCounted(this);
                return new DynamicMap(UIElement_GetVars(Handle));
            }
        }

        unsafe public StringVector Tags
        {
            get
            {
				Runtime.ValidateRefCounted(this);
                return (StringVector)(*UIElement_GetTags(Handle));
            }

            set
            {
                SetTags(value);
            }
        }

        public void SetTags(StringVector tags)
        {
            RemoveAllTags();
            for (int i = 0; i < tags.Count; i++)
            {
                AddTag(tags[i]);
            }
        }

    }
}
