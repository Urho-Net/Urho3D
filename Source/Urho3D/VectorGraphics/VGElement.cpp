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

#include "../Core/Context.h"
#include "../Graphics/GraphicsEvents.h"
#include "../Input/InputEvents.h"
#include "../UI/UI.h"
#include "../UI/UIEvents.h"

#if defined(URHO3D_DOTNET)
#include "../DotNet/Mono.h"
#endif

#include "VectorGraphics.h"
#include "VGElement.h"
#include "VGEvents.h"

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#endif

#include "nanovg_gl_utils.h"

#include "../DebugNew.h"

namespace Urho3D
{

VGElement::VGElement(Context* context)
    : BorderImage(context)
    , nvgFrameBuffer_(NULL)
{
    nanoVG_ = GetSubsystem<VectorGraphics>();
    vg_ = nanoVG_->GetNVGContext();
    graphics_ = GetSubsystem<Graphics>();
    drawTexture_ = NULL;
    clearColor_ = Color(0.0,0.0,0.0,1.0);

    nvgFrameBuffer_ = nullptr;
    
// TBD ELI , disabled for now
    // if it is not visible because of parent then mark it as such
//    if(this->IsVisibleEffective() == false)
//    {
//        isHiddenByParent = true;
//        SetVisible(false);
//    }

    SubscribeToEvent(E_ENDRENDERING, URHO3D_HANDLER(VGElement, HandleRender));
    //TBD ELI disabled for now
//    SubscribeToEvent(E_VISIBLECHANGED, URHO3D_HANDLER(VGElement, HandleVisibleChanged));
}

VGElement::~VGElement()
{
    UnsubscribeFromAllEvents();
    
    VectorGraphics* nanovg = GetSubsystem<VectorGraphics>();
    NVGcontext* vg = nanovg->GetNVGContext();

    VGFrameBuffer_.Reset();

    if (vg)
    {
        nvgluDeleteFramebuffer(nvgFrameBuffer_);
        nvgFrameBuffer_ = NULL;
    }
    else
    {
        if (nvgFrameBuffer_ != nullptr)
        {

            if (nvgFrameBuffer_->fbo != 0)
                glDeleteFramebuffers(1, &nvgFrameBuffer_->fbo);
            if (nvgFrameBuffer_->rbo != 0)
                glDeleteRenderbuffers(1, &nvgFrameBuffer_->rbo);
        }
    }

    if (drawTexture_ != NULL)
    {
        SetTexture(nullptr);
        drawTexture_->Release();
        drawTexture_.Reset();
        drawTexture_ = NULL;
        imageRect_ = IntRect::ZERO;
    }
}

void VGElement::RegisterObject(Context* context)
{
    context->RegisterFactory<VGElement>("UI");
    URHO3D_COPY_BASE_ATTRIBUTES(BorderImage);
    URHO3D_UPDATE_ATTRIBUTE_DEFAULT_VALUE("Is Enabled", true);
}

void VGElement::SetClearColor(Color color) {

    if (VGFrameBuffer_)
    {
        VGFrameBuffer_->SetClearColor(color);
    }

    clearColor_ = color; 

}

Color VGElement::GetClearColor() 
{ 
    if (VGFrameBuffer_)
    {
        return VGFrameBuffer_->GetClearColor();
    }
    return clearColor_; 
}

 IntVector2 VGElement::GetSize() 
 { 
     if (VGFrameBuffer_)
     {
         return VGFrameBuffer_->GetSize();
     }

     return textureSize_; 
 }

void VGElement::BeginRender()
{
    if (VGFrameBuffer_)
    {
        VGFrameBuffer_->Bind();
    }
    else
    if (nvgFrameBuffer_ != nullptr && vg_ != nullptr)
    {

        glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &previousVBO);
        glGetIntegerv(GL_FRAMEBUFFER_BINDING, &previousFBO);

        previousVS = graphics_->GetVertexShader();
        previousPS = graphics_->GetPixelShader();

        graphics_->SetShaders(NULL, NULL);

        glBindFramebuffer(GL_FRAMEBUFFER, nvgFrameBuffer_->fbo);

        
        graphics_->ClearParameterSources();
        graphics_->SetColorWrite(true);
        graphics_->SetCullMode(CULL_NONE);
        graphics_->SetDepthTest(CMP_ALWAYS);
        graphics_->SetDepthWrite(false);
        graphics_->SetFillMode(FILL_SOLID);
        graphics_->SetStencilTest(false);
        graphics_->SetScissorTest(false);
        graphics_->Clear(CLEAR_COLOR | CLEAR_DEPTH | CLEAR_STENCIL, clearColor_, 0, 0);
        

        glViewport(0, 0, textureSize_.x_, textureSize_.y_);
  

        nvgBeginFrame(vg_, textureSize_.x_, textureSize_.y_, 1.0f);

        // TBD ELI , hack to flip the image horizontal
        nvgTranslate(vg_, textureSize_.x_ / 2, textureSize_.y_ / 2);
        nvgScale(vg_, 1.0, -1.0);
        nvgTranslate(vg_, -textureSize_.x_ / 2, -textureSize_.y_ / 2);
    }

   
}

void VGElement::EndRender()
{

    if (VGFrameBuffer_)
    {
        VGFrameBuffer_->UnBind();
    }
    else
    if (nvgFrameBuffer_ != nullptr && vg_ != nullptr)
    {
        nvgEndFrame(vg_);
        //  Urho3D restore old values
        glBindFramebuffer(GL_FRAMEBUFFER, previousFBO);
        glBindBuffer(GL_ARRAY_BUFFER, previousVBO);
        glEnable(GL_DEPTH_TEST);
        graphics_->SetCullMode(CULL_CCW);
        graphics_->SetDepthTest(CMP_LESSEQUAL);
        graphics_->SetDepthWrite(true);
        graphics_->SetShaders(previousVS, previousPS);
    }
    
}

void VGElement::HandleRender(StringHash eventType, VariantMap& eventData)
{
    if (vg_ != nullptr && this->IsVisibleEffective() == true)
    {
        BeginRender();

        using namespace OnVGElementRender;

        VariantMap& eventData = GetEventDataMap();

        eventData[P_VGELEMENT] = this;

        this->SendEvent(E_VGELEMENTRENDER, eventData);
#if defined(URHO3D_DOTNET)
        Mono::Callback(VGElement_Render, this);
#endif
        EndRender();
    }
}

void VGElement::HandleVisibleChanged(StringHash eventType, VariantMap& eventData)
{
// TBD ELI , need to check all if all use cases are valid
    
//    using namespace VisibleChanged;
//    UIElement* uiElement = static_cast<UIElement*>(eventData[P_ELEMENT].GetPtr());
//    bool isVisible = eventData[P_VISIBLE].GetBool();
//    if(this != uiElement && this->IsChildOf(uiElement))
//    {
//        // parent is visible
//        if(isVisible == true)
//        {
//            SetVisible(true);
//
//            // this element was hidden because of paretn , make it visible
//            if(isHiddenByParent == true && this->IsVisibleEffective() == true)
//            {
//                isHiddenByParent = false;
//                SetVisible(isVisible);
//            }
//            else
//            {
//                SetVisible(false);
//            }
//        }
//        else
//        {
//            isHiddenByParent = true;
//            SetVisible(isVisible);
//        }
//
//    }
    
}

void VGElement::OnResize(const IntVector2& newSize, const IntVector2& delta)
{
  //  CreateFrameBuffer(newSize.x_, newSize.y_);
 
    VGFrameBuffer_ = new VGFrameBuffer(context_, newSize.x_, newSize.y_);
    VGFrameBuffer_->SetClearColor(this->clearColor_);
    imageRect_ = IntRect::ZERO;
    SetTexture(VGFrameBuffer_->GetRenderTarget());
    
}

Texture2D* VGElement::GetRenderTarget()
{
    if(VGFrameBuffer_ != nullptr)
    {
        return VGFrameBuffer_->GetRenderTarget();
    }
    else{
        return nullptr;
    }
}

void VGElement::CreateFrameBuffer(int width, int height)
{

    if (width == 0 || height == 0)
        return;

    VectorGraphics* nanovg = GetSubsystem<VectorGraphics>();
    NVGcontext* vg_ = nanovg->GetNVGContext();

    nvgluDeleteFramebuffer(nvgFrameBuffer_);
    nvgFrameBuffer_ = NULL;
    if (drawTexture_ != NULL)
    {
        SetTexture(nullptr);
        drawTexture_->Release();
        drawTexture_.Reset();
        drawTexture_ = NULL;
        imageRect_ = IntRect::ZERO;
    }

    drawTexture_ = new Texture2D(context_);
    textureSize_ = IntVector2(width, height);
    drawTexture_->SetMipsToSkip(QUALITY_HIGH, 0);
    drawTexture_->SetNumLevels(1);
    drawTexture_->SetSize(textureSize_.x_, textureSize_.y_, Graphics::GetRGBAFormat(), TEXTURE_RENDERTARGET);

    unsigned TextureID = drawTexture_->GetGPUObjectName();

    GLint defaultFBO;
    GLint defaultRBO;
    NVGLUframebuffer* fb = NULL;

    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFBO);
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &defaultRBO);

    fb = (NVGLUframebuffer*)malloc(sizeof(NVGLUframebuffer));
    if (fb == NULL)
        goto error;
    memset(fb, 0, sizeof(NVGLUframebuffer));

    fb->texture = TextureID;
    fb->image = -1;
    fb->ctx = vg_;

    // frame buffer object
    glGenFramebuffers(1, &fb->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fb->fbo);

    // render buffer object
    glGenRenderbuffers(1, &fb->rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, fb->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, width, height);

    // combine all
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fb->texture, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, fb->rbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
#ifdef GL_DEPTH24_STENCIL8
        // If GL_STENCIL_INDEX8 is not supported, try GL_DEPTH24_STENCIL8 as a fallback.
        // Some graphics cards require a depth buffer along with a stencil.
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fb->texture, 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, fb->rbo);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
#endif // GL_DEPTH24_STENCIL8
            goto error;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, defaultFBO);
    glBindRenderbuffer(GL_RENDERBUFFER, defaultRBO);
    nvgFrameBuffer_ = fb;
    SetTexture(drawTexture_);
    return;
error:
    glBindFramebuffer(GL_FRAMEBUFFER, defaultFBO);
    glBindRenderbuffer(GL_RENDERBUFFER, defaultRBO);
    nvgluDeleteFramebuffer(fb);
    nvgFrameBuffer_ = NULL;
    delete drawTexture_;
    drawTexture_ = NULL;
}

void VGElement::BeginFrame(float windowWidth, float windowHeight, float devicePixelRatio)
{
    nvgBeginFrame(vg_, windowWidth, windowHeight, devicePixelRatio);
}

void VGElement::CancelFrame() { nvgCancelFrame(vg_); }

void VGElement::EndFrame() { nvgEndFrame(vg_); }

void VGElement::GlobalCompositeOperation(int op) { nvgGlobalCompositeOperation(vg_, op); }

void VGElement::GlobalCompositeBlendFunc(int sfactor, int dfactor)
{
    nvgGlobalCompositeBlendFunc(vg_, sfactor, dfactor);
}

void VGElement::GlobalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha)
{
    nvgGlobalCompositeBlendFuncSeparate(vg_, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

NVGcolor VGElement::RGB(unsigned char r, unsigned char g, unsigned char b) { return nvgRGB(r, g, b); }

NVGcolor VGElement::RGBf(float r, float g, float b) { return nvgRGBf(r, g, b); }

NVGcolor VGElement::RGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return nvgRGBA(r, g, b, a);
}

NVGcolor VGElement::RGBAf(float r, float g, float b, float a) { return nvgRGBAf(r, g, b, a); }

NVGcolor VGElement::LerpRGBA(NVGcolor c0, NVGcolor c1, float u) { return nvgLerpRGBA(c0, c1, u); }

NVGcolor VGElement::TransRGBA(NVGcolor c0, unsigned char a) { return nvgTransRGBA(c0, a); }

NVGcolor VGElement::TransRGBAf(NVGcolor c0, float a) { return nvgTransRGBAf(c0, a); }

NVGcolor VGElement::HSL(float h, float s, float l) { return nvgHSL(h, s, l); }

NVGcolor VGElement::HSLA(float h, float s, float l, unsigned char a) { return nvgHSLA(h, s, l, a); }

void VGElement::SaveState() { nvgSave(vg_); }

void VGElement::RestoreState() { nvgRestore(vg_); }

void VGElement::ResetState() { nvgReset(vg_); }

void VGElement::ShapeAntiAlias(int enabled) { nvgShapeAntiAlias(vg_, enabled); }

void VGElement::StrokeColor(NVGcolor color) { nvgStrokeColor(vg_, color); }

void VGElement::StrokePaint(NVGpaint paint) { nvgStrokePaint(vg_, paint); }

void VGElement::FillColor(NVGcolor color) { nvgFillColor(vg_, color); }

void VGElement::FillPaint(NVGpaint paint) { nvgFillPaint(vg_, paint); }

void VGElement::MiterLimit(float limit) { nvgMiterLimit(vg_, limit); }

void VGElement::StrokeWidth(float size) { nvgStrokeWidth(vg_, size); }

void VGElement::LineCap(int cap) { nvgLineCap(vg_, cap); }

void VGElement::LineJoin(int join) { nvgLineJoin(vg_, join); }

void VGElement::GlobalAlpha(float alpha) { nvgGlobalAlpha(vg_, alpha); }

void VGElement::ResetTransform() { nvgResetTransform(vg_); }

void VGElement::Transform(float a, float b, float c, float d, float e, float f) { nvgTransform(vg_, a, b, c, d, e, f); }

void VGElement::Translate(float x, float y) { nvgTranslate(vg_, x, y); }

void VGElement::Rotate(float angle) { nvgRotate(vg_, angle); }

void VGElement::SkewX(float angle) { nvgSkewX(vg_, angle); }

void VGElement::SkewY(float angle) { nvgSkewY(vg_, angle); }

void VGElement::Scale(float x, float y) { nvgScale(vg_, x, y); }

void VGElement::CurrentTransform(float* xform) { nvgCurrentTransform(vg_, xform); }

void VGElement::TransformIdentity(float* dst) { nvgTransformIdentity(dst); }

void VGElement::TransformTranslate(float* dst, float tx, float ty) { nvgTransformTranslate(dst, tx, ty); }

void VGElement::TransformScale(float* dst, float sx, float sy) { nvgTransformScale(dst, sx, sy); }

void VGElement::TransformRotate(float* dst, float a) { nvgTransformRotate(dst, a); }

void VGElement::TransformSkewX(float* dst, float a) { nvgTransformSkewX(dst, a); }

void VGElement::TransformSkewY(float* dst, float a) { nvgTransformSkewY(dst, a); }

void VGElement::TransformMultiply(float* dst, const float* src) { nvgTransformMultiply(dst, src); }

void VGElement::TransformPremultiply(float* dst, const float* src) { nvgTransformPremultiply(dst, src); }

int VGElement::TransformInverse(float* dst, const float* src) { return nvgTransformInverse(dst, src); }

void VGElement::TransformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy)
{
    nvgTransformPoint(dstx, dsty, xform, srcx, srcy);
}

float VGElement::DegToRad(float deg) { return nvgDegToRad(deg); }

float VGElement::RadToDeg(float rad) { return nvgRadToDeg(rad); }

int VGElement::CreateImage(const char* filename, int imageFlags)
{
    return nanoVG_->CreateImage(filename, imageFlags);
}

int VGElement::CreateImageMem(int imageFlags, unsigned char* data, int ndata)
{
    return nanoVG_->CreateImageMem(imageFlags, data, ndata);
}

int VGElement::CreateImageRGBA(int w, int h, int imageFlags, const unsigned char* data)
{
    return nanoVG_->CreateImageRGBA( w, h, imageFlags, data);
}

void VGElement::UpdateImage(int image, const unsigned char* data) { nanoVG_->UpdateImage(image, data); }

void VGElement::ImageSize(int image, int* w, int* h) { nanoVG_->ImageSize(image, w, h); }

void VGElement::DeleteImage(int image) { nanoVG_->DeleteImage( image); }

NVGpaint VGElement::LinearGradient(float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol)
{
    return nvgLinearGradient(vg_, sx, sy, ex, ey, icol, ocol);
}

NVGpaint VGElement::BoxGradient(float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol)
{
    return nvgBoxGradient(vg_, x, y, w, h, r, f, icol, ocol);
}

NVGpaint VGElement::RadialGradient(float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol)
{
    return nvgRadialGradient(vg_, cx, cy, inr, outr, icol, ocol);
}

NVGpaint VGElement::ImagePattern(float ox, float oy, float ex, float ey, float angle, int image, float alpha)
{
    return nvgImagePattern(vg_, ox, oy, ex, ey, angle, image, alpha);
}

void VGElement::Scissor(float x, float y, float w, float h) { nvgScissor(vg_, x, y, w, h); }

void VGElement::IntersectScissor(float x, float y, float w, float h) { nvgIntersectScissor(vg_, x, y, w, h); }

void VGElement::ResetScissor() { nvgResetScissor(vg_); }

void VGElement::BeginPath() { nvgBeginPath(vg_); }

void VGElement::MoveTo(float x, float y) { nvgMoveTo(vg_, x, y); }

void VGElement::LineTo(float x, float y) { nvgLineTo(vg_, x, y); }

void VGElement::BezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y)
{
    nvgBezierTo(vg_, c1x, c1y, c2x, c2y, x, y);
}

void VGElement::QuadTo(float cx, float cy, float x, float y) { nvgQuadTo(vg_, cx, cy, x, y); }

void VGElement::ArcTo(float x1, float y1, float x2, float y2, float radius) { nvgArcTo(vg_, x1, y1, x2, y2, radius); }

void VGElement::ClosePath() { nvgClosePath(vg_); }

void VGElement::PathWinding(int dir) { nvgPathWinding(vg_, dir); }

void VGElement::Arc(float cx, float cy, float r, float a0, float a1, int dir) { nvgArc(vg_, cx, cy, r, a0, a1, dir); }

void VGElement::Rect(float x, float y, float w, float h) { nvgRect(vg_, x, y, w, h); }

void VGElement::RoundedRect(float x, float y, float w, float h, float r) { nvgRoundedRect(vg_, x, y, w, h, r); }

void VGElement::RoundedRectVarying(float x, float y, float w, float h, float radTopLeft, float radTopRight,
                                   float radBottomRight, float radBottomLeft)
{
    nvgRoundedRectVarying(vg_, x, y, w, h, radTopLeft, radTopRight, radBottomRight, radBottomLeft);
}

void VGElement::Ellipse(float cx, float cy, float rx, float ry) { nvgEllipse(vg_, cx, cy, rx, ry); }

void VGElement::Circle(float cx, float cy, float r) { nvgCircle(vg_, cx, cy, r); }

void VGElement::Fill() { nvgFill(vg_); }

void VGElement::Stroke() { nvgStroke(vg_); }

int VGElement::CreateFont(const char* name, const char* filename)
{

    return nanoVG_->CreateFont(name, filename);
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VGElement::CreateFontAtIndex(const char* name, const char* filename, const int fontIndex)
{
    return nanoVG_->CreateFontAtIndex(name, filename, fontIndex);
}

// Creates font by loading it from the specified memory chunk.
// Returns handle to the font.
int VGElement::CreateFontMem(const char* name, unsigned char* data, int ndata)
{
    return nanoVG_->CreateFontMem( name, data, ndata);
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VGElement::CreateFontMemAtIndex(const char* name, unsigned char* data, int ndata, const int fontIndex)
{
    return nanoVG_->CreateFontMemAtIndex( name, data, ndata, fontIndex);
}

// Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
int VGElement::FindFont(const char* name) { return nanoVG_->FindFont(name); }

// Adds a fallback font by handle.
int VGElement::AddFallbackFontId(int baseFont, int fallbackFont)
{
    return nanoVG_->AddFallbackFontId( baseFont, fallbackFont);
}

// Adds a fallback font by name.
int VGElement::AddFallbackFont(const char* baseFont, const char* fallbackFont)
{
    return nanoVG_->AddFallbackFont( baseFont, fallbackFont);
}

// Resets fallback fonts by handle.
void VGElement::ResetFallbackFontsId(int baseFont) { nanoVG_->ResetFallbackFontsId( baseFont); }

// Resets fallback fonts by name.
void VGElement::ResetFallbackFonts(const char* baseFont) { nanoVG_->ResetFallbackFonts( baseFont); }

// Sets the font size of current text style.
void VGElement::FontSize(float size) { nvgFontSize(vg_, size); }

// Sets the blur of current text style.
void VGElement::FontBlur(float blur) { nvgFontBlur(vg_, blur); }

// Sets the letter spacing of current text style.
void VGElement::TextLetterSpacing(float spacing) { nvgTextLetterSpacing(vg_, spacing); }

// Sets the proportional line height of current text style. The line height is specified as multiple of font size.
void VGElement::TextLineHeight(float lineHeight) { nvgTextLineHeight(vg_, lineHeight); }

// Sets the text align of current text style, see NVGalign for options.
void VGElement::TextAlign(int align) { nvgTextAlign(vg_, align); }

// Sets the font face based on specified id of current text style.
void VGElement::FontFaceId(int font) { nvgFontFaceId(vg_, font); }

// Sets the font face based on specified name of current text style.
 void VGElement::FontFace(const char* font) { nvgFontFace(vg_, font); }

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float VGElement::Text(float x, float y, const char* string, const char* end) { return nvgText(vg_, x, y, string, end); }

// Draws multi-line text string at specified location wrapped at the specified width. If end is specified only the
// sub-string up to the end is drawn. White space is stripped at the beginning of the rows, the text is split at
// word boundaries or when new-line characters are encountered. Words longer than the max width are slit at nearest
// character (i.e. no hyphenation).
void VGElement::TextBox(float x, float y, float breakRowWidth, const char* string, const char* end)
{
    nvgTextBox(vg_, x, y, breakRowWidth, string, end);
}

// Measures the specified text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Returns the horizontal advance of the measured text (i.e. where the next character should drawn).
// Measured values are returned in local coordinate space.
float VGElement::TextBounds(float x, float y, const char* string, const char* end, float* bounds)
{
    return nvgTextBounds(vg_, x, y, string, end, bounds);
}


// Measures the specified multi-text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Measured values are returned in local coordinate space.
void VGElement::TextBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds)
{
    nvgTextBoxBounds(vg_, x, y, breakRowWidth, string, end, bounds);
}


// Calculates the glyph x positions of the specified text. If end is specified only the sub-string will be used.
// Measured values are returned in local coordinate space.
int VGElement::TextGlyphPositions(float x, float y, const char* string, const char* end, NVGglyphPosition* positions,
                                  int maxPositions)
{
    return nvgTextGlyphPositions(vg_, x, y, string, end, positions, maxPositions);
}

// Returns the vertical metrics based on the current text style.
// Measured values are returned in local coordinate space.
void VGElement::TextMetrics(float* ascender, float* descender, float* lineh)
{
    nvgTextMetrics(vg_, ascender, descender, lineh);
}

// Breaks the specified text into lines. If end is specified only the sub-string will be used.
// White space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line
// characters are encountered. Words longer than the max width are slit at nearest character (i.e. no hyphenation).
int VGElement::TextBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows)
{
    return nvgTextBreakLines(vg_, string, end, breakRowWidth, rows, maxRows);
}


// Sets the font face based on specified name of current text style.
 void VGElement::FontFace( const String& font)
 {
    nvgFontFace(vg_, font.CString());
 }

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float VGElement::Text( float x, float y, const String& string)
{
    return nvgText(vg_, x, y, string.CString(), nullptr);
}

void VGElement::TextBox( float x, float y, float breakRowWidth, const String& str)
{
    nvgTextBox(vg_, x, y, breakRowWidth, str.CString(), nullptr);
}

float VGElement::TextBounds( float x, float y, const String& str, float* bounds)
{
    return nvgTextBounds(vg_, x, y, str.CString(), nullptr, bounds);
}

void VGElement::TextBoxBounds( float x, float y, float breakRowWidth, const String& str,float* bounds)
{
    nvgTextBoxBounds(vg_, x, y, breakRowWidth, str.CString(), nullptr, bounds);
}

int VGElement::TextGlyphPositions( float x, float y, const String& str,
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

unsigned int VGElement::TextBreakLines(const String& str, float breakRowWidth, VGTextRowBuffer * vgTextRowBuffer)
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
