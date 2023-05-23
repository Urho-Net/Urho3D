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

		public VGTextRow GetRow(int index)
		{
		    Runtime.ValidateRefCounted (this);
			IntPtr pnt = Marshal.AllocHGlobal(sizeof(float) * 3);
			String text = GetRowData (index, (float*) pnt);
			VGTextRow result = new VGTextRow();
			result.Text = text;
			result.Width = ((float*)pnt)[0];
			result.Min = ((float*)pnt)[1];
			result.Max = ((float*)pnt)[2];
			Marshal.FreeHGlobal(pnt);
			return result;
		}
	}


}