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
    /// Hierarchical performance profiler subsystem.
    /// </summary>
    public unsafe partial class Profiler : UrhoObject
    {

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void Profiler_BeginBlock(IntPtr handle, string name);

        /// <summary>
		/// Begin timing a profiling block..
		/// </summary>
		public void BeginBlock(string name)
        {
            Runtime.ValidateRefCounted(this);
            Profiler_BeginBlock(handle, name);
        }
    }

}