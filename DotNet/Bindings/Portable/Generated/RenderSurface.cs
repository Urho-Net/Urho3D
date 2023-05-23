// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// RenderSurface.cs
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
	/// %Color or depth-stencil surface that can be rendered into.
	/// </summary>
	public unsafe partial class RenderSurface : RefCounted
	{
		unsafe partial void OnRenderSurfaceCreated ();

		[Preserve]
		public RenderSurface (IntPtr handle) : base (handle)
		{
			OnRenderSurfaceCreated ();
		}

		[Preserve]
		protected RenderSurface (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnRenderSurfaceCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_RenderSurface (IntPtr parentTexture);

		[Preserve]
		public RenderSurface (Texture parentTexture) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(RenderSurface));
			handle = RenderSurface_RenderSurface ((object)parentTexture == null ? IntPtr.Zero : parentTexture.Handle);
			Runtime.RegisterObject (this);
			OnRenderSurfaceCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_SetNumViewports (IntPtr handle, uint num);

		/// <summary>
		/// Set number of viewports.
		/// 
		/// </summary>
		private void SetNumViewports (uint num)
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_SetNumViewports (handle, num);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_SetViewport (IntPtr handle, uint index, IntPtr viewport);

		/// <summary>
		/// Set viewport.
		/// 
		/// </summary>
		public void SetViewport (uint index, Viewport viewport)
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_SetViewport (handle, index, (object)viewport == null ? IntPtr.Zero : viewport.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_SetUpdateMode (IntPtr handle, RenderSurfaceUpdateMode mode);

		/// <summary>
		/// Set viewport update mode. Default is to update when visible.
		/// 
		/// </summary>
		private void SetUpdateMode (RenderSurfaceUpdateMode mode)
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_SetUpdateMode (handle, mode);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_SetLinkedRenderTarget (IntPtr handle, IntPtr renderTarget);

		/// <summary>
		/// Set linked color rendertarget.
		/// 
		/// </summary>
		private void SetLinkedRenderTarget (RenderSurface renderTarget)
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_SetLinkedRenderTarget (handle, (object)renderTarget == null ? IntPtr.Zero : renderTarget.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_SetLinkedDepthStencil (IntPtr handle, IntPtr depthStencil);

		/// <summary>
		/// Set linked depth-stencil surface.
		/// 
		/// </summary>
		private void SetLinkedDepthStencil (RenderSurface depthStencil)
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_SetLinkedDepthStencil (handle, (object)depthStencil == null ? IntPtr.Zero : depthStencil.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_QueueUpdate (IntPtr handle);

		/// <summary>
		/// Queue manual update of the viewport(s).
		/// </summary>
		public void QueueUpdate ()
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_QueueUpdate (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_Release (IntPtr handle);

		/// <summary>
		/// Release surface.
		/// </summary>
		public void Release ()
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_Release (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderSurface_CreateRenderBuffer (IntPtr handle, uint width, uint height, uint format, int multiSample);

		/// <summary>
		/// Create renderbuffer that cannot be sampled as a texture. Only used on OpenGL.
		/// </summary>
		public bool CreateRenderBuffer (uint width, uint height, uint format, int multiSample)
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_CreateRenderBuffer (handle, width, height, format, multiSample);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int RenderSurface_GetWidth (IntPtr handle);

		/// <summary>
		/// Return width.
		/// 
		/// </summary>
		private int GetWidth ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetWidth (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int RenderSurface_GetHeight (IntPtr handle);

		/// <summary>
		/// Return height.
		/// 
		/// </summary>
		private int GetHeight ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetHeight (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern TextureUsage RenderSurface_GetUsage (IntPtr handle);

		/// <summary>
		/// Return usage.
		/// 
		/// </summary>
		private TextureUsage GetUsage ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetUsage (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int RenderSurface_GetMultiSample (IntPtr handle);

		/// <summary>
		/// Return multisampling level.
		/// </summary>
		private int GetMultiSample ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetMultiSample (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderSurface_GetAutoResolve (IntPtr handle);

		/// <summary>
		/// Return multisampling autoresolve mode.
		/// </summary>
		private bool GetAutoResolve ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetAutoResolve (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint RenderSurface_GetNumViewports (IntPtr handle);

		/// <summary>
		/// Return number of viewports.
		/// 
		/// </summary>
		private uint GetNumViewports ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetNumViewports (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetViewport (IntPtr handle, uint index);

		/// <summary>
		/// Return viewport by index.
		/// 
		/// </summary>
		public Viewport GetViewport (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Viewport> (RenderSurface_GetViewport (handle, index));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern RenderSurfaceUpdateMode RenderSurface_GetUpdateMode (IntPtr handle);

		/// <summary>
		/// Return viewport update mode.
		/// 
		/// </summary>
		private RenderSurfaceUpdateMode GetUpdateMode ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetUpdateMode (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetLinkedRenderTarget (IntPtr handle);

		/// <summary>
		/// Return linked color rendertarget.
		/// 
		/// </summary>
		private RenderSurface GetLinkedRenderTarget ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<RenderSurface> (RenderSurface_GetLinkedRenderTarget (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetLinkedDepthStencil (IntPtr handle);

		/// <summary>
		/// Return linked depth-stencil surface.
		/// 
		/// </summary>
		private RenderSurface GetLinkedDepthStencil ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<RenderSurface> (RenderSurface_GetLinkedDepthStencil (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderSurface_IsUpdateQueued (IntPtr handle);

		/// <summary>
		/// Return whether manual update queued. Called internally.
		/// </summary>
		private bool IsUpdateQueued ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_IsUpdateQueued (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_ResetUpdateQueued (IntPtr handle);

		/// <summary>
		/// Reset update queued flag. Called internally.
		/// </summary>
		public void ResetUpdateQueued ()
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_ResetUpdateQueued (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetParentTexture (IntPtr handle);

		/// <summary>
		/// Return parent texture.
		/// 
		/// </summary>
		private Texture GetParentTexture ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Texture> (RenderSurface_GetParentTexture (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetSurface (IntPtr handle);

		/// <summary>
		/// Return Direct3D9 surface.
		/// </summary>
		private IntPtr GetSurface ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetSurface (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetRenderTargetView (IntPtr handle);

		/// <summary>
		/// Return Direct3D11 rendertarget or depth-stencil view. Not valid on OpenGL.
		/// </summary>
		private IntPtr GetRenderTargetView ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetRenderTargetView (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr RenderSurface_GetReadOnlyView (IntPtr handle);

		/// <summary>
		/// Return Direct3D11 read-only depth-stencil view. May be null if not applicable. Not valid on OpenGL.
		/// </summary>
		private IntPtr GetReadOnlyView ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetReadOnlyView (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint RenderSurface_GetTarget (IntPtr handle);

		/// <summary>
		/// Return surface's OpenGL target.
		/// </summary>
		private uint GetTarget ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetTarget (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint RenderSurface_GetRenderBuffer (IntPtr handle);

		/// <summary>
		/// Return OpenGL renderbuffer if created.
		/// </summary>
		private uint GetRenderBuffer ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_GetRenderBuffer (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool RenderSurface_IsResolveDirty (IntPtr handle);

		/// <summary>
		/// Return whether multisampled rendertarget needs resolve.
		/// 
		/// </summary>
		private bool IsResolveDirty ()
		{
			Runtime.ValidateRefCounted (this);
			return RenderSurface_IsResolveDirty (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void RenderSurface_SetResolveDirty (IntPtr handle, bool enable);

		/// <summary>
		/// Set or clear the need resolve flag. Called internally by Graphics.
		/// </summary>
		private void SetResolveDirty (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			RenderSurface_SetResolveDirty (handle, enable);
		}

		/// <summary>
		/// Return number of viewports.
		/// 
		/// Or
		/// Set number of viewports.
		/// 
		/// </summary>
		public uint NumViewports {
			get {
				return GetNumViewports ();
			}
			set {
				SetNumViewports (value);
			}
		}

		/// <summary>
		/// Return viewport update mode.
		/// 
		/// Or
		/// Set viewport update mode. Default is to update when visible.
		/// 
		/// </summary>
		public RenderSurfaceUpdateMode UpdateMode {
			get {
				return GetUpdateMode ();
			}
			set {
				SetUpdateMode (value);
			}
		}

		/// <summary>
		/// Return linked color rendertarget.
		/// 
		/// Or
		/// Set linked color rendertarget.
		/// 
		/// </summary>
		public RenderSurface LinkedRenderTarget {
			get {
				return GetLinkedRenderTarget ();
			}
			set {
				SetLinkedRenderTarget (value);
			}
		}

		/// <summary>
		/// Return linked depth-stencil surface.
		/// 
		/// Or
		/// Set linked depth-stencil surface.
		/// 
		/// </summary>
		public RenderSurface LinkedDepthStencil {
			get {
				return GetLinkedDepthStencil ();
			}
			set {
				SetLinkedDepthStencil (value);
			}
		}

		/// <summary>
		/// Return width.
		/// 
		/// </summary>
		public int Width {
			get {
				return GetWidth ();
			}
		}

		/// <summary>
		/// Return height.
		/// 
		/// </summary>
		public int Height {
			get {
				return GetHeight ();
			}
		}

		/// <summary>
		/// Return usage.
		/// 
		/// </summary>
		public TextureUsage Usage {
			get {
				return GetUsage ();
			}
		}

		/// <summary>
		/// Return multisampling level.
		/// </summary>
		public int MultiSample {
			get {
				return GetMultiSample ();
			}
		}

		/// <summary>
		/// Return multisampling autoresolve mode.
		/// </summary>
		public bool AutoResolve {
			get {
				return GetAutoResolve ();
			}
		}

		/// <summary>
		/// Return whether manual update queued. Called internally.
		/// </summary>
		public bool UpdateQueued {
			get {
				return IsUpdateQueued ();
			}
		}

		/// <summary>
		/// Return parent texture.
		/// 
		/// </summary>
		public Texture ParentTexture {
			get {
				return GetParentTexture ();
			}
		}

		/// <summary>
		/// Return Direct3D9 surface.
		/// </summary>
		public IntPtr Surface {
			get {
				return GetSurface ();
			}
		}

		/// <summary>
		/// Return Direct3D11 rendertarget or depth-stencil view. Not valid on OpenGL.
		/// </summary>
		public IntPtr RenderTargetView {
			get {
				return GetRenderTargetView ();
			}
		}

		/// <summary>
		/// Return Direct3D11 read-only depth-stencil view. May be null if not applicable. Not valid on OpenGL.
		/// </summary>
		public IntPtr ReadOnlyView {
			get {
				return GetReadOnlyView ();
			}
		}

		/// <summary>
		/// Return surface's OpenGL target.
		/// </summary>
		public uint Target {
			get {
				return GetTarget ();
			}
		}

		/// <summary>
		/// Return OpenGL renderbuffer if created.
		/// </summary>
		public uint RenderBuffer {
			get {
				return GetRenderBuffer ();
			}
		}

		/// <summary>
		/// Return whether multisampled rendertarget needs resolve.
		/// 
		/// Or
		/// Set or clear the need resolve flag. Called internally by Graphics.
		/// </summary>
		public bool ResolveDirty {
			get {
				return IsResolveDirty ();
			}
			set {
				SetResolveDirty (value);
			}
		}
	}
}
