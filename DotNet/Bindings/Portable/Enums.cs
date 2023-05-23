using System;

namespace Urho
{
    [Flags]
    public enum ViewOverrideFlags
    {
        None = 0,
        LowMaterialQuality = 1,
        DisableShadows = 2,
        DisableOcclusion = 4
    }

    public enum LogLevel
    {
        Raw = -1,
        Debug = 1,
        Info = 2,
        Warning = 3,
        Error = 4,
        None = 5
    }

    [Flags]
    public enum ElementMask : uint
    {
        None = 0x0,
        Position = 0x1,
        Normal = 0x2,
        Color = 0x4,
        TexCoord1 = 0x8,
        TexCoord2 = 0x10,
        CubeTexCoord1 = 0x20,
        CubeTexCoord2 = 0x40,
        Tangent = 0x80,
        BlendWeights = 0x100,
        BlendIndices = 0x200,
        InstanceMatrix1 = 0x400,
        InstanceMatrix2 = 0x800,
        InstanceMatrix3 = 0x1000,
        Default = 0xffffffff,
    }

    public enum SoundType
    {
        Master,
        Effect,
        Ambient,
        Voice,
        Music
    }

    public enum DrawableFlags : uint
    {
        Geometry = 0x1,
        Light = 0x2,
        Zone = 0x4,
        Geometry2D = 0x8,
        Any = 0xff,
    }

    public enum Platforms
    {
        Unknown,
        Android,
        iOS,
        tvOS,
        Windows,
        MacOSX,
        Linux,
        UWP,
        SharpReality,
        Web,
        RPI
    }

    public static class Protocol
    {
        /// Client->server: send VariantMap of identity and authentication data.
        public const int msg_identity = 0x87;
        /// client->server: send controls (buttons and mouse movement).
        public const int msg_controls = 0x88;
        /// client->server: scene has been loaded and client is ready to proceed.
        public const int msg_sceneloaded = 0x89;
        /// client->server: request a package file.
        public const int msg_requestpackage = 0x8a;

        /// server->client: package file data fragment.
        public const int msg_packagedata = 0x8b;
        /// server->client: load new scene. in case of empty filename the client should just empty the scene.
        public const int msg_loadscene = 0x8c;
        /// server->client: wrong scene checksum, can not participate.
        public const int msg_scenechecksumerror = 0x8d;
        /// server->client: create new node.
        public const int msg_createnode = 0x8e;
        /// server->client: node delta update.
        public const int msg_nodedeltaupdate = 0x8f;
        /// server->client: node latest data update.
        public const int msg_nodelatestdata = 0x90;
        /// server->client: remove node.
        public const int msg_removenode = 0x91;
        /// server->client: create new component.
        public const int msg_createcomponent = 0x92;
        /// server->client: component delta update.
        public const int msg_componentdeltaupdate = 0x93;
        /// server->client: component latest data update.
        public const int msg_componentlatestdata = 0x94;
        /// server->client: remove component.
        public const int msg_removecomponent = 0x95;

        /// client->server and server->client: remote event.
        public const int msg_remoteevent = 0x96;
        /// client->server and server->client: remote node event.
        public const int msg_remotenodeevent = 0x97;
        /// server->client: info about package.
        public const int msg_packageinfo = 0x98;

        /// packet that includes all the above messages
        public const int msg_packed_message = 0x99;

        /// used to define custom messages, usually of the form msg_user + x, where x is an integer value.
        public const int msg_user = 0x200;

        /// fixed content id for client controls update.
        public const uint controls_content_id = 1;
        /// package file fragment size.
        public const uint package_fragment_size = 1024;
    }

    public static class PlatformsExtensions
    {
        public static bool IsMobile(this Platforms platform)
        {
            return
                platform != Platforms.Windows &&
                platform != Platforms.Linux &&
                platform != Platforms.MacOSX;
        }
    }

    internal static class PlatformsMap
    {
        public static Platforms FromString(string str)
        {
            switch (str)
            {
                // ProcessUtils.cpp:L349
                case "Android": return Platforms.Android;
                case "iOS": return Platforms.iOS;
                case "tvOS": return Platforms.tvOS;
                case "Windows": return Platforms.Windows;
                case "macOS": return Platforms.MacOSX;
                case "Linux": return Platforms.Linux;
                case "Raspberry Pi": return Platforms.RPI;
                case "Web": return Platforms.Web;
            }
#if UWP_HOLO
			return Platforms.SharpReality;
#elif WINDOWS_UWP
			return Platforms.UWP;
#endif
            return Platforms.Unknown;
        }
    }

    internal enum CallbackType
    {
        Component_OnSceneSet,
        Component_SaveXml,
        Component_LoadXml,
        Component_AttachedToNode,
        Component_OnNodeSetEnabled,

        RefCounted_AddRef,
        RefCounted_Delete,

        Log_Write,

        Serializable_LoadXml,
        VGElement_Render,
        Component_Clone,
        Component_Serialize,
        Serializable_Load,
        Drawable2D_UpdateSourceBatches,
        StaticSprite2D_OnWorldBoundingBoxUpdate
    };

}
