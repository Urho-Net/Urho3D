// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// ParticleEmitter.cs
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
using File = Urho.IO.File;

namespace Urho
{
	/// <summary>
	/// %Particle emitter component.
	/// </summary>
	public unsafe partial class ParticleEmitter : BillboardSet
	{
		unsafe partial void OnParticleEmitterCreated ();

		[Preserve]
		public ParticleEmitter (IntPtr handle) : base (handle)
		{
			OnParticleEmitterCreated ();
		}

		[Preserve]
		protected ParticleEmitter (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnParticleEmitterCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ParticleEmitter_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (ParticleEmitter_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ParticleEmitter_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (ParticleEmitter_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int ParticleEmitter_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(ParticleEmitter));
			return new StringHash (ParticleEmitter_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ParticleEmitter_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(ParticleEmitter));
			return Marshal.PtrToStringAnsi (ParticleEmitter_GetTypeNameStatic ());
		}

		[Preserve]
		public ParticleEmitter () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ParticleEmitter_ParticleEmitter (IntPtr context);

		[Preserve]
		public ParticleEmitter (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(ParticleEmitter));
			handle = ParticleEmitter_ParticleEmitter ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnParticleEmitterCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public new static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(ParticleEmitter));
			ParticleEmitter_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_OnSetEnabled (IntPtr handle);

		/// <summary>
		/// Handle enabled/disabled state change.
		/// </summary>
		public override void OnSetEnabled ()
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_OnSetEnabled (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_SetEffect (IntPtr handle, IntPtr effect);

		/// <summary>
		/// Set particle effect.
		/// 
		/// </summary>
		private void SetEffect (ParticleEffect effect)
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_SetEffect (handle, (object)effect == null ? IntPtr.Zero : effect.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_SetNumParticles (IntPtr handle, uint num);

		/// <summary>
		/// Set maximum number of particles.
		/// 
		/// </summary>
		private void SetNumParticles (uint num)
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_SetNumParticles (handle, num);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_SetEmitting (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether should be emitting. If the state was changed, also resets the emission period timer.
		/// 
		/// </summary>
		private void SetEmitting (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_SetEmitting (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_SetSerializeParticles (IntPtr handle, bool enable);

		/// <summary>
		/// Set whether particles should be serialized. Default true, set false to reduce scene file size.
		/// 
		/// </summary>
		private void SetSerializeParticles (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_SetSerializeParticles (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_SetAutoRemoveMode (IntPtr handle, AutoRemoveMode mode);

		/// <summary>
		/// Set to remove either the emitter component or its owner node from the scene automatically on particle effect completion. Disabled by default.
		/// 
		/// </summary>
		private void SetAutoRemoveMode (AutoRemoveMode mode)
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_SetAutoRemoveMode (handle, mode);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_ResetEmissionTimer (IntPtr handle);

		/// <summary>
		/// Reset the emission period timer.
		/// </summary>
		public void ResetEmissionTimer ()
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_ResetEmissionTimer (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_RemoveAllParticles (IntPtr handle);

		/// <summary>
		/// Remove all current particles.
		/// </summary>
		public void RemoveAllParticles ()
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_RemoveAllParticles (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_Reset (IntPtr handle);

		/// <summary>
		/// Reset the particle emitter completely. Removes current particles, sets emitting state on, and resets the emission timer.
		/// </summary>
		public void Reset ()
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_Reset (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void ParticleEmitter_ApplyEffect (IntPtr handle);

		/// <summary>
		/// Apply not continuously updated values such as the material, the number of particles and sorting mode from the particle effect. Call this if you change the effect programmatically.
		/// </summary>
		public void ApplyEffect ()
		{
			Runtime.ValidateRefCounted (this);
			ParticleEmitter_ApplyEffect (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr ParticleEmitter_GetEffect (IntPtr handle);

		/// <summary>
		/// Return particle effect.
		/// 
		/// </summary>
		private ParticleEffect GetEffect ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupObject<ParticleEffect> (ParticleEmitter_GetEffect (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint ParticleEmitter_GetNumParticles (IntPtr handle);

		/// <summary>
		/// Return maximum number of particles.
		/// 
		/// </summary>
		private uint GetNumParticles ()
		{
			Runtime.ValidateRefCounted (this);
			return ParticleEmitter_GetNumParticles (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ParticleEmitter_IsEmitting (IntPtr handle);

		/// <summary>
		/// Return whether is currently emitting.
		/// 
		/// </summary>
		private bool IsEmitting ()
		{
			Runtime.ValidateRefCounted (this);
			return ParticleEmitter_IsEmitting (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool ParticleEmitter_GetSerializeParticles (IntPtr handle);

		/// <summary>
		/// Return whether particles are to be serialized.
		/// 
		/// </summary>
		private bool GetSerializeParticles ()
		{
			Runtime.ValidateRefCounted (this);
			return ParticleEmitter_GetSerializeParticles (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern AutoRemoveMode ParticleEmitter_GetAutoRemoveMode (IntPtr handle);

		/// <summary>
		/// Return automatic removal mode on particle effect completion.
		/// 
		/// </summary>
		private AutoRemoveMode GetAutoRemoveMode ()
		{
			Runtime.ValidateRefCounted (this);
			return ParticleEmitter_GetAutoRemoveMode (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern ResourceRef ParticleEmitter_GetEffectAttr (IntPtr handle);

		/// <summary>
		/// Set particles effect attribute.
		/// </summary>
		private ResourceRef GetEffectAttr ()
		{
			Runtime.ValidateRefCounted (this);
			return ParticleEmitter_GetEffectAttr (handle);
		}

		public override StringHash Type {
			get {
				return UrhoGetType ();
			}
		}

		public override string TypeName {
			get {
				return GetTypeName ();
			}
		}

		[Preserve]
		public new static StringHash TypeStatic {
			get {
				return GetTypeStatic ();
			}
		}

		public new static string TypeNameStatic {
			get {
				return GetTypeNameStatic ();
			}
		}

		/// <summary>
		/// Return particle effect.
		/// 
		/// Or
		/// Set particle effect.
		/// 
		/// </summary>
		public ParticleEffect Effect {
			get {
				return GetEffect ();
			}
			set {
				SetEffect (value);
			}
		}

		/// <summary>
		/// Return maximum number of particles.
		/// 
		/// Or
		/// Set maximum number of particles.
		/// 
		/// </summary>
		public uint NumParticles {
			get {
				return GetNumParticles ();
			}
			set {
				SetNumParticles (value);
			}
		}

		/// <summary>
		/// Return whether is currently emitting.
		/// 
		/// Or
		/// Set whether should be emitting. If the state was changed, also resets the emission period timer.
		/// 
		/// </summary>
		public bool Emitting {
			get {
				return IsEmitting ();
			}
			set {
				SetEmitting (value);
			}
		}

		/// <summary>
		/// Return whether particles are to be serialized.
		/// 
		/// Or
		/// Set whether particles should be serialized. Default true, set false to reduce scene file size.
		/// 
		/// </summary>
		public bool SerializeParticles {
			get {
				return GetSerializeParticles ();
			}
			set {
				SetSerializeParticles (value);
			}
		}

		/// <summary>
		/// Return automatic removal mode on particle effect completion.
		/// 
		/// Or
		/// Set to remove either the emitter component or its owner node from the scene automatically on particle effect completion. Disabled by default.
		/// 
		/// </summary>
		public AutoRemoveMode AutoRemoveMode {
			get {
				return GetAutoRemoveMode ();
			}
			set {
				SetAutoRemoveMode (value);
			}
		}

		/// <summary>
		/// Set particles effect attribute.
		/// </summary>
		public ResourceRef EffectAttr {
			get {
				return GetEffectAttr ();
			}
		}
	}
}
