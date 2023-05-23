using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho.Urho2D
{
	/// <summary>
	/// Static sprite component.
	/// </summary>
	public unsafe partial class StaticSprite2D : Drawable2D
	{
        public virtual void UpdateWorldBoundingBox(out BoundingBox result) { result = new  BoundingBox(float.MaxValue,float.MinValue); }

    }

}