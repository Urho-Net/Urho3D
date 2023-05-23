using System;
using System.Runtime.InteropServices;
namespace Urho {
	/* TBD ELI
	[StructLayout(LayoutKind.Sequential)]
	public partial struct String {
		uint length;
		uint capacity;
		IntPtr buffer;
	}

	public partial struct StringPtr {
		public IntPtr ptr;

		public static implicit operator String (StringPtr stringPtr)
		{
			unsafe {
				return *((String *) (stringPtr.ptr));
			}
		}
	}
	*/

	static class NativeString
	{
		// free native char*
		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		static extern void  String_FreeNativeString(IntPtr str);

		public static void Free(IntPtr str)
		{
			String_FreeNativeString(str);
		}
	}
}
