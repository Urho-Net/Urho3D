// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Technique.cs
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
	/// %Material technique. Consists of several passes.
	/// </summary>
	public unsafe partial class Technique : Resource
	{
		unsafe partial void OnTechniqueCreated ();

		[Preserve]
		public Technique (IntPtr handle) : base (handle)
		{
			OnTechniqueCreated ();
		}

		[Preserve]
		protected Technique (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnTechniqueCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Technique_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Technique_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Technique_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Technique_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Technique));
			return new StringHash (Technique_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Technique));
			return Marshal.PtrToStringAnsi (Technique_GetTypeNameStatic ());
		}

		[Preserve]
		public Technique () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_Technique (IntPtr context);

		[Preserve]
		public Technique (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Technique));
			handle = Technique_Technique ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnTechniqueCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Technique_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Technique));
			Technique_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Technique_BeginLoad_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Technique_BeginLoad_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Technique_BeginLoad_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Technique_BeginLoad_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Technique_SetIsDesktop (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether requires desktop level hardware.
		/// 
		/// </summary>
		public void SetIsDesktop (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Technique_SetIsDesktop (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_CreatePass (IntPtr handle, string name);

		/// <summary>
		/// Create a new pass.
		/// </summary>
		public Pass CreatePass (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Pass> (Technique_CreatePass (handle, name));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Technique_RemovePass (IntPtr handle, string name);

		/// <summary>
		/// Remove a pass.
		/// </summary>
		public void RemovePass (string name)
		{
			Runtime.ValidateRefCounted (this);
			Technique_RemovePass (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Technique_ReleaseShaders (IntPtr handle);

		/// <summary>
		/// Reset shader pointers in all passes.
		/// </summary>
		public void ReleaseShaders ()
		{
			Runtime.ValidateRefCounted (this);
			Technique_ReleaseShaders (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_Clone (IntPtr handle, string cloneName);

		/// <summary>
		/// Clone the technique. Passes will be deep copied to allow independent modification.
		/// </summary>
		public Technique Clone (string cloneName = "")
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Technique> (Technique_Clone (handle, cloneName));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Technique_IsDesktop (IntPtr handle);

		/// <summary>
		/// Return whether requires desktop level hardware.
		/// 
		/// </summary>
		private bool IsDesktop ()
		{
			Runtime.ValidateRefCounted (this);
			return Technique_IsDesktop (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Technique_IsSupported (IntPtr handle);

		/// <summary>
		/// Return whether technique is supported by the current hardware.
		/// 
		/// </summary>
		private bool IsSupported ()
		{
			Runtime.ValidateRefCounted (this);
			return Technique_IsSupported (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Technique_HasPass (IntPtr handle, uint passIndex);

		/// <summary>
		/// Return whether has a pass.
		/// </summary>
		public bool HasPass (uint passIndex)
		{
			Runtime.ValidateRefCounted (this);
			return Technique_HasPass (handle, passIndex);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Technique_HasPass0 (IntPtr handle, string name);

		/// <summary>
		/// Return whether has a pass by name. This overload should not be called in time-critical rendering loops; use a pre-acquired pass index instead.
		/// </summary>
		public bool HasPass (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Technique_HasPass0 (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_GetPass (IntPtr handle, uint passIndex);

		/// <summary>
		/// Return a pass, or null if not found.
		/// </summary>
		public Pass GetPass (uint passIndex)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Pass> (Technique_GetPass (handle, passIndex));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_GetPass1 (IntPtr handle, string name);

		/// <summary>
		/// Return a pass by name, or null if not found. This overload should not be called in time-critical rendering loops; use a pre-acquired pass index instead.
		/// </summary>
		public Pass GetPass (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Pass> (Technique_GetPass1 (handle, name));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_GetSupportedPass (IntPtr handle, uint passIndex);

		/// <summary>
		/// Return a pass that is supported for rendering, or null if not found.
		/// </summary>
		public Pass GetSupportedPass (uint passIndex)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Pass> (Technique_GetSupportedPass (handle, passIndex));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_GetSupportedPass2 (IntPtr handle, string name);

		/// <summary>
		/// Return a supported pass by name. This overload should not be called in time-critical rendering loops; use a pre-acquired pass index instead.
		/// </summary>
		public Pass GetSupportedPass (string name)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Pass> (Technique_GetSupportedPass2 (handle, name));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Technique_GetNumPasses (IntPtr handle);

		/// <summary>
		/// Return number of passes.
		/// 
		/// </summary>
		private uint GetNumPasses ()
		{
			Runtime.ValidateRefCounted (this);
			return Technique_GetNumPasses (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Technique_CloneWithDefines (IntPtr handle, string vsDefines, string psDefines);

		/// <summary>
		/// Return a clone with added shader compilation defines. Called internally by Material.
		/// </summary>
		public Technique CloneWithDefines (string vsDefines, string psDefines)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Technique> (Technique_CloneWithDefines (handle, vsDefines, psDefines));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Technique_GetPassIndex (string passName);

		/// <summary>
		/// Return a pass type index by name. Allocate new if not used yet.
		/// </summary>
		public static uint GetPassIndex (string passName)
		{
			Runtime.Validate (typeof(Technique));
			return Technique_GetPassIndex (passName);
		}

		public override StringHash Type {
			get {
				return UrhoGetType ();
			}
		}

		public override string TypeName {
			get {
				return GetTypeName ();
			}
		}

		[Preserve]
		public new static StringHash TypeStatic {
			get {
				return GetTypeStatic ();
			}
		}

		public new static string TypeNameStatic {
			get {
				return GetTypeNameStatic ();
			}
		}

		/// <summary>
		/// Return whether requires desktop level hardware.
		/// 
		/// </summary>
		public bool Desktop {
			get {
				return IsDesktop ();
			}
		}

		/// <summary>
		/// Return whether technique is supported by the current hardware.
		/// 
		/// </summary>
		public bool Supported {
			get {
				return IsSupported ();
			}
		}

		/// <summary>
		/// Return number of passes.
		/// 
		/// </summary>
		public uint NumPasses {
			get {
				return GetNumPasses ();
			}
		}
	}
}
