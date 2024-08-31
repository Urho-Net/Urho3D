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
#pragma once

#include "../UI/UIElement.h"
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
struct ImGuiContext;

namespace Urho3D
{
    URHO3D_EVENT(E_IMGUI_DRAW, IMGUIDraw)
    {
        URHO3D_PARAM(P_ELEMENT, Element);       // UIElement pointer
        URHO3D_PARAM(P_TIMESTEP, TimeStep);     // float
    }

    class ImGuiElement;
    typedef void(*ImGuiRenderFunction)(ImGuiElement* self);

    /// Implements a fullscreen Dear ImGui context.
    class URHO3D_API ImGuiElement : public UIElement
    {
        URHO3D_OBJECT(ImGuiElement, UIElement);
    public:
        /// Construct.
        explicit ImGuiElement(Context* context);
        /// Destruct.
        ~ImGuiElement();

        /// Register object factory and properties.
        static void RegisterObject(Context* context);

        /// Updates and 'soft renders' the ImGui context.
        void Update(float timeStep) override;
        /// Constructs UIBatches for rendering from the ImGuiContext's draw data.
        void GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor) override;

        /// Records the text for use in the next update.
        void OnTextInput(const String& text) override;

        /// Sets an external rendering function to be called for running ImGui commands. Function will be called from Update.
        void SetRenderFunction(ImGuiRenderFunction* func);

        /// Add a texture for referencing within ImGui.
        void AddTexture(void* textureID, SharedPtr<Texture2D> texture);
        /// Remove a texture from the table.
        void RemoveTexture(void* textureID);

        /// Returns the factor by which all alpha transparency is multiplied.
        float GetAlphaMultiplier() const;
        /// Returns true if antialiasing of lines and fill is active.
        bool AntialiasEnabled() const;
        /// Returns the extra padding around controls for easier touch interaction.
        Vector2 GetTouchPadding() const;
        /// Returns true if the ImGui debugging window is visible.
        inline bool IsMetricsWindowVisible() const { return showMetrics_; }
        /// Returns true if the ImGui standard demo is visible.
        inline bool IsDemoWindowVisible() const { return showDemo_; }

        /// Sets the global alpha multiplier.
        void SetAlphaMultiplier(float value);
        /// Activates or deactivates antialiasing of fill and lines.
        void SetAntialize(bool state);
        /// Sets the extra padding around controls for touch interaction.
        void SetTouchPadding(const Vector2& extraPadding);
        /// Sets the visibility of the ImGui debug window for tracking draws.
        void SetMetricsWindowVisible(bool state) { showMetrics_ = state; }
        /// Sets the visibility of the demo window, this is useful for tracking down widgets/layout.
        void SetDemoWindowVisible(bool state) { showDemo_ = state; }

        inline int GetFontSize() const { return fontSize_; }
        void SetFontSize(int size);
        
        void SetFontName(String fontName);
        inline String GetFontName() const { return fontName_; }
        
        bool Begin(const char* name, bool* p_open, ImGuiWindowFlags flags);
        
        void HandleMouseButtonDown(StringHash eventType, VariantMap& eventData);
        /// Handle mouse button up event.
        void HandleMouseButtonUp(StringHash eventType, VariantMap& eventData);
        /// Handle mouse move event.
        void HandleMouseMove(StringHash eventType, VariantMap& eventData);
        /// Handle mouse wheel event.
        void HandleMouseWheel(StringHash eventType, VariantMap& eventData);
        /// Handle touch begin event.
        void HandleTouchBegin(StringHash eventType, VariantMap& eventData);
        /// Handle touch end event.
        void HandleTouchEnd(StringHash eventType, VariantMap& eventData);
        /// Handle touch move event.
        void HandleTouchMove(StringHash eventType, VariantMap& eventData);
        /// Handle keypress event.
        void HandleKeyDown(StringHash eventType, VariantMap& eventData);
        void HandleKeyUp(StringHash eventType, VariantMap& eventData);
        
        

    protected:
        /// Alternatively to set the ImGuiRenderFunction pointer this method can be overriden for generating the UI.
        virtual void RenderImGui() { }

        /// Creates or acquires the font texture.
        void CreateFontTexture(bool force = false);
        
        void AddMousePosEvent();
        void AddMouseButtonEvent(int mouse_button, bool down);
        void AddTouchPosEvent(float x, float y);
        void AddTouchButtonEvent(int mouse_button, bool down);
        void AddKeyEvent(ImGuiKey imgui_key, bool down);
        void UpdateQualifiers(QualifierFlags qualifiers);

    private:
        /// Rebuilds the font texture when necessary.
        void HandleDeviceReset(StringHash eventType, VariantMap& eventData);

        /// Last text received from OnTextInput.
        String lastText_;
        /// ImGuiContext for this particular instance.
        ImGuiContext* imguiContext_;
        /// Optional GUI rendering function to use.
        ImGuiRenderFunction* renderFunction_;
        /// Table of IDs to textures for drawing textures/render-target in Dear ImGui.
        HashMap<void*, SharedPtr<Texture2D> > textureTable_;
        /// Stored font texture.
        SharedPtr<Texture2D> fontTexture_;
        /// Pixel height for font size.
        int fontSize_ = 20;
        /// Whether to show the debug window or not.
        bool showMetrics_ = false;
        /// Whether to show the standard ImGui demo or not.
        bool showDemo_ = false;
        
        String imguiActiveWindowName_;
        String fontName_ = "Data/Fonts/Anonymous Pro.ttf";
        
        MouseButtonFlags mouseButtons_;
        /// Last mouse button pressed.
        /// Qualifier keys held down.
        QualifierFlags qualifiers_;
    };

}
