using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho.Gui
{
	/// <summary>
	/// Scrollable list %UI element.
	/// </summary>
	public unsafe partial class ListView : ScrollView
	{
        private IReadOnlyList<uint> _GetSelections_cache;

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ListView_GetSelections (IntPtr handle);

        [DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void ListView_SetSelections(IntPtr handle, uint* data, int size);

		/// <summary>
		/// Return all selected indices.
		/// </summary>
		private IReadOnlyList<uint> GetSelections ()
		{
			Runtime.ValidateRefCounted (this);
			return _GetSelections_cache != null ? _GetSelections_cache : _GetSelections_cache =  Runtime.CreatePodVectorUintProxy(ListView_GetSelections (handle));
		}   

        /// <summary>
		/// Return all selected indices.
		/// </summary>
		public IReadOnlyList<uint> Selections {
			get {
				return GetSelections ();
			}
		}    

        public void SetSelections (uint [] selections)
        {
            fixed ( uint * ptr  = selections)
            {
                ListView_SetSelections( handle, ptr, selections.Length);
            }
        }
    }

}