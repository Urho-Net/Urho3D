// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// CollisionChain2D.cs
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

namespace Urho.Urho2D
{
	/// <summary>
	/// 2D chain collision component.
	/// </summary>
	public unsafe partial class CollisionChain2D : CollisionShape2D
	{
		unsafe partial void OnCollisionChain2DCreated ();

		[Preserve]
		public CollisionChain2D (IntPtr handle) : base (handle)
		{
			OnCollisionChain2DCreated ();
		}

		[Preserve]
		protected CollisionChain2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnCollisionChain2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionChain2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (CollisionChain2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CollisionChain2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (CollisionChain2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int CollisionChain2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(CollisionChain2D));
			return new StringHash (CollisionChain2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CollisionChain2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(CollisionChain2D));
			return Marshal.PtrToStringAnsi (CollisionChain2D_GetTypeNameStatic ());
		}

		[Preserve]
		public CollisionChain2D () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr CollisionChain2D_CollisionChain2D (IntPtr context);

		[Preserve]
		public CollisionChain2D (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(CollisionChain2D));
			handle = CollisionChain2D_CollisionChain2D ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnCollisionChain2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionChain2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(CollisionChain2D));
			CollisionChain2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionChain2D_SetLoop (IntPtr handle, bool loop);

		/// <summary>
		/// Set loop.
		/// 
		/// </summary>
		private void SetLoop (bool loop)
		{
			Runtime.ValidateRefCounted (this);
			CollisionChain2D_SetLoop (handle, loop);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionChain2D_SetVertexCount (IntPtr handle, uint count);

		/// <summary>
		/// Set vertex count.
		/// 
		/// </summary>
		private void SetVertexCount (uint count)
		{
			Runtime.ValidateRefCounted (this);
			CollisionChain2D_SetVertexCount (handle, count);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void CollisionChain2D_SetVertex (IntPtr handle, uint index, ref Urho.Vector2 vertex);

		/// <summary>
		/// Set vertex.
		/// </summary>
		public void SetVertex (uint index, Urho.Vector2 vertex)
		{
			Runtime.ValidateRefCounted (this);
			CollisionChain2D_SetVertex (handle, index, ref vertex);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool CollisionChain2D_GetLoop (IntPtr handle);

		/// <summary>
		/// Return loop.
		/// 
		/// </summary>
		private bool GetLoop ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionChain2D_GetLoop (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint CollisionChain2D_GetVertexCount (IntPtr handle);

		/// <summary>
		/// Return vertex count.
		/// 
		/// </summary>
		private uint GetVertexCount ()
		{
			Runtime.ValidateRefCounted (this);
			return CollisionChain2D_GetVertexCount (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern 
#if __WEB__
Urho.Vector2 *
#else
Urho.Vector2
#endif
 CollisionChain2D_GetVertex (IntPtr handle, uint index);

		/// <summary>
		/// Return vertex.
		/// </summary>
		public Urho.Vector2 GetVertex (uint index)
		{
			Runtime.ValidateRefCounted (this);
			return 
#if __WEB__
*CollisionChain2D_GetVertex
#else
CollisionChain2D_GetVertex
#endif
 (handle, index);
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
		/// Return loop.
		/// 
		/// Or
		/// Set loop.
		/// 
		/// </summary>
		public bool Loop {
			get {
				return GetLoop ();
			}
			set {
				SetLoop (value);
			}
		}

		/// <summary>
		/// Return vertex count.
		/// 
		/// Or
		/// Set vertex count.
		/// 
		/// </summary>
		public uint VertexCount {
			get {
				return GetVertexCount ();
			}
			set {
				SetVertexCount (value);
			}
		}
	}
}
