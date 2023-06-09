// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Spline.cs
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
	/// Spline class to get a point on it based off the interpolation mode.
	/// </summary>
	public unsafe partial class Spline
	{
		private IntPtr handle;

		public IntPtr Handle {
			get {
				return handle;
			}
		}

		unsafe partial void OnSplineCreated ();

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Spline_Spline ();

		[Preserve]
		public Spline ()
		{
			Runtime.Validate (typeof(Spline));
			handle = Spline_Spline ();
			OnSplineCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Spline_Spline0 (InterpolationMode mode);

		[Preserve]
		public Spline (InterpolationMode mode)
		{
			Runtime.Validate (typeof(Spline));
			handle = Spline_Spline0 (mode);
			OnSplineCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern InterpolationMode Spline_GetInterpolationMode (IntPtr handle);

		/// <summary>
		/// Return the interpolation mode.
		/// 
		/// </summary>
		private InterpolationMode GetInterpolationMode ()
		{
			Runtime.ValidateObject (this);
			return Spline_GetInterpolationMode (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Variant Spline_GetKnot (IntPtr handle, uint index);

		/// <summary>
		/// Return the knot at the specific index.
		/// 
		/// </summary>
		public Variant GetKnot (uint index)
		{
			Runtime.ValidateObject (this);
			return Spline_GetKnot (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern Variant Spline_GetPoint (IntPtr handle, float f);

		/// <summary>
		/// Return the T of the point of the spline at f from 0.f - 1.f.
		/// </summary>
		public Variant GetPoint (float f)
		{
			Runtime.ValidateObject (this);
			return Spline_GetPoint (handle, f);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetInterpolationMode (IntPtr handle, InterpolationMode interpolationMode);

		/// <summary>
		/// Set the interpolation mode.
		/// 
		/// </summary>
		private void SetInterpolationMode (InterpolationMode interpolationMode)
		{
			Runtime.ValidateObject (this);
			Spline_SetInterpolationMode (handle, interpolationMode);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_0 (IntPtr handle, ref Vector3 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Vector3 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_0 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_1 (IntPtr handle, ref IntRect knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (IntRect knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_1 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_2 (IntPtr handle, ref Color knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Color knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_2 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_3 (IntPtr handle, ref Vector2 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Vector2 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_3 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_4 (IntPtr handle, ref Vector4 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Vector4 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_4 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_5 (IntPtr handle, ref IntVector2 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (IntVector2 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_5 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_6 (IntPtr handle, ref Quaternion knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Quaternion knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_6 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_7 (IntPtr handle, ref Matrix4 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Matrix4 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_7 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_8 (IntPtr handle, ref Matrix3 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Matrix3 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_8 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_9 (IntPtr handle, ref Matrix3x4 knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (Matrix3x4 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_9 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_10 (IntPtr handle, int knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (int knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_10 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_11 (IntPtr handle, uint knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (uint knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_11 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_12 (IntPtr handle, float knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (float knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_12 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_13 (IntPtr handle, string knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (string knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_13 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_SetKnot_14 (IntPtr handle, bool knot, uint index);

		/// <summary>
		/// Set the value of an existing knot.
		/// </summary>
		public void SetKnot (bool knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_SetKnot_14 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_0 (IntPtr handle, ref Vector3 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Vector3 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_0 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_1 (IntPtr handle, ref IntRect knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (IntRect knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_1 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_2 (IntPtr handle, ref Color knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Color knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_2 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_3 (IntPtr handle, ref Vector2 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Vector2 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_3 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_4 (IntPtr handle, ref Vector4 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Vector4 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_4 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_5 (IntPtr handle, ref IntVector2 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (IntVector2 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_5 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_6 (IntPtr handle, ref Quaternion knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Quaternion knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_6 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_7 (IntPtr handle, ref Matrix4 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Matrix4 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_7 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_8 (IntPtr handle, ref Matrix3 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Matrix3 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_8 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_9 (IntPtr handle, ref Matrix3x4 knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (Matrix3x4 knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_9 (handle, ref knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_10 (IntPtr handle, int knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (int knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_10 (handle, knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_11 (IntPtr handle, uint knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (uint knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_11 (handle, knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_12 (IntPtr handle, float knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (float knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_12 (handle, knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_13 (IntPtr handle, string knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (string knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_13 (handle, knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot_14 (IntPtr handle, bool knot);

		/// <summary>
		/// Add a knot to the end of the spline.
		/// </summary>
		public void AddKnot (bool knot)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot_14 (handle, knot);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_0 (IntPtr handle, ref Vector3 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Vector3 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_0 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_1 (IntPtr handle, ref IntRect knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (IntRect knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_1 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_2 (IntPtr handle, ref Color knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Color knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_2 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_3 (IntPtr handle, ref Vector2 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Vector2 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_3 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_4 (IntPtr handle, ref Vector4 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Vector4 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_4 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_5 (IntPtr handle, ref IntVector2 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (IntVector2 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_5 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_6 (IntPtr handle, ref Quaternion knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Quaternion knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_6 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_7 (IntPtr handle, ref Matrix4 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Matrix4 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_7 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_8 (IntPtr handle, ref Matrix3 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Matrix3 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_8 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_9 (IntPtr handle, ref Matrix3x4 knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (Matrix3x4 knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_9 (handle, ref knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_10 (IntPtr handle, int knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (int knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_10 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_11 (IntPtr handle, uint knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (uint knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_11 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_12 (IntPtr handle, float knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (float knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_12 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_13 (IntPtr handle, string knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (string knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_13 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_AddKnot1_14 (IntPtr handle, bool knot, uint index);

		/// <summary>
		/// Add a knot to the spline at a specific index.
		/// </summary>
		public void AddKnot (bool knot, uint index)
		{
			Runtime.ValidateObject (this);
			Spline_AddKnot1_14 (handle, knot, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_RemoveKnot (IntPtr handle);

		/// <summary>
		/// Remove the last knot on the spline.
		/// </summary>
		public void RemoveKnot ()
		{
			Runtime.ValidateObject (this);
			Spline_RemoveKnot (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_RemoveKnot2 (IntPtr handle, uint index);

		/// <summary>
		/// Remove the knot at the specific index.
		/// </summary>
		public void RemoveKnot (uint index)
		{
			Runtime.ValidateObject (this);
			Spline_RemoveKnot2 (handle, index);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Spline_Clear (IntPtr handle);

		/// <summary>
		/// Clear the spline.
		/// </summary>
		public void Clear ()
		{
			Runtime.ValidateObject (this);
			Spline_Clear (handle);
		}

		/// <summary>
		/// Return the interpolation mode.
		/// 
		/// Or
		/// Set the interpolation mode.
		/// 
		/// </summary>
		public InterpolationMode InterpolationMode {
			get {
				return GetInterpolationMode ();
			}
			set {
				SetInterpolationMode (value);
			}
		}
	}
}
