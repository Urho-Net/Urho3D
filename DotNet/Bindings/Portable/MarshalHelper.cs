using System;
using System.Runtime.InteropServices;

namespace Urho
{
	public static class MarshalHelper
	{
		public static unsafe float ReadSingle(this IntPtr ptr, int offset = 0)
		{
			return *(float*)((byte*)ptr + offset);
		}

		public static unsafe void WriteSingle(this IntPtr ptr,float value, int offset = 0)
		{
			 *(float*)((byte*)ptr + offset) = value;
		}

		public static unsafe uint ReadUInt(this IntPtr ptr, int offset = 0)
		{
			return *(uint*)((byte*)ptr + offset);
		}

		public static unsafe void WriteUInt(this IntPtr ptr,uint value, int offset = 0)
		{
			 *(uint*)((byte*)ptr + offset) = value;
		}


		public static float[] ToFloatsArray(this IntPtr ptr, int size)
		{
			float[] result = new float[size];
			Marshal.Copy(ptr, result, 0, size);
			return result;
		}

		public static byte[] ToBytesArray(this IntPtr ptr, int size)
		{
			byte[] result = new byte[size];
			Marshal.Copy(ptr, result, 0, size);
			return result;
		}

		public static int[] ToIntsArray(this IntPtr ptr, int size)
		{
			int[] result = new int[size];
			Marshal.Copy(ptr, result, 0, size);
			return result;
		}

		public static T[] ToStructsArray<T>(this IntPtr ptr, int size) where T : struct
		{
			if (ptr == IntPtr.Zero || size < 1)
				return new T[0];

			T[] result = new T[size];
			var typeSize = Marshal.SizeOf(typeof(T));
			for (int i = 0; i < size; i++)
			{
				IntPtr data = new IntPtr(ptr.ToInt64() + typeSize * i);
				result[i] = (T)Marshal.PtrToStructure(data, typeof(T));
			}
			return result;
		}
	}
}
