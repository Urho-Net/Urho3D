// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// FileWatcher.cs
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

namespace Urho.IO
{
	/// <summary>
	/// Watches a directory and its subdirectories for files being modified.
	/// </summary>
	public unsafe partial class FileWatcher : UrhoObject
	{
		unsafe partial void OnFileWatcherCreated ();

		[Preserve]
		public FileWatcher (IntPtr handle) : base (handle)
		{
			OnFileWatcherCreated ();
		}

		[Preserve]
		protected FileWatcher (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnFileWatcherCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int FileWatcher_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (FileWatcher_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr FileWatcher_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (FileWatcher_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int FileWatcher_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(FileWatcher));
			return new StringHash (FileWatcher_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr FileWatcher_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(FileWatcher));
			return Marshal.PtrToStringAnsi (FileWatcher_GetTypeNameStatic ());
		}

		[Preserve]
		public FileWatcher () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr FileWatcher_FileWatcher (IntPtr context);

		[Preserve]
		public FileWatcher (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(FileWatcher));
			handle = FileWatcher_FileWatcher ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnFileWatcherCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void FileWatcher_ThreadFunction (IntPtr handle);

		/// <summary>
		/// Directory watching loop.
		/// </summary>
		public void ThreadFunction ()
		{
			Runtime.ValidateRefCounted (this);
			FileWatcher_ThreadFunction (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool FileWatcher_StartWatching (IntPtr handle, string pathName, bool watchSubDirs);

		/// <summary>
		/// Start watching a directory. Return true if successful.
		/// </summary>
		public bool StartWatching (string pathName, bool watchSubDirs)
		{
			Runtime.ValidateRefCounted (this);
			return FileWatcher_StartWatching (handle, pathName, watchSubDirs);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void FileWatcher_StopWatching (IntPtr handle);

		/// <summary>
		/// Stop watching the directory.
		/// </summary>
		public void StopWatching ()
		{
			Runtime.ValidateRefCounted (this);
			FileWatcher_StopWatching (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void FileWatcher_SetDelay (IntPtr handle, float interval);

		/// <summary>
		/// Set the delay in seconds before file changes are notified. This (hopefully) avoids notifying when a file save is still in progress. Default 1 second.
		/// </summary>
		private void SetDelay (float interval)
		{
			Runtime.ValidateRefCounted (this);
			FileWatcher_SetDelay (handle, interval);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void FileWatcher_AddChange (IntPtr handle, string fileName);

		/// <summary>
		/// Add a file change into the changes queue.
		/// </summary>
		public void AddChange (string fileName)
		{
			Runtime.ValidateRefCounted (this);
			FileWatcher_AddChange (handle, fileName);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr FileWatcher_GetPath (IntPtr handle);

		/// <summary>
		/// Return the path being watched, or empty if not watching.
		/// </summary>
		private string GetPath ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (FileWatcher_GetPath (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float FileWatcher_GetDelay (IntPtr handle);

		/// <summary>
		/// Return the delay in seconds for notifying file changes.
		/// </summary>
		private float GetDelay ()
		{
			Runtime.ValidateRefCounted (this);
			return FileWatcher_GetDelay (handle);
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
		/// Return the delay in seconds for notifying file changes.
		/// Or
		/// Set the delay in seconds before file changes are notified. This (hopefully) avoids notifying when a file save is still in progress. Default 1 second.
		/// </summary>
		public float Delay {
			get {
				return GetDelay ();
			}
			set {
				SetDelay (value);
			}
		}

		/// <summary>
		/// Return the path being watched, or empty if not watching.
		/// </summary>
		public string Path {
			get {
				return GetPath ();
			}
		}
	}
}
