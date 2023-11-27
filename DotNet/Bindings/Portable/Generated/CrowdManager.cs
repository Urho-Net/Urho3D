// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// CrowdManager.cs
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

namespace Urho.Navigation
{
	/// <summary>
	/// Crowd manager scene component. Should be added only to the root scene node.
	/// </summary>
	public unsafe partial class CrowdManager : Component
	{
		unsafe partial void OnCrowdManagerCreated ();

		[Preserve]
		public CrowdManager (IntPtr handle) : base (handle)
		{
			OnCrowdManagerCreated ();
		}

		[Preserve]
		protected CrowdManager (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnCrowdManagerCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CrowdManager_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (CrowdManager_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CrowdManager_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (CrowdManager_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CrowdManager_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(CrowdManager));
			return new StringHash (CrowdManager_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CrowdManager_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(CrowdManager));
			return Marshal.PtrToStringAnsi (CrowdManager_GetTypeNameStatic ());
		}

		[Preserve]
		public CrowdManager () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CrowdManager_CrowdManager (IntPtr context);

		[Preserve]
		public CrowdManager (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(CrowdManager));
			handle = CrowdManager_CrowdManager ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnCrowdManagerCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(CrowdManager));
			CrowdManager_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_ApplyAttributes (IntPtr handle);

		/// <summary>
		/// Apply attribute changes that can not be applied immediately. Called after scene load or a network update.
		/// </summary>
		public override void ApplyAttributes ()
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_ApplyAttributes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_DrawDebugGeometry (IntPtr handle, IntPtr debug, bool depthTest);

		/// <summary>
		/// Draw the agents' pathing debug data.
		/// </summary>
		public override void DrawDebugGeometry (DebugRenderer debug, bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_DrawDebugGeometry (handle, (object)debug == null ? IntPtr.Zero : debug.Handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_DrawDebugGeometry0 (IntPtr handle, bool depthTest);

		/// <summary>
		/// Add debug geometry to the debug renderer.
		/// </summary>
		public void DrawDebugGeometry (bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_DrawDebugGeometry0 (handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetCrowdTarget (IntPtr handle, ref Urho.Vector3 position, IntPtr node);

		/// <summary>
		/// Set the crowd target position. The target position is set to all crowd agents found in the specified node. Defaulted to scene node.
		/// </summary>
		public void SetCrowdTarget (Urho.Vector3 position, Node node = null)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetCrowdTarget (handle, ref position, (object)node == null ? IntPtr.Zero : node.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetCrowdVelocity (IntPtr handle, ref Urho.Vector3 velocity, IntPtr node);

		/// <summary>
		/// Set the crowd move velocity. The move velocity is applied to all crowd agents found in the specified node. Defaulted to scene node.
		/// </summary>
		public void SetCrowdVelocity (Urho.Vector3 velocity, Node node = null)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetCrowdVelocity (handle, ref velocity, (object)node == null ? IntPtr.Zero : node.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_ResetCrowdTarget (IntPtr handle, IntPtr node);

		/// <summary>
		/// Reset any crowd target for all crowd agents found in the specified node. Defaulted to scene node.
		/// </summary>
		public void ResetCrowdTarget (Node node = null)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_ResetCrowdTarget (handle, (object)node == null ? IntPtr.Zero : node.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetMaxAgents (IntPtr handle, uint maxAgents);

		/// <summary>
		/// Set the maximum number of agents.
		/// 
		/// </summary>
		private void SetMaxAgents (uint maxAgents)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetMaxAgents (handle, maxAgents);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetMaxAgentRadius (IntPtr handle, float maxAgentRadius);

		/// <summary>
		/// Set the maximum radius of any agent.
		/// 
		/// </summary>
		private void SetMaxAgentRadius (float maxAgentRadius)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetMaxAgentRadius (handle, maxAgentRadius);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetNavigationMesh (IntPtr handle, IntPtr navMesh);

		/// <summary>
		/// Assigns the navigation mesh for the crowd.
		/// 
		/// </summary>
		private void SetNavigationMesh (NavigationMesh navMesh)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetNavigationMesh (handle, (object)navMesh == null ? IntPtr.Zero : navMesh.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetIncludeFlags (IntPtr handle, uint queryFilterType, ushort flags);

		/// <summary>
		/// Set the include flags for the specified query filter type.
		/// </summary>
		public void SetIncludeFlags (uint queryFilterType, ushort flags)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetIncludeFlags (handle, queryFilterType, flags);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetExcludeFlags (IntPtr handle, uint queryFilterType, ushort flags);

		/// <summary>
		/// Set the exclude flags for the specified query filter type.
		/// </summary>
		public void SetExcludeFlags (uint queryFilterType, ushort flags)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetExcludeFlags (handle, queryFilterType, flags);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetAreaCost (IntPtr handle, uint queryFilterType, uint areaID, float cost);

		/// <summary>
		/// Set the cost of an area for the specified query filter type.
		/// </summary>
		public void SetAreaCost (uint queryFilterType, uint areaID, float cost)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetAreaCost (handle, queryFilterType, areaID, cost);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CrowdManager_SetObstacleAvoidanceParams (IntPtr handle, uint obstacleAvoidanceType, ref CrowdObstacleAvoidanceParams @params);

		/// <summary>
		/// Set the params for the specified obstacle avoidance type.
		/// </summary>
		public void SetObstacleAvoidanceParams (uint obstacleAvoidanceType, CrowdObstacleAvoidanceParams @params)
		{
			Runtime.ValidateRefCounted (this);
			CrowdManager_SetObstacleAvoidanceParams (handle, obstacleAvoidanceType, ref @params);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 CrowdManager_FindNearestPoint (IntPtr handle, ref Urho.Vector3 point, int queryFilterType, uint* nearestRef);

		/// <summary>
		/// Find the nearest point on the navigation mesh to a given point using the crowd initialized query extent (based on maxAgentRadius) and the specified query filter type.
		/// </summary>
		public Vector3 FindNearestPoint (Urho.Vector3 point, int queryFilterType, uint* nearestRef = null)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CrowdManager_FindNearestPoint
#else
CrowdManager_FindNearestPoint
#endif
 (handle, ref point, queryFilterType, nearestRef);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 CrowdManager_MoveAlongSurface (IntPtr handle, ref Urho.Vector3 start, ref Urho.Vector3 end, int queryFilterType, int maxVisited);

		/// <summary>
		/// Try to move along the surface from one point to another using the crowd initialized query extent (based on maxAgentRadius) and the specified query filter type.
		/// </summary>
		public Vector3 MoveAlongSurface (Urho.Vector3 start, Urho.Vector3 end, int queryFilterType, int maxVisited = 3)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CrowdManager_MoveAlongSurface
#else
CrowdManager_MoveAlongSurface
#endif
 (handle, ref start, ref end, queryFilterType, maxVisited);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 CrowdManager_GetRandomPoint (IntPtr handle, int queryFilterType, uint* randomRef);

		/// <summary>
		/// Return a random point on the navigation mesh using the crowd initialized query extent (based on maxAgentRadius) and the specified query filter type.
		/// </summary>
		public Vector3 GetRandomPoint (int queryFilterType, uint* randomRef = null)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CrowdManager_GetRandomPoint
#else
CrowdManager_GetRandomPoint
#endif
 (handle, queryFilterType, randomRef);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 CrowdManager_GetRandomPointInCircle (IntPtr handle, ref Urho.Vector3 center, float radius, int queryFilterType, uint* randomRef);

		/// <summary>
		/// Return a random point on the navigation mesh within a circle using the crowd initialized query extent (based on maxAgentRadius) and the specified query filter type. The circle radius is only a guideline and in practice the returned point may be further away.
		/// </summary>
		public Vector3 GetRandomPointInCircle (Urho.Vector3 center, float radius, int queryFilterType, uint* randomRef = null)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CrowdManager_GetRandomPointInCircle
#else
CrowdManager_GetRandomPointInCircle
#endif
 (handle, ref center, radius, queryFilterType, randomRef);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CrowdManager_GetDistanceToWall (IntPtr handle, ref Urho.Vector3 point, float radius, int queryFilterType, Vector3* hitPos, Vector3* hitNormal);

		/// <summary>
		/// Return distance to wall from a point using the crowd initialized query extent (based on maxAgentRadius) and the specified query filter type. Maximum search radius must be specified.
		/// </summary>
		public float GetDistanceToWall (Urho.Vector3 point, float radius, int queryFilterType, Vector3* hitPos = null, Vector3* hitNormal = null)
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetDistanceToWall (handle, ref point, radius, queryFilterType, hitPos, hitNormal);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 CrowdManager_Raycast (IntPtr handle, ref Urho.Vector3 start, ref Urho.Vector3 end, int queryFilterType, Vector3* hitNormal);

		/// <summary>
		/// Perform a walkability raycast on the navigation mesh between start and end using the crowd initialized query extent (based on maxAgentRadius) and the specified query filter type. Return the point where a wall was hit, or the end point if no walls.
		/// </summary>
		public Vector3 Raycast (Urho.Vector3 start, Urho.Vector3 end, int queryFilterType, Vector3* hitNormal = null)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CrowdManager_Raycast
#else
CrowdManager_Raycast
#endif
 (handle, ref start, ref end, queryFilterType, hitNormal);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint CrowdManager_GetMaxAgents (IntPtr handle);

		/// <summary>
		/// Get the maximum number of agents.
		/// 
		/// </summary>
		private uint GetMaxAgents ()
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetMaxAgents (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CrowdManager_GetMaxAgentRadius (IntPtr handle);

		/// <summary>
		/// Get the maximum radius of any agent.
		/// 
		/// </summary>
		private float GetMaxAgentRadius ()
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetMaxAgentRadius (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CrowdManager_GetNavigationMesh (IntPtr handle);

		/// <summary>
		/// Get the Navigation mesh assigned to the crowd.
		/// 
		/// </summary>
		private NavigationMesh GetNavigationMesh ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<NavigationMesh> (CrowdManager_GetNavigationMesh (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint CrowdManager_GetNumQueryFilterTypes (IntPtr handle);

		/// <summary>
		/// Get the number of configured query filter types.
		/// 
		/// </summary>
		private uint GetNumQueryFilterTypes ()
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetNumQueryFilterTypes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint CrowdManager_GetNumAreas (IntPtr handle, uint queryFilterType);

		/// <summary>
		/// Get the number of configured area in the specified query filter type.
		/// 
		/// </summary>
		public uint GetNumAreas (uint queryFilterType)
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetNumAreas (handle, queryFilterType);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ushort CrowdManager_GetIncludeFlags (IntPtr handle, uint queryFilterType);

		/// <summary>
		/// Get the include flags for the specified query filter type.
		/// </summary>
		public ushort GetIncludeFlags (uint queryFilterType)
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetIncludeFlags (handle, queryFilterType);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ushort CrowdManager_GetExcludeFlags (IntPtr handle, uint queryFilterType);

		/// <summary>
		/// Get the exclude flags for the specified query filter type.
		/// </summary>
		public ushort GetExcludeFlags (uint queryFilterType)
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetExcludeFlags (handle, queryFilterType);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float CrowdManager_GetAreaCost (IntPtr handle, uint queryFilterType, uint areaID);

		/// <summary>
		/// Get the cost of an area for the specified query filter type.
		/// </summary>
		public float GetAreaCost (uint queryFilterType, uint areaID)
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetAreaCost (handle, queryFilterType, areaID);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint CrowdManager_GetNumObstacleAvoidanceTypes (IntPtr handle);

		/// <summary>
		/// Get the number of configured obstacle avoidance types.
		/// 
		/// </summary>
		private uint GetNumObstacleAvoidanceTypes ()
		{
			Runtime.ValidateRefCounted (this);
			return CrowdManager_GetNumObstacleAvoidanceTypes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
CrowdObstacleAvoidanceParams *
#else
CrowdObstacleAvoidanceParams
#endif
 CrowdManager_GetObstacleAvoidanceParams (IntPtr handle, uint obstacleAvoidanceType);

		/// <summary>
		/// Get the params for the specified obstacle avoidance type.
		/// </summary>
		public CrowdObstacleAvoidanceParams GetObstacleAvoidanceParams (uint obstacleAvoidanceType)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CrowdManager_GetObstacleAvoidanceParams
#else
CrowdManager_GetObstacleAvoidanceParams
#endif
 (handle, obstacleAvoidanceType);
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
		/// Get the maximum number of agents.
		/// 
		/// Or
		/// Set the maximum number of agents.
		/// 
		/// </summary>
		public uint MaxAgents {
			get {
				return GetMaxAgents ();
			}
			set {
				SetMaxAgents (value);
			}
		}

		/// <summary>
		/// Get the maximum radius of any agent.
		/// 
		/// Or
		/// Set the maximum radius of any agent.
		/// 
		/// </summary>
		public float MaxAgentRadius {
			get {
				return GetMaxAgentRadius ();
			}
			set {
				SetMaxAgentRadius (value);
			}
		}

		/// <summary>
		/// Get the Navigation mesh assigned to the crowd.
		/// 
		/// Or
		/// Assigns the navigation mesh for the crowd.
		/// 
		/// </summary>
		public NavigationMesh NavigationMesh {
			get {
				return GetNavigationMesh ();
			}
			set {
				SetNavigationMesh (value);
			}
		}

		/// <summary>
		/// Get the number of configured query filter types.
		/// 
		/// </summary>
		public uint NumQueryFilterTypes {
			get {
				return GetNumQueryFilterTypes ();
			}
		}

		/// <summary>
		/// Get the number of configured obstacle avoidance types.
		/// 
		/// </summary>
		public uint NumObstacleAvoidanceTypes {
			get {
				return GetNumObstacleAvoidanceTypes ();
			}
		}
	}
}
