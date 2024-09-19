/*
 *
 * MIT License
   Copyright (c) 2024 Eli Aloni
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */

using System;
using System.Runtime.InteropServices;

// Structs

namespace Manifold
{
    public struct ManifoldManifold { }
    public struct ManifoldManifoldVec { }
    public struct ManifoldCrossSection { }
    public struct ManifoldCrossSectionVec { }
    public struct ManifoldSimplePolygon { }
    public struct ManifoldPolygons { }
    public struct ManifoldMesh { }
    public struct ManifoldMeshGL { }
    public struct ManifoldBox { }
    public struct ManifoldRect { }
#if MANIFOLD_EXPORT
public struct ManifoldMaterial { }
public struct ManifoldExportOptions { }
#endif

    [StructLayout(LayoutKind.Sequential)]
    public struct ManifoldManifoldPair
    {
        public IntPtr first; // Equivalent to ManifoldManifold*
        public IntPtr second; // Equivalent to ManifoldManifold*
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ManifoldVec2
    {
        public double x;
        public double y;
        public ManifoldVec2(double _x, double _y)
        {
            x = _x;
            y = _y;
        }
        
        public static implicit operator ManifoldVec2(Urho.Vector2 v)
        {
            return new ManifoldVec2(v.X, v.Y);
        }
        public static implicit operator Urho.Vector2(ManifoldVec2 v)
        {
            return new Urho.Vector2((float)v.x, (float)v.y);
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ManifoldVec3
    {
        public double x;
        public double y;
        public double z;

        public ManifoldVec3(double _x, double _y, double _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }

        public static ManifoldVec3 Zero()
        {
            return new ManifoldVec3(0,0,0);
        }
        
        public static ManifoldVec3 One()
        {
            return new ManifoldVec3(1,1,1);
        }
        
        public static implicit operator ManifoldVec3(Urho.Vector3 v)
        {
            return new ManifoldVec3(v.X, v.Y, v.Z);
        }
        public static implicit operator Urho.Vector3(ManifoldVec3 v)
        {
            return new Urho.Vector3((float)v.x, (float)v.y, (float)v.z);
        }
    }
    
  

    [StructLayout(LayoutKind.Sequential)]
    public struct ManifoldIVec3
    {
        public int x;
        public int y;
        public int z;
        
        public ManifoldIVec3(int _x, int _y, int _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }
        
        public static implicit operator ManifoldIVec3(Urho.IntVector3 v)
        {
            return new ManifoldIVec3(v.X, v.Y, v.Z);
        }
        public static implicit operator Urho.IntVector3(ManifoldIVec3 v)
        {
            return new Urho.IntVector3(v.x, v.y, v.z);
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ManifoldVec4
    {
        public double x;
        public double y;
        public double z;
        public double w;
        
        public ManifoldVec4(double _x, double _y, double _z , double _w)
        {
            x = _x;
            y = _y;
            z = _z;
            w = _w;
        }
        
        public static implicit operator ManifoldVec4(Urho.Vector4 v)
        {
            return new ManifoldVec4(v.X, v.Y, v.Z, v.W);
        }
        public static implicit operator Urho.Vector4(ManifoldVec4 v)
        {
            return new Urho.Vector4((float)v.x, (float)v.y, (float)v.z, (float)v.w);
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ManifoldProperties
    {
        public double surface_area;
        public double volume;
    }

    // Enums

    public enum ManifoldOpType
    {
        MANIFOLD_ADD,
        MANIFOLD_SUBTRACT,
        MANIFOLD_INTERSECT
    }

    public enum ManifoldError
    {
        MANIFOLD_NO_ERROR,
        MANIFOLD_NON_FINITE_VERTEX,
        MANIFOLD_NOT_MANIFOLD,
        MANIFOLD_VERTEX_INDEX_OUT_OF_BOUNDS,
        MANIFOLD_PROPERTIES_WRONG_LENGTH,
        MANIFOLD_MISSING_POSITION_PROPERTIES,
        MANIFOLD_MERGE_VECTORS_DIFFERENT_LENGTHS,
        MANIFOLD_MERGE_INDEX_OUT_OF_BOUNDS,
        MANIFOLD_TRANSFORM_WRONG_LENGTH,
        MANIFOLD_RUN_INDEX_WRONG_LENGTH,
        MANIFOLD_FACE_ID_WRONG_LENGTH,
        MANIFOLD_INVALID_CONSTRUCTION
    }

    public enum ManifoldFillRule
    {
        MANIFOLD_FILL_RULE_EVEN_ODD,
        MANIFOLD_FILL_RULE_NON_ZERO,
        MANIFOLD_FILL_RULE_POSITIVE,
        MANIFOLD_FILL_RULE_NEGATIVE
    }

    public enum ManifoldJoinType
    {
        MANIFOLD_JOIN_TYPE_SQUARE,
        MANIFOLD_JOIN_TYPE_ROUND,
        MANIFOLD_JOIN_TYPE_MITER
    }
}