//
// Runtime C# support
//
// Authors:
//   Miguel de Icaza (miguel@xamarin.com)
//
// Copyrigh 2015 Xamarin INc
//
using System;
using System.Collections.Generic;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Urho.IO;
using Urho.Resources;
using Urho.Gui;
using Urho.Urho2D;

namespace Urho
{
    internal class Runtime
    {
        static Dictionary<Type, int> hashDict;

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        delegate void NativeCallback(CallbackType type, IntPtr target, IntPtr param1, int param2, string param3);

        [DllImport(Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
        static extern void RegisterMonoNativeCallbacks(NativeCallback callback);

        // ReSharper disable once NotAccessedField.Local
        static NativeCallback nativeCallback; //keep references to native callbacks (protect from GC)
        static bool isStarted;

        internal static RefCountedCache RefCountedCache { get; private set; } = new RefCountedCache();
        internal static bool IsClosing { get; private set; }

        internal static Action<RefCounted, IntPtr> KnownObjectDeleted;

        internal static void Start()
        {
            IsClosing = false;
            isStarted = true;
        }

        internal static void Setup()
        {
            isStarted = false;
            RegisterMonoNativeCallbacks(nativeCallback = OnNativeCallback);
        }

        static bool CopySCharpComponentAttributes(Component srcComponent, Component dstComponent)
        {
            bool result = false;
            System.Type srcComponentType = srcComponent.GetType();
            System.Type dstComponentType = dstComponent.GetType();
            if (srcComponentType.FullName == dstComponentType.FullName)
            {
                Type CompnentType = srcComponent.GetType();
                BindingFlags bindingFlags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static | BindingFlags.GetProperty | BindingFlags.SetProperty;
                foreach (FieldInfo mInfo in CompnentType.GetFields(bindingFlags))
                {

                    FieldAttributes fieldAttributes = mInfo.Attributes;
                    // skip constants
                    if ((fieldAttributes & FieldAttributes.Literal) == FieldAttributes.Literal) continue;

                    bool isSerializable = false;

                    foreach (Attribute attr in Attribute.GetCustomAttributes(mInfo))
                    {
                        if (attr.GetType() == typeof(SerializeFieldAttribute))
                        {
                            isSerializable = true;
                        }
                    }

                    if (!(mInfo.IsPrivate || mInfo.IsPublic || isSerializable)) continue;


                    object? srcValue = mInfo.GetValue(srcComponent);
                    if (srcValue != null)
                    {
                        mInfo.SetValue(dstComponent, srcValue);
                    }
                }
                result = true;
            }
            return result;
        }
        /// <summary>
        /// This method is called by RefCounted::~RefCounted or RefCounted::AddRef
        /// </summary>
        [MonoPInvokeCallback(typeof(NativeCallback))]
        static void OnNativeCallback(CallbackType type, IntPtr target, IntPtr param1, int param2, string param3)
        {
            const string typeNameKey = "SharpTypeName";

            // while app is not started - accept only Log callbacks
            if (!isStarted && type != CallbackType.Log_Write)
                return;

            switch (type)
            {
                case CallbackType.Component_Clone:
                    {
                        var component = LookupObject<Component>(param1, false);
                        if (component != null && component.HasVar("SharpTypeName") == 1)
                        {
                            string typeName = component.GetVar("SharpTypeName");
                            if (!string.IsNullOrEmpty(typeName))
                            {               
                                var typeObj = Type.GetType(typeName);

                                if (typeObj != null)
                                {
                                    var newComponent = (Component)Activator.CreateInstance(typeObj, target);
                                    if (newComponent != null)
                                    {
                                        newComponent.Enabled = component.Enabled;
                                        newComponent.SetVar("SharpTypeName", typeName);
                                        CopySCharpComponentAttributes(component,newComponent);
                                        if (newComponent.Node != null)
                                        {
                                            newComponent.AttachedToNode(newComponent.Node);
                                        }
                                    }
                                }
                                else
                                {
#if __EDITOR__
                                    if (Application.HasCurrent)
                                    {
                                        bool deserializeComponentFields = false;
                                        var  newComponent = Application.Current.CreateComponentInstance(typeName, target, ref deserializeComponentFields);
                                        if(newComponent != null)
                                        {
                                            newComponent.SetVar("SharpTypeName", typeName);
                                            CopySCharpComponentAttributes(component,newComponent);
                                            if (newComponent.Node != null)
                                            {
                                                newComponent.AttachedToNode(newComponent.Node);
                                            }
                                        }
                                    }
#endif
                                }
                            }
                        }
                    }
                    break;

                case CallbackType.Component_Serialize:
                    {
                        var component = LookupObject<Component>(target, false);
                        // Managed component
                        if (component != null && component.TypeName != component.GetType().Name)
                        {
                            component.SetVar(typeNameKey, component.GetType().AssemblyQualifiedName);
                            component.SerializeFields();
                        }
                    }
                    break;

                case CallbackType.Serializable_Load:
                    {
                        string typeName = param3;
                        if (!string.IsNullOrEmpty(typeName))
                        {
                            var typeObj = Type.GetType(typeName);

                            if (typeObj != null)
                            {
                                var newComponent = (Component)Activator.CreateInstance(typeObj, target);
                                if (newComponent != null)
                                {
                                    newComponent.Enabled = (param2 != 0) ? true : false;
                                    newComponent.SetVar("SharpTypeName", typeName);
                                    newComponent.DeserializeFields();
                                    if (newComponent.Node != null)
                                    {
                                        newComponent.AttachedToNode(newComponent.Node);
                                    }
                                }
                            }
                            else{
#if __EDITOR__
                                if (Application.HasCurrent)
                                {
                                    bool deserializeComponentFields = true;
                                    var newComponent = Application.Current.CreateComponentInstance(typeName, target, ref deserializeComponentFields);
                                    if (newComponent != null)
                                    {
                                        newComponent.Enabled = (param2 != 0) ? true : false;
                                        newComponent.SetVar("SharpTypeName", typeName);
                                        newComponent.DeserializeFields();
                                        if (newComponent.Node != null)
                                        {
                                            newComponent.AttachedToNode(newComponent.Node);
                                        }
                                    }
                                }
#endif                    
                            }
                        }
                    }
                break;
                //Component:
                case CallbackType.Component_OnSceneSet:
                    {
                        var component = LookupObject<Component>(target, false);
                        component?.OnSceneSet(LookupObject<Scene>(param1, false));
                    }
                    break;
                case CallbackType.Component_SaveXml:
                    {
                        var component = LookupObject<Component>(target, false);
                        if (component != null && component.TypeName != component.GetType().Name)
                        {
                            var xmlElement = new XmlElement(param1);
                            xmlElement.SetString("type", "Component");
                            xmlElement.SetString(typeNameKey, component.GetType().AssemblyQualifiedName);
                            XmlComponentSerializer xmlComponentSerializer = new XmlComponentSerializer(xmlElement);
                            xmlComponentSerializer.Serialize("Enabled", component.Enabled);
                            component.OnSerialize(xmlComponentSerializer);
                        }
                    }
                    break;
                case CallbackType.Component_LoadXml:
                    {
                        var xmlElement = new XmlElement(param1);
                        var name = xmlElement.GetAttribute(typeNameKey);
                        bool deserializeComponentFields = true;

                        string fqn_name_in_game_assembly = "";
                        if (Application.Current != null)
                        {
                            string app_fqn = Application.Current.GetType().AssemblyQualifiedName;
                            String[] app_fqn_split = app_fqn.Split(",");
                            String[] name_split = name.Split(",");

                            app_fqn_split[0] = name_split[0];
                            fqn_name_in_game_assembly = String.Join(",", app_fqn_split);
                        }

                        if (!string.IsNullOrEmpty(name))
                        {
                            Component component = null;
                            try
                            {
                                var typeObj = Type.GetType(name);
                                if (typeObj == null)
                                {
                                    // might be that the component was saved from another assmebly , check if it exist in the main Game.dll assembly
                                    typeObj = Type.GetType(fqn_name_in_game_assembly);
                                    if (typeObj == null)
                                    {
#if __EDITOR__
                                        if (Application.HasCurrent)
                                        {
                                            component = Application.Current.CreateComponentInstance(name, target, ref deserializeComponentFields);
                                        }
#endif

                                        if (component == null)
                                        {
                                            Log.Write(LogLevel.Warning, $"{fqn_name_in_game_assembly} doesn't exist. Probably was removed by Linker. Add it to a some LinkerPleaseInclude.cs in case if you need it.");
                                            return;
                                        }
                                    }
                                }

                                if (component == null)
                                    component = (Component)Activator.CreateInstance(typeObj, target);
                            }
                            catch (Exception exc)
                            {
                                throw new InvalidOperationException($"{name} doesn't override constructor Component(IntPtr handle).", exc);
                            }

                            if (deserializeComponentFields == true)
                            {
                                if (xmlElement.GetAttribute("Enabled") != string.Empty)
                                    component.Enabled = xmlElement.GetBool("Enabled");
                                XmlComponentSerializer xmlComponentSerializer = new XmlComponentSerializer(xmlElement);
                                component.DeserializeFields(xmlComponentSerializer);
                                component.OnDeserialize(xmlComponentSerializer);
                            }

                            // Will allow  managed component cloning
                            if (component != null && fqn_name_in_game_assembly != string.Empty )
                            {
                                component.SetVar("SharpTypeName", fqn_name_in_game_assembly);
                            }

                            if (component.Node != null)
                            {
                                component.AttachedToNode(component.Node);
                            }
                        }
                    }
                    break;
                case CallbackType.Component_AttachedToNode:
                    {
                        var component = LookupObject<Component>(target, false);
                        component?.AttachedToNode(component.Node);
                    }
                    break;
                case CallbackType.Component_OnNodeSetEnabled:
                    {
                        var component = LookupObject<Component>(target, false);
                        component?.OnNodeSetEnabled();
                    }
                    break;


                //RefCounted:

                case CallbackType.RefCounted_AddRef:
                    {
                        //if we have an object with this handle and it's reference is weak - then change it to strong.
                        var referenceHolder = RefCountedCache.Get(target);
                        referenceHolder?.MakeStrong();
                    }
                    break;

                case CallbackType.RefCounted_Delete:
                    {
                        var referenceHolder = RefCountedCache.Get(target);
                        if (referenceHolder == null)
                            return; //we don't have this object in the cache so let's just skip it

                        var reference = referenceHolder.Reference;
                        if (reference == null)
                            // seems like the reference was Weak and GC has removed it - remove item from the dictionary
                            RefCountedCache.Remove(target);
                        else
                        {
                            reference.HandleNativeDelete();
                            KnownObjectDeleted(reference, target);
                        }
                    }
                    break;

                case CallbackType.Log_Write:
                    Urho.Application.ThrowUnhandledException(
                        new Exception(param3 + ". You can omit this exception by subscribing to Urho.Application.UnhandledException event and set Handled property to True.\nApplicationOptions: " + Application.CurrentOptions));
                    break;

                case CallbackType.Serializable_LoadXml:
                    var serializable = LookupObject<Serializable>(target, false);
                    var xmlElement1 = new XmlElement(param1);
                    serializable?.OnDeserialize(xmlElement1);
                    break;

                case CallbackType.VGElement_Render:
                    {
                        var vgElement = LookupObject<VGElement>(target, false);
                        if (vgElement != null)
                        {
                            VGRenderChilderen(vgElement);
                        }
                    }
                    break;

                case CallbackType.Drawable2D_UpdateSourceBatches:
                {
                    Drawable2DUpdateSourceBatches( target,  param1);
                }
                break;

                case CallbackType.StaticSprite2D_OnWorldBoundingBoxUpdate:
                {
                    StaticSprite2DOnWorldBoundingBoxUpdate( target,  param1);
                }
                break;
            }
        }

        private static unsafe void Drawable2DUpdateSourceBatches(IntPtr target, IntPtr param1)
        {
            Drawable2D drawable2D = LookupObject<Drawable2D>(target, false);
            if (drawable2D != null)
            {
                bool status = drawable2D.UpdateSourceBatches();
                if (status == true)
                {
                    *(int*)((byte*)param1) = 1;
                }
            }
        }

        private static unsafe void StaticSprite2DOnWorldBoundingBoxUpdate(IntPtr target, IntPtr param1)
        {
             StaticSprite2D staticSprite2D = LookupObject<StaticSprite2D>(target, false);
             if(staticSprite2D != null)
             {
                 staticSprite2D.UpdateWorldBoundingBox(out BoundingBox result);
                 *(BoundingBox*)((byte*)param1) = result;
             }
        }

        private static void VGRenderChilderen(UIElement element)
        {
            uint childCount = element.GetNumChildren();

            for (uint i = 0; i < childCount; i++)
            {
                UIElement child = element.GetChild(i);

                // don't render child of type VGCanvas , avoiding duplicate rendering 
                if (child is VGCanvas)
                {
                    continue;
                }

                float timeStep = (Application.Current != null) ? Application.Current.Time.TimeStep : 0.0f;

                if (child.Visible == true)
                {
                    child.OnVGRenderUpdate(timeStep);
                }

                //recursive VG render
                VGRenderChilderen(child);

            }
        }

        public static T LookupRefCounted<T>(IntPtr ptr, bool createIfNotFound = true) where T : RefCounted
        {
            if (ptr == IntPtr.Zero)
                return null;

            var reference = RefCountedCache.Get(ptr)?.Reference;
            if (reference is T)
                return (T)reference;

            if (!createIfNotFound)
                return null;

            var refCounted = (T)Activator.CreateInstance(typeof(T), ptr);
            return refCounted;
        }

        public static T LookupObject<T>(IntPtr ptr, bool createIfNotFound = true) where T : UrhoObject
        {
            if (ptr == IntPtr.Zero)
                return null;

            var referenceHolder = RefCountedCache.Get(ptr);
            var reference = referenceHolder?.Reference;
            if (reference is T) //possible collisions
                return (T)reference;

            if (!createIfNotFound)
                return null;

            var name = Marshal.PtrToStringAnsi(UrhoObject.UrhoObject_GetTypeName(ptr));
            var type = FindTypeByName(name);
            var typeInfo = type.GetTypeInfo();
            if (typeInfo.IsSubclassOf(typeof(Component)) || type == typeof(Component))
            {
                //TODO: special case, handle managed subclasses
            }

#if __EDITOR__
            // For unknown components , give the application a chance to find it.
            if (type == typeof(UnknownComponent))
            {
                bool deserializeComponentFields = true;
                var urhoComponent = (T)Application.Current.CreateComponentInstance(type, ptr, ref deserializeComponentFields);
                if (urhoComponent != null) return urhoComponent;
            }
#endif

            var urhoObject = (T)Activator.CreateInstance(type, ptr);
            return urhoObject;
        }

        public static void UnregisterObject(IntPtr handle)
        {
            RefCountedCache.Remove(handle);
        }

        public static void RegisterObject(RefCounted refCounted)
        {
            RefCountedCache.Add(refCounted);
        }

        public static StringHash LookupStringHash(Type t)
        {
            if (hashDict == null)
                hashDict = new Dictionary<Type, int>();

            int c;
            if (hashDict.TryGetValue(t, out c))
                return new StringHash(c);
            var hash = GetTypeStatic(t);
            hashDict[t] = hash.Code;
            return hash;
        }

        static StringHash GetTypeStatic(Type type)
        {
            var typeStatic = type.GetRuntimeProperty("TypeStatic");
            while (typeStatic == null)
            {
                type = type.GetTypeInfo().BaseType;
                if (type == typeof(object))
                    throw new InvalidOperationException("The type doesn't have static TypeStatic property");
                typeStatic = type.GetRuntimeProperty("TypeStatic");
            }
            return (StringHash)typeStatic.GetValue(null);
        }

        // for RefCounted, UrhoObjects
        internal static void ValidateRefCounted<T>(T obj, [CallerMemberName] string name = "") where T : RefCounted
        {
            //TODO: remove ValidateRefCounted from IsExiting in the Binder
            if (name == "IsExisting")
                return;

            if (IsClosing)
            {
                var errorText = $"{typeof(T).Name}.{name} (Handle={obj.Handle}) was invoked after Application.Stop";
                LogSharp.Error(errorText);
#if __EDITOR__
                Urho.Application.ThrowUnhandledException(
                     new Exception(errorText + " . You can omit this exception by subscribing to Urho.Application.UnhandledException event and set Handled property to True.\nApplicationOptions: " + Application.CurrentOptions));
#else
                throw new InvalidOperationException(errorText);
#endif
            }
            if (obj.IsDeleted) //IsDeleted is set to True when we receive a native callback from RefCounted::~RefCounted
            {
                var errorText = $"Underlying native object was deleted for Handle={obj.Handle}. {typeof(T).Name}.{name}";
                LogSharp.Error(errorText);
#if __EDITOR__
                Urho.Application.ThrowUnhandledException(
                     new Exception(errorText + " . You can omit this exception by subscribing to Urho.Application.UnhandledException event and set Handled property to True.\nApplicationOptions: " + Application.CurrentOptions));
                throw new InvalidOperationException(errorText);
#else
                throw new InvalidOperationException(errorText);
#endif
            }
            //if (obj.Handle == IntPtr.Zero)
            //{
            //}
            //TODO: check current thread?
        }

        // non-RefCounted classes
        internal static void ValidateObject<T>(T obj, [CallerMemberName] string name = "") where T : class
        {
            if (IsClosing)
            {
                var errorText = $"{typeof(T).Name}.{name} was invoked after Application.Stop";
                LogSharp.Error(errorText);
                throw new InvalidOperationException(errorText);
            }
        }

        // constructors, static methods, value types
        internal static void Validate(Type type, [CallerMemberName] string name = "")
        {
            if (IsClosing)
            {
                var errorText = $"{type.Name}.{name} was invoked after Application.Stop";
                LogSharp.Error(errorText);
                throw new InvalidOperationException(errorText);
            }
        }

        internal static IReadOnlyList<T> CreateVectorSharedPtrProxy<T>(IntPtr handle) where T : UrhoObject
        {
            return new Vectors.ProxyUrhoObject<T>(handle);
        }

        internal static IReadOnlyList<T> CreateVectorSharedPtrRefcountedProxy<T>(IntPtr handle) where T : RefCounted
        {
            return new Vectors.ProxyRefCounted<T>(handle);
        }

        internal static IReadOnlyList<uint> CreatePodVectorUintProxy(IntPtr handle)
        {
            return new Vectors.ProxyPodVectorUint<uint>(handle);
        }

        internal static void Cleanup(bool disposeContext = true)
        {
            IsClosing = true;
            RefCountedCache.Clean(disposeContext);
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
        }

        static Dictionary<string, Type> typesByNativeNames;
        // special cases: (TODO: share this code with SharpieBinder somehow)
        static Dictionary<string, string> typeNamesMap = new Dictionary<string, string>
            {
                {nameof(UrhoObject),  "Object"},
                {nameof(UrhoConsole), "Console"},
                {nameof(XmlFile),     "XMLFile"},
                {nameof(JsonFile),    "JSONFile"},
            };

        static Type FindTypeByName(string name)
        {
            if (typesByNativeNames == null)
            {
                typesByNativeNames = new Dictionary<string, Type>(200);
                foreach (var type in typeof(Runtime).GetTypeInfo().Assembly.ExportedTypes)
                {
                    if (!type.GetTypeInfo().IsSubclassOf(typeof(RefCounted)))
                        continue;

                    string remappedName;
                    if (!typeNamesMap.TryGetValue(type.Name, out remappedName))
                        remappedName = type.Name;

                    typesByNativeNames[remappedName] = type;
                }
            }
            Type result;
            if (!typesByNativeNames.TryGetValue(name, out result))
                return typeof(UnknownComponent);
            // throw new Exception($"Type {name} not found.");

            return result;
        }
    }
}
