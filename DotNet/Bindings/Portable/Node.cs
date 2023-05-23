//
// Node C# sugar
//
// Authors:
//   Miguel de Icaza (miguel@xamarin.com)
//
// Copyrigh 2015 Xamarin INc
//
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Reflection;
using Urho.IO;

namespace Urho
{

    internal partial class NodeHelper
    {
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal extern static IntPtr urho_node_get_components(IntPtr node, int code, int recursive, out int count);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal extern static IntPtr Node_GetChildrenWithTag(IntPtr node, string tag, int recursive, out int count);
    }

    public partial class Node
    {
        static Node[] ZeroArray = new Node[0];

        /// <summary>
        /// Remove from the parent node. If no other shared pointer references exist, causes immediate deletion.
        /// </summary>
        public void Remove()
        {
            RemoveAllActions(); // TBD ELI , should remove all actions prior of deletion
            Runtime.ValidateRefCounted(this);
            Node_Remove(handle);
        }

        private void GetChildrenWithManagedComponent(Node parent, System.Type type, bool recursive, ref List<Node> children)
        {
            if (parent == null) return;

            foreach (Node node in parent.Children)
            {
                var components = node.Components;
                foreach (Component component in components)
                {
                    if (component.GetType() == type)
                    {
                        children.Add(node);
                    }
                }

                if (recursive == true)
                {
                    GetChildrenWithManagedComponent(node, type, recursive, ref children);
                }
            }
        }

        public Node[] GetChildrenWithComponent<T>(bool recursive = false) where T : Component
        {
            Runtime.ValidateRefCounted(this);

            // This is a managed component so don't search it in Urho3D native
            // TBD ELI , This soultion needs some optimization
            if (Component.IsDefinedInManagedCode<T>())
            {
                List<Node> children = new List<Node>();
                GetChildrenWithManagedComponent(this, typeof(T), recursive, ref children);
                return children.ToArray();
            }

            var stringhash = Runtime.LookupStringHash(typeof(T));
            int count;
            var ptr = NodeHelper.urho_node_get_components(handle, stringhash.Code, recursive ? 1 : 0, out count);
            if (ptr == IntPtr.Zero)
                return ZeroArray;

            var res = new Node[count];
            for (int i = 0; i < count; i++)
            {
                var node = Marshal.ReadIntPtr(ptr, i * IntPtr.Size);
                res[i] = Runtime.LookupObject<Node>(node);
            }
            if (Component.IsDefinedInManagedCode<T>())
                //is not really efficient, but underlying Urho3D knows nothing about components defined in C#
                return res.Where(c => c.GetComponent<T>() != null).ToArray();
            return res;
        }

        public Node[] GetChildrenWithTag(string tag, bool recursive = false)
        {
            Runtime.ValidateRefCounted(this);
            int count;
            var ptr = NodeHelper.Node_GetChildrenWithTag(handle, tag, recursive ? 1 : 0, out count);
            if (ptr == IntPtr.Zero)
                return ZeroArray;

            var res = new Node[count];
            for (int i = 0; i < count; i++)
            {
                var node = Marshal.ReadIntPtr(ptr, i * IntPtr.Size);
                res[i] = Runtime.LookupObject<Node>(node);
            }

            return res;
        }

        public T CreateComponent<T>(StringHash type, CreateMode mode = CreateMode.Replicated, uint id = 0) where T : Component
        {
            Runtime.ValidateRefCounted(this);
            var ptr = Node_CreateComponent(handle, type.Code, mode, id);
            return Runtime.LookupObject<T>(ptr);
        }

        public void RemoveComponent<T>()
        {
            Runtime.ValidateRefCounted(this);
            var stringHash = Runtime.LookupStringHash(typeof(T));
            RemoveComponent(stringHash);
        }


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void Node_RemoveComponent22(IntPtr handle, IntPtr component);

        /// <summary>
        /// Remove a component from this node.
        /// </summary>
        public void RemoveComponent(Component component)
        {
            Runtime.ValidateRefCounted(this);
            component.UnSubscribeFromAllEvents();
            component.Remove();
        }

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
#if __WEB__
		unsafe internal static extern Variant * Node_GetVar (IntPtr handle, int key);
#else
        internal static extern Variant Node_GetVar(IntPtr handle, int key);
#endif

        unsafe public Variant GetVar(StringHash key)
        {
            Runtime.ValidateRefCounted(this);
#if __WEB__
			return *Node_GetVar (handle, key.Code);
#else
            return Node_GetVar(handle, key.Code);
#endif
        }

        unsafe public Variant GetVar(int key)
        {
            Runtime.ValidateRefCounted(this);
#if __WEB__
			return *Node_GetVar (handle, key);
#else
            return Node_GetVar(handle, key);
#endif
        }

        public T CreateComponent<T>(CreateMode mode = CreateMode.Replicated, uint id = 0) where T : Component
        {
            Runtime.ValidateRefCounted(this);
            var component = Activator.CreateInstance<T>();
            AddComponent(component, id, mode);
            return component;
        }

        /// <summary>
        /// Add a pre-created component.
        /// </summary>
        public void AddComponent(Component component, uint id = 0)
        {
            Runtime.ValidateRefCounted(this);
            AddComponent(component, id, CreateMode.Replicated);
        }

        /// <summary>
        /// Changes Parent for the node
        /// </summary>
        public void ChangeParent(Node newParent)
        {
            AddRef();
            Remove(); //without AddRef "Delete" will completly delete the node and the next operation will throw AccessViolationException
            newParent.AddChild(this);
            ReleaseRef();
        }

        public T GetComponent<T>(bool recursive = false) where T : Component
        {
            Runtime.ValidateRefCounted(this);
            var nativeTypeHash = typeof(T).GetRuntimeProperty("TypeStatic")?.GetValue(null);
            if (nativeTypeHash != null)
                return (T)GetComponent((StringHash)nativeTypeHash, recursive);

            //slow search (only for components defined by user):
            var component = (T)Components.FirstOrDefault(c => c is T);
            if (component == null && recursive)
                return GetChildrenWithComponent<T>(true).FirstOrDefault()?.GetComponent<T>(false);
            return component;
        }

        public T GetOrCreateComponent<T>(bool recursive = false) where T : Component
        {
            Runtime.ValidateRefCounted(this);
            var component = GetComponent<T>(recursive);
            if (component == null)
                return CreateComponent<T>();
            return component;
        }

        public bool LoadXml(string prefab)
        {
            bool result = false;
            var file = Application.Current.ResourceCache.GetFile(prefab, true);
            if(file != null)
            {
                file.Seek(0);
                result =  LoadXml(file);
                file.Close();
            }
            return result;
        }


        public bool Load(string prefab)
        {
            bool result = false;
            var file = Application.Current.ResourceCache.GetFile(prefab, true);
            if(file != null)
            {
                file.Seek(0);
                result =  Load(file);
                file.Close();
            }
            return result;
        }


        public bool LoadJson(string prefab)
        {
            bool result = false;
            var file = Application.Current.ResourceCache.GetFile(prefab, true);
            if(file != null)
            {
                file.Seek(0);
                result =  LoadJson(file);
                file.Close();
            }
            return result;
        }

   

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        unsafe internal static extern Variant * Node_GetTags(IntPtr handle);

		[DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Node_GetVars(IntPtr handle);

        unsafe public StringVector Tags
        {
            get
            {
                return (StringVector)(*Node_GetTags(Handle));
            }

            set
            {
                SetTags(value);
            }
        }

		public DynamicMap Vars
        {
            get
            {
				return new DynamicMap(Node_GetVars(Handle));
            }
        }


        public void SetTags(StringVector tags)
        {
            RemoveAllTags();
            for (int i = 0; i < tags.Count; i++)
            {
                AddTag(tags[i]);
            }
        }
    }
}
