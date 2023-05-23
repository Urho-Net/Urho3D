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
	/// Construct.
	/// </summary>
	public unsafe partial class KinematicCharacterController : Component
	{
		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void KinematicCharacterController_GetTransform (IntPtr handle , out Urho.Vector3 position, out Urho.Quaternion rotation);

		/// <summary>
		/// Set character position and rotation in world space as an atomic operation.
		/// </summary>
		public void GetTransform(out Urho.Vector3 position, out Urho.Quaternion rotation)
		{
			Runtime.ValidateRefCounted (this);
			KinematicCharacterController_GetTransform (handle, out position, out  rotation);
		}
    }

}