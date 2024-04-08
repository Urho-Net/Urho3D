//
// Component C# sugar
//
// Authors:
//   Miguel de Icaza (miguel@xamarin.com)
//
// Copyrigh 2015 Xamarin INc
//

using System;
using System.Linq;
using System.Reflection;
using Urho.Resources;
using Urho.IO;
using Urho.Gui;
using Urho.Audio;


namespace Urho
{
    public partial class Component : Animatable
    {
        protected Engine Engine = Application.Current.Engine;
        protected Renderer Renderer = Application.Current.Renderer;
        protected Graphics Graphics = Application.Current.Graphics;
        protected ResourceCache ResourceCache = Application.Current.ResourceCache;
        protected Input Input = Application.Current.Input;
        protected UI UI = Application.Current.UI;
        protected FileSystem FileSystem = Application.Current.FileSystem;
        protected VectorGraphics VectorGraphics = Application.Current.VectorGraphics;
        protected Urho.Audio.Audio Audio = Application.Current.Audio;

        bool subscribedToSceneUpdate = false;

        bool isDisposed = false;
        private bool IsDelayedStartCalled = false;

        public bool IsStarted
        {
            get
            {
                return IsDelayedStartCalled;
            }
        }

        public bool ReceiveSceneUpdates
        {
            get
            {
                return subscribedToSceneUpdate;
            }
            set
            {
                if (value == true)
                {
                    if (!subscribedToSceneUpdate)
                    {
                        subscribedToSceneUpdate = true;
                        Application.Update += HandleUpdate;
                    }
                }
                else
                {
                    if (subscribedToSceneUpdate)
                    {
                        subscribedToSceneUpdate = false;
                        Application.Update -= HandleUpdate;
                    }
                }
            }
        }

        public T GetComponent<T>() where T : Component
        {
            Runtime.ValidateRefCounted(this);
            return (T)Node.Components.FirstOrDefault(c => c is T);
        }

        protected override void Dispose(bool disposing)
        {
            isDisposed = true;
            ReceiveSceneUpdates = false;
            base.Dispose(disposing);
        }

        public Application Application => Application.Current;

        public virtual void OnSerialize(IComponentSerializer serializer) { }

        public virtual void OnDeserialize(IComponentDeserializer deserializer) { }

        public void SerializeFields()
        {
            Type type = GetType();

            BindingFlags bindingFlags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;

            foreach (FieldInfo mInfo in type.GetFields(bindingFlags))
            {
                FieldAttributes fieldAttributes = mInfo.Attributes;
                bool isSerializable = false;

                foreach (Attribute attr in
                          Attribute.GetCustomAttributes(mInfo))
                {
                    if (attr.GetType() == typeof(SerializeFieldAttribute))
                    {
                        isSerializable = true;
                    }
                }

                // save only public or serializable fields
                if (!(mInfo.IsPublic || isSerializable)) continue;
                // don't save constants
                if ((fieldAttributes & FieldAttributes.Literal) == FieldAttributes.Literal) continue;


                Type field_type = mInfo.FieldType;
                string key = mInfo.Name;
                object value = mInfo.GetValue(this);

                if(value == null)continue;

                // SerializeField((StringHash)(key),value);
                // use a more common way to serialize , can be used alos for binary serialization
                try
                {
                    SetVar(key, value.SerializeJson());
                }
                catch (Exception exc)
                {
                    // throw new InvalidOperationException($"SerializeJson of {value.GetType()} failed.", exc);
                }
            }
        }


        public void DeserializeFields(IComponentDeserializer deserializer = null)
        {
            Type CompnentType = this.GetType();

            BindingFlags bindingFlags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;

            foreach (FieldInfo mInfo in CompnentType.GetFields(bindingFlags))
            {
                FieldAttributes fieldAttributes = mInfo.Attributes;
                bool isSerializable = false;

                foreach (Attribute attr in Attribute.GetCustomAttributes(mInfo))
                {
                    if (attr.GetType() == typeof(SerializeFieldAttribute))
                    {
                        isSerializable = true;
                    }
                }

                // load only public or serializable fields
                if (!(mInfo.IsPublic || isSerializable)) continue;
                // don't load constants
                if ((fieldAttributes & FieldAttributes.Literal) == FieldAttributes.Literal) continue;

                Type type = mInfo.FieldType;
                string key = mInfo.Name;
                // TBD ELI , Well not surprising  , crashing on  .NET 8.X AOT WASM , for now disabling , will enable it on .NET 9.X
#if !__WEB__
                string blob = GetVar(key);
                if (blob != string.Empty)
                {
                    try
                    {
                        object value = type.DeserializeJson(blob);
                        if (value != null)
                        {
                            mInfo.SetValue(this, value);
                        }
                    }
                    catch
                    {

                    }
                }
                else
#endif
                {
                    if (deserializer != null)
                    {
                        object value = deserializer.GetObjectValueFromXmlElement(type, key);
                        if (value != null)
                        {
                            mInfo.SetValue(this, value);
                        }
                    }
                }

            }
        }

        public virtual void OnAttachedToNode(Node node) { }

        public virtual void OnSceneSet(Scene scene) { }

        public virtual void OnNodeSetEnabled() { }

        public virtual void OnCloned(Scene scene, Component originalComponent) { }

        protected override void OnDeleted()
        {
            isDisposed = true;
            if (subscribedToSceneUpdate)
            {
                ReceiveSceneUpdates = false;
            }
            base.OnDeleted();
        }

        internal void AttachedToNode(Node node)
        {
            if (node != null && !subscribedToSceneUpdate)
            {
                ReceiveSceneUpdates = true;
            }
            else if (node == null && subscribedToSceneUpdate)
            {
                ReceiveSceneUpdates = false;
            }
            OnAttachedToNode(node);
        }


        /// <summary>
        /// Called before the first update. At this point all other components of the node should exist.
        /// </summary>
        protected virtual void OnStart() { }


        /// <summary>
        /// Make sure you set SubscribeToSceneUpdate property to true in order to receive Update events
        /// </summary>
        protected virtual void OnUpdate(float timeStep) { }

        internal static bool IsDefinedInManagedCode<T>() => typeof(T).GetRuntimeProperty("TypeStatic") == null;

        void HandleUpdate(UpdateEventArgs args)
        {
            if (isDisposed) return;

            if (Enabled == false) return;
#if __EDITOR__
            if (Application.HasCurrent)
            {
                if (Application.Current.EditorMode == true && Application.Current.EditorUpdate == false)
                {
                    return;
                }
            }
#endif
            try
            {
                if (IsDelayedStartCalled == false)
                {
                    IsDelayedStartCalled = true;
                    OnStart();
                }

                OnUpdate(args.TimeStep);
            }
            catch (Exception ex)
            {
                Urho.Application.ThrowUnhandledException(
                     new Exception(ex.ToString() + " . You can omit this exception by subscribing to Urho.Application.UnhandledException event and set Handled property to True.\nApplicationOptions: " + Application.CurrentOptions));
            }
        }
    }
}
