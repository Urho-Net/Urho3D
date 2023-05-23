// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// VGTextRowBuffer.cs
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
	/// Destruct.
	/// </summary>
	public unsafe partial class VGTextRowBuffer : UrhoObject
	{
		unsafe partial void OnVGTextRowBufferCreated ();

		[Preserve]
		public VGTextRowBuffer (IntPtr handle) : base (handle)
		{
			OnVGTextRowBufferCreated ();
		}

		[Preserve]
		protected VGTextRowBuffer (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnVGTextRowBufferCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int VGTextRowBuffer_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (VGTextRowBuffer_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr VGTextRowBuffer_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (VGTextRowBuffer_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int VGTextRowBuffer_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(VGTextRowBuffer));
			return new StringHash (VGTextRowBuffer_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr VGTextRowBuffer_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(VGTextRowBuffer));
			return Marshal.PtrToStringAnsi (VGTextRowBuffer_GetTypeNameStatic ());
		}

		[Preserve]
		public VGTextRowBuffer () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr VGTextRowBuffer_VGTextRowBuffer (IntPtr context);

		[Preserve]
		public VGTextRowBuffer (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(VGTextRowBuffer));
			handle = VGTextRowBuffer_VGTextRowBuffer ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnVGTextRowBufferCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void VGTextRowBuffer_Clear (IntPtr handle);

		public void Clear ()
		{
			Runtime.ValidateRefCounted (this);
			VGTextRowBuffer_Clear (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void VGTextRowBuffer_AddRow (IntPtr handle, IntPtr row);

		public void AddRow (VGTextRow row)
		{
			Runtime.ValidateRefCounted (this);
			VGTextRowBuffer_AddRow (handle, (object)row == null ? IntPtr.Zero : row.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint VGTextRowBuffer_GetSize (IntPtr handle);

		private uint GetSize ()
		{
			Runtime.ValidateRefCounted (this);
			return VGTextRowBuffer_GetSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr VGTextRowBuffer_GetRowData (IntPtr handle, int index, float* data);

		public string GetRowData (int index, float* data)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (VGTextRowBuffer_GetRowData (handle, index, data));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr VGTextRowBuffer_GetRowText (IntPtr handle, int index);

		public string GetRowText (int index)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (VGTextRowBuffer_GetRowText (handle, index));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float VGTextRowBuffer_GetRowMin (IntPtr handle, int index);

		public float GetRowMin (int index)
		{
			Runtime.ValidateRefCounted (this);
			return VGTextRowBuffer_GetRowMin (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float VGTextRowBuffer_GetRowMax (IntPtr handle, int index);

		public float GetRowMax (int index)
		{
			Runtime.ValidateRefCounted (this);
			return VGTextRowBuffer_GetRowMax (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float VGTextRowBuffer_GetRowWidth (IntPtr handle, int index);

		public float GetRowWidth (int index)
		{
			Runtime.ValidateRefCounted (this);
			return VGTextRowBuffer_GetRowWidth (handle, index);
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

		public uint Size {
			get {
				return GetSize ();
			}
		}
	}
}
