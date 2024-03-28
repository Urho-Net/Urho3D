// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Skybox.cs
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
using ListView = Urho.Gui.ListView;
using Button = Urho.Gui.Button;

namespace Urho
{
	/// <summary>
	/// Static model component with fixed position in relation to the camera.
	/// </summary>
	public unsafe partial class Skybox : StaticModel
	{
		unsafe partial void OnSkyboxCreated ();

		[Preserve]
		public Skybox (IntPtr handle) : base (handle)
		{
			OnSkyboxCreated ();
		}

		[Preserve]
		protected Skybox (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnSkyboxCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Skybox_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Skybox_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Skybox_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Skybox_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Skybox_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Skybox));
			return new StringHash (Skybox_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Skybox_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Skybox));
			return Marshal.PtrToStringAnsi (Skybox_GetTypeNameStatic ());
		}

		[Preserve]
		public Skybox () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Skybox_Skybox (IntPtr context);

		[Preserve]
		public Skybox (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Skybox));
			handle = Skybox_Skybox ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnSkyboxCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Skybox_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory. StaticModel must be registered first.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Skybox));
			Skybox_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
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
