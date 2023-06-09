// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Texture3D.cs
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
	/// 3D texture resource.
	/// </summary>
	public unsafe partial class Texture3D : Texture
	{
		unsafe partial void OnTexture3DCreated ();

		[Preserve]
		public Texture3D (IntPtr handle) : base (handle)
		{
			OnTexture3DCreated ();
		}

		[Preserve]
		protected Texture3D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnTexture3DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Texture3D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Texture3D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture3D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Texture3D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Texture3D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Texture3D));
			return new StringHash (Texture3D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture3D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Texture3D));
			return Marshal.PtrToStringAnsi (Texture3D_GetTypeNameStatic ());
		}

		[Preserve]
		public Texture3D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture3D_Texture3D (IntPtr context);

		[Preserve]
		public Texture3D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Texture3D));
			handle = Texture3D_Texture3D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnTexture3DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Texture3D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Texture3D));
			Texture3D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_BeginLoad_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_BeginLoad_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_BeginLoad_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_BeginLoad_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_EndLoad (IntPtr handle);

		/// <summary>
		/// Finish resource loading. Always called from the main thread. Return true if successful.
		/// </summary>
		public override bool EndLoad ()
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_EndLoad (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Texture3D_Release (IntPtr handle);

		/// <summary>
		/// Release the texture.
		/// </summary>
		public void Release ()
		{
			Runtime.ValidateRefCounted (this);
			Texture3D_Release (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_SetSize (IntPtr handle, int width, int height, int depth, uint format, TextureUsage usage);

		/// <summary>
		/// Set size, format and usage. Zero size will follow application window size. Return true if successful.
		/// </summary>
		public bool SetSize (int width, int height, int depth, uint format, TextureUsage usage = TextureUsage.Static)
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_SetSize (handle, width, height, depth, format, usage);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_SetData (IntPtr handle, uint level, int x, int y, int z, int width, int height, int depth, void* data);

		/// <summary>
		/// Set data either partially or fully on a mip level. Return true if successful.
		/// </summary>
		public bool SetData (uint level, int x, int y, int z, int width, int height, int depth, void* data)
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_SetData (handle, level, x, y, z, width, height, depth, data);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_SetData0 (IntPtr handle, IntPtr image, bool useAlpha);

		/// <summary>
		/// Set data from an image. Return true if successful. Optionally make a single channel image alpha-only.
		/// </summary>
		public bool SetData (Image image, bool useAlpha = false)
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_SetData0 (handle, (object)image == null ? IntPtr.Zero : image.Handle, useAlpha);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture3D_GetData (IntPtr handle, uint level, IntPtr dest);

		/// <summary>
		/// Get data from a mip level. The destination buffer must be big enough. Return true if successful.
		/// </summary>
		public bool GetData (uint level, IntPtr dest)
		{
			Runtime.ValidateRefCounted (this);
			return Texture3D_GetData (handle, level, dest);
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
