using System;
using System.Collections.Generic;

namespace Urho
{
    internal class UrhoEventAdapter<TEventArgs>
    {
        readonly Dictionary<IntPtr, List<Action<TEventArgs>>> managedSubscribersByObjects;
        readonly Dictionary<IntPtr, Subscription> nativeSubscriptionsForObjects;
        readonly Type objectType;

        public UrhoEventAdapter(Type objectType)
        {
            this.objectType = objectType;
            managedSubscribersByObjects = new Dictionary<IntPtr, List<Action<TEventArgs>>>(IntPtrEqualityComparer.Instance);
            nativeSubscriptionsForObjects = new Dictionary<IntPtr, Subscription>(IntPtrEqualityComparer.Instance);
            Runtime.KnownObjectDeleted += OnObjectDeleted;
        }

        void OnObjectDeleted(RefCounted refCounted, IntPtr handle)
        {
            if (refCounted.GetType() != objectType)
                return;

            managedSubscribersByObjects.Remove(handle);
            nativeSubscriptionsForObjects.Remove(handle);
        }

        public void AddManagedSubscriber(IntPtr handle, Action<TEventArgs> action, Func<Action<TEventArgs>, Subscription> nativeSubscriber)
        {
            List<Action<TEventArgs>> listOfManagedSubscribers;
            if (!managedSubscribersByObjects.TryGetValue(handle, out listOfManagedSubscribers))
            {
                listOfManagedSubscribers = new List<Action<TEventArgs>> { action };
                managedSubscribersByObjects[handle] = listOfManagedSubscribers;
                nativeSubscriptionsForObjects[handle] = nativeSubscriber(args =>
                    {
                        var count = listOfManagedSubscribers.Count;
                        for (int i = 0; i < count; i++)
                        {
                            if (i < listOfManagedSubscribers.Count)
                            {
                                if (i >= 0)
                                {
                                    // elix22
                                    // If RefCounted object gets deleted/disposed , it doesn't notify all UrhoEventAdapters  that it's subscribed to  .
                                    // It is expected from the developer to  unsubscribe any RefCounted(Node , Component , ...) before it's deleted. 
                                    // But as we all know that it's not always the case.
                                    // If the RefCounted object is part of  the listOfManagedSubscribers then it must be first checked that it's valid.
                                    // if it's already deleted then remove it from the listOfManagedSubscribers
                                    RefCounted refCounted = listOfManagedSubscribers[i].Target as RefCounted;
                                    if (refCounted != null && refCounted.IsDeleted)
                                    {
                                        // invalid managed subscriber , remove it and continue to the next in the list.
                                        listOfManagedSubscribers.Remove(listOfManagedSubscribers[i]);
                                        // elix22
                                        // the size of listOfManagedSubscribers is reduced by 1 , now i points the next managed subscriber , 
                                        // Above loop will increase i and the call to the next managed subscriber will be missed.
                                        // So i must be adjusted and decreased by 1.
                                        i--;
                                        continue;
                                    }

                                    // elix22 , valid managed subscriber , call it.
                                    listOfManagedSubscribers[i](args);
                                }
                            }
                            else
                            {
                                break;
                            }
                        }

                        // elix22 
                        // Might occur in case the listOfManagedSubscribers contained only RefCounted objects that were  all removed 
                        if (listOfManagedSubscribers.Count < 1)
                        {
                            managedSubscribersByObjects.Remove(handle);
                            nativeSubscriptionsForObjects[handle].Unsubscribe();
                        }
                    });
            }
            else
            {
                //this handle is already subscribed to the native event - don't call native subscription again - just add it to the list.
                listOfManagedSubscribers.Add(action);
            }
        }

        public void RemoveManagedSubscriber(IntPtr handle, Action<TEventArgs> action)
        {
            var target = action.Target;

            List<Action<TEventArgs>> listOfManagedSubscribers;
            if (managedSubscribersByObjects.TryGetValue(handle, out listOfManagedSubscribers))
            {
                listOfManagedSubscribers.RemoveAll(a => a == action);

                if (listOfManagedSubscribers.Count < 1)
                {
                    managedSubscribersByObjects.Remove(handle);
                    nativeSubscriptionsForObjects[handle].Unsubscribe();
                }
            }
        }
    }
}
