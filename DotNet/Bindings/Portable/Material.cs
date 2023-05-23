using System;
using System.Runtime.InteropServices;
using Urho.Resources;
using Urho.Urho2D;
using System.Collections.Generic;

namespace Urho
{
    partial class Material
    {

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern uint Material_GetShaderParameterKeysSize(IntPtr _target);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static unsafe extern void Material_GetShaderParameterGetKeys(IntPtr _target, uint* buffer);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static unsafe extern MaterialShaderParameter* Material_GetMaterialShaderParameterPtr(IntPtr _target, int key);


        public static Material FromImage(string image, string normals)
        {
            if (string.IsNullOrEmpty(normals))
                return FromImage(image);

            var cache = Application.Current.ResourceCache;
            var diff = cache.GetTexture2D(image);
            if (diff == null)
                return null;
            var normal = cache.GetTexture2D(normals);
            if (normal == null)
                return FromImage(image);

            var material = new Material();
            material.SetTexture(TextureUnit.Diffuse, diff);
            material.SetTexture(TextureUnit.Normal, normal);
            material.SetTechnique(0, CoreAssets.Techniques.DiffNormal, 0, 0);
            return material;
        }

        public static Material FromImage(string image)
        {
            var cache = Application.Current.ResourceCache;
            var diff = cache.GetTexture2D(image);
            if (diff == null)
                return null;
            var material = new Material();
            material.SetTexture(TextureUnit.Diffuse, diff);
            material.SetTechnique(0, CoreAssets.Techniques.Diff, 0, 0);
            return material;
        }

        public static Material FromImage(Image image, bool useAlpha = false)
        {
            var texture = new Texture2D();
            texture.SetData(image, useAlpha);
            var material = new Material();
            material.SetTechnique(0, CoreAssets.Techniques.Diff, 0, 0);
            material.SetTexture(TextureUnit.Diffuse, texture);
            return material;
        }

        public static Material FromColor(Color color)
        {
            return FromColor(color, false);
        }

        public static Material FromColor(Color color, bool unlit)
        {
            var material = new Material();
            var cache = Application.Current.ResourceCache;
            float tolerance = 0.001f;
            if (unlit)
                material.SetTechnique(0, Math.Abs(color.A - 1) < tolerance ? CoreAssets.Techniques.NoTextureUnlit : CoreAssets.Techniques.NoTextureUnlitAlpha, MaterialQuality.Medium, 1);
            else
                material.SetTechnique(0, Math.Abs(color.A - 1) < tolerance ? CoreAssets.Techniques.NoTexture : CoreAssets.Techniques.NoTextureAlpha, MaterialQuality.Medium, 1);
            material.SetShaderParameter("MatDiffColor", color);
            return material;
        }

        public static Material SkyboxFromImages(
            string imagePositiveX,
            string imageNegativeX,
            string imagePositiveY,
            string imageNegativeY,
            string imagePositiveZ,
            string imageNegativeZ)
        {
            var cache = Application.Current.ResourceCache;
            var material = new Material();
            TextureCube cube = new TextureCube();
            cube.SetData(CubeMapFace.PositiveX, cache.GetFile(imagePositiveX, false));
            cube.SetData(CubeMapFace.NegativeX, cache.GetFile(imageNegativeX, false));
            cube.SetData(CubeMapFace.PositiveY, cache.GetFile(imagePositiveY, false));
            cube.SetData(CubeMapFace.NegativeY, cache.GetFile(imageNegativeY, false));
            cube.SetData(CubeMapFace.PositiveZ, cache.GetFile(imagePositiveZ, false));
            cube.SetData(CubeMapFace.NegativeZ, cache.GetFile(imageNegativeZ, false));
            material.SetTexture(TextureUnit.Diffuse, cube);
            material.SetTechnique(0, CoreAssets.Techniques.DiffSkybox, 0, 0);
            material.CullMode = CullMode.None;
            return material;
        }

        public static Material SkyboxFromImage(string image)
        {
            return SkyboxFromImages(image, image, image, image, image, image);
        }

        //TODO: Surface Variant& GetShaderParameter
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
		unsafe static extern Color * Material_GetShaderParameterColor(IntPtr target, string paramName);
#else
        static extern Color Material_GetShaderParameterColor(IntPtr target, string paramName);
#endif

        unsafe public Color GetShaderParameter(string parameterName)
        {
#if __WEB__
			return *Material_GetShaderParameterColor(Handle, parameterName);
#else
            return Material_GetShaderParameterColor(Handle, parameterName);
#endif
        }


        public unsafe Dictionary<int, MaterialShaderParameter> GetShaderParameters()
        {
            Dictionary<int, MaterialShaderParameter> parameters = new Dictionary<int, MaterialShaderParameter>();
            if (Handle != IntPtr.Zero)
            {
                foreach (var key in ShaderParametersKeys)
                {

                    MaterialShaderParameter* materialShaderParameter = Material_GetMaterialShaderParameterPtr(Handle, key);
                    if (materialShaderParameter != null)
                    {
                        parameters[key] = *materialShaderParameter;
                    }
                }
            }
            return parameters;
        }

        public unsafe Dictionary<string, MaterialShaderParameter> GetShaderParametersWithNames()
        {
            Dictionary<string, MaterialShaderParameter> parameters = new Dictionary<string, MaterialShaderParameter>();
            if (Handle != IntPtr.Zero)
            {
                foreach (var key in ShaderParametersKeys)
                {

                    MaterialShaderParameter* materialShaderParameter = Material_GetMaterialShaderParameterPtr(Handle, key);
                    if (materialShaderParameter != null)
                    {
                        parameters[materialShaderParameter->Name] = *materialShaderParameter;
                    }
                }
            }
            return parameters;
        }

        public unsafe int ShaderParametersCount
        {
            get
            {
                if (Handle != IntPtr.Zero)
                    return (int)Material_GetShaderParameterKeysSize(Handle);
                else
                    return 0;
            }
        }

        public unsafe List<int> ShaderParametersKeys
        {
            get
            {
                List<int> keys = new List<int>();

                if (Handle != IntPtr.Zero)
                {

                    if (ShaderParametersCount > 0)
                    {
                        IntPtr pnt = Marshal.AllocHGlobal(sizeof(uint) * ShaderParametersCount);
                        Material_GetShaderParameterGetKeys(Handle, (uint*)pnt);
                        for (int i = 0; i < ShaderParametersCount; i++)
                        {
                            keys.Add(((int)((uint*)pnt)[i]));
                        }
                        Marshal.FreeHGlobal(pnt);
                    }
                }

                return keys;
            }
        }
    }
}
