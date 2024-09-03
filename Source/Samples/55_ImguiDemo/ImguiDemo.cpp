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

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/Technique.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/CheckBox.h>
#include <Urho3D/UI/LineEdit.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/ToolTip.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/UI/ListView.h>
#include <Urho3D/UI/UIComponent.h>

#include <imgui/imgui.h>
#include <imnodes/imnodes.h>

#include "ImguiDemo.h"

#include <Urho3D/DebugNew.h>

URHO3D_DEFINE_APPLICATION_MAIN(ImguiDemo)

ImguiDemo::ImguiDemo(Context* context) :
    Sample(context),
    uiRoot_(GetSubsystem<UI>()->GetRoot()),
    dragBeginPosition_(IntVector2::ZERO)
{
}

void ImguiDemo::Start()
{
    // Execute base class startup
    Sample::Start();
    Graphics* graphics = GetSubsystem<Graphics>();

    // Enable OS cursor
    GetSubsystem<Input>()->SetMouseVisible(true);

    // Load XML file containing default UI style sheet
    auto* cache = GetSubsystem<ResourceCache>();
    auto* style = cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

    // Set the loaded style as default style
    uiRoot_->SetDefaultStyle(style);
    
    // Initialize Scene
    InitScene();

    // Initialize Window
    InitWindow();

    // Create and add some controls to the Window
    InitControls();

    // Create a draggable Fish
    CreateDraggableFish();

    // Set the mouse mode to use in the sample
    Sample::InitMouseMode(MM_FREE);
    
//    window_->SetPosition(graphics->GetWidth()/2 - window_->GetWidth()/2,graphics->GetHeight()/2 - window_->GetHeight()/2);
}

void ImguiDemo::InitControls()
{
    // Create a CheckBox
    auto* checkBox = new CheckBox(context_);
    checkBox->SetName("CheckBox");

    // Create a Button
    auto* button = new Button(context_);
    button->SetName("Button");
    button->SetMinHeight(24);

    // Create a LineEdit
    auto* lineEdit = new LineEdit(context_);
    lineEdit->SetName("LineEdit");
    lineEdit->SetMinHeight(24);

    // Add controls to Window
    window_->AddChild(checkBox);
    window_->AddChild(button);
    window_->AddChild(lineEdit);
    
    // Add imgui Control
    imGuiElementTool  = window_->CreateChild<ImGuiElement>();
    imGuiElementTool->SetName("ImGuiElement");
    imGuiElementTool->SetMinHeight(500);
    imGuiElementTool->SetFontSize(20); // that's the default , so only for educational purpose
    imGuiElementTool->SetFontName("Data/Fonts/Anonymous Pro.ttf"); // that's the default , so only for educational purpose
//    imGuiElementTool->SetDemoWindowVisible(true);
    
    // Subscribe to imgui draw event event.
    SubscribeToEvent(imGuiElementTool,E_IMGUI_DRAW, URHO3D_HANDLER(ImguiDemo, HandleImgGuiDraw));
  
    imNodeWindow_=   new Window(context_);
    uiRoot_->AddChild(imNodeWindow_);
    imNodeWindow_->SetLayoutMode(LM_VERTICAL);
    imNodeWindow_->SetPosition(600,0);
    imNodeElementTool = imNodeWindow_->CreateChild<ImGuiElement>();
    imNodeElementTool->SetMinSize(800,800);
    imNodeElementTool->SetMovable(true);
    imNodeElementTool->SetResizable(true);

    SubscribeToEvent(imNodeElementTool,E_IMGUI_DRAW, URHO3D_HANDLER(ImguiDemo, HandleImNodeDraw));
    
    ImNodes::CreateContext();
    
    ImNodesIO& io = ImNodes::GetIO();
    io.LinkDetachWithModifierClick.Modifier = &ImGui::GetIO().KeyShift;
    io.MultipleSelectModifier.Modifier = &ImGui::GetIO().KeyCtrl;
    
    ImNodesStyle style =  ImNodes::GetStyle();
    style.Flags |= ImNodesStyleFlags_GridLinesPrimary |ImNodesStyleFlags_GridSnapping;
    ImNodes::StyleColorsClassic();

    
    // Apply previously set default style
    checkBox->SetStyleAuto();
    button->SetStyleAuto();
    lineEdit->SetStyleAuto();
    
}

void ImguiDemo::InitWindow()
{
    
    // Create the Window and add it to the UI's root node
    window_ = new Window(context_);
    uiRoot_->AddChild(window_);

    // Set Window size and layout settings
    window_->SetMinWidth(600);
    window_->SetLayout(LM_VERTICAL, 6, IntRect(6, 6, 6, 6));
//    window_->SetAlignment(HA_CENTER, VA_CENTER);
    window_->SetName("Window");
    window_->SetMovable(true);
    window_->SetResizable(false);

    // Create Window 'titlebar' container
    auto* titleBar = new UIElement(context_);
    titleBar->SetMinSize(0, 24);
    titleBar->SetVerticalAlignment(VA_TOP);
    titleBar->SetLayoutMode(LM_HORIZONTAL);

    // Create the Window title Text
    auto* windowTitle = new Text(context_);
    windowTitle->SetName("WindowTitle");
    windowTitle->SetText("Hello GUI!");

    // Create the Window's close button
    auto* buttonClose = new Button(context_);
    buttonClose->SetName("CloseButton");

    // Add the controls to the title bar
    titleBar->AddChild(windowTitle);
    titleBar->AddChild(buttonClose);

    // Add the title bar to the Window
    window_->AddChild(titleBar);

    // Create a list.
    auto* list = window_->CreateChild<ListView>();
    list->SetSelectOnClickEnd(true);
    list->SetHighlightMode(HM_ALWAYS);
    list->SetMinHeight(200);

    for (int i = 0; i < 32; i++)
    {
        auto* text = new Text(context_);
        text->SetStyleAuto();
        text->SetText(ToString("List item %d", i));
        text->SetName(ToString("Item %d", i));
        list->AddItem(text);
    }

    // Apply styles
    window_->SetStyleAuto();
    list->SetStyleAuto();
    windowTitle->SetStyleAuto();
    buttonClose->SetStyle("CloseButton");

    // Subscribe to buttonClose release (following a 'press') events
    SubscribeToEvent(buttonClose, E_RELEASED, URHO3D_HANDLER(ImguiDemo, HandleClosePressed));

    // Subscribe also to all UI mouse clicks just to see where we have clicked
    SubscribeToEvent(E_UIMOUSECLICK, URHO3D_HANDLER(ImguiDemo, HandleControlClicked));
}

void ImguiDemo::InitScene()
{
    auto* cache = GetSubsystem<ResourceCache>();

    scene_ = new Scene(context_);
    scene_->CreateComponent<Octree>();
    auto* zone = scene_->CreateComponent<Zone>();
    zone->SetBoundingBox(BoundingBox(-1000.0f, 1000.0f));
    zone->SetFogColor(Color::GRAY);
    zone->SetFogStart(100.0f);
    zone->SetFogEnd(300.0f);

    // Create a child scene node (at world origin) and a StaticModel component into it.
    Node* boxNode = scene_->CreateChild("Box");
    boxNode->SetScale(Vector3(5.0f, 5.0f, 5.0f));
    boxNode->SetRotation(Quaternion(90, Vector3::LEFT));

    // Create a box model and hide it initially.
    auto* boxModel = boxNode->CreateComponent<StaticModel>();
    boxModel->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
    boxNode->SetEnabled(false);

    // Create a camera.
    cameraNode_ = scene_->CreateChild("Camera");
    cameraNode_->CreateComponent<Camera>();

    // Set an initial position for the camera scene node.
    cameraNode_->SetPosition(Vector3(0.0f, 0.0f, -10.0f));

    // Set up a viewport so 3D scene can be visible.
    auto* renderer = GetSubsystem<Renderer>();
    SharedPtr<Viewport> viewport(new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>()));
    renderer->SetViewport(0, viewport);

    // Subscribe to update event and animate cube and handle input.
    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(ImguiDemo, HandleUpdate));
    

}

void ImguiDemo::CreateDraggableFish()
{
    auto* cache = GetSubsystem<ResourceCache>();
    auto* graphics = GetSubsystem<Graphics>();

    // Create a draggable Fish button
    auto* draggableFish = new Button(context_);
    draggableFish->SetTexture(cache->GetResource<Texture2D>("Textures/UrhoDecal.dds")); // Set texture
    draggableFish->SetBlendMode(BLEND_ADD);
    draggableFish->SetSize(128, 128);
    draggableFish->SetPosition((graphics->GetWidth() - draggableFish->GetWidth()) / 2, 200);
    draggableFish->SetName("Fish");
    uiRoot_->AddChild(draggableFish);

    // Add a tooltip to Fish button
    auto* toolTip = new ToolTip(context_);
    draggableFish->AddChild(toolTip);
    toolTip->SetPosition(IntVector2(draggableFish->GetWidth() + 5, draggableFish->GetWidth() / 2)); // slightly offset from close button
    auto* textHolder = new BorderImage(context_);
    toolTip->AddChild(textHolder);
    textHolder->SetStyle("ToolTipBorderImage");
    auto* toolTipText = new Text(context_);
    textHolder->AddChild(toolTipText);
    toolTipText->SetStyle("ToolTipText");
    toolTipText->SetText("Please drag me!");

    // Subscribe draggableFish to Drag Events (in order to make it draggable)
    // See "Event list" in documentation's Main Page for reference on available Events and their eventData
    SubscribeToEvent(draggableFish, E_DRAGBEGIN, URHO3D_HANDLER(ImguiDemo, HandleDragBegin));
    SubscribeToEvent(draggableFish, E_DRAGMOVE, URHO3D_HANDLER(ImguiDemo, HandleDragMove));
    SubscribeToEvent(draggableFish, E_DRAGEND, URHO3D_HANDLER(ImguiDemo, HandleDragEnd));
}

void ImguiDemo::HandleDragBegin(StringHash eventType, VariantMap& eventData)
{
    // Get UIElement relative position where input (touch or click) occurred (top-left = IntVector2(0,0))
    dragBeginPosition_ = IntVector2(eventData["ElementX"].GetInt(), eventData["ElementY"].GetInt());
}

void ImguiDemo::HandleDragMove(StringHash eventType, VariantMap& eventData)
{
    IntVector2 dragCurrentPosition = IntVector2(eventData["X"].GetInt(), eventData["Y"].GetInt());
    UIElement* draggedElement = static_cast<UIElement*>(eventData["Element"].GetPtr());
    draggedElement->SetPosition(dragCurrentPosition - dragBeginPosition_);
}

void ImguiDemo::HandleDragEnd(StringHash eventType, VariantMap& eventData) // For reference (not used here)
{
}

void ImguiDemo::HandleClosePressed(StringHash eventType, VariantMap& eventData)
{
    if (GetPlatform() != "Web")
        engine_->Exit();
}

void ImguiDemo::HandleControlClicked(StringHash eventType, VariantMap& eventData)
{
    // Get the Text control acting as the Window's title
    auto* windowTitle = window_->GetChildStaticCast<Text>("WindowTitle", true);

    // Get control that was clicked
    auto* clicked = static_cast<UIElement*>(eventData[UIMouseClick::P_ELEMENT].GetPtr());

    String name = "...?";
    if (clicked)
    {
        // Get the name of the control that was clicked
        name = clicked->GetName();
    }

    // Update the Window's title text
    windowTitle->SetText("Hello " + name + "!");
}


void ImguiDemo::HandleUpdate(StringHash, VariantMap& eventData)
{
    using namespace Update;
    float timeStep = eventData[P_TIMESTEP].GetFloat();

}


void ImguiDemo::HandleImgGuiDraw(StringHash, VariantMap& eventData)
{
  
    using namespace  IMGUIDraw;
    ImGuiElement *imguiElement = (ImGuiElement*)eventData[P_ELEMENT].GetVoidPtr();
    
    if(imguiElement == imGuiElementTool)
    {
        // Create a window called "My First Tool", with a menu bar.
        
        // VERY IMPORTANT DON'T CALL ImGui::Begin  , call  ImGuiElement::Begin instead
        imguiElement->Begin("Some Imgui window", &my_tool_active, ImGuiWindowFlags_MenuBar);
        
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
                if (ImGui::MenuItem("Close", "Ctrl+W"))  { my_tool_active = false; }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        
        // Edit a color stored as 4 floats
        ImGui::ColorEdit4("Color", my_color);
        
        // Generate samples and plot them
        float samples[100];
        for (int n = 0; n < 100; n++)
            samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
        ImGui::PlotLines("Samples", samples, 100);
        
        // Display contents in a scrolling region
        ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
        ImGui::BeginChild("Scrolling");
        for (int n = 0; n < 1000; n++)
            ImGui::Text("%04d: Some text", n);
        ImGui::EndChild();
        ImGui::End();
        
    }
 
}


void ImguiDemo::HandleImNodeDraw(StringHash, VariantMap& eventData)
{
    using namespace  IMGUIDraw;
    ImGuiElement *imguiElement = (ImGuiElement*)eventData[P_ELEMENT].GetVoidPtr();
    
    // VERY IMPORTANT DON'T CALL ImGui::Begin  , call  ImGuiElement::Begin instead

    imguiElement->Begin("imNode Demo window");
    
    ImGui::TextUnformatted("A -- add node");

    
    ImNodes::BeginNodeEditor();
    


    if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) &&
        ImNodes::IsEditorHovered() && ImGui::IsKeyReleased(ImGuiKey_A))
    {
        const int node_id = ++current_imnode_id;
        ImNodes::SetNodeScreenSpacePos(node_id, ImGui::GetMousePos());
        ImNodes::SnapNodeToGrid(node_id);
        nodes.push_back(ImNode(node_id, 0.f));
    }

    for (ImNode& node : nodes)
    {
        ImNodes::BeginNode(node.id);

        ImNodes::BeginNodeTitleBar();
        ImGui::TextUnformatted("node");
        ImNodes::EndNodeTitleBar();

        ImNodes::BeginInputAttribute(node.id << 8);
        ImGui::TextUnformatted("input");
        ImNodes::EndInputAttribute();

        ImNodes::BeginStaticAttribute(node.id << 16);
        ImGui::PushItemWidth(120.0f);
        ImGui::DragFloat("value", &node.value, 0.01f);
        ImGui::PopItemWidth();
        ImNodes::EndStaticAttribute();

        ImNodes::BeginOutputAttribute(node.id << 24);
        const float text_width = ImGui::CalcTextSize("output").x;
        ImGui::Indent(120.f + ImGui::CalcTextSize("value").x - text_width);
        ImGui::TextUnformatted("output");
        ImNodes::EndOutputAttribute();

        ImNodes::EndNode();
    }

    for (const Link& link : links)
    {
        ImNodes::Link(link.id, link.start_attr, link.end_attr);
    }

    ImNodes::MiniMap();
    ImNodes::EndNodeEditor();
    
    //ZOOM
    if( ImNodes::IsEditorHovered() && ImGui::GetIO().MouseWheel != 0 )
    {
        float zoom = ImNodes::EditorContextGetZoom() + ImGui::GetIO().MouseWheel * 0.1f;
        ImNodes::EditorContextSetZoom( zoom, ImGui::GetMousePos() );
    }
    

    {
        Link link;
        if (ImNodes::IsLinkCreated(&link.start_attr, &link.end_attr))
        {
            link.id = ++current_imnode_id;
            links.push_back(link);
        }
    }

    {
        int link_id;
        if (ImNodes::IsLinkDestroyed(&link_id))
        {
            auto iter = std::find_if(
                links.begin(), links.end(), [link_id](const Link& link) -> bool {
                    return link.id == link_id;
                });
            assert(iter != links.end());
            links.erase(iter);
        }
    }
    


    ImGui::End();
}
