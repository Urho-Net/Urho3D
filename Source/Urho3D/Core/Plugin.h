
//
// Copyright (c) 2008-2021 the Urho3D project.
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

#include "../Core/Object.h"
#include "../Resource/JSONFile.h"

namespace Urho3D
{

class Context;

// Notify posted from plugin
URHO3D_EVENT(E_PLUGIN_NOTIFY, PluginNotify)
{
    URHO3D_PARAM(P_DATA, Data); // String
}

class URHO3D_API Plugin : public Object
{
    URHO3D_OBJECT(Plugin, Object);

public:

       /// Construct.
    explicit Plugin(Context* context);
    /// Destruct.
    ~Plugin() override;
    
    bool PostCommand(Context * context , const String& method, JSONFile& data);
    
    virtual bool PostCommandToIOS(Context * context ,const String& method,JSONFile& data){return false;}
    virtual bool PostCommandToAndroid(Context * context ,const String& method,JSONFile& data){return false;}
    virtual bool HandleCommand(Context * context ,const String& method,JSONFile& data){return false;}
    
    virtual bool LoadAndroidPlugin(){return true;}

    void sendEvent(String evt);

    static void OnPluginEvent(String strData);
    
    void OnPluginEvent(JSONFile & jsonData);
    
    static int SDL_PLUGIN_EVENT;
 
#if defined(IOS)
    void * ios_plugin_handle;
#endif

};

}
