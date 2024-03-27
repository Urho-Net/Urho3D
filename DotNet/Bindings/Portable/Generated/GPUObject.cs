// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// GPUObject.cs
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

namespace Urho
{
	/// <summary>
	/// Base class for GPU resources.
	/// </summary>
	public unsafe partial class GPUObject
	{
		unsafe partial void OnGPUObjectCreated ();

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr GPUObject_GPUObject (IntPtr graphics);

		[Preserve]
		public GPUObject (Graphics graphics)
		{
			Runtime.Validate (typeof(GPUObject));
			handle = GPUObject_GPUObject ((object)graphics == null ? IntPtr.Zero : graphics.Handle);
			OnGPUObjectCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void GPUObject_OnDeviceLost (IntPtr handle);

		/// <summary>
		/// Mark the GPU resource destroyed on graphics context destruction.
		/// </summary>
		public void OnDeviceLost ()
		{
			Runtime.ValidateObject (this);
			GPUObject_OnDeviceLost (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void GPUObject_OnDeviceReset (IntPtr handle);

		/// <summary>
		/// Recreate the GPU resource and restore data if applicable.
		/// </summary>
		public void OnDeviceReset ()
		{
			Runtime.ValidateObject (this);
			GPUObject_OnDeviceReset (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void GPUObject_Release (IntPtr handle);

		/// <summary>
		/// Unconditionally release the GPU resource.
		/// </summary>
		public void Release ()
		{
			Runtime.ValidateObject (this);
			GPUObject_Release (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void GPUObject_ClearDataLost (IntPtr handle);

		/// <summary>
		/// Clear the data lost flag.
		/// </summary>
		public void ClearDataLost ()
		{
			Runtime.ValidateObject (this);
			GPUObject_ClearDataLost (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr GPUObject_GetGraphics (IntPtr handle);

		/// <summary>
		/// Return the graphics subsystem associated with this GPU object.
		/// </summary>
		private Graphics GetGraphics ()
		{
			Runtime.ValidateObject (this);
			return Runtime.LookupObject<Graphics> (GPUObject_GetGraphics (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr GPUObject_GetGPUObject (IntPtr handle);

		/// <summary>
		/// Return the object pointer. Applicable only on Direct3D.
		/// </summary>
		public IntPtr GetGPUObject ()
		{
			Runtime.ValidateObject (this);
			return GPUObject_GetGPUObject (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint GPUObject_GetGPUObjectName (IntPtr handle);

		/// <summary>
		/// Return the object name. Applicable only on OpenGL.
		/// </summary>
		private uint GetGPUObjectName ()
		{
			Runtime.ValidateObject (this);
			return GPUObject_GetGPUObjectName (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool GPUObject_IsDataLost (IntPtr handle);

		/// <summary>
		/// Return whether data is lost due to context loss.
		/// 
		/// </summary>
		private bool IsDataLost ()
		{
			Runtime.ValidateObject (this);
			return GPUObject_IsDataLost (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool GPUObject_HasPendingData (IntPtr handle);

		/// <summary>
		/// Return whether has pending data assigned while graphics context was lost.
		/// </summary>
		public bool HasPendingData ()
		{
			Runtime.ValidateObject (this);
			return GPUObject_HasPendingData (handle);
		}

		/// <summary>
		/// Return the graphics subsystem associated with this GPU object.
		/// </summary>
		public Graphics Graphics {
			get {
				return GetGraphics ();
			}
		}

		/// <summary>
		/// Return the object name. Applicable only on OpenGL.
		/// </summary>
		public uint GPUObjectName {
			get {
				return GetGPUObjectName ();
			}
		}

		/// <summary>
		/// Return whether data is lost due to context loss.
		/// 
		/// </summary>
		public bool DataLost {
			get {
				return IsDataLost ();
			}
		}
	}
}
