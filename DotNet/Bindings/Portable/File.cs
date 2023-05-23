using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Urho.IO
{
    partial class File
    {
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern uint File_GetSize(IntPtr handle);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern bool File_WriteLine(IntPtr handle, string line);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr File_ReadLine(IntPtr handle);

        public uint Size => File_GetSize(Handle);

		public File ( string fileName, FileMode mode = FileMode.Read): base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(File));
			handle = File_File0 ((object)Application.CurrentContext == null ? IntPtr.Zero : Application.CurrentContext.Handle, fileName, mode);
			Runtime.RegisterObject (this);
			OnFileCreated ();
		}

        public uint Read(byte[] buffer, uint size = 0)
        {
            unsafe
            {
                fixed (byte* b = buffer)
                {
                    if (size == 0 || size > buffer.Length)
                    {
                        size = (uint)buffer.Length;
                    }
                    return Read((IntPtr)b, size);
                }
            }
        }

        public uint Write(byte[] buffer, uint size = 0)
        {
            unsafe
            {
                fixed (byte* b = buffer)
                {
                    if (size == 0 || size > buffer.Length)
                    {
                        size = (uint)buffer.Length;
                    }
                    return Write((void*)b, (uint)size);
                }
            }
        }

        public bool WriteLine(string line)
        {
            return File_WriteLine(Handle, line);
        }
        public string ReadLine()
        {
            IntPtr nativeCString = File_ReadLine(Handle);
            string result = Marshal.PtrToStringAnsi(nativeCString);
            return result;
        }
    }
}
