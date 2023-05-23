// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// CollisionShape2D.cs
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
	/// 2D collision shape component.
	/// </summary>
	public unsafe partial class CollisionShape2D : Component
	{
		unsafe partial void OnCollisionShape2DCreated ();

		[Preserve]
		public CollisionShape2D (IntPtr handle) : base (handle)
		{
			OnCollisionShape2DCreated ();
		}

		[Preserve]
		protected CollisionShape2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnCollisionShape2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionShape2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (CollisionShape2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CollisionShape2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (CollisionShape2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionShape2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(CollisionShape2D));
			return new StringHash (CollisionShape2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CollisionShape2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(CollisionShape2D));
			return Marshal.PtrToStringAnsi (CollisionShape2D_GetTypeNameStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(CollisionShape2D));
			CollisionShape2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_OnSetEnabled (IntPtr handle);

		/// <summary>
		/// Handle enabled/disabled state change.
		/// </summary>
		public override void OnSetEnabled ()
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_OnSetEnabled (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetTrigger (IntPtr handle, bool trigger);

		/// <summary>
		/// Set trigger.
		/// 
		/// </summary>
		private void SetTrigger (bool trigger)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetTrigger (handle, trigger);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetCategoryBits (IntPtr handle, int categoryBits);

		/// <summary>
		/// Set filter category bits.
		/// 
		/// </summary>
		private void SetCategoryBits (int categoryBits)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetCategoryBits (handle, categoryBits);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetMaskBits (IntPtr handle, int maskBits);

		/// <summary>
		/// Set filter mask bits.
		/// 
		/// </summary>
		private void SetMaskBits (int maskBits)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetMaskBits (handle, maskBits);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetGroupIndex (IntPtr handle, int groupIndex);

		/// <summary>
		/// Set filter group index.
		/// 
		/// </summary>
		private void SetGroupIndex (int groupIndex)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetGroupIndex (handle, groupIndex);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetDensity (IntPtr handle, float density);

		/// <summary>
		/// Set density.
		/// 
		/// </summary>
		private void SetDensity (float density)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetDensity (handle, density);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetFriction (IntPtr handle, float friction);

		/// <summary>
		/// Set friction.
		/// 
		/// </summary>
		private void SetFriction (float friction)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetFriction (handle, friction);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_SetRestitution (IntPtr handle, float restitution);

		/// <summary>
		/// Set restitution.
		/// 
		/// </summary>
		private void SetRestitution (float restitution)
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_SetRestitution (handle, restitution);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_CreateFixture (IntPtr handle);

		/// <summary>
		/// Create fixture.
		/// </summary>
		public void CreateFixture ()
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_CreateFixture (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionShape2D_ReleaseFixture (IntPtr handle);

		/// <summary>
		/// Release fixture.
		/// </summary>
		public void ReleaseFixture ()
		{
			Runtime.ValidateRefCounted (this);
			CollisionShape2D_ReleaseFixture (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool CollisionShape2D_IsTrigger (IntPtr handle);

		/// <summary>
		/// Return trigger.
		/// 
		/// </summary>
		private bool IsTrigger ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_IsTrigger (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionShape2D_GetCategoryBits (IntPtr handle);

		/// <summary>
		/// Return filter category bits.
		/// 
		/// </summary>
		private int GetCategoryBits ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetCategoryBits (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionShape2D_GetMaskBits (IntPtr handle);

		/// <summary>
		/// Return filter mask bits.
		/// 
		/// </summary>
		private int GetMaskBits ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetMaskBits (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionShape2D_GetGroupIndex (IntPtr handle);

		/// <summary>
		/// Return filter group index.
		/// 
		/// </summary>
		private int GetGroupIndex ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetGroupIndex (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CollisionShape2D_GetDensity (IntPtr handle);

		/// <summary>
		/// Return density.
		/// 
		/// </summary>
		private float GetDensity ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetDensity (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CollisionShape2D_GetFriction (IntPtr handle);

		/// <summary>
		/// Return friction.
		/// 
		/// </summary>
		private float GetFriction ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetFriction (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CollisionShape2D_GetRestitution (IntPtr handle);

		/// <summary>
		/// Return restitution.
		/// 
		/// </summary>
		private float GetRestitution ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetRestitution (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CollisionShape2D_GetMass (IntPtr handle);

		/// <summary>
		/// Return mass.
		/// 
		/// </summary>
		private float GetMass ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetMass (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CollisionShape2D_GetInertia (IntPtr handle);

		/// <summary>
		/// Return inertia.
		/// 
		/// </summary>
		private float GetInertia ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionShape2D_GetInertia (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector2 *
#else
Vector2
#endif
 CollisionShape2D_GetMassCenter (IntPtr handle);

		/// <summary>
		/// Return mass center.
		/// 
		/// </summary>
		private Vector2 GetMassCenter ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CollisionShape2D_GetMassCenter
#else
CollisionShape2D_GetMassCenter
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
		/// Return trigger.
		/// 
		/// Or
		/// Set trigger.
		/// 
		/// </summary>
		public bool Trigger {
			get {
				return IsTrigger ();
			}
			set {
				SetTrigger (value);
			}
		}

		/// <summary>
		/// Return filter category bits.
		/// 
		/// Or
		/// Set filter category bits.
		/// 
		/// </summary>
		public int CategoryBits {
			get {
				return GetCategoryBits ();
			}
			set {
				SetCategoryBits (value);
			}
		}

		/// <summary>
		/// Return filter mask bits.
		/// 
		/// Or
		/// Set filter mask bits.
		/// 
		/// </summary>
		public int MaskBits {
			get {
				return GetMaskBits ();
			}
			set {
				SetMaskBits (value);
			}
		}

		/// <summary>
		/// Return filter group index.
		/// 
		/// Or
		/// Set filter group index.
		/// 
		/// </summary>
		public int GroupIndex {
			get {
				return GetGroupIndex ();
			}
			set {
				SetGroupIndex (value);
			}
		}

		/// <summary>
		/// Return density.
		/// 
		/// Or
		/// Set density.
		/// 
		/// </summary>
		public float Density {
			get {
				return GetDensity ();
			}
			set {
				SetDensity (value);
			}
		}

		/// <summary>
		/// Return friction.
		/// 
		/// Or
		/// Set friction.
		/// 
		/// </summary>
		public float Friction {
			get {
				return GetFriction ();
			}
			set {
				SetFriction (value);
			}
		}

		/// <summary>
		/// Return restitution.
		/// 
		/// Or
		/// Set restitution.
		/// 
		/// </summary>
		public float Restitution {
			get {
				return GetRestitution ();
			}
			set {
				SetRestitution (value);
			}
		}

		/// <summary>
		/// Return mass.
		/// 
		/// </summary>
		public float Mass {
			get {
				return GetMass ();
			}
		}

		/// <summary>
		/// Return inertia.
		/// 
		/// </summary>
		public float Inertia {
			get {
				return GetInertia ();
			}
		}

		/// <summary>
		/// Return mass center.
		/// 
		/// </summary>
		public Vector2 MassCenter {
			get {
				return GetMassCenter ();
			}
		}
	}
}
