// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Sphere.cs
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
	/// %Sphere in three-dimensional space.
	/// </summary>
	public unsafe partial class Sphere
	{
		private IntPtr handle;

		public IntPtr Handle {
			get {
				return handle;
			}
		}

		unsafe partial void OnSphereCreated ();

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere ();

		[Preserve]
		public Sphere ()
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere ();
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere0 (IntPtr sphere);

		[Preserve]
		public Sphere (Sphere sphere)
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere0 ((object)sphere == null ? IntPtr.Zero : sphere.Handle);
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere1 (ref Urho.Vector3 center, float radius);

		[Preserve]
		public Sphere (Urho.Vector3 center, float radius)
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere1 (ref center, radius);
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere2 (Vector3* vertices, uint count);

		[Preserve]
		public Sphere (Vector3* vertices, uint count)
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere2 (vertices, count);
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere3 (ref Urho.BoundingBox box);

		[Preserve]
		public Sphere (Urho.BoundingBox box)
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere3 (ref box);
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere4 (IntPtr frustum);

		[Preserve]
		public Sphere (Frustum frustum)
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere4 ((object)frustum == null ? IntPtr.Zero : frustum.Handle);
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sphere_Sphere5 (IntPtr poly);

		[Preserve]
		public Sphere (Polyhedron poly)
		{
			Runtime.Validate (typeof(Sphere));
			handle = Sphere_Sphere5 ((object)poly == null ? IntPtr.Zero : poly.Handle);
			OnSphereCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Define (IntPtr handle, IntPtr sphere);

		/// <summary>
		/// Define from another sphere.
		/// </summary>
		public void Define (Sphere sphere)
		{
			Runtime.ValidateObject (this);
			Sphere_Define (handle, (object)sphere == null ? IntPtr.Zero : sphere.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Define6 (IntPtr handle, ref Urho.Vector3 center, float radius);

		/// <summary>
		/// Define from center and radius.
		/// </summary>
		public void Define (Urho.Vector3 center, float radius)
		{
			Runtime.ValidateObject (this);
			Sphere_Define6 (handle, ref center, radius);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Define7 (IntPtr handle, Vector3* vertices, uint count);

		/// <summary>
		/// Define from an array of vertices.
		/// </summary>
		public void Define (Vector3* vertices, uint count)
		{
			Runtime.ValidateObject (this);
			Sphere_Define7 (handle, vertices, count);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Define8 (IntPtr handle, ref Urho.BoundingBox box);

		/// <summary>
		/// Define from a bounding box.
		/// </summary>
		public void Define (Urho.BoundingBox box)
		{
			Runtime.ValidateObject (this);
			Sphere_Define8 (handle, ref box);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Define9 (IntPtr handle, IntPtr frustum);

		/// <summary>
		/// Define from a frustum.
		/// </summary>
		public void Define (Frustum frustum)
		{
			Runtime.ValidateObject (this);
			Sphere_Define9 (handle, (object)frustum == null ? IntPtr.Zero : frustum.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Define10 (IntPtr handle, IntPtr poly);

		/// <summary>
		/// Define from a polyhedron.
		/// </summary>
		public void Define (Polyhedron poly)
		{
			Runtime.ValidateObject (this);
			Sphere_Define10 (handle, (object)poly == null ? IntPtr.Zero : poly.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Merge (IntPtr handle, ref Urho.Vector3 point);

		/// <summary>
		/// Merge a point.
		/// </summary>
		public void Merge (Urho.Vector3 point)
		{
			Runtime.ValidateObject (this);
			Sphere_Merge (handle, ref point);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Merge11 (IntPtr handle, Vector3* vertices, uint count);

		/// <summary>
		/// Merge an array of vertices.
		/// </summary>
		public void Merge (Vector3* vertices, uint count)
		{
			Runtime.ValidateObject (this);
			Sphere_Merge11 (handle, vertices, count);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Merge12 (IntPtr handle, ref Urho.BoundingBox box);

		/// <summary>
		/// Merge a bounding box.
		/// </summary>
		public void Merge (Urho.BoundingBox box)
		{
			Runtime.ValidateObject (this);
			Sphere_Merge12 (handle, ref box);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Merge13 (IntPtr handle, IntPtr frustum);

		/// <summary>
		/// Merge a frustum.
		/// </summary>
		public void Merge (Frustum frustum)
		{
			Runtime.ValidateObject (this);
			Sphere_Merge13 (handle, (object)frustum == null ? IntPtr.Zero : frustum.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Merge14 (IntPtr handle, IntPtr poly);

		/// <summary>
		/// Merge a polyhedron.
		/// </summary>
		public void Merge (Polyhedron poly)
		{
			Runtime.ValidateObject (this);
			Sphere_Merge14 (handle, (object)poly == null ? IntPtr.Zero : poly.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Merge15 (IntPtr handle, IntPtr sphere);

		/// <summary>
		/// Merge a sphere.
		/// </summary>
		public void Merge (Sphere sphere)
		{
			Runtime.ValidateObject (this);
			Sphere_Merge15 (handle, (object)sphere == null ? IntPtr.Zero : sphere.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_Clear (IntPtr handle);

		/// <summary>
		/// Clear to undefined state.
		/// </summary>
		public void Clear ()
		{
			Runtime.ValidateObject (this);
			Sphere_Clear (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sphere_Defined (IntPtr handle);

		/// <summary>
		/// Return true if this sphere is defined via a previous call to Define() or Merge().
		/// </summary>
		public bool Defined ()
		{
			Runtime.ValidateObject (this);
			return Sphere_Defined (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Intersection Sphere_IsInside (IntPtr handle, ref Urho.Vector3 point);

		/// <summary>
		/// Test if a point is inside.
		/// </summary>
		public Intersection IsInside (Urho.Vector3 point)
		{
			Runtime.ValidateObject (this);
			return Sphere_IsInside (handle, ref point);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Intersection Sphere_IsInside16 (IntPtr handle, IntPtr sphere);

		/// <summary>
		/// Test if another sphere is inside, outside or intersects.
		/// </summary>
		public Intersection IsInside (Sphere sphere)
		{
			Runtime.ValidateObject (this);
			return Sphere_IsInside16 (handle, (object)sphere == null ? IntPtr.Zero : sphere.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Intersection Sphere_IsInsideFast (IntPtr handle, IntPtr sphere);

		/// <summary>
		/// Test if another sphere is (partially) inside or outside.
		/// </summary>
		public Intersection IsInsideFast (Sphere sphere)
		{
			Runtime.ValidateObject (this);
			return Sphere_IsInsideFast (handle, (object)sphere == null ? IntPtr.Zero : sphere.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Intersection Sphere_IsInside17 (IntPtr handle, ref Urho.BoundingBox box);

		/// <summary>
		/// Test if a bounding box is inside, outside or intersects.
		/// </summary>
		public Intersection IsInside (Urho.BoundingBox box)
		{
			Runtime.ValidateObject (this);
			return Sphere_IsInside17 (handle, ref box);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Intersection Sphere_IsInsideFast18 (IntPtr handle, ref Urho.BoundingBox box);

		/// <summary>
		/// Test if a bounding box is (partially) inside or outside.
		/// </summary>
		public Intersection IsInsideFast (Urho.BoundingBox box)
		{
			Runtime.ValidateObject (this);
			return Sphere_IsInsideFast18 (handle, ref box);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Sphere_Distance (IntPtr handle, ref Urho.Vector3 point);

		/// <summary>
		/// Return distance of a point to the surface, or 0 if inside.
		/// </summary>
		public float Distance (Urho.Vector3 point)
		{
			Runtime.ValidateObject (this);
			return Sphere_Distance (handle, ref point);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 Sphere_GetLocalPoint (IntPtr handle, float theta, float phi);

		/// <summary>
		/// Return point on the sphere relative to sphere position.
		/// </summary>
		public Vector3 GetLocalPoint (float theta, float phi)
		{
			Runtime.ValidateObject (this);
			return 
#if __WEB__
*Sphere_GetLocalPoint
#else
Sphere_GetLocalPoint
#endif
 (handle, theta, phi);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 Sphere_GetPoint (IntPtr handle, float theta, float phi);

		/// <summary>
		/// Return point on the sphere.
		/// </summary>
		public Vector3 GetPoint (float theta, float phi)
		{
			Runtime.ValidateObject (this);
			return 
#if __WEB__
*Sphere_GetPoint
#else
Sphere_GetPoint
#endif
 (handle, theta, phi);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 Sphere_GetCenter (IntPtr handle);

		/// <summary>
		/// Return center of the sphere.
		/// </summary>
		private Vector3 GetCenter ()
		{
			Runtime.ValidateObject (this);
			return 
#if __WEB__
*Sphere_GetCenter
#else
Sphere_GetCenter
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Sphere_GetRadius (IntPtr handle);

		/// <summary>
		/// Return radius of the sphere.
		/// </summary>
		private float GetRadius ()
		{
			Runtime.ValidateObject (this);
			return Sphere_GetRadius (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sphere_SetRadius (IntPtr handle, float radius);

		/// <summary>
		/// Set radius of the sphere.
		/// </summary>
		private void SetRadius (float radius)
		{
			Runtime.ValidateObject (this);
			Sphere_SetRadius (handle, radius);
		}

		/// <summary>
		/// Return center of the sphere.
		/// </summary>
		public Vector3 Center {
			get {
				return GetCenter ();
			}
		}

		/// <summary>
		/// Return radius of the sphere.
		/// Or
		/// Set radius of the sphere.
		/// </summary>
		public float Radius {
			get {
				return GetRadius ();
			}
			set {
				SetRadius (value);
			}
		}
	}
}
