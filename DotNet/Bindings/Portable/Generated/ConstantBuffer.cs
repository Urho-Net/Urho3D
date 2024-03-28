// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ConstantBuffer.cs
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
	/// Hardware constant buffer.
	/// </summary>
	public unsafe partial class ConstantBuffer : UrhoObject, IGPUObject
	{
		unsafe partial void OnConstantBufferCreated ();

		[Preserve]
		public ConstantBuffer (IntPtr handle) : base (handle)
		{
			OnConstantBufferCreated ();
		}

		[Preserve]
		protected ConstantBuffer (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnConstantBufferCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstantBuffer_CastToGPUObject (IntPtr handle);

		public GPUObject AsGPUObject ()
		{
			return new GPUObject (ConstantBuffer_CastToGPUObject (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstantBuffer_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ConstantBuffer_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstantBuffer_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ConstantBuffer_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ConstantBuffer_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ConstantBuffer));
			return new StringHash (ConstantBuffer_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstantBuffer_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ConstantBuffer));
			return Marshal.PtrToStringAnsi (ConstantBuffer_GetTypeNameStatic ());
		}

		[Preserve]
		public ConstantBuffer () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ConstantBuffer_ConstantBuffer (IntPtr context);

		[Preserve]
		public ConstantBuffer (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ConstantBuffer));
			handle = ConstantBuffer_ConstantBuffer ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnConstantBufferCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstantBuffer_Release (IntPtr handle);

		/// <summary>
		/// Release the buffer.
		/// </summary>
		public void Release ()
		{
			Runtime.ValidateRefCounted (this);
			ConstantBuffer_Release (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ConstantBuffer_SetSize (IntPtr handle, uint size);

		/// <summary>
		/// Set size and create GPU-side buffer. Return true on success.
		/// </summary>
		public bool SetSize (uint size)
		{
			Runtime.ValidateRefCounted (this);
			return ConstantBuffer_SetSize (handle, size);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstantBuffer_SetParameter (IntPtr handle, uint offset, uint size, void* data);

		/// <summary>
		/// Set a generic parameter and mark buffer dirty.
		/// </summary>
		public void SetParameter (uint offset, uint size, void* data)
		{
			Runtime.ValidateRefCounted (this);
			ConstantBuffer_SetParameter (handle, offset, size, data);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstantBuffer_SetVector3ArrayParameter (IntPtr handle, uint offset, uint rows, void* data);

		/// <summary>
		/// Set a Vector3 array parameter and mark buffer dirty.
		/// </summary>
		public void SetVector3ArrayParameter (uint offset, uint rows, void* data)
		{
			Runtime.ValidateRefCounted (this);
			ConstantBuffer_SetVector3ArrayParameter (handle, offset, rows, data);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ConstantBuffer_Apply (IntPtr handle);

		/// <summary>
		/// Apply to GPU.
		/// </summary>
		public void Apply ()
		{
			Runtime.ValidateRefCounted (this);
			ConstantBuffer_Apply (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint ConstantBuffer_GetSize (IntPtr handle);

		/// <summary>
		/// Return size.
		/// </summary>
		private uint GetSize ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstantBuffer_GetSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ConstantBuffer_IsDirty (IntPtr handle);

		/// <summary>
		/// Return whether has unapplied data.
		/// </summary>
		private bool IsDirty ()
		{
			Runtime.ValidateRefCounted (this);
			return ConstantBuffer_IsDirty (handle);
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
		/// Return size.
		/// Or
		/// Set size and create GPU-side buffer. Return true on success.
		/// </summary>
		public uint Size {
			get {
				return GetSize ();
			}
			set {
				SetSize (value);
			}
		}

		/// <summary>
		/// Return whether has unapplied data.
		/// </summary>
		public bool Dirty {
			get {
				return IsDirty ();
			}
		}
	}
}
