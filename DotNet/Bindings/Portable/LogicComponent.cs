using System;
using System.Runtime.InteropServices;
using Urho.Physics;

namespace Urho
{
    /// <summary>
    /// Helper base class for user-defined game logic components that hooks up to update events and forwards them to virtual functions similar to ScriptInstance class.
    /// </summary>
    public partial class LogicComponent : Component
    {
        private Node node_ = null;
        private Scene scene_ = null;

        private Scene scene
        {
            get
            {
                if (scene_ == null && (node_ != null && node_.Scene != null)) scene_ = node_.Scene;
                return scene_;
            }

            set
            {
                scene_ = value;
            }
        }

        protected override void Dispose(bool disposing)
        {
            if (!Application.IsExiting)
                DisableAllUpdates = true;

            base.Dispose(disposing);
        }

        protected override void OnDeleted()
        {
            if (!Application.IsExiting)
                DisableAllUpdates = true;

            base.OnDeleted();
        }

        public override void OnAttachedToNode(Node node)
        {
            node_ = node;
            if (node != null && node.Scene != null)
            {
                scene = node.Scene;
                if (receiveFixedUpdates)
                {
                    var physicsWorld = node.Scene.GetComponent<PhysicsWorld>();
                    if (physicsWorld != null)
                        physicsWorld.PhysicsPreStep += OnFixedUpdate;
                }

                if (receiveFixedPostUpdates)
                {
                    var physicsWorld = node.Scene.GetComponent<PhysicsWorld>();
                    if (physicsWorld != null)
                        physicsWorld.PhysicsPostStep += OnFixedPostUpdate;
                }

                if (receivePostUpdates)
                {
                    node.Scene.ScenePostUpdate += OnPostUpdate;
                }
            }
            else if (node == null)
            {
                Remove();
            }
        }

        private bool receiveFixedUpdates = true;
        protected bool ReceiveFixedUpdates
        {
            get
            {
                return receiveFixedUpdates;
            }

            set
            {
                if (receiveFixedUpdates == value) return;

                receiveFixedUpdates = value;

                if (receiveFixedUpdates == true)
                {
                    if (scene != null)
                    {
                        var physicsWorld = scene.GetComponent<PhysicsWorld>();
                        if (physicsWorld != null)
                            physicsWorld.PhysicsPreStep += OnFixedUpdate;
                    }
                }
                else
                {
                    if (scene != null)
                    {
                        var physicsWorld = scene.GetComponent<PhysicsWorld>();
                        if (physicsWorld != null)
                            physicsWorld.PhysicsPreStep -= OnFixedUpdate;
                    }
                }
            }
        }

        private bool receiveFixedPostUpdates = true;
        protected bool ReceiveFixedPostUpdates
        {
            get
            {
                return receiveFixedPostUpdates;
            }

            set
            {
                if (receiveFixedPostUpdates == value) return;

                receiveFixedPostUpdates = value;

                if (receiveFixedPostUpdates == true)
                {
                    if (scene != null)
                    {
                        var physicsWorld = scene.GetComponent<PhysicsWorld>();
                        if (physicsWorld != null)
                            physicsWorld.PhysicsPostStep += OnFixedPostUpdate;
                    }
                }
                else
                {
                    if (scene != null)
                    {
                        var physicsWorld = scene.GetComponent<PhysicsWorld>();
                        if (physicsWorld != null)
                            physicsWorld.PhysicsPostStep -= OnFixedPostUpdate;
                    }
                }
            }
        }

        private bool receivePostUpdates = true;
        protected bool ReceivePostUpdates
        {
            get
            {
                return receivePostUpdates;
            }

            set
            {
                if (receivePostUpdates == value) return;

                receivePostUpdates = value;

                if (receivePostUpdates == true)
                {
                    if (scene != null)
                    {
                        scene.ScenePostUpdate += OnPostUpdate;
                    }
                }
                else
                {
                    if (scene != null)
                    {
                        scene.ScenePostUpdate -= OnPostUpdate;
                    }
                }
            }
        }

        protected bool EnableAllUpdates
        {
            set
            {
                if (value == true)
                {
                    ReceiveSceneUpdates = true;
                    ReceiveFixedUpdates = true;
                    ReceiveFixedPostUpdates = true;
                    ReceivePostUpdates = true;
                }
            }
        }

        protected bool DisableAllUpdates
        {
            set
            {
                if (value == true)
                {
                    ReceiveSceneUpdates = false;
                    ReceiveFixedUpdates = false;
                    ReceiveFixedPostUpdates = false;
                    ReceivePostUpdates = false;
                }
            }
        }

        public void SetUpdateEventMask(uint mask)
        {
            ReceiveSceneUpdates = ((Convert.ToUInt32(UpdateEvent.Update) & mask) == Convert.ToUInt32(UpdateEvent.Update)) ? true : false;
            ReceiveFixedUpdates = ((Convert.ToUInt32(UpdateEvent.Fixedupdate) & mask) == Convert.ToUInt32(UpdateEvent.Fixedupdate)) ? true : false;
            ReceiveFixedPostUpdates = ((Convert.ToUInt32(UpdateEvent.Fixedpostupdate) & mask) == Convert.ToUInt32(UpdateEvent.Fixedpostupdate)) ? true : false;
            ReceivePostUpdates = ((Convert.ToUInt32(UpdateEvent.Postupdate) & mask) == Convert.ToUInt32(UpdateEvent.Postupdate)) ? true : false;
        }

        public uint GetUpdateEventMask()
        {
            uint result = 0;

            if (ReceiveSceneUpdates == true)
            {
                result |= Convert.ToUInt32(UpdateEvent.Update);
            }

            if (ReceiveFixedUpdates == true)
            {
                result |= Convert.ToUInt32(UpdateEvent.Fixedupdate);
            }

            if (ReceiveFixedPostUpdates == true)
            {
                result |= Convert.ToUInt32(UpdateEvent.Fixedpostupdate);
            }

            if (ReceivePostUpdates == true)
            {
                result |= Convert.ToUInt32(UpdateEvent.Postupdate);
            }

            return result;
        }

        public bool IsUpdateEventEnabled(UpdateEvent evt)
        {
            if (evt == UpdateEvent.Update) return ReceiveSceneUpdates;
            else if (evt == UpdateEvent.Fixedupdate) return ReceiveFixedUpdates;
            else if (evt == UpdateEvent.Fixedpostupdate) return ReceiveFixedPostUpdates;
            else if (evt == UpdateEvent.Postupdate) return ReceivePostUpdates;

            return false;
        }

        /// <summary>
        /// Make sure you set ReceiveSceneUpdates property to true in order to receive Update events (this porperty is true by default)
        /// </summary>
        protected override void OnUpdate(float timeStep)
        {
#if __EDITOR__
            if (Application.HasCurrent)
            {
                if (Application.Current.EditorMode == true && Application.Current.EditorUpdate == false)
                {
                    return;
                }
            }
#endif
            base.OnUpdate(timeStep);
        }

        /// <summary>
        /// Called on physics post-update
        /// </summary>
        protected virtual void OnFixedUpdate(PhysicsPreStepEventArgs e) { }

        /// <summary>
        /// Called on physics update
        /// </summary>
        protected virtual void OnFixedPostUpdate(PhysicsPostStepEventArgs e) { }

        /// <summary>
        /// Called on scene post-update,
        /// </summary>
        protected virtual void OnPostUpdate(ScenePostUpdateEventArgs e) { }

    }
}
