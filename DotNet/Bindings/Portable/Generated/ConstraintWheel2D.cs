// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ConstraintWheel2D.cs
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
	/// 2D wheel constraint component.
	/// </summary>
	public unsafe partial class ConstraintWheel2D : Constraint2D
	{
		unsafe partial void OnConstraintWheel2DCreated ();

		[Preserve]
		public ConstraintWheel2D (IntPtr handle) : base (handle)
		{
			OnConstraintWheel2DCreated ();
		}

		[Preserve]
		protected ConstraintWheel2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnConstraintWheel2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintWheel2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ConstraintWheel2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintWheel2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ConstraintWheel2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintWheel2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ConstraintWheel2D));
			return new StringHash (ConstraintWheel2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintWheel2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ConstraintWheel2D));
			return Marshal.PtrToStringAnsi (ConstraintWheel2D_GetTypeNameStatic ());
		}

		[Preserve]
		public ConstraintWheel2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintWheel2D_ConstraintWheel2D (IntPtr context);

		[Preserve]
		public ConstraintWheel2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ConstraintWheel2D));
			handle = ConstraintWheel2D_ConstraintWheel2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnConstraintWheel2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ConstraintWheel2D));
			ConstraintWheel2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetAnchor (IntPtr handle, ref Urho.Vector2 anchor);

		/// <summary>
		/// Set anchor.
		/// 
		/// </summary>
		private void SetAnchor (Urho.Vector2 anchor)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetAnchor (handle, ref anchor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetAxis (IntPtr handle, ref Urho.Vector2 axis);

		/// <summary>
		/// Set axis.
		/// 
		/// </summary>
		private void SetAxis (Urho.Vector2 axis)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetAxis (handle, ref axis);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetEnableMotor (IntPtr handle, bool enableMotor);

		/// <summary>
		/// Set enable motor.
		/// 
		/// </summary>
		private void SetEnableMotor (bool enableMotor)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetEnableMotor (handle, enableMotor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetMaxMotorTorque (IntPtr handle, float maxMotorTorque);

		/// <summary>
		/// Set max motor torque.
		/// 
		/// </summary>
		private void SetMaxMotorTorque (float maxMotorTorque)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetMaxMotorTorque (handle, maxMotorTorque);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetMotorSpeed (IntPtr handle, float motorSpeed);

		/// <summary>
		/// Set motor speed.
		/// 
		/// </summary>
		private void SetMotorSpeed (float motorSpeed)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetMotorSpeed (handle, motorSpeed);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetFrequencyHz (IntPtr handle, float frequencyHz);

		/// <summary>
		/// Set frequency Hz.
		/// 
		/// </summary>
		private void SetFrequencyHz (float frequencyHz)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetFrequencyHz (handle, frequencyHz);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintWheel2D_SetDampingRatio (IntPtr handle, float dampingRatio);

		/// <summary>
		/// Set damping ratio.
		/// 
		/// </summary>
		private void SetDampingRatio (float dampingRatio)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintWheel2D_SetDampingRatio (handle, dampingRatio);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 ConstraintWheel2D_GetAnchor (IntPtr handle);

		/// <summary>
		/// Return anchor.
		/// 
		/// </summary>
		private Urho.Vector2 GetAnchor ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*ConstraintWheel2D_GetAnchor
#else
ConstraintWheel2D_GetAnchor
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
 ConstraintWheel2D_GetAxis (IntPtr handle);

		/// <summary>
		/// Return axis.
		/// 
		/// </summary>
		private Urho.Vector2 GetAxis ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*ConstraintWheel2D_GetAxis
#else
ConstraintWheel2D_GetAxis
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ConstraintWheel2D_GetEnableMotor (IntPtr handle);

		/// <summary>
		/// Return enable motor.
		/// 
		/// </summary>
		private bool GetEnableMotor ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWheel2D_GetEnableMotor (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintWheel2D_GetMaxMotorTorque (IntPtr handle);

		/// <summary>
		/// Return maxMotor torque.
		/// 
		/// </summary>
		private float GetMaxMotorTorque ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWheel2D_GetMaxMotorTorque (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintWheel2D_GetMotorSpeed (IntPtr handle);

		/// <summary>
		/// Return motor speed.
		/// 
		/// </summary>
		private float GetMotorSpeed ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWheel2D_GetMotorSpeed (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintWheel2D_GetFrequencyHz (IntPtr handle);

		/// <summary>
		/// Return frequency Hz.
		/// 
		/// </summary>
		private float GetFrequencyHz ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWheel2D_GetFrequencyHz (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintWheel2D_GetDampingRatio (IntPtr handle);

		/// <summary>
		/// Return damping ratio.
		/// 
		/// </summary>
		private float GetDampingRatio ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintWheel2D_GetDampingRatio (handle);
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
		/// Return axis.
		/// 
		/// Or
		/// Set axis.
		/// 
		/// </summary>
		public Urho.Vector2 Axis {
			get {
				return GetAxis ();
			}
			set {
				SetAxis (value);
			}
		}

		/// <summary>
		/// Return enable motor.
		/// 
		/// Or
		/// Set enable motor.
		/// 
		/// </summary>
		public bool EnableMotor {
			get {
				return GetEnableMotor ();
			}
			set {
				SetEnableMotor (value);
			}
		}

		/// <summary>
		/// Return maxMotor torque.
		/// 
		/// Or
		/// Set max motor torque.
		/// 
		/// </summary>
		public float MaxMotorTorque {
			get {
				return GetMaxMotorTorque ();
			}
			set {
				SetMaxMotorTorque (value);
			}
		}

		/// <summary>
		/// Return motor speed.
		/// 
		/// Or
		/// Set motor speed.
		/// 
		/// </summary>
		public float MotorSpeed {
			get {
				return GetMotorSpeed ();
			}
			set {
				SetMotorSpeed (value);
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
