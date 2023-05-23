//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// SurfaceMtl.h: Defines the class interface for Metal Surface.

#ifndef LIBANGLE_RENDERER_METAL_SURFACEMTL_H_
#define LIBANGLE_RENDERER_METAL_SURFACEMTL_H_

#import <Metal/Metal.h>
#import <QuartzCore/CALayer.h>
#import <QuartzCore/CAMetalLayer.h>

#include "libANGLE/renderer/FramebufferImpl.h"
#include "libANGLE/renderer/SurfaceImpl.h"
#include "libANGLE/renderer/metal/RenderTargetMtl.h"
#include "libANGLE/renderer/metal/mtl_format_utils.h"
#include "libANGLE/renderer/metal/mtl_resources.h"
#include "libANGLE/renderer/metal/mtl_state_cache.h"

namespace rx
{

class DisplayMtl;

class SurfaceMtl : public SurfaceImpl
{
  public:
    SurfaceMtl(DisplayMtl *display,
               const egl::SurfaceState &state,
               EGLNativeWindowType window,
               const egl::AttributeMap &attribs);
    ~SurfaceMtl() override;

    void destroy(const egl::Display *display) override;

    egl::Error initialize(const egl::Display *display) override;
    FramebufferImpl *createDefaultFramebuffer(const gl::Context *context,
                                              const gl::FramebufferState &state) override;

    egl::Error makeCurrent(const gl::Context *context) override;
    egl::Error unMakeCurrent(const gl::Context *context) override;
    egl::Error swap(const gl::Context *context) override;
    egl::Error postSubBuffer(const gl::Context *context,
                             EGLint x,
                             EGLint y,
                             EGLint width,
                             EGLint height) override;

    egl::Error querySurfacePointerANGLE(EGLint attribute, void **value) override;
    egl::Error bindTexImage(const gl::Context *context,
                            gl::Texture *texture,
                            EGLint buffer) override;
    egl::Error releaseTexImage(const gl::Context *context, EGLint buffer) override;
    egl::Error getSyncValues(EGLuint64KHR *ust, EGLuint64KHR *msc, EGLuint64KHR *sbc) override;
    void setSwapInterval(EGLint interval) override;
    void setSwapBehavior(EGLint behavior) override;
    void setFixedWidth(EGLint width) override;
    void setFixedHeight(EGLint height) override;

    // width and height can change with client window resizing
    EGLint getWidth() const override;
    EGLint getHeight() const override;

    EGLint isPostSubBufferSupported() const override;
    EGLint getSwapBehavior() const override;

    int getSamples() const { return mSamples; }
    bool preserveBuffer() const { return mRetainBuffer; }

    angle::Result getAttachmentRenderTarget(const gl::Context *context,
                                            GLenum binding,
                                            const gl::ImageIndex &imageIndex,
                                            GLsizei samples,
                                            FramebufferAttachmentRenderTarget **rtOut) override;

    angle::Result ensureCurrentDrawableObtained(const gl::Context *context);

  private:
    angle::Result swapImpl(const gl::Context *context);
    angle::Result obtainNextDrawable(const gl::Context *context);
    angle::Result ensureTexturesSizeCorrect(const gl::Context *context);

    CGSize calcExpectedDrawableSize() const;
    // Check if metal layer has been resized.
    bool checkIfLayerResized(const gl::Context *context);

    angle::Result copyOldContents(const gl::Context *context,
                                  const mtl::TextureRef &oldColorTexture,
                                  const mtl::TextureRef &oldDepthTexture,
                                  const mtl::TextureRef &oldStencilTexture);

    mtl::AutoObjCObj<CAMetalLayer> mMetalLayer = nil;
    CALayer *mLayer;
    mtl::AutoObjCPtr<id<CAMetalDrawable>> mCurrentDrawable = nil;

    // Cache last known drawable size that is used by GL context. Can be used to detect resize
    // event. We don't use mMetalLayer.drawableSize directly since it might be changed internally by
    // metal runtime.
    CGSize mCurrentKnownDrawableSize;

    // Normal textures
    mtl::TextureRef mDrawableTexture;
    mtl::TextureRef mDepthTexture;
    mtl::TextureRef mStencilTexture;

    // Implicit multisample texture
    mtl::TextureRef mMSColorTexture;

    // Texture for preserving content of color buffer.
    mtl::TextureRef mRetainedColorTexture;

    bool mUsePackedDepthStencil     = false;
    bool mAutoResolveMSColorTexture = false;

    mtl::Format mColorFormat;
    mtl::Format mDepthFormat;
    mtl::Format mStencilFormat;

    int mSamples       = 0;
    bool mRetainBuffer = false;

    RenderTargetMtl mColorRenderTarget;
    RenderTargetMtl mColorManualResolveRenderTarget;
    RenderTargetMtl mDepthRenderTarget;
    RenderTargetMtl mStencilRenderTarget;
};

}  // namespace rx

#endif /* LIBANGLE_RENDERER_METAL_SURFACEMTL_H_ */
