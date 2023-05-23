using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho.Gui
{
	/// <summary>
	/// %File selector dialog.
	/// </summary>
	public unsafe partial class FileSelector : UrhoObject
	{

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void FileSelector_SetFilters (IntPtr handle , IntPtr StringVectorHandle , uint  defaultIndex);

        public void SetFilters( StringVector filters, uint defaultIndex)
        {
            FileSelector_SetFilters (Handle , filters.Handle , defaultIndex);
        }
    }

}