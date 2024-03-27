// WARNING - AUTOGENERATED - DO NOT EDIT
// 
// Sound.cs
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

namespace Urho.Audio
{
	/// <summary>
	/// %Sound resource.
	/// </summary>
	public unsafe partial class Sound : ResourceWithMetadata
	{
		unsafe partial void OnSoundCreated ();

		[Preserve]
		public Sound (IntPtr handle) : base (handle)
		{
			OnSoundCreated ();
		}

		[Preserve]
		protected Sound (UrhoObjectFlag emptyFlag) : base (emptyFlag)
		{
			OnSoundCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Sound_GetType (IntPtr handle);

		private StringHash UrhoGetType ()
		{
			Runtime.ValidateRefCounted (this);
			return new StringHash (Sound_GetType (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sound_GetTypeName (IntPtr handle);

		private string GetTypeName ()
		{
			Runtime.ValidateRefCounted (this);
			return Marshal.PtrToStringAnsi (Sound_GetTypeName (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern int Sound_GetTypeStatic ();

		private static StringHash GetTypeStatic ()
		{
			Runtime.Validate (typeof(Sound));
			return new StringHash (Sound_GetTypeStatic ());
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sound_GetTypeNameStatic ();

		private static string GetTypeNameStatic ()
		{
			Runtime.Validate (typeof(Sound));
			return Marshal.PtrToStringAnsi (Sound_GetTypeNameStatic ());
		}

		[Preserve]
		public Sound () : this (Application.CurrentContext)
		{
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sound_Sound (IntPtr context);

		[Preserve]
		public Sound (Context context) : base (UrhoObjectFlag.Empty)
		{
			Runtime.Validate (typeof(Sound));
			handle = Sound_Sound ((object)context == null ? IntPtr.Zero : context.Handle);
			Runtime.RegisterObject (this);
			OnSoundCreated ();
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_RegisterObject (IntPtr context);

		/// <summary>
		/// Register object factory.
		/// 
		/// </summary>
		public static void RegisterObject (Context context)
		{
			Runtime.Validate (typeof(Sound));
			Sound_RegisterObject ((object)context == null ? IntPtr.Zero : context.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_BeginLoad_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_BeginLoad_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_BeginLoad_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load resource from stream. May be called from a worker thread. Return true if successful.
		/// </summary>
		public override bool BeginLoad (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_BeginLoad_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_LoadRaw_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load raw sound data.
		/// </summary>
		public bool LoadRaw (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_LoadRaw_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_LoadRaw_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load raw sound data.
		/// </summary>
		public bool LoadRaw (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_LoadRaw_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_LoadWav_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load WAV format sound data.
		/// </summary>
		public bool LoadWav (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_LoadWav_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_LoadWav_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load WAV format sound data.
		/// </summary>
		public bool LoadWav (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_LoadWav_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_LoadOggVorbis_File (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load Ogg Vorbis format sound data. Does not decode at load, but will rather be decoded while playing.
		/// </summary>
		public bool LoadOggVorbis (File source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_LoadOggVorbis_File (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_LoadOggVorbis_MemoryBuffer (IntPtr handle, IntPtr source);

		/// <summary>
		/// Load Ogg Vorbis format sound data. Does not decode at load, but will rather be decoded while playing.
		/// </summary>
		public bool LoadOggVorbis (MemoryBuffer source)
		{
			Runtime.ValidateRefCounted (this);
			return Sound_LoadOggVorbis_MemoryBuffer (handle, (object)source == null ? IntPtr.Zero : source.Handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_SetSize (IntPtr handle, uint dataSize);

		/// <summary>
		/// Set sound size in bytes. Also resets the sound to be uncompressed and one-shot.
		/// </summary>
		public void SetSize (uint dataSize)
		{
			Runtime.ValidateRefCounted (this);
			Sound_SetSize (handle, dataSize);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_SetData (IntPtr handle, void* data, uint dataSize);

		/// <summary>
		/// Set uncompressed sound data.
		/// </summary>
		public void SetData (void* data, uint dataSize)
		{
			Runtime.ValidateRefCounted (this);
			Sound_SetData (handle, data, dataSize);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_SetFormat (IntPtr handle, uint frequency, bool sixteenBit, bool stereo);

		/// <summary>
		/// Set uncompressed sound data format.
		/// </summary>
		public void SetFormat (uint frequency, bool sixteenBit, bool stereo)
		{
			Runtime.ValidateRefCounted (this);
			Sound_SetFormat (handle, frequency, sixteenBit, stereo);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_SetLooped (IntPtr handle, bool enable);

		/// <summary>
		/// Set loop on/off. If loop is enabled, sets the full sound as loop range.
		/// 
		/// </summary>
		private void SetLooped (bool enable)
		{
			Runtime.ValidateRefCounted (this);
			Sound_SetLooped (handle, enable);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_SetLoop (IntPtr handle, uint repeatOffset, uint endOffset);

		/// <summary>
		/// Define loop.
		/// </summary>
		public void SetLoop (uint repeatOffset, uint endOffset)
		{
			Runtime.ValidateRefCounted (this);
			Sound_SetLoop (handle, repeatOffset, endOffset);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern IntPtr Sound_GetDecoderStream (IntPtr handle);

		/// <summary>
		/// Return a new instance of a decoder sound stream. Used by compressed sounds.
		/// </summary>
		private SoundStream GetDecoderStream ()
		{
			Runtime.ValidateRefCounted (this);
			return Runtime.LookupRefCounted<SoundStream> (Sound_GetDecoderStream (handle));
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern sbyte* Sound_GetStart (IntPtr handle);

		/// <summary>
		/// Return sound data start.
		/// </summary>
		private sbyte* GetStart ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetStart (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern sbyte* Sound_GetRepeat (IntPtr handle);

		/// <summary>
		/// Return loop start.
		/// </summary>
		private sbyte* GetRepeat ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetRepeat (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern sbyte* Sound_GetEnd (IntPtr handle);

		/// <summary>
		/// Return sound data end.
		/// </summary>
		private sbyte* GetEnd ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetEnd (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Sound_GetLength (IntPtr handle);

		/// <summary>
		/// Return length in seconds.
		/// 
		/// </summary>
		private float GetLength ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetLength (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Sound_GetDataSize (IntPtr handle);

		/// <summary>
		/// Return total sound data size.
		/// </summary>
		private uint GetDataSize ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetDataSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Sound_GetSampleSize (IntPtr handle);

		/// <summary>
		/// Return sample size.
		/// 
		/// </summary>
		private uint GetSampleSize ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetSampleSize (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern float Sound_GetFrequency (IntPtr handle);

		/// <summary>
		/// Return default frequency as a float.
		/// 
		/// </summary>
		private float GetFrequency ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetFrequency (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern uint Sound_GetIntFrequency (IntPtr handle);

		/// <summary>
		/// Return default frequency as an integer.
		/// </summary>
		private uint GetIntFrequency ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_GetIntFrequency (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_IsLooped (IntPtr handle);

		/// <summary>
		/// Return whether is looped.
		/// 
		/// </summary>
		private bool IsLooped ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_IsLooped (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_IsSixteenBit (IntPtr handle);

		/// <summary>
		/// Return whether data is sixteen bit.
		/// 
		/// </summary>
		private bool IsSixteenBit ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_IsSixteenBit (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_IsStereo (IntPtr handle);

		/// <summary>
		/// Return whether data is stereo.
		/// 
		/// </summary>
		private bool IsStereo ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_IsStereo (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern bool Sound_IsCompressed (IntPtr handle);

		/// <summary>
		/// Return whether is compressed.
		/// 
		/// </summary>
		private bool IsCompressed ()
		{
			Runtime.ValidateRefCounted (this);
			return Sound_IsCompressed (handle);
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Sound_FixInterpolation (IntPtr handle);

		/// <summary>
		/// Fix interpolation by copying data from loop start to loop end (looped), or adding silence (oneshot). Called internally, does not normally need to be called, unless the sound data is modified manually on the fly.
		/// </summary>
		public void FixInterpolation ()
		{
			Runtime.ValidateRefCounted (this);
			Sound_FixInterpolation (handle);
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
		/// Return whether is looped.
		/// 
		/// Or
		/// Set loop on/off. If loop is enabled, sets the full sound as loop range.
		/// 
		/// </summary>
		public bool Looped {
			get {
				return IsLooped ();
			}
			set {
				SetLooped (value);
			}
		}

		/// <summary>
		/// Return a new instance of a decoder sound stream. Used by compressed sounds.
		/// </summary>
		public SoundStream DecoderStream {
			get {
				return GetDecoderStream ();
			}
		}

		/// <summary>
		/// Return sound data start.
		/// </summary>
		public sbyte* Start {
			get {
				return GetStart ();
			}
		}

		/// <summary>
		/// Return loop start.
		/// </summary>
		public sbyte* Repeat {
			get {
				return GetRepeat ();
			}
		}

		/// <summary>
		/// Return sound data end.
		/// </summary>
		public sbyte* End {
			get {
				return GetEnd ();
			}
		}

		/// <summary>
		/// Return length in seconds.
		/// 
		/// </summary>
		public float Length {
			get {
				return GetLength ();
			}
		}

		/// <summary>
		/// Return total sound data size.
		/// </summary>
		public uint DataSize {
			get {
				return GetDataSize ();
			}
		}

		/// <summary>
		/// Return sample size.
		/// 
		/// </summary>
		public uint SampleSize {
			get {
				return GetSampleSize ();
			}
		}

		/// <summary>
		/// Return default frequency as a float.
		/// 
		/// </summary>
		public float Frequency {
			get {
				return GetFrequency ();
			}
		}

		/// <summary>
		/// Return default frequency as an integer.
		/// </summary>
		public uint IntFrequency {
			get {
				return GetIntFrequency ();
			}
		}

		/// <summary>
		/// Return whether data is sixteen bit.
		/// 
		/// </summary>
		public bool SixteenBit {
			get {
				return IsSixteenBit ();
			}
		}

		/// <summary>
		/// Return whether data is stereo.
		/// 
		/// </summary>
		public bool Stereo {
			get {
				return IsStereo ();
			}
		}

		/// <summary>
		/// Return whether is compressed.
		/// 
		/// </summary>
		public bool Compressed {
			get {
				return IsCompressed ();
			}
		}
	}
}
