// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// GImpactMeshData.cs
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
	/// Triangle mesh geometry data.
	/// </summary>
	[StructLayout (LayoutKind.Sequential)]
	public unsafe partial struct GImpactMeshData
	{
		unsafe partial void OnGImpactMeshDataCreated ();

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr GImpactMeshData_GImpactMeshData (IntPtr model, uint lodLevel);

		[Preserve]
		public GImpactMeshData (Model model, uint lodLevel)
		{
			Runtime.Validate (typeof(GImpactMeshData));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr GImpactMeshData_GImpactMeshData0 (IntPtr custom);

		[Preserve]
		public GImpactMeshData (CustomGeometry custom)
		{
			Runtime.Validate (typeof(GImpactMeshData));
		}
	}
}
