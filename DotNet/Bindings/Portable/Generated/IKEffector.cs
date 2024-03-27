// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// IKEffector.cs
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
	/// Constructs a new IK effector.
	/// </summary>
	public unsafe partial class IKEffector : Component
	{
		unsafe partial void OnIKEffectorCreated ();

		[Preserve]
		public IKEffector (IntPtr handle) : base (handle)
		{
			OnIKEffectorCreated ();
		}

		[Preserve]
		protected IKEffector (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnIKEffectorCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int IKEffector_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (IKEffector_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKEffector_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (IKEffector_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int IKEffector_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(IKEffector));
			return new StringHash (IKEffector_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKEffector_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(IKEffector));
			return Marshal.PtrToStringAnsi (IKEffector_GetTypeNameStatic ());
		}

		[Preserve]
		public IKEffector () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKEffector_IKEffector (IntPtr context);

		[Preserve]
		public IKEffector (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(IKEffector));
			handle = IKEffector_IKEffector ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnIKEffectorCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_RegisterObject (IntPtr context);

		/// <summary>
		/// Registers this class as an object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(IKEffector));
			IKEffector_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKEffector_GetFeature (IntPtr handle, IKEffectorFeature feature);

		/// <summary>
		/// Test if a certain feature is enabled (see IKEffector::IKEffectorFeature).
		/// 
		/// </summary>
		public bool GetFeature (IKEffectorFeature feature)
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetFeature (handle, feature);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetFeature (IntPtr handle, IKEffectorFeature feature, bool enable);

		/// <summary>
		/// Enable or disable a certain feature (see IKEffector::IKEffectorFeature).
		/// 
		/// </summary>
		public void SetFeature (IKEffectorFeature feature, bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetFeature (handle, feature, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKEffector_GetTargetNode (IntPtr handle);

		/// <summary>
		/// Retrieves the node that is being used as a target. Can be NULL.
		/// 
		/// </summary>
		private Node GetTargetNode ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Node> (IKEffector_GetTargetNode (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetTargetNode (IntPtr handle, IntPtr targetNode);

		/// <summary>
		/// 
		/// 
		/// The position of the target node provides the target position of
		/// the effector node.
		/// The IK chain is solved such that the node to which this component is
		/// attached to will try to move to the position of the target node.
		/// 
		/// A scene node that acts as a target. Specifying NULL
		/// will erase the target and cause the solver to ignore this chain.
		/// 
		/// You will get very strange behaviour if you specify a target node
		/// that is part the IK chain being solved for (circular dependency). Don't
		/// do that.
		/// </summary>
		private void SetTargetNode (Node targetNode)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetTargetNode (handle, (object)targetNode == null ? IntPtr.Zero : targetNode.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr IKEffector_GetTargetName (IntPtr handle);

		/// <summary>
		/// 
		/// 
		/// Retrieves the name of the target node. The node doesn't
		/// necessarily have to exist in the scene graph.
		/// </summary>
		private string GetTargetName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (IKEffector_GetTargetName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetTargetName (IntPtr handle, string nodeName);

		/// <summary>
		/// 
		/// 
		/// Sets the name of the target node. The node doesn't necessarily
		/// have to exist in the scene graph. When a node is created that matches
		/// this name, it is selected as the target.
		/// 
		/// This clears the existing target node.
		/// </summary>
		private void SetTargetName (string nodeName)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetTargetName (handle, nodeName);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector3 *
#else
Urho.Vector3
#endif
 IKEffector_GetTargetPosition (IntPtr handle);

		/// <summary>
		/// Returns the current target position in world space.
		/// 
		/// </summary>
		private Urho.Vector3 GetTargetPosition ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*IKEffector_GetTargetPosition
#else
IKEffector_GetTargetPosition
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetTargetPosition (IntPtr handle, ref Urho.Vector3 targetPosition);

		/// <summary>
		/// Sets the current target position. If the effector has a target node then this will have no effect.
		/// 
		/// </summary>
		private void SetTargetPosition (Urho.Vector3 targetPosition)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetTargetPosition (handle, ref targetPosition);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Quaternion *
#else
Urho.Quaternion
#endif
 IKEffector_GetTargetRotation (IntPtr handle);

		/// <summary>
		/// Gets the current target rotation in world space.
		/// 
		/// </summary>
		private Urho.Quaternion GetTargetRotation ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*IKEffector_GetTargetRotation
#else
IKEffector_GetTargetRotation
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetTargetRotation (IntPtr handle, ref Urho.Quaternion targetRotation);

		/// <summary>
		/// Sets the current target rotation. If the effector has a target node then this will have no effect.
		/// 
		/// </summary>
		private void SetTargetRotation (Urho.Quaternion targetRotation)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetTargetRotation (handle, ref targetRotation);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Vector3 *
#else
Vector3
#endif
 IKEffector_GetTargetRotationEuler (IntPtr handle);

		/// <summary>
		/// Required for the editor, get the target rotation in euler angles.
		/// </summary>
		private Vector3 GetTargetRotationEuler ()
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*IKEffector_GetTargetRotationEuler
#else
IKEffector_GetTargetRotationEuler
#endif
 (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetTargetRotationEuler (IntPtr handle, ref Urho.Vector3 targetRotation);

		/// <summary>
		/// Required for the editor, sets the target rotation in euler angles.
		/// </summary>
		public void SetTargetRotationEuler (Urho.Vector3 targetRotation)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetTargetRotationEuler (handle, ref targetRotation);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint IKEffector_GetChainLength (IntPtr handle);

		/// <summary>
		/// Returns the number of segments that will be affected by this effector. 0 Means all nodes between this effector
		/// and the next IKSolver.
		/// 
		/// </summary>
		private uint GetChainLength ()
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetChainLength (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetChainLength (IntPtr handle, uint chainLength);

		/// <summary>
		/// Sets the number of segments that will be affected. 0 Means all nodes between this effector and the next
		/// IKSolver.
		/// 
		/// </summary>
		private void SetChainLength (uint chainLength)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetChainLength (handle, chainLength);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float IKEffector_GetWeight (IntPtr handle);

		/// <summary>
		/// How strongly the effector affects the solution.
		/// 
		/// </summary>
		private float GetWeight ()
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetWeight (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetWeight (IntPtr handle, float weight);

		/// <summary>
		/// 
		/// 
		/// Sets how much influence the effector has on the solution.
		/// You can use this value to smoothly transition between a solved pose and
		/// an initial pose  For instance, lifting a foot off of the ground or
		/// letting go of an object.
		/// </summary>
		private void SetWeight (float weight)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetWeight (handle, weight);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float IKEffector_GetRotationWeight (IntPtr handle);

		/// <summary>
		/// How strongly the target node's rotation influences the solution.
		/// 
		/// </summary>
		private float GetRotationWeight ()
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetRotationWeight (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetRotationWeight (IntPtr handle, float weight);

		/// <summary>
		/// 
		/// 
		/// Sets how much influence the target rotation should have on the
		/// solution. A value of 1 means to match the target rotation exactly, if
		/// possible. A value of 0 means to not match it at all.
		/// 
		/// The solver must have target rotation enabled for this to have
		/// any effect. See IKSolver::IKEffectorFeature::TARGET_ROTATIONS.
		/// </summary>
		private void SetRotationWeight (float weight)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetRotationWeight (handle, weight);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float IKEffector_GetRotationDecay (IntPtr handle);

		/// <summary>
		/// Retrieves the rotation decay factor. See SetRotationDecay() for info.
		/// 
		/// </summary>
		private float GetRotationDecay ()
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetRotationDecay (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetRotationDecay (IntPtr handle, float decay);

		/// <summary>
		/// 
		/// 
		/// A factor with which to control the target rotation influence of
		/// the next segments down the chain.
		/// For example, if this is set to 0.5 and the rotation weight is set to
		/// 1.0, then the first segment will match the target rotation exactly, the
		/// next segment will match it only 50%, the next segment 25%, the next
		/// 12.5%, etc. This parameter makes long chains look more natural when
		/// matching a target rotation.
		/// </summary>
		private void SetRotationDecay (float decay)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetRotationDecay (handle, decay);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_DrawDebugGeometry (IntPtr handle, bool depthTest);

		public void DrawDebugGeometry (bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_DrawDebugGeometry (handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_DrawDebugGeometry0 (IntPtr handle, IntPtr debug, bool depthTest);

		public override void DrawDebugGeometry (DebugRenderer debug, bool depthTest)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_DrawDebugGeometry0 (handle, (object)debug == null ? IntPtr.Zero : debug.Handle, depthTest);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKEffector_GetFEATURE_WEIGHT_NLERP (IntPtr handle);

		/// <summary>
		/// Need these wrapper functions flags of GetFeature/SetFeature can be correctly exposed to the editor and to
		/// AngelScript and lua.
		/// </summary>
		private bool GetFEATURE_WEIGHT_NLERP ()
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetFEATURE_WEIGHT_NLERP (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool IKEffector_GetFEATURE_INHERIT_PARENT_ROTATION (IntPtr handle);

		private bool GetFEATURE_INHERIT_PARENT_ROTATION ()
		{
			Runtime.ValidateRefCounted (this);
			return IKEffector_GetFEATURE_INHERIT_PARENT_ROTATION (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetFEATURE_WEIGHT_NLERP (IntPtr handle, bool enable);

		private void SetFEATURE_WEIGHT_NLERP (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetFEATURE_WEIGHT_NLERP (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void IKEffector_SetFEATURE_INHERIT_PARENT_ROTATION (IntPtr handle, bool enable);

		private void SetFEATURE_INHERIT_PARENT_ROTATION (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			IKEffector_SetFEATURE_INHERIT_PARENT_ROTATION (handle, enable);
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
		/// Retrieves the node that is being used as a target. Can be NULL.
		/// 
		/// Or
		/// 
		/// 
		/// The position of the target node provides the target position of
		/// the effector node.
		/// The IK chain is solved such that the node to which this component is
		/// attached to will try to move to the position of the target node.
		/// 
		/// A scene node that acts as a target. Specifying NULL
		/// will erase the target and cause the solver to ignore this chain.
		/// 
		/// You will get very strange behaviour if you specify a target node
		/// that is part the IK chain being solved for (circular dependency). Don't
		/// do that.
		/// </summary>
		public Node TargetNode {
			get {
				return GetTargetNode ();
			}
			set {
				SetTargetNode (value);
			}
		}

		/// <summary>
		/// 
		/// 
		/// Retrieves the name of the target node. The node doesn't
		/// necessarily have to exist in the scene graph.
		/// Or
		/// 
		/// 
		/// Sets the name of the target node. The node doesn't necessarily
		/// have to exist in the scene graph. When a node is created that matches
		/// this name, it is selected as the target.
		/// 
		/// This clears the existing target node.
		/// </summary>
		public string TargetName {
			get {
				return GetTargetName ();
			}
			set {
				SetTargetName (value);
			}
		}

		/// <summary>
		/// Returns the current target position in world space.
		/// 
		/// Or
		/// Sets the current target position. If the effector has a target node then this will have no effect.
		/// 
		/// </summary>
		public Urho.Vector3 TargetPosition {
			get {
				return GetTargetPosition ();
			}
			set {
				SetTargetPosition (value);
			}
		}

		/// <summary>
		/// Gets the current target rotation in world space.
		/// 
		/// Or
		/// Sets the current target rotation. If the effector has a target node then this will have no effect.
		/// 
		/// </summary>
		public Urho.Quaternion TargetRotation {
			get {
				return GetTargetRotation ();
			}
			set {
				SetTargetRotation (value);
			}
		}

		/// <summary>
		/// Required for the editor, get the target rotation in euler angles.
		/// </summary>
		public Vector3 TargetRotationEuler {
			get {
				return GetTargetRotationEuler ();
			}
		}

		/// <summary>
		/// Returns the number of segments that will be affected by this effector. 0 Means all nodes between this effector
		/// and the next IKSolver.
		/// 
		/// Or
		/// Sets the number of segments that will be affected. 0 Means all nodes between this effector and the next
		/// IKSolver.
		/// 
		/// </summary>
		public uint ChainLength {
			get {
				return GetChainLength ();
			}
			set {
				SetChainLength (value);
			}
		}

		/// <summary>
		/// How strongly the effector affects the solution.
		/// 
		/// Or
		/// 
		/// 
		/// Sets how much influence the effector has on the solution.
		/// You can use this value to smoothly transition between a solved pose and
		/// an initial pose  For instance, lifting a foot off of the ground or
		/// letting go of an object.
		/// </summary>
		public float Weight {
			get {
				return GetWeight ();
			}
			set {
				SetWeight (value);
			}
		}

		/// <summary>
		/// How strongly the target node's rotation influences the solution.
		/// 
		/// Or
		/// 
		/// 
		/// Sets how much influence the target rotation should have on the
		/// solution. A value of 1 means to match the target rotation exactly, if
		/// possible. A value of 0 means to not match it at all.
		/// 
		/// The solver must have target rotation enabled for this to have
		/// any effect. See IKSolver::IKEffectorFeature::TARGET_ROTATIONS.
		/// </summary>
		public float RotationWeight {
			get {
				return GetRotationWeight ();
			}
			set {
				SetRotationWeight (value);
			}
		}

		/// <summary>
		/// Retrieves the rotation decay factor. See SetRotationDecay() for info.
		/// 
		/// Or
		/// 
		/// 
		/// A factor with which to control the target rotation influence of
		/// the next segments down the chain.
		/// For example, if this is set to 0.5 and the rotation weight is set to
		/// 1.0, then the first segment will match the target rotation exactly, the
		/// next segment will match it only 50%, the next segment 25%, the next
		/// 12.5%, etc. This parameter makes long chains look more natural when
		/// matching a target rotation.
		/// </summary>
		public float RotationDecay {
			get {
				return GetRotationDecay ();
			}
			set {
				SetRotationDecay (value);
			}
		}

		/// <summary>
		/// Need these wrapper functions flags of GetFeature/SetFeature can be correctly exposed to the editor and to
		/// AngelScript and lua.
		/// </summary>
		public bool FEATURE_WEIGHT_NLERP {
			get {
				return GetFEATURE_WEIGHT_NLERP ();
			}
			set {
				SetFEATURE_WEIGHT_NLERP (value);
			}
		}

		public bool FEATURE_INHERIT_PARENT_ROTATION {
			get {
				return GetFEATURE_INHERIT_PARENT_ROTATION ();
			}
			set {
				SetFEATURE_INHERIT_PARENT_ROTATION (value);
			}
		}
	}
}
