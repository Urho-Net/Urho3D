// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// WorkQueue.cs
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
	/// Work queue subsystem for multithreading.
	/// </summary>
	public unsafe partial class WorkQueue : UrhoObject
	{
		unsafe partial void OnWorkQueueCreated ();

		[Preserve]
		public WorkQueue (IntPtr handle) : base (handle)
		{
			OnWorkQueueCreated ();
		}

		[Preserve]
		protected WorkQueue (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnWorkQueueCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int WorkQueue_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (WorkQueue_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr WorkQueue_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (WorkQueue_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int WorkQueue_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(WorkQueue));
			return new StringHash (WorkQueue_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr WorkQueue_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(WorkQueue));
			return Marshal.PtrToStringAnsi (WorkQueue_GetTypeNameStatic ());
		}

		[Preserve]
		public WorkQueue () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr WorkQueue_WorkQueue (IntPtr context);

		[Preserve]
		public WorkQueue (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(WorkQueue));
			handle = WorkQueue_WorkQueue ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnWorkQueueCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void WorkQueue_CreateThreads (IntPtr handle, uint numThreads);

		/// <summary>
		/// Create worker threads. Can only be called once.
		/// </summary>
		public void CreateThreads (uint numThreads)
		{
			Runtime.ValidateRefCounted (this);
			WorkQueue_CreateThreads (handle, numThreads);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern WorkItem WorkQueue_GetFreeItem (IntPtr handle);

		/// <summary>
		/// Get pointer to an usable WorkItem from the item pool. Allocate one if no more free items.
		/// </summary>
		private WorkItem GetFreeItem ()
		{
			Runtime.ValidateRefCounted (this);
			return WorkQueue_GetFreeItem (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void WorkQueue_Pause (IntPtr handle);

		/// <summary>
		/// Pause worker threads.
		/// </summary>
		public void Pause ()
		{
			Runtime.ValidateRefCounted (this);
			WorkQueue_Pause (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void WorkQueue_Resume (IntPtr handle);

		/// <summary>
		/// Resume worker threads.
		/// </summary>
		public void Resume ()
		{
			Runtime.ValidateRefCounted (this);
			WorkQueue_Resume (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void WorkQueue_Complete (IntPtr handle, uint priority);

		/// <summary>
		/// Finish all queued work which has at least the specified priority. Main thread will also execute priority work. Pause worker threads if no more work remains.
		/// </summary>
		public void Complete (uint priority)
		{
			Runtime.ValidateRefCounted (this);
			WorkQueue_Complete (handle, priority);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void WorkQueue_SetTolerance (IntPtr handle, int tolerance);

		/// <summary>
		/// Set the pool telerance before it starts deleting pool items.
		/// </summary>
		private void SetTolerance (int tolerance)
		{
			Runtime.ValidateRefCounted (this);
			WorkQueue_SetTolerance (handle, tolerance);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void WorkQueue_SetNonThreadedWorkMs (IntPtr handle, int ms);

		/// <summary>
		/// Set how many milliseconds maximum per frame to spend on low-priority work, when there are no worker threads.
		/// </summary>
		private void SetNonThreadedWorkMs (int ms)
		{
			Runtime.ValidateRefCounted (this);
			WorkQueue_SetNonThreadedWorkMs (handle, ms);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint WorkQueue_GetNumThreads (IntPtr handle);

		/// <summary>
		/// Return number of worker threads.
		/// </summary>
		private uint GetNumThreads ()
		{
			Runtime.ValidateRefCounted (this);
			return WorkQueue_GetNumThreads (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool WorkQueue_IsCompleted (IntPtr handle, uint priority);

		/// <summary>
		/// Return whether all work with at least the specified priority is finished.
		/// </summary>
		public bool IsCompleted (uint priority)
		{
			Runtime.ValidateRefCounted (this);
			return WorkQueue_IsCompleted (handle, priority);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool WorkQueue_IsCompleting (IntPtr handle);

		/// <summary>
		/// Return whether the queue is currently completing work in the main thread.
		/// </summary>
		private bool IsCompleting ()
		{
			Runtime.ValidateRefCounted (this);
			return WorkQueue_IsCompleting (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int WorkQueue_GetTolerance (IntPtr handle);

		/// <summary>
		/// Return the pool tolerance.
		/// </summary>
		private int GetTolerance ()
		{
			Runtime.ValidateRefCounted (this);
			return WorkQueue_GetTolerance (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int WorkQueue_GetNonThreadedWorkMs (IntPtr handle);

		/// <summary>
		/// Return how many milliseconds maximum to spend on non-threaded low-priority work.
		/// </summary>
		private int GetNonThreadedWorkMs ()
		{
			Runtime.ValidateRefCounted (this);
			return WorkQueue_GetNonThreadedWorkMs (handle);
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
		public static StringHash TypeStatic {
			get {
				return GetTypeStatic ();
			}
		}

		public static string TypeNameStatic {
			get {
				return GetTypeNameStatic ();
			}
		}

		/// <summary>
		/// Get pointer to an usable WorkItem from the item pool. Allocate one if no more free items.
		/// </summary>
		public WorkItem FreeItem {
			get {
				return GetFreeItem ();
			}
		}

		/// <summary>
		/// Return the pool tolerance.
		/// Or
		/// Set the pool telerance before it starts deleting pool items.
		/// </summary>
		public int Tolerance {
			get {
				return GetTolerance ();
			}
			set {
				SetTolerance (value);
			}
		}

		/// <summary>
		/// Return how many milliseconds maximum to spend on non-threaded low-priority work.
		/// Or
		/// Set how many milliseconds maximum per frame to spend on low-priority work, when there are no worker threads.
		/// </summary>
		public int NonThreadedWorkMs {
			get {
				return GetNonThreadedWorkMs ();
			}
			set {
				SetNonThreadedWorkMs (value);
			}
		}

		/// <summary>
		/// Return number of worker threads.
		/// </summary>
		public uint NumThreads {
			get {
				return GetNumThreads ();
			}
		}

		/// <summary>
		/// Return whether the queue is currently completing work in the main thread.
		/// </summary>
		public bool Completing {
			get {
				return IsCompleting ();
			}
		}
	}
}
