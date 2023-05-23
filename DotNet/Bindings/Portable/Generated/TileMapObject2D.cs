// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// TileMapObject2D.cs
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

namespace Urho.Urho2D
{
	/// <summary>
	/// Tile map object.
	/// </summary>
	public unsafe partial class TileMapObject2D : RefCounted
	{
		unsafe partial void OnTileMapObject2DCreated ();

		[Preserve]
		public TileMapObject2D (IntPtr handle) : base (handle)
		{
			OnTileMapObject2DCreated ();
		}

		[Preserve]
		protected TileMapObject2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnTileMapObject2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TileMapObject2D_TileMapObject2D ();

		[Preserve]
		public TileMapObject2D () : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(TileMapObject2D));
			handle = TileMapObject2D_TileMapObject2D ();
			Runtime.RegisterObject (this);
			OnTileMapObject2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern TileMapObjectType2D TileMapObject2D_GetObjectType (IntPtr handle);

		/// <summary>
		/// Return type.
		/// 
		/// </summary>
		private TileMapObjectType2D GetObjectType ()
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_GetObjectType (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TileMapObject2D_GetName (IntPtr handle);

		/// <summary>
		/// Return name.
		/// 
		/// </summary>
		private string GetName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (TileMapObject2D_GetName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TileMapObject2D_GetType (IntPtr handle);

		/// <summary>
		/// Return type.
		/// 
		/// </summary>
		private string UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (TileMapObject2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 TileMapObject2D_GetPosition (IntPtr handle);

		/// <summary>
		/// Return position.
		/// 
		/// </summary>
		private Urho.Vector2 GetPosition ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*TileMapObject2D_GetPosition
#else
TileMapObject2D_GetPosition
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 TileMapObject2D_GetSize (IntPtr handle);

		/// <summary>
		/// Return size (for rectangle and ellipse).
		/// 
		/// </summary>
		private Urho.Vector2 GetSize ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*TileMapObject2D_GetSize
#else
TileMapObject2D_GetSize
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint TileMapObject2D_GetNumPoints (IntPtr handle);

		/// <summary>
		/// Return number of points (use for script).
		/// 
		/// </summary>
		private uint GetNumPoints ()
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_GetNumPoints (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 TileMapObject2D_GetPoint (IntPtr handle, uint index);

		/// <summary>
		/// Return point at index (use for script).
		/// </summary>
		public Urho.Vector2 GetPoint (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*TileMapObject2D_GetPoint
#else
TileMapObject2D_GetPoint
#endif
 (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint TileMapObject2D_GetTileGid (IntPtr handle);

		/// <summary>
		/// Return tile Gid.
		/// 
		/// </summary>
		private uint GetTileGid ()
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_GetTileGid (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool TileMapObject2D_GetTileFlipX (IntPtr handle);

		/// <summary>
		/// Return tile flip X.
		/// 
		/// </summary>
		private bool GetTileFlipX ()
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_GetTileFlipX (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool TileMapObject2D_GetTileFlipY (IntPtr handle);

		/// <summary>
		/// Return tile flip Y.
		/// 
		/// </summary>
		private bool GetTileFlipY ()
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_GetTileFlipY (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool TileMapObject2D_GetTileSwapXY (IntPtr handle);

		/// <summary>
		/// Return tile swap X and Y.
		/// 
		/// </summary>
		private bool GetTileSwapXY ()
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_GetTileSwapXY (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TileMapObject2D_GetTileSprite (IntPtr handle);

		/// <summary>
		/// Return tile sprite.
		/// 
		/// </summary>
		private Sprite2D GetTileSprite ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Sprite2D> (TileMapObject2D_GetTileSprite (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool TileMapObject2D_HasProperty (IntPtr handle, string name);

		/// <summary>
		/// Return has property.
		/// </summary>
		public bool HasProperty (string name)
		{
			Runtime.ValidateRefCounted (this);
			return TileMapObject2D_HasProperty (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr TileMapObject2D_GetProperty (IntPtr handle, string name);

		/// <summary>
		/// Return property value.
		/// </summary>
		public string GetProperty (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (TileMapObject2D_GetProperty (handle, name));
		}

		/// <summary>
		/// Return type.
		/// 
		/// </summary>
		public TileMapObjectType2D ObjectType {
			get {
				return GetObjectType ();
			}
		}

		/// <summary>
		/// Return name.
		/// 
		/// </summary>
		public string Name {
			get {
				return GetName ();
			}
		}

		/// <summary>
		/// Return type.
		/// 
		/// </summary>
		public string Type {
			get {
				return UrhoGetType ();
			}
		}

		/// <summary>
		/// Return position.
		/// 
		/// </summary>
		public Urho.Vector2 Position {
			get {
				return GetPosition ();
			}
		}

		/// <summary>
		/// Return size (for rectangle and ellipse).
		/// 
		/// </summary>
		public Urho.Vector2 Size {
			get {
				return GetSize ();
			}
		}

		/// <summary>
		/// Return number of points (use for script).
		/// 
		/// </summary>
		public uint NumPoints {
			get {
				return GetNumPoints ();
			}
		}

		/// <summary>
		/// Return tile Gid.
		/// 
		/// </summary>
		public uint TileGid {
			get {
				return GetTileGid ();
			}
		}

		/// <summary>
		/// Return tile flip X.
		/// 
		/// </summary>
		public bool TileFlipX {
			get {
				return GetTileFlipX ();
			}
		}

		/// <summary>
		/// Return tile flip Y.
		/// 
		/// </summary>
		public bool TileFlipY {
			get {
				return GetTileFlipY ();
			}
		}

		/// <summary>
		/// Return tile swap X and Y.
		/// 
		/// </summary>
		public bool TileSwapXY {
			get {
				return GetTileSwapXY ();
			}
		}

		/// <summary>
		/// Return tile sprite.
		/// 
		/// </summary>
		public Sprite2D TileSprite {
			get {
				return GetTileSprite ();
			}
		}
	}
}
