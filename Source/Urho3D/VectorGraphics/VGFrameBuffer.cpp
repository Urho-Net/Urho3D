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
#include "VGFrameBuffer.h"
#include "VectorGraphics.h"
#include "VGEvents.h"
#include "nanovg.h"
#include "../Core/Context.h"
#include "../Graphics/GraphicsEvents.h"

#include "nanovg_gl_utils.h"

namespace Urho3D
{

static VGFrameBuffer* CurrenVGFrameBuffer_ = nullptr;

void VGFrameBuffer::RegisterObject(Context* context)
{
    context->RegisterFactory<VGFrameBuffer>("UI");
}

VGFrameBuffer* VGFrameBuffer::Current() 
{ 
    return CurrenVGFrameBuffer_; 
}

VGFrameBuffer::VGFrameBuffer(Context* context)
    : Component(context)
    , nvgFrameBuffer_(nullptr)
{
    nanoVG_ = GetSubsystem<VectorGraphics>();
    vg_ = nanoVG_->GetNVGContext();
    graphics_ = GetSubsystem<Graphics>();

    drawTexture_ = nullptr;
    clearColor_ = Color(0.0, 0.0, 0.0, 1.0);
}

VGFrameBuffer::VGFrameBuffer(Context* context, int Width, int Height)
    : Component(context)
    , nvgFrameBuffer_(nullptr)
{
    nanoVG_ = GetSubsystem<VectorGraphics>();
    vg_ = nanoVG_->GetNVGContext();
    graphics_ = GetSubsystem<Graphics>();

    drawTexture_ = nullptr;
    clearColor_ = Color(0.0, 0.0, 0.0, 1.0);

    CreateFrameBuffer(Width, Height);
}

VGFrameBuffer::~VGFrameBuffer()
{

    if (nanoVG_.Get() && vg_)
    {
        nvgluDeleteFramebuffer(nvgFrameBuffer_);
        nvgFrameBuffer_ = NULL;
    }
    else
    {
        if (nvgFrameBuffer_->fbo != 0)
            glDeleteFramebuffers(1, &nvgFrameBuffer_->fbo);
        if (nvgFrameBuffer_->rbo != 0)
            glDeleteRenderbuffers(1, &nvgFrameBuffer_->rbo);
    }

    if (drawTexture_ != NULL)
    {
        drawTexture_->Release();
        drawTexture_.Reset();
        drawTexture_ = NULL;
    }
}

void VGFrameBuffer::SetClearColor(Color color) { clearColor_ = color; }

Color VGFrameBuffer::GetClearColor() { return clearColor_; }

bool VGFrameBuffer::CreateFrameBuffer(int width, int height)
{

    if (width == 0 || height == 0)
        return false;

    if (nanoVG_ == nullptr || vg_ == nullptr)
    {
        return false;
    }

    nvgluDeleteFramebuffer(nvgFrameBuffer_);
    nvgFrameBuffer_ = NULL;
    if (drawTexture_ != NULL)
    {

        drawTexture_->Release();
        drawTexture_.Reset();
        drawTexture_ = NULL;
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

    fb->image = -1;
    fb->texture = TextureID;

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
    return true;
error:
    glBindFramebuffer(GL_FRAMEBUFFER, defaultFBO);
    glBindRenderbuffer(GL_RENDERBUFFER, defaultRBO);
    nvgluDeleteFramebuffer(fb);
    nvgFrameBuffer_ = NULL;
    delete drawTexture_;
    drawTexture_ = NULL;
    return false;
}


void VGFrameBuffer::EnableRenderEvents() {

      SubscribeToEvent(E_ENDRENDERING, URHO3D_HANDLER(VGFrameBuffer, HandleRender));
}

void VGFrameBuffer::DisbaleRenderEvents() 
{ 
    UnsubscribeFromEvent(E_ENDRENDERING); 
}

void VGFrameBuffer::HandleRender(StringHash eventType, VariantMap& eventData) {

    if (nvgFrameBuffer_ != nullptr && nanoVG_ != nullptr && vg_ != nullptr)
    {
        Bind();

        using namespace OnVGFrameBufferRender;

        VariantMap& eventData = GetEventDataMap();

        eventData[P_VGFRAMEBUFFER] = this;

        this->SendEvent(E_VGFRAMEBUFFERRENDER, eventData);

        UnBind();
    }

}


void VGFrameBuffer::Bind()
{
    if (nvgFrameBuffer_ != nullptr && nanoVG_ != nullptr && vg_ != nullptr)
    {
        if (CurrenVGFrameBuffer_ == this)
        {
            return;
        }

        if (CurrenVGFrameBuffer_)
        {
            CurrenVGFrameBuffer_->UnBind();
            CurrenVGFrameBuffer_ = nullptr;
        }
        CurrenVGFrameBuffer_ = this;

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

        // Flip the image on the horizontal axis
        float midx = textureSize_.x_ / 2.0f;
        float midy = textureSize_.y_ / 2.0f;
        nvgTranslate(vg_, midx, midy);
        nvgScale(vg_, 1.0, -1.0);
        nvgTranslate(vg_, -midx, -midy);
    }
}

void VGFrameBuffer::UnBind()
{
    if (nvgFrameBuffer_ != nullptr && nanoVG_ != nullptr && vg_ != nullptr)
    {
        if (CurrenVGFrameBuffer_ == this)
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
            CurrenVGFrameBuffer_ = nullptr;
        }
    }
}

Texture2D* VGFrameBuffer::GetRenderTarget() { return drawTexture_; }

void VGFrameBuffer::BeginFrame() { Bind(); }

void VGFrameBuffer::CancelFrame()
{
    Bind();
    nvgCancelFrame(vg_);
}

void VGFrameBuffer::EndFrame() { UnBind(); }

void VGFrameBuffer::GlobalCompositeOperation(int op)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgGlobalCompositeOperation(vg_, op);
}

void VGFrameBuffer::GlobalCompositeBlendFunc(int sfactor, int dfactor)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgGlobalCompositeBlendFunc(vg_, sfactor, dfactor);
}

void VGFrameBuffer::GlobalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha)
{
    if (CurrenVGFrameBuffer_ == this)
    nvgGlobalCompositeBlendFuncSeparate(vg_, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

NVGcolor VGFrameBuffer::RGB(unsigned char r, unsigned char g, unsigned char b) { return nvgRGB(r, g, b); }

NVGcolor VGFrameBuffer::RGBf(float r, float g, float b) { return nvgRGBf(r, g, b); }

NVGcolor VGFrameBuffer::RGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return nvgRGBA(r, g, b, a);
}

NVGcolor VGFrameBuffer::RGBAf(float r, float g, float b, float a) { return nvgRGBAf(r, g, b, a); }

NVGcolor VGFrameBuffer::LerpRGBA(NVGcolor c0, NVGcolor c1, float u) { return nvgLerpRGBA(c0, c1, u); }

NVGcolor VGFrameBuffer::TransRGBA(NVGcolor c0, unsigned char a) { return nvgTransRGBA(c0, a); }

NVGcolor VGFrameBuffer::TransRGBAf(NVGcolor c0, float a) { return nvgTransRGBAf(c0, a); }

NVGcolor VGFrameBuffer::HSL(float h, float s, float l) { return nvgHSL(h, s, l); }

NVGcolor VGFrameBuffer::HSLA(float h, float s, float l, unsigned char a) { return nvgHSLA(h, s, l, a); }

void VGFrameBuffer::SaveState()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgSave(vg_);
}

void VGFrameBuffer::RestoreState()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgRestore(vg_);
}

void VGFrameBuffer::ResetState()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgReset(vg_);
}

void VGFrameBuffer::ShapeAntiAlias(int enabled)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgShapeAntiAlias(vg_, enabled);
}

void VGFrameBuffer::StrokeColor(NVGcolor color)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgStrokeColor(vg_, color);
}

void VGFrameBuffer::StrokePaint(NVGpaint paint)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgStrokePaint(vg_, paint);
}

void VGFrameBuffer::FillColor(NVGcolor color)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFillColor(vg_, color);
}

void VGFrameBuffer::FillPaint(NVGpaint paint)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFillPaint(vg_, paint);
}

void VGFrameBuffer::MiterLimit(float limit)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgMiterLimit(vg_, limit);
}

void VGFrameBuffer::StrokeWidth(float size)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgStrokeWidth(vg_, size);
}

void VGFrameBuffer::LineCap(int cap)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgLineCap(vg_, cap);
}

void VGFrameBuffer::LineJoin(int join)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgLineJoin(vg_, join);
}

void VGFrameBuffer::GlobalAlpha(float alpha)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgGlobalAlpha(vg_, alpha);
}

void VGFrameBuffer::ResetTransform()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgResetTransform(vg_);
}

void VGFrameBuffer::Transform(float a, float b, float c, float d, float e, float f)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransform(vg_, a, b, c, d, e, f);
}

void VGFrameBuffer::Translate(float x, float y)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTranslate(vg_, x, y);
}

void VGFrameBuffer::Rotate(float angle)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgRotate(vg_, angle);
}

void VGFrameBuffer::SkewX(float angle)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgSkewX(vg_, angle);
}

void VGFrameBuffer::SkewY(float angle)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgSkewY(vg_, angle);
}

void VGFrameBuffer::Scale(float x, float y)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgScale(vg_, x, y);
}

void VGFrameBuffer::CurrentTransform(float* xform)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgCurrentTransform(vg_, xform);
}

void VGFrameBuffer::TransformIdentity(float* dst)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformIdentity(dst);
}

void VGFrameBuffer::TransformTranslate(float* dst, float tx, float ty)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformTranslate(dst, tx, ty);
}

void VGFrameBuffer::TransformScale(float* dst, float sx, float sy)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformScale(dst, sx, sy);
}

void VGFrameBuffer::TransformRotate(float* dst, float a)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformRotate(dst, a);
}

void VGFrameBuffer::TransformSkewX(float* dst, float a)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformSkewX(dst, a);
}

void VGFrameBuffer::TransformSkewY(float* dst, float a)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformSkewY(dst, a);
}

void VGFrameBuffer::TransformMultiply(float* dst, const float* src)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformMultiply(dst, src);
}

void VGFrameBuffer::TransformPremultiply(float* dst, const float* src)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTransformPremultiply(dst, src);
}

int VGFrameBuffer::TransformInverse(float* dst, const float* src)
{
    if (CurrenVGFrameBuffer_ == this)
        return nvgTransformInverse(dst, src);
    else
        return 0;
}

void VGFrameBuffer::TransformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy)
{
    if (CurrenVGFrameBuffer_ == this)
    nvgTransformPoint(dstx, dsty, xform, srcx, srcy);
}

float VGFrameBuffer::DegToRad(float deg) { return nvgDegToRad(deg); }

float VGFrameBuffer::RadToDeg(float rad) { return nvgRadToDeg(rad); }

int VGFrameBuffer::CreateImage(const char* filename, int imageFlags)
{
    if (CurrenVGFrameBuffer_ == this)
        return nanoVG_->CreateImage(filename, imageFlags);
    else
        return -1;
}

int VGFrameBuffer::CreateImageMem(int imageFlags, unsigned char* data, int ndata)
{
    if (CurrenVGFrameBuffer_ == this)
        return nanoVG_->CreateImageMem(imageFlags, data, ndata);
    else
        return -1;
}

int VGFrameBuffer::CreateImageRGBA(int w, int h, int imageFlags, const unsigned char* data)
{
    if (CurrenVGFrameBuffer_ == this)
        return nanoVG_->CreateImageRGBA(w, h, imageFlags, data);
    else
        return -1;
}

void VGFrameBuffer::UpdateImage(int image, const unsigned char* data)
{
    if (CurrenVGFrameBuffer_ == this)
        nanoVG_->UpdateImage(image, data);
}

void VGFrameBuffer::ImageSize(int image, int* w, int* h)
{
    if (CurrenVGFrameBuffer_ == this)
        nanoVG_->ImageSize(image, w, h);
}

void VGFrameBuffer::DeleteImage(int image)
{
    if (CurrenVGFrameBuffer_ == this)
        nanoVG_->DeleteImage(image);
}

NVGpaint VGFrameBuffer::LinearGradient(float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol)
{
    return nvgLinearGradient(vg_, sx, sy, ex, ey, icol, ocol);
}

NVGpaint VGFrameBuffer::BoxGradient(float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol)
{
    return nvgBoxGradient(vg_, x, y, w, h, r, f, icol, ocol);
}

NVGpaint VGFrameBuffer::RadialGradient(float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol)
{
    return nvgRadialGradient(vg_, cx, cy, inr, outr, icol, ocol);
}

NVGpaint VGFrameBuffer::ImagePattern(float ox, float oy, float ex, float ey, float angle, int image, float alpha)
{
    return nvgImagePattern(vg_, ox, oy, ex, ey, angle, image, alpha);
}

void VGFrameBuffer::Scissor(float x, float y, float w, float h)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgScissor(vg_, x, y, w, h);
}

void VGFrameBuffer::IntersectScissor(float x, float y, float w, float h)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgIntersectScissor(vg_, x, y, w, h);
}

void VGFrameBuffer::ResetScissor()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgResetScissor(vg_);
}

void VGFrameBuffer::BeginPath()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgBeginPath(vg_);
}

void VGFrameBuffer::MoveTo(float x, float y)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgMoveTo(vg_, x, y);
}

void VGFrameBuffer::LineTo(float x, float y)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgLineTo(vg_, x, y);
}

void VGFrameBuffer::BezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgBezierTo(vg_, c1x, c1y, c2x, c2y, x, y);
}

void VGFrameBuffer::QuadTo(float cx, float cy, float x, float y)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgQuadTo(vg_, cx, cy, x, y);
}

void VGFrameBuffer::ArcTo(float x1, float y1, float x2, float y2, float radius)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgArcTo(vg_, x1, y1, x2, y2, radius);
}

void VGFrameBuffer::ClosePath()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgClosePath(vg_);
}

void VGFrameBuffer::PathWinding(int dir)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgPathWinding(vg_, dir);
}

void VGFrameBuffer::Arc(float cx, float cy, float r, float a0, float a1, int dir)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgArc(vg_, cx, cy, r, a0, a1, dir);
}

void VGFrameBuffer::Rect(float x, float y, float w, float h)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgRect(vg_, x, y, w, h);
}

void VGFrameBuffer::RoundedRect(float x, float y, float w, float h, float r)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgRoundedRect(vg_, x, y, w, h, r);
}

void VGFrameBuffer::RoundedRectVarying(float x, float y, float w, float h, float radTopLeft, float radTopRight,
                                       float radBottomRight, float radBottomLeft)
{
    if (CurrenVGFrameBuffer_ == this)
    nvgRoundedRectVarying(vg_, x, y, w, h, radTopLeft, radTopRight, radBottomRight, radBottomLeft);
}

void VGFrameBuffer::Ellipse(float cx, float cy, float rx, float ry)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgEllipse(vg_, cx, cy, rx, ry);
}

void VGFrameBuffer::Circle(float cx, float cy, float r)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgCircle(vg_, cx, cy, r);
}

void VGFrameBuffer::Fill()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFill(vg_);
}

void VGFrameBuffer::Stroke()
{
    if (CurrenVGFrameBuffer_ == this)
        nvgStroke(vg_);
}

int VGFrameBuffer::CreateFont(const char* name, const char* filename) { return nanoVG_->CreateFont(name, filename); }

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VGFrameBuffer::CreateFontAtIndex(const char* name, const char* filename, const int fontIndex)
{
    return nanoVG_->CreateFontAtIndex(name, filename, fontIndex);
}

// Creates font by loading it from the specified memory chunk.
// Returns handle to the font.
int VGFrameBuffer::CreateFontMem(const char* name, unsigned char* data, int ndata)
{
    return nanoVG_->CreateFontMem(name, data, ndata);
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VGFrameBuffer::CreateFontMemAtIndex(const char* name, unsigned char* data, int ndata, const int fontIndex)
{
    return nanoVG_->CreateFontMemAtIndex(name, data, ndata, fontIndex);
}

// Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
int VGFrameBuffer::FindFont(const char* name) { return nanoVG_->FindFont(name); }

// Adds a fallback font by handle.
int VGFrameBuffer::AddFallbackFontId(int baseFont, int fallbackFont)
{
    return nanoVG_->AddFallbackFontId(baseFont, fallbackFont);
}

// Adds a fallback font by name.
int VGFrameBuffer::AddFallbackFont(const char* baseFont, const char* fallbackFont)
{
    return nanoVG_->AddFallbackFont(baseFont, fallbackFont);
}

// Resets fallback fonts by handle.
void VGFrameBuffer::ResetFallbackFontsId(int baseFont) { nanoVG_->ResetFallbackFontsId(baseFont); }

// Resets fallback fonts by name.
void VGFrameBuffer::ResetFallbackFonts(const char* baseFont) { nanoVG_->ResetFallbackFonts(baseFont); }

// Sets the font size of current text style.
void VGFrameBuffer::FontSize(float size)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFontSize(vg_, size);
}

// Sets the blur of current text style.
void VGFrameBuffer::FontBlur(float blur)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFontBlur(vg_, blur);
}

// Sets the letter spacing of current text style.
void VGFrameBuffer::TextLetterSpacing(float spacing)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTextLetterSpacing(vg_, spacing);
}

// Sets the proportional line height of current text style. The line height is specified as multiple of font size.
void VGFrameBuffer::TextLineHeight(float lineHeight)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTextLineHeight(vg_, lineHeight);
}

// Sets the text align of current text style, see NVGalign for options.
void VGFrameBuffer::TextAlign(int align)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTextAlign(vg_, align);
}

// Sets the font face based on specified id of current text style.
void VGFrameBuffer::FontFaceId(int font)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFontFaceId(vg_, font);
}

// Sets the font face based on specified name of current text style.
void VGFrameBuffer::FontFace(const char* font)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgFontFace(vg_, font);
}

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float VGFrameBuffer::Text(float x, float y, const char* string, const char* end)
{
    if (CurrenVGFrameBuffer_ == this)
        return nvgText(vg_, x, y, string, end);
    else
        return 0.0f;
}

// Draws multi-line text string at specified location wrapped at the specified width. If end is specified only the
// sub-string up to the end is drawn. White space is stripped at the beginning of the rows, the text is split at
// word boundaries or when new-line characters are encountered. Words longer than the max width are slit at nearest
// character (i.e. no hyphenation).
void VGFrameBuffer::TextBox(float x, float y, float breakRowWidth, const char* string, const char* end)
{
    if (CurrenVGFrameBuffer_ == this)
    nvgTextBox(vg_, x, y, breakRowWidth, string, end);
}

// Measures the specified text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Returns the horizontal advance of the measured text (i.e. where the next character should drawn).
// Measured values are returned in local coordinate space.
float VGFrameBuffer::TextBounds(float x, float y, const char* string, const char* end, float* bounds)
{
    if (CurrenVGFrameBuffer_ == this)
        return nvgTextBounds(vg_, x, y, string, end, bounds);
    else
        return 0.0f;
}

// Measures the specified multi-text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Measured values are returned in local coordinate space.
void VGFrameBuffer::TextBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end,
                                  float* bounds)
{
    if (CurrenVGFrameBuffer_ == this)
    nvgTextBoxBounds(vg_, x, y, breakRowWidth, string, end, bounds);
}

// Calculates the glyph x positions of the specified text. If end is specified only the sub-string will be used.
// Measured values are returned in local coordinate space.
int VGFrameBuffer::TextGlyphPositions(float x, float y, const char* string, const char* end,
                                      NVGglyphPosition* positions, int maxPositions)
{
    return nvgTextGlyphPositions(vg_, x, y, string, end, positions, maxPositions);
}

// Returns the vertical metrics based on the current text style.
// Measured values are returned in local coordinate space.
void VGFrameBuffer::TextMetrics(float* ascender, float* descender, float* lineh)
{
    if (CurrenVGFrameBuffer_ == this)
    nvgTextMetrics(vg_, ascender, descender, lineh);
}

// Breaks the specified text into lines. If end is specified only the sub-string will be used.
// White space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line
// characters are encountered. Words longer than the max width are slit at nearest character (i.e. no hyphenation).
int VGFrameBuffer::TextBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows,
                                  int maxRows)
{
    if (CurrenVGFrameBuffer_ == this)
        return nvgTextBreakLines(vg_, string, end, breakRowWidth, rows, maxRows);
    else
        return -1;
}

// Sets the font face based on specified name of current text style.
 void VGFrameBuffer::FontFace( const String& font)
 {
     if (CurrenVGFrameBuffer_ == this)
         nvgFontFace(vg_, font.CString());
 }

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float VGFrameBuffer::Text( float x, float y, const String& string)
{
    if (CurrenVGFrameBuffer_ == this)
        return nvgText(vg_, x, y, string.CString(), nullptr);
    else
        return 0.0f;
}

void VGFrameBuffer::TextBox( float x, float y, float breakRowWidth, const String& str)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTextBox(vg_, x, y, breakRowWidth, str.CString(), nullptr);
}

float VGFrameBuffer::TextBounds( float x, float y, const String& str, float* bounds)
{
    if (CurrenVGFrameBuffer_ == this)
        return nvgTextBounds(vg_, x, y, str.CString(), nullptr, bounds);
    else
        return 0.0f;
}

void VGFrameBuffer::TextBoxBounds(float x, float y, float breakRowWidth, const String& str, float* bounds)
{
    if (CurrenVGFrameBuffer_ == this)
        nvgTextBoxBounds(vg_, x, y, breakRowWidth, str.CString(), nullptr, bounds);
}

int VGFrameBuffer::TextGlyphPositions(float x, float y, const String& str, float* positions, int maxPositions)
{
    int nglyphs = 0;
    if (CurrenVGFrameBuffer_ == this)
    {
        NVGglyphPosition* glyphs = new NVGglyphPosition[maxPositions];
        if (glyphs != nullptr)
        {
            nglyphs = TextGlyphPositions(x, y, str.CString(), nullptr, glyphs, maxPositions);
            for (int i = 0; i < nglyphs; i++)
            {
                positions[i * 4 + 0] = (float)(glyphs[i].str - str.CString());
                positions[i * 4 + 1] = glyphs[i].x;
                positions[i * 4 + 2] = glyphs[i].minx;
                positions[i * 4 + 3] = glyphs[i].maxx;
            }

            delete[] glyphs;
            glyphs = nullptr;
        }
    }

    return nglyphs;
}

unsigned int VGFrameBuffer::TextBreakLines(const String& str, float breakRowWidth, VGTextRowBuffer* vgTextRowBuffer)
{
    if (CurrenVGFrameBuffer_ == this)
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
                VGTextRow* vgRow = new VGTextRow(context_);
                String str(row->start, row->end - row->start);
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
    else
        return 0;
}

} // namespace Urho3D
