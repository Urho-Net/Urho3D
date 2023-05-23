using System;
using System.Runtime.InteropServices;
using Urho.Audio;
using Urho.Navigation;
using Urho.Physics;
using Urho.Urho2D;
using Urho.Resources;
using Urho.Gui;
using Urho.Network;
using System.Collections.Generic;

namespace Urho
{

    /// <summary>
    /// Helper functions to return elements from a VariantMap
    /// </summary>
    public unsafe class EventDataContainer
    {
        public IntPtr Handle { get; private set; } = IntPtr.Zero;
        private bool isManaged = false;
        private bool disposed = false;
        public EventDataContainer()
        {
            Handle = VariantMap_VariantMap();
            isManaged = true;
            disposed = false;
        }
        public EventDataContainer(IntPtr handle)
        {
            Handle = handle;
            isManaged = false;
            disposed = false;
        }

        public int Count
        {
            get
            {
                if (Handle != IntPtr.Zero)
                    return (int)urho_map_get_keys_size(Handle);
                else
                    return 0;
            }
        }
        public List<StringHash> Keys
        {
            get
            {
                List<StringHash> keys = new List<StringHash>();

                if (Handle != IntPtr.Zero)
                {
                    if (Count > 0)
                    {
                        IntPtr pnt = Marshal.AllocHGlobal(sizeof(uint) * Count);
                        urho_map_keys_get_keys(Handle, (uint*)pnt);
                        for (int i = 0; i < Count; i++)
                        {
                            keys.Add(new StringHash((int)((uint*)pnt)[i]));
                        }
                        Marshal.FreeHGlobal(pnt);
                    }
                }

                return keys;
            }
        }

        public uint GetKey(int index)
        {
            return urho_map_keys_get_key(Handle, index);
        }

        public void Dispose()
        {
            if (isManaged == true)
            {
                if (disposed == false)
                {
                    disposed = true;
                    VariantMap_Dispose(Handle);
                    //	GC.SuppressFinalize(this);
                }
            }
        }

        ~EventDataContainer()
        {
            Dispose();
        }

        public bool Erase(string key)
        {
            return VariantMap_Erase(Handle, key);
        }

        public bool Erase(StringHash key)
        {
            return VariantMap_Erase2(Handle, key.Code);
        }


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr VariantMap_VariantMap();

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void VariantMap_Dispose(IntPtr variantMap);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern bool VariantMap_Erase(IntPtr handle, string key);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern bool VariantMap_Erase2(IntPtr handle, int paramNameHash);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr urho_map_get_variantmap(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr urho_map_get_ptr(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr urho_map_get_buffer(IntPtr handle, int paramNameHash, out int size);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr urho_map_get_String(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern int urho_map_get_StringHash(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern bool urho_map_get_bool(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern int urho_map_get_int(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern float urho_map_get_float(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern uint urho_map_get_uint(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
		static extern Vector3 * urho_map_get_Vector3(IntPtr handle, int paramNameHash);
#else
        static extern Vector3 urho_map_get_Vector3(IntPtr handle, int paramNameHash);
#endif

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
		static extern IntVector2 * urho_map_get_IntVector2(IntPtr handle, int paramNameHash);
#else
        static extern IntVector2 urho_map_get_IntVector2(IntPtr handle, int paramNameHash);
#endif

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
		static extern Variant * urho_map_get_Variant(IntPtr handle, int paramNameHash);
#else
        static extern Variant urho_map_get_Variant(IntPtr handle, int paramNameHash);
#endif

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool urho_map_contains_value(IntPtr handle, int paramNameHash);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void urho_map_get_value(IntPtr handle, int paramNameHash, out Variant value);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void urho_map_set_value(IntPtr handle, int paramNameHash, ref Variant value);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void urho_map_set_value_ptr(IntPtr handle, int paramNameHash, IntPtr value);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint urho_map_get_keys_size(IntPtr handle);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint urho_map_keys_get_key(IntPtr handle, int index);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void urho_map_keys_get_keys(IntPtr handle, uint* buffer);

        public T get_Object<T>(int paramNameHash) where T : UrhoObject
        {
            return Runtime.LookupObject<T>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public T get_Object<T>(string paramName) where T : UrhoObject
        {
            return Runtime.LookupObject<T>(urho_map_get_ptr(Handle, new StringHash(paramName).Code));
        }

        public SoundSource get_SoundSource(int paramNameHash)
        {
            return Runtime.LookupObject<SoundSource>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Sound get_Sound(int paramNameHash)
        {
            return Runtime.LookupObject<Sound>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Animation get_Animation(int paramNameHash)
        {
            return Runtime.LookupObject<Animation>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public ParticleEffect get_ParticleEffect(int paramNameHash)
        {
            return Runtime.LookupObject<ParticleEffect>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Camera get_Camera(int paramNameHash)
        {
            return Runtime.LookupObject<Camera>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Component get_Component(int paramNameHash)
        {
            return Runtime.LookupObject<Component>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Connection get_Connection(int paramNameHash)
        {
            return Runtime.LookupObject<Connection>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public CrowdAgent get_CrowdAgent(int paramNameHash)
        {
            return Runtime.LookupObject<CrowdAgent>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public IntPtr get_IntPtr(int paramNameHash)
        {
            return urho_map_get_ptr(Handle, paramNameHash);
        }

        public MouseMode get_MouseMode(int paramNameHash)
        {
            return (MouseMode)urho_map_get_int(Handle, paramNameHash);
        }

        public NavigationMesh get_NavigationMesh(int paramNameHash)
        {
            return Runtime.LookupObject<NavigationMesh>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Node get_Node(int paramNameHash)
        {
            return Runtime.LookupObject<Node>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public UrhoObject get_Object(int paramNameHash)
        {
            return Runtime.LookupObject<UrhoObject>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Obstacle get_Obstacle(int paramNameHash)
        {
            return Runtime.LookupObject<Obstacle>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public PhysicsWorld get_PhysicsWorld(int paramNameHash)
        {
            return Runtime.LookupObject<PhysicsWorld>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public PhysicsWorld2D get_PhysicsWorld2D(int paramNameHash)
        {
            return Runtime.LookupObject<PhysicsWorld2D>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public RenderSurface get_RenderSurface(int paramNameHash)
        {
            var ptr = urho_map_get_ptr(Handle, paramNameHash);
            return ptr == IntPtr.Zero ? null : new RenderSurface(ptr);
        }

        public Resource get_Resource(int paramNameHash)
        {
            return Runtime.LookupObject<Resource>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public RigidBody get_RigidBody(int paramNameHash)
        {
            return Runtime.LookupObject<RigidBody>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public RigidBody2D get_RigidBody2D(int paramNameHash)
        {
            return Runtime.LookupObject<RigidBody2D>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Scene get_Scene(int paramNameHash)
        {
            return Runtime.LookupObject<Scene>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public CollisionShape2D get_CollisionShape2D(int paramNameHash)
        {
            return Runtime.LookupObject<CollisionShape2D>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public ParticleEffect2D get_ParticleEffect2D(int paramNameHash)
        {
            return Runtime.LookupObject<ParticleEffect2D>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public VGElement get_VGElement(int paramNameHash)
        {
            return Runtime.LookupObject<VGElement>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public VGFrameBuffer get_VGFrameBuffer(int paramNameHash)
        {
            return Runtime.LookupObject<VGFrameBuffer>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Serializable get_Serializable(int paramNameHash)
        {
            throw new Exception("Not implemented, as we need to figure out serializable mapping");
        }

        public CollisionData[] get_CollisionData(int paramNameHash)
        {
            int size;
            var buffer = urho_map_get_buffer(Handle, paramNameHash, out size);
            return CollisionData.FromContactData(buffer, size);
        }

        public byte[] get_Buffer(int paramNameHash)
        {
            int size;
            var buffer = urho_map_get_buffer(Handle, paramNameHash, out size);
            var bytes = new byte[size];
            Marshal.Copy(buffer, bytes, 0, size);
            return bytes;
        }

        public string get_String(int paramNameHash)
        {
            IntPtr native_string = urho_map_get_String(Handle, paramNameHash);
            string managed_string = Marshal.PtrToStringAnsi(native_string);
            return managed_string;

            // Memory leak	return Marshal.PtrToStringAnsi(urho_map_get_String (Handle, paramNameHash));
        }

        public StringHash get_StringHash(int paramNameHash)
        {
            return new StringHash(urho_map_get_StringHash(Handle, paramNameHash));
        }

        public Texture get_Texture(int paramNameHash)
        {
            return Runtime.LookupObject<Texture>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public Variant get_Variant(int paramNameHash)
        {
#if __WEB__
			return *urho_map_get_Variant (Handle, paramNameHash);
#else
            return urho_map_get_Variant(Handle, paramNameHash);
#endif
        }

        public Vector3 get_Vector3(int paramNameHash)
        {
#if __WEB__
			return *urho_map_get_Vector3 (Handle, paramNameHash);
#else
            return urho_map_get_Vector3(Handle, paramNameHash);
#endif
        }

        public IntVector2 get_IntVector2(int paramNameHash)
        {
#if __WEB__
			return *urho_map_get_IntVector2(Handle, paramNameHash);
#else
            return urho_map_get_IntVector2(Handle, paramNameHash);
#endif
        }

        public View get_View(int paramNameHash)
        {
            var ptr = urho_map_get_ptr(Handle, paramNameHash);
            return ptr == IntPtr.Zero ? null : new View(ptr);
        }

        public UIElement get_UIElement(int paramNameHash)
        {
            return Runtime.LookupObject<UIElement>(urho_map_get_ptr(Handle, paramNameHash));
        }

        public WorkItem get_WorkItem(int paramNameHash)
        {
            return new WorkItem(urho_map_get_ptr(Handle, paramNameHash));
        }

        public bool get_bool(int paramNameHash)
        {
            return urho_map_get_bool(Handle, paramNameHash);
        }

        public float get_float(int paramNameHash)
        {
            return urho_map_get_float(Handle, paramNameHash);
        }

        public int get_int(int paramNameHash)
        {
            return urho_map_get_int(Handle, paramNameHash);
        }

        public uint get_uint(int paramNameHash)
        {
            return urho_map_get_uint(Handle, paramNameHash);
        }

        public EventDataContainer get_EventDataContainer(int paramNameHash)
        {
            IntPtr ptr = urho_map_get_variantmap(Handle, paramNameHash);
            return new EventDataContainer(ptr);
        }

    }
}
