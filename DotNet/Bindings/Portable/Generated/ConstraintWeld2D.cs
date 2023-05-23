// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ConstraintWeld2D.cs
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

namespace Urho.Urho2D
{
	/// <summary>
	/// 2D weld constraint component.
	/// </summary>
	public unsafe partial class ConstraintWeld2D : Constraint2D
	{
		unsafe partial void OnConstraintWeld2DCreated ();

		[Preserve]
		public ConstraintWeld2D (IntPtr handle) : base (handle)
		{
			OnConstraintWeld2DCreated ();
		}

		[Preserve]
		protected ConstraintWeld2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnConstraintWeld2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintWeld2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ConstraintWeld2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintWeld2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ConstraintWeld2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintWeld2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ConstraintWeld2D));
			return new StringHash (ConstraintWeld2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintWeld2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ConstraintWeld2D));
			return Marshal.PtrToStringAnsi (ConstraintWeld2D_GetTypeNameStatic ());
		}

		[Preserve]
		public ConstraintWeld2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintWeld2D_ConstraintWeld2D (IntPtr context);

		[Preserve]
		public ConstraintWeld2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ConstraintWeld2D));
			handle = ConstraintWeld2D_ConstraintWeld2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnConstraintWeld2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWeld2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ConstraintWeld2D));
			ConstraintWeld2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWeld2D_SetAnchor (IntPtr handle, ref Urho.Vector2 anchor);

		/// <summary>
		/// Set anchor.
		/// 
		/// </summary>
		private void SetAnchor (Urho.Vector2 anchor)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWeld2D_SetAnchor (handle, ref anchor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWeld2D_SetFrequencyHz (IntPtr handle, float frequencyHz);

		/// <summary>
		/// Set frequency Hz.
		/// 
		/// </summary>
		private void SetFrequencyHz (float frequencyHz)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWeld2D_SetFrequencyHz (handle, frequencyHz);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWeld2D_SetDampingRatio (IntPtr handle, float dampingRatio);

		/// <summary>
		/// Set damping ratio.
		/// 
		/// </summary>
		private void SetDampingRatio (float dampingRatio)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWeld2D_SetDampingRatio (handle, dampingRatio);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 ConstraintWeld2D_GetAnchor (IntPtr handle);

		/// <summary>
		/// Return anchor.
		/// 
		/// </summary>
		private Urho.Vector2 GetAnchor ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*ConstraintWeld2D_GetAnchor
#else
ConstraintWeld2D_GetAnchor
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintWeld2D_GetFrequencyHz (IntPtr handle);

		/// <summary>
		/// Return frequency Hz.
		/// 
		/// </summary>
		private float GetFrequencyHz ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWeld2D_GetFrequencyHz (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintWeld2D_GetDampingRatio (IntPtr handle);

		/// <summary>
		/// Return damping ratio.
		/// 
		/// </summary>
		private float GetDampingRatio ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWeld2D_GetDampingRatio (handle);
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
		/// Return anchor.
		/// 
		/// Or
		/// Set anchor.
		/// 
		/// </summary>
		public Urho.Vector2 Anchor {
			get {
				return GetAnchor ();
			}
			set {
				SetAnchor (value);
			}
		}

		/// <summary>
		/// Return frequency Hz.
		/// 
		/// Or
		/// Set frequency Hz.
		/// 
		/// </summary>
		public float FrequencyHz {
			get {
				return GetFrequencyHz ();
			}
			set {
				SetFrequencyHz (value);
			}
		}

		/// <summary>
		/// Return damping ratio.
		/// 
		/// Or
		/// Set damping ratio.
		/// 
		/// </summary>
		public float DampingRatio {
			get {
				return GetDampingRatio ();
			}
			set {
				SetDampingRatio (value);
			}
		}
	}
}
