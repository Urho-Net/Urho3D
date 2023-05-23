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
    /// Skeletal animation resource.
    /// </summary>
    public unsafe partial class Animation : ResourceWithMetadata
    {
        public AnimationTrackWrapper CreateTrackSafe(string name)
        {
            Runtime.ValidateObject(this);
            unsafe
            {
                AnimationTrack* result = CreateTrack(name);
                if (result == null)
                    return null;
                return new AnimationTrackWrapper(this, result);
            }
        }

        public AnimationTrackWrapper GetTrackSafe(uint index)
        {
            Runtime.ValidateObject(this);
            unsafe
            {
                AnimationTrack* result = GetTrack(index);
                if (result == null)
                    return null;
                return new AnimationTrackWrapper(this, result);
            }
        }

        public AnimationTrackWrapper GetTrackSafe(StringHash nameHash)
        {
            Runtime.ValidateObject(this);
            unsafe
            {
                AnimationTrack* result = GetTrack(nameHash);
                if (result == null)
                    return null;
                return new AnimationTrackWrapper(this, result);
            }
        }

        public AnimationTrackWrapper GetTrackSafe(string name)
        {
            Runtime.ValidateObject(this);
            unsafe
            {
                AnimationTrack* result = GetTrack(name);
                if (result == null)
                    return null;
                return new AnimationTrackWrapper(this, result);
            }
        }

    }

}