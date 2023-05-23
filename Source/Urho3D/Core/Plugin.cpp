
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

#include "../Precompiled.h"
#include "../Core/Plugin.h"
#include <SDL/SDL_events.h>
#include "../IO/Log.h"
#include "../DebugNew.h"


namespace Urho3D
{

int Plugin::SDL_PLUGIN_EVENT = -1;

Plugin::Plugin(Context* context) :
    Object(context)
{
   if(SDL_PLUGIN_EVENT == -1)
   {
       SDL_PLUGIN_EVENT = SDL_RegisterEvents(1);
   }
}

Plugin::~Plugin()
{

}

void Plugin::sendEvent(String evt)
{
    auto jsonBuilder = (MakeShared<JsonBuilder>(context_));
    (*jsonBuilder)("source", this->GetTypeName().CString())("event", evt);
    
    OnPluginEvent(jsonBuilder->F());
}

void Plugin::OnPluginEvent(JSONFile & jsonData)
{
    String strData = jsonData.ToString();
    VariantMap* pArgs = new VariantMap;
    (*pArgs)[PluginNotify::P_DATA] = strData;
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_PLUGIN_EVENT;
    event.user.data2 = pArgs;
    event.user.code = E_PLUGIN_NOTIFY.Value();
    SDL_PushEvent(&event);
}

void Plugin::OnPluginEvent(String strData)
{
    VariantMap* pArgs = new VariantMap;
    (*pArgs)[PluginNotify::P_DATA] = strData;
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_PLUGIN_EVENT;
    event.user.data2 = pArgs;
    event.user.code = E_PLUGIN_NOTIFY.Value();
    SDL_PushEvent(&event);
}


bool Plugin::PostCommand(Context * context , const String& method, JSONFile& data)
{
#ifdef __ANDROID__
        return PostCommandToAndroid(context,method,data);
#elif defined(IOS)
        return PostCommandToIOS(context,method,data);
#else
        return HandleCommand(context, method, data);
#endif
}

}
