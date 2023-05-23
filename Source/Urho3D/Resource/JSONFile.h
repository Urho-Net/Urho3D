//
// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "../Resource/Resource.h"
#include "../Resource/JSONValue.h"

namespace Urho3D
{

/// JSON document resource.
class URHO3D_API JSONFile : public Resource
{
    URHO3D_OBJECT(JSONFile, Resource);

public:
    /// Construct.
    explicit JSONFile(Context* context);
    /// Destruct.
    ~JSONFile() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Load resource from stream. May be called from a worker thread. Return true if successful.
    bool BeginLoad(Deserializer& source) override;
    /// Save resource with default indentation (one tab). Return true if successful.
    bool Save(Serializer& dest) const override;
    /// Save resource with user-defined indentation, only the first character (if any) of the string is used and the length of the string defines the character count. Return true if successful.
    bool Save(Serializer& dest, const String& indendation) const;

    /// Deserialize from a string. Return true if successful.
    bool FromString(const String& source);
    /// Save to a string.
    String ToString(const String& indendation = "\t") const;
    
    String GetString(const String& key);
    int GetInt(const String& key);
    unsigned int GetUInt(const String& key);
    float GetFloat(const String& key);
    double GetDouble(const String&  key);
    bool GetBool(const String& key);

    
    void SetString(const String& key , const String& val);
    void SetInt(const String& key,int val);
    void SetUInt(const String& key,unsigned int val);
    void SetFloat(const String& key,float val);
    void SetDouble(const String&  key,double val);
    void SetBool(const String& key,bool val);
    
    /// Return root value.
    /// @property
    JSONValue& GetRoot() { return root_; }
    /// Return root value.
    const JSONValue& GetRoot() const { return root_; }

private:
    /// JSON root value.
    JSONValue root_;
};



class URHO3D_API JsonBuilder : public Object
{
    URHO3D_OBJECT(JsonBuilder, Object);

public:
    JSONFile *f;

    JSONFile & F() {
        return *f;
    }
    
    JSONFile & data() {
        return *f;
    }

    JsonBuilder(Context* context)
        : Object(context)
    {
        f = new JSONFile(context);
    }

    ~JsonBuilder() 
    {
        delete f;
    }

    JsonBuilder& operator()(const String& key, int v)
    {
        f->GetRoot()[key] = v;
        return *this;
    }

    JsonBuilder& operator()(const String& key, const String& v)
    {
        f->GetRoot()[key] = v;
        return *this;
    }

    JsonBuilder& operator()(const String& key, const char * v)
    {
        f->GetRoot()[key] = v;
        return *this;
    }

  
    JsonBuilder& operator()(const String& key, bool v)
    {
         f->GetRoot()[key] = v;
        return *this;
    }

    JsonBuilder& operator()(const String& key, StringVector & v)
    {
        JSONValue & root = f->GetRoot();
        JSONValue var;
        if (v.Size() == 0)
        {
            var.Push(JSONValue());
            var.Pop();
        }
        else
        {
            for (unsigned int k = 0; k < v.Size(); k++)
                var.Push(JSONValue(v[k]));
        }
        root[key] = var;
        return * this;
    }
    

};

}
