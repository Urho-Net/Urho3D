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
using Urho;

namespace Manifold;

public unsafe class Manifold : IDisposable
{
    private bool disposedValue = false;
    public  ManifoldManifold* Handle{get; private set;}

    private static IntPtr mallocNativeObject()
    {
        return ManifoldNative.manifold_malloc(ManifoldNative.manifold_manifold_size());
    }
    
    public Manifold()
    {
        Handle = ManifoldNative.manifold_empty(mallocNativeObject());
    }
    public Manifold(ManifoldManifold* handle)
    {
        Handle = handle;
    }
    
    public static Manifold Sphere(double radius , int circularSegments = 0)
    {
        ManifoldManifold* manifold = ManifoldNative.manifold_sphere(mallocNativeObject(), radius, circularSegments);
        var status = ManifoldNative.manifold_status(manifold);
        if (status == ManifoldError.MANIFOLD_NO_ERROR)
        {
            return new Manifold(manifold);
        }
        else
        {
            return null;
        }
    }

    public static Manifold Cube(ManifoldVec3 size , bool center = false)
    {
        ManifoldManifold* manifold = ManifoldNative.manifold_cube(mallocNativeObject(),size.x,size.y,size.z,(center == true)?1:0);
        var status = ManifoldNative.manifold_status(manifold);
        if (status == ManifoldError.MANIFOLD_NO_ERROR)
        {
            return new Manifold(manifold);
        }
        else
        {
            return null;
        }
    }
    
    public static Manifold operator-(Manifold first ,  Manifold second)
    {
        ManifoldManifold* manifold = ManifoldNative.manifold_difference(mallocNativeObject(), first.Handle, second.Handle);
        
        var status = ManifoldNative.manifold_status(manifold);
        if (status == ManifoldError.MANIFOLD_NO_ERROR)
        {
            return new Manifold(manifold);
        }
        else
        {
            return null;
        }
    }

    public bool GetMeshData(
        out double precision,
        out ManifoldVec3[] outVertPos,
        out int outVertPosCount,
        out ManifoldIVec3[] outTriVerts,
        out int outTriVertsCount,
        out ManifoldVec3[] outVertNormal,
        out int outVertNormaCount)
    {
        return ManifoldNative.manifoldGetMeshData(Handle,
            out  precision,
            out  outVertPos,
            out  outVertPosCount,
            out  outTriVerts,
            out  outTriVertsCount,
            out  outVertNormal,
            out  outVertNormaCount);
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!disposedValue)
        {
            if (disposing)
            {
                // TODO: dispose managed state (managed objects)
            }

            if(Handle != null)
            {
                ManifoldNative.manifold_delete_manifold(Handle);
                Handle = null;
            }

            // TODO: free unmanaged resources (unmanaged objects) and override finalizer
            // TODO: set large fields to null
            disposedValue = true;
        }
    }
    
    // // TODO: override finalizer only if 'Dispose(bool disposing)' has code to free unmanaged resources
    ~Manifold()
    {
        // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
        Dispose(disposing: false);
    }

    public void Dispose()
    {
        // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
        Dispose(disposing: true);
        GC.SuppressFinalize(this);
    }
    
    
}