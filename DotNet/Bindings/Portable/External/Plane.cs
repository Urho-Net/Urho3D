using System;
using System.Runtime.InteropServices;
using Urho.Json;
namespace Urho
{
    [StructLayout(LayoutKind.Sequential)]
    [JsonObject(MemberSerialization.OptIn)]
    public struct Plane
    {
        /// <summary>
        /// Plane normal.
        /// </summary>
        [JsonProperty]
        public Vector3 Normal;

        /// <summary>
        /// Plane absolute normal.
        /// </summary>
        [JsonProperty]
        public Vector3 AbsNormal;

        /// <summary>
        /// Plane constant.
        /// </summary>
        [JsonProperty]
        public float D;

        /// <summary>
        /// Construct from a normal vector and a point on the plane.
        /// </summary>
        public Plane(Vector3 normal, Vector3 point)
        {
            Normal = Vector3.Normalize(normal);
            AbsNormal = new Vector3(Math.Abs(Normal.X), Math.Abs(Normal.Y), Math.Abs(Normal.Z));
            D = -Vector3.Dot(Normal, point);
        }

        /// <summary>
        /// Construct from a 4-dimensional vector, where the w coordinate is the plane parameter.
        /// </summary>
        public Plane(Vector4 plane)
        {
            Normal = new Vector3(plane.X, plane.Y, plane.Z);
            AbsNormal = new Vector3(Math.Abs(plane.X), Math.Abs(plane.Y), Math.Abs(plane.Z));
            D = plane.W;
        }
    }
}
