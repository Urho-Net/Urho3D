using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Urho
{
	internal static class Vectors {
		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		internal extern static int VectorSharedPtr_Count (IntPtr h);

		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		internal extern static IntPtr VectorSharedPtr_GetIdx (IntPtr h, int idx);

		internal class ProxyUrhoObject<T> : ProxyRefCounted<T>, IReadOnlyList<T> where T : UrhoObject
		{
			public ProxyUrhoObject(IntPtr handle) : base(handle) { }

			public override T this[int idx] => Runtime.LookupObject<T>(VectorSharedPtr_GetIdx(handle, idx));

			IEnumerator IEnumerable.GetEnumerator() => new ProxyUrhoObjectEnumerator<UrhoObject>(handle);

			public override IEnumerator<T> GetEnumerator() => new ProxyUrhoObjectEnumerator<T>(handle);

			class ProxyUrhoObjectEnumerator<U> : IEnumerator, IEnumerator<U> where U : UrhoObject
			{
				readonly IntPtr handle;
				int index;
				U current;

				public ProxyUrhoObjectEnumerator(IntPtr handle)
				{
					this.handle = handle;
				}

				public bool MoveNext()
				{
					var count = VectorSharedPtr_Count(handle);
					if (count < 1 || count <= index)
						return false;

					current = Runtime.LookupObject<U>(VectorSharedPtr_GetIdx(handle, index));
					index++;
					return true;
				}

				public void Reset()
				{
					index = 0;
					current = null;
				}

				U IEnumerator<U>.Current => current;

				public object Current => current;

				public void Dispose()
				{
					Reset();
				}
			}
		}

		internal class ProxyRefCounted<T> : IReadOnlyList<T> where T : RefCounted
		{
			protected IntPtr handle;
			public ProxyRefCounted(IntPtr handle)
			{
				this.handle = handle;
			}
		
			public virtual T this [int idx] => Runtime.LookupRefCounted<T> (VectorSharedPtr_GetIdx (handle, idx));

			public int Count => VectorSharedPtr_Count (handle);
			
			IEnumerator IEnumerable.GetEnumerator () => new ProxyRefCountedEnumerator<RefCounted>(handle);

			public virtual IEnumerator<T> GetEnumerator () => new ProxyRefCountedEnumerator<T>(handle);

			class ProxyRefCountedEnumerator<U> : IEnumerator, IEnumerator<U> where U : RefCounted
			{
				readonly IntPtr handle;
				int index;
				U current;

				public ProxyRefCountedEnumerator(IntPtr handle)
				{
					this.handle = handle;
				}

				public bool MoveNext()
				{
					var count = VectorSharedPtr_Count(handle);
					if (count < 1 || count <= index)
						return false;

					current = Runtime.LookupRefCounted<U>(VectorSharedPtr_GetIdx(handle, index));
					index++;
					return true;
				}

				public void Reset()
				{
					index = 0;
					current = null;
				}

				U IEnumerator<U>.Current => current;

				public object Current => current;

				public void Dispose()
				{
					Reset();
				}
			}
		}

		[DllImport ("Urho3D", CallingConvention=CallingConvention.Cdecl)]
		internal extern static int PodVectorUint_Count (IntPtr h);

		[DllImport ("Urho3D", CallingConvention=CallingConvention.Cdecl)]
        internal extern static uint PodVectorUint_GetIdx (IntPtr h, int idx);

        public class ProxyPodVectorUint<T> : IReadOnlyList<uint>
        {
            protected IntPtr handle;
			public ProxyPodVectorUint(IntPtr handle)
			{
				this.handle = handle;
			}
            
            public uint this[int index] => PodVectorUint_GetIdx (handle, index);

            public int Count => PodVectorUint_Count (handle);

            public IEnumerator<uint> GetEnumerator()
            {
                return  new ProxyPodVectorUintEnumerator(handle);
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                return new ProxyPodVectorUintEnumerator(handle);
            }

            class ProxyPodVectorUintEnumerator : IEnumerator<uint>
            {
                readonly IntPtr handle;
                int index;
                uint current;

                public ProxyPodVectorUintEnumerator(IntPtr handle)
                {
                    this.handle = handle;
                }

                public uint Current => current;

                object IEnumerator.Current => current;

                public void Dispose()
                {
                    Reset();
                }

                public bool MoveNext()
                {
                    var count = PodVectorUint_Count(handle);
					if (count < 1 || count <= index)
						return false;

					current = PodVectorUint_GetIdx(handle, index);
					index++;
                    return true;
                }

                public void Reset()
                {
                    index = 0;
					current = 0;
                }
            }
        }
	}
}