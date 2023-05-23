// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// HierarchyContainer.cs
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

namespace Urho
{
	/// <summary>
	/// Hierarchy container (used by ListView internally when in hierarchy mode).
	/// </summary>
	public unsafe partial class HierarchyContainer : UIElement
	{
		unsafe partial void OnHierarchyContainerCreated ();

		[Preserve]
		public HierarchyContainer (IntPtr handle) : base (handle)
		{
			OnHierarchyContainerCreated ();
		}

		[Preserve]
		protected HierarchyContainer (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnHierarchyContainerCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int HierarchyContainer_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (HierarchyContainer_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr HierarchyContainer_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (HierarchyContainer_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int HierarchyContainer_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(HierarchyContainer));
			return new StringHash (HierarchyContainer_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr HierarchyContainer_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(HierarchyContainer));
			return Marshal.PtrToStringAnsi (HierarchyContainer_GetTypeNameStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr HierarchyContainer_HierarchyContainer (IntPtr context, IntPtr listView, IntPtr overlayContainer);

		[Preserve]
		public HierarchyContainer (Context context, ListView listView, UIElement overlayContainer) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(HierarchyContainer));
			handle = HierarchyContainer_HierarchyContainer ((object)context == null ? IntPtr.Zero : context.Handle, (object)listView == null ? IntPtr.Zero : listView.Handle, (object)overlayContainer == null ? IntPtr.Zero : overlayContainer.Handle);
			Runtime.RegisterObject (this);
			OnHierarchyContainerCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void HierarchyContainer_RegisterObject (IntPtr context);

		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(HierarchyContainer));
			HierarchyContainer_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void HierarchyContainer_InsertChild (IntPtr handle, uint index, IntPtr element);

		public override void InsertChild (uint index, UIElement element)
		{
			Runtime.ValidateRefCounted (this);
			HierarchyContainer_InsertChild (handle, index, (object)element == null ? IntPtr.Zero : element.Handle);
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
	}
}
