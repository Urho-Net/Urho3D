#include <stdio.h>
#include <string.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include "AllUrho.h"
#include "glue.h"
#include "interop.h"
#include <stdlib.h>

#ifndef _WINDOWS
#include <net/if.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#endif

#include "qoi.h"

using namespace Urho3D;

#ifdef _WINDOWS
typedef unsigned int uint;
#endif

//
// This is just an implemention of EventHandler that can be used with function
// pointers, so we can register delegates from C#
//

static String StringDup;
const char* stringdup(const char* s)
{
    StringDup = String(s);
    return StringDup.CString();
}

extern "C"
{

    // reciever and sender are the same
    DllExport void* urho_subscribe_event(void* _receiver, HandlerFunctionPtr callback, void* data, int eventNameHash)
    {
        StringHash h(eventNameHash);
        Urho3D::Object* receiver = (Urho3D::Object*)_receiver;
        NotificationProxy* proxy = new NotificationProxy(receiver, callback, data, h);
        receiver->SubscribeToEvent(receiver, h, proxy);
        return proxy;
    }

    // sender is unknown here , can be anyone
    DllExport void* urho_subscribe_global_event(void* _receiver, HandlerFunctionPtr callback, void* data,
                                                int eventNameHash)
    {
        StringHash h(eventNameHash);
        Urho3D::Object* receiver = (Urho3D::Object*)_receiver;
        WeakPtr<Urho3D::Object> weak_receiver(receiver);
        NotificationProxy* proxy = new NotificationProxy(weak_receiver, callback, data, h);
        receiver->SubscribeToEvent(h, proxy);
        return proxy;
    }

    DllExport void* VariantMap_VariantMap() { return (void*)(new VariantMap()); }

    DllExport void VariantMap_Dispose(VariantMap* variantMap)
    {
        if (variantMap)
        {
            variantMap->Clear();
            delete variantMap;
        }
    }

    bool VariantMap_Erase(VariantMap& map, const char* key)
    {
        StringHash h(key);
        return map.Erase(h);
    }

    bool VariantMap_Erase2(VariantMap& map, int key)
    {
        StringHash h(key);
        return map.Erase(h);
    }

    DllExport void* urho_map_get_variantmap(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return (void*)(&map[h].GetVariantMap());
    }

    DllExport void* urho_map_get_ptr(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h].GetVoidPtr();
    }

    DllExport void* urho_map_get_object(VariantMap& map, int hash, int* objHash)
    {
        StringHash h(hash);
        void* ptr = map[h].GetVoidPtr();
        Object* object = static_cast<Object*>(ptr);
        *objHash = object->GetType().Value(); // GetType is virtual
        return ptr;
    }

    DllExport const char* urho_map_get_String(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return stringdup(map[h].GetString().CString());
    }

    DllExport int urho_map_get_StringHash(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h].GetStringHash().Value();
    }

#ifdef __EMSCRIPTEN__
    DllExport Variant* urho_map_get_Variant(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return &map[h];
    }
#else
    DllExport Variant urho_map_get_Variant(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h];
    }
#endif

#ifdef __EMSCRIPTEN__
    DllExport Interop::Vector3* urho_map_get_Vector3(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return ((Interop::Vector3*)&(map[h].GetVector3()));
    }
#else
    DllExport Interop::Vector3 urho_map_get_Vector3(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return *((Interop::Vector3*)&(map[h].GetVector3()));
    }
#endif

#ifdef __EMSCRIPTEN__
    DllExport Interop::IntVector2* urho_map_get_IntVector2(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return ((Interop::IntVector2*)&(map[h].GetIntVector2()));
    }
#else
    DllExport Interop::IntVector2 urho_map_get_IntVector2(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return *((Interop::IntVector2*)&(map[h].GetIntVector2()));
    }
#endif

    DllExport int urho_map_get_bool(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h].GetBool();
    }

    DllExport float urho_map_get_float(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h].GetFloat();
    }

    DllExport int urho_map_get_int(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h].GetInt();
    }

    DllExport unsigned int urho_map_get_uint(VariantMap& map, int hash)
    {
        StringHash h(hash);
        return map[h].GetUInt();
    }

    DllExport unsigned char* urho_map_get_buffer(VariantMap& map, int hash, unsigned* size)
    {
        StringHash h(hash);
        PODVector<unsigned char> p(map[h].GetBuffer());
        *size = p.Size();
        unsigned char* result = new unsigned char[p.Size()];
        for (int i = 0; i < p.Size(); i++)
        {
            result[i] = p[i];
        }
        return result;
    }

    DllExport void urho_unsubscribe(NotificationProxy* proxy) { proxy->Unsub(); }

    DllExport void UI_LoadLayoutToElement(Urho3D::UI* _target, Urho3D::UIElement* to, Urho3D::ResourceCache* cache,
                                          const char* name)
    {
        SharedPtr<UIElement> layoutRoot = _target->LoadLayout(cache->GetResource<XMLFile>(name));
        to->AddChild(layoutRoot);
    }

    DllExport int Scene_LoadXMLFromCache(Urho3D::Scene* _target, Urho3D::ResourceCache* cache, const char* name)
    {
        SharedPtr<File> file = cache->GetFile(name);
        return _target->LoadXML(*file);
    }

    DllExport void* TouchState_GetTouchedElement(TouchState* state) { return (void*)state->GetTouchedElement(); }

    DllExport const char* Urho_GetPlatform() { return stringdup(GetPlatform().CString()); }

    DllExport unsigned int urho_stringhash_from_string(const char* p)
    {
        StringHash foo(p);
        return foo.Value();
    }

    DllExport Skeleton* AnimatedModel_GetSkeleton(AnimatedModel* model) { return &model->GetSkeleton(); }

    DllExport unsigned Controls_GetButtons(Controls* controls) { return controls->buttons_; }

    DllExport void* Graphics_GetSdlWindow(Graphics* target) { return target->GetWindow(); }

    DllExport void Controls_SetButtons(Controls* controls, unsigned value) { controls->buttons_ = value; }

    DllExport float Controls_GetYaw(Controls* controls) { return controls->yaw_; }

    DllExport void Controls_SetYaw(Controls* controls, float value) { controls->yaw_ = value; }

    DllExport float Controls_GetPitch(Controls* controls) { return controls->pitch_; }

    DllExport void Controls_SetPitch(Controls* controls, float value) { controls->pitch_ = value; }

    DllExport void Controls_Reset(Urho3D::Controls* _target) { _target->Reset(); }

    DllExport void Controls_Set(Urho3D::Controls* _target, unsigned int buttons, int down)
    {
        _target->Set(buttons, down);
    }

    DllExport int Controls_IsDown(Urho3D::Controls* _target, unsigned int button) { return _target->IsDown(button); }

#if !defined(UWP)
    DllExport int Network_Connect(Network* net, const char* ptr, short port, Scene* scene)
    {
        String s(ptr);
        return net->Connect(s, port, scene) ? 1 : 0;
    }

    DllExport const Controls* Connection_GetControls(Connection* conn) { return &conn->GetControls(); }
    DllExport void Connection_SetControls(Connection* conn, Controls* ctl) { conn->SetControls(*ctl); }
#endif

    DllExport Controls* Controls_Create() { return new Controls(); }

    DllExport void Controls_Destroy(Controls* controls) { delete controls; }

    DllExport RayQueryResult* Octree_Raycast(Octree* octree, const Urho3D::Ray& ray, const Urho3D::RayQueryLevel& level,
                                             float maxDistance, unsigned int flags, unsigned int viewMask, bool single,
                                             int* count)
    {
        PODVector<RayQueryResult> results;
        auto size = sizeof(RayQueryResult);
        RayOctreeQuery query(results, ray, level, maxDistance, flags, viewMask);
        if (single)
            octree->RaycastSingle(query);
        else
            octree->Raycast(query);

        if (results.Size() == 0)
            return NULL;

        RayQueryResult* result = new RayQueryResult[results.Size()];
        *count = results.Size();
        for (int i = 0; i < results.Size(); i++)
        {
            result[i] = results[i];
        }
        return result;
    }

    DllExport void Console_OpenConsoleWindow() { OpenConsoleWindow(); }

    DllExport const char* Console_GetConsoleInput() { return stringdup(GetConsoleInput().CString()); }

    //
    // returns: null on no matches
    // otherwise, a pointer that should be released with free() that
    // contains a first element (pointer sized) with the number of elements
    // followed by the number of pointers
    //
    DllExport void* urho_node_get_components(Node* node, int code, int recursive, int* count)
    {
        PODVector<Node*> dest;
        node->GetChildrenWithComponent(dest, StringHash(code), recursive);
        if (dest.Size() == 0)
            return NULL;
        *count = dest.Size();
        void** t = (void**)malloc(sizeof(Node*) * dest.Size());
        for (int i = 0; i < dest.Size(); i++)
        {
            t[i] = dest[i];
        }
        return t;
    }

    DllExport void* Node_GetChildrenWithTag(Node* node, const char* tag, bool recursive, int* count)
    {
        PODVector<Node*> dest;
        node->GetChildrenWithTag(dest, String(tag), recursive);
        if (dest.Size() == 0)
            return NULL;
        *count = dest.Size();
        void** t = (void**)malloc(sizeof(Node*) * dest.Size());
        for (int i = 0; i < dest.Size(); i++)
        {
            t[i] = dest[i];
        }
        return t;
    }

    DllExport void* Node_GetChildren2(Node* node, bool recursive, int* count)
    {
        PODVector<Node*> dest;
        node->GetChildren(dest, recursive);
        if (dest.Size() == 0)
            return NULL;
        *count = dest.Size();
        void** t = (void**)malloc(sizeof(Node*) * dest.Size());
        for (int i = 0; i < dest.Size(); i++)
        {
            t[i] = dest[i];
        }
        return t;
    }

    DllExport void Node_RemoveComponent22(Urho3D::Node* _target, Urho3D::Component* component)
    {
        _target->RemoveComponent(component);
    }

    DllExport Interop::Vector3* urho_navigationmesh_findpath(NavigationMesh* navMesh,
                                                             const class Urho3D::Vector3& start,
                                                             const class Urho3D::Vector3& end, int* count)
    {
        PODVector<Vector3> dest;
        navMesh->FindPath(dest, start, end);
        if (dest.Size() == 0)
            return NULL;
        *count = dest.Size();
        Interop::Vector3* results = new Interop::Vector3[dest.Size()];
        for (int i = 0; i < dest.Size(); i++)
        {
            auto vector = *((Interop::Vector3*)&(dest[i]));
            results[i] = vector;
        }
        return results;
    }

    DllExport int* Graphics_GetMultiSampleLevels(Graphics* target, int* count)
    {
        PODVector<int> levels = target->GetMultiSampleLevels();
        *count = levels.Size();
        int* result = new int[levels.Size()];
        for (int i = 0; i < levels.Size(); i++)
        {
            result[i] = levels[i];
        }
        return result;
    }

    DllExport MemoryBuffer* MemoryBuffer_MemoryBuffer(void* data, int size)
    {
        auto buffer = new MemoryBuffer(data, size);
        return buffer;
    }

    DllExport unsigned char* MemoryBuffer_GetData(MemoryBuffer* target, int* count)
    {
        *count = target->GetSize();
        return target->GetData();
    }

    DllExport void MemoryBuffer_Dispose(MemoryBuffer* target) { delete target; }

    DllExport unsigned MemoryBuffer_GetSize(MemoryBuffer* target) { return target->GetSize(); }

    DllExport const char* MemoryBuffer_GetString(MemoryBuffer* target)
    {
        return stringdup(target->ReadString().CString());
    }

    DllExport unsigned File_GetSize(File* target) { return target->GetSize(); }

    DllExport Interop::Vector3* Frustum_GetVertices(Frustum* frustum, int* count)
    {
        int size = NUM_FRUSTUM_VERTICES;
        Interop::Vector3* results = new Interop::Vector3[size];
        for (int i = 0; i < size; i++)
        {
            auto vector = *((Interop::Vector3*)&(frustum->vertices_[i]));
            results[i] = vector;
        }
        *count = size;
        return results;
    }

    DllExport Interop::Plane* Frustum_GetPlanes(Frustum* frustum, int* count)
    {
        int size = NUM_FRUSTUM_PLANES;
        Interop::Plane* results = new Interop::Plane[size];
        for (int i = 0; i < size; i++)
        {
            auto plane = *((Interop::Plane*)&(frustum->planes_[i]));
            results[i] = plane;
        }
        *count = size;
        return results;
    }

#ifdef __EMSCRIPTEN__
    DllExport Interop::Color* Material_GetShaderParameterColor(Urho3D::Material* _target, const char* paramName)
    {
        return ((Interop::Color*)&(_target->GetShaderParameter(Urho3D::String(paramName)).GetColor()));
    }
#else
    DllExport Interop::Color Material_GetShaderParameterColor(Urho3D::Material* _target, const char* paramName)
    {
        return *((Interop::Color*)&(_target->GetShaderParameter(Urho3D::String(paramName)).GetColor()));
    }
#endif

    DllExport unsigned char* Image_GetDataBytes(Urho3D::Image* _target, int* len)
    {
        *len = _target->GetWidth() * _target->GetHeight() * _target->GetDepth() * _target->GetComponents();
        return _target->GetData();
    }

    DllExport unsigned char* Image_SavePNG2(Urho3D::Image* _target, int* len) { return _target->SavePNG(len); }

    DllExport void FreeBuffer(unsigned char* myBuffer) { delete myBuffer; }

    DllExport void RenderPathCommand_SetShaderParameter_float(RenderPathCommand* rpc, const char* parameter,
                                                              float value)
    {
        rpc->SetShaderParameter(String(parameter), value);
    }

    DllExport void RenderPathCommand_SetShaderParameter_Matrix4(RenderPathCommand* rpc, const char* parameter,
                                                                const class Urho3D::Matrix4& value)
    {
        rpc->SetShaderParameter(String(parameter), value);
    }

    DllExport void RenderPathCommand_SetOutput(RenderPathCommand* rpc, int index, const char* name)
    {
        rpc->SetOutput(index, String(name));
    }

    DllExport int Input_GetMouseButtonDown(Urho3D::Input* _target, int button)
    {
        return _target->GetMouseButtonDown(MouseButtonFlags(button));
    }

    DllExport int Input_GetMouseButtonPress(Urho3D::Input* _target, int button)
    {
        return _target->GetMouseButtonPress(MouseButtonFlags(button));
    }

    DllExport Urho3D::Bone* Skeleton_GetBone0(Urho3D::Skeleton* _target, int boneNameHash)
    {
        return _target->GetBone(Urho3D::StringHash(boneNameHash));
    }

    DllExport unsigned int Camera_GetViewOverrideFlags(Urho3D::Camera* _target)
    {
        return _target->GetViewOverrideFlags();
    }

    DllExport void Camera_SetViewOverrideFlags(Urho3D::Camera* _target, unsigned int flags)
    {
        _target->SetViewOverrideFlags(ViewOverrideFlags(flags));
    }

    DllExport unsigned int VertexBuffer_GetElementMask(Urho3D::VertexBuffer* _target)
    {
        unsigned int mask = _target->GetElementMask();
        return mask;
    }

    DllExport void String_FreeNativeString(char* str)
    {
        /*
        if(str)
        {
            free(str);
        }
         */
    }

    DllExport const char* Variant_GetTypeName(Variant& v) { return stringdup(v.GetTypeName().CString()); }

    DllExport Variant Variant_CreateInt(int i)
    {
        Variant v = i;
        return v;
    }

    DllExport int Variant_GetInt(Variant& v) { return v.GetInt(); }

    DllExport Variant Variant_CreateBool(bool val)
    {
        Variant v = val;
        return v;
    }

    DllExport bool Variant_GetBool(Variant& v) { return v.GetBool(); }

    DllExport Variant Variant_CreateFloat(float f)
    {
        Variant v = f;
        return v;
    }

    DllExport float Variant_GetFloat(Variant& v) { return v.GetFloat(); }

    DllExport Variant Variant_CreateVector2(Interop::Vector2 vec)
    {
        Variant v = Vector2(vec.x, vec.y);
        return v;
    }

    DllExport Interop::Vector2 Variant_GetVector2(Variant& v) { return *((Interop::Vector2*)&(v.GetVector2())); }

    DllExport Variant Variant_CreateVector3(Interop::Vector3 vec)
    {
        Variant v = Vector3(vec.x, vec.y, vec.z);
        return v;
    }

    DllExport Interop::Vector3 Variant_GetVector3(Variant& v) { return *((Interop::Vector3*)&(v.GetVector3())); }

    DllExport Variant Variant_CreateVector4(Interop::Vector4 vec)
    {
        Variant v = Vector4(vec.x, vec.y, vec.z, vec.w);
        return v;
    }

    DllExport Interop::Vector4 Variant_GetVector4(Variant& v) { return *((Interop::Vector4*)&(v.GetVector4())); }

    DllExport Variant Variant_CreateQuaternion(Interop::Quaternion q)
    {
        Variant v = Quaternion(q.w, q.x, q.y, q.z);
        return v;
    }

    DllExport Interop::Quaternion Variant_GetQuaternion(Variant& v)
    {
        return *((Interop::Quaternion*)&(v.GetQuaternion()));
    }

    DllExport Variant Variant_CreateColor(Interop::Color c)
    {
        Variant v = Color(c.r, c.g, c.b, c.a);
        return v;
    }

    DllExport Interop::Color Variant_GetColor(Variant& v) { return *((Interop::Color*)&(v.GetColor())); }

    DllExport Variant Variant_CreateDouble(double f)
    {
        Variant v = f;
        return v;
    }

    DllExport double Variant_GetDouble(Variant& v) { return v.GetDouble(); }

    DllExport Variant Variant_CreateString(const char* value)
    {
        Variant v = value;
        return v;
    }

    DllExport const char* Variant_GetString(Variant& variant)
    {
        String urhoString = variant.GetString();
        return stringdup(urhoString.CString());
    }

    DllExport const char* Variant_ToString(Variant& variant)
    {
        String urhoString = variant.ToString();
        return stringdup(urhoString.CString());
    }

    DllExport void Variant_CreateBuffer(void* data, int size, Variant& v) { v = VectorBuffer(data, size); }

    DllExport unsigned char* Variant_GetBuffer(Variant& v, int* count)
    {
        const PODVector<unsigned char>& pod = v.GetBuffer();
        *count = pod.Size();
        return pod.Buffer();
    }

    static VariantMap Variant_GetVariantMap_VariantMap;
    DllExport const VariantMap* Variant_GetVariantMap(Variant& variant)
    {
        Variant_GetVariantMap_VariantMap = variant.GetVariantMap();
        return &Variant_GetVariantMap_VariantMap;
    }

    DllExport bool Variant_EqualityOperator(Variant& variant1, Variant& variant2) { return variant1 == variant2; }

    DllExport void urho_map_get_value(VariantMap& nativeInstance, int key, Variant& value)
    {
        value = nativeInstance[StringHash(key)];
    }

    DllExport bool urho_map_contains_value(VariantMap& nativeInstance, int key)
    {
        return nativeInstance.Contains(StringHash(key));
    }

    DllExport void urho_map_set_value(VariantMap& nativeInstance, int key, Variant& value)
    {
        nativeInstance[StringHash(key)] = value;
    }

    DllExport void urho_map_set_value_ptr(VariantMap& nativeInstance, int key, Variant* value)
    {
        nativeInstance[StringHash(key)] = *value;
    }

    DllExport unsigned urho_map_get_keys_size(VariantMap& nativeInstance) { return nativeInstance.Keys().Size(); }

    DllExport void urho_map_keys_get_keys(VariantMap& nativeInstance, unsigned int* buffer)
    {
        Vector<StringHash> keys = nativeInstance.Keys();
        for (unsigned i = 0; i < keys.Size(); i++)
        {
            buffer[i] = keys[i].ToHash();
        }
    }

    DllExport unsigned urho_map_keys_get_key(VariantMap& nativeInstance, int index)
    {
        unsigned value = nativeInstance.Keys()[index].Value();
        return value;
    }

    static char conversionNumbersBuffer[CONVERSION_BUFFER_LENGTH];

    DllExport char* float_convert_to_string(float value)
    {
        sprintf(conversionNumbersBuffer, "%g", value);
        return conversionNumbersBuffer;
    }

    DllExport char* double_convert_to_string(double value)
    {

        sprintf(conversionNumbersBuffer, "%g", value);
        return conversionNumbersBuffer;
    }

    /*DYNAMIC*/

    DllExport Variant* Dynamic_CreateFromType(VariantType type, const char* value)
    {
        Variant* v = new Variant(type, value);
        return v;
    }

    //
    DllExport Variant* Dynamic_CreateVariant(Variant& value)
    {
        Variant* v = new Variant(value);
        return v;
    }

    DllExport Variant* Dynamic_CreateBool(bool val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateInt(int val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateUInt(unsigned int val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateInt64(long long val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateUInt64(unsigned long long val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateFloat(float val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateDouble(double val)
    {
        Variant* v = new Variant(val);
        return v;
    }

    DllExport Variant* Dynamic_CreateVector2(Interop::Vector2 val)
    {
        Variant* v = new Variant(Vector2(val.x, val.y));
        return v;
    }

    DllExport Variant* Dynamic_CreateVector3(Interop::Vector3 val)
    {
        Variant* v = new Variant(Vector3(val.x, val.y, val.z));
        return v;
    }

    DllExport Variant* Dynamic_CreateVector4(Interop::Vector4 val)
    {
        Variant* v = new Variant(Vector4(val.x, val.y, val.z, val.w));
        return v;
    }

    DllExport Variant* Dynamic_CreateQuaternion(Interop::Quaternion q)
    {
        Variant* v = new Variant(Quaternion(q.w, q.x, q.y, q.z));
        return v;
    }

    DllExport Variant* Dynamic_CreateColor(Interop::Color c)
    {
        Variant* v = new Variant(Color(c.r, c.g, c.b, c.a));
        return v;
    }

    DllExport Variant* Dynamic_CreateIntVector2(Interop::IntVector2 val)
    {
        Variant* v = new Variant(IntVector2(val.x, val.y));
        return v;
    }

    DllExport Variant* Dynamic_CreateIntVector3(Interop::IntVector3 val)
    {
        Variant* v = new Variant(IntVector3(val.x, val.y, val.z));
        return v;
    }

    DllExport Variant* Dynamic_CreateIntRect(Interop::IntRect val)
    {
        // int left, int top, int right, int bottom
        Variant* v = new Variant(IntRect(val.left, val.top, val.right, val.bottom));
        return v;
    }

    DllExport Variant* Dynamic_CreateRect(Interop::Rect val)
    {
        Variant* v = new Variant(Rect(val.min.x, val.min.y, val.max.x, val.max.y));
        return v;
    }

    DllExport Variant* Dynamic_CreateMatrix3(Interop::Matrix3 val)
    {
        Variant* v =
            new Variant(Matrix3(val.m00, val.m01, val.m02, val.m10, val.m11, val.m12, val.m20, val.m21, val.m22));

        Matrix3 mat = v->GetMatrix3();

        //  printf("Dynamic_CreateMatrix3 : %g:%g:%g %g:%g:%g %g:%g:%g \n",mat.m00_,mat.m01_,mat.m02_,
        //  mat.m10_,mat.m11_,mat.m12_ , mat.m20_,mat.m21_,mat.m22_);

        return v;
    }

#ifdef __EMSCRIPTEN__
    DllExport Interop::Matrix3* Dynamic_GetMatrix3(Variant* v) { return ((Interop::Matrix3*)&(v->GetMatrix3())); }
#else
    DllExport Interop::Matrix3 Dynamic_GetMatrix3(Variant* v) { return *((Interop::Matrix3*)&(v->GetMatrix3())); }
#endif

    DllExport Variant* Dynamic_CreateMatrix4(Interop::Matrix4 val)
    {
        Variant* v = new Variant(Matrix4(val.m00, val.m01, val.m02, val.m03, val.m10, val.m11, val.m12, val.m13,
                                         val.m20, val.m21, val.m22, val.m23, val.m30, val.m31, val.m32, val.m33));
        return v;
    }

#ifdef __EMSCRIPTEN__
    DllExport Interop::Matrix4* Dynamic_GetMatrix4(Variant* v) { return ((Interop::Matrix4*)&(v->GetMatrix4())); }
#else
    DllExport Interop::Matrix4 Dynamic_GetMatrix4(Variant* v) { return *((Interop::Matrix4*)&(v->GetMatrix4())); }
#endif

    DllExport Variant* Dynamic_CreateMatrix3x4(Interop::Matrix3x4 val)
    {
        Variant* v = new Variant(Matrix3x4(val.m00, val.m01, val.m02, val.m03, val.m10, val.m11, val.m12, val.m13,
                                           val.m20, val.m21, val.m22, val.m23));
        return v;
    }

#ifdef __EMSCRIPTEN__
    DllExport Interop::Matrix3x4* Dynamic_GetMatrix3x4(Variant* v)
    {
        return ((Interop::Matrix3x4*)&(v->GetMatrix3x4()));
    }
#else
    DllExport Interop::Matrix3x4 Dynamic_GetMatrix3x4(Variant* v)
    {
        return *((Interop::Matrix3x4*)&(v->GetMatrix3x4()));
    }
#endif

    DllExport Variant* Dynamic_CreateString(const char* value)
    {
        Variant* v = new Variant(value);
        return v;
    }

    DllExport const char* Dynamic_GetString(Variant* variant)
    {
        String urhoString = variant->GetString();
        return stringdup(urhoString.CString());
    }

    DllExport Variant* Dynamic_CreateBuffer(void* data, int size)
    {
        Variant* v = new Variant(VectorBuffer(data, size));
        return v;
    }

    DllExport unsigned char* Dynamic_GetBuffer(Variant* v, int* count)
    {
        const PODVector<unsigned char>& pod = v->GetBuffer();
        *count = pod.Size();
        return pod.Buffer();
    }

    DllExport Variant* Dynamic_CreateResourceRef(int type, const char* name)
    {
        Variant* v = new Variant(ResourceRef(StringHash(type), name));
        return v;
    }

    DllExport ResourceRef* Dynamic_GetResourceRef(Variant* v) { return ((ResourceRef*)&(v->GetResourceRef())); }

    DllExport void Dynamic_GetRetVariant(Variant* v, Variant* var) { *var = *v; }

    DllExport Variant* Dynamic_CreateResourceRefList(int type, const Vector<String>* stringVector)
    {
        ResourceRefList resourceRefList;
        resourceRefList.type_ = StringHash(type);
        resourceRefList.names_.Push(*stringVector);
        Variant* v = new Variant(resourceRefList);
        return v;
    }

    DllExport void Dynamic_ResourceRefList_AddName(Variant* v, const char* name)
    {
        ResourceRefList resourceRefList = v->GetResourceRefList();
        resourceRefList.names_.Push(String(name));
    }

    DllExport Variant* Dynamic_CreateVariantVector(int count)
    {
        VariantVector variantVector(count);
        Variant* v = new Variant(variantVector);
        return v;
    }

    DllExport void Dynamic_VariantVector_AddVariant(Variant* v, Variant& value, int index)
    {
        VariantVector variantVector = v->GetVariantVector();
        variantVector[index] = value;
        *v = variantVector;
    }

    DllExport void Dynamic_Dispose(Variant* target) { delete target; }

    DllExport void Connection_SendRemoteEvent(Connection* conn, int eventType, bool inOrder, VariantMap& eventData)
    {
        conn->SendRemoteEvent(StringHash(eventType), inOrder, eventData);
    }

    DllExport void Connection_SendRemoteEvent2(Connection* conn, Node* node, int eventType, bool inOrder,
                                               VariantMap& eventData)
    {
        conn->SendRemoteEvent(node, StringHash(eventType), inOrder, eventData);
    }

    DllExport void* Network_GetClientConnections(Network* network, int* count)
    {
        const Vector<SharedPtr<Connection>>& dest = network->GetClientConnections();
        *count = 0;

        if (dest.Size() == 0)
            return NULL;

        *count = dest.Size();

        void** t = (void**)malloc(sizeof(Connection*) * dest.Size());
        for (int i = 0; i < dest.Size(); i++)
        {
            t[i] = dest[i];
        }
        return t;
    }

    DllExport void VoidPtr_Free(void* ptr) { free(ptr); }

    DllExport void KinematicCharacterController_GetTransform(Urho3D::KinematicCharacterController* _target,
                                                             Interop::Vector3* position, Interop::Quaternion* rotation)
    {
        Vector3 _pos;
        Quaternion _rot;

        _target->GetTransform(_pos, _rot);

        *position = *((Interop::Vector3*)&(_pos));
        *rotation = *((Interop::Quaternion*)&(_rot));
    }

#ifdef __EMSCRIPTEN__
    DllExport Variant* Node_GetVar(Urho3D::Node* _target, int key)
    {
        return (Urho3D::Variant*)(&_target->GetVar(Urho3D::StringHash(key)));
    }
#else
    DllExport Variant Node_GetVar(Urho3D::Node* _target, int key) { return _target->GetVar(Urho3D::StringHash(key)); }
#endif

#ifdef __EMSCRIPTEN_
    static matrix3x4 Matrix3x4_Create_matrix3x4;
    DllExport Interop::Matrix3x4* Matrix3x4_Create(Vector3& translation, Quaternion& rotation, Vector3& scale)
    {
        Matrix3x4_Create_matrix3x4 = Matrix3x4(translation, rotation, scale);
        return ((Interop::Matrix3x4*)&(Matrix3x4_Create_matrix3x4));
    }
#else
    DllExport Interop::Matrix3x4 Matrix3x4_Create(Vector3& translation, Quaternion& rotation, Vector3& scale)
    {
        Matrix3x4 matrix3x4(translation, rotation, scale);
        return *((Interop::Matrix3x4*)&(matrix3x4));
    }
#endif

#ifdef __EMSCRIPTEN_
    static matrix3x4 Matrix3x4_Multiply_matrix3x4;
    DllExport Interop::Matrix3x4* Matrix3x4_Multiply(Matrix3x4& left, Matrix3x4& right)
    {
        Matrix3x4_Multiply_matrix3x4 = left * right;
        return ((Interop::Matrix3x4*)&(Matrix3x4_Multiply_matrix3x4));
    }
#else
    DllExport Interop::Matrix3x4 Matrix3x4_Multiply(Matrix3x4& left, Matrix3x4& right)
    {
        Matrix3x4 matrix3x4 = left * right;
        return *((Interop::Matrix3x4*)&(matrix3x4));
    }
#endif

    DllExport Interop::Vector3 Matrix3x4_Translation(Matrix3x4& matrix3x4)
    {
        Vector3 translation = matrix3x4.Translation();
        return *((Interop::Vector3*)&(translation));
    }

    DllExport Interop::Quaternion Matrix3x4_Rotation(Matrix3x4& matrix3x4)
    {
        Quaternion rotation = matrix3x4.Rotation();
        return *((Interop::Quaternion*)&(rotation));
    }

    DllExport void Profiler_BeginBlock(Urho3D::Profiler* _target, const char* name) { _target->BeginBlock(name); }

    DllExport uint JoystickState_GetNumButtons(Urho3D::JoystickState* _target) { return _target->GetNumButtons(); }

    DllExport bool JoystickState_GetButtonDown(Urho3D::JoystickState* _target, int position)
    {
        return _target->GetButtonDown(position);
    }

    DllExport uint JoystickState_GetNumHats(Urho3D::JoystickState* _target) { return _target->GetNumHats(); }

    DllExport int JoystickState_GetHatPosition(Urho3D::JoystickState* _target, uint index)
    {
        return _target->GetHatPosition(index);
    }

    DllExport uint JoystickState_GetNumAxes(Urho3D::JoystickState* _target) { return _target->GetNumAxes(); }

    DllExport float JoystickState_GetAxisPosition(Urho3D::JoystickState* _target, uint index)
    {
        return _target->GetAxisPosition(index);
    }

    DllExport void* PhysicsWorld2D_GetRigidBodies(Urho3D::PhysicsWorld2D* _target, const class Urho3D::Rect& aabb,
                                                  unsigned collisionMask, int* count)
    {
        PODVector<RigidBody2D*> results;
        _target->GetRigidBodies(results, aabb, collisionMask);
        if (results.Size() == 0)
            return NULL;
        *count = results.Size();
        void** t = (void**)malloc(sizeof(RigidBody2D*) * results.Size());
        for (int i = 0; i < results.Size(); i++)
        {
            t[i] = results[i];
        }
        return t;
    }

    static Vector<String> resultFilesInResourceDirs;

    DllExport int ResourceCache_GetFilesInResourceDirs(Urho3D::ResourceCache* _target, const char* name,
                                                       const char* filter, bool recursive)
    {
        resultFilesInResourceDirs.Clear();
        _target->GetFilesInResourceDirs(resultFilesInResourceDirs, name, filter, recursive);
        return resultFilesInResourceDirs.Size();
    }

    DllExport const char* ResourceCache_GetFromResultFileInResourceDirs(Urho3D::ResourceCache* _target, int index)
    {
        if (index >= 0 && index < resultFilesInResourceDirs.Size())
        {
            return stringdup(resultFilesInResourceDirs[index].CString());
        }
        else
        {
            return stringdup("");
        }
    }

    DllExport void ResourceCache_ClearVectorResultFilesInResourceDirs(Urho3D::ResourceCache* _target)
    {
        resultFilesInResourceDirs.Clear();
    }

    DllExport int ResourceCache_GetResourceDirsCount(Urho3D::ResourceCache* _target)
    {
        Vector<String> resourceDirs = _target->GetResourceDirs();
        return resourceDirs.Size();
    }

    DllExport const char* ResourceCache_GetResourceDir(Urho3D::ResourceCache* _target, int index)
    {
        Vector<String> resourceDirs = _target->GetResourceDirs();
        if (index >= 0 && index < resourceDirs.Size())
        {
            return stringdup(resourceDirs[index].CString());
        }
        else
        {
            return stringdup("");
        }
    }

    DllExport void* DbConnection_GetSQLite3Implementation(Urho3D::DbConnection* _target)
    {
        const sqlite3* sqlConnection = _target->GetConnectionImpl();
        return (void*)sqlConnection;
    }

    DllExport void* sqlite3_connection_prepare(sqlite3* connectionImpl_, const char* sqlQuery)
    {

        if (connectionImpl_ == nullptr)
            return nullptr;

        sqlite3_stmt* pStmt = nullptr;
        const char* zLeftover = nullptr;
        String trimmedSqlStr = String(sqlQuery).Trimmed();

        int rc = sqlite3_prepare_v2(connectionImpl_, trimmedSqlStr.CString(), -1, &pStmt, &zLeftover);
        if (rc != SQLITE_OK)
        {
            URHO3D_LOGERRORF("Could not execute: %s", sqlite3_errmsg(connectionImpl_));
            pStmt = nullptr;
            return nullptr;
        }

        if (*zLeftover)
        {
            URHO3D_LOGERROR("Could not execute: only one SQL statement is allowed");
            sqlite3_finalize(pStmt);
            return nullptr;
        }

        return pStmt;
    }

    DllExport int sqlite3_connection_changes(sqlite3* connectionImpl_)
    {
        if (connectionImpl_ == nullptr)
            return -1;

        return sqlite3_changes(connectionImpl_);
    }

    DllExport int sqlite3_connection_finalize(sqlite3_stmt* pStmt)
    {
        if (pStmt == nullptr)
            return -1;
        return sqlite3_finalize(pStmt);
    }

    DllExport int sqlite3_connection_column_count(sqlite3_stmt* pStmt)
    {
        if (pStmt == nullptr)
            return -1;
        return (int)sqlite3_column_count(pStmt);
    }

    DllExport const char* sqlite3_connection_column_name(sqlite3_stmt* pStmt, int index)
    {
        if (pStmt == nullptr)
            return nullptr;
        return stringdup(sqlite3_column_name(pStmt, index));
    }

    DllExport int sqlite3_connection_column_step(sqlite3_stmt* pStmt) { return sqlite3_step(pStmt); }

    DllExport int sqlite3_connection_column_type(sqlite3_stmt* pStmt, int index)
    {
        if (pStmt == nullptr)
            return -1;
        return sqlite3_column_type(pStmt, index);
    }

    DllExport int sqlite3_connection_column_int(sqlite3_stmt* pStmt, int index)
    {
        if (pStmt == nullptr)
            return -1;
        return sqlite3_column_int(pStmt, index);
    }

    DllExport double sqlite3_connection_column_double(sqlite3_stmt* pStmt, int index)
    {
        if (pStmt == nullptr)
            return -1;
        return sqlite3_column_double(pStmt, index);
    }

    DllExport const char* sqlite3_connection_column_decltype(sqlite3_stmt* pStmt, int index)
    {
        if (pStmt == nullptr)
            return nullptr;
        return stringdup(sqlite3_column_decltype(pStmt, index));
    }

    DllExport const char* sqlite3_connection_column_text(sqlite3_stmt* pStmt, int index)
    {
        if (pStmt == nullptr)
            return nullptr;
        return stringdup((const char*)sqlite3_column_text(pStmt, index));
    }

    DllExport void delete_vector3_pointer(const class Urho3D::Vector3* vector3_ptr)
    {
        if (vector3_ptr != nullptr)
        {
            delete[] vector3_ptr;
        }
    }

    DllExport Urho3D::Model* Model_Clone_EmptyName(Urho3D::Model* _target)
    {
        auto copy = _target->Clone();
        auto plain = copy.Get();
        copy.Detach();
        delete copy;
        return plain;
    }

    DllExport bool Serializable_SetAttribute_Variant(Urho3D::Serializable* _target, const char* name, Variant* v)
    {
        if (v != NULL)
            return _target->SetAttribute(name, *v);
        else
            return false;
    }

    DllExport bool Serializable_SetAttribute_Variant2(Urho3D::Serializable* _target, const char* name, Variant& v)
    {
        return _target->SetAttribute(name, v);
    }

    DllExport bool Serializable_SetAttribute_Variant3(Urho3D::Serializable* _target, unsigned index, Variant& v)
    {
        return _target->SetAttribute(index, v);
    }

    DllExport bool Serializable_SetAttribute_Variant4(Urho3D::Serializable* _target, unsigned index, Variant* v)
    {
        if (v != NULL)
        {
            return _target->SetAttribute(index, *v);
        }
        else
            return false;
    }

    DllExport const Vector<AttributeInfo>* Serializable_GetAttributes(Urho3D::Serializable* serializable)
    {
        return serializable->GetAttributes();
    }

    DllExport const char* Variant_GetResourceRefName(Variant& variant)
    {
        return stringdup(variant.GetResourceRef().name_.CString());
    }

    DllExport unsigned int Variant_GetResourceRefType(Variant& variant)
    {
        return variant.GetResourceRef().type_.Value();
    }

    DllExport void Variant_GetRetVariant(Variant* v, Variant* var) { *var = *v; }

    DllExport const Variant* Variant_VariantVector_GetVariant(Variant& variant, int index)
    {
        return &(variant.GetVariantVector()[index]);
    }

    DllExport int Variant_VariantVector_GetSize(Variant& variant) { return variant.GetVariantVector().Size(); }

    DllExport const char* Variant_StringVector_GetString(Variant& variant, int index)
    {
        return stringdup(variant.GetStringVector()[index].CString());
    }

    DllExport int Variant_StringVector_GetSize(Variant& variant) { return variant.GetStringVector().Size(); }

    DllExport int Variant_ResourceRefList_GetType(Variant& variant)
    {
        return variant.GetResourceRefList().type_.Value();
    }

    DllExport int Variant_ResourceRefList_Names_GetSize(Variant& variant)
    {
        return variant.GetResourceRefList().names_.Size();
    }

    DllExport const char* Variant_ResourceRefList_Names_GetNameAt(Variant& variant, int index)
    {
        return stringdup(variant.GetResourceRefList().names_[index].CString());
    }

    DllExport void UIElement_SetVar_IntPtr(Urho3D::UIElement* _target, int key, const void* value)
    {
        _target->SetVar(Urho3D::StringHash(key), *((Variant*)value));
    }

    DllExport const PODVector<unsigned>& ListView_GetSelections(Urho3D::ListView* _target)
    {
        return _target->GetSelections();
    }

    DllExport void ListView_SetSelections(Urho3D::ListView* _target, unsigned* data, int size)
    {
        PODVector<unsigned> selections;
        for (int i = 0; i < size; i++)
        {
            selections.Push(data[i]);
        }

        _target->SetSelections(selections);
    }

    DllExport const Vector<AttributeInfo>* Context_GetAttributes(Urho3D::Context* context, int type)
    {
        StringHash attrType(type);
        return context->GetAttributes(attrType);
    }

    DllExport int AttributeVector_GetSize(const Vector<AttributeInfo>* attributes) { return attributes->Size(); }

    DllExport const AttributeInfo* AttributeVector_Attribute_GetHandle(const Vector<AttributeInfo>* attributes,
                                                                       unsigned int index)
    {
        return &attributes->At(index);
    }

    DllExport VariantType AttributeVector_Attribute_GetType(const Vector<AttributeInfo>* attributes, unsigned int index)
    {
        return attributes->At(index).type_;
    }

    DllExport const char* AttributeVector_Attribute_GetName(const Vector<AttributeInfo>* attributes, unsigned int index)
    {
        return attributes->At(index).name_.CString();
    }

    DllExport const Variant AttributeVector_Attribute_GetDefaultValue(const Vector<AttributeInfo>* attributes,
                                                                      unsigned int index)
    {
        return (attributes->At(index).defaultValue_);
    }

    DllExport unsigned int AttributeVector_Attribute_GetMode(const Vector<AttributeInfo>* attributes,
                                                             unsigned int index)
    {
        return attributes->At(index).mode_;
    }

    DllExport void AttributeVector_Attribute_GetEnumNames(const Vector<AttributeInfo>* attributes, int index,
                                                          Vector<String>* stringVector)
    {
        const char** enumNamePtrs = attributes->At(index).enumNames_;

        while (enumNamePtrs && *enumNamePtrs)
            stringVector->Push(*enumNamePtrs++);
    }

    static AttributeInfo attributes_attributeInfo;
    DllExport AttributeInfo* Attributes_GetAttribute(const Vector<AttributeInfo>* attributes, int index)
    {
        attributes_attributeInfo = attributes->At(index);
        return &attributes_attributeInfo;
    }

    DllExport VariantType AttributeInfo_GetType(AttributeInfo* attributeInfo) { return attributeInfo->type_; }

    DllExport const char* AttributeInfo_GetName(AttributeInfo* attributeInfo)
    {
        return stringdup(attributeInfo->name_.CString());
    }

    static Variant UIElement_GetTags_Variant;
    DllExport Variant* UIElement_GetTags(UIElement* target)
    {
        UIElement_GetTags_Variant = target->GetTags();
        return &UIElement_GetTags_Variant;
    }

    DllExport const VariantMap* UIElement_GetVars(UIElement* target) { return &target->GetVars(); }

    static Variant Node_GetTags_Variant;
    DllExport Variant* Node_GetTags(Node* target)
    {
        Node_GetTags_Variant = target->GetTags();
        return &Node_GetTags_Variant;
    }

    DllExport const VariantMap* Node_GetVars(Node* target) { return &target->GetVars(); }

    DllExport bool File_WriteLine(File* file, const char* line) { return file->WriteLine(line); }

    DllExport const char* File_ReadLine(File* file)
    {
        String str = file->ReadLine();
        return stringdup(str.CString());
    }

    DllExport Vector<String>* StringVector_Create()
    {
        Vector<String>* stringVector = new Vector<String>();
        stringVector->Empty();
        return stringVector;
    }

    DllExport int StringVector_GetSize(const Vector<String>* stringVector)
    {
        if (stringVector != NULL)
        {
            return stringVector->Size();
        }
        else
        {
            return 0;
        }
    }

    DllExport const char* StringVector_GetString(const Vector<String>* stringVector, int index)
    {
        if (stringVector != NULL && index >= 0 && index < stringVector->Size())
        {
            return stringVector->At(index).CString();
        }
        else
            return nullptr;
    }

    DllExport bool StringVector_SetString(Vector<String>* stringVector, int index, const char* str)
    {
        bool result = false;
        if (stringVector != NULL && index >= 0 && index < stringVector->Size())
        {
            stringVector->At(index) = str;
            result = true;
        }
        return result;
    }

    DllExport void StringVector_AddString(Vector<String>* stringVector, const char* str)
    {
        if (stringVector != NULL)
        {
            stringVector->Push(str);
        }
    }

    DllExport void StringVector_Empty(const Vector<String>* stringVector) { stringVector->Empty(); }

    DllExport void StringVector_Delete(const Vector<String>* stringVector) { delete stringVector; }

    DllExport void FileSelector_SetFilters(FileSelector* fileSelector, const Vector<String>* filters,
                                           unsigned int defaultIndex)
    {
        fileSelector->SetFilters(*filters, defaultIndex);
    }

    DllExport Skeleton* Model_GetSkeleton(Model* model) { return &model->GetSkeleton(); }

    DllExport void AnimationTrack_PushAnimationKeyFrame(AnimationTrack* animationTrack,
                                                        const AnimationKeyFrame& animationKeyFrame)
    {
        animationTrack->keyFrames_.Push(animationKeyFrame);
    }

    DllExport bool Quaternion_FromLookRotation(Vector3& direction, Vector3& up, Interop::Quaternion* rotation_out)
    {
        Quaternion rotation;
        bool status = rotation.FromLookRotation(direction, up);
        *rotation_out = *((Interop::Quaternion*)&(rotation));
        return status;
    }

    /* elix22 , for some reason couldn't find it in .NET  NetworkInterface*/
    DllExport const char* Network_GetInterfaceBroadcastAddress(const char* name)
    {
        char host[128] = {0};
// TBD elix22 for Windows
#ifndef _WINDOWS
        int sock;
        struct ifreq ifreq;
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock >= 0)
        {
            memset(&ifreq, 0, sizeof ifreq);
            strncpy(ifreq.ifr_name, name, IFNAMSIZ);

            if (ioctl(sock, SIOCGIFBRDADDR, &ifreq) == 0)
            {
                getnameinfo(&ifreq.ifr_broadaddr, sizeof(ifreq.ifr_broadaddr), host, sizeof(host), 0, 0,
                            NI_NUMERICHOST);
            }

            close(sock);
        }
#endif

        return stringdup(host);
    }

    DllExport unsigned Material_GetShaderParameterKeysSize(Urho3D::Material* _target)
    {
        return _target->GetShaderParametersKeysSize();
    }

    DllExport void Material_GetShaderParameterGetKeys(Urho3D::Material* _target, unsigned int* buffer)
    {

        _target->GetShaderParametersKeys(buffer);
    }

    DllExport const MaterialShaderParameter* Material_GetMaterialShaderParameterPtr(Urho3D::Material* _target, int key)
    {
        StringHash h(key);

        return _target->GetMaterialShaderParameterPtr(h);
    }

    DllExport void Drawable2D_SetSourceBatchesVertices(Drawable2D* _target, Vertex2D* vertex2DArraysPointer, int count)
    {
        _target->SetSourceBatches(vertex2DArraysPointer, count);
    }



    DllExport int QoiEncode(const unsigned char *data, const qoi_desc desc,unsigned char *out_bytes)
    {
        return qoi_encode_ext(data,desc,out_bytes);
    }

    DllExport int QoiDecode(const unsigned char *data, int size, qoi_desc *desc,unsigned char *out_pixels)
    {
        return qoi_decode_ext(data,size,desc,out_pixels);
    }

   
}
