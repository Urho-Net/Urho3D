//
// Urho's Object C# sugar
//
// Authors:
//   Miguel de Icaza (miguel@xamarin.com)
//
// Copyrigh 2015 Xamarin INc
//

using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Reflection;

namespace Urho
{


    public partial class UrhoObject : RefCounted
    {

        Dictionary<int, Subscription> nativeSubscriptions = null;

        [MonoPInvokeCallback(typeof(ObjectCallbackSignature))]
        internal static void ObjectCallback(IntPtr data, int stringHash, IntPtr variantMap)
        {
            try
            {
                GCHandle gch = GCHandle.FromIntPtr(data);
                Action<IntPtr> a = (Action<IntPtr>)gch.Target;
                a(variantMap);
            }
            catch (Exception ex)
            {
                Urho.Application.ThrowUnhandledException(
                     new Exception(ex.ToString() + " . You can omit this exception by subscribing to Urho.Application.UnhandledException event and set Handled property to True.\nApplicationOptions: " + Application.CurrentOptions));
            }
        }

        [MonoPInvokeCallback(typeof(ObjectCallbackSignature))]
        internal static void ObjectCallback2(IntPtr data, int stringHash, IntPtr variantMap)
        {
            GCHandle gch = GCHandle.FromIntPtr(data);
            Action<UrhoEventArgs> a = (Action<UrhoEventArgs>)gch.Target;

			UrhoEventArgs args;
			args.EventType = stringHash;
			args.EventData = new DynamicMap(variantMap);
            a(args);
        }


        internal static ObjectCallbackSignature ObjectCallbackInstance = ObjectCallback;

		internal static ObjectCallbackSignature ObjectCallbackInstance2 = ObjectCallback2;
		

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern void FreeBuffer(IntPtr buffer);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr urho_subscribe_global_event(IntPtr target, ObjectCallbackSignature act, IntPtr data, int eventNameHash);


        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr urho_subscribe_event(IntPtr target, ObjectCallbackSignature act, IntPtr data, int eventNameHash);


        public void SubscribeToEvent(string eventName, Action<UrhoEventArgs> handler)
        {
            SubscribeToEvent(new StringHash(eventName), handler);
        }

        public void SubscribeToEvent(StringHash eventName, Action<UrhoEventArgs> handler)
        {
            Runtime.ValidateRefCounted (this);

            if (nativeSubscriptions == null)
            {
                nativeSubscriptions = new Dictionary<int, Subscription>();
            }

            Subscription subscription = null;
            if (nativeSubscriptions.TryGetValue(eventName.Code, out subscription))
            {
                subscription.Dispose();
            }

			Action<UrhoEventArgs> proxy = (x)=> { handler (x); };

            var s = new Subscription(proxy);
            s.UnmanagedProxy = urho_subscribe_global_event(handle, ObjectCallbackInstance2, GCHandle.ToIntPtr(s.gch), eventName.Code);
            nativeSubscriptions[eventName.Code] = s;

        }

        public void UnSubscribeFromEvent(string eventName)
        {
            UnSubscribeFromEvent(new StringHash(eventName));
        }
        public void UnSubscribeFromEvent(StringHash eventName)
        {

            Runtime.ValidateRefCounted (this);
            
            Subscription subscription = null;

            if (nativeSubscriptions != null && nativeSubscriptions.TryGetValue(eventName.Code, out subscription))
            {
                subscription.Unsubscribe();
                nativeSubscriptions.Remove(eventName.Code);
            }
        }

        public void UnSubscribeFromAllEvents()
        {
            if (!Runtime.IsClosing && !IsDeleted && !Application.isExiting)
            {
                UnsubscribeFromAllEvents();

                if (nativeSubscriptions != null)
                {

                    foreach (var item in nativeSubscriptions)
                    {
                        Subscription s = item.Value;
                        s.Dispose();
                    }


                    nativeSubscriptions.Clear();
                }
            }
        }

        protected override void OnDeleted()
        {
            if (!Runtime.IsClosing && !IsDeleted && !Application.isExiting)
            {
                base.OnDeleted();

                if (nativeSubscriptions != null)
                {

                    foreach (var item in nativeSubscriptions)
                    {
                        Subscription s = item.Value;
                        s.gch.Free();
                    }


                    nativeSubscriptions.Clear();
                }

                nativeSubscriptions = null;
            }
        }


    }
}



        /*
                public Subscription SubscribeToEvent(string eventName, Action<EventDataContainer> handler)
                {
                    return SubscribeToEvent(new StringHash(eventName), handler);
                }

                public Subscription SubscribeToEvent(StringHash eventName, Action<EventDataContainer> handler)
                {
                    var s = new Subscription(ptr => handler(new EventDataContainer(ptr)));
                    s.UnmanagedProxy = urho_subscribe_event(handle, ObjectCallbackInstance, GCHandle.ToIntPtr(s.gch), eventName.Code);
                    return s;
                }

        */