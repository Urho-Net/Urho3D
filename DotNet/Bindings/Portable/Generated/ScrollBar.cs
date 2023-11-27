// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ScrollBar.cs
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
	/// Scroll bar %UI element with forward and back buttons.
	/// </summary>
	public unsafe partial class ScrollBar : BorderImage
	{
		unsafe partial void OnScrollBarCreated ();

		[Preserve]
		public ScrollBar (IntPtr handle) : base (handle)
		{
			OnScrollBarCreated ();
		}

		[Preserve]
		protected ScrollBar (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnScrollBarCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ScrollBar_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ScrollBar_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ScrollBar_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ScrollBar_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ScrollBar_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ScrollBar));
			return new StringHash (ScrollBar_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ScrollBar_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ScrollBar));
			return Marshal.PtrToStringAnsi (ScrollBar_GetTypeNameStatic ());
		}

		[Preserve]
		public ScrollBar () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ScrollBar_ScrollBar (IntPtr context);

		[Preserve]
		public ScrollBar (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ScrollBar));
			handle = ScrollBar_ScrollBar ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnScrollBarCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ScrollBar));
			ScrollBar_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_ApplyAttributes (IntPtr handle);

		/// <summary>
		/// Apply attribute changes that can not be applied immediately.
		/// </summary>
		public override void ApplyAttributes ()
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_ApplyAttributes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_OnResize (IntPtr handle, ref Urho.IntVector2 newSize, ref Urho.IntVector2 delta);

		/// <summary>
		/// React to resize.
		/// </summary>
		public override void OnResize (Urho.IntVector2 newSize, Urho.IntVector2 delta)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_OnResize (handle, ref newSize, ref delta);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_OnSetEditable (IntPtr handle);

		/// <summary>
		/// React to editable status change.
		/// </summary>
		public override void OnSetEditable ()
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_OnSetEditable (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_SetOrientation (IntPtr handle, Orientation orientation);

		/// <summary>
		/// Set orientation type.
		/// 
		/// </summary>
		private void SetOrientation (Orientation orientation)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_SetOrientation (handle, orientation);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_SetRange (IntPtr handle, float range);

		/// <summary>
		/// Set slider range maximum value (minimum value is always 0).
		/// 
		/// </summary>
		private void SetRange (float range)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_SetRange (handle, range);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_SetValue (IntPtr handle, float value);

		/// <summary>
		/// Set slider current value.
		/// 
		/// </summary>
		private void SetValue (float value)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_SetValue (handle, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_ChangeValue (IntPtr handle, float delta);

		/// <summary>
		/// Change slider current value by a delta.
		/// </summary>
		public void ChangeValue (float delta)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_ChangeValue (handle, delta);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_SetScrollStep (IntPtr handle, float step);

		/// <summary>
		/// Set button scroll step.
		/// 
		/// </summary>
		private void SetScrollStep (float step)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_SetScrollStep (handle, step);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_SetStepFactor (IntPtr handle, float factor);

		/// <summary>
		/// Set button step factor, can be used to adjust the step for constant pixel size.
		/// 
		/// </summary>
		private void SetStepFactor (float factor)
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_SetStepFactor (handle, factor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_StepBack (IntPtr handle);

		/// <summary>
		/// Scroll back one step.
		/// </summary>
		public void StepBack ()
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_StepBack (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ScrollBar_StepForward (IntPtr handle);

		/// <summary>
		/// Scroll forward one step.
		/// </summary>
		public void StepForward ()
		{
			Runtime.ValidateRefCounted (this);
			ScrollBar_StepForward (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Orientation ScrollBar_GetOrientation (IntPtr handle);

		/// <summary>
		/// Return scrollbar orientation.
		/// 
		/// </summary>
		private Orientation GetOrientation ()
		{
			Runtime.ValidateRefCounted (this);
			return ScrollBar_GetOrientation (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ScrollBar_GetRange (IntPtr handle);

		/// <summary>
		/// Return slider range.
		/// 
		/// </summary>
		private float GetRange ()
		{
			Runtime.ValidateRefCounted (this);
			return ScrollBar_GetRange (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ScrollBar_GetValue (IntPtr handle);

		/// <summary>
		/// Return slider current value.
		/// 
		/// </summary>
		private float GetValue ()
		{
			Runtime.ValidateRefCounted (this);
			return ScrollBar_GetValue (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ScrollBar_GetScrollStep (IntPtr handle);

		/// <summary>
		/// Return button scroll step.
		/// 
		/// </summary>
		private float GetScrollStep ()
		{
			Runtime.ValidateRefCounted (this);
			return ScrollBar_GetScrollStep (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ScrollBar_GetStepFactor (IntPtr handle);

		/// <summary>
		/// Return button step factor.
		/// 
		/// </summary>
		private float GetStepFactor ()
		{
			Runtime.ValidateRefCounted (this);
			return ScrollBar_GetStepFactor (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ScrollBar_GetEffectiveScrollStep (IntPtr handle);

		/// <summary>
		/// Return scroll step multiplied by factor.
		/// 
		/// </summary>
		private float GetEffectiveScrollStep ()
		{
			Runtime.ValidateRefCounted (this);
			return ScrollBar_GetEffectiveScrollStep (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ScrollBar_GetBackButton (IntPtr handle);

		/// <summary>
		/// Return back button element.
		/// 
		/// </summary>
		private Button GetBackButton ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Button> (ScrollBar_GetBackButton (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ScrollBar_GetForwardButton (IntPtr handle);

		/// <summary>
		/// Return forward button element.
		/// 
		/// </summary>
		private Button GetForwardButton ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Button> (ScrollBar_GetForwardButton (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ScrollBar_GetSlider (IntPtr handle);

		/// <summary>
		/// Return slider element.
		/// 
		/// </summary>
		private Slider GetSlider ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Slider> (ScrollBar_GetSlider (handle));
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
		/// Return scrollbar orientation.
		/// 
		/// Or
		/// Set orientation type.
		/// 
		/// </summary>
		public Orientation Orientation {
			get {
				return GetOrientation ();
			}
			set {
				SetOrientation (value);
			}
		}

		/// <summary>
		/// Return slider range.
		/// 
		/// Or
		/// Set slider range maximum value (minimum value is always 0).
		/// 
		/// </summary>
		public float Range {
			get {
				return GetRange ();
			}
			set {
				SetRange (value);
			}
		}

		/// <summary>
		/// Return slider current value.
		/// 
		/// Or
		/// Set slider current value.
		/// 
		/// </summary>
		public float Value {
			get {
				return GetValue ();
			}
			set {
				SetValue (value);
			}
		}

		/// <summary>
		/// Return button scroll step.
		/// 
		/// Or
		/// Set button scroll step.
		/// 
		/// </summary>
		public float ScrollStep {
			get {
				return GetScrollStep ();
			}
			set {
				SetScrollStep (value);
			}
		}

		/// <summary>
		/// Return button step factor.
		/// 
		/// Or
		/// Set button step factor, can be used to adjust the step for constant pixel size.
		/// 
		/// </summary>
		public float StepFactor {
			get {
				return GetStepFactor ();
			}
			set {
				SetStepFactor (value);
			}
		}

		/// <summary>
		/// Return scroll step multiplied by factor.
		/// 
		/// </summary>
		public float EffectiveScrollStep {
			get {
				return GetEffectiveScrollStep ();
			}
		}

		/// <summary>
		/// Return back button element.
		/// 
		/// </summary>
		public Button BackButton {
			get {
				return GetBackButton ();
			}
		}

		/// <summary>
		/// Return forward button element.
		/// 
		/// </summary>
		public Button ForwardButton {
			get {
				return GetForwardButton ();
			}
		}

		/// <summary>
		/// Return slider element.
		/// 
		/// </summary>
		public Slider Slider {
			get {
				return GetSlider ();
			}
		}
	}
}
