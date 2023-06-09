// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ShaderVariation.cs
// 
using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho
{
	/// <summary>
	/// Vertex or pixel shader on the GPU.
	/// </summary>
	public unsafe partial class ShaderVariation : RefCounted, IGPUObject
	{
		unsafe partial void OnShaderVariationCreated ();

		[Preserve]
		public ShaderVariation (IntPtr handle) : base (handle)
		{
			OnShaderVariationCreated ();
		}

		[Preserve]
		protected ShaderVariation (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnShaderVariationCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_CastToGPUObject (IntPtr handle);

		public GPUObject AsGPUObject ()
		{
			return new GPUObject (ShaderVariation_CastToGPUObject (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_ShaderVariation (IntPtr owner, ShaderType type);

		[Preserve]
		public ShaderVariation (Shader owner, ShaderType type) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ShaderVariation));
			handle = ShaderVariation_ShaderVariation ((object)owner == null ? IntPtr.Zero : owner.Handle, type);
			Runtime.RegisterObject (this);
			OnShaderVariationCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ShaderVariation_Release (IntPtr handle);

		/// <summary>
		/// Release the shader.
		/// </summary>
		public void Release ()
		{
			Runtime.ValidateRefCounted (this);
			ShaderVariation_Release (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ShaderVariation_Create (IntPtr handle);

		/// <summary>
		/// Compile the shader. Return true if successful.
		/// </summary>
		public bool Create ()
		{
			Runtime.ValidateRefCounted (this);
			return ShaderVariation_Create (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ShaderVariation_SetName (IntPtr handle, string name);

		/// <summary>
		/// Set name.
		/// </summary>
		private void SetName (string name)
		{
			Runtime.ValidateRefCounted (this);
			ShaderVariation_SetName (handle, name);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ShaderVariation_SetDefines (IntPtr handle, string defines);

		/// <summary>
		/// Set defines.
		/// </summary>
		private void SetDefines (string defines)
		{
			Runtime.ValidateRefCounted (this);
			ShaderVariation_SetDefines (handle, defines);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_GetOwner (IntPtr handle);

		/// <summary>
		/// Return the owner resource.
		/// </summary>
		private Shader GetOwner ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<Shader> (ShaderVariation_GetOwner (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ShaderType ShaderVariation_GetShaderType (IntPtr handle);

		/// <summary>
		/// Return shader type.
		/// </summary>
		private ShaderType GetShaderType ()
		{
			Runtime.ValidateRefCounted (this);
			return ShaderVariation_GetShaderType (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_GetName (IntPtr handle);

		/// <summary>
		/// Return shader name.
		/// </summary>
		private string GetName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ShaderVariation_GetName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_GetFullName (IntPtr handle);

		/// <summary>
		/// Return full shader name.
		/// </summary>
		private string GetFullName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ShaderVariation_GetFullName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ShaderVariation_HasParameter (IntPtr handle, int param);

		/// <summary>
		/// Return whether uses a parameter. Not applicable on OpenGL, where this information is contained in ShaderProgram instead.
		/// </summary>
		public bool HasParameter (StringHash param)
		{
			Runtime.ValidateRefCounted (this);
			return ShaderVariation_HasParameter (handle, param.Code);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ShaderVariation_HasTextureUnit (IntPtr handle, TextureUnit unit);

		/// <summary>
		/// Return whether uses a texture unit (only for pixel shaders). Not applicable on OpenGL, where this information is contained in ShaderProgram instead.
		/// </summary>
		public bool HasTextureUnit (TextureUnit unit)
		{
			Runtime.ValidateRefCounted (this);
			return ShaderVariation_HasTextureUnit (handle, unit);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ulong ShaderVariation_GetElementHash (IntPtr handle);

		/// <summary>
		/// Return vertex element hash.
		/// </summary>
		private ulong GetElementHash ()
		{
			Runtime.ValidateRefCounted (this);
			return ShaderVariation_GetElementHash (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_GetDefines (IntPtr handle);

		/// <summary>
		/// Return defines.
		/// </summary>
		private string GetDefines ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ShaderVariation_GetDefines (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_GetCompilerOutput (IntPtr handle);

		/// <summary>
		/// Return compile error/warning string.
		/// </summary>
		private string GetCompilerOutput ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ShaderVariation_GetCompilerOutput (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint* ShaderVariation_GetConstantBufferSizes (IntPtr handle);

		/// <summary>
		/// Return constant buffer data sizes.
		/// </summary>
		private uint* GetConstantBufferSizes ()
		{
			Runtime.ValidateRefCounted (this);
			return ShaderVariation_GetConstantBufferSizes (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ShaderVariation_GetDefinesClipPlane (IntPtr handle);

		/// <summary>
		/// Return defines with the CLIPPLANE define appended. Used internally on Direct3D11 only, will be empty on other APIs.
		/// </summary>
		private string GetDefinesClipPlane ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ShaderVariation_GetDefinesClipPlane (handle));
		}

		/// <summary>
		/// Return shader name.
		/// Or
		/// Set name.
		/// </summary>
		public string Name {
			get {
				return GetName ();
			}
			set {
				SetName (value);
			}
		}

		/// <summary>
		/// Return defines.
		/// Or
		/// Set defines.
		/// </summary>
		public string Defines {
			get {
				return GetDefines ();
			}
			set {
				SetDefines (value);
			}
		}

		/// <summary>
		/// Return the owner resource.
		/// </summary>
		public Shader Owner {
			get {
				return GetOwner ();
			}
		}

		/// <summary>
		/// Return shader type.
		/// </summary>
		public ShaderType ShaderType {
			get {
				return GetShaderType ();
			}
		}

		/// <summary>
		/// Return full shader name.
		/// </summary>
		public string FullName {
			get {
				return GetFullName ();
			}
		}

		/// <summary>
		/// Return vertex element hash.
		/// </summary>
		public ulong ElementHash {
			get {
				return GetElementHash ();
			}
		}

		/// <summary>
		/// Return compile error/warning string.
		/// </summary>
		public string CompilerOutput {
			get {
				return GetCompilerOutput ();
			}
		}

		/// <summary>
		/// Return constant buffer data sizes.
		/// </summary>
		public uint* ConstantBufferSizes {
			get {
				return GetConstantBufferSizes ();
			}
		}

		/// <summary>
		/// Return defines with the CLIPPLANE define appended. Used internally on Direct3D11 only, will be empty on other APIs.
		/// </summary>
		public string DefinesClipPlane {
			get {
				return GetDefinesClipPlane ();
			}
		}
	}
}
