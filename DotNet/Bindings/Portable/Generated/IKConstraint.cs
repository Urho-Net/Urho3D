// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// IKConstraint.cs
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

namespace Urho
{
	/// <summary>
	/// Constructs a new IK constraint.
	/// </summary>
	public unsafe partial class IKConstraint : Component
	{
		unsafe partial void OnIKConstraintCreated ();

		[Preserve]
		public IKConstraint (IntPtr handle) : base (handle)
		{
			OnIKConstraintCreated ();
		}

		[Preserve]
		protected IKConstraint (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnIKConstraintCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int IKConstraint_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (IKConstraint_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKConstraint_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (IKConstraint_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int IKConstraint_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(IKConstraint));
			return new StringHash (IKConstraint_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKConstraint_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(IKConstraint));
			return Marshal.PtrToStringAnsi (IKConstraint_GetTypeNameStatic ());
		}

		[Preserve]
		public IKConstraint () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKConstraint_IKConstraint (IntPtr context);

		[Preserve]
		public IKConstraint (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(IKConstraint));
			handle = IKConstraint_IKConstraint ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnIKConstraintCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKConstraint_RegisterObject (IntPtr context);

		/// <summary>
		/// Registers this class as an object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(IKConstraint));
			IKConstraint_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float IKConstraint_GetStiffness (IntPtr handle);

		private float GetStiffness ()
		{
			Runtime.ValidateRefCounted (this);
			return IKConstraint_GetStiffness (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKConstraint_SetStiffness (IntPtr handle, float stiffness);

		private void SetStiffness (float stiffness)
		{
			Runtime.ValidateRefCounted (this);
			IKConstraint_SetStiffness (handle, stiffness);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float IKConstraint_GetStretchiness (IntPtr handle);

		private float GetStretchiness ()
		{
			Runtime.ValidateRefCounted (this);
			return IKConstraint_GetStretchiness (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKConstraint_SetStretchiness (IntPtr handle, float stretchiness);

		private void SetStretchiness (float stretchiness)
		{
			Runtime.ValidateRefCounted (this);
			IKConstraint_SetStretchiness (handle, stretchiness);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 IKConstraint_GetLengthConstraints (IntPtr handle);

		private Urho.Vector2 GetLengthConstraints ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*IKConstraint_GetLengthConstraints
#else
IKConstraint_GetLengthConstraints
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKConstraint_SetLengthConstraints (IntPtr handle, ref Urho.Vector2 lengthConstraints);

		private void SetLengthConstraints (Urho.Vector2 lengthConstraints)
		{
			Runtime.ValidateRefCounted (this);
			IKConstraint_SetLengthConstraints (handle, ref lengthConstraints);
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

		public float Stiffness {
			get {
				return GetStiffness ();
			}
			set {
				SetStiffness (value);
			}
		}

		public float Stretchiness {
			get {
				return GetStretchiness ();
			}
			set {
				SetStretchiness (value);
			}
		}

		public Urho.Vector2 LengthConstraints {
			get {
				return GetLengthConstraints ();
			}
			set {
				SetLengthConstraints (value);
			}
		}
	}
}
