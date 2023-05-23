#nullable enable

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Threading;

namespace Java.Interop
{
    class AndroidObjectReferenceManager : JniRuntime.JniObjectReferenceManager
    {
        public override int GlobalReferenceCount => 1;

        public override int WeakGlobalReferenceCount => 1;

        public override bool LogLocalReferenceMessages => base.LogLocalReferenceMessages;

        public override bool LogGlobalReferenceMessages => base.LogGlobalReferenceMessages;

        public override void CreatedLocalReference(JniObjectReference reference, ref int localReferenceCount)
        {
            base.CreatedLocalReference(reference, ref localReferenceCount);
        }

        public override JniObjectReference CreateGlobalReference(JniObjectReference reference)
        {
            return base.CreateGlobalReference(reference);
        }

        public override JniObjectReference CreateLocalReference(JniObjectReference reference, ref int localReferenceCount)
        {
            return base.CreateLocalReference(reference, ref localReferenceCount);
        }

        public override JniObjectReference CreateWeakGlobalReference(JniObjectReference reference)
        {
            return base.CreateWeakGlobalReference(reference);
        }

        public override void DeleteGlobalReference(ref JniObjectReference reference)
        {
            base.DeleteGlobalReference(ref reference);
        }

        public override void DeleteLocalReference(ref JniObjectReference reference, ref int localReferenceCount)
        {
            base.DeleteLocalReference(ref reference, ref localReferenceCount);
        }

        public override void DeleteWeakGlobalReference(ref JniObjectReference reference)
        {
            base.DeleteWeakGlobalReference(ref reference);
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override void OnSetRuntime(JniRuntime runtime)
        {
            base.OnSetRuntime(runtime);
        }

        public override IntPtr ReleaseLocalReference(ref JniObjectReference reference, ref int localReferenceCount)
        {
            return base.ReleaseLocalReference(ref reference, ref localReferenceCount);
        }

        public override string ToString()
        {
            return base.ToString();
        }

        public override void WriteGlobalReferenceLine(string format, params object[] args)
        {
            base.WriteGlobalReferenceLine(format, args);
        }

        public override void WriteLocalReferenceLine(string format, params object[] args)
        {
            base.WriteLocalReferenceLine(format, args);
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }
    }

}