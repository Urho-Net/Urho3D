using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;

namespace Urho
{
    public partial class Model
    {
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        extern static IntPtr Model_Clone_EmptyName(IntPtr handle);

        public Model Clone()
        {
            Runtime.ValidateRefCounted(this);
            return Runtime.LookupObject<Model>(Model_Clone_EmptyName(handle));
        }


        public unsafe void SetGeometryBoneMappings(List<List<uint>> geometryBoneMappings)
        {
            Runtime.ValidateRefCounted(this);
            ClearGeometryBoneMappings();
            if (geometryBoneMappings.Count > 0)
            {

                foreach (var geometryBoneMapping in geometryBoneMappings)
                {
                    uint[] array = geometryBoneMapping.ToArray();
                    if (array.Length > 0)
                    {
                        fixed (uint* ptr = &array[0])
                        {
                            AddGeometryBoneMapping(ptr, (uint)geometryBoneMappings.Count);
                        }
                    }
                }
            }
        }
    }
}
