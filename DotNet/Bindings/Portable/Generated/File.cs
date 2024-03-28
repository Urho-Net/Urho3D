// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// File.cs
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
	/// %File opened either through the filesystem or from within a package file.
	/// </summary>
	public unsafe partial class File : UrhoObject, IAbstractFile
	{
		unsafe partial void OnFileCreated ();

		[Preserve]
		public File (IntPtr handle) : base (handle)
		{
			OnFileCreated ();
		}

		[Preserve]
		protected File (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnFileCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int File_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (File_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (File_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int File_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(File));
			return new StringHash (File_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(File));
			return Marshal.PtrToStringAnsi (File_GetTypeNameStatic ());
		}

		[Preserve]
		public File () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_File (IntPtr context);

		[Preserve]
		public File (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(File));
			handle = File_File ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnFileCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_File0 (IntPtr context, string fileName, FileMode mode);

		[Preserve]
		public File (Context context, string fileName, FileMode mode = FileMode.Read) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(File));
			handle = File_File0 ((object)context == null ? IntPtr.Zero : context.Handle, fileName, mode);
			Runtime.RegisterObject (this);
			OnFileCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_File1 (IntPtr context, IntPtr package, string fileName);

		[Preserve]
		public File (Context context, PackageFile package, string fileName) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(File));
			handle = File_File1 ((object)context == null ? IntPtr.Zero : context.Handle, (object)package == null ? IntPtr.Zero : package.Handle, fileName);
			Runtime.RegisterObject (this);
			OnFileCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint File_Read (IntPtr handle, IntPtr dest, uint size);

		/// <summary>
		/// Read bytes from the file. Return number of bytes actually read.
		/// </summary>
		public uint Read (IntPtr dest, uint size)
		{
			Runtime.ValidateRefCounted (this);
			return File_Read (handle, dest, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint File_Seek (IntPtr handle, uint position);

		/// <summary>
		/// Set position from the beginning of the file.
		/// </summary>
		public uint Seek (uint position)
		{
			Runtime.ValidateRefCounted (this);
			return File_Seek (handle, position);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint File_Write (IntPtr handle, void* data, uint size);

		/// <summary>
		/// Write bytes to the file. Return number of bytes actually written.
		/// </summary>
		public uint Write (void* data, uint size)
		{
			Runtime.ValidateRefCounted (this);
			return File_Write (handle, data, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint File_GetChecksum (IntPtr handle);

		/// <summary>
		/// Return a checksum of the file contents using the SDBM hash algorithm.
		/// </summary>
		private uint GetChecksum ()
		{
			Runtime.ValidateRefCounted (this);
			return File_GetChecksum (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool File_Open (IntPtr handle, string fileName, FileMode mode);

		/// <summary>
		/// Open a filesystem file. Return true if successful.
		/// </summary>
		public bool Open (string fileName, FileMode mode = FileMode.Read)
		{
			Runtime.ValidateRefCounted (this);
			return File_Open (handle, fileName, mode);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool File_Open2 (IntPtr handle, IntPtr package, string fileName);

		/// <summary>
		/// Open from within a package file. Return true if successful.
		/// </summary>
		public bool Open (PackageFile package, string fileName)
		{
			Runtime.ValidateRefCounted (this);
			return File_Open2 (handle, (object)package == null ? IntPtr.Zero : package.Handle, fileName);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void File_Close (IntPtr handle);

		/// <summary>
		/// Close the file.
		/// </summary>
		public void Close ()
		{
			Runtime.ValidateRefCounted (this);
			File_Close (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void File_Flush (IntPtr handle);

		/// <summary>
		/// Flush any buffered output to the file.
		/// </summary>
		public void Flush ()
		{
			Runtime.ValidateRefCounted (this);
			File_Flush (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern FileMode File_GetMode (IntPtr handle);

		/// <summary>
		/// Return the open mode.
		/// 
		/// </summary>
		private FileMode GetMode ()
		{
			Runtime.ValidateRefCounted (this);
			return File_GetMode (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool File_IsOpen (IntPtr handle);

		/// <summary>
		/// Return whether is open.
		/// 
		/// </summary>
		public bool IsOpen ()
		{
			Runtime.ValidateRefCounted (this);
			return File_IsOpen (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_GetHandle (IntPtr handle);

		/// <summary>
		/// Return the file handle.
		/// </summary>
		private IntPtr GetHandle ()
		{
			Runtime.ValidateRefCounted (this);
			return File_GetHandle (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool File_IsPackaged (IntPtr handle);

		/// <summary>
		/// Return whether the file originates from a package.
		/// 
		/// </summary>
		private bool IsPackaged ()
		{
			Runtime.ValidateRefCounted (this);
			return File_IsPackaged (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr File_GetName (IntPtr handle);

		/// <summary>
		/// Return the file name.
		/// </summary>
		private string GetName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (File_GetName (handle));
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
		/// Return a checksum of the file contents using the SDBM hash algorithm.
		/// </summary>
		public uint Checksum {
			get {
				return GetChecksum ();
			}
		}

		/// <summary>
		/// Return the open mode.
		/// 
		/// </summary>
		public FileMode Mode {
			get {
				return GetMode ();
			}
		}

		/// <summary>
		/// Return the file handle.
		/// </summary>
		public IntPtr FileHandle {
			get {
				return GetHandle ();
			}
		}

		/// <summary>
		/// Return whether the file originates from a package.
		/// 
		/// </summary>
		public bool Packaged {
			get {
				return IsPackaged ();
			}
		}

		/// <summary>
		/// Return the file name.
		/// </summary>
		public string Name {
			get {
				return GetName ();
			}
		}
	}
}
