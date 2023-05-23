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

namespace Urho.Urho2D
{
    /// <summary>
    /// 2D physics simulation world component. Should be added only to the root scene node.
    /// </summary>
    public unsafe partial class PhysicsWorld2D : Component
    {

        static RigidBody2D[] ZeroArrayRigidBody2D = new RigidBody2D[0];
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr PhysicsWorld2D_GetRigidBodies(IntPtr handle, ref Urho.Rect rect, uint collisionMask , out int count);

        public RigidBody2D[] GetRigidBodies(Urho.Rect rect, uint collisionMask = uint.MaxValue)
        {
            Runtime.ValidateRefCounted(this);
            int count;
            var ptr = PhysicsWorld2D_GetRigidBodies(handle, ref rect, collisionMask, out count);
            if (ptr == IntPtr.Zero)
                return ZeroArrayRigidBody2D;

            var res = new RigidBody2D[count];
            for (int i = 0; i < count; i++)
            {
                var rigidBody2D = Marshal.ReadIntPtr(ptr, i * IntPtr.Size);
                res[i] = Runtime.LookupObject<RigidBody2D>(rigidBody2D);
            }

            return res;
        }

    }

}