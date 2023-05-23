using System;
using System.IO;
using System.Runtime.InteropServices;

namespace Urho
{
	public unsafe class MemoryBuffer : IDeserializer, ISerializer, IDisposable
	{
		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr MemoryBuffer_MemoryBuffer(byte* data, int size);

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr MemoryBuffer_GetData(IntPtr handle, out int data);

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		static extern uint MemoryBuffer_GetSize(IntPtr handle);

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr MemoryBuffer_Dispose(IntPtr handle);

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
 		static extern IntPtr MemoryBuffer_GetString(IntPtr handle);

		public MemoryBuffer(byte[] data)
		{
			fixed (byte* bptr = data)
			{
				Handle = MemoryBuffer_MemoryBuffer(bptr, data.Length);
			}
		}

		public MemoryBuffer(MemoryStream ms) : this(ms.ToArray()) { }

		public MemoryBuffer(IntPtr handle) { Handle = handle; }

		public IntPtr Handle { get; private set; }

		public uint Size => MemoryBuffer_GetSize(Handle);

		public byte[] GetData()
		{
			int size;
			var bytesPtr = MemoryBuffer_GetData(Handle, out size);
			if (bytesPtr == IntPtr.Zero)
				return new byte[0];
			byte[] result = new byte[size];
			Marshal.Copy(bytesPtr, result, 0, size);
			return result;
		}

		/// <summary>
		/// Return Read a null-terminated string..
		/// </summary>
		public string GetString ()
		{
			Runtime.ValidateObject (this);
			return Marshal.PtrToStringAnsi(MemoryBuffer_GetString(Handle));
		}

		public void Dispose()
		{
			MemoryBuffer_Dispose(Handle);
			GC.SuppressFinalize(this);
		}

		~MemoryBuffer()
		{
			Dispose();
		}
	}
}
