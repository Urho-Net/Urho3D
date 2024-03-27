// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// SoundListener.cs
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

namespace Urho.Audio
{
	/// <summary>
	/// %Sound listener component.
	/// </summary>
	public unsafe partial class SoundListener : Component
	{
		unsafe partial void OnSoundListenerCreated ();

		[Preserve]
		public SoundListener (IntPtr handle) : base (handle)
		{
			OnSoundListenerCreated ();
		}

		[Preserve]
		protected SoundListener (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnSoundListenerCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int SoundListener_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (SoundListener_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr SoundListener_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (SoundListener_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int SoundListener_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(SoundListener));
			return new StringHash (SoundListener_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr SoundListener_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(SoundListener));
			return Marshal.PtrToStringAnsi (SoundListener_GetTypeNameStatic ());
		}

		[Preserve]
		public SoundListener () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr SoundListener_SoundListener (IntPtr context);

		[Preserve]
		public SoundListener (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(SoundListener));
			handle = SoundListener_SoundListener ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnSoundListenerCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void SoundListener_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(SoundListener));
			SoundListener_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
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
