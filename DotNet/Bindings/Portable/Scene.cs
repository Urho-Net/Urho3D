using System;
using System.Runtime.InteropServices;
using Urho.IO;
using Urho.Resources;

using File = Urho.IO.File;
using FileMode = Urho.IO.FileMode;
namespace Urho
{
    partial class Scene : Node
    {
        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern bool Scene_LoadXMLFromCache(IntPtr handle, IntPtr cache, string file);

        public bool LoadXmlFromCache(ResourceCache cache, string file)
        {
            Runtime.ValidateRefCounted(this);
            return Scene_LoadXMLFromCache(handle, cache.Handle, file);
        }

        public bool LoadXml(string path)
        {
            bool result = false;
            var file = Application.Current.ResourceCache.GetFile(path, true);
            if (file != null)
            {
                file.Seek(0);
                result = LoadXml(file);
                file.Close();
            }
            return result;
        }

        public bool Load(string path)
        {
            Runtime.ValidateRefCounted(this);
            bool result = false;
            var file = Application.Current.ResourceCache.GetFile(path, true);
            if (file != null)
            {
                file.Seek(0);
                result = Load(file);
                file.Close();
            }
            return result;
        }

        public bool LoadJson(string path)
        {
            Runtime.ValidateRefCounted(this);
            bool result = false;
            var file = Application.Current.ResourceCache.GetFile(path, true);
            if (file != null)
            {
                file.Seek(0);
                result = LoadJson(file);
                file.Close();
            }
            return result;
        }

        public bool SaveXml(string path, string indentation = "\t")
        {
            Runtime.ValidateRefCounted(this);
            using (var file = new File(Context, path, FileMode.Write))
            {
                bool result = false;
                if (file.IsOpen())
                {
                    result = SaveXml(file, indentation);
                    file.Close();
                }
                return result;
            }
        }

        public bool SaveJson(string path, string indentation = "\t")
        {
            Runtime.ValidateRefCounted(this);
            using (var file = new File(Context, path, FileMode.Write))
            {
                bool result = false;
                if (file.IsOpen())
                {
                    result = SaveJson(file, indentation);
                    file.Close();
                }
                return result;
            }
        }

        public bool Save(string path)
        {
            Runtime.ValidateRefCounted(this);
            using (var file = new File(Context, path, FileMode.Write))
            {
                bool result = false;
                if (file.IsOpen())
                {
                    result = Save(file);
                    file.Close();
                }
                return result;
            }
        }

        /// <summary>
		/// Instantiate prefab content from XML data. Return root node if successful.
		/// </summary>
		public Node InstantiateXml(string path, Urho.Vector3 position, Urho.Quaternion rotation, CreateMode mode = CreateMode.Replicated)
        {
            Runtime.ValidateRefCounted(this);
            Node result = null;
            var file = Application.Current.ResourceCache.GetFile(path, true);
            if (file != null)
            {
                file.Seek(0);
                result = InstantiateXml(file, position, rotation, mode);
                file.Close();
            }
            return result;
        }

        /// <summary>
		/// Instantiate prefab content from JSON data. Return root node if successful.
		/// </summary>
        public Node InstantiateJson(string path, Urho.Vector3 position, Urho.Quaternion rotation, CreateMode mode = CreateMode.Replicated)
        {
            Runtime.ValidateRefCounted(this);
            Node result = null;
            var file = Application.Current.ResourceCache.GetFile(path, true);
            if (file != null)
            {
                file.Seek(0);
                result = InstantiateJson(file, position, rotation, mode);
                file.Close();
            }
            return result;
        }

        /// <summary>
		/// Instantiate prefab content from binary data. Return root node if successful.
		/// </summary>
		public Node Instantiate(string path, Urho.Vector3 position, Urho.Quaternion rotation, CreateMode mode = CreateMode.Replicated)
        {
            Runtime.ValidateRefCounted(this);
            Node result = null;
            var file = Application.Current.ResourceCache.GetFile(path, true);
            if (file != null)
            {
                file.Seek(0);
                result = Instantiate(file, position, rotation, mode);
                file.Close();
            }
            return result;
        }

        unsafe partial void OnSceneCreated()
        {
            ComponentCloned += Scene_ComponentCloned;
        }

        void Scene_ComponentCloned(ComponentClonedEventArgs e)
        {
            if (e.CloneComponent.GetType() != e.Component.GetType())
            {
                // it means Component to clone is a managed subclass.
                // Let's wrap this Handle with that Managed class and re-register in the internal cache.
                var clonedManagedComponent = (Component)Activator.CreateInstance(e.Component.GetType(), e.CloneComponent.Handle);
                clonedManagedComponent.OnCloned(e.Scene, e.Component);
                Runtime.RegisterObject(clonedManagedComponent);
            }
        }
    }
}
