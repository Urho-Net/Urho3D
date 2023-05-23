// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Context.cs
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
	/// Urho3D execution context. Provides access to subsystems, object factories and attributes, and event receivers.
	/// </summary>
	public unsafe partial class Context : RefCounted
	{
		unsafe partial void OnContextCreated ();

		[Preserve]
		public Context (IntPtr handle) : base (handle)
		{
			OnContextCreated ();
		}

		[Preserve]
		protected Context (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnContextCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_Context ();

		[Preserve]
		public Context () : base (UrhoObjectFlag.Empty)
		{
			CheckEngine ();
			handle = Context_Context ();
			Runtime.RegisterObject (this);
			OnContextCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_CreateObject (IntPtr handle, int objectType);

		/// <summary>
		/// Create an object by type hash. Return pointer to it or null if no factory found.
		/// </summary>
		public UrhoObject CreateObject (StringHash objectType)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<UrhoObject> (Context_CreateObject (handle, objectType.Code));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_RegisterFactory (IntPtr handle, IntPtr factory);

		/// <summary>
		/// Register a factory for an object type.
		/// </summary>
		public void RegisterFactory (ObjectFactory factory)
		{
			Runtime.ValidateRefCounted (this);
			Context_RegisterFactory (handle, (object)factory == null ? IntPtr.Zero : factory.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_RegisterSubsystem (IntPtr handle, IntPtr @object);

		/// <summary>
		/// Register a subsystem.
		/// </summary>
		public void RegisterSubsystem (Urho.UrhoObject @object)
		{
			Runtime.ValidateRefCounted (this);
			Context_RegisterSubsystem (handle, (object)@object == null ? IntPtr.Zero : @object.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_RemoveSubsystem (IntPtr handle, int objectType);

		/// <summary>
		/// Remove a subsystem.
		/// </summary>
		public void RemoveSubsystem (StringHash objectType)
		{
			Runtime.ValidateRefCounted (this);
			Context_RemoveSubsystem (handle, objectType.Code);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_RemoveAllAttributes (IntPtr handle, int objectType);

		/// <summary>
		/// Remove all object attributes.
		/// </summary>
		public void RemoveAllAttributes (StringHash objectType)
		{
			Runtime.ValidateRefCounted (this);
			Context_RemoveAllAttributes (handle, objectType.Code);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Context_RequireSDL (IntPtr handle, uint sdlFlags);

		/// <summary>
		/// Initialises the specified SDL systems, if not already. Returns true if successful. This call must be matched with ReleaseSDL() when SDL functions are no longer required, even if this call fails.
		/// </summary>
		public bool RequireSDL (uint sdlFlags)
		{
			Runtime.ValidateRefCounted (this);
			return Context_RequireSDL (handle, sdlFlags);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_ReleaseSDL (IntPtr handle);

		/// <summary>
		/// Indicate that you are done with using SDL. Must be called after using RequireSDL().
		/// </summary>
		public void ReleaseSDL ()
		{
			Runtime.ValidateRefCounted (this);
			Context_ReleaseSDL (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_CopyBaseAttributes (IntPtr handle, int baseType, int derivedType);

		/// <summary>
		/// Copy base class attributes to derived class.
		/// </summary>
		public void CopyBaseAttributes (StringHash baseType, StringHash derivedType)
		{
			Runtime.ValidateRefCounted (this);
			Context_CopyBaseAttributes (handle, baseType.Code, derivedType.Code);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetSubsystem (IntPtr handle, int type);

		/// <summary>
		/// Return subsystem by type.
		/// </summary>
		public Urho.UrhoObject GetSubsystem (StringHash type)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Urho.UrhoObject> (Context_GetSubsystem (handle, type.Code));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_0 (IntPtr handle, int key, ref Vector3 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Vector3 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_0 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_1 (IntPtr handle, int key, ref IntRect value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, IntRect value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_1 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_2 (IntPtr handle, int key, ref Color value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Color value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_2 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_3 (IntPtr handle, int key, ref Vector2 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Vector2 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_3 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_4 (IntPtr handle, int key, ref Vector4 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Vector4 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_4 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_5 (IntPtr handle, int key, ref IntVector2 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, IntVector2 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_5 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_6 (IntPtr handle, int key, ref Quaternion value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Quaternion value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_6 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_7 (IntPtr handle, int key, ref Matrix4 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Matrix4 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_7 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_8 (IntPtr handle, int key, ref Matrix3 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Matrix3 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_8 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_9 (IntPtr handle, int key, ref Matrix3x4 value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, Matrix3x4 value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_9 (handle, key.Code, ref value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_10 (IntPtr handle, int key, int value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, int value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_10 (handle, key.Code, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_11 (IntPtr handle, int key, uint value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, uint value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_11 (handle, key.Code, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_12 (IntPtr handle, int key, float value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, float value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_12 (handle, key.Code, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_13 (IntPtr handle, int key, string value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, string value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_13 (handle, key.Code, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_SetGlobalVar_14 (IntPtr handle, int key, bool value);

		/// <summary>
		/// Set global variable with the respective key and value.
		/// </summary>
		public void SetGlobalVar (StringHash key, bool value)
		{
			Runtime.ValidateRefCounted (this);
			Context_SetGlobalVar_14 (handle, key.Code, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetEventSender (IntPtr handle);

		/// <summary>
		/// Return active event sender. Null outside event handling.
		/// </summary>
		private Urho.UrhoObject GetEventSender ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<Urho.UrhoObject> (Context_GetEventSender (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetEventHandler (IntPtr handle);

		/// <summary>
		/// Return active event handler. Set by Object. Null outside event handling.
		/// </summary>
		private IntPtr GetEventHandler ()
		{
			Runtime.ValidateRefCounted (this);
			return Context_GetEventHandler (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetTypeName (IntPtr handle, int objectType);

		/// <summary>
		/// Return object type name from hash, or empty if unknown.
		/// </summary>
		public string GetTypeName (StringHash objectType)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Context_GetTypeName (handle, objectType.Code));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetEventReceivers (IntPtr handle, IntPtr sender, int eventType);

		/// <summary>
		/// Return event receivers for a sender and event type, or null if they do not exist.
		/// </summary>
		public EventReceiverGroup GetEventReceivers (Urho.UrhoObject sender, StringHash eventType)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<EventReceiverGroup> (Context_GetEventReceivers (handle, (object)sender == null ? IntPtr.Zero : sender.Handle, eventType.Code));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetEventReceivers0 (IntPtr handle, int eventType);

		/// <summary>
		/// Return event receivers for an event type, or null if they do not exist.
		/// </summary>
		public EventReceiverGroup GetEventReceivers (StringHash eventType)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<EventReceiverGroup> (Context_GetEventReceivers0 (handle, eventType.Code));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_RegisterPlugin (IntPtr handle, IntPtr plugin);

		/// <summary>
		/// Register a subsystem.
		/// </summary>
		public void RegisterPlugin (Plugin plugin)
		{
			Runtime.ValidateRefCounted (this);
			Context_RegisterPlugin (handle, (object)plugin == null ? IntPtr.Zero : plugin.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_RemovePlugin (IntPtr handle, int pluginType);

		/// <summary>
		/// Remove a subsystem.
		/// </summary>
		public void RemovePlugin (StringHash pluginType)
		{
			Runtime.ValidateRefCounted (this);
			Context_RemovePlugin (handle, pluginType.Code);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetPlugin (IntPtr handle, int type);

		/// <summary>
		/// Return subsystem by type.
		/// </summary>
		public Plugin GetPlugin (StringHash type)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Plugin> (Context_GetPlugin (handle, type.Code));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Context_PostCommandToPlugin (IntPtr handle, string clazz, string method);

		public bool PostCommandToPlugin (string clazz, string method)
		{
			Runtime.ValidateRefCounted (this);
			return Context_PostCommandToPlugin (handle, clazz, method);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_PopulateByCategory (IntPtr handle, string category);

		public void PopulateByCategory (string category)
		{
			Runtime.ValidateRefCounted (this);
			Context_PopulateByCategory (handle, category);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Context_GetObjectCountInLastPopulatedCetegory (IntPtr handle);

		private int GetObjectCountInLastPopulatedCetegory ()
		{
			Runtime.ValidateRefCounted (this);
			return Context_GetObjectCountInLastPopulatedCetegory (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetObjectInLastPopulatedCetegory (IntPtr handle, int index);

		public string GetObjectInLastPopulatedCetegory (int index)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Context_GetObjectInLastPopulatedCetegory (handle, index));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Context_ClearLastPopulatedCategory (IntPtr handle);

		public void ClearLastPopulatedCategory ()
		{
			Runtime.ValidateRefCounted (this);
			Context_ClearLastPopulatedCategory (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Context_GetCetegoriesSize (IntPtr handle);

		private int GetCetegoriesSize ()
		{
			Runtime.ValidateRefCounted (this);
			return Context_GetCetegoriesSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Context_GetCategory (IntPtr handle, int index);

		public string GetCategory (int index)
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Context_GetCategory (handle, index));
		}

		/// <summary>
		/// Return active event sender. Null outside event handling.
		/// </summary>
		public Urho.UrhoObject EventSender {
			get {
				return GetEventSender ();
			}
		}

		/// <summary>
		/// Return active event handler. Set by Object. Null outside event handling.
		/// </summary>
		public IntPtr EventHandler {
			get {
				return GetEventHandler ();
			}
		}

		public int ObjectCountInLastPopulatedCetegory {
			get {
				return GetObjectCountInLastPopulatedCetegory ();
			}
		}

		public int CetegoriesSize {
			get {
				return GetCetegoriesSize ();
			}
		}
	}
}
