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

    public enum SQLType : int
    {
        Integer=1,
        Double   = 2,
        Text = 3,
        Blob  =     4,
        Null  =   5
    }

    public enum SQLResult : int
    {
        OK     =      0,   /* Successful result */
        /* beginning-of-error-codes */
        Error    =    1,   /* Generic error */
        Internal  =   2,   /* Internal logic error in SQLite */
        Permission      =   3,   /* Access permission denied */
        Abort     =   4,   /* Callback routine requested an abort */
        Busy     =    5,   /* The database file is locked */
        Locked   =    6,   /* A table in the database is locked */
        NoMem    =    7,   /* A malloc() failed */
        Readonly  =   8,   /* Attempt to write a readonly database */
        Interrupt =   9,   /* Operation terminated by sqlite3_interrupt()*/
        IOError    =   10,   /* Some kind of disk I/O error occurred */
        Corrupt  =   11,   /* The database disk image is malformed */
        NotFound =   12,   /* Unknown opcode in sqlite3_file_control() */
        Full    =    13,   /* Insertion failed because database is full */
        CantOpen  =  14,   /* Unable to open the database file */
        Protocol =   15,   /* Database lock protocol error */
        Empty    =   16,   /* Not used */
        Schema   =   17,   /* The database schema changed */
        TooBig   =   18,   /* String or BLOB exceeds size limit */
        Cinstraint   = 19,   /* Abort due to constraint violation */
        Mismatch  =  20,   /* Data type mismatch */
        Misuse   =   21,   /* Library used incorrectly */
        NoLFS   =    22,   /* Uses OS features not supported on host */
        Authorization   =     23,   /* Authorization denied */
        Format   =   24,   /* Not used */
        Range   =    25,   /* 2nd parameter to sqlite3_bind out of range */
        NotDatabase   =   26,   /* File opened that is not a database file */
        Notice  =    27,   /* Notifications from sqlite3_log() */
        Warning  =   28,   /* Warnings from sqlite3_log() */
        Row     =    100,  /* sqlite3_step() has another row ready */
        Done   =     101,  /* sqlite3_step() has finished executing */     
    }

    public class SQLStatement
    {
        private IntPtr _handle;

        public IntPtr Handle{
            get
            {
                return _handle;
            }
        }

        public SQLStatement(IntPtr handle)
        {
            _handle = handle;
        }

        public bool IsValid()
        {
            return _handle != null;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern  int sqlite3_connection_finalize(IntPtr handle);

        public int Finalize()
        {
            int res =  sqlite3_connection_finalize(_handle);
            _handle = IntPtr.Zero;
            return res;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern  int sqlite3_connection_column_count(IntPtr handle);

        public int ColumnCount
        {
            get{
                if(_handle != null)
                    return sqlite3_connection_column_count(_handle);
                else
                    return 0;
            }
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr sqlite3_connection_column_name (IntPtr handle , int index);

        
        public string ColumnName(int columnIndex)
        {
            if(_handle != null)
                return  Marshal.PtrToStringAnsi(sqlite3_connection_column_name (_handle , columnIndex));
            else 
                return "";
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int sqlite3_connection_column_step (IntPtr handle);

        public SQLResult Step()
        {
            if(_handle != null)
                return (SQLResult)sqlite3_connection_column_step(_handle);
            else return SQLResult.Error;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern  int sqlite3_connection_column_type(IntPtr handle, int index);

        public SQLType ColumnType(int index)
        {
            if(_handle != null)
                return (SQLType)(sqlite3_connection_column_type(_handle,index));
            else 
                return SQLType.Null;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern  int sqlite3_connection_column_int(IntPtr handle, int index);

        public int ColumnInt(int index)
        {
            if(_handle != null)
                return  sqlite3_connection_column_int(_handle,index);
            else
                return 0;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern  double sqlite3_connection_column_double(IntPtr handle, int index);

        public double ColumnDouble(int index)
        {
            if(_handle != null)
                return  sqlite3_connection_column_double(_handle,index);
            else
                return 0.0;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr sqlite3_connection_column_decltype (IntPtr handle , int index);

        public string ColumnDeclType(int columnIndex)
        {
            return  Marshal.PtrToStringAnsi(sqlite3_connection_column_decltype (_handle , columnIndex));
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr sqlite3_connection_column_text (IntPtr handle , int index);

        public string ColumnText(int columnIndex)
        {
            if(_handle != null)
                return  Marshal.PtrToStringAnsi(sqlite3_connection_column_text (_handle , columnIndex));
            else
                return "";
        }

    }
	/// <summary>
	/// % SQlite Database connection.
	/// </summary>
	public partial class SQLite 
	{

		private IntPtr _handle;
        private DbConnection _db;

		public SQLite(IntPtr handle , DbConnection db)
        {
            _handle = handle;
            _db = db;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr sqlite3_connection_prepare (IntPtr handle , string sqlQuery);

        public SQLStatement Prepare(string sqlQuery)
        {
            IntPtr ptr = sqlite3_connection_prepare(_handle,sqlQuery);
            if(ptr != IntPtr.Zero)
                return new SQLStatement(ptr);
            else
                return null;
        }

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern  int sqlite3_connection_changes(IntPtr handle);

        public int Changes()
        {
            return sqlite3_connection_changes(_db.SQLiteImplPtr());
        }

	}
}
