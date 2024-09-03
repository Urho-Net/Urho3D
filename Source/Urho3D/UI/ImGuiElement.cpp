//
// Copyright (c) 2008-2024 the Urho3D project.
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
#include "../Core/Context.h"
#include "../Graphics/Graphics.h"
#include "../Graphics/GraphicsEvents.h"
#include "../Resource/Image.h"
#include "../UI/ImGuiElement.h"
#include "../Input/Input.h"
#include "../Resource/ResourceCache.h"
#include "../Graphics/Texture2D.h"
#include "../UI/UI.h"
#include "../IO/Log.h"
#include "../UI/Font.h"
#include "../UI/UIEvents.h"
#include "../UI/Window.h"
#include "../UI/ImGuiEvents.h"
#include <imgui/imgui.h>

namespace Urho3D
{

    extern const char* UI_CATEGORY;

    const char* IMGUI_FONT_TEXTURE = "IMGUI_FONT_TEXTURE";
    const intptr_t IMGUI_FONT_KEY = -1;
   
static ImGuiKey SDL2KeyEventToImGuiKey(SDL_Keycode keycode, SDL_Scancode scancode)
{
    IM_UNUSED(scancode);
    switch (keycode)
    {
        case SDLK_TAB: return ImGuiKey_Tab;
        case SDLK_LEFT: return ImGuiKey_LeftArrow;
        case SDLK_RIGHT: return ImGuiKey_RightArrow;
        case SDLK_UP: return ImGuiKey_UpArrow;
        case SDLK_DOWN: return ImGuiKey_DownArrow;
        case SDLK_PAGEUP: return ImGuiKey_PageUp;
        case SDLK_PAGEDOWN: return ImGuiKey_PageDown;
        case SDLK_HOME: return ImGuiKey_Home;
        case SDLK_END: return ImGuiKey_End;
        case SDLK_INSERT: return ImGuiKey_Insert;
        case SDLK_DELETE: return ImGuiKey_Delete;
        case SDLK_BACKSPACE: return ImGuiKey_Backspace;
        case SDLK_SPACE: return ImGuiKey_Space;
        case SDLK_RETURN: return ImGuiKey_Enter;
        case SDLK_ESCAPE: return ImGuiKey_Escape;
        case SDLK_QUOTE: return ImGuiKey_Apostrophe;
        case SDLK_COMMA: return ImGuiKey_Comma;
        case SDLK_MINUS: return ImGuiKey_Minus;
        case SDLK_PERIOD: return ImGuiKey_Period;
        case SDLK_SLASH: return ImGuiKey_Slash;
        case SDLK_SEMICOLON: return ImGuiKey_Semicolon;
        case SDLK_EQUALS: return ImGuiKey_Equal;
        case SDLK_LEFTBRACKET: return ImGuiKey_LeftBracket;
        case SDLK_BACKSLASH: return ImGuiKey_Backslash;
        case SDLK_RIGHTBRACKET: return ImGuiKey_RightBracket;
        case SDLK_BACKQUOTE: return ImGuiKey_GraveAccent;
        case SDLK_CAPSLOCK: return ImGuiKey_CapsLock;
        case SDLK_SCROLLLOCK: return ImGuiKey_ScrollLock;
        case SDLK_NUMLOCKCLEAR: return ImGuiKey_NumLock;
        case SDLK_PRINTSCREEN: return ImGuiKey_PrintScreen;
        case SDLK_PAUSE: return ImGuiKey_Pause;
        case SDLK_KP_0: return ImGuiKey_Keypad0;
        case SDLK_KP_1: return ImGuiKey_Keypad1;
        case SDLK_KP_2: return ImGuiKey_Keypad2;
        case SDLK_KP_3: return ImGuiKey_Keypad3;
        case SDLK_KP_4: return ImGuiKey_Keypad4;
        case SDLK_KP_5: return ImGuiKey_Keypad5;
        case SDLK_KP_6: return ImGuiKey_Keypad6;
        case SDLK_KP_7: return ImGuiKey_Keypad7;
        case SDLK_KP_8: return ImGuiKey_Keypad8;
        case SDLK_KP_9: return ImGuiKey_Keypad9;
        case SDLK_KP_PERIOD: return ImGuiKey_KeypadDecimal;
        case SDLK_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case SDLK_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case SDLK_KP_MINUS: return ImGuiKey_KeypadSubtract;
        case SDLK_KP_PLUS: return ImGuiKey_KeypadAdd;
        case SDLK_KP_ENTER: return ImGuiKey_KeypadEnter;
        case SDLK_KP_EQUALS: return ImGuiKey_KeypadEqual;
        case SDLK_LCTRL: return ImGuiKey_LeftCtrl;
        case SDLK_LSHIFT: return ImGuiKey_LeftShift;
        case SDLK_LALT: return ImGuiKey_LeftAlt;
        case SDLK_LGUI: return ImGuiKey_LeftSuper;
        case SDLK_RCTRL: return ImGuiKey_RightCtrl;
        case SDLK_RSHIFT: return ImGuiKey_RightShift;
        case SDLK_RALT: return ImGuiKey_RightAlt;
        case SDLK_RGUI: return ImGuiKey_RightSuper;
        case SDLK_APPLICATION: return ImGuiKey_Menu;
        case SDLK_0: return ImGuiKey_0;
        case SDLK_1: return ImGuiKey_1;
        case SDLK_2: return ImGuiKey_2;
        case SDLK_3: return ImGuiKey_3;
        case SDLK_4: return ImGuiKey_4;
        case SDLK_5: return ImGuiKey_5;
        case SDLK_6: return ImGuiKey_6;
        case SDLK_7: return ImGuiKey_7;
        case SDLK_8: return ImGuiKey_8;
        case SDLK_9: return ImGuiKey_9;
        case SDLK_a: return ImGuiKey_A;
        case SDLK_b: return ImGuiKey_B;
        case SDLK_c: return ImGuiKey_C;
        case SDLK_d: return ImGuiKey_D;
        case SDLK_e: return ImGuiKey_E;
        case SDLK_f: return ImGuiKey_F;
        case SDLK_g: return ImGuiKey_G;
        case SDLK_h: return ImGuiKey_H;
        case SDLK_i: return ImGuiKey_I;
        case SDLK_j: return ImGuiKey_J;
        case SDLK_k: return ImGuiKey_K;
        case SDLK_l: return ImGuiKey_L;
        case SDLK_m: return ImGuiKey_M;
        case SDLK_n: return ImGuiKey_N;
        case SDLK_o: return ImGuiKey_O;
        case SDLK_p: return ImGuiKey_P;
        case SDLK_q: return ImGuiKey_Q;
        case SDLK_r: return ImGuiKey_R;
        case SDLK_s: return ImGuiKey_S;
        case SDLK_t: return ImGuiKey_T;
        case SDLK_u: return ImGuiKey_U;
        case SDLK_v: return ImGuiKey_V;
        case SDLK_w: return ImGuiKey_W;
        case SDLK_x: return ImGuiKey_X;
        case SDLK_y: return ImGuiKey_Y;
        case SDLK_z: return ImGuiKey_Z;
        case SDLK_F1: return ImGuiKey_F1;
        case SDLK_F2: return ImGuiKey_F2;
        case SDLK_F3: return ImGuiKey_F3;
        case SDLK_F4: return ImGuiKey_F4;
        case SDLK_F5: return ImGuiKey_F5;
        case SDLK_F6: return ImGuiKey_F6;
        case SDLK_F7: return ImGuiKey_F7;
        case SDLK_F8: return ImGuiKey_F8;
        case SDLK_F9: return ImGuiKey_F9;
        case SDLK_F10: return ImGuiKey_F10;
        case SDLK_F11: return ImGuiKey_F11;
        case SDLK_F12: return ImGuiKey_F12;
        case SDLK_F13: return ImGuiKey_F13;
        case SDLK_F14: return ImGuiKey_F14;
        case SDLK_F15: return ImGuiKey_F15;
        case SDLK_F16: return ImGuiKey_F16;
        case SDLK_F17: return ImGuiKey_F17;
        case SDLK_F18: return ImGuiKey_F18;
        case SDLK_F19: return ImGuiKey_F19;
        case SDLK_F20: return ImGuiKey_F20;
        case SDLK_F21: return ImGuiKey_F21;
        case SDLK_F22: return ImGuiKey_F22;
        case SDLK_F23: return ImGuiKey_F23;
        case SDLK_F24: return ImGuiKey_F24;
        case SDLK_AC_BACK: return ImGuiKey_AppBack;
        case SDLK_AC_FORWARD: return ImGuiKey_AppForward;
        default: break;
    }
    return ImGuiKey_None;
}


    ImGuiElement::ImGuiElement(Context* context) :
        UIElement(context), 
        imguiContext_(nullptr),
        firstTime(true),
        movable_(false),
        resizable_(false)
    {
        enabled_ = true;
        SetFocusMode(FM_FOCUSABLE);
        imguiActiveWindowName_ = "";

        imguiContext_ = ImGui::CreateContext();
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO& io = ImGui::GetIO();
        
        io.IniFilename = nullptr; // Don't save ini file
        
        CreateFontTexture(true);
        
        // Render function is deliberately not set
        // Buffering the UIBatches and vertex-data was ridiculously slow

        ImGui::StyleColorsDark(nullptr);
        
        SubscribeToEvent(E_DEVICERESET, URHO3D_HANDLER(ImGuiElement, HandleDeviceReset));
        SubscribeToEvent(E_MOUSEBUTTONDOWN, URHO3D_HANDLER(ImGuiElement, HandleMouseButtonDown));
        SubscribeToEvent(E_MOUSEBUTTONUP, URHO3D_HANDLER(ImGuiElement, HandleMouseButtonUp));
        SubscribeToEvent(E_MOUSEMOVE, URHO3D_HANDLER(ImGuiElement, HandleMouseMove));
        SubscribeToEvent(E_MOUSEWHEEL, URHO3D_HANDLER(ImGuiElement, HandleMouseWheel));
        SubscribeToEvent(E_TOUCHBEGIN, URHO3D_HANDLER(ImGuiElement, HandleTouchBegin));
        SubscribeToEvent(E_TOUCHEND, URHO3D_HANDLER(ImGuiElement, HandleTouchEnd));
        SubscribeToEvent(E_TOUCHMOVE, URHO3D_HANDLER(ImGuiElement, HandleTouchMove));
        SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(ImGuiElement, HandleKeyDown));
        SubscribeToEvent(E_KEYUP, URHO3D_HANDLER(ImGuiElement, HandleKeyUp));
        
        SubscribeToEvent(E_ELEMENTADDED, URHO3D_HANDLER(ImGuiElement, HandleElementAdded));
        
    }

    ImGuiElement::~ImGuiElement()
    {
        if (imguiContext_)
        {
            //!!! NOTICE: this block will be invalid when [GH issue #1565](https://github.com/ocornut/imgui/issues/1565) makes its' way into the DearImGui trunk
            
            // have to shut it down to clear it's context local copy of font data
            ImGui::SetCurrentContext(imguiContext_);

            // this only frees, does not shut it down
            ImGui::DestroyContext(imguiContext_);
            imguiContext_ = nullptr;
        }
        
        UnsubscribeFromEvent(E_DEVICERESET);
        UnsubscribeFromEvent(E_MOUSEBUTTONDOWN);
        UnsubscribeFromEvent(E_MOUSEBUTTONUP);
        UnsubscribeFromEvent(E_MOUSEMOVE);
        UnsubscribeFromEvent(E_MOUSEWHEEL);
        UnsubscribeFromEvent(E_TOUCHBEGIN);
        UnsubscribeFromEvent(E_TOUCHEND);
        UnsubscribeFromEvent(E_TOUCHMOVE);
        UnsubscribeFromEvent(E_KEYDOWN);
        UnsubscribeFromEvent(E_KEYUP);
        UnsubscribeFromEvent(E_TEXTINPUT);
        UnsubscribeFromEvent(E_ELEMENTADDED);
    }

    void ImGuiElement::RegisterObject(Context* context)
    {
        context->RegisterFactory<ImGuiElement>(UI_CATEGORY);
        URHO3D_ACCESSOR_ATTRIBUTE("Enabled", IsEnabled, SetEnabled, bool, true, AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Visible", IsVisible, SetVisible, bool, true, AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Alpha Multiplier", GetAlphaMultiplier, SetAlphaMultiplier, float, 1.0f, AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Antialias", AntialiasEnabled, SetAntialize, bool, true, AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Touch Padding", GetTouchPadding, SetTouchPadding, Vector2, Vector2(0, 0), AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Font Size", GetFontSize, SetFontSize, int, 20, AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Show Metrics", IsMetricsWindowVisible, SetMetricsWindowVisible, bool, false, AM_DEFAULT);
        URHO3D_ACCESSOR_ATTRIBUTE("Show Demo", IsDemoWindowVisible, SetDemoWindowVisible, bool, false, AM_DEFAULT);
    }

    void ImGuiElement::HandleElementAdded(StringHash eventType, VariantMap& eventData)
    {
        using namespace ElementAdded;
        
        UIElement * parent = (UIElement *)(eventData[P_PARENT].GetPtr());
        UIElement * elm = (UIElement *)(eventData[P_ELEMENT].GetPtr());
//        if(this == elm)
//        {
//            if(parent)
//            {
//                parent->SetLayoutMode(LM_VERTICAL);
//            }
//        }
    }

    void ImGuiElement::Update(float timeStep)
    {
        // If not visible then there's nothing todo
        if (!IsVisibleEffective() || GetAlphaMultiplier() == 0.0f)
        {
            // make sure we don't have the focus to be interrupting anything
            if (HasFocus())
                SetFocus(false);
            return;
        }

        ImGui::SetCurrentContext(imguiContext_);
        Graphics* graphics = GetSubsystem<Graphics>();


        const Input* input = GetSubsystem<Input>();

        ImGuiIO& io = ImGui::GetIO();
        
        io.DeltaTime = timeStep;

        // Viewport
        io.DisplaySize = ImVec2(graphics->GetWidth(), graphics->GetHeight());
        if(input->GetMouseButtonDown(MOUSEB_LEFT) || input->GetNumTouches())
        {
            if(IsInside(input->GetMousePosition(), true))
            {
                SetFocus(true);
            }
        }
        
      
        if(imguiContext_->Windows.size()>0 && imguiActiveWindowName_ !="")
        {
            auto screenPosition = this->GetScreenPosition();
            auto size = GetSize();
            
            for (auto window :imguiContext_->Windows)
            {
                if(strcmp(window->Name,imguiActiveWindowName_.CString()) == 0)
                {
                    if(firstTime)
                    {
                        window->Pos = ImVec2(screenPosition.x_, screenPosition.y_);
                        window->Size = ImVec2(size.x_, size.y_);
                        window->SizeFull = ImVec2(size.x_, size.y_);
                        firstTime = false;
                    }
                    else{
                        
                        if(movable_ == false)
                        {
                            window->Pos = ImVec2(screenPosition.x_, screenPosition.y_);
                        }
                        else{
                            auto * parent = GetParent();
                            if(parent)
                            {
                                auto border = parent->GetLayoutBorder();
                                parent->SetPosition(window->Pos.x-border.left_, window->Pos.y-border.top_);
                            }
                            else{
                                SetPosition(window->Pos.x, window->Pos.y);
                            }
                            
                        }
                        
                        if(resizable_ == true)
                        {
                            if(size.x_ != window->SizeFull.x || size.y_ != window->SizeFull.y)
                            {
                                auto * parent = GetParent();
                                if(parent)
                                {
                                    auto newSize = IntVector2(window->SizeFull.x,window->SizeFull.y);
                                    auto border = parent->GetLayoutBorder();
                                    newSize.x_ += (border.right_ + border.left_);
                                    newSize.y_ += (border.bottom_ + border.top_);
                                    
                                    parent->SetFixedSize(newSize);
                                }
                                else{
                                    SetFixedSize(IntVector2(window->SizeFull.x,window->SizeFull.y));
                                }
                            }
                        }
                        else
                        {
                            window->Size = ImVec2(size.x_, size.y_);
                            window->SizeFull = ImVec2(size.x_, size.y_);
                        }
                    }
                    break;
                }
            }
        }
        
        

        if (!lastText_.Empty())
            io.AddInputCharactersUTF8(lastText_.CString());
        

        lastText_ = String::EMPTY;

        ImGui::NewFrame();

        VariantMap& eventMap = GetEventDataMap();
        using namespace IMGUIDraw;
        eventMap[IMGUIDraw::P_ELEMENT] = this;
        eventMap[IMGUIDraw::P_TIMESTEP] = timeStep;
        SendEvent(E_IMGUI_DRAW, eventMap);

        // Show optional windows as appropriate
        if (showMetrics_)
            ImGui::ShowMetricsWindow();
        if (showDemo_)
            ImGui::ShowDemoWindow();

        ImGui::Render();

        if (io.WantTextInput)
        {
            if (!HasFocus())
                SetFocus(true);
            
            if (GetSubsystem<UI>()->GetUseScreenKeyboard())
                GetSubsystem<Input>()->SetScreenKeyboardVisible(true);
            
        }
        else // unfocus otherwise
        {
            if (GetSubsystem<UI>()->GetUseScreenKeyboard())
                GetSubsystem<Input>()->SetScreenKeyboardVisible(false);
        }
        
        
    }

    void ImGuiElement::HandleMouseButtonDown(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        using namespace MouseButtonDown;
        MouseButton button = (MouseButton)(eventData[P_BUTTON].GetUInt());
        mouseButtons_ = MouseButtonFlags(eventData[P_BUTTONS].GetUInt());
        qualifiers_ = QualifierFlags(eventData[P_QUALIFIERS].GetUInt());
        
        UpdateQualifiers(qualifiers_);
        int mouse_button = -1;
        switch(button)
        {
            case MOUSEB_LEFT:
                AddMouseButtonEvent( ImGuiMouseButton_Left, true);
                break;
            case MOUSEB_RIGHT:
                AddMouseButtonEvent( ImGuiMouseButton_Right, true);
                break;
            case MOUSEB_MIDDLE:
                AddMouseButtonEvent( ImGuiMouseButton_Middle, true);
                break;
                
        }
    }

    /// Handle mouse button up event.
    void ImGuiElement::HandleMouseButtonUp(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        using namespace MouseButtonUp;
        MouseButton button = (MouseButton)(eventData[P_BUTTON].GetUInt());
        mouseButtons_ = MouseButtonFlags(eventData[P_BUTTONS].GetUInt());
        qualifiers_ = QualifierFlags(eventData[P_QUALIFIERS].GetUInt());
        
        UpdateQualifiers(qualifiers_);

        switch(button)
        {
            case MOUSEB_LEFT:
                AddMouseButtonEvent( ImGuiMouseButton_Left, false);
                break;
            case MOUSEB_RIGHT:
                AddMouseButtonEvent( ImGuiMouseButton_Right, false);
                break;
            case MOUSEB_MIDDLE:
                AddMouseButtonEvent( ImGuiMouseButton_Middle, false);
                break;
                
        }
    }
    /// Handle mouse move event.
    void ImGuiElement::HandleMouseMove(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        using namespace MouseMove;

        mouseButtons_ = MouseButtonFlags(eventData[P_BUTTONS].GetUInt());
        qualifiers_ = QualifierFlags(eventData[P_QUALIFIERS].GetUInt());
        UpdateQualifiers(qualifiers_);
        AddMousePosEvent();
    }
    /// Handle mouse wheel event.
    void ImGuiElement::HandleMouseWheel(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        using namespace MouseWheel;

        mouseButtons_ = MouseButtonFlags(eventData[P_BUTTONS].GetInt());
        qualifiers_ = QualifierFlags(eventData[P_QUALIFIERS].GetInt());
        int delta = eventData[P_WHEEL].GetInt();
        int delta_x = eventData[P_WHEEL_X].GetInt();
        int delta_y = eventData[P_WHEEL_Y].GetInt();
        
        UpdateQualifiers(qualifiers_);
        
        ImGuiIO* io = &ImGui::GetIO();
        #if (IMGUI_VERSION_NUM >= 18950)
        io->AddMouseSourceEvent(ImGuiMouseSource_Mouse);
        #endif
        io->AddMouseWheelEvent(delta_x, delta_y);
    }
    /// Handle touch begin event.
    void ImGuiElement::HandleTouchBegin(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        const Input* input = GetSubsystem<Input>();
        float uiSCale =  GetSubsystem<UI>()->GetScale();
        AddTouchPosEvent(input->GetTouch(0)->position_.x_/uiSCale, input->GetTouch(0)->position_.y_/uiSCale);
        AddTouchButtonEvent(0,true);
    }
    /// Handle touch end event.
    void ImGuiElement::HandleTouchEnd(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        const Input* input = GetSubsystem<Input>();
        float uiSCale =  GetSubsystem<UI>()->GetScale();
        AddTouchPosEvent(input->GetTouch(0)->position_.x_/uiSCale, input->GetTouch(0)->position_.y_/uiSCale);
        AddTouchButtonEvent(0,false);
    }
    /// Handle touch move event.
    void ImGuiElement::HandleTouchMove(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        const Input* input = GetSubsystem<Input>();
        float uiSCale =  GetSubsystem<UI>()->GetScale();
        AddTouchPosEvent(input->GetTouch(0)->position_.x_/uiSCale, input->GetTouch(0)->position_.y_/uiSCale);
    }
    /// Handle keypress event.
    void ImGuiElement::HandleKeyDown(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        using namespace KeyDown;
        mouseButtons_ = MouseButtonFlags(eventData[P_BUTTONS].GetUInt());
        qualifiers_ = QualifierFlags(eventData[P_QUALIFIERS].GetUInt());
        auto key = (SDL_Keycode)eventData[P_KEY].GetUInt();
        auto scancode =(SDL_Scancode)eventData[P_SCANCODE].GetUInt();
        UpdateQualifiers(qualifiers_);
        ImGuiKey imGuiKey = SDL2KeyEventToImGuiKey(key,scancode);
        AddKeyEvent(imGuiKey, true);
    }

    void ImGuiElement::HandleKeyUp(StringHash eventType, VariantMap& eventData)
    {
        ImGui::SetCurrentContext(imguiContext_);
        using namespace KeyUp;
        mouseButtons_ = MouseButtonFlags(eventData[P_BUTTONS].GetUInt());
        qualifiers_ = QualifierFlags(eventData[P_QUALIFIERS].GetUInt());
        auto key = (Key)eventData[P_KEY].GetUInt();
        auto scancode =(SDL_Scancode)eventData[P_SCANCODE].GetUInt();
        UpdateQualifiers(qualifiers_);
        ImGuiKey imGuiKey = SDL2KeyEventToImGuiKey(key,scancode);
        AddKeyEvent(imGuiKey, false);
    }

    void ImGuiElement::AddMousePosEvent()
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO* io = &ImGui::GetIO();
        float uiSCale =  GetSubsystem<UI>()->GetScale();
        const Input* input = GetSubsystem<Input>();
        IntVector2 mousePos = input->GetMousePosition();
        
#if (IMGUI_VERSION_NUM >= 18950)
        io->AddMouseSourceEvent(ImGuiMouseSource_Mouse);
#endif
        io->AddMousePosEvent(mousePos.x_/uiSCale,mousePos.y_/uiSCale);
    }

    void ImGuiElement::AddMouseButtonEvent(int mouse_button, bool down)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO* io = &ImGui::GetIO();
        AddMousePosEvent();
        
#if (IMGUI_VERSION_NUM >= 18950)
        io->AddMouseSourceEvent(ImGuiMouseSource_Mouse);
#endif
        io->AddMouseButtonEvent(mouse_button, down);
    }

    void ImGuiElement::AddTouchPosEvent(float x, float y)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO* io = &ImGui::GetIO();
#if (IMGUI_VERSION_NUM >= 18950)
        io->AddMouseSourceEvent(ImGuiMouseSource_TouchScreen);
#endif
        io->AddMousePosEvent(x, y);
    }

    void ImGuiElement::AddTouchButtonEvent(int mouse_button, bool down)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO* io = &ImGui::GetIO();
#if (IMGUI_VERSION_NUM >= 18950)
        io->AddMouseSourceEvent(ImGuiMouseSource_TouchScreen);
#endif
        io->AddMouseButtonEvent(mouse_button, down);
    }

    void ImGuiElement::AddKeyEvent(ImGuiKey imgui_key, bool down)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO* io = &ImGui::GetIO();
        io->AddKeyEvent(imgui_key, down);
    }

    void ImGuiElement::UpdateQualifiers(QualifierFlags qualifiers)
    {
        ImGui::SetCurrentContext(imguiContext_);
        AddKeyEvent(ImGuiMod_Ctrl, (qualifiers & QUAL_CTRL) != 0);
        AddKeyEvent(ImGuiMod_Shift, (qualifiers & QUAL_SHIFT) != 0);
        AddKeyEvent(ImGuiMod_Alt, (qualifiers & QUAL_ALT )!= 0);
    }

    bool ImGuiElement::Begin(const String& name, bool* p_open, ImGuiWindowFlags flags)
    {
        imguiActiveWindowName_ = name;
        ImGui::SetCurrentContext(imguiContext_);
        flags |= ImGuiWindowFlags_NoMove| ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
        if(resizable_ == true)
        {
            flags &= ~ImGuiWindowFlags_NoResize;
        }
        if(movable_)
        {
            flags &= ~ImGuiWindowFlags_NoMove;
        }
        
        return  ImGui::Begin(name.CString(), p_open, flags);
    }

    bool ImGuiElement::Begin(const String& name, ImGuiWindowFlags flags)
    {
        imguiActiveWindowName_ = name;
        ImGui::SetCurrentContext(imguiContext_);
        bool p_open = true;
        flags |= ImGuiWindowFlags_NoMove| ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
        if(resizable_ == true)
        {
            flags &= ~ImGuiWindowFlags_NoResize;
        }
        if(movable_)
        {
            flags &= ~ImGuiWindowFlags_NoMove;
        }
        return  ImGui::Begin(name.CString(), &p_open, flags);
    }

   
    bool ImGuiElement::Begin(const String& name)
    {
        imguiActiveWindowName_ = name;
        ImGui::SetCurrentContext(imguiContext_);
        bool p_open = true;
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove| ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
        if(resizable_ == true)
        {
            flags &= ~ImGuiWindowFlags_NoResize;
        }
        if(movable_)
        {
            flags &= ~ImGuiWindowFlags_NoMove;
        }
        return  ImGui::Begin(name.CString(), &p_open, flags);
    }

    void ImGuiElement::GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor)
    {
        if (!IsVisibleEffective())
            return;

        // Can batches be a bit more aggressive? Add to the batch in the back unless textureid changes?
        // ImGui is pretty aggressive about minimizing batches though

        // ImGui doesn't flush draw data after the end of the frame, so this is safe to do (for now)
        ImGui::SetCurrentContext(imguiContext_);
        ImDrawData* drawData = ImGui::GetDrawData();
        if (drawData == nullptr)
            return;
        
        for (int cmdListIdx = 0; cmdListIdx < drawData->CmdListsCount; ++cmdListIdx)
        {
            ImDrawList* drawList = drawData->CmdLists[cmdListIdx];
            ImDrawIdx idx_buffer_offset = 0;
            
            for (int cmdIdx = 0; cmdIdx < drawList->CmdBuffer.Size; ++cmdIdx)
            {
                const ImDrawCmd* drawCmd = &drawList->CmdBuffer[cmdIdx];
                if(drawCmd->ElemCount == 0)continue;
                
                if (drawCmd->UserCallback)
                {
                    //TODO: is there a meaningful use to this?
                    // most likely entirely end-user-project specific
                }
                else
                {
                    ImVec4 clipRect = drawCmd->ClipRect;
                    Texture* texture = nullptr;
                    if (drawCmd->TextureId)
                    {
                        intptr_t textureID = (intptr_t)drawCmd->TextureId;
                        HashMap<void*, SharedPtr<Texture2D> >::ConstIterator foundTexture = textureTable_.Find((void*)textureID);
                        if (foundTexture != textureTable_.End())
                            texture = foundTexture->second_.Get();
                    }
                    else
                        texture = fontTexture_;

                    UIBatch batch(this, BLEND_ALPHA, IntRect(clipRect.x, clipRect.y, clipRect.z, clipRect.w), texture, &vertexData);
                    batch.useGradient_ = true;
                    unsigned begin = batch.vertexData_->Size();
                    batch.vertexData_->Resize(begin + drawCmd->ElemCount * UI_VERTEX_SIZE);
                    float* dest = &(batch.vertexData_->At(begin));
                    batch.vertexEnd_ = batch.vertexData_->Size();

                    // Unfortunately, the index buffer is used a lot
                    // Consider adding Vtx/Idx buffer support to UI batch?
                    for (unsigned i = 0; i < drawCmd->ElemCount; ++i)
                    {
                        unsigned index = drawList->IdxBuffer[idx_buffer_offset+i];

                        auto vert = drawList->VtxBuffer[index];
                        // ?? Consider reordering ImDrawVertex data, would be able to memcpy then
                        dest[0] = vert.pos.x;
                        dest[1] = vert.pos.y;
                        dest[2] = 0.0f;
                        ((unsigned&)dest[3]) = vert.col;
                        dest[4] = vert.uv.x;
                        dest[5] = vert.uv.y;

                        // xyz, rgba8, uv
                        dest += UI_VERTEX_SIZE;
                    }

                    batches.Push(batch);
                }
                idx_buffer_offset += drawCmd->ElemCount;
            }
        }
    }


    void ImGuiElement::OnTextInput(const String& text)
    {
        lastText_ = text;
    }

    void ImGuiElement::AddTexture(void * textureID, SharedPtr<Texture2D> texture)
    {
        textureTable_[textureID] = texture;
    }

    void ImGuiElement::RemoveTexture(void * textureID)
    {
        textureTable_.Erase(textureID);
    }

    void ImGuiElement::CreateFontTexture(bool force)
    {
        ResourceCache* resCache = GetSubsystem<ResourceCache>();
        ImGuiIO& io = ImGui::GetIO();
        //TBD elix22 ,needs better handling
//        if (!force)
//        {
//            if (Texture2D* fontTexture = resCache->GetResource<Texture2D>(IMGUI_FONT_TEXTURE, false))
//            {
//                fontTexture_ = fontTexture;
//                io.Fonts->TexID = (void*)IMGUI_FONT_KEY;
//                textureTable_[(void*)IMGUI_FONT_KEY] = fontTexture_;
//                return;
//            }
//        }
        
        // ?? what to do about fonts is a serious question?
        ImFontConfig config;
        config.OversampleH = 1; // horizontal oversampling blurs things quite badly
        config.OversampleV = 1;
        config.GlyphExtraSpacing.x = 1.0f;
        config.SizePixels = fontSize_;
//        io.Fonts->Clear();
        io.Fonts->AddFontFromFileTTF(fontName_.CString(), fontSize_, &config, io.Fonts->GetGlyphRangesDefault());

        unsigned char* pixels;
        int width, height;
        int out_bytes_per_pixel;
        io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height,&out_bytes_per_pixel);

        SharedPtr<Image> img(new Image(context_));
        img->SetSize(width, height, 4);
        img->SetData(pixels);

        SharedPtr<Texture2D> texture(new Texture2D(context_));
        texture->SetName(IMGUI_FONT_TEXTURE);
        texture->SetData(img, true);
        texture->AddMetadata("FONT_SIZE", fontSize_);
        resCache->AddManualResource(texture);
        
        fontTexture_ = texture;
        io.Fonts->TexID = (void*)IMGUI_FONT_KEY;
        textureTable_[(void*)IMGUI_FONT_KEY] = fontTexture_;
    }

    void ImGuiElement::HandleDeviceReset(StringHash eventType, VariantMap& eventData)
    {
        if (fontTexture_ && fontTexture_->IsDataLost())
        {
            ImGuiIO& io = ImGui::GetIO();

            unsigned char* pixels;
            int width, height;
            int out_bytes_per_pixel;
            io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height,&out_bytes_per_pixel);

            SharedPtr<Image> img(new Image(context_));
            img->SetSize(width, height, 4);
            img->SetData(pixels);
            fontTexture_->SetData(img, true);
        }
    }

    float ImGuiElement::GetAlphaMultiplier() const
    {
        ImGui::SetCurrentContext(imguiContext_);
        return ImGui::GetStyle().Alpha;
    }

    void ImGuiElement::SetAlphaMultiplier(float value)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGui::GetStyle().Alpha = Clamp(value, 0.0f, 1.0f);
    }

    bool ImGuiElement::AntialiasEnabled() const
    {
        ImGui::SetCurrentContext(imguiContext_);
        // always working with them together
        return ImGui::GetStyle().AntiAliasedLines;
    }

    void ImGuiElement::SetAntialize(bool state)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiStyle& style = ImGui::GetStyle();
        style.AntiAliasedFill = style.AntiAliasedLines = state;
    }

    Vector2 ImGuiElement::GetTouchPadding() const
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiStyle& style = ImGui::GetStyle();
        return Vector2(style.TouchExtraPadding.x, style.TouchExtraPadding.y);
    }

    void ImGuiElement::SetTouchPadding(const Vector2& extraPadding)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGui::GetStyle().TouchExtraPadding = ImVec2(extraPadding.x_, extraPadding.y_);
    }

    void ImGuiElement::SetFontSize(int newSize)
    {
        if (newSize == fontSize_)
            return;
        
        // never allow less than 8
        // High DPIs tend to be ~150 ... extreme cases are ~200, 256 max leaves enough room for a 1-inch character
        // beyond that it's really time to use font-scaling
        fontSize_ = Clamp(newSize, 8, 256);
        // Rebuild the font texture, if multiple instances of ImGuiElement are used this will mangle the others,
        //  due to shared font-texture being used with different font-data.
        //  If necessary append the element ID to the manual resource.
        CreateFontTexture(true);
    }

    void ImGuiElement::SetFontName(String fontName)
    {
        if(fontName == fontName_)return;
        ResourceCache* resCache = GetSubsystem<ResourceCache>();
        if(resCache->GetResource<Font>(fontName) == nullptr)return;
        fontName_ = fontName;
        CreateFontTexture(true);
    }

    void ImGuiElement::SetWindowSize(IntVector2 & size)
    {
        ImGui::SetCurrentContext(imguiContext_);
        ImGui::SetNextWindowSize(ImVec2((float)size.x_, (float)size.y_));
    }

    /// Set whether can be moved.
    /// @property
    void ImGuiElement::SetMovable(bool enable)
    {
        movable_ = enable;
        if(resizable_ && movable_)
        {
            auto parent = GetParent();
            if(parent)
            {
                parent->SetColor(Color::TRANSPARENT_BLACK);
            }
        }
    }
    /// Set whether can be resized.
    /// @property
    void ImGuiElement::SetResizable(bool enable)
    {
        resizable_ = enable;
        
        if(resizable_ && movable_)
        {
            auto parent = GetParent();
            if(parent)
            {
                parent->SetColor(Color::TRANSPARENT_BLACK);
            }
        }
    }

 
}

