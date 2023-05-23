using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;
using System.Runtime.InteropServices;
using Urho.Physics;
using Urho.Gui;
using Urho.Urho2D;
using Urho.Resources;
using Urho.IO;

namespace Urho
{
    public class StringVector : IDisposable
    {
        public IntPtr Handle { get; private set; } = IntPtr.Zero;

        private bool _disposedValue = false;

        public StringVector()
        {
            _disposedValue = false;
            Handle = StringVector_Create();
        }
        public StringVector(string[] stringArray)
        {
            Handle = StringVector_Create();
            if (Handle != IntPtr.Zero)
            {
                foreach (string str in stringArray)
                {
                    StringVector_AddString(Handle, str);
                }
            }

        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!_disposedValue)
            {
                if (disposing)
                {
                    // TODO: dispose managed state (managed objects)
                }

                if (Handle != IntPtr.Zero)
                {
                    StringVector_Delete(Handle);
                    Handle = IntPtr.Zero;
                }
                _disposedValue = true;
            }
        }

        public int Count
        {
            get
            {
                return StringVector_GetSize(Handle);
            }
        }
        public string this[int index]
        {
            get
            {
                if (index < Count)
                {
                    IntPtr nativeString = StringVector_GetString(Handle, index);
                    string result = Marshal.PtrToStringAnsi(nativeString);
                    return result;
                }
                else
                    return string.Empty;
            }

            set
            {
                if (index < Count)
                {
                    StringVector_SetString(Handle, index, value);
                }
            }
        }

        public void Add(string str)
        {
            StringVector_AddString(Handle, str);
        }

        public string[] ToArray()
        {
            int count = Count;
            if (count == 0)
            {
                return new string[1];
            }
            string[] array = new string[count];
            for (int i = 0; i < count; i++)
            {
                IntPtr nativeString = StringVector_GetString(Handle, i);
                array[i] = Marshal.PtrToStringAnsi(nativeString);
            }
            return array;
        }

        ~StringVector()
        {
            Dispose(false);
        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr StringVector_Create();

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern int StringVector_GetSize(IntPtr handle);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr StringVector_GetString(IntPtr handle, int index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void StringVector_AddString(IntPtr handle, string str);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern bool StringVector_SetString(IntPtr handle, int index, string str);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void StringVector_Empty(IntPtr handle);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void StringVector_Delete(IntPtr handle);
    }

}