// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ObjectAnimation.cs
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

namespace Urho
{
	/// <summary>
	/// Object animation class, an object animation include one or more attribute animations and theirs wrap mode and speed for an Animatable object.
	/// </summary>
	public unsafe partial class ObjectAnimation : Resource
	{
		unsafe partial void OnObjectAnimationCreated ();

		[Preserve]
		public ObjectAnimation (IntPtr handle) : base (handle)
		{
			OnObjectAnimationCreated ();
		}

		[Preserve]
		protected ObjectAnimation (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnObjectAnimationCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ObjectAnimation_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ObjectAnimation_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectAnimation_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ObjectAnimation_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ObjectAnimation_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ObjectAnimation));
			return new StringHash (ObjectAnimation_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectAnimation_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ObjectAnimation));
			return Marshal.PtrToStringAnsi (ObjectAnimation_GetTypeNameStatic ());
		}

		[Preserve]
		public ObjectAnimation () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectAnimation_ObjectAnimation (IntPtr context);

		[Preserve]
		public ObjectAnimation (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ObjectAnimation));
			handle = ObjectAnimation_ObjectAnimation ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnObjectAnimationCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ObjectAnimation_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ObjectAnimation));
			ObjectAnimation_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ObjectAnimation_BeginLoad_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (File source)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_BeginLoad_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ObjectAnimation_BeginLoad_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_BeginLoad_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ObjectAnimation_Save_File (IntPtr handle, IntPtr dest);

		/// <summary>
		/// Save resource. Return true if successful.
		/// </summary>
		public override bool Save (File dest)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_Save_File (handle, (object)dest == null ? IntPtr.Zero : dest.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ObjectAnimation_Save_MemoryBuffer (IntPtr handle, IntPtr dest);

		/// <summary>
		/// Save resource. Return true if successful.
		/// </summary>
		public override bool Save (MemoryBuffer dest)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_Save_MemoryBuffer (handle, (object)dest == null ? IntPtr.Zero : dest.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ObjectAnimation_LoadXML (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load from XML data. Return true if successful.
		/// </summary>
		public bool LoadXml (XmlElement source)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_LoadXML (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ObjectAnimation_SaveXML (IntPtr handle, IntPtr dest);

		/// <summary>
		/// Save as XML data. Return true if successful.
		/// </summary>
		public bool SaveXml (XmlElement dest)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_SaveXML (handle, (object)dest == null ? IntPtr.Zero : dest.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ObjectAnimation_AddAttributeAnimation (IntPtr handle, string name, IntPtr attributeAnimation, WrapMode wrapMode, float speed);

		/// <summary>
		/// Add attribute animation, attribute name can in following format: "attribute" or "#0/#1/attribute" or ""#0/#1/
		/// #1/attribute.
		/// </summary>
		public void AddAttributeAnimation (string name, ValueAnimation attributeAnimation, WrapMode wrapMode = WrapMode.Loop, float speed = 1f)
		{
			Runtime.ValidateRefCounted (this);
			ObjectAnimation_AddAttributeAnimation (handle, name, (object)attributeAnimation == null ? IntPtr.Zero : attributeAnimation.Handle, wrapMode, speed);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ObjectAnimation_RemoveAttributeAnimation (IntPtr handle, string name);

		/// <summary>
		/// Remove attribute animation, attribute name can in following format: "attribute" or "#0/#1/attribute" or ""#0/#1/
		/// #1/attribute.
		/// </summary>
		public void RemoveAttributeAnimation (string name)
		{
			Runtime.ValidateRefCounted (this);
			ObjectAnimation_RemoveAttributeAnimation (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ObjectAnimation_RemoveAttributeAnimation0 (IntPtr handle, IntPtr attributeAnimation);

		/// <summary>
		/// Remove attribute animation.
		/// </summary>
		public void RemoveAttributeAnimation (ValueAnimation attributeAnimation)
		{
			Runtime.ValidateRefCounted (this);
			ObjectAnimation_RemoveAttributeAnimation0 (handle, (object)attributeAnimation == null ? IntPtr.Zero : attributeAnimation.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectAnimation_GetAttributeAnimation (IntPtr handle, string name);

		/// <summary>
		/// Return attribute animation by name.
		/// 
		/// </summary>
		public ValueAnimation GetAttributeAnimation (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<ValueAnimation> (ObjectAnimation_GetAttributeAnimation (handle, name));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern WrapMode ObjectAnimation_GetAttributeAnimationWrapMode (IntPtr handle, string name);

		/// <summary>
		/// Return attribute animation wrap mode by name.
		/// 
		/// </summary>
		public WrapMode GetAttributeAnimationWrapMode (string name)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_GetAttributeAnimationWrapMode (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ObjectAnimation_GetAttributeAnimationSpeed (IntPtr handle, string name);

		/// <summary>
		/// Return attribute animation speed by name.
		/// 
		/// </summary>
		public float GetAttributeAnimationSpeed (string name)
		{
			Runtime.ValidateRefCounted (this);
			return ObjectAnimation_GetAttributeAnimationSpeed (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectAnimation_GetAttributeAnimationInfo (IntPtr handle, string name);

		/// <summary>
		/// Return attribute animation info by name.
		/// </summary>
		public ValueAnimationInfo GetAttributeAnimationInfo (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<ValueAnimationInfo> (ObjectAnimation_GetAttributeAnimationInfo (handle, name));
		}

		public override StringHash Type {
			get {
				return UrhoGetType ();
			}
		}

		public override string TypeName {
			get {
				return GetTypeName ();
			}
		}

		[Preserve]
		public new static StringHash TypeStatic {
			get {
				return GetTypeStatic ();
			}
		}

		public new static string TypeNameStatic {
			get {
				return GetTypeNameStatic ();
			}
		}
	}
}
