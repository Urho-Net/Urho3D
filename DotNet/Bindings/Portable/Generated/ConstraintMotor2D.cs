// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ConstraintMotor2D.cs
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
	/// 2D motor constraint component.
	/// </summary>
	public unsafe partial class ConstraintMotor2D : Constraint2D
	{
		unsafe partial void OnConstraintMotor2DCreated ();

		[Preserve]
		public ConstraintMotor2D (IntPtr handle) : base (handle)
		{
			OnConstraintMotor2DCreated ();
		}

		[Preserve]
		protected ConstraintMotor2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnConstraintMotor2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintMotor2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ConstraintMotor2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintMotor2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ConstraintMotor2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstraintMotor2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ConstraintMotor2D));
			return new StringHash (ConstraintMotor2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintMotor2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ConstraintMotor2D));
			return Marshal.PtrToStringAnsi (ConstraintMotor2D_GetTypeNameStatic ());
		}

		[Preserve]
		public ConstraintMotor2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstraintMotor2D_ConstraintMotor2D (IntPtr context);

		[Preserve]
		public ConstraintMotor2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ConstraintMotor2D));
			handle = ConstraintMotor2D_ConstraintMotor2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnConstraintMotor2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMotor2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ConstraintMotor2D));
			ConstraintMotor2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMotor2D_SetLinearOffset (IntPtr handle, ref Urho.Vector2 linearOffset);

		/// <summary>
		/// Set linear offset.
		/// 
		/// </summary>
		private void SetLinearOffset (Urho.Vector2 linearOffset)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMotor2D_SetLinearOffset (handle, ref linearOffset);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMotor2D_SetAngularOffset (IntPtr handle, float angularOffset);

		/// <summary>
		/// Set angular offset.
		/// 
		/// </summary>
		private void SetAngularOffset (float angularOffset)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMotor2D_SetAngularOffset (handle, angularOffset);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMotor2D_SetMaxForce (IntPtr handle, float maxForce);

		/// <summary>
		/// Set max force.
		/// 
		/// </summary>
		private void SetMaxForce (float maxForce)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMotor2D_SetMaxForce (handle, maxForce);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMotor2D_SetMaxTorque (IntPtr handle, float maxTorque);

		/// <summary>
		/// Set max torque.
		/// 
		/// </summary>
		private void SetMaxTorque (float maxTorque)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMotor2D_SetMaxTorque (handle, maxTorque);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstraintMotor2D_SetCorrectionFactor (IntPtr handle, float correctionFactor);

		/// <summary>
		/// Set correction factor.
		/// 
		/// </summary>
		private void SetCorrectionFactor (float correctionFactor)
		{
			Runtime.ValidateRefCounted (this);
			ConstraintMotor2D_SetCorrectionFactor (handle, correctionFactor);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 ConstraintMotor2D_GetLinearOffset (IntPtr handle);

		/// <summary>
		/// Return linear offset.
		/// 
		/// </summary>
		private Urho.Vector2 GetLinearOffset ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*ConstraintMotor2D_GetLinearOffset
#else
ConstraintMotor2D_GetLinearOffset
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMotor2D_GetAngularOffset (IntPtr handle);

		/// <summary>
		/// Return angular offset.
		/// 
		/// </summary>
		private float GetAngularOffset ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMotor2D_GetAngularOffset (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMotor2D_GetMaxForce (IntPtr handle);

		/// <summary>
		/// Return max force.
		/// 
		/// </summary>
		private float GetMaxForce ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMotor2D_GetMaxForce (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMotor2D_GetMaxTorque (IntPtr handle);

		/// <summary>
		/// Return max torque.
		/// 
		/// </summary>
		private float GetMaxTorque ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMotor2D_GetMaxTorque (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float ConstraintMotor2D_GetCorrectionFactor (IntPtr handle);

		/// <summary>
		/// Return correction factor.
		/// 
		/// </summary>
		private float GetCorrectionFactor ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstraintMotor2D_GetCorrectionFactor (handle);
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
		/// Return linear offset.
		/// 
		/// Or
		/// Set linear offset.
		/// 
		/// </summary>
		public Urho.Vector2 LinearOffset {
			get {
				return GetLinearOffset ();
			}
			set {
				SetLinearOffset (value);
			}
		}

		/// <summary>
		/// Return angular offset.
		/// 
		/// Or
		/// Set angular offset.
		/// 
		/// </summary>
		public float AngularOffset {
			get {
				return GetAngularOffset ();
			}
			set {
				SetAngularOffset (value);
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
		/// Return max torque.
		/// 
		/// Or
		/// Set max torque.
		/// 
		/// </summary>
		public float MaxTorque {
			get {
				return GetMaxTorque ();
			}
			set {
				SetMaxTorque (value);
			}
		}

		/// <summary>
		/// Return correction factor.
		/// 
		/// Or
		/// Set correction factor.
		/// 
		/// </summary>
		public float CorrectionFactor {
			get {
				return GetCorrectionFactor ();
			}
			set {
				SetCorrectionFactor (value);
			}
		}
	}
}
