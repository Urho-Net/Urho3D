using System;
using System.Runtime.InteropServices;

namespace Urho
{
	public partial class Graphics
	{
		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr Graphics_GetSdlWindow(IntPtr graphics);

		/// <summary>
		/// Pointer to SDL window
		/// </summary>
		public IntPtr SdlWindow => Graphics_GetSdlWindow(Handle);

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal extern static IntPtr Graphics_GetMultiSampleLevels(IntPtr target, out int count);


		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal extern static void Graphics_BringWindowToFront(IntPtr target);
		
		public void BringWindowToFront()
		{
			Runtime.ValidateRefCounted(this);
			Graphics_BringWindowToFront(Handle);
		}

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal extern static void Graphics_SetWindowToPriority(IntPtr target, int level);
		
		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal extern static int Graphics_GetWindowPriority(IntPtr target);

		public void SetWindowToPriority(int level)
		{
			Runtime.ValidateRefCounted(this);
			Graphics_SetWindowToPriority(Handle, level);
		}
		public int GetWindowPriority()
		{
			Runtime.ValidateRefCounted(this);
			return Graphics_GetWindowPriority(Handle);
		}


		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal extern static int Graphics_IsWindowFocused(IntPtr target);

		public bool IsWindowFocused
		{
			get
			{
				Runtime.ValidateRefCounted(this);
				return Graphics_IsWindowFocused(Handle) != 0;
			}
		}

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal extern static ulong Graphics_GetGlobalWindowID(IntPtr target);

		public ulong GlobalWindowID
		{
			get
			{
				Runtime.ValidateRefCounted(this);
				return Graphics_GetGlobalWindowID(Handle);
			}
		}
		


		public int[] MultiSampleLevels
		{
			get
			{
				Runtime.ValidateRefCounted(this);
				int count;
				var ptr = Graphics_GetMultiSampleLevels(Handle, out count);
				if (ptr == IntPtr.Zero)
					return new int[0];

				var res = new int[count];
				Marshal.Copy(ptr, res, 0, count);
				return res;
			}
		}
	}
}
