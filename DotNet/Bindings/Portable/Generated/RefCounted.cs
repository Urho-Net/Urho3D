// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// RefCounted.cs
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

namespace Urho
{
	/// <summary>
	/// Base class for intrusively reference-counted objects. These are noncopyable and non-assignable.
	/// </summary>
	public unsafe partial class RefCounted
	{
		unsafe partial void OnRefCountedCreated ();

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RefCounted_RefCounted ();

		[Preserve]
		public RefCounted ()
		{
			handle = RefCounted_RefCounted ();
			OnRefCountedCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RefCounted_AddRef (IntPtr handle);

		/// <summary>
		/// Increment reference count. Can also be called outside of a SharedPtr for traditional reference counting.
		/// </summary>
		public void AddRef ()
		{
			RefCounted_AddRef (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RefCounted_ReleaseRef (IntPtr handle);

		/// <summary>
		/// Decrement reference count and delete self if no more references. Can also be called outside of a SharedPtr for traditional reference counting.
		/// </summary>
		public void ReleaseRef ()
		{
			RefCounted_ReleaseRef (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int RefCounted_Refs (IntPtr handle);

		/// <summary>
		/// Return reference count.
		/// 
		/// </summary>
		public int Refs ()
		{
			return RefCounted_Refs (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int RefCounted_WeakRefs (IntPtr handle);

		/// <summary>
		/// Return weak reference count.
		/// 
		/// </summary>
		public int WeakRefs ()
		{
			return RefCounted_WeakRefs (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern RefCount* RefCounted_RefCountPtr (IntPtr handle);

		/// <summary>
		/// Return pointer to the reference count structure.
		/// </summary>
		public RefCount* RefCountPtr ()
		{
			return RefCounted_RefCountPtr (handle);
		}
	}
}
