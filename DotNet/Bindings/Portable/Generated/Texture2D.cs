// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Texture2D.cs
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

namespace Urho.Urho2D
{
	/// <summary>
	/// 2D texture resource.
	/// </summary>
	public unsafe partial class Texture2D : Texture
	{
		unsafe partial void OnTexture2DCreated ();

		[Preserve]
		public Texture2D (IntPtr handle) : base (handle)
		{
			OnTexture2DCreated ();
		}

		[Preserve]
		protected Texture2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnTexture2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Texture2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Texture2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Texture2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Texture2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Texture2D));
			return new StringHash (Texture2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Texture2D));
			return Marshal.PtrToStringAnsi (Texture2D_GetTypeNameStatic ());
		}

		[Preserve]
		public Texture2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture2D_Texture2D (IntPtr context);

		[Preserve]
		public Texture2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Texture2D));
			handle = Texture2D_Texture2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnTexture2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Texture2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Texture2D));
			Texture2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_BeginLoad_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_BeginLoad_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_BeginLoad_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_BeginLoad_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_EndLoad (IntPtr handle);

		/// <summary>
		/// Finish resource loading. Always called from the main thread. Return true if successful.
		/// </summary>
		public override bool EndLoad ()
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_EndLoad (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Texture2D_Release (IntPtr handle);

		/// <summary>
		/// Release the texture.
		/// </summary>
		public void Release ()
		{
			Runtime.ValidateRefCounted (this);
			Texture2D_Release (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_SetSize (IntPtr handle, int width, int height, uint format, TextureUsage usage, int multiSample, bool autoResolve);

		/// <summary>
		/// Set size, format, usage and multisampling parameters for rendertargets. Zero size will follow application window size. Return true if successful.
		/// Autoresolve true means the multisampled texture will be automatically resolved to 1-sample after being rendered to and before being sampled as a texture.
		/// Autoresolve false means the multisampled texture will be read as individual samples in the shader and is not supported on Direct3D9.
		/// </summary>
		public bool SetSize (int width, int height, uint format, TextureUsage usage = TextureUsage.Static, int multiSample = 1, bool autoResolve = true)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_SetSize (handle, width, height, format, usage, multiSample, autoResolve);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_SetData (IntPtr handle, uint level, int x, int y, int width, int height, void* data);

		/// <summary>
		/// Set data either partially or fully on a mip level. Return true if successful.
		/// </summary>
		public bool SetData (uint level, int x, int y, int width, int height, void* data)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_SetData (handle, level, x, y, width, height, data);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_SetData0 (IntPtr handle, IntPtr image, bool useAlpha);

		/// <summary>
		/// Set data from an image. Return true if successful. Optionally make a single channel image alpha-only.
		/// </summary>
		public bool SetData (Image image, bool useAlpha = false)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_SetData0 (handle, (object)image == null ? IntPtr.Zero : image.Handle, useAlpha);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_GetData (IntPtr handle, uint level, IntPtr dest);

		/// <summary>
		/// Get data from a mip level. The destination buffer must be big enough. Return true if successful.
		/// </summary>
		public bool GetData (uint level, IntPtr dest)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_GetData (handle, level, dest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Texture2D_GetImage (IntPtr handle, IntPtr image);

		/// <summary>
		/// Get image data from zero mip level. Only RGB and RGBA textures are supported.
		/// </summary>
		public bool GetImage (Image image)
		{
			Runtime.ValidateRefCounted (this);
			return Texture2D_GetImage (handle, (object)image == null ? IntPtr.Zero : image.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture2D_GetImage1 (IntPtr handle);

		/// <summary>
		/// Get image data from zero mip level. Only RGB and RGBA textures are supported.
		/// </summary>
		private Image GetImage ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Image> (Texture2D_GetImage1 (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Texture2D_GetRenderSurface (IntPtr handle);

		/// <summary>
		/// Return render surface.
		/// 
		/// </summary>
		private RenderSurface GetRenderSurface ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<RenderSurface> (Texture2D_GetRenderSurface (handle));
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

		/// <summary>
		/// Get image data from zero mip level. Only RGB and RGBA textures are supported.
		/// </summary>
		public Image Image {
			get {
				return GetImage ();
			}
		}

		/// <summary>
		/// Return render surface.
		/// 
		/// </summary>
		public RenderSurface RenderSurface {
			get {
				return GetRenderSurface ();
			}
		}
	}
}
