// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Viewport.cs
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
	/// %Viewport definition either for a render surface or the backbuffer.
	/// </summary>
	public unsafe partial class Viewport : UrhoObject
	{
		unsafe partial void OnViewportCreated ();

		[Preserve]
		public Viewport (IntPtr handle) : base (handle)
		{
			OnViewportCreated ();
		}

		[Preserve]
		protected Viewport (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnViewportCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Viewport_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Viewport_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Viewport_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Viewport_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Viewport));
			return new StringHash (Viewport_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Viewport));
			return Marshal.PtrToStringAnsi (Viewport_GetTypeNameStatic ());
		}

		[Preserve]
		public Viewport () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_Viewport (IntPtr context);

		[Preserve]
		public Viewport (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Viewport));
			handle = Viewport_Viewport ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnViewportCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_Viewport0 (IntPtr context, IntPtr scene, IntPtr camera, IntPtr renderPath);

		[Preserve]
		public Viewport (Context context, Scene scene, Camera camera, RenderPath renderPath = null) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Viewport));
			handle = Viewport_Viewport0 ((object)context == null ? IntPtr.Zero : context.Handle, (object)scene == null ? IntPtr.Zero : scene.Handle, (object)camera == null ? IntPtr.Zero : camera.Handle, (object)renderPath == null ? IntPtr.Zero : renderPath.Handle);
			Runtime.RegisterObject (this);
			OnViewportCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_Viewport1 (IntPtr context, IntPtr scene, IntPtr camera, ref Urho.IntRect rect, IntPtr renderPath);

		[Preserve]
		public Viewport (Context context, Scene scene, Camera camera, Urho.IntRect rect, RenderPath renderPath = null) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Viewport));
			handle = Viewport_Viewport1 ((object)context == null ? IntPtr.Zero : context.Handle, (object)scene == null ? IntPtr.Zero : scene.Handle, (object)camera == null ? IntPtr.Zero : camera.Handle, ref rect, (object)renderPath == null ? IntPtr.Zero : renderPath.Handle);
			Runtime.RegisterObject (this);
			OnViewportCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetScene (IntPtr handle, IntPtr scene);

		/// <summary>
		/// Set scene.
		/// 
		/// </summary>
		private void SetScene (Scene scene)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetScene (handle, (object)scene == null ? IntPtr.Zero : scene.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetCamera (IntPtr handle, IntPtr camera);

		/// <summary>
		/// Set viewport camera.
		/// 
		/// </summary>
		private void SetCamera (Camera camera)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetCamera (handle, (object)camera == null ? IntPtr.Zero : camera.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetRect (IntPtr handle, ref Urho.IntRect rect);

		/// <summary>
		/// Set view rectangle. A zero rectangle (0 0 0 0) means to use the rendertarget's full dimensions.
		/// 
		/// </summary>
		private void SetRect (Urho.IntRect rect)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetRect (handle, ref rect);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetRenderPath (IntPtr handle, IntPtr renderPath);

		/// <summary>
		/// Set rendering path.
		/// 
		/// </summary>
		private void SetRenderPath (RenderPath renderPath)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetRenderPath (handle, (object)renderPath == null ? IntPtr.Zero : renderPath.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Viewport_SetRenderPath2 (IntPtr handle, IntPtr file);

		/// <summary>
		/// Set rendering path from an XML file.
		/// </summary>
		public bool SetRenderPath (Urho.Resources.XmlFile file)
		{
			Runtime.ValidateRefCounted (this);
			return Viewport_SetRenderPath2 (handle, (object)file == null ? IntPtr.Zero : file.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetDrawDebug (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether to render debug geometry. Default true.
		/// 
		/// </summary>
		private void SetDrawDebug (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetDrawDebug (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetCullCamera (IntPtr handle, IntPtr camera);

		/// <summary>
		/// Set separate camera to use for culling. Sharing a culling camera between several viewports allows to prepare the view only once, saving in CPU use. The culling camera's frustum should cover all the viewport cameras' frusta or else objects may be missing from the rendered view.
		/// 
		/// </summary>
		private void SetCullCamera (Camera camera)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetCullCamera (handle, (object)camera == null ? IntPtr.Zero : camera.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetScene (IntPtr handle);

		/// <summary>
		/// Return scene.
		/// 
		/// </summary>
		private Scene GetScene ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Scene> (Viewport_GetScene (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetCamera (IntPtr handle);

		/// <summary>
		/// Return viewport camera.
		/// 
		/// </summary>
		private Camera GetCamera ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Camera> (Viewport_GetCamera (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetView (IntPtr handle);

		/// <summary>
		/// Return the internal rendering structure. May be null if the viewport has not been rendered yet.
		/// </summary>
		private View GetView ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<View> (Viewport_GetView (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.IntRect *
#else
Urho.IntRect
#endif
 Viewport_GetRect (IntPtr handle);

		/// <summary>
		/// Return view rectangle. A zero rectangle (0 0 0 0) means to use the rendertarget's full dimensions. In this case you could fetch the actual view rectangle from View object, though it will be valid only after the first frame.
		/// 
		/// </summary>
		private Urho.IntRect GetRect ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Viewport_GetRect
#else
Viewport_GetRect
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetRenderPath (IntPtr handle);

		/// <summary>
		/// Return rendering path.
		/// 
		/// </summary>
		private RenderPath GetRenderPath ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<RenderPath> (Viewport_GetRenderPath (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Viewport_GetDrawDebug (IntPtr handle);

		/// <summary>
		/// Return whether to draw debug geometry.
		/// 
		/// </summary>
		private bool GetDrawDebug ()
		{
			Runtime.ValidateRefCounted (this);
			return Viewport_GetDrawDebug (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Viewport_GetCullCamera (IntPtr handle);

		/// <summary>
		/// Return the culling camera. If null, the viewport camera will be used for culling (normal case).
		/// 
		/// </summary>
		private Camera GetCullCamera ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Camera> (Viewport_GetCullCamera (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Ray *
#else
Ray
#endif
 Viewport_GetScreenRay (IntPtr handle, int x, int y);

		/// <summary>
		/// Return ray corresponding to normalized screen coordinates.
		/// </summary>
		public Ray GetScreenRay (int x, int y)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Viewport_GetScreenRay
#else
Viewport_GetScreenRay
#endif
 (handle, x, y);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.IntVector2 *
#else
Urho.IntVector2
#endif
 Viewport_WorldToScreenPoint (IntPtr handle, ref Urho.Vector3 worldPos);

		/// <summary>
		/// Convert a world space point to normalized screen coordinates.
		/// </summary>
		public Urho.IntVector2 WorldToScreenPoint (Urho.Vector3 worldPos)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Viewport_WorldToScreenPoint
#else
Viewport_WorldToScreenPoint
#endif
 (handle, ref worldPos);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 Viewport_ScreenToWorldPoint (IntPtr handle, int x, int y, float depth);

		/// <summary>
		/// Convert screen coordinates and depth to a world space point.
		/// </summary>
		public Vector3 ScreenToWorldPoint (int x, int y, float depth)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Viewport_ScreenToWorldPoint
#else
Viewport_ScreenToWorldPoint
#endif
 (handle, x, y, depth);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_AllocateView (IntPtr handle);

		/// <summary>
		/// Allocate the view structure. Called by Renderer.
		/// </summary>
		public void AllocateView ()
		{
			Runtime.ValidateRefCounted (this);
			Viewport_AllocateView (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Viewport_SetClearColor (IntPtr handle, ref Urho.Color color);

		/// <summary>
		/// Set  Viewport clear color , will override the color set in the RenderPath (CLEAR_CMD) , setting  the value of Color(0,0,0,0) will reset it to the default clear color used in the RenderPath
		/// </summary>
		public void SetClearColor (Urho.Color color)
		{
			Runtime.ValidateRefCounted (this);
			Viewport_SetClearColor (handle, ref color);
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
		/// Return scene.
		/// 
		/// Or
		/// Set scene.
		/// 
		/// </summary>
		public Scene Scene {
			get {
				return GetScene ();
			}
			set {
				SetScene (value);
			}
		}

		/// <summary>
		/// Return viewport camera.
		/// 
		/// Or
		/// Set viewport camera.
		/// 
		/// </summary>
		public Camera Camera {
			get {
				return GetCamera ();
			}
			set {
				SetCamera (value);
			}
		}

		/// <summary>
		/// Return view rectangle. A zero rectangle (0 0 0 0) means to use the rendertarget's full dimensions. In this case you could fetch the actual view rectangle from View object, though it will be valid only after the first frame.
		/// 
		/// Or
		/// Set view rectangle. A zero rectangle (0 0 0 0) means to use the rendertarget's full dimensions.
		/// 
		/// </summary>
		public Urho.IntRect Rect {
			get {
				return GetRect ();
			}
			set {
				SetRect (value);
			}
		}

		/// <summary>
		/// Return rendering path.
		/// 
		/// Or
		/// Set rendering path.
		/// 
		/// </summary>
		public RenderPath RenderPath {
			get {
				return GetRenderPath ();
			}
			set {
				SetRenderPath (value);
			}
		}

		/// <summary>
		/// Return whether to draw debug geometry.
		/// 
		/// Or
		/// Set whether to render debug geometry. Default true.
		/// 
		/// </summary>
		public bool DrawDebug {
			get {
				return GetDrawDebug ();
			}
			set {
				SetDrawDebug (value);
			}
		}

		/// <summary>
		/// Return the culling camera. If null, the viewport camera will be used for culling (normal case).
		/// 
		/// Or
		/// Set separate camera to use for culling. Sharing a culling camera between several viewports allows to prepare the view only once, saving in CPU use. The culling camera's frustum should cover all the viewport cameras' frusta or else objects may be missing from the rendered view.
		/// 
		/// </summary>
		public Camera CullCamera {
			get {
				return GetCullCamera ();
			}
			set {
				SetCullCamera (value);
			}
		}

		/// <summary>
		/// Return the internal rendering structure. May be null if the viewport has not been rendered yet.
		/// </summary>
		public View View {
			get {
				return GetView ();
			}
		}
	}
}
