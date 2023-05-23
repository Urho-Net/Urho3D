// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Drawable.cs
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
	/// Base class for visible components.
	/// </summary>
	public unsafe partial class Drawable : Component
	{
		unsafe partial void OnDrawableCreated ();

		[Preserve]
		public Drawable (IntPtr handle) : base (handle)
		{
			OnDrawableCreated ();
		}

		[Preserve]
		protected Drawable (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnDrawableCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Drawable_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Drawable_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Drawable_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Drawable_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Drawable));
			return new StringHash (Drawable_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Drawable));
			return Marshal.PtrToStringAnsi (Drawable_GetTypeNameStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object attributes. Drawable must be registered first.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Drawable));
			Drawable_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_OnSetEnabled (IntPtr handle);

		/// <summary>
		/// Handle enabled/disabled state change.
		/// </summary>
		public override void OnSetEnabled ()
		{
			Runtime.ValidateRefCounted (this);
			Drawable_OnSetEnabled (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern UpdateGeometryType Drawable_GetUpdateGeometryType (IntPtr handle);

		/// <summary>
		/// Return whether a geometry update is necessary, and if it can happen in a worker thread.
		/// </summary>
		private UpdateGeometryType GetUpdateGeometryType ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetUpdateGeometryType (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable_GetLodGeometry (IntPtr handle, uint batchIndex, uint level);

		/// <summary>
		/// Return the geometry for a specific LOD level.
		/// </summary>
		public virtual Geometry GetLodGeometry (uint batchIndex, uint level)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Geometry> (Drawable_GetLodGeometry (handle, batchIndex, level));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Drawable_GetNumOccluderTriangles (IntPtr handle);

		/// <summary>
		/// Return number of occlusion geometry triangles.
		/// </summary>
		private uint GetNumOccluderTriangles ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetNumOccluderTriangles (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_DrawOcclusion (IntPtr handle, IntPtr buffer);

		/// <summary>
		/// Draw to occlusion buffer. Return true if did not run out of triangles.
		/// </summary>
		public virtual bool DrawOcclusion (OcclusionBuffer buffer)
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_DrawOcclusion (handle, (object)buffer == null ? IntPtr.Zero : buffer.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_DrawDebugGeometry (IntPtr handle, IntPtr debug, bool depthTest);

		/// <summary>
		/// Visualize the component as debug geometry.
		/// </summary>
		public override void DrawDebugGeometry (DebugRenderer debug, bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_DrawDebugGeometry (handle, (object)debug == null ? IntPtr.Zero : debug.Handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetDrawDistance (IntPtr handle, float distance);

		/// <summary>
		/// Set draw distance.
		/// 
		/// </summary>
		private void SetDrawDistance (float distance)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetDrawDistance (handle, distance);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetShadowDistance (IntPtr handle, float distance);

		/// <summary>
		/// Set shadow draw distance.
		/// 
		/// </summary>
		private void SetShadowDistance (float distance)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetShadowDistance (handle, distance);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetLodBias (IntPtr handle, float bias);

		/// <summary>
		/// Set LOD bias.
		/// 
		/// </summary>
		private void SetLodBias (float bias)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetLodBias (handle, bias);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetViewMask (IntPtr handle, uint mask);

		/// <summary>
		/// Set view mask. Is and'ed with camera's view mask to see if the object should be rendered.
		/// 
		/// </summary>
		private void SetViewMask (uint mask)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetViewMask (handle, mask);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetLightMask (IntPtr handle, uint mask);

		/// <summary>
		/// Set light mask. Is and'ed with light's and zone's light mask to see if the object should be lit.
		/// 
		/// </summary>
		private void SetLightMask (uint mask)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetLightMask (handle, mask);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetShadowMask (IntPtr handle, uint mask);

		/// <summary>
		/// Set shadow mask. Is and'ed with light's light mask and zone's shadow mask to see if the object should be rendered to a shadow map.
		/// 
		/// </summary>
		private void SetShadowMask (uint mask)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetShadowMask (handle, mask);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetZoneMask (IntPtr handle, uint mask);

		/// <summary>
		/// Set zone mask. Is and'ed with zone's zone mask to see if the object should belong to the zone.
		/// 
		/// </summary>
		private void SetZoneMask (uint mask)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetZoneMask (handle, mask);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetMaxLights (IntPtr handle, uint num);

		/// <summary>
		/// Set maximum number of per-pixel lights. Default 0 is unlimited.
		/// 
		/// </summary>
		private void SetMaxLights (uint num)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetMaxLights (handle, num);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetCastShadows (IntPtr handle, bool enable);

		/// <summary>
		/// Set shadowcaster flag.
		/// 
		/// </summary>
		private void SetCastShadows (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetCastShadows (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetOccluder (IntPtr handle, bool enable);

		/// <summary>
		/// Set occlusion flag.
		/// 
		/// </summary>
		private void SetOccluder (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetOccluder (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetOccludee (IntPtr handle, bool enable);

		/// <summary>
		/// Set occludee flag.
		/// 
		/// </summary>
		private void SetOccludee (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetOccludee (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_MarkForUpdate (IntPtr handle);

		/// <summary>
		/// Mark for update and octree reinsertion. Update is automatically queued when the drawable's scene node moves or changes scale.
		/// </summary>
		public void MarkForUpdate ()
		{
			Runtime.ValidateRefCounted (this);
			Drawable_MarkForUpdate (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.BoundingBox *
#else
Urho.BoundingBox
#endif
 Drawable_GetBoundingBox (IntPtr handle);

		/// <summary>
		/// Return local space bounding box. May not be applicable or properly updated on all drawables.
		/// 
		/// </summary>
		private Urho.BoundingBox GetBoundingBox ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Drawable_GetBoundingBox
#else
Drawable_GetBoundingBox
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.BoundingBox *
#else
Urho.BoundingBox
#endif
 Drawable_GetWorldBoundingBox (IntPtr handle);

		/// <summary>
		/// Return world-space bounding box.
		/// 
		/// </summary>
		private Urho.BoundingBox GetWorldBoundingBox ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*Drawable_GetWorldBoundingBox
#else
Drawable_GetWorldBoundingBox
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern byte Drawable_GetDrawableFlags (IntPtr handle);

		/// <summary>
		/// Return drawable flags.
		/// </summary>
		private byte GetDrawableFlags ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetDrawableFlags (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetDrawDistance (IntPtr handle);

		/// <summary>
		/// Return draw distance.
		/// 
		/// </summary>
		private float GetDrawDistance ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetDrawDistance (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetShadowDistance (IntPtr handle);

		/// <summary>
		/// Return shadow draw distance.
		/// 
		/// </summary>
		private float GetShadowDistance ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetShadowDistance (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetLodBias (IntPtr handle);

		/// <summary>
		/// Return LOD bias.
		/// 
		/// </summary>
		private float GetLodBias ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetLodBias (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Drawable_GetViewMask (IntPtr handle);

		/// <summary>
		/// Return view mask.
		/// 
		/// </summary>
		private uint GetViewMask ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetViewMask (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Drawable_GetLightMask (IntPtr handle);

		/// <summary>
		/// Return light mask.
		/// 
		/// </summary>
		private uint GetLightMask ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetLightMask (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Drawable_GetShadowMask (IntPtr handle);

		/// <summary>
		/// Return shadow mask.
		/// 
		/// </summary>
		private uint GetShadowMask ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetShadowMask (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Drawable_GetZoneMask (IntPtr handle);

		/// <summary>
		/// Return zone mask.
		/// 
		/// </summary>
		private uint GetZoneMask ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetZoneMask (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Drawable_GetMaxLights (IntPtr handle);

		/// <summary>
		/// Return maximum number of per-pixel lights.
		/// 
		/// </summary>
		private uint GetMaxLights ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetMaxLights (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_GetCastShadows (IntPtr handle);

		/// <summary>
		/// Return shadowcaster flag.
		/// 
		/// </summary>
		private bool GetCastShadows ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetCastShadows (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_IsOccluder (IntPtr handle);

		/// <summary>
		/// Return occluder flag.
		/// 
		/// </summary>
		private bool IsOccluder ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_IsOccluder (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_IsOccludee (IntPtr handle);

		/// <summary>
		/// Return occludee flag.
		/// 
		/// </summary>
		private bool IsOccludee ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_IsOccludee (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_IsInView (IntPtr handle);

		/// <summary>
		/// Return whether is in view this frame from any viewport camera. Excludes shadow map cameras.
		/// 
		/// </summary>
		private bool IsInView ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_IsInView (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_IsInView0 (IntPtr handle, IntPtr camera);

		/// <summary>
		/// Return whether is in view of a specific camera this frame. Pass in a null camera to allow any camera, including shadow map cameras.
		/// </summary>
		public bool IsInView (Camera camera)
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_IsInView0 (handle, (object)camera == null ? IntPtr.Zero : camera.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetZone (IntPtr handle, IntPtr zone, bool temporary);

		/// <summary>
		/// Set new zone. Zone assignment may optionally be temporary, meaning it needs to be re-evaluated on the next frame.
		/// </summary>
		public void SetZone (Zone zone, bool temporary = false)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetZone (handle, (object)zone == null ? IntPtr.Zero : zone.Handle, temporary);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetSortValue (IntPtr handle, float value);

		/// <summary>
		/// Set sorting value.
		/// </summary>
		private void SetSortValue (float value)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetSortValue (handle, value);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetMinMaxZ (IntPtr handle, float minZ, float maxZ);

		/// <summary>
		/// Set view-space depth bounds.
		/// </summary>
		public void SetMinMaxZ (float minZ, float maxZ)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetMinMaxZ (handle, minZ, maxZ);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_MarkInView (IntPtr handle, uint frameNumber);

		/// <summary>
		/// Mark in view without specifying a camera. Used for shadow casters.
		/// </summary>
		public void MarkInView (uint frameNumber)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_MarkInView (handle, frameNumber);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_LimitLights (IntPtr handle);

		/// <summary>
		/// Sort and limit per-pixel lights to maximum allowed. Convert extra lights into vertex lights.
		/// </summary>
		public void LimitLights ()
		{
			Runtime.ValidateRefCounted (this);
			Drawable_LimitLights (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_LimitVertexLights (IntPtr handle, bool removeConvertedLights);

		/// <summary>
		/// Sort and limit per-vertex lights to maximum allowed.
		/// </summary>
		public void LimitVertexLights (bool removeConvertedLights)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_LimitVertexLights (handle, removeConvertedLights);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_SetBasePass (IntPtr handle, uint batchIndex);

		/// <summary>
		/// Set base pass flag for a batch.
		/// </summary>
		public void SetBasePass (uint batchIndex)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_SetBasePass (handle, batchIndex);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Octant* Drawable_GetOctant (IntPtr handle);

		/// <summary>
		/// Return octree octant.
		/// </summary>
		private Octant* GetOctant ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetOctant (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable_GetZone (IntPtr handle);

		/// <summary>
		/// Return current zone.
		/// 
		/// </summary>
		private Zone GetZone ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Zone> (Drawable_GetZone (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_IsZoneDirty (IntPtr handle);

		/// <summary>
		/// Return whether current zone is inconclusive or dirty due to the drawable moving.
		/// </summary>
		private bool IsZoneDirty ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_IsZoneDirty (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetDistance (IntPtr handle);

		/// <summary>
		/// Return distance from camera.
		/// </summary>
		private float GetDistance ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetDistance (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetLodDistance (IntPtr handle);

		/// <summary>
		/// Return LOD scaled distance from camera.
		/// </summary>
		private float GetLodDistance ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetLodDistance (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetSortValue (IntPtr handle);

		/// <summary>
		/// Return sorting value.
		/// </summary>
		private float GetSortValue ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetSortValue (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Drawable_HasBasePass (IntPtr handle, uint batchIndex);

		/// <summary>
		/// Return whether has a base pass.
		/// </summary>
		public bool HasBasePass (uint batchIndex)
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_HasBasePass (handle, batchIndex);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable_GetFirstLight (IntPtr handle);

		/// <summary>
		/// Return the first added per-pixel light.
		/// </summary>
		private Light GetFirstLight ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Light> (Drawable_GetFirstLight (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetMinZ (IntPtr handle);

		/// <summary>
		/// Return the minimum view-space depth.
		/// </summary>
		private float GetMinZ ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetMinZ (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Drawable_GetMaxZ (IntPtr handle);

		/// <summary>
		/// Return the maximum view-space depth.
		/// </summary>
		private float GetMaxZ ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable_GetMaxZ (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_AddLight (IntPtr handle, IntPtr light);

		/// <summary>
		/// Add a per-pixel light affecting the object this frame.
		/// </summary>
		public void AddLight (Light light)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_AddLight (handle, (object)light == null ? IntPtr.Zero : light.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable_AddVertexLight (IntPtr handle, IntPtr light);

		/// <summary>
		/// Add a per-vertex light affecting the object this frame.
		/// </summary>
		public void AddVertexLight (Light light)
		{
			Runtime.ValidateRefCounted (this);
			Drawable_AddVertexLight (handle, (object)light == null ? IntPtr.Zero : light.Handle);
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
		/// Return whether a geometry update is necessary, and if it can happen in a worker thread.
		/// </summary>
		public virtual UpdateGeometryType UpdateGeometryType {
			get {
				return GetUpdateGeometryType ();
			}
		}

		/// <summary>
		/// Return number of occlusion geometry triangles.
		/// </summary>
		public virtual uint NumOccluderTriangles {
			get {
				return GetNumOccluderTriangles ();
			}
		}

		/// <summary>
		/// Return draw distance.
		/// 
		/// Or
		/// Set draw distance.
		/// 
		/// </summary>
		public float DrawDistance {
			get {
				return GetDrawDistance ();
			}
			set {
				SetDrawDistance (value);
			}
		}

		/// <summary>
		/// Return shadow draw distance.
		/// 
		/// Or
		/// Set shadow draw distance.
		/// 
		/// </summary>
		public float ShadowDistance {
			get {
				return GetShadowDistance ();
			}
			set {
				SetShadowDistance (value);
			}
		}

		/// <summary>
		/// Return LOD bias.
		/// 
		/// Or
		/// Set LOD bias.
		/// 
		/// </summary>
		public float LodBias {
			get {
				return GetLodBias ();
			}
			set {
				SetLodBias (value);
			}
		}

		/// <summary>
		/// Return view mask.
		/// 
		/// Or
		/// Set view mask. Is and'ed with camera's view mask to see if the object should be rendered.
		/// 
		/// </summary>
		public uint ViewMask {
			get {
				return GetViewMask ();
			}
			set {
				SetViewMask (value);
			}
		}

		/// <summary>
		/// Return light mask.
		/// 
		/// Or
		/// Set light mask. Is and'ed with light's and zone's light mask to see if the object should be lit.
		/// 
		/// </summary>
		public uint LightMask {
			get {
				return GetLightMask ();
			}
			set {
				SetLightMask (value);
			}
		}

		/// <summary>
		/// Return shadow mask.
		/// 
		/// Or
		/// Set shadow mask. Is and'ed with light's light mask and zone's shadow mask to see if the object should be rendered to a shadow map.
		/// 
		/// </summary>
		public uint ShadowMask {
			get {
				return GetShadowMask ();
			}
			set {
				SetShadowMask (value);
			}
		}

		/// <summary>
		/// Return zone mask.
		/// 
		/// Or
		/// Set zone mask. Is and'ed with zone's zone mask to see if the object should belong to the zone.
		/// 
		/// </summary>
		public uint ZoneMask {
			get {
				return GetZoneMask ();
			}
			set {
				SetZoneMask (value);
			}
		}

		/// <summary>
		/// Return maximum number of per-pixel lights.
		/// 
		/// Or
		/// Set maximum number of per-pixel lights. Default 0 is unlimited.
		/// 
		/// </summary>
		public uint MaxLights {
			get {
				return GetMaxLights ();
			}
			set {
				SetMaxLights (value);
			}
		}

		/// <summary>
		/// Return shadowcaster flag.
		/// 
		/// Or
		/// Set shadowcaster flag.
		/// 
		/// </summary>
		public bool CastShadows {
			get {
				return GetCastShadows ();
			}
			set {
				SetCastShadows (value);
			}
		}

		/// <summary>
		/// Return occluder flag.
		/// 
		/// Or
		/// Set occlusion flag.
		/// 
		/// </summary>
		public bool Occluder {
			get {
				return IsOccluder ();
			}
			set {
				SetOccluder (value);
			}
		}

		/// <summary>
		/// Return occludee flag.
		/// 
		/// Or
		/// Set occludee flag.
		/// 
		/// </summary>
		public bool Occludee {
			get {
				return IsOccludee ();
			}
			set {
				SetOccludee (value);
			}
		}

		/// <summary>
		/// Return local space bounding box. May not be applicable or properly updated on all drawables.
		/// 
		/// </summary>
		public Urho.BoundingBox BoundingBox {
			get {
				return GetBoundingBox ();
			}
		}

		/// <summary>
		/// Return world-space bounding box.
		/// 
		/// </summary>
		public Urho.BoundingBox WorldBoundingBox {
			get {
				return GetWorldBoundingBox ();
			}
		}

		/// <summary>
		/// Return drawable flags.
		/// </summary>
		public byte DrawableFlags {
			get {
				return GetDrawableFlags ();
			}
		}

		/// <summary>
		/// Return whether is in view this frame from any viewport camera. Excludes shadow map cameras.
		/// 
		/// </summary>
		public bool InView {
			get {
				return IsInView ();
			}
		}

		/// <summary>
		/// Return sorting value.
		/// Or
		/// Set sorting value.
		/// </summary>
		public float SortValue {
			get {
				return GetSortValue ();
			}
			set {
				SetSortValue (value);
			}
		}

		/// <summary>
		/// Return octree octant.
		/// </summary>
		public Octant* Octant {
			get {
				return GetOctant ();
			}
		}

		/// <summary>
		/// Return current zone.
		/// 
		/// </summary>
		public Zone Zone {
			get {
				return GetZone ();
			}
		}

		/// <summary>
		/// Return whether current zone is inconclusive or dirty due to the drawable moving.
		/// </summary>
		public bool ZoneDirty {
			get {
				return IsZoneDirty ();
			}
		}

		/// <summary>
		/// Return distance from camera.
		/// </summary>
		public float Distance {
			get {
				return GetDistance ();
			}
		}

		/// <summary>
		/// Return LOD scaled distance from camera.
		/// </summary>
		public float LodDistance {
			get {
				return GetLodDistance ();
			}
		}

		/// <summary>
		/// Return the first added per-pixel light.
		/// </summary>
		public Light FirstLight {
			get {
				return GetFirstLight ();
			}
		}

		/// <summary>
		/// Return the minimum view-space depth.
		/// </summary>
		public float MinZ {
			get {
				return GetMinZ ();
			}
		}

		/// <summary>
		/// Return the maximum view-space depth.
		/// </summary>
		public float MaxZ {
			get {
				return GetMaxZ ();
			}
		}
	}
}
