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

	public unsafe partial class VGComponent : Component
	{
		public void TextMetrics (out float ascender, out float descender, out float lineh)
		{
			Runtime.ValidateRefCounted (this);
			float t1,t2,t3;
			VGComponent_TextMetrics (handle, &t1, &t2, &t3);
			ascender = t1;
			descender = t2;
			lineh = t3;
		}

		public float TextBounds (float x, float y, string str, out Rect result)
		{
			Runtime.ValidateRefCounted (this);
			result = new Rect();
			IntPtr pnt = Marshal.AllocHGlobal(sizeof(float) * 4);
			float ret = VGComponent_TextBounds (handle, x, y, str, (float*)pnt);
			result.Min.X = ((float*)pnt)[0];
			result.Min.Y = ((float*)pnt)[1];
			result.Max.X = ((float*)pnt)[2];
			result.Max.Y = ((float*)pnt)[3];
			Marshal.FreeHGlobal(pnt);
			return ret;
		}

		public float TextBounds (float x, float y, string str, out float [] result)
		{
		
			IntPtr pnt = Marshal.AllocHGlobal(sizeof(float) * 4);
			float ret = VGComponent_TextBounds (handle, x, y, str, (float*)pnt);
			result =  MarshalHelper.ToFloatsArray(pnt, 4);
			Marshal.FreeHGlobal(pnt);
			return ret;
		}

		//public void TextBoxBounds (float x, float y, float breakRowWidth, string str, float* bounds)
		public void TextBoxBounds (float x, float y, float breakRowWidth, string str, out Rect result)
		{
			Runtime.ValidateRefCounted (this);
			result = new Rect();
			IntPtr pnt = Marshal.AllocHGlobal(sizeof(float) * 4);
			VGComponent_TextBoxBounds (handle, x, y,breakRowWidth, str, (float*)pnt);
			result.Min.X = ((float*)pnt)[0];
			result.Min.Y = ((float*)pnt)[1];
			result.Max.X = ((float*)pnt)[2];
			result.Max.Y = ((float*)pnt)[3];
			Marshal.FreeHGlobal(pnt);
	
		}

		public void TextBoxBounds (float x, float y, float breakRowWidth, string str, out float [] result)
		{
		
			IntPtr pnt = Marshal.AllocHGlobal(sizeof(float) * 4);
			VGComponent_TextBoxBounds (handle, x, y,breakRowWidth, str, (float*)pnt);
			result =  MarshalHelper.ToFloatsArray(pnt, 4);
			Marshal.FreeHGlobal(pnt);
		}

		public VGTextRowBuffer  TextBreakLines (string str, float breakRowWidth)
		{
			VGTextRowBuffer vgTextRowBuffer = new VGTextRowBuffer();
			 TextBreakLines ( str,  breakRowWidth,  vgTextRowBuffer);
			 return vgTextRowBuffer;
		}

		public void ImageSize (int image, out int width, out int height)
		{
			int w , h;
			ImageSize ( image, &w, &h);
			width = w;
			height = h;
		}

		public int TextGlyphPositions (float x, float y, string str, out NVGglyphPosition [] positions, int maxPositions)
		{
			IntPtr pnt = Marshal.AllocHGlobal(sizeof(float) * 4 * maxPositions);
			int ncount = TextGlyphPositions ( x,  y,  str, (float*)pnt,  maxPositions);
			positions = new NVGglyphPosition[ncount];
			for(int i = 0 ; i < ncount ; i++)
			{
				positions[i].StringPosition = (int)((float*)pnt)[i*4 + 0];
				positions[i].X = ((float*)pnt)[i*4 + 1];
				positions[i].MinX = ((float*)pnt)[i*4 + 2];
				positions[i].MaxX = ((float*)pnt)[i*4 + 3];
			}
			
			Marshal.FreeHGlobal(pnt);

			return ncount;
		}
	}
}