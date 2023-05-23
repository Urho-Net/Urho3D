// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// DbConnection.cs
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
	/// %Database connection.
	/// </summary>
	public unsafe partial class DbConnection : UrhoObject
	{
		unsafe partial void OnDbConnectionCreated ();

		[Preserve]
		public DbConnection (IntPtr handle) : base (handle)
		{
			OnDbConnectionCreated ();
		}

		[Preserve]
		protected DbConnection (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnDbConnectionCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int DbConnection_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (DbConnection_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr DbConnection_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (DbConnection_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int DbConnection_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(DbConnection));
			return new StringHash (DbConnection_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr DbConnection_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(DbConnection));
			return Marshal.PtrToStringAnsi (DbConnection_GetTypeNameStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr DbConnection_DbConnection (IntPtr context, string connectionString);

		[Preserve]
		public DbConnection (Context context, string connectionString) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(DbConnection));
			handle = DbConnection_DbConnection ((object)context == null ? IntPtr.Zero : context.Handle, connectionString);
			Runtime.RegisterObject (this);
			OnDbConnectionCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void DbConnection_Finalize (IntPtr handle);

		/// <summary>
		/// Finalize all prepared statements, close all BLOB handles, and finish all sqlite3_backup objects.
		/// </summary>
		public void Finalize ()
		{
			Runtime.ValidateRefCounted (this);
			DbConnection_Finalize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr DbConnection_GetConnectionString (IntPtr handle);

		/// <summary>
		/// Return database connection string. The connection string for SQLite3 is using the URI format described in https://www.sqlite.org/uri.html, while the connection string for ODBC is using DSN format as per ODBC standard.
		/// </summary>
		private string GetConnectionString ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (DbConnection_GetConnectionString (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool DbConnection_IsConnected (IntPtr handle);

		/// <summary>
		/// Return true when the connection object is connected to the associated database.
		/// </summary>
		private bool IsConnected ()
		{
			Runtime.ValidateRefCounted (this);
			return DbConnection_IsConnected (handle);
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
		/// Return database connection string. The connection string for SQLite3 is using the URI format described in https://www.sqlite.org/uri.html, while the connection string for ODBC is using DSN format as per ODBC standard.
		/// </summary>
		public string ConnectionString {
			get {
				return GetConnectionString ();
			}
		}

		/// <summary>
		/// Return true when the connection object is connected to the associated database.
		/// </summary>
		public bool Connected {
			get {
				return IsConnected ();
			}
		}
	}
}
