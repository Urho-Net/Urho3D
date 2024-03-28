// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Drawable2D.cs
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
	/// Base class for 2D visible components.
	/// </summary>
	public unsafe partial class Drawable2D : Drawable
	{
		unsafe partial void OnDrawable2DCreated ();

		[Preserve]
		public Drawable2D (IntPtr handle) : base (handle)
		{
			OnDrawable2DCreated ();
		}

		[Preserve]
		protected Drawable2D (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnDrawable2DCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Drawable2D_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Drawable2D_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable2D_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Drawable2D_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Drawable2D_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Drawable2D));
			return new StringHash (Drawable2D_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Drawable2D_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Drawable2D));
			return Marshal.PtrToStringAnsi (Drawable2D_GetTypeNameStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory. Drawable must be registered first.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Drawable2D));
			Drawable2D_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_OnSetEnabled (IntPtr handle);

		/// <summary>
		/// Handle enabled/disabled state change.
		/// </summary>
		public override void OnSetEnabled ()
		{
			Runtime.ValidateRefCounted (this);
			Drawable2D_OnSetEnabled (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_SetLayer (IntPtr handle, int layer);

		/// <summary>
		/// Set layer.
		/// 
		/// </summary>
		private void SetLayer (int layer)
		{
			Runtime.ValidateRefCounted (this);
			Drawable2D_SetLayer (handle, layer);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_SetOrderInLayer (IntPtr handle, int orderInLayer);

		/// <summary>
		/// Set order in layer.
		/// 
		/// </summary>
		private void SetOrderInLayer (int orderInLayer)
		{
			Runtime.ValidateRefCounted (this);
			Drawable2D_SetOrderInLayer (handle, orderInLayer);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Drawable2D_GetLayer (IntPtr handle);

		/// <summary>
		/// Return layer.
		/// 
		/// </summary>
		private int GetLayer ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable2D_GetLayer (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Drawable2D_GetOrderInLayer (IntPtr handle);

		/// <summary>
		/// Return order in layer.
		/// 
		/// </summary>
		private int GetOrderInLayer ()
		{
			Runtime.ValidateRefCounted (this);
			return Drawable2D_GetOrderInLayer (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_SetSourceBatches (IntPtr handle, Vertex2D* ptr, int count);

		public void SetSourceBatches (Vertex2D* ptr, int count)
		{
			Runtime.ValidateRefCounted (this);
			Drawable2D_SetSourceBatches (handle, ptr, count);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_SetSourceBatchesDirty (IntPtr handle);

		/// <summary>
		/// 
		/// </summary>
		public void SetSourceBatchesDirty ()
		{
			Runtime.ValidateRefCounted (this);
			Drawable2D_SetSourceBatchesDirty (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Drawable2D_SetMonoUpdateSourceBatches (IntPtr handle, bool val);

		public void SetMonoUpdateSourceBatches (bool val)
		{
			Runtime.ValidateRefCounted (this);
			Drawable2D_SetMonoUpdateSourceBatches (handle, val);
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
		/// Return layer.
		/// 
		/// Or
		/// Set layer.
		/// 
		/// </summary>
		public int Layer {
			get {
				return GetLayer ();
			}
			set {
				SetLayer (value);
			}
		}

		/// <summary>
		/// Return order in layer.
		/// 
		/// Or
		/// Set order in layer.
		/// 
		/// </summary>
		public int OrderInLayer {
			get {
				return GetOrderInLayer ();
			}
			set {
				SetOrderInLayer (value);
			}
		}
	}
}
