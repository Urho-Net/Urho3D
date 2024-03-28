// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// PacketType.cs
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
	/// Packet types for outgoing buffers. Outgoing messages are grouped by their type
	/// </summary>
	public enum PacketType
	{
		UnreliableUnordered,
		UnreliableOrdered,
		ReliableUnordered,
		ReliableOrdered
	}
}
