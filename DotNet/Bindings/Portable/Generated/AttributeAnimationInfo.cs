// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// AttributeAnimationInfo.cs
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
	/// Attribute animation instance.
	/// </summary>
	public unsafe partial class AttributeAnimationInfo : ValueAnimationInfo
	{
		unsafe partial void OnAttributeAnimationInfoCreated ();

		[Preserve]
		public AttributeAnimationInfo (IntPtr handle) : base (handle)
		{
			OnAttributeAnimationInfoCreated ();
		}

		[Preserve]
		protected AttributeAnimationInfo (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnAttributeAnimationInfoCreated ();
		}
	}
}
