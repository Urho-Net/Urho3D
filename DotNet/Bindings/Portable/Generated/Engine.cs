// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Engine.cs
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
	/// Urho3D engine. Creates the other subsystems.
	/// </summary>
	public unsafe partial class Engine : UrhoObject
	{
		unsafe partial void OnEngineCreated ();

		[Preserve]
		public Engine (IntPtr handle) : base (handle)
		{
			OnEngineCreated ();
		}

		[Preserve]
		protected Engine (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnEngineCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Engine_GetType (IntPtr handle);

		private StringHash GetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Engine_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Engine_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Engine_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Engine_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Engine));
			return new StringHash (Engine_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Engine_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Engine));
			return Marshal.PtrToStringAnsi (Engine_GetTypeNameStatic ());
		}

		[Preserve]
		public Engine () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Engine_Engine (IntPtr context);

		[Preserve]
		public Engine (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Engine));
			handle = Engine_Engine ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnEngineCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_RunFrame (IntPtr handle);

		/// <summary>
		/// Run one frame.
		/// </summary>
		public void RunFrame ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_RunFrame (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Engine_CreateConsole (IntPtr handle);

		/// <summary>
		/// Create the console and return it. May return null if engine configuration does not allow creation (headless mode).
		/// </summary>
		public Urho.UrhoConsole CreateConsole ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Urho.UrhoConsole> (Engine_CreateConsole (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Engine_CreateDebugHud (IntPtr handle);

		/// <summary>
		/// Create the debug hud.
		/// </summary>
		public DebugHud CreateDebugHud ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<DebugHud> (Engine_CreateDebugHud (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetMinFps (IntPtr handle, int fps);

		/// <summary>
		/// Set minimum frames per second. If FPS goes lower than this, time will appear to slow down.
		/// 
		/// </summary>
		private void SetMinFps (int fps)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetMinFps (handle, fps);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetMaxFps (IntPtr handle, int fps);

		/// <summary>
		/// Set maximum frames per second. The engine will sleep if FPS is higher than this.
		/// 
		/// </summary>
		private void SetMaxFps (int fps)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetMaxFps (handle, fps);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetMaxInactiveFps (IntPtr handle, int fps);

		/// <summary>
		/// Set maximum frames per second when the application does not have input focus.
		/// 
		/// </summary>
		private void SetMaxInactiveFps (int fps)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetMaxInactiveFps (handle, fps);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetTimeStepSmoothing (IntPtr handle, int frames);

		/// <summary>
		/// Set how many frames to average for timestep smoothing. Default is 2. 1 disables smoothing.
		/// 
		/// </summary>
		private void SetTimeStepSmoothing (int frames)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetTimeStepSmoothing (handle, frames);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetPauseMinimized (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether to pause update events and audio when minimized.
		/// 
		/// </summary>
		private void SetPauseMinimized (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetPauseMinimized (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetAutoExit (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether to exit automatically on exit request (window close button).
		/// 
		/// </summary>
		private void SetAutoExit (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetAutoExit (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_SetNextTimeStep (IntPtr handle, float seconds);

		/// <summary>
		/// Override timestep of the next frame. Should be called in between RunFrame() calls.
		/// </summary>
		private void SetNextTimeStep (float seconds)
		{
			Runtime.ValidateRefCounted (this);
			Engine_SetNextTimeStep (handle, seconds);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_Exit (IntPtr handle);

		/// <summary>
		/// Close the graphics window and set the exit flag. No-op on iOS/tvOS, as an iOS/tvOS application can not legally exit.
		/// </summary>
		internal void Exit ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_Exit (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_DumpProfiler (IntPtr handle);

		/// <summary>
		/// Dump profiling information to the log.
		/// </summary>
		public void DumpProfiler ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_DumpProfiler (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_DumpResources (IntPtr handle, bool dumpFileName);

		/// <summary>
		/// Dump information of all resources to the log.
		/// </summary>
		public void DumpResources (bool dumpFileName = false)
		{
			Runtime.ValidateRefCounted (this);
			Engine_DumpResources (handle, dumpFileName);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_DumpMemory (IntPtr handle);

		/// <summary>
		/// Dump information of all memory allocations to the log. Supported in MSVC debug mode only.
		/// </summary>
		public void DumpMemory ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_DumpMemory (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Engine_GetNextTimeStep (IntPtr handle);

		/// <summary>
		/// Get timestep of the next frame. Updated by ApplyFrameLimit().
		/// </summary>
		private float GetNextTimeStep ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetNextTimeStep (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Engine_GetMinFps (IntPtr handle);

		/// <summary>
		/// Return the minimum frames per second.
		/// 
		/// </summary>
		private int GetMinFps ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetMinFps (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Engine_GetMaxFps (IntPtr handle);

		/// <summary>
		/// Return the maximum frames per second.
		/// 
		/// </summary>
		private int GetMaxFps ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetMaxFps (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Engine_GetMaxInactiveFps (IntPtr handle);

		/// <summary>
		/// Return the maximum frames per second when the application does not have input focus.
		/// 
		/// </summary>
		private int GetMaxInactiveFps ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetMaxInactiveFps (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Engine_GetTimeStepSmoothing (IntPtr handle);

		/// <summary>
		/// Return how many frames to average for timestep smoothing.
		/// 
		/// </summary>
		private int GetTimeStepSmoothing ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetTimeStepSmoothing (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Engine_GetPauseMinimized (IntPtr handle);

		/// <summary>
		/// Return whether to pause update events and audio when minimized.
		/// 
		/// </summary>
		private bool GetPauseMinimized ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetPauseMinimized (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Engine_GetAutoExit (IntPtr handle);

		/// <summary>
		/// Return whether to exit automatically on exit request.
		/// 
		/// </summary>
		private bool GetAutoExit ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_GetAutoExit (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Engine_IsInitialized (IntPtr handle);

		/// <summary>
		/// Return whether engine has been initialized.
		/// 
		/// </summary>
		private bool IsInitialized ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_IsInitialized (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Engine_IsExiting (IntPtr handle);

		/// <summary>
		/// Return whether exit has been requested.
		/// 
		/// </summary>
		private bool IsExiting ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_IsExiting (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Engine_IsHeadless (IntPtr handle);

		/// <summary>
		/// Return whether the engine has been created in headless mode.
		/// 
		/// </summary>
		private bool IsHeadless ()
		{
			Runtime.ValidateRefCounted (this);
			return Engine_IsHeadless (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_Update (IntPtr handle);

		/// <summary>
		/// Send frame update events.
		/// </summary>
		public void UpdateFrame ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_Update (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_Render (IntPtr handle);

		/// <summary>
		/// Render after frame update.
		/// </summary>
		public void Render ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_Render (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Engine_ApplyFrameLimit (IntPtr handle);

		/// <summary>
		/// Get the timestep for the next frame and sleep for frame limiting if necessary.
		/// </summary>
		public void ApplyFrameLimit ()
		{
			Runtime.ValidateRefCounted (this);
			Engine_ApplyFrameLimit (handle);
		}

		public override StringHash Type {
			get {
				return GetType ();
			}
		}

		public override string TypeName {
			get {
				return GetTypeName ();
			}
		}

		[Preserve]
		public static StringHash TypeStatic {
			get {
				return GetTypeStatic ();
			}
		}

		public static string TypeNameStatic {
			get {
				return GetTypeNameStatic ();
			}
		}

		/// <summary>
		/// Return the minimum frames per second.
		/// 
		/// Or
		/// Set minimum frames per second. If FPS goes lower than this, time will appear to slow down.
		/// 
		/// </summary>
		public int MinFps {
			get {
				return GetMinFps ();
			}
			set {
				SetMinFps (value);
			}
		}

		/// <summary>
		/// Return the maximum frames per second.
		/// 
		/// Or
		/// Set maximum frames per second. The engine will sleep if FPS is higher than this.
		/// 
		/// </summary>
		public int MaxFps {
			get {
				return GetMaxFps ();
			}
			set {
				SetMaxFps (value);
			}
		}

		/// <summary>
		/// Return the maximum frames per second when the application does not have input focus.
		/// 
		/// Or
		/// Set maximum frames per second when the application does not have input focus.
		/// 
		/// </summary>
		public int MaxInactiveFps {
			get {
				return GetMaxInactiveFps ();
			}
			set {
				SetMaxInactiveFps (value);
			}
		}

		/// <summary>
		/// Return how many frames to average for timestep smoothing.
		/// 
		/// Or
		/// Set how many frames to average for timestep smoothing. Default is 2. 1 disables smoothing.
		/// 
		/// </summary>
		public int TimeStepSmoothing {
			get {
				return GetTimeStepSmoothing ();
			}
			set {
				SetTimeStepSmoothing (value);
			}
		}

		/// <summary>
		/// Return whether to pause update events and audio when minimized.
		/// 
		/// Or
		/// Set whether to pause update events and audio when minimized.
		/// 
		/// </summary>
		public bool PauseMinimized {
			get {
				return GetPauseMinimized ();
			}
			set {
				SetPauseMinimized (value);
			}
		}

		/// <summary>
		/// Return whether to exit automatically on exit request.
		/// 
		/// Or
		/// Set whether to exit automatically on exit request (window close button).
		/// 
		/// </summary>
		public bool AutoExit {
			get {
				return GetAutoExit ();
			}
			set {
				SetAutoExit (value);
			}
		}

		/// <summary>
		/// Get timestep of the next frame. Updated by ApplyFrameLimit().
		/// Or
		/// Override timestep of the next frame. Should be called in between RunFrame() calls.
		/// </summary>
		public float NextTimeStep {
			get {
				return GetNextTimeStep ();
			}
			set {
				SetNextTimeStep (value);
			}
		}

		/// <summary>
		/// Return whether engine has been initialized.
		/// 
		/// </summary>
		public bool Initialized {
			get {
				return IsInitialized ();
			}
		}

		/// <summary>
		/// Return whether exit has been requested.
		/// 
		/// </summary>
		public bool Exiting {
			get {
				return IsExiting ();
			}
		}

		/// <summary>
		/// Return whether the engine has been created in headless mode.
		/// 
		/// </summary>
		public bool Headless {
			get {
				return IsHeadless ();
			}
		}
	}
}
