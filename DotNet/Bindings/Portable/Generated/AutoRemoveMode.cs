// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// AutoRemoveMode.cs
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
using File = Urho.IO.File;
using ListView = Urho.Gui.ListView;
using Button = Urho.Gui.Button;

namespace Urho
{
	/// <summary>
	/// Autoremove is used by some components for automatic removal from the scene hierarchy upon completion of an action, for example sound or particle effect.
	/// </summary>
	public enum AutoRemoveMode
	{
		Disabled = 0,
		Component,
		Node
	}
}
