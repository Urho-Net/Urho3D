#nullable enable

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Threading;

namespace Java.Interop
{

    class AndroidValueManager : JniRuntime.JniValueManager
    {
        public override void ActivatePeer(IJavaPeerable? self, JniObjectReference reference, ConstructorInfo cinfo, object?[]? argumentValues)
        {
          
        }

        public override void AddPeer(IJavaPeerable value)
        {
           
        }

        public override void CollectPeers()
        {
           
        }

        public override IJavaPeerable? CreatePeer(ref JniObjectReference reference, JniObjectReferenceOptions transfer, Type? targetType)
        {
            return base.CreatePeer(ref reference, transfer, targetType);
        }

        public override void DisposePeer(IJavaPeerable value)
        {
            base.DisposePeer(value);
        }

        public override void DisposePeerUnlessReferenced(IJavaPeerable value)
        {
            base.DisposePeerUnlessReferenced(value);
        }

        public override bool Equals(object? obj)
        {
            return base.Equals(obj);
        }

        public override void FinalizePeer(IJavaPeerable value)
        {
          
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override List<JniSurfacedPeerInfo> GetSurfacedPeers()
        {
            return new List<JniSurfacedPeerInfo>();
        }

        public override void OnSetRuntime(JniRuntime runtime)
        {
            base.OnSetRuntime(runtime);
        }

        public override IJavaPeerable? PeekPeer(JniObjectReference reference)
        {
           return null;
        }

        public override void RemovePeer(IJavaPeerable value)
        {
            
        }

        public override string? ToString()
        {
            return base.ToString();
        }

        public override void WaitForGCBridgeProcessing()
        {
           
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        protected override JniValueMarshaler GetValueMarshalerCore(Type type)
        {
            return base.GetValueMarshalerCore(type);
        }

        protected override bool TryUnboxPeerObject(IJavaPeerable value, [NotNullWhen(true)] out object? result)
        {
            return base.TryUnboxPeerObject(value, out result);
        }
    }

}