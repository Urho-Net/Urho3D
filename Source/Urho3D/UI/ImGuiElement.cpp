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



namespace Urho3D
{

    extern const char* UI_CATEGORY;

    const char* IMGUI_FONT_TEXTURE = "IMGUI_FONT_TEXTURE";
    const intptr_t IMGUI_FONT_KEY = -1;
   

    void AddTriangleToUIBatch(UIBatch& batch)
    {

    }

    ImGuiElement::ImGuiElement(Context* context) :
        UIElement(context), 
        imguiContext_(nullptr),
        renderFunction_(nullptr)
    {
        enabled_ = true;
        SetFocusMode(FM_FOCUSABLE);
        imguiActiveWindowName_ = "";

        imguiContext_ = ImGui::CreateContext();
        ImGui::SetCurrentContext(imguiContext_);
        ImGuiIO& io = ImGui::GetIO();
        
        io.IniFilename = nullptr; // Don't save ini file
        
        CreateFontTexture();

        // Scancodes and key-codes mixed because SDL keys have massive values in many cases
        io.KeyMap[ImGuiKey_Tab] = KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = SCANCODE_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = SCANCODE_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = SCANCODE_UP;
        io.KeyMap[ImGuiKey_DownArrow] = SCANCODE_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = SCANCODE_PAGEUP;
        io.KeyMap[ImGuiKey_PageDown] = SCANCODE_PAGEDOWN;
        io.KeyMap[ImGuiKey_Home] = SCANCODE_HOME;
        io.KeyMap[ImGuiKey_End] = SCANCODE_END;
        io.KeyMap[ImGuiKey_Insert] = SCANCODE_INSERT;
        io.KeyMap[ImGuiKey_Delete] = KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Enter] = KEY_RETURN;
        io.KeyMap[ImGuiKey_Escape] = KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A] = KEY_A;
        io.KeyMap[ImGuiKey_C] = KEY_C;
        io.KeyMap[ImGuiKey_V] = KEY_V;
        io.KeyMap[ImGuiKey_X] = KEY_X;
        io.KeyMap[ImGuiKey_Y] = KEY_Y;
        io.KeyMap[ImGuiKey_Z] = KEY_Z;
        
        // Render function is deliberately not set
        // Buffering the UIBatches and vertex-data was ridiculously slow

        ImGui::StyleColorsDark(nullptr);
        
        SubscribeToEvent(E_DEVICERESET, URHO3D_HANDLER(ImGuiElement, HandleDeviceReset));
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
                    window->Pos = ImVec2(screenPosition.x_, screenPosition.y_);
                    window->Size = ImVec2(size.x_, size.y_);
                    window->SizeFull = ImVec2(size.x_, size.y_);
                    break;
                }
            }
        }
        
        

        // Grab whoever is under the mouse so that regular UI elements will be respected
        IntVector2 mousePos = input->GetMousePosition();
        UIElement* mouseHitter = GetSubsystem<UI>()->GetElementAt(mousePos); 

        // Process input, if allowed
        // do nothing if the mouse is in a capturing state
        // respect the Z-index precedent under the mouse
        if (IsEnabled() && (input->GetMouseMode() == MM_FREE || input->GetMouseMode() == MM_ABSOLUTE) && (mouseHitter == nullptr || mouseHitter == this))
        {
            float uiSCale =  GetSubsystem<UI>()->GetScale();
            
            if (input->GetNumTouches())
                mousePos = input->GetTouch(0)->position_;
            io.MousePos = ImVec2(mousePos.x_/uiSCale, mousePos.y_/uiSCale);
            io.MouseDown[0] = input->GetMouseButtonDown(MOUSEB_LEFT) || input->GetNumTouches();
            io.MouseDown[1] = input->GetMouseButtonDown(MOUSEB_RIGHT);
            io.MouseDown[2] = input->GetMouseButtonDown(MOUSEB_MIDDLE);
            
            // Is suppressing mouse wheel the correct thing to do? Mouse dampening?
            // Wheel amounts vary considerably between mice, as much as an order of magnitude
            int wheel = input->GetMouseMoveWheel();
            io.MouseWheel = wheel > 0 ? 1 : (wheel < 0 ? -1 : 0);

            // Modifier keys
            io.KeyAlt = input->GetScancodeDown(SCANCODE_ALT);
            io.KeyCtrl = input->GetScancodeDown(SCANCODE_CTRL);
            io.KeyShift = input->GetScancodeDown(SCANCODE_SHIFT);

            // We get text through the OnTextInput, SDL's keycodes are a complete mess so only dealing with these important keys
            io.KeysDown[KEY_TAB] = input->GetKeyDown(KEY_TAB);
            io.KeysDown[SCANCODE_LEFT] = input->GetScancodeDown(SCANCODE_LEFT);
            io.KeysDown[SCANCODE_RIGHT] = input->GetScancodeDown(SCANCODE_RIGHT);
            io.KeysDown[SCANCODE_UP] = input->GetScancodeDown(SCANCODE_UP);
            io.KeysDown[SCANCODE_DOWN] = input->GetScancodeDown(SCANCODE_DOWN);
            io.KeysDown[SCANCODE_PAGEUP] = input->GetScancodeDown(SCANCODE_PAGEUP);
            io.KeysDown[SCANCODE_PAGEDOWN] = input->GetScancodeDown(SCANCODE_PAGEDOWN);
            io.KeysDown[SCANCODE_HOME] = input->GetScancodeDown(SCANCODE_HOME);
            io.KeysDown[SCANCODE_END] = input->GetScancodeDown(SCANCODE_END);
            io.KeysDown[SCANCODE_INSERT] = input->GetScancodeDown(SCANCODE_INSERT);
            io.KeysDown[KEY_DELETE] = input->GetKeyDown(KEY_DELETE);
            io.KeysDown[KEY_BACKSPACE] = input->GetKeyDown(KEY_BACKSPACE);
            io.KeysDown[KEY_RETURN] = input->GetKeyDown(KEY_RETURN);
            io.KeysDown[KEY_ESCAPE] = input->GetKeyDown(KEY_ESCAPE);
            io.KeysDown[KEY_A] = input->GetKeyDown(KEY_A);
            io.KeysDown[KEY_C] = input->GetKeyDown(KEY_C);
            io.KeysDown[KEY_V] = input->GetKeyDown(KEY_V);
            io.KeysDown[KEY_X] = input->GetKeyDown(KEY_X);
            io.KeysDown[KEY_Y] = input->GetKeyDown(KEY_Y);
            io.KeysDown[KEY_Z] = input->GetKeyDown(KEY_Z);

            if (!lastText_.Empty())
                io.AddInputCharactersUTF8(lastText_.CString());
        }
        else
        {
            io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
            io.MouseWheel = false;
            io.MouseDown[0] = io.MouseDown[1] = io.MouseDown[2] = false;
            for (int i = 0; i < 512; ++i)
                io.KeysDown[i] = false;
        }

        lastText_ = String::EMPTY;

        ImGui::NewFrame();

        // if we have a render function then use that, otherwise default to whatever is in our virtual method
        if (renderFunction_)
            renderFunction_;
        else
        {
          
            VariantMap& eventMap = GetEventDataMap();
            using namespace IMGUIDraw;
            eventMap[IMGUIDraw::P_ELEMENT] = this;
            eventMap[IMGUIDraw::P_TIMESTEP] = timeStep;
            SendEvent(E_IMGUI_DRAW, eventMap);

            RenderImGui();
        }

        // Show optional windows as appropriate
        if (showMetrics_)
            ImGui::ShowMetricsWindow();
        if (showDemo_)
            ImGui::ShowDemoWindow();

        ImGui::Render();

        if (io.WantTextInput || io.WantCaptureKeyboard || io.WantCaptureMouse)
        {
            if (!HasFocus())
                SetFocus(true);
            if (io.WantTextInput && GetSubsystem<UI>()->GetUseScreenKeyboard())
                GetSubsystem<UI>()->SetUseScreenKeyboard(true);
        }
        else // unfocus otherwise
        {
            if (HasFocus() && GetSubsystem<UI>()->GetUseScreenKeyboard())
                GetSubsystem<UI>()->SetUseScreenKeyboard(false);
            SetFocus(false);
        }
    }

    bool ImGuiElement::Begin(const char* name, bool* p_open, ImGuiWindowFlags flags)
    {
        imguiActiveWindowName_ = name;
        flags |= ImGuiWindowFlags_NoMove| ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
        return  ImGui::Begin(name, p_open, flags);
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


    void ImGuiElement::SetRenderFunction(ImGuiRenderFunction* func)
    {
        renderFunction_ = func;
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
        if (!force)
        {
            if (Texture2D* fontTexture = resCache->GetResource<Texture2D>(IMGUI_FONT_TEXTURE, false))
            {
                fontTexture_ = fontTexture;
                io.Fonts->TexID = (void*)IMGUI_FONT_KEY;
                textureTable_[(void*)IMGUI_FONT_KEY] = fontTexture_;
                return;
            }
        }
        
        // ?? what to do about fonts is a serious question?
        ImFontConfig config;
        config.OversampleH = 1; // horizontal oversampling blurs things quite badly
        config.OversampleV = 1;
        config.GlyphExtraSpacing.x = 1.0f;
        config.SizePixels = fontSize_;
        io.Fonts->Clear();
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

 
}

