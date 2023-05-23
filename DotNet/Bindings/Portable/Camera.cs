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
	partial class Camera
	{
		public Ray GetScreenRayForMouse()
		{
			var app = Application.Current;
			var cursorPos = app.UI.CursorPosition;
			return GetScreenRay((float)cursorPos.X / app.Graphics.Width, (float)cursorPos.Y / app.Graphics.Height);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Camera_SetViewOverrideFlags (IntPtr handle, uint flags);

		/// <summary>
		/// Set view override flags.
		/// </summary>
		private void SetViewOverrideFlags (uint flags)
		{
			Runtime.ValidateRefCounted (this);
			Camera_SetViewOverrideFlags (handle, flags);
		}


		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Camera_GetViewOverrideFlags (IntPtr handle);

		/// <summary>
		/// Return view override flags.
		/// </summary>
		private uint GetViewOverrideFlags ()
		{
			Runtime.ValidateRefCounted (this);
			return Camera_GetViewOverrideFlags (handle);
		}

		/// <summary>
		/// Return view override flags.
		/// Or
		/// Set view override flags.
		/// </summary>
		public ViewOverrideFlags ViewOverrideFlags {
			get {
				return (ViewOverrideFlags)GetViewOverrideFlags ();
			}
			set {
				SetViewOverrideFlags ((uint)value);
			}
		}
	}
}
