// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// StaticModelGroup.cs
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
	/// Renders several object instances while culling and receiving light as one unit. Can be used as a CPU-side optimization, but note that also regular StaticModels will use instanced rendering if possible.
	/// </summary>
	public unsafe partial class StaticModelGroup : StaticModel
	{
		unsafe partial void OnStaticModelGroupCreated ();

		[Preserve]
		public StaticModelGroup (IntPtr handle) : base (handle)
		{
			OnStaticModelGroupCreated ();
		}

		[Preserve]
		protected StaticModelGroup (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnStaticModelGroupCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int StaticModelGroup_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (StaticModelGroup_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr StaticModelGroup_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (StaticModelGroup_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int StaticModelGroup_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(StaticModelGroup));
			return new StringHash (StaticModelGroup_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr StaticModelGroup_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(StaticModelGroup));
			return Marshal.PtrToStringAnsi (StaticModelGroup_GetTypeNameStatic ());
		}

		[Preserve]
		public StaticModelGroup () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr StaticModelGroup_StaticModelGroup (IntPtr context);

		[Preserve]
		public StaticModelGroup (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(StaticModelGroup));
			handle = StaticModelGroup_StaticModelGroup ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnStaticModelGroupCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void StaticModelGroup_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory. StaticModel must be registered first.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(StaticModelGroup));
			StaticModelGroup_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void StaticModelGroup_ApplyAttributes (IntPtr handle);

		/// <summary>
		/// Apply attribute changes that can not be applied immediately. Called after scene load or a network update.
		/// </summary>
		public override void ApplyAttributes ()
		{
			Runtime.ValidateRefCounted (this);
			StaticModelGroup_ApplyAttributes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint StaticModelGroup_GetNumOccluderTriangles (IntPtr handle);

		/// <summary>
		/// Return number of occlusion geometry triangles.
		/// </summary>
		private uint GetNumOccluderTriangles ()
		{
			Runtime.ValidateRefCounted (this);
			return StaticModelGroup_GetNumOccluderTriangles (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool StaticModelGroup_DrawOcclusion (IntPtr handle, IntPtr buffer);

		/// <summary>
		/// Draw to occlusion buffer. Return true if did not run out of triangles.
		/// </summary>
		public override bool DrawOcclusion (OcclusionBuffer buffer)
		{
			Runtime.ValidateRefCounted (this);
			return StaticModelGroup_DrawOcclusion (handle, (object)buffer == null ? IntPtr.Zero : buffer.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void StaticModelGroup_AddInstanceNode (IntPtr handle, IntPtr node);

		/// <summary>
		/// Add an instance scene node. It does not need any drawable components of its own.
		/// </summary>
		public void AddInstanceNode (Node node)
		{
			Runtime.ValidateRefCounted (this);
			StaticModelGroup_AddInstanceNode (handle, (object)node == null ? IntPtr.Zero : node.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void StaticModelGroup_RemoveInstanceNode (IntPtr handle, IntPtr node);

		/// <summary>
		/// Remove an instance scene node.
		/// </summary>
		public void RemoveInstanceNode (Node node)
		{
			Runtime.ValidateRefCounted (this);
			StaticModelGroup_RemoveInstanceNode (handle, (object)node == null ? IntPtr.Zero : node.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void StaticModelGroup_RemoveAllInstanceNodes (IntPtr handle);

		/// <summary>
		/// Remove all instance scene nodes.
		/// </summary>
		public void RemoveAllInstanceNodes ()
		{
			Runtime.ValidateRefCounted (this);
			StaticModelGroup_RemoveAllInstanceNodes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint StaticModelGroup_GetNumInstanceNodes (IntPtr handle);

		/// <summary>
		/// Return number of instance nodes.
		/// 
		/// </summary>
		private uint GetNumInstanceNodes ()
		{
			Runtime.ValidateRefCounted (this);
			return StaticModelGroup_GetNumInstanceNodes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr StaticModelGroup_GetInstanceNode (IntPtr handle, uint index);

		/// <summary>
		/// Return instance node by index.
		/// 
		/// </summary>
		public Node GetInstanceNode (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Node> (StaticModelGroup_GetInstanceNode (handle, index));
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
		/// Return number of occlusion geometry triangles.
		/// </summary>
		public override uint NumOccluderTriangles {
			get {
				return GetNumOccluderTriangles ();
			}
		}

		/// <summary>
		/// Return number of instance nodes.
		/// 
		/// </summary>
		public uint NumInstanceNodes {
			get {
				return GetNumInstanceNodes ();
			}
		}
	}
}
