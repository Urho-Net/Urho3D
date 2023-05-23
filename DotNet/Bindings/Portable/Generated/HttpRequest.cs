// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// HttpRequest.cs
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

namespace Urho.Network
{
	/// <summary>
	/// An HTTP connection with response data stream.
	/// </summary>
	public unsafe partial class HttpRequest : RefCounted, IDeserializer
	{
		unsafe partial void OnHttpRequestCreated ();

		[Preserve]
		public HttpRequest (IntPtr handle) : base (handle)
		{
			OnHttpRequestCreated ();
		}

		[Preserve]
		protected HttpRequest (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnHttpRequestCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void HttpRequest_ThreadFunction (IntPtr handle);

		/// <summary>
		/// Process the connection in the worker thread until closed.
		/// </summary>
		public void ThreadFunction ()
		{
			Runtime.ValidateRefCounted (this);
			HttpRequest_ThreadFunction (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint HttpRequest_Read (IntPtr handle, IntPtr dest, uint size);

		/// <summary>
		/// Read response data from the HTTP connection and return number of bytes actually read. While the connection is open, will block while trying to read the specified size. To avoid blocking, only read up to as many bytes as GetAvailableSize() returns.
		/// </summary>
		public uint Read (IntPtr dest, uint size)
		{
			Runtime.ValidateRefCounted (this);
			return HttpRequest_Read (handle, dest, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint HttpRequest_Seek (IntPtr handle, uint position);

		/// <summary>
		/// Set position from the beginning of the stream. Not supported.
		/// </summary>
		public uint Seek (uint position)
		{
			Runtime.ValidateRefCounted (this);
			return HttpRequest_Seek (handle, position);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool HttpRequest_IsEof (IntPtr handle);

		/// <summary>
		/// Return whether all response data has been read.
		/// </summary>
		private bool IsEof ()
		{
			Runtime.ValidateRefCounted (this);
			return HttpRequest_IsEof (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr HttpRequest_GetURL (IntPtr handle);

		/// <summary>
		/// Return URL used in the request.
		/// 
		/// </summary>
		private string GetURL ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (HttpRequest_GetURL (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr HttpRequest_GetVerb (IntPtr handle);

		/// <summary>
		/// Return verb used in the request. Default GET if empty verb specified on construction.
		/// 
		/// </summary>
		private string GetVerb ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (HttpRequest_GetVerb (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr HttpRequest_GetError (IntPtr handle);

		/// <summary>
		/// Return error. Only non-empty in the error state.
		/// 
		/// </summary>
		private string GetError ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (HttpRequest_GetError (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern HttpRequestState HttpRequest_GetState (IntPtr handle);

		/// <summary>
		/// Return connection state.
		/// 
		/// </summary>
		private HttpRequestState GetState ()
		{
			Runtime.ValidateRefCounted (this);
			return HttpRequest_GetState (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint HttpRequest_GetAvailableSize (IntPtr handle);

		/// <summary>
		/// Return amount of bytes in the read buffer.
		/// 
		/// </summary>
		private uint GetAvailableSize ()
		{
			Runtime.ValidateRefCounted (this);
			return HttpRequest_GetAvailableSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool HttpRequest_IsOpen (IntPtr handle);

		/// <summary>
		/// Return whether connection is in the open state.
		/// 
		/// </summary>
		public bool IsOpen ()
		{
			Runtime.ValidateRefCounted (this);
			return HttpRequest_IsOpen (handle);
		}

		/// <summary>
		/// Return whether all response data has been read.
		/// </summary>
		public bool Eof {
			get {
				return IsEof ();
			}
		}

		/// <summary>
		/// Return URL used in the request.
		/// 
		/// </summary>
		public string URL {
			get {
				return GetURL ();
			}
		}

		/// <summary>
		/// Return verb used in the request. Default GET if empty verb specified on construction.
		/// 
		/// </summary>
		public string Verb {
			get {
				return GetVerb ();
			}
		}

		/// <summary>
		/// Return error. Only non-empty in the error state.
		/// 
		/// </summary>
		public string Error {
			get {
				return GetError ();
			}
		}

		/// <summary>
		/// Return connection state.
		/// 
		/// </summary>
		public HttpRequestState State {
			get {
				return GetState ();
			}
		}

		/// <summary>
		/// Return amount of bytes in the read buffer.
		/// 
		/// </summary>
		public uint AvailableSize {
			get {
				return GetAvailableSize ();
			}
		}
	}
}
