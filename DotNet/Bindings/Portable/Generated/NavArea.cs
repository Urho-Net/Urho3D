// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// NavArea.cs
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
using ListView = Urho.Gui.ListView;
using Button = Urho.Gui.Button;

namespace Urho.Navigation
{
	/// <summary>
	/// Construct.
	/// </summary>
	public unsafe partial class NavArea : Component
	{
		unsafe partial void OnNavAreaCreated ();

		[Preserve]
		public NavArea (IntPtr handle) : base (handle)
		{
			OnNavAreaCreated ();
		}

		[Preserve]
		protected NavArea (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnNavAreaCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int NavArea_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (NavArea_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr NavArea_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (NavArea_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int NavArea_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(NavArea));
			return new StringHash (NavArea_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr NavArea_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(NavArea));
			return Marshal.PtrToStringAnsi (NavArea_GetTypeNameStatic ());
		}

		[Preserve]
		public NavArea () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr NavArea_NavArea (IntPtr context);

		[Preserve]
		public NavArea (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(NavArea));
			handle = NavArea_NavArea ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnNavAreaCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void NavArea_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory and attributes.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(NavArea));
			NavArea_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void NavArea_DrawDebugGeometry (IntPtr handle, IntPtr debug, bool depthTest);

		/// <summary>
		/// Render debug geometry for the bounds.
		/// </summary>
		public override void DrawDebugGeometry (DebugRenderer debug, bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			NavArea_DrawDebugGeometry (handle, (object)debug == null ? IntPtr.Zero : debug.Handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint NavArea_GetAreaID (IntPtr handle);

		/// <summary>
		/// Get the area id for this volume.
		/// 
		/// </summary>
		private uint GetAreaID ()
		{
			Runtime.ValidateRefCounted (this);
			return NavArea_GetAreaID (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void NavArea_SetAreaID (IntPtr handle, uint newID);

		/// <summary>
		/// Set the area id for this volume.
		/// 
		/// </summary>
		private void SetAreaID (uint newID)
		{
			Runtime.ValidateRefCounted (this);
			NavArea_SetAreaID (handle, newID);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
BoundingBox *
#else
BoundingBox
#endif
 NavArea_GetBoundingBox (IntPtr handle);

		/// <summary>
		/// Get the bounding box of this navigation area, in local space.
		/// 
		/// </summary>
		private BoundingBox GetBoundingBox ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*NavArea_GetBoundingBox
#else
NavArea_GetBoundingBox
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void NavArea_SetBoundingBox (IntPtr handle, ref Urho.BoundingBox bnds);

		/// <summary>
		/// Set the bounding box of this area, in local space.
		/// 
		/// </summary>
		public void SetBoundingBox (Urho.BoundingBox bnds)
		{
			Runtime.ValidateRefCounted (this);
			NavArea_SetBoundingBox (handle, ref bnds);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
BoundingBox *
#else
BoundingBox
#endif
 NavArea_GetWorldBoundingBox (IntPtr handle);

		/// <summary>
		/// Get the bounds of this navigation area in world space.
		/// 
		/// </summary>
		private BoundingBox GetWorldBoundingBox ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*NavArea_GetWorldBoundingBox
#else
NavArea_GetWorldBoundingBox
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
		/// Get the area id for this volume.
		/// 
		/// Or
		/// Set the area id for this volume.
		/// 
		/// </summary>
		public uint AreaID {
			get {
				return GetAreaID ();
			}
			set {
				SetAreaID (value);
			}
		}

		/// <summary>
		/// Get the bounding box of this navigation area, in local space.
		/// 
		/// </summary>
		public BoundingBox BoundingBox {
			get {
				return GetBoundingBox ();
			}
		}

		/// <summary>
		/// Get the bounds of this navigation area in world space.
		/// 
		/// </summary>
		public BoundingBox WorldBoundingBox {
			get {
				return GetWorldBoundingBox ();
			}
		}
	}
}
