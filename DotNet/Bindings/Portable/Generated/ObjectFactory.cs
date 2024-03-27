// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ObjectFactory.cs
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
using File = Urho.IO.File;

namespace Urho
{
	/// <summary>
	/// Base class for object factories.
	/// </summary>
	public unsafe partial class ObjectFactory : RefCounted
	{
		unsafe partial void OnObjectFactoryCreated ();

		[Preserve]
		public ObjectFactory (IntPtr handle) : base (handle)
		{
			OnObjectFactoryCreated ();
		}

		[Preserve]
		protected ObjectFactory (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnObjectFactoryCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectFactory_CreateObject (IntPtr handle);

		/// <summary>
		/// Create an object. Implemented in templated subclasses.
		/// </summary>
		public UrhoObject CreateObject ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<UrhoObject> (ObjectFactory_CreateObject (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectFactory_GetContext (IntPtr handle);

		/// <summary>
		/// Return execution context.
		/// </summary>
		private Context GetContext ()
		{
			return Runtime.LookupRefCounted<Context> (ObjectFactory_GetContext (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern TypeInfo* ObjectFactory_GetTypeInfo (IntPtr handle);

		/// <summary>
		/// Return type info of objects created by this factory.
		/// </summary>
		private TypeInfo* GetTypeInfo ()
		{
			Runtime.ValidateRefCounted (this);
			return ObjectFactory_GetTypeInfo (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ObjectFactory_GetType (IntPtr handle);

		/// <summary>
		/// Return type hash of objects created by this factory.
		/// </summary>
		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ObjectFactory_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ObjectFactory_GetTypeName (IntPtr handle);

		/// <summary>
		/// Return type name of objects created by this factory.
		/// </summary>
		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ObjectFactory_GetTypeName (handle));
		}

		/// <summary>
		/// Return execution context.
		/// </summary>
		public Context Context {
			get {
				return GetContext ();
			}
		}

		/// <summary>
		/// Return type info of objects created by this factory.
		/// </summary>
		public TypeInfo* TypeInfo {
			get {
				return GetTypeInfo ();
			}
		}

		/// <summary>
		/// Return type hash of objects created by this factory.
		/// </summary>
		public StringHash Type {
			get {
				return UrhoGetType ();
			}
		}

		/// <summary>
		/// Return type name of objects created by this factory.
		/// </summary>
		public string TypeName {
			get {
				return GetTypeName ();
			}
		}
	}
}
