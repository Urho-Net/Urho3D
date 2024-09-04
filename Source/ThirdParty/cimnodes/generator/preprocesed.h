
typedef int ImNodesCol;
typedef int ImNodesStyleVar;
typedef int ImNodesStyleFlags;
typedef int ImNodesPinShape;
typedef int ImNodesAttributeFlags;
typedef int ImNodesMiniMapLocation;
enum ImNodesCol_
{
    ImNodesCol_NodeBackground = 0,
    ImNodesCol_NodeBackgroundHovered,
    ImNodesCol_NodeBackgroundSelected,
    ImNodesCol_NodeOutline,
    ImNodesCol_TitleBar,
    ImNodesCol_TitleBarHovered,
    ImNodesCol_TitleBarSelected,
    ImNodesCol_Link,
    ImNodesCol_LinkHovered,
    ImNodesCol_LinkSelected,
    ImNodesCol_Pin,
    ImNodesCol_PinHovered,
    ImNodesCol_BoxSelector,
    ImNodesCol_BoxSelectorOutline,
    ImNodesCol_GridBackground,
    ImNodesCol_GridLine,
    ImNodesCol_GridLinePrimary,
    ImNodesCol_MiniMapBackground,
    ImNodesCol_MiniMapBackgroundHovered,
    ImNodesCol_MiniMapOutline,
    ImNodesCol_MiniMapOutlineHovered,
    ImNodesCol_MiniMapNodeBackground,
    ImNodesCol_MiniMapNodeBackgroundHovered,
    ImNodesCol_MiniMapNodeBackgroundSelected,
    ImNodesCol_MiniMapNodeOutline,
    ImNodesCol_MiniMapLink,
    ImNodesCol_MiniMapLinkSelected,
    ImNodesCol_MiniMapCanvas,
    ImNodesCol_MiniMapCanvasOutline,
    ImNodesCol_COUNT
};
enum ImNodesStyleVar_
{
    ImNodesStyleVar_GridSpacing = 0,
    ImNodesStyleVar_NodeCornerRounding,
    ImNodesStyleVar_NodePadding,
    ImNodesStyleVar_NodeBorderThickness,
    ImNodesStyleVar_LinkThickness,
    ImNodesStyleVar_LinkLineSegmentsPerLength,
    ImNodesStyleVar_LinkHoverDistance,
    ImNodesStyleVar_PinCircleRadius,
    ImNodesStyleVar_PinQuadSideLength,
    ImNodesStyleVar_PinTriangleSideLength,
    ImNodesStyleVar_PinLineThickness,
    ImNodesStyleVar_PinHoverRadius,
    ImNodesStyleVar_PinOffset,
    ImNodesStyleVar_MiniMapPadding,
    ImNodesStyleVar_MiniMapOffset,
    ImNodesStyleVar_COUNT
};
enum ImNodesStyleFlags_
{
    ImNodesStyleFlags_None = 0,
    ImNodesStyleFlags_NodeOutline = 1 << 0,
    ImNodesStyleFlags_GridLines = 1 << 2,
    ImNodesStyleFlags_GridLinesPrimary = 1 << 3,
    ImNodesStyleFlags_GridSnapping = 1 << 4
};
enum ImNodesPinShape_
{
    ImNodesPinShape_Circle,
    ImNodesPinShape_CircleFilled,
    ImNodesPinShape_Triangle,
    ImNodesPinShape_TriangleFilled,
    ImNodesPinShape_Quad,
    ImNodesPinShape_QuadFilled
};
enum ImNodesAttributeFlags_
{
    ImNodesAttributeFlags_None = 0,
    ImNodesAttributeFlags_EnableLinkDetachWithDragClick = 1 << 0,
    ImNodesAttributeFlags_EnableLinkCreationOnSnap = 1 << 1
};
struct ImNodesIO
{
    struct EmulateThreeButtonMouse
    {
        EmulateThreeButtonMouse();
        const bool* Modifier;
    } EmulateThreeButtonMouse;
    struct LinkDetachWithModifierClick
    {
        LinkDetachWithModifierClick();
        const bool* Modifier;
    } LinkDetachWithModifierClick;
    struct MultipleSelectModifier
    {
        MultipleSelectModifier();
        const bool* Modifier;
    } MultipleSelectModifier;
    int AltMouseButton;
    float AutoPanningSpeed;
    ImNodesIO();
};
struct ImNodesStyle
{
    float GridSpacing;
    float NodeCornerRounding;
    ImVec2 NodePadding;
    float NodeBorderThickness;
    float LinkThickness;
    float LinkLineSegmentsPerLength;
    float LinkHoverDistance;
    float PinCircleRadius;
    float PinQuadSideLength;
    float PinTriangleSideLength;
    float PinLineThickness;
    float PinHoverRadius;
    float PinOffset;
    ImVec2 MiniMapPadding;
    ImVec2 MiniMapOffset;
    ImNodesStyleFlags Flags;
    unsigned int Colors[ImNodesCol_COUNT];
    ImNodesStyle();
};
enum ImNodesMiniMapLocation_
{
    ImNodesMiniMapLocation_BottomLeft,
    ImNodesMiniMapLocation_BottomRight,
    ImNodesMiniMapLocation_TopLeft,
    ImNodesMiniMapLocation_TopRight,
};
struct ImGuiContext;
struct ImVec2;
struct ImNodesContext;
struct ImNodesEditorContext;
typedef void (*ImNodesMiniMapNodeHoveringCallback)(int, void*);
typedef void* ImNodesMiniMapNodeHoveringCallbackUserData;
namespace ImNodes
{
void SetImGuiContext(ImGuiContext* ctx);
ImNodesContext* CreateContext();
void DestroyContext(ImNodesContext* ctx = ((void *)0));
ImNodesContext* GetCurrentContext();
void SetCurrentContext(ImNodesContext* ctx);
ImNodesEditorContext* EditorContextCreate();
void EditorContextFree(ImNodesEditorContext*);
void EditorContextSet(ImNodesEditorContext*);
ImVec2 EditorContextGetPanning();
void EditorContextResetPanning(const ImVec2& pos);
void EditorContextMoveToNode(const int node_id);
ImNodesIO& GetIO();
ImNodesStyle& GetStyle();
void StyleColorsDark(ImNodesStyle* dest = ((void *)0));
void StyleColorsClassic(ImNodesStyle* dest = ((void *)0));
void StyleColorsLight(ImNodesStyle* dest = ((void *)0));
void BeginNodeEditor();
void EndNodeEditor();
void MiniMap(
    const float minimap_size_fraction = 0.2f,
    const ImNodesMiniMapLocation location = ImNodesMiniMapLocation_TopLeft,
    const ImNodesMiniMapNodeHoveringCallback node_hovering_callback = ((void *)0),
    const ImNodesMiniMapNodeHoveringCallbackUserData node_hovering_callback_data = ((void *)0));
void PushColorStyle(ImNodesCol item, unsigned int color);
void PopColorStyle();
void PushStyleVar(ImNodesStyleVar style_item, float value);
void PushStyleVar(ImNodesStyleVar style_item, const ImVec2& value);
void PopStyleVar(int count = 1);
void BeginNode(int id);
void EndNode();
ImVec2 GetNodeDimensions(int id);
void BeginNodeTitleBar();
void EndNodeTitleBar();
void BeginInputAttribute(int id, ImNodesPinShape shape = ImNodesPinShape_CircleFilled);
void EndInputAttribute();
void BeginOutputAttribute(int id, ImNodesPinShape shape = ImNodesPinShape_CircleFilled);
void EndOutputAttribute();
void BeginStaticAttribute(int id);
void EndStaticAttribute();
void PushAttributeFlag(ImNodesAttributeFlags flag);
void PopAttributeFlag();
void Link(int id, int start_attribute_id, int end_attribute_id);
void SetNodeDraggable(int node_id, const bool draggable);
void SetNodeScreenSpacePos(int node_id, const ImVec2& screen_space_pos);
void SetNodeEditorSpacePos(int node_id, const ImVec2& editor_space_pos);
void SetNodeGridSpacePos(int node_id, const ImVec2& grid_pos);
ImVec2 GetNodeScreenSpacePos(const int node_id);
ImVec2 GetNodeEditorSpacePos(const int node_id);
ImVec2 GetNodeGridSpacePos(const int node_id);
void SnapNodeToGrid(int node_id);
bool IsEditorHovered();
bool IsNodeHovered(int* node_id);
bool IsLinkHovered(int* link_id);
bool IsPinHovered(int* attribute_id);
int NumSelectedNodes();
int NumSelectedLinks();
void GetSelectedNodes(int* node_ids);
void GetSelectedLinks(int* link_ids);
void ClearNodeSelection();
void ClearLinkSelection();
void SelectNode(int node_id);
void ClearNodeSelection(int node_id);
bool IsNodeSelected(int node_id);
void SelectLink(int link_id);
void ClearLinkSelection(int link_id);
bool IsLinkSelected(int link_id);
bool IsAttributeActive();
bool IsAnyAttributeActive(int* attribute_id = ((void *)0));
bool IsLinkStarted(int* started_at_attribute_id);
bool IsLinkDropped(int* started_at_attribute_id = ((void *)0), bool including_detached_links = true);
bool IsLinkCreated(
    int* started_at_attribute_id,
    int* ended_at_attribute_id,
    bool* created_from_snap = ((void *)0));
bool IsLinkCreated(
    int* started_at_node_id,
    int* started_at_attribute_id,
    int* ended_at_node_id,
    int* ended_at_attribute_id,
    bool* created_from_snap = ((void *)0));
bool IsLinkDestroyed(int* link_id);
const char* SaveCurrentEditorStateToIniString(size_t* data_size = ((void *)0));
const char* SaveEditorStateToIniString(
    const ImNodesEditorContext* editor,
    size_t* data_size = ((void *)0));
void LoadCurrentEditorStateFromIniString(const char* data, size_t data_size);
void LoadEditorStateFromIniString(ImNodesEditorContext* editor, const char* data, size_t data_size);
void SaveCurrentEditorStateToIniFile(const char* file_name);
void SaveEditorStateToIniFile(const ImNodesEditorContext* editor, const char* file_name);
void LoadCurrentEditorStateFromIniFile(const char* file_name);
void LoadEditorStateFromIniFile(ImNodesEditorContext* editor, const char* file_name);
ImGuiContext* GetNodeEditorImGuiContext();
float EditorContextGetZoom();
void EditorContextSetZoom(float zoom_scale, ImVec2 zoom_center);
void AppendDrawData(ImDrawList* src, ImVec2 origin, float scale);
}