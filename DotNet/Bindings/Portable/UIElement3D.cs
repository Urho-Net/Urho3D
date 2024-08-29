using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Reflection;

namespace Urho.Gui
{
    public partial class UIElement3D:UIElement 
    {
	    [Preserve]
		public UIElement3D (IntPtr handle) : base (handle)
		{
			
		}
    }

}