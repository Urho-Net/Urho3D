// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Font.cs
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

namespace Urho.Gui
{
	/// <summary>
	/// %Font resource.
	/// </summary>
	public unsafe partial class Font : Resource
	{
		unsafe partial void OnFontCreated ();

		[Preserve]
		public Font (IntPtr handle) : base (handle)
		{
			OnFontCreated ();
		}

		[Preserve]
		protected Font (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnFontCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Font_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Font_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Font_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Font_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Font_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Font));
			return new StringHash (Font_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Font_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Font));
			return Marshal.PtrToStringAnsi (Font_GetTypeNameStatic ());
		}

		[Preserve]
		public Font () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Font_Font (IntPtr context);

		[Preserve]
		public Font (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Font));
			handle = Font_Font ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnFontCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Font_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Font));
			Font_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Font_BeginLoad_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Font_BeginLoad_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Font_BeginLoad_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Font_BeginLoad_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Font_SaveXML_File (IntPtr handle, IntPtr dest, int pointSize, bool usedGlyphs, string indentation);

		/// <summary>
		/// Save resource as a new bitmap font type in XML format. Return true if successful.
		/// </summary>
		public bool SaveXml (File dest, int pointSize, bool usedGlyphs = false, string indentation = "\t")
		{
			Runtime.ValidateRefCounted (this);
			return Font_SaveXML_File (handle, (object)dest == null ? IntPtr.Zero : dest.Handle, pointSize, usedGlyphs, indentation);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Font_SaveXML_MemoryBuffer (IntPtr handle, IntPtr dest, int pointSize, bool usedGlyphs, string indentation);

		/// <summary>
		/// Save resource as a new bitmap font type in XML format. Return true if successful.
		/// </summary>
		public bool SaveXml (MemoryBuffer dest, int pointSize, bool usedGlyphs = false, string indentation = "\t")
		{
			Runtime.ValidateRefCounted (this);
			return Font_SaveXML_MemoryBuffer (handle, (object)dest == null ? IntPtr.Zero : dest.Handle, pointSize, usedGlyphs, indentation);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Font_SetAbsoluteGlyphOffset (IntPtr handle, ref Urho.IntVector2 offset);

		/// <summary>
		/// Set absolute (in pixels) position adjustment for glyphs.
		/// 
		/// </summary>
		private void SetAbsoluteGlyphOffset (Urho.IntVector2 offset)
		{
			Runtime.ValidateRefCounted (this);
			Font_SetAbsoluteGlyphOffset (handle, ref offset);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Font_SetScaledGlyphOffset (IntPtr handle, ref Urho.Vector2 offset);

		/// <summary>
		/// Set point size scaled position adjustment for glyphs.
		/// 
		/// </summary>
		private void SetScaledGlyphOffset (Urho.Vector2 offset)
		{
			Runtime.ValidateRefCounted (this);
			Font_SetScaledGlyphOffset (handle, ref offset);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Font_GetFace (IntPtr handle, float pointSize);

		/// <summary>
		/// Return font face. Pack and render to a texture if not rendered yet. Return null on error.
		/// </summary>
		public FontFace GetFace (float pointSize)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<FontFace> (Font_GetFace (handle, pointSize));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern FontType Font_GetFontType (IntPtr handle);

		/// <summary>
		/// Return font type.
		/// 
		/// </summary>
		private FontType GetFontType ()
		{
			Runtime.ValidateRefCounted (this);
			return Font_GetFontType (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Font_IsSDFFont (IntPtr handle);

		/// <summary>
		/// Is signed distance field font.
		/// </summary>
		private bool IsSDFFont ()
		{
			Runtime.ValidateRefCounted (this);
			return Font_IsSDFFont (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.IntVector2 *
#else
Urho.IntVector2
#endif
 Font_GetAbsoluteGlyphOffset (IntPtr handle);

		/// <summary>
		/// Return absolute position adjustment for glyphs.
		/// 
		/// </summary>
		private Urho.IntVector2 GetAbsoluteGlyphOffset ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Font_GetAbsoluteGlyphOffset
#else
Font_GetAbsoluteGlyphOffset
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 Font_GetScaledGlyphOffset (IntPtr handle);

		/// <summary>
		/// Return point size scaled position adjustment for glyphs.
		/// 
		/// </summary>
		private Urho.Vector2 GetScaledGlyphOffset ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Font_GetScaledGlyphOffset
#else
Font_GetScaledGlyphOffset
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.IntVector2 *
#else
Urho.IntVector2
#endif
 Font_GetTotalGlyphOffset (IntPtr handle, float pointSize);

		/// <summary>
		/// Return the total effective offset for a point size.
		/// </summary>
		public Urho.IntVector2 GetTotalGlyphOffset (float pointSize)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Font_GetTotalGlyphOffset
#else
Font_GetTotalGlyphOffset
#endif
 (handle, pointSize);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Font_ReleaseFaces (IntPtr handle);

		/// <summary>
		/// Release font faces and recreate them next time when requested. Called when font textures lost or global font properties change.
		/// </summary>
		public void ReleaseFaces ()
		{
			Runtime.ValidateRefCounted (this);
			Font_ReleaseFaces (handle);
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
		/// Return absolute position adjustment for glyphs.
		/// 
		/// Or
		/// Set absolute (in pixels) position adjustment for glyphs.
		/// 
		/// </summary>
		public Urho.IntVector2 AbsoluteGlyphOffset {
			get {
				return GetAbsoluteGlyphOffset ();
			}
			set {
				SetAbsoluteGlyphOffset (value);
			}
		}

		/// <summary>
		/// Return point size scaled position adjustment for glyphs.
		/// 
		/// Or
		/// Set point size scaled position adjustment for glyphs.
		/// 
		/// </summary>
		public Urho.Vector2 ScaledGlyphOffset {
			get {
				return GetScaledGlyphOffset ();
			}
			set {
				SetScaledGlyphOffset (value);
			}
		}

		/// <summary>
		/// Return font type.
		/// 
		/// </summary>
		public FontType FontType {
			get {
				return GetFontType ();
			}
		}

		/// <summary>
		/// Is signed distance field font.
		/// </summary>
		public bool SDFFont {
			get {
				return IsSDFFont ();
			}
		}
	}
}
