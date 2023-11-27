// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// RenderPath.cs
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

namespace Urho
{
	/// <summary>
	/// Rendering path definition. A sequence of commands (e.g. clear screen, draw objects with specific pass) that yields the scene rendering result.
	/// </summary>
	public unsafe partial class RenderPath : RefCounted
	{
		unsafe partial void OnRenderPathCreated ();

		[Preserve]
		public RenderPath (IntPtr handle) : base (handle)
		{
			OnRenderPathCreated ();
		}

		[Preserve]
		protected RenderPath (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnRenderPathCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderPath_RenderPath ();

		[Preserve]
		public RenderPath () : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(RenderPath));
			handle = RenderPath_RenderPath ();
			Runtime.RegisterObject (this);
			OnRenderPathCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderPath_Clone (IntPtr handle);

		/// <summary>
		/// Clone the rendering path.
		/// </summary>
		public RenderPath Clone ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<RenderPath> (RenderPath_Clone (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderPath_Load (IntPtr handle, IntPtr file);

		/// <summary>
		/// Clear existing data and load from an XML file. Return true if successful.
		/// </summary>
		public bool Load (Urho.Resources.XmlFile file)
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_Load (handle, (object)file == null ? IntPtr.Zero : file.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderPath_Append (IntPtr handle, IntPtr file);

		/// <summary>
		/// Append data from an XML file. Return true if successful.
		/// </summary>
		public bool Append (Urho.Resources.XmlFile file)
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_Append (handle, (object)file == null ? IntPtr.Zero : file.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetEnabled (IntPtr handle, string tag, bool active);

		/// <summary>
		/// Enable/disable commands and rendertargets by tag.
		/// </summary>
		public void SetEnabled (string tag, bool active)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetEnabled (handle, tag, active);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderPath_IsEnabled (IntPtr handle, string tag);

		/// <summary>
		/// Return true of any of render targets or commands with specified tag are enabled.
		/// 
		/// </summary>
		public bool IsEnabled (string tag)
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_IsEnabled (handle, tag);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderPath_IsAdded (IntPtr handle, string tag);

		/// <summary>
		/// Return true if renderpath or command with given tag exists.
		/// 
		/// </summary>
		public bool IsAdded (string tag)
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_IsAdded (handle, tag);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_ToggleEnabled (IntPtr handle, string tag);

		/// <summary>
		/// Toggle enabled state of commands and rendertargets by tag.
		/// </summary>
		public void ToggleEnabled (string tag)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_ToggleEnabled (handle, tag);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_RemoveRenderTarget (IntPtr handle, uint index);

		/// <summary>
		/// Remove a rendertarget by index.
		/// </summary>
		public void RemoveRenderTarget (uint index)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_RemoveRenderTarget (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_RemoveRenderTarget0 (IntPtr handle, string name);

		/// <summary>
		/// Remove a rendertarget by name.
		/// </summary>
		public void RemoveRenderTarget (string name)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_RemoveRenderTarget0 (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_RemoveRenderTargets (IntPtr handle, string tag);

		/// <summary>
		/// Remove rendertargets by tag name.
		/// </summary>
		public void RemoveRenderTargets (string tag)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_RemoveRenderTargets (handle, tag);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetCommand (IntPtr handle, uint index, ref Urho.RenderPathCommand command);

		/// <summary>
		/// Assign command at index.
		/// 
		/// </summary>
		public void SetCommand (uint index, Urho.RenderPathCommand command)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetCommand (handle, index, ref command);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_AddCommand (IntPtr handle, ref Urho.RenderPathCommand command);

		/// <summary>
		/// Add a command to the end of the list.
		/// </summary>
		public void AddCommand (Urho.RenderPathCommand command)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_AddCommand (handle, ref command);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_InsertCommand (IntPtr handle, uint index, ref Urho.RenderPathCommand command);

		/// <summary>
		/// Insert a command at a position.
		/// </summary>
		public void InsertCommand (uint index, Urho.RenderPathCommand command)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_InsertCommand (handle, index, ref command);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_RemoveCommand (IntPtr handle, uint index);

		/// <summary>
		/// Remove a command by index.
		/// </summary>
		public void RemoveCommand (uint index)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_RemoveCommand (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_RemoveCommands (IntPtr handle, string tag);

		/// <summary>
		/// Remove commands by tag name.
		/// </summary>
		public void RemoveCommands (string tag)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_RemoveCommands (handle, tag);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_0 (IntPtr handle, string name, ref Vector3 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Vector3 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_0 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_1 (IntPtr handle, string name, ref IntRect value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, IntRect value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_1 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_2 (IntPtr handle, string name, ref Color value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Color value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_2 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_3 (IntPtr handle, string name, ref Vector2 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Vector2 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_3 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_4 (IntPtr handle, string name, ref Vector4 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Vector4 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_4 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_5 (IntPtr handle, string name, ref IntVector2 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, IntVector2 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_5 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_6 (IntPtr handle, string name, ref Quaternion value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Quaternion value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_6 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_7 (IntPtr handle, string name, ref Matrix4 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Matrix4 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_7 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_8 (IntPtr handle, string name, ref Matrix3 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Matrix3 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_8 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_9 (IntPtr handle, string name, ref Matrix3x4 value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, Matrix3x4 value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_9 (handle, name, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_10 (IntPtr handle, string name, int value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, int value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_10 (handle, name, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_11 (IntPtr handle, string name, uint value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, uint value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_11 (handle, name, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_12 (IntPtr handle, string name, float value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, float value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_12 (handle, name, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_13 (IntPtr handle, string name, string value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, string value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_13 (handle, name, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderPath_SetShaderParameter_14 (IntPtr handle, string name, bool value);

		/// <summary>
		/// Set a shader parameter in all commands that define it.
		/// 
		/// </summary>
		public void SetShaderParameter (string name, bool value)
		{
			Runtime.ValidateRefCounted (this);
			RenderPath_SetShaderParameter_14 (handle, name, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint RenderPath_GetNumRenderTargets (IntPtr handle);

		/// <summary>
		/// Return number of rendertargets.
		/// 
		/// </summary>
		private uint GetNumRenderTargets ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_GetNumRenderTargets (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint RenderPath_GetNumCommands (IntPtr handle);

		/// <summary>
		/// Return number of commands.
		/// 
		/// </summary>
		private uint GetNumCommands ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_GetNumCommands (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern RenderPathCommand* RenderPath_GetCommand (IntPtr handle, uint index);

		/// <summary>
		/// Return command at index, or null if does not exist.
		/// </summary>
		public RenderPathCommand* GetCommand (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return RenderPath_GetCommand (handle, index);
		}

		/// <summary>
		/// Return number of rendertargets.
		/// 
		/// </summary>
		public uint NumRenderTargets {
			get {
				return GetNumRenderTargets ();
			}
		}

		/// <summary>
		/// Return number of commands.
		/// 
		/// </summary>
		public uint NumCommands {
			get {
				return GetNumCommands ();
			}
		}
	}
}
