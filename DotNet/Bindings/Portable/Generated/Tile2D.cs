// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Tile2D.cs
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
	/// Tile define.
	/// </summary>
	public unsafe partial class Tile2D : RefCounted
	{
		unsafe partial void OnTile2DCreated ();

		[Preserve]
		public Tile2D (IntPtr handle) : base (handle)
		{
			OnTile2DCreated ();
		}

		[Preserve]
		protected Tile2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnTile2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Tile2D_Tile2D ();

		[Preserve]
		public Tile2D () : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Tile2D));
			handle = Tile2D_Tile2D ();
			Runtime.RegisterObject (this);
			OnTile2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Tile2D_GetGid (IntPtr handle);

		/// <summary>
		/// Return gid.
		/// 
		/// </summary>
		private uint GetGid ()
		{
			Runtime.ValidateRefCounted (this);
			return Tile2D_GetGid (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Tile2D_GetFlipX (IntPtr handle);

		/// <summary>
		/// Return flip X.
		/// 
		/// </summary>
		private bool GetFlipX ()
		{
			Runtime.ValidateRefCounted (this);
			return Tile2D_GetFlipX (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Tile2D_GetFlipY (IntPtr handle);

		/// <summary>
		/// Return flip Y.
		/// 
		/// </summary>
		private bool GetFlipY ()
		{
			Runtime.ValidateRefCounted (this);
			return Tile2D_GetFlipY (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Tile2D_GetSwapXY (IntPtr handle);

		/// <summary>
		/// Return swap X and Y.
		/// 
		/// </summary>
		private bool GetSwapXY ()
		{
			Runtime.ValidateRefCounted (this);
			return Tile2D_GetSwapXY (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Tile2D_GetSprite (IntPtr handle);

		/// <summary>
		/// Return sprite.
		/// 
		/// </summary>
		private Sprite2D GetSprite ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Sprite2D> (Tile2D_GetSprite (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Tile2D_HasProperty (IntPtr handle, string name);

		/// <summary>
		/// Return has property.
		/// </summary>
		public bool HasProperty (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Tile2D_HasProperty (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Tile2D_GetProperty (IntPtr handle, string name);

		/// <summary>
		/// Return property.
		/// </summary>
		public string GetProperty (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Tile2D_GetProperty (handle, name));
		}

		/// <summary>
		/// Return gid.
		/// 
		/// </summary>
		public uint Gid {
			get {
				return GetGid ();
			}
		}

		/// <summary>
		/// Return flip X.
		/// 
		/// </summary>
		public bool FlipX {
			get {
				return GetFlipX ();
			}
		}

		/// <summary>
		/// Return flip Y.
		/// 
		/// </summary>
		public bool FlipY {
			get {
				return GetFlipY ();
			}
		}

		/// <summary>
		/// Return swap X and Y.
		/// 
		/// </summary>
		public bool SwapXY {
			get {
				return GetSwapXY ();
			}
		}

		/// <summary>
		/// Return sprite.
		/// 
		/// </summary>
		public Sprite2D Sprite {
			get {
				return GetSprite ();
			}
		}
	}
}
