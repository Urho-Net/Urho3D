// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ConstraintMouse2D.cs
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

namespace Urho.Urho2D
{
	/// <summary>
	/// 2D mouse constraint component.
	/// </summary>
	public unsafe partial class ConstraintMouse2D : Constraint2D
	{
		unsafe partial void OnConstraintMouse2DCreated ();

		[Preserve]
		public ConstraintMouse2D (IntPtr handle) : base (handle)
		{
			OnConstraintMouse2DCreated ();
		}

		[Preserve]
		protected ConstraintMouse2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnConstraintMouse2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintMouse2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ConstraintMouse2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintMouse2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ConstraintMouse2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintMouse2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ConstraintMouse2D));
			return new StringHash (ConstraintMouse2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintMouse2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ConstraintMouse2D));
			return Marshal.PtrToStringAnsi (ConstraintMouse2D_GetTypeNameStatic ());
		}

		[Preserve]
		public ConstraintMouse2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintMouse2D_ConstraintMouse2D (IntPtr context);

		[Preserve]
		public ConstraintMouse2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ConstraintMouse2D));
			handle = ConstraintMouse2D_ConstraintMouse2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnConstraintMouse2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMouse2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ConstraintMouse2D));
			ConstraintMouse2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMouse2D_SetTarget (IntPtr handle, ref Urho.Vector2 target);

		/// <summary>
		/// Set target.
		/// 
		/// </summary>
		private void SetTarget (Urho.Vector2 target)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMouse2D_SetTarget (handle, ref target);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMouse2D_SetMaxForce (IntPtr handle, float maxForce);

		/// <summary>
		/// Set max force.
		/// 
		/// </summary>
		private void SetMaxForce (float maxForce)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMouse2D_SetMaxForce (handle, maxForce);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMouse2D_SetFrequencyHz (IntPtr handle, float frequencyHz);

		/// <summary>
		/// Set frequency Hz.
		/// 
		/// </summary>
		private void SetFrequencyHz (float frequencyHz)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMouse2D_SetFrequencyHz (handle, frequencyHz);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMouse2D_SetDampingRatio (IntPtr handle, float dampingRatio);

		/// <summary>
		/// Set damping ratio.
		/// 
		/// </summary>
		private void SetDampingRatio (float dampingRatio)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMouse2D_SetDampingRatio (handle, dampingRatio);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 ConstraintMouse2D_GetTarget (IntPtr handle);

		/// <summary>
		/// Return target.
		/// 
		/// </summary>
		private Urho.Vector2 GetTarget ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*ConstraintMouse2D_GetTarget
#else
ConstraintMouse2D_GetTarget
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMouse2D_GetMaxForce (IntPtr handle);

		/// <summary>
		/// Return max force.
		/// 
		/// </summary>
		private float GetMaxForce ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMouse2D_GetMaxForce (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMouse2D_GetFrequencyHz (IntPtr handle);

		/// <summary>
		/// Return frequency Hz.
		/// 
		/// </summary>
		private float GetFrequencyHz ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMouse2D_GetFrequencyHz (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMouse2D_GetDampingRatio (IntPtr handle);

		/// <summary>
		/// Return damping ratio.
		/// 
		/// </summary>
		private float GetDampingRatio ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMouse2D_GetDampingRatio (handle);
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
		/// Return target.
		/// 
		/// Or
		/// Set target.
		/// 
		/// </summary>
		public Urho.Vector2 Target {
			get {
				return GetTarget ();
			}
			set {
				SetTarget (value);
			}
		}

		/// <summary>
		/// Return max force.
		/// 
		/// Or
		/// Set max force.
		/// 
		/// </summary>
		public float MaxForce {
			get {
				return GetMaxForce ();
			}
			set {
				SetMaxForce (value);
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
