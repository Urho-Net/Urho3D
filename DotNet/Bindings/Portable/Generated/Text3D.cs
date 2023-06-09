// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Text3D.cs
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

namespace Urho.Gui
{
	/// <summary>
	/// 3D text component.
	/// </summary>
	public unsafe partial class Text3D : Drawable
	{
		unsafe partial void OnText3DCreated ();

		[Preserve]
		public Text3D (IntPtr handle) : base (handle)
		{
			OnText3DCreated ();
		}

		[Preserve]
		protected Text3D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnText3DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Text3D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Text3D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Text3D));
			return new StringHash (Text3D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Text3D));
			return Marshal.PtrToStringAnsi (Text3D_GetTypeNameStatic ());
		}

		[Preserve]
		public Text3D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_Text3D (IntPtr context);

		[Preserve]
		public Text3D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Text3D));
			handle = Text3D_Text3D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnText3DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory. Drawable must be registered first.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Text3D));
			Text3D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_ApplyAttributes (IntPtr handle);

		/// <summary>
		/// Apply attribute changes that can not be applied immediately.
		/// </summary>
		public override void ApplyAttributes ()
		{
			Runtime.ValidateRefCounted (this);
			Text3D_ApplyAttributes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern UpdateGeometryType Text3D_GetUpdateGeometryType (IntPtr handle);

		/// <summary>
		/// Return whether a geometry update is necessary, and if it can happen in a worker thread.
		/// </summary>
		private UpdateGeometryType GetUpdateGeometryType ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetUpdateGeometryType (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Text3D_SetFont (IntPtr handle, string fontName, float size);

		/// <summary>
		/// Set font by looking from resource cache by name and font size. Return true if successful.
		/// </summary>
		public bool SetFont (string fontName, float size)
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_SetFont (handle, fontName, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Text3D_SetFont0 (IntPtr handle, IntPtr font, float size);

		/// <summary>
		/// Set font and font size. Return true if successful.
		/// </summary>
		public bool SetFont (Font font, float size)
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_SetFont0 (handle, (object)font == null ? IntPtr.Zero : font.Handle, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Text3D_SetFontSize (IntPtr handle, float size);

		/// <summary>
		/// Set font size only while retaining the existing font. Return true if successful.
		/// 
		/// </summary>
		public bool SetFontSize (float size)
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_SetFontSize (handle, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetMaterial (IntPtr handle, IntPtr material);

		/// <summary>
		/// Set material.
		/// 
		/// </summary>
		private void SetMaterial (Material material)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetMaterial (handle, (object)material == null ? IntPtr.Zero : material.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetText (IntPtr handle, string text);

		/// <summary>
		/// Set text. Text is assumed to be either ASCII or UTF8-encoded.
		/// 
		/// </summary>
		private void SetText (string text)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetText (handle, text);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetAlignment (IntPtr handle, HorizontalAlignment hAlign, VerticalAlignment vAlign);

		/// <summary>
		/// Set horizontal and vertical alignment.
		/// </summary>
		public void SetAlignment (HorizontalAlignment hAlign, VerticalAlignment vAlign)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetAlignment (handle, hAlign, vAlign);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetHorizontalAlignment (IntPtr handle, HorizontalAlignment align);

		/// <summary>
		/// Set horizontal alignment.
		/// 
		/// </summary>
		private void SetHorizontalAlignment (HorizontalAlignment align)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetHorizontalAlignment (handle, align);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetVerticalAlignment (IntPtr handle, VerticalAlignment align);

		/// <summary>
		/// Set vertical alignment.
		/// 
		/// </summary>
		private void SetVerticalAlignment (VerticalAlignment align)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetVerticalAlignment (handle, align);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetTextAlignment (IntPtr handle, HorizontalAlignment align);

		/// <summary>
		/// Set row alignment.
		/// 
		/// </summary>
		private void SetTextAlignment (HorizontalAlignment align)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetTextAlignment (handle, align);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetRowSpacing (IntPtr handle, float spacing);

		/// <summary>
		/// Set row spacing, 1.0 for original font spacing.
		/// 
		/// </summary>
		private void SetRowSpacing (float spacing)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetRowSpacing (handle, spacing);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetWordwrap (IntPtr handle, bool enable);

		/// <summary>
		/// Set wordwrap. In wordwrap mode the text element will respect its current width. Otherwise it resizes itself freely.
		/// 
		/// </summary>
		private void SetWordwrap (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetWordwrap (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetTextEffect (IntPtr handle, TextEffect textEffect);

		/// <summary>
		/// Set text effect.
		/// 
		/// </summary>
		private void SetTextEffect (TextEffect textEffect)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetTextEffect (handle, textEffect);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetEffectShadowOffset (IntPtr handle, ref Urho.IntVector2 offset);

		/// <summary>
		/// Set shadow offset.
		/// 
		/// </summary>
		private void SetEffectShadowOffset (Urho.IntVector2 offset)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetEffectShadowOffset (handle, ref offset);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetEffectStrokeThickness (IntPtr handle, int thickness);

		/// <summary>
		/// Set stroke thickness.
		/// 
		/// </summary>
		private void SetEffectStrokeThickness (int thickness)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetEffectStrokeThickness (handle, thickness);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetEffectRoundStroke (IntPtr handle, bool roundStroke);

		/// <summary>
		/// Set stroke rounding. Corners of the font will be rounded off in the stroke so the stroke won't have corners.
		/// 
		/// </summary>
		private void SetEffectRoundStroke (bool roundStroke)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetEffectRoundStroke (handle, roundStroke);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetEffectColor (IntPtr handle, ref Urho.Color effectColor);

		/// <summary>
		/// Set effect color.
		/// 
		/// </summary>
		private void SetEffectColor (Urho.Color effectColor)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetEffectColor (handle, ref effectColor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetEffectDepthBias (IntPtr handle, float bias);

		/// <summary>
		/// Set effect Z bias.
		/// 
		/// </summary>
		private void SetEffectDepthBias (float bias)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetEffectDepthBias (handle, bias);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetWidth (IntPtr handle, int width);

		/// <summary>
		/// Set text width. Only has effect in word wrap mode.
		/// 
		/// </summary>
		private void SetWidth (int width)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetWidth (handle, width);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetColor (IntPtr handle, ref Urho.Color color);

		/// <summary>
		/// Set color on all corners.
		/// 
		/// </summary>
		public void SetColor (Urho.Color color)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetColor (handle, ref color);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetColor1 (IntPtr handle, Corner corner, ref Urho.Color color);

		/// <summary>
		/// Set color on one corner.
		/// 
		/// </summary>
		public void SetColor (Corner corner, Urho.Color color)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetColor1 (handle, corner, ref color);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetOpacity (IntPtr handle, float opacity);

		/// <summary>
		/// Set opacity.
		/// 
		/// </summary>
		private void SetOpacity (float opacity)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetOpacity (handle, opacity);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetFixedScreenSize (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether text has fixed size on screen (pixel-perfect) regardless of distance to camera. Works best when combined with face camera rotation. Default false.
		/// 
		/// </summary>
		private void SetFixedScreenSize (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetFixedScreenSize (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetFaceCameraMode (IntPtr handle, FaceCameraMode mode);

		/// <summary>
		/// Set how the text should rotate in relation to the camera. Default is to not rotate (FC_NONE).
		/// 
		/// </summary>
		private void SetFaceCameraMode (FaceCameraMode mode)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetFaceCameraMode (handle, mode);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_GetFont (IntPtr handle);

		/// <summary>
		/// Return font.
		/// 
		/// </summary>
		private Font GetFont ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Font> (Text3D_GetFont (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Text3D_GetFontSize (IntPtr handle);

		/// <summary>
		/// Return font size.
		/// 
		/// </summary>
		private float GetFontSize ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetFontSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_GetMaterial (IntPtr handle);

		/// <summary>
		/// Return material.
		/// 
		/// </summary>
		private Material GetMaterial ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Material> (Text3D_GetMaterial (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_GetText (IntPtr handle);

		/// <summary>
		/// Return text.
		/// 
		/// </summary>
		private string GetText ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Text3D_GetText (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern HorizontalAlignment Text3D_GetTextAlignment (IntPtr handle);

		/// <summary>
		/// Return row alignment.
		/// 
		/// </summary>
		private HorizontalAlignment GetTextAlignment ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetTextAlignment (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern HorizontalAlignment Text3D_GetHorizontalAlignment (IntPtr handle);

		/// <summary>
		/// Return horizontal alignment.
		/// 
		/// </summary>
		private HorizontalAlignment GetHorizontalAlignment ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetHorizontalAlignment (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern VerticalAlignment Text3D_GetVerticalAlignment (IntPtr handle);

		/// <summary>
		/// Return vertical alignment.
		/// 
		/// </summary>
		private VerticalAlignment GetVerticalAlignment ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetVerticalAlignment (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Text3D_GetRowSpacing (IntPtr handle);

		/// <summary>
		/// Return row spacing.
		/// 
		/// </summary>
		private float GetRowSpacing ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetRowSpacing (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Text3D_GetWordwrap (IntPtr handle);

		/// <summary>
		/// Return wordwrap mode.
		/// 
		/// </summary>
		private bool GetWordwrap ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetWordwrap (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern TextEffect Text3D_GetTextEffect (IntPtr handle);

		/// <summary>
		/// Return text effect.
		/// 
		/// </summary>
		private TextEffect GetTextEffect ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetTextEffect (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.IntVector2 *
#else
Urho.IntVector2
#endif
 Text3D_GetEffectShadowOffset (IntPtr handle);

		/// <summary>
		/// Return effect shadow offset.
		/// 
		/// </summary>
		private Urho.IntVector2 GetEffectShadowOffset ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Text3D_GetEffectShadowOffset
#else
Text3D_GetEffectShadowOffset
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetEffectStrokeThickness (IntPtr handle);

		/// <summary>
		/// Return effect stroke thickness.
		/// 
		/// </summary>
		private int GetEffectStrokeThickness ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetEffectStrokeThickness (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Text3D_GetEffectRoundStroke (IntPtr handle);

		/// <summary>
		/// Return effect round stroke.
		/// 
		/// </summary>
		private bool GetEffectRoundStroke ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetEffectRoundStroke (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Color *
#else
Urho.Color
#endif
 Text3D_GetEffectColor (IntPtr handle);

		/// <summary>
		/// Return effect color.
		/// 
		/// </summary>
		private Urho.Color GetEffectColor ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Text3D_GetEffectColor
#else
Text3D_GetEffectColor
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Text3D_GetEffectDepthBias (IntPtr handle);

		/// <summary>
		/// Return effect depth bias.
		/// 
		/// </summary>
		private float GetEffectDepthBias ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetEffectDepthBias (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetWidth (IntPtr handle);

		/// <summary>
		/// Return text width.
		/// 
		/// </summary>
		private int GetWidth ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetWidth (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetHeight (IntPtr handle);

		/// <summary>
		/// Return text height.
		/// 
		/// </summary>
		private int GetHeight ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetHeight (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetRowHeight (IntPtr handle);

		/// <summary>
		/// Return row height.
		/// 
		/// </summary>
		private int GetRowHeight ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetRowHeight (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Text3D_GetNumRows (IntPtr handle);

		/// <summary>
		/// Return number of rows.
		/// 
		/// </summary>
		private uint GetNumRows ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetNumRows (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Text3D_GetNumChars (IntPtr handle);

		/// <summary>
		/// Return number of characters.
		/// 
		/// </summary>
		private uint GetNumChars ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetNumChars (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Text3D_GetRowWidth (IntPtr handle, uint index);

		/// <summary>
		/// Return width of row by index.
		/// 
		/// </summary>
		public int GetRowWidth (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetRowWidth (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector2 *
#else
Vector2
#endif
 Text3D_GetCharPosition (IntPtr handle, uint index);

		/// <summary>
		/// Return position of character by index relative to the text element origin.
		/// 
		/// </summary>
		public Vector2 GetCharPosition (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Text3D_GetCharPosition
#else
Text3D_GetCharPosition
#endif
 (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector2 *
#else
Vector2
#endif
 Text3D_GetCharSize (IntPtr handle, uint index);

		/// <summary>
		/// Return size of character by index.
		/// 
		/// </summary>
		public Vector2 GetCharSize (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Text3D_GetCharSize
#else
Text3D_GetCharSize
#endif
 (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Color *
#else
Urho.Color
#endif
 Text3D_GetColor (IntPtr handle, Corner corner);

		/// <summary>
		/// Return corner color.
		/// 
		/// </summary>
		public Urho.Color GetColor (Corner corner)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Text3D_GetColor
#else
Text3D_GetColor
#endif
 (handle, corner);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Text3D_GetOpacity (IntPtr handle);

		/// <summary>
		/// Return opacity.
		/// 
		/// </summary>
		private float GetOpacity ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetOpacity (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Text3D_IsFixedScreenSize (IntPtr handle);

		/// <summary>
		/// Return whether text has fixed screen size.
		/// 
		/// </summary>
		private bool IsFixedScreenSize ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_IsFixedScreenSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern FaceCameraMode Text3D_GetFaceCameraMode (IntPtr handle);

		/// <summary>
		/// Return how the text rotates in relation to the camera.
		/// 
		/// </summary>
		private FaceCameraMode GetFaceCameraMode ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetFaceCameraMode (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ResourceRef Text3D_GetFontAttr (IntPtr handle);

		/// <summary>
		/// Return font attribute.
		/// </summary>
		private ResourceRef GetFontAttr ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetFontAttr (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ResourceRef Text3D_GetMaterialAttr (IntPtr handle);

		/// <summary>
		/// Return material attribute.
		/// </summary>
		private ResourceRef GetMaterialAttr ()
		{
			Runtime.ValidateRefCounted (this);
			return Text3D_GetMaterialAttr (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Text3D_SetTextAttr (IntPtr handle, string value);

		/// <summary>
		/// Set text attribute.
		/// </summary>
		public void SetTextAttr (string value)
		{
			Runtime.ValidateRefCounted (this);
			Text3D_SetTextAttr (handle, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Text3D_GetTextAttr (IntPtr handle);

		/// <summary>
		/// Return text attribute.
		/// </summary>
		private string GetTextAttr ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Text3D_GetTextAttr (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Color *
#else
Urho.Color
#endif
 Text3D_GetColorAttr (IntPtr handle);

		/// <summary>
		/// Get color attribute. Uses just the top-left color.
		/// </summary>
		private Urho.Color GetColorAttr ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Text3D_GetColorAttr
#else
Text3D_GetColorAttr
#endif
 (handle);
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
		/// Return whether a geometry update is necessary, and if it can happen in a worker thread.
		/// </summary>
		public override UpdateGeometryType UpdateGeometryType {
			get {
				return GetUpdateGeometryType ();
			}
		}

		/// <summary>
		/// Return font size.
		/// 
		/// Or
		/// Set font size only while retaining the existing font. Return true if successful.
		/// 
		/// </summary>
		public float FontSize {
			get {
				return GetFontSize ();
			}
			set {
				SetFontSize (value);
			}
		}

		/// <summary>
		/// Return material.
		/// 
		/// Or
		/// Set material.
		/// 
		/// </summary>
		public Material Material {
			get {
				return GetMaterial ();
			}
			set {
				SetMaterial (value);
			}
		}

		/// <summary>
		/// Return text.
		/// 
		/// Or
		/// Set text. Text is assumed to be either ASCII or UTF8-encoded.
		/// 
		/// </summary>
		public string Text {
			get {
				return GetText ();
			}
			set {
				SetText (value);
			}
		}

		/// <summary>
		/// Return horizontal alignment.
		/// 
		/// Or
		/// Set horizontal alignment.
		/// 
		/// </summary>
		public HorizontalAlignment HorizontalAlignment {
			get {
				return GetHorizontalAlignment ();
			}
			set {
				SetHorizontalAlignment (value);
			}
		}

		/// <summary>
		/// Return vertical alignment.
		/// 
		/// Or
		/// Set vertical alignment.
		/// 
		/// </summary>
		public VerticalAlignment VerticalAlignment {
			get {
				return GetVerticalAlignment ();
			}
			set {
				SetVerticalAlignment (value);
			}
		}

		/// <summary>
		/// Return row alignment.
		/// 
		/// Or
		/// Set row alignment.
		/// 
		/// </summary>
		public HorizontalAlignment TextAlignment {
			get {
				return GetTextAlignment ();
			}
			set {
				SetTextAlignment (value);
			}
		}

		/// <summary>
		/// Return row spacing.
		/// 
		/// Or
		/// Set row spacing, 1.0 for original font spacing.
		/// 
		/// </summary>
		public float RowSpacing {
			get {
				return GetRowSpacing ();
			}
			set {
				SetRowSpacing (value);
			}
		}

		/// <summary>
		/// Return wordwrap mode.
		/// 
		/// Or
		/// Set wordwrap. In wordwrap mode the text element will respect its current width. Otherwise it resizes itself freely.
		/// 
		/// </summary>
		public bool Wordwrap {
			get {
				return GetWordwrap ();
			}
			set {
				SetWordwrap (value);
			}
		}

		/// <summary>
		/// Return text effect.
		/// 
		/// Or
		/// Set text effect.
		/// 
		/// </summary>
		public TextEffect TextEffect {
			get {
				return GetTextEffect ();
			}
			set {
				SetTextEffect (value);
			}
		}

		/// <summary>
		/// Return effect shadow offset.
		/// 
		/// Or
		/// Set shadow offset.
		/// 
		/// </summary>
		public Urho.IntVector2 EffectShadowOffset {
			get {
				return GetEffectShadowOffset ();
			}
			set {
				SetEffectShadowOffset (value);
			}
		}

		/// <summary>
		/// Return effect stroke thickness.
		/// 
		/// Or
		/// Set stroke thickness.
		/// 
		/// </summary>
		public int EffectStrokeThickness {
			get {
				return GetEffectStrokeThickness ();
			}
			set {
				SetEffectStrokeThickness (value);
			}
		}

		/// <summary>
		/// Return effect round stroke.
		/// 
		/// Or
		/// Set stroke rounding. Corners of the font will be rounded off in the stroke so the stroke won't have corners.
		/// 
		/// </summary>
		public bool EffectRoundStroke {
			get {
				return GetEffectRoundStroke ();
			}
			set {
				SetEffectRoundStroke (value);
			}
		}

		/// <summary>
		/// Return effect color.
		/// 
		/// Or
		/// Set effect color.
		/// 
		/// </summary>
		public Urho.Color EffectColor {
			get {
				return GetEffectColor ();
			}
			set {
				SetEffectColor (value);
			}
		}

		/// <summary>
		/// Return effect depth bias.
		/// 
		/// Or
		/// Set effect Z bias.
		/// 
		/// </summary>
		public float EffectDepthBias {
			get {
				return GetEffectDepthBias ();
			}
			set {
				SetEffectDepthBias (value);
			}
		}

		/// <summary>
		/// Return text width.
		/// 
		/// Or
		/// Set text width. Only has effect in word wrap mode.
		/// 
		/// </summary>
		public int Width {
			get {
				return GetWidth ();
			}
			set {
				SetWidth (value);
			}
		}

		/// <summary>
		/// Return opacity.
		/// 
		/// Or
		/// Set opacity.
		/// 
		/// </summary>
		public float Opacity {
			get {
				return GetOpacity ();
			}
			set {
				SetOpacity (value);
			}
		}

		/// <summary>
		/// Return whether text has fixed screen size.
		/// 
		/// Or
		/// Set whether text has fixed size on screen (pixel-perfect) regardless of distance to camera. Works best when combined with face camera rotation. Default false.
		/// 
		/// </summary>
		public bool FixedScreenSize {
			get {
				return IsFixedScreenSize ();
			}
			set {
				SetFixedScreenSize (value);
			}
		}

		/// <summary>
		/// Return how the text rotates in relation to the camera.
		/// 
		/// Or
		/// Set how the text should rotate in relation to the camera. Default is to not rotate (FC_NONE).
		/// 
		/// </summary>
		public FaceCameraMode FaceCameraMode {
			get {
				return GetFaceCameraMode ();
			}
			set {
				SetFaceCameraMode (value);
			}
		}

		/// <summary>
		/// Return font.
		/// 
		/// </summary>
		public Font Font {
			get {
				return GetFont ();
			}
		}

		/// <summary>
		/// Return text height.
		/// 
		/// </summary>
		public int Height {
			get {
				return GetHeight ();
			}
		}

		/// <summary>
		/// Return row height.
		/// 
		/// </summary>
		public int RowHeight {
			get {
				return GetRowHeight ();
			}
		}

		/// <summary>
		/// Return number of rows.
		/// 
		/// </summary>
		public uint NumRows {
			get {
				return GetNumRows ();
			}
		}

		/// <summary>
		/// Return number of characters.
		/// 
		/// </summary>
		public uint NumChars {
			get {
				return GetNumChars ();
			}
		}

		/// <summary>
		/// Return font attribute.
		/// </summary>
		public ResourceRef FontAttr {
			get {
				return GetFontAttr ();
			}
		}

		/// <summary>
		/// Return material attribute.
		/// </summary>
		public ResourceRef MaterialAttr {
			get {
				return GetMaterialAttr ();
			}
		}

		/// <summary>
		/// Return text attribute.
		/// </summary>
		public string TextAttr {
			get {
				return GetTextAttr ();
			}
		}

		/// <summary>
		/// Get color attribute. Uses just the top-left color.
		/// </summary>
		public Urho.Color ColorAttr {
			get {
				return GetColorAttr ();
			}
		}
	}
}
