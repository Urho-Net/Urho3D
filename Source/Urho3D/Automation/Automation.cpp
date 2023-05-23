//
// Copyright (c) 2008-2022 the Urho3D project.
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

#include "Automation.h"
#include "../Core/Context.h"
#include "../IO/Log.h"
#include "../IO/File.h"
#include "../IO/FileSystem.h"
#include "../Resource/ResourceCache.h"
#include "../Graphics/Texture2D.h"


namespace Urho3D
{

#ifdef URHO3D_AUTOMATION
Robot::Button UrhoMouseButtonToRobotMouseButton(MouseButton button)
{
    
    Robot::Button robotButton = Robot::Button::ButtonLeft;
    
    switch (button) {
        case MouseButton::MOUSEB_LEFT:
            robotButton = Robot::Button::ButtonLeft;
            break;
        case MouseButton::MOUSEB_MIDDLE:
            robotButton = Robot::Button::ButtonMid;
            break;
        case MouseButton::MOUSEB_RIGHT :
            robotButton = Robot::Button::ButtonRight;
            break;
        case MouseButton::MOUSEB_X1 :
            robotButton = Robot::Button::ButtonX1;
            break;
        case MouseButton::MOUSEB_X2 :
            robotButton = Robot::Button::ButtonX2;
            break;
        default:
            break;
    }
    
    return  robotButton;;
}
#endif

Automation::Automation(Context* context)
: Object(context)

{
    
}

Automation::~Automation() {  }

void  Automation::MouseClick(MouseButton button) const
{
#ifdef URHO3D_AUTOMATION
    Robot::Button rbButton = UrhoMouseButtonToRobotMouseButton(button);
    _mouse.Click (rbButton);
#endif
}

bool Automation::IsAvaliable()
{
#ifdef URHO3D_AUTOMATION
    return true;
#else
    return false;
#endif
}

void  Automation::MousePress(MouseButton button) const
{
#ifdef URHO3D_AUTOMATION
    Robot::Button rbButton = UrhoMouseButtonToRobotMouseButton(button);
    _mouse.Press(rbButton);
#endif
}

void  Automation::MouseRelease(MouseButton button) const
{
#ifdef URHO3D_AUTOMATION
    Robot::Button rbButton = UrhoMouseButtonToRobotMouseButton(button);
    _mouse.Release(rbButton);
#endif
}

void  Automation::MouseScrollH(int amount) const
{
#ifdef URHO3D_AUTOMATION
    _mouse.ScrollH(amount);
#endif
}

void  Automation::MouseScrollV(int amount) const
{
#ifdef URHO3D_AUTOMATION
      _mouse.ScrollV(amount);
#endif
}

IntVector2  Automation::MouseGetPos(void)
{
#ifdef URHO3D_AUTOMATION
    Robot::Point point = _mouse.GetPos();
    return IntVector2(point.X,point.Y);
#else
    return IntVector2::ZERO;
#endif
}

void  Automation::MouseSetPos(const IntVector2& point)
{
#ifdef URHO3D_AUTOMATION
    _mouse.SetPos(point.x_,point.y_);
#endif
}

void  Automation::MouseSetPos(uint32_t x, uint32_t y)
{
#ifdef URHO3D_AUTOMATION
    _mouse.SetPos(x,y);
#endif
}

bool  Automation::MouseGetState(MouseButton button)
{
#ifdef URHO3D_AUTOMATION
    Robot::Button rbButton = UrhoMouseButtonToRobotMouseButton(button);
    return _mouse.GetState(rbButton);
#else
    return false;
#endif
}

void  Automation::KeyboardClick(int keycode) const
{
#ifdef URHO3D_AUTOMATION
    _keyboard.Click((Robot::Key)keycode);
#endif
}

void  Automation::KeyboardPress(int keycode) const
{
#ifdef URHO3D_AUTOMATION
    _keyboard.Press((Robot::Key)keycode);
#endif
}

void  Automation::KeyboardRelease(int keycode) const
{
#ifdef URHO3D_AUTOMATION
    _keyboard.Release((Robot::Key)keycode);
#endif
}

bool  Automation::KeyboardGetState(int keycode)
{
#ifdef URHO3D_AUTOMATION
    return _keyboard.GetState((Robot::Key)keycode);
#else
    return false;
#endif
}

IntRect Automation::GetScreenBounds()
{
    IntRect rect =  IntRect(0,0,0,0);
#ifdef URHO3D_AUTOMATION
    Robot::Screen::Synchronize();
    Robot::Screen * screen =  Robot::Screen::GetMain();
    if(screen != nullptr)
    {
       Robot::Bounds bounds =  screen->GetBounds();
       rect = IntRect(bounds.X,bounds.Y,bounds.W,bounds.H);
    }
#endif
    return rect;

}


} //namespace Urho3D

