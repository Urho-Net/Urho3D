//
// Helpers to surface a simpler API for collisions
//
using System;
using System.Runtime.InteropServices;

namespace Urho.Physics {
	
	public unsafe struct CollisionData
	{
		public Vector3 ContactPosition, ContactNormal;
		public float ContactDistance, ContactImpulse;
		
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