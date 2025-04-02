//
// Helpers to surface a simpler API for collisions
//
using System;
using System.Runtime.InteropServices;

namespace Urho.Physics {
	
	[StructLayout(LayoutKind.Sequential)]
	public unsafe struct CollisionData
	{
		 [MarshalAs(UnmanagedType.Struct)]
		public Vector3 ContactPosition;
		 [MarshalAs(UnmanagedType.Struct)]
		public Vector3  ContactNormal;
		[MarshalAs(UnmanagedType.R4)]
		public float ContactDistance;
		[MarshalAs(UnmanagedType.R4)]
		public float ContactImpulse;
		
		public override string ToString ()
		{
			return $"[CollisionData: Position={ContactPosition}, Normal={ContactNormal}, Distance={ContactDistance}, Impuse={ContactImpulse}";
		}

		
		internal static CollisionData [] FromContactData (IntPtr data, int size)
		{
			return data.ToStructsArray<CollisionData>(size / sizeof(CollisionData));
		}
	}
}