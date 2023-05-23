// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ConstraintRevolute2D.cs
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
	/// 2D revolute constraint component.
	/// </summary>
	public unsafe partial class ConstraintRevolute2D : Constraint2D
	{
		unsafe partial void OnConstraintRevolute2DCreated ();

		[Preserve]
		public ConstraintRevolute2D (IntPtr handle) : base (handle)
		{
			OnConstraintRevolute2DCreated ();
		}

		[Preserve]
		protected ConstraintRevolute2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnConstraintRevolute2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintRevolute2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ConstraintRevolute2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintRevolute2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ConstraintRevolute2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintRevolute2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ConstraintRevolute2D));
			return new StringHash (ConstraintRevolute2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintRevolute2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ConstraintRevolute2D));
			return Marshal.PtrToStringAnsi (ConstraintRevolute2D_GetTypeNameStatic ());
		}

		[Preserve]
		public ConstraintRevolute2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintRevolute2D_ConstraintRevolute2D (IntPtr context);

		[Preserve]
		public ConstraintRevolute2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ConstraintRevolute2D));
			handle = ConstraintRevolute2D_ConstraintRevolute2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnConstraintRevolute2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ConstraintRevolute2D));
			ConstraintRevolute2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetAnchor (IntPtr handle, ref Urho.Vector2 anchor);

		/// <summary>
		/// Set anchor.
		/// 
		/// </summary>
		private void SetAnchor (Urho.Vector2 anchor)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetAnchor (handle, ref anchor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetEnableLimit (IntPtr handle, bool enableLimit);

		/// <summary>
		/// Set enable limit.
		/// 
		/// </summary>
		private void SetEnableLimit (bool enableLimit)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetEnableLimit (handle, enableLimit);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetLowerAngle (IntPtr handle, float lowerAngle);

		/// <summary>
		/// Set lower angle.
		/// 
		/// </summary>
		private void SetLowerAngle (float lowerAngle)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetLowerAngle (handle, lowerAngle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetUpperAngle (IntPtr handle, float upperAngle);

		/// <summary>
		/// Set upper angle.
		/// 
		/// </summary>
		private void SetUpperAngle (float upperAngle)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetUpperAngle (handle, upperAngle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetEnableMotor (IntPtr handle, bool enableMotor);

		/// <summary>
		/// Set enable motor.
		/// 
		/// </summary>
		private void SetEnableMotor (bool enableMotor)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetEnableMotor (handle, enableMotor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetMotorSpeed (IntPtr handle, float motorSpeed);

		/// <summary>
		/// Set motor speed.
		/// 
		/// </summary>
		private void SetMotorSpeed (float motorSpeed)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetMotorSpeed (handle, motorSpeed);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintRevolute2D_SetMaxMotorTorque (IntPtr handle, float maxMotorTorque);

		/// <summary>
		/// Set max motor torque.
		/// 
		/// </summary>
		private void SetMaxMotorTorque (float maxMotorTorque)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintRevolute2D_SetMaxMotorTorque (handle, maxMotorTorque);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 ConstraintRevolute2D_GetAnchor (IntPtr handle);

		/// <summary>
		/// Return anchor.
		/// 
		/// </summary>
		private Urho.Vector2 GetAnchor ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*ConstraintRevolute2D_GetAnchor
#else
ConstraintRevolute2D_GetAnchor
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ConstraintRevolute2D_GetEnableLimit (IntPtr handle);

		/// <summary>
		/// Return enable limit.
		/// 
		/// </summary>
		private bool GetEnableLimit ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintRevolute2D_GetEnableLimit (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintRevolute2D_GetLowerAngle (IntPtr handle);

		/// <summary>
		/// Return lower angle.
		/// 
		/// </summary>
		private float GetLowerAngle ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintRevolute2D_GetLowerAngle (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintRevolute2D_GetUpperAngle (IntPtr handle);

		/// <summary>
		/// Return upper angle.
		/// 
		/// </summary>
		private float GetUpperAngle ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintRevolute2D_GetUpperAngle (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ConstraintRevolute2D_GetEnableMotor (IntPtr handle);

		/// <summary>
		/// Return enable motor.
		/// 
		/// </summary>
		private bool GetEnableMotor ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintRevolute2D_GetEnableMotor (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintRevolute2D_GetMotorSpeed (IntPtr handle);

		/// <summary>
		/// Return motor speed.
		/// 
		/// </summary>
		private float GetMotorSpeed ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintRevolute2D_GetMotorSpeed (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintRevolute2D_GetMaxMotorTorque (IntPtr handle);

		/// <summary>
		/// Return max motor torque.
		/// 
		/// </summary>
		private float GetMaxMotorTorque ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintRevolute2D_GetMaxMotorTorque (handle);
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
		/// Return enable limit.
		/// 
		/// Or
		/// Set enable limit.
		/// 
		/// </summary>
		public bool EnableLimit {
			get {
				return GetEnableLimit ();
			}
			set {
				SetEnableLimit (value);
			}
		}

		/// <summary>
		/// Return lower angle.
		/// 
		/// Or
		/// Set lower angle.
		/// 
		/// </summary>
		public float LowerAngle {
			get {
				return GetLowerAngle ();
			}
			set {
				SetLowerAngle (value);
			}
		}

		/// <summary>
		/// Return upper angle.
		/// 
		/// Or
		/// Set upper angle.
		/// 
		/// </summary>
		public float UpperAngle {
			get {
				return GetUpperAngle ();
			}
			set {
				SetUpperAngle (value);
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
		/// Return max motor torque.
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
	}
}
