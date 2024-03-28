// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// IKSolver.cs
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
	/// 
	/// </summary>
	public unsafe partial class IKSolver : Component
	{
		unsafe partial void OnIKSolverCreated ();

		[Preserve]
		public IKSolver (IntPtr handle) : base (handle)
		{
			OnIKSolverCreated ();
		}

		[Preserve]
		protected IKSolver (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnIKSolverCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int IKSolver_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (IKSolver_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKSolver_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (IKSolver_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int IKSolver_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(IKSolver));
			return new StringHash (IKSolver_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKSolver_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(IKSolver));
			return Marshal.PtrToStringAnsi (IKSolver_GetTypeNameStatic ());
		}

		[Preserve]
		public IKSolver () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKSolver_IKSolver (IntPtr context);

		[Preserve]
		public IKSolver (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(IKSolver));
			handle = IKSolver_IKSolver ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnIKSolverCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_RegisterObject (IntPtr context);

		/// <summary>
		/// Registers this class to the context.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(IKSolver));
			IKSolver_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IKSolverAlgorithm IKSolver_GetAlgorithm (IntPtr handle);

		/// <summary>
		/// Returns the active algorithm.
		/// 
		/// </summary>
		private IKSolverAlgorithm GetAlgorithm ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetAlgorithm (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetAlgorithm (IntPtr handle, IKSolverAlgorithm algorithm);

		/// <summary>
		/// 
		/// 
		/// Selects the solver algorithm. Default is FABRIK. Note that this
		/// may not be the most efficient algorithm available. The specialized
		/// solvers will be a lot faster.
		/// The currently supported solvers are listed below.
		/// + **FABRIK**: This is a fairly new and highly efficient inverse
		/// kinematic solving algorithm. It requires the least iterations to
		/// reach its goal, it does not suffer from singularities (nearly no
		/// violent snapping about), and it always converges.
		/// + **2 Bone**: A specialized solver optimized for 2 bone problems (such
		/// as a human leg)
		/// + **1 Bone**: A specialized solver optimized for 1 bone problems (such
		/// as a look-at target, e.g. eyes or a head)
		/// </summary>
		private void SetAlgorithm (IKSolverAlgorithm algorithm)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetAlgorithm (handle, algorithm);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFeature (IntPtr handle, IKSolverFeature feature);

		/// <summary>
		/// Test if a certain feature is enabled (see IKSolver::IKSolverFeature).
		/// 
		/// </summary>
		public bool GetFeature (IKSolverFeature feature)
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFeature (handle, feature);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFeature (IntPtr handle, IKSolverFeature feature, bool enable);

		/// <summary>
		/// Enable or disable a certain feature (see IKSolver::IKSolverFeature).
		/// 
		/// </summary>
		public void SetFeature (IKSolverFeature feature, bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFeature (handle, feature, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint IKSolver_GetMaximumIterations (IntPtr handle);

		/// <summary>
		/// Returns the configured maximum number of iterations.
		/// 
		/// </summary>
		private uint GetMaximumIterations ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetMaximumIterations (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetMaximumIterations (IntPtr handle, uint iterations);

		/// <summary>
		/// 
		/// 
		/// Sets the maximum number of iterations the solver is allowed to
		/// perform before applying the result.
		/// Depending on the algorithm, you may want higher or lower values.
		/// FABRIK looks decent after only 10 iterations, whereas Jacobian based
		/// methods often require more than a 100.
		/// The default value is 20.
		/// 
		/// Most algorithms have a convergence criteria at which the solver
		/// will stop iterating, so most of the time the maximum number of
		/// iterations isn't even reached.
		/// 
		/// Number of iterations. Must be greater than 0. Higher
		/// values yield more accurate results, but at the cost of performance.
		/// </summary>
		private void SetMaximumIterations (uint iterations)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetMaximumIterations (handle, iterations);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float IKSolver_GetTolerance (IntPtr handle);

		/// <summary>
		/// Returns the configured tolerance.
		/// 
		/// </summary>
		private float GetTolerance ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetTolerance (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetTolerance (IntPtr handle, float tolerance);

		/// <summary>
		/// 
		/// 
		/// Sets the distance at which the effector is "close enough" to the
		/// target node, at which point the algorithm will stop iterating.
		/// 
		/// The distance to set. Smaller values yield more accurate
		/// results, but at the cost of more iterations. Generally you'll want to
		/// specify a number that is about 1/100th to 1/1000th of the total size of
		/// the IK chain, e.g. if your human character has a leg that is 1 Urho3D
		/// unit long, a good starting tolerance would be 0.01.
		/// </summary>
		private void SetTolerance (float tolerance)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetTolerance (handle, tolerance);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_RebuildChainTrees (IntPtr handle);

		/// <summary>
		/// 
		/// Updates the solver's internal data structures, which is required
		/// whenever the tree is modified in any way (e.g. adding or removing nodes,
		/// adding or removing effectors, etc.).
		/// 
		/// This gets called  automatically for you in Solve().
		/// </summary>
		public void RebuildChainTrees ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_RebuildChainTrees (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_RecalculateSegmentLengths (IntPtr handle);

		/// <summary>
		/// 
		/// Unusual, but if you have a tree with translational motions such
		/// that the distances between nodes changes (perhaps a slider?), you can
		/// call this to recalculate the segment lengths after assigning new
		/// positions to the nodes.
		/// 
		/// This function gets called by RebuildData() and by extension in
		/// Solve().
		/// </summary>
		public void RecalculateSegmentLengths ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_RecalculateSegmentLengths (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_CalculateJointRotations (IntPtr handle);

		/// <summary>
		/// 
		/// Skinned models require joint rotations to be calculated so
		/// skinning works correctly. This is automatically enabled by default with
		/// the feature flag JOINT_ROTATIONS.
		/// </summary>
		public void CalculateJointRotations ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_CalculateJointRotations (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_Solve (IntPtr handle);

		/// <summary>
		/// 
		/// Invokes the solver. The solution is applied back to the scene
		/// graph automatically.
		/// 
		/// By default this is called automatically for you if the feature
		/// flag AUTO_SOLVE is set. For more complex IK problems you can disable
		/// that flag and call Solve() in response to E_SCENEDRAWABLEUPDATEFINISHED.
		/// This is right after the animations have been applied.
		/// </summary>
		public void Solve ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_Solve (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_ApplyOriginalPoseToScene (IntPtr handle);

		/// <summary>
		/// Copies the original pose into the scene graph. This will reset the pose
		/// to whatever state it had when the IKSolver component was first created,
		/// or, if the original pose was updated since then (for example if
		/// IKSolverFeature::UPDATE_ORIGINAL_POSE is set), will reset it to that state.
		/// </summary>
		public void ApplyOriginalPoseToScene ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_ApplyOriginalPoseToScene (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_ApplySceneToOriginalPose (IntPtr handle);

		/// <summary>
		/// Copies the current scene graph data into the solvers original pose. You
		/// generally won't need to call this, because it gets called for you
		/// automatically if IKSolverFeature::UPDATE_ORIGINAL_POSE is set.
		/// </summary>
		public void ApplySceneToOriginalPose ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_ApplySceneToOriginalPose (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_ApplyActivePoseToScene (IntPtr handle);

		/// <summary>
		/// Copies the solvers current active pose into the scene graph. You
		/// generally won't need to call this because it gets called for you
		/// automatically in Solve(). This is used to apply the solution back to the
		/// scene graph.
		/// </summary>
		public void ApplyActivePoseToScene ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_ApplyActivePoseToScene (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_ApplySceneToActivePose (IntPtr handle);

		/// <summary>
		/// Copies the current scene graph data into the solvers active pose. You
		/// generally won't need to call this because it gets called for you
		/// automatically if IKSolverFeature::UPDATE_ACTIVE_POSE is set.
		/// </summary>
		public void ApplySceneToActivePose ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_ApplySceneToActivePose (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_ApplyOriginalPoseToActivePose (IntPtr handle);

		/// <summary>
		/// Copies the solvers original pose into the solvers active pose. This is
		/// used in Solve() automatically if IKSolverFeature::USE_ORIGINAL_POSE is set.
		/// </summary>
		public void ApplyOriginalPoseToActivePose ()
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_ApplyOriginalPoseToActivePose (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_DrawDebugGeometry (IntPtr handle, bool depthTest);

		public void DrawDebugGeometry (bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_DrawDebugGeometry (handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_DrawDebugGeometry0 (IntPtr handle, IntPtr debug, bool depthTest);

		public override void DrawDebugGeometry (DebugRenderer debug, bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_DrawDebugGeometry0 (handle, (object)debug == null ? IntPtr.Zero : debug.Handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_JOINT_ROTATIONS (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_JOINT_ROTATIONS ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_JOINT_ROTATIONS (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_TARGET_ROTATIONS (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_TARGET_ROTATIONS ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_TARGET_ROTATIONS (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_UPDATE_ORIGINAL_POSE (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_UPDATE_ORIGINAL_POSE ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_UPDATE_ORIGINAL_POSE (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_UPDATE_ACTIVE_POSE (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_UPDATE_ACTIVE_POSE ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_UPDATE_ACTIVE_POSE (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_USE_ORIGINAL_POSE (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_USE_ORIGINAL_POSE ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_USE_ORIGINAL_POSE (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_CONSTRAINTS (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_CONSTRAINTS ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_CONSTRAINTS (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKSolver_GetFEATURE_AUTO_SOLVE (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		private bool GetFEATURE_AUTO_SOLVE ()
		{
			Runtime.ValidateRefCounted (this);
			return IKSolver_GetFEATURE_AUTO_SOLVE (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_JOINT_ROTATIONS (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_JOINT_ROTATIONS (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_JOINT_ROTATIONS (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_TARGET_ROTATIONS (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_TARGET_ROTATIONS (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_TARGET_ROTATIONS (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_UPDATE_ORIGINAL_POSE (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_UPDATE_ORIGINAL_POSE (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_UPDATE_ORIGINAL_POSE (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_UPDATE_ACTIVE_POSE (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_UPDATE_ACTIVE_POSE (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_UPDATE_ACTIVE_POSE (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_USE_ORIGINAL_POSE (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_USE_ORIGINAL_POSE (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_USE_ORIGINAL_POSE (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_CONSTRAINTS (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_CONSTRAINTS (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_CONSTRAINTS (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKSolver_SetFEATURE_AUTO_SOLVE (IntPtr handle, bool enable);

		/// <summary>
		/// 
		/// </summary>
		private void SetFEATURE_AUTO_SOLVE (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKSolver_SetFEATURE_AUTO_SOLVE (handle, enable);
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
		/// Returns the active algorithm.
		/// 
		/// Or
		/// 
		/// 
		/// Selects the solver algorithm. Default is FABRIK. Note that this
		/// may not be the most efficient algorithm available. The specialized
		/// solvers will be a lot faster.
		/// The currently supported solvers are listed below.
		/// + **FABRIK**: This is a fairly new and highly efficient inverse
		/// kinematic solving algorithm. It requires the least iterations to
		/// reach its goal, it does not suffer from singularities (nearly no
		/// violent snapping about), and it always converges.
		/// + **2 Bone**: A specialized solver optimized for 2 bone problems (such
		/// as a human leg)
		/// + **1 Bone**: A specialized solver optimized for 1 bone problems (such
		/// as a look-at target, e.g. eyes or a head)
		/// </summary>
		public IKSolverAlgorithm Algorithm {
			get {
				return GetAlgorithm ();
			}
			set {
				SetAlgorithm (value);
			}
		}

		/// <summary>
		/// Returns the configured maximum number of iterations.
		/// 
		/// Or
		/// 
		/// 
		/// Sets the maximum number of iterations the solver is allowed to
		/// perform before applying the result.
		/// Depending on the algorithm, you may want higher or lower values.
		/// FABRIK looks decent after only 10 iterations, whereas Jacobian based
		/// methods often require more than a 100.
		/// The default value is 20.
		/// 
		/// Most algorithms have a convergence criteria at which the solver
		/// will stop iterating, so most of the time the maximum number of
		/// iterations isn't even reached.
		/// 
		/// Number of iterations. Must be greater than 0. Higher
		/// values yield more accurate results, but at the cost of performance.
		/// </summary>
		public uint MaximumIterations {
			get {
				return GetMaximumIterations ();
			}
			set {
				SetMaximumIterations (value);
			}
		}

		/// <summary>
		/// Returns the configured tolerance.
		/// 
		/// Or
		/// 
		/// 
		/// Sets the distance at which the effector is "close enough" to the
		/// target node, at which point the algorithm will stop iterating.
		/// 
		/// The distance to set. Smaller values yield more accurate
		/// results, but at the cost of more iterations. Generally you'll want to
		/// specify a number that is about 1/100th to 1/1000th of the total size of
		/// the IK chain, e.g. if your human character has a leg that is 1 Urho3D
		/// unit long, a good starting tolerance would be 0.01.
		/// </summary>
		public float Tolerance {
			get {
				return GetTolerance ();
			}
			set {
				SetTolerance (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_JOINT_ROTATIONS {
			get {
				return GetFEATURE_JOINT_ROTATIONS ();
			}
			set {
				SetFEATURE_JOINT_ROTATIONS (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_TARGET_ROTATIONS {
			get {
				return GetFEATURE_TARGET_ROTATIONS ();
			}
			set {
				SetFEATURE_TARGET_ROTATIONS (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_UPDATE_ORIGINAL_POSE {
			get {
				return GetFEATURE_UPDATE_ORIGINAL_POSE ();
			}
			set {
				SetFEATURE_UPDATE_ORIGINAL_POSE (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_UPDATE_ACTIVE_POSE {
			get {
				return GetFEATURE_UPDATE_ACTIVE_POSE ();
			}
			set {
				SetFEATURE_UPDATE_ACTIVE_POSE (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_USE_ORIGINAL_POSE {
			get {
				return GetFEATURE_USE_ORIGINAL_POSE ();
			}
			set {
				SetFEATURE_USE_ORIGINAL_POSE (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_CONSTRAINTS {
			get {
				return GetFEATURE_CONSTRAINTS ();
			}
			set {
				SetFEATURE_CONSTRAINTS (value);
			}
		}

		/// <summary>
		/// 
		/// Or
		/// 
		/// </summary>
		public bool FEATURE_AUTO_SOLVE {
			get {
				return GetFEATURE_AUTO_SOLVE ();
			}
			set {
				SetFEATURE_AUTO_SOLVE (value);
			}
		}
	}
}
