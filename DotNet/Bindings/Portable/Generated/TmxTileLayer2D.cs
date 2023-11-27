// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// TmxTileLayer2D.cs
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

namespace Urho.Urho2D
{
	/// <summary>
	/// Tmx tile layer.
	/// </summary>
	public unsafe partial class TmxTileLayer2D : TmxLayer2D
	{
		unsafe partial void OnTmxTileLayer2DCreated ();

		[Preserve]
		public TmxTileLayer2D (IntPtr handle) : base (handle)
		{
			OnTmxTileLayer2DCreated ();
		}

		[Preserve]
		protected TmxTileLayer2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnTmxTileLayer2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TmxTileLayer2D_TmxTileLayer2D (IntPtr tmxFile);

		[Preserve]
		public TmxTileLayer2D (TmxFile2D tmxFile) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(TmxTileLayer2D));
			handle = TmxTileLayer2D_TmxTileLayer2D ((object)tmxFile == null ? IntPtr.Zero : tmxFile.Handle);
			Runtime.RegisterObject (this);
			OnTmxTileLayer2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool TmxTileLayer2D_Load (IntPtr handle, IntPtr element, ref Urho.Urho2D.TileMapInfo2D info);

		/// <summary>
		/// Load from XML element.
		/// </summary>
		public bool Load (XmlElement element, Urho.Urho2D.TileMapInfo2D info)
		{
			Runtime.ValidateRefCounted (this);
			return TmxTileLayer2D_Load (handle, (object)element == null ? IntPtr.Zero : element.Handle, ref info);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TmxTileLayer2D_GetTile (IntPtr handle, int x, int y);

		/// <summary>
		/// Return tile.
		/// </summary>
		public Tile2D GetTile (int x, int y)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Tile2D> (TmxTileLayer2D_GetTile (handle, x, y));
		}
	}
}
