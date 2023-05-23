
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
#include "VGComponent.h"
#include "VectorGraphics.h"
#include "VGEvents.h"
#include "nanovg.h"
#include "../Core/Object.h"
#include "../Core/Context.h"
#include "../Graphics/GraphicsEvents.h"
#include "../Scene/Node.h"

namespace Urho3D
{

static VGComponent* CurrenVGComponent_ = nullptr;

void VGComponent::RegisterObject(Context* context)
{
    context->RegisterFactory<VGComponent>("UI");
    
}

SharedPtr<VGComponent> VGComponent::Create(Node* parent, String Name)
{
    Node * child = parent->CreateChild(Name);
    return SharedPtr<VGComponent>(child->CreateComponent<VGComponent>());
}

SharedPtr<VGComponent> VGComponent::CreateChild(String Name)
{
    Node* child = node_->CreateChild(Name);
    return SharedPtr<VGComponent>(child->CreateComponent<VGComponent>());
}

VGComponent* VGComponent::GetChild(const String& name, bool recursive) const {
    Node* child = node_->GetChild(name, recursive);
    if (child)
    {
        return child->GetComponent<VGComponent>(recursive);
    }
    else
        return nullptr;
}

void VGComponent::GetChildren(PODVector<VGComponent*>& dest, bool recursive) const 
{
    node_->GetComponents(dest, recursive);
}

String VGComponent::GetName() 
{ 
    return node_->GetName();
}

VGComponent::VGComponent(Context* context)
    : Component(context)
    , hotSpot_(IntVector2::ZERO)
{
    nanoVG_ = GetSubsystem<VectorGraphics>();
    vg_ = nanoVG_->GetNVGContext();
    graphics_ = GetSubsystem<Graphics>();
}

VGComponent::~VGComponent() {}

void VGComponent::SetPosition(const Vector2& position) { node_->SetPosition2D(position); }

void VGComponent::SetPosition(float x, float y) { SetPosition(Vector2(x, y)); }

void VGComponent::SetHotSpot(const Vector2& hotSpot)
{
    if (hotSpot != hotSpot_)
    {
        hotSpot_ = hotSpot;
    }
}

void VGComponent::SetHotSpot(float x, float y) { SetHotSpot(Vector2(x, y)); }

void VGComponent::SetScale(const Vector2& scale) { node_->SetScale2D(scale); }

void VGComponent::SetScale(float x, float y) { SetScale(Vector2(x, y)); }

void VGComponent::SetScale(float scale) { SetScale(Vector2(scale, scale)); }

void VGComponent::SetRotation(float angle) { node_->SetRotation2D(angle); }


void VGComponent::BeginDraw()
{
    if (nanoVG_ != nullptr && vg_ != nullptr)
    {
        float xform[6] = {0};
        Vector2 scale = Vector2::ONE;

        this->SaveState();
        this->BeginPath();

        nvgTransformIdentity(xform);
        GetTransformScale(xform);
        GetTransformPositionRotation(xform);
        this->Transform(xform[0], xform[1], xform[2], xform[3], xform[4], xform[5]);
    }
}

void VGComponent::EndDraw()
{
    if (nanoVG_ != nullptr && vg_ != nullptr)
    {
        this->RestoreState();
    }
}

void VGComponent::GetTransformPositionRotation(float xform[6])
{
    float rotation = node_->GetRotation2D();
    Vector2 position = node_->GetPosition2D();
    float t[6] = {0};

    nvgTransformTranslate(t, -hotSpot_.x_, -hotSpot_.y_);
    nvgTransformMultiply(xform, t);
    nvgTransformRotate(t,  nvgDegToRad(rotation));
    nvgTransformMultiply(xform, t);
    nvgTransformTranslate(t, hotSpot_.x_, hotSpot_.y_);
    nvgTransformMultiply(xform, t);
    nvgTransformTranslate(t, position.x_, position.y_);
    nvgTransformMultiply(xform, t);

    if (node_->GetParent())
    {
        Node* parent = node_->GetParent();
        VGComponent* parentVGComponent = parent->GetComponent<VGComponent>();
        if (parentVGComponent)
        {
            parentVGComponent->GetTransformPositionRotation(xform);
        }
    }

    /*
    nvgTransformTranslate(t, position.x_, position.y_);
    nvgTransformPremultiply(xform, t);
    nvgTransformTranslate(t, hotSpot_.x_, hotSpot_.y_);
    nvgTransformPremultiply(xform, t);
    nvgTransformRotate(t, rotation);
    nvgTransformPremultiply(xform, t);
    nvgTransformTranslate(t, -hotSpot_.x_, -hotSpot_.y_);
    nvgTransformPremultiply(xform, t);
    */
}

void VGComponent::GetTransformScale(float xform[6])
{

    Vector2 scale = node_->GetScale2D();
    float t[6] = {0};
    float tsum[6] = {0};

    if (node_->GetParent())
    {
        Node* parent = node_->GetParent();
        VGComponent* parentVGComponent = parent->GetComponent<VGComponent>();
        if (parentVGComponent)
        {
            parentVGComponent->GetTransformScale(xform);
        }
    }

    nvgTransformIdentity(tsum);
    nvgTransformTranslate(t, -hotSpot_.x_, -hotSpot_.y_);
    nvgTransformMultiply(tsum, t);
    nvgTransformScale(t, scale.x_, scale.y_);
    nvgTransformMultiply(tsum, t);
    nvgTransformTranslate(t, hotSpot_.x_, hotSpot_.y_);
    nvgTransformMultiply(tsum, t);
    nvgTransformPremultiply(xform, tsum);

    /*
    nvgTransformTranslate(t, hotSpot_.x_, hotSpot_.y_);
    nvgTransformPremultiply(xform, t);
    nvgTransformScale(t, scale.x_, scale.y_);
    nvgTransformPremultiply(xform, t);
    nvgTransformTranslate(t, -hotSpot_.x_, -hotSpot_.y_);
    nvgTransformPremultiply(xform, t);
    */
}

void VGComponent::GlobalCompositeOperation(int op) { nvgGlobalCompositeOperation(vg_, op); }

void VGComponent::GlobalCompositeBlendFunc(int sfactor, int dfactor)
{
    nvgGlobalCompositeBlendFunc(vg_, sfactor, dfactor);
}

void VGComponent::GlobalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha)
{
    nvgGlobalCompositeBlendFuncSeparate(vg_, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

NVGcolor VGComponent::RGB(unsigned char r, unsigned char g, unsigned char b) { return nvgRGB(r, g, b); }

NVGcolor VGComponent::RGBf(float r, float g, float b) { return nvgRGBf(r, g, b); }

NVGcolor VGComponent::RGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return nvgRGBA(r, g, b, a);
}

NVGcolor VGComponent::RGBAf(float r, float g, float b, float a) { return nvgRGBAf(r, g, b, a); }

NVGcolor VGComponent::LerpRGBA(NVGcolor c0, NVGcolor c1, float u) { return nvgLerpRGBA(c0, c1, u); }

NVGcolor VGComponent::TransRGBA(NVGcolor c0, unsigned char a) { return nvgTransRGBA(c0, a); }

NVGcolor VGComponent::TransRGBAf(NVGcolor c0, float a) { return nvgTransRGBAf(c0, a); }

NVGcolor VGComponent::HSL(float h, float s, float l) { return nvgHSL(h, s, l); }

NVGcolor VGComponent::HSLA(float h, float s, float l, unsigned char a) { return nvgHSLA(h, s, l, a); }

void VGComponent::SaveState() { nvgSave(vg_); }

void VGComponent::RestoreState() { nvgRestore(vg_); }

void VGComponent::ResetState() { nvgReset(vg_); }

void VGComponent::ShapeAntiAlias(int enabled) { nvgShapeAntiAlias(vg_, enabled); }

void VGComponent::StrokeColor(NVGcolor color) { nvgStrokeColor(vg_, color); }

void VGComponent::StrokePaint(NVGpaint paint) { nvgStrokePaint(vg_, paint); }

void VGComponent::FillColor(NVGcolor color) { nvgFillColor(vg_, color); }

void VGComponent::FillPaint(NVGpaint paint) { nvgFillPaint(vg_, paint); }

void VGComponent::MiterLimit(float limit) { nvgMiterLimit(vg_, limit); }

void VGComponent::StrokeWidth(float size) { nvgStrokeWidth(vg_, size); }

void VGComponent::LineCap(int cap) { nvgLineCap(vg_, cap); }

void VGComponent::LineJoin(int join) { nvgLineJoin(vg_, join); }

void VGComponent::GlobalAlpha(float alpha) { nvgGlobalAlpha(vg_, alpha); }

void VGComponent::ResetTransform() { nvgResetTransform(vg_); }

void VGComponent::Transform(float a, float b, float c, float d, float e, float f)
{
    nvgTransform(vg_, a, b, c, d, e, f);
}

void VGComponent::Translate(float x, float y) { nvgTranslate(vg_, x, y); }

void VGComponent::Rotate(float angle) { nvgRotate(vg_, angle); }

void VGComponent::SkewX(float angle) { nvgSkewX(vg_, angle); }

void VGComponent::SkewY(float angle) { nvgSkewY(vg_, angle); }

void VGComponent::Scale(float x, float y) { nvgScale(vg_, x, y); }

void VGComponent::CurrentTransform(float* xform) { nvgCurrentTransform(vg_, xform); }

void VGComponent::TransformIdentity(float* dst) { nvgTransformIdentity(dst); }

void VGComponent::TransformTranslate(float* dst, float tx, float ty) { nvgTransformTranslate(dst, tx, ty); }

void VGComponent::TransformScale(float* dst, float sx, float sy) { nvgTransformScale(dst, sx, sy); }

void VGComponent::TransformRotate(float* dst, float a) { nvgTransformRotate(dst, a); }

void VGComponent::TransformSkewX(float* dst, float a) { nvgTransformSkewX(dst, a); }

void VGComponent::TransformSkewY(float* dst, float a) { nvgTransformSkewY(dst, a); }

void VGComponent::TransformMultiply(float* dst, const float* src) { nvgTransformMultiply(dst, src); }

void VGComponent::TransformPremultiply(float* dst, const float* src) { nvgTransformPremultiply(dst, src); }

int VGComponent::TransformInverse(float* dst, const float* src) { return nvgTransformInverse(dst, src); }

void VGComponent::TransformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy)
{
    nvgTransformPoint(dstx, dsty, xform, srcx, srcy);
}

float VGComponent::DegToRad(float deg) { return nvgDegToRad(deg); }

float VGComponent::RadToDeg(float rad) { return nvgRadToDeg(rad); }

int VGComponent::CreateImage(const char* filename, int imageFlags)
{
    return nanoVG_->CreateImage(filename, imageFlags);
}

int VGComponent::CreateImageMem(int imageFlags, unsigned char* data, int ndata)
{
    return nanoVG_->CreateImageMem(imageFlags, data, ndata);
}

int VGComponent::CreateImageRGBA(int w, int h, int imageFlags, const unsigned char* data)
{
    return nanoVG_->CreateImageRGBA(w, h, imageFlags, data);
}

void VGComponent::UpdateImage(int image, const unsigned char* data) { nanoVG_->UpdateImage(image, data); }

void VGComponent::ImageSize(int image, int* w, int* h) { nanoVG_->ImageSize(image, w, h); }

void VGComponent::DeleteImage(int image) { nanoVG_->DeleteImage(image); }

NVGpaint VGComponent::LinearGradient(float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol)
{
    return nvgLinearGradient(vg_, sx, sy, ex, ey, icol, ocol);
}

NVGpaint VGComponent::BoxGradient(float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol)
{
    return nvgBoxGradient(vg_, x, y, w, h, r, f, icol, ocol);
}

NVGpaint VGComponent::RadialGradient(float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol)
{
    return nvgRadialGradient(vg_, cx, cy, inr, outr, icol, ocol);
}

NVGpaint VGComponent::ImagePattern(float ox, float oy, float ex, float ey, float angle, int image, float alpha)
{
    return nvgImagePattern(vg_, ox, oy, ex, ey, angle, image, alpha);
}

void VGComponent::Scissor(float x, float y, float w, float h) { nvgScissor(vg_, x, y, w, h); }

void VGComponent::IntersectScissor(float x, float y, float w, float h) { nvgIntersectScissor(vg_, x, y, w, h); }

void VGComponent::ResetScissor() { nvgResetScissor(vg_); }

void VGComponent::BeginPath() { nvgBeginPath(vg_); }

void VGComponent::MoveTo(float x, float y) { nvgMoveTo(vg_, x, y); }

void VGComponent::LineTo(float x, float y) { nvgLineTo(vg_, x, y); }

void VGComponent::BezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y)
{
    nvgBezierTo(vg_, c1x, c1y, c2x, c2y, x, y);
}

void VGComponent::QuadTo(float cx, float cy, float x, float y) { nvgQuadTo(vg_, cx, cy, x, y); }

void VGComponent::ArcTo(float x1, float y1, float x2, float y2, float radius) { nvgArcTo(vg_, x1, y1, x2, y2, radius); }

void VGComponent::ClosePath() { nvgClosePath(vg_); }

void VGComponent::PathWinding(int dir) { nvgPathWinding(vg_, dir); }

void VGComponent::Arc(float cx, float cy, float r, float a0, float a1, int dir) { nvgArc(vg_, cx, cy, r, a0, a1, dir); }

void VGComponent::Rect(float x, float y, float w, float h) { nvgRect(vg_, x, y, w, h); }

void VGComponent::RoundedRect(float x, float y, float w, float h, float r) { nvgRoundedRect(vg_, x, y, w, h, r); }

void VGComponent::RoundedRectVarying(float x, float y, float w, float h, float radTopLeft, float radTopRight,
                                   float radBottomRight, float radBottomLeft)
{
    nvgRoundedRectVarying(vg_, x, y, w, h, radTopLeft, radTopRight, radBottomRight, radBottomLeft);
}

void VGComponent::Ellipse(float cx, float cy, float rx, float ry) { nvgEllipse(vg_, cx, cy, rx, ry); }

void VGComponent::Circle(float cx, float cy, float r) { nvgCircle(vg_, cx, cy, r); }


void VGComponent::Arc(float r, float a0, float a1, int dir) { nvgArc(vg_, r/2.0, r/2.0, r, a0, a1, dir); }

void VGComponent::Rect(float w, float h) { nvgRect(vg_, 0, 0, w, h); }

void VGComponent::RoundedRect(float w, float h, float r) { nvgRoundedRect(vg_, 0, 0, w, h, r); }

void VGComponent::RoundedRectVarying(float w, float h, float radTopLeft, float radTopRight, float radBottomRight,
                                     float radBottomLeft)
{
    nvgRoundedRectVarying(vg_, 0, 0, w, h, radTopLeft, radTopRight, radBottomRight, radBottomLeft);
}

void VGComponent::Ellipse(float rx, float ry) { nvgEllipse(vg_, rx/2.0, ry/2.0, rx, ry); }

void VGComponent::Circle(float r) { nvgCircle(vg_, r/2.0, r/2.0, r); }

void VGComponent::Fill() { nvgFill(vg_); }

void VGComponent::Stroke() { nvgStroke(vg_); }

int VGComponent::CreateFont(const char* name, const char* filename) { return nanoVG_->CreateFont(name, filename); }

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VGComponent::CreateFontAtIndex(const char* name, const char* filename, const int fontIndex)
{
    return nanoVG_->CreateFontAtIndex(name, filename, fontIndex);
}

// Creates font by loading it from the specified memory chunk.
// Returns handle to the font.
int VGComponent::CreateFontMem(const char* name, unsigned char* data, int ndata)
{
    return nanoVG_->CreateFontMem(name, data, ndata);
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VGComponent::CreateFontMemAtIndex(const char* name, unsigned char* data, int ndata, const int fontIndex)
{
    return nanoVG_->CreateFontMemAtIndex(name, data, ndata, fontIndex);
}

// Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
int VGComponent::FindFont(const char* name) { return nanoVG_->FindFont(name); }

// Adds a fallback font by handle.
int VGComponent::AddFallbackFontId(int baseFont, int fallbackFont)
{
    return nanoVG_->AddFallbackFontId(baseFont, fallbackFont);
}

// Adds a fallback font by name.
int VGComponent::AddFallbackFont(const char* baseFont, const char* fallbackFont)
{
    return nanoVG_->AddFallbackFont(baseFont, fallbackFont);
}

// Resets fallback fonts by handle.
void VGComponent::ResetFallbackFontsId(int baseFont) { nanoVG_->ResetFallbackFontsId(baseFont); }

// Resets fallback fonts by name.
void VGComponent::ResetFallbackFonts(const char* baseFont) { nanoVG_->ResetFallbackFonts(baseFont); }

// Sets the font size of current text style.
void VGComponent::FontSize(float size) { nvgFontSize(vg_, size); }

// Sets the blur of current text style.
void VGComponent::FontBlur(float blur) { nvgFontBlur(vg_, blur); }

// Sets the letter spacing of current text style.
void VGComponent::TextLetterSpacing(float spacing) { nvgTextLetterSpacing(vg_, spacing); }

// Sets the proportional line height of current text style. The line height is specified as multiple of font size.
void VGComponent::TextLineHeight(float lineHeight) { nvgTextLineHeight(vg_, lineHeight); }

// Sets the text align of current text style, see NVGalign for options.
void VGComponent::TextAlign(int align) { nvgTextAlign(vg_, align); }

// Sets the font face based on specified id of current text style.
void VGComponent::FontFaceId(int font) { nvgFontFaceId(vg_, font); }

// Sets the font face based on specified name of current text style.
void VGComponent::FontFace(const char* font) { nvgFontFace(vg_, font); }

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float VGComponent::Text(float x, float y, const char* string, const char* end)
{
    return nvgText(vg_, x, y, string, end);
}

// Draws multi-line text string at specified location wrapped at the specified width. If end is specified only the
// sub-string up to the end is drawn. White space is stripped at the beginning of the rows, the text is split at
// word boundaries or when new-line characters are encountered. Words longer than the max width are slit at nearest
// character (i.e. no hyphenation).
void VGComponent::TextBox(float x, float y, float breakRowWidth, const char* string, const char* end)
{
    nvgTextBox(vg_, x, y, breakRowWidth, string, end);
}

// Measures the specified text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Returns the horizontal advance of the measured text (i.e. where the next character should drawn).
// Measured values are returned in local coordinate space.
float VGComponent::TextBounds(float x, float y, const char* string, const char* end, float* bounds)
{
    return nvgTextBounds(vg_, x, y, string, end, bounds);
}

// Measures the specified multi-text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Measured values are returned in local coordinate space.
void VGComponent::TextBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end,
                                float* bounds)
{
    nvgTextBoxBounds(vg_, x, y, breakRowWidth, string, end, bounds);
}

// Calculates the glyph x positions of the specified text. If end is specified only the sub-string will be used.
// Measured values are returned in local coordinate space.
int VGComponent::TextGlyphPositions(float x, float y, const char* string, const char* end, NVGglyphPosition* positions,
                                    int maxPositions)
{
    return nvgTextGlyphPositions(vg_, x, y, string, end, positions, maxPositions);
}

// Returns the vertical metrics based on the current text style.
// Measured values are returned in local coordinate space.
void VGComponent::TextMetrics(float* ascender, float* descender, float* lineh)
{
    nvgTextMetrics(vg_, ascender, descender, lineh);
}

// Breaks the specified text into lines. If end is specified only the sub-string will be used.
// White space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line
// characters are encountered. Words longer than the max width are slit at nearest character (i.e. no hyphenation).
int VGComponent::TextBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows)
{
    return nvgTextBreakLines(vg_, string, end, breakRowWidth, rows, maxRows);
}


// Sets the font face based on specified name of current text style.
 void VGComponent::FontFace( const String& font)
 {
    nvgFontFace(vg_, font.CString());
 }

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float VGComponent::Text( float x, float y, const String& string)
{
    return nvgText(vg_, x, y, string.CString(), nullptr);
}

void VGComponent::TextBox( float x, float y, float breakRowWidth, const String& str)
{
    nvgTextBox(vg_, x, y, breakRowWidth, str.CString(), nullptr);
}

float VGComponent::TextBounds( float x, float y, const String& str, float* bounds)
{
    return nvgTextBounds(vg_, x, y, str.CString(), nullptr, bounds);
}

void VGComponent::TextBoxBounds( float x, float y, float breakRowWidth, const String& str,float* bounds)
{
    nvgTextBoxBounds(vg_, x, y, breakRowWidth, str.CString(), nullptr, bounds);
}

int VGComponent::TextGlyphPositions( float x, float y, const String& str,
                          float* positions, int maxPositions)
{
    int nglyphs = 0;
    NVGglyphPosition  * glyphs = new NVGglyphPosition[maxPositions];
    if(glyphs != nullptr)
    {
        nglyphs = TextGlyphPositions(x, y, str.CString(), nullptr, glyphs, maxPositions);
        for(int i = 0 ; i < nglyphs ; i++)
        {
            positions[i*4+0] = (float)(glyphs[i].str - str.CString());
            positions[i*4+1] = glyphs[i].x;
            positions[i*4+2] = glyphs[i].minx;
            positions[i*4+3] = glyphs[i].maxx;
        }
        
        delete [] glyphs;
        glyphs = nullptr;
    }
    
    return nglyphs;
}

unsigned int VGComponent::TextBreakLines(const String& str, float breakRowWidth, VGTextRowBuffer * vgTextRowBuffer)
{
    NVGtextRow rows[3];
    const char* start;
    const char* end;
    int nrows, i, nglyphs, j, lnum = 0;
    
    vgTextRowBuffer->Clear();
    start = str.CString();
    end = str.CString() + strlen(str.CString());
    while ((nrows = TextBreakLines(start, end, breakRowWidth, rows, 3)))
    {
        for (i = 0; i < nrows; i++)
        {
            NVGtextRow* row = &rows[i];
            VGTextRow * vgRow = new VGTextRow(context_);
            String str(row->start,row->end - row->start);
            str.Append('\0');
            vgRow->SetText(str);
            vgRow->SetMax(row->maxx);
            vgRow->SetMin(row->minx);
            vgRow->SetWidth(row->width);
            
            
            vgTextRowBuffer->AddRow(vgRow);
        
        }
        // Keep going...
        start = rows[nrows - 1].next;
    }
    
    return vgTextRowBuffer->GetSize();
}

} // namespace Urho3D
