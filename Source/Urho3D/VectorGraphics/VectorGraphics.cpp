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

#include "VectorGraphics.h"
#include "../Core/Context.h"
#include "../IO/Log.h"
#include "../IO/File.h"
#include "../IO/FileSystem.h"
#include "../Resource/ResourceCache.h"
#include "../Graphics/Texture2D.h"

#include "VGCanvas.h"
#include "VGEvents.h"
#include "VGFrameBuffer.h"
#include "VGElement.h"
#include "VGComponent.h"

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#endif
#include "nanovg.h"
#include "nanovg_gl.h"
#include "nanovg_gl_utils.h"

#define NANOSVG_ALL_COLOR_KEYWORDS // Include full list of color keywords.
#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"
#define NANOSVGRAST_IMPLEMENTATION
#include "nanosvgrast.h"

namespace Urho3D
{



VectorGraphics::VectorGraphics(Context* context)
    : Object(context)
    , initialized_(false)
    , vg_(NULL)
{
    imagesMap_.Clear();
    imagesIDMap_.Clear();
    fontsMap_.Clear();
    fontsIDMap_.Clear();

    VGElement::RegisterObject(context_);
    VGCanvas::RegisterObject(context_);
    VGFrameBuffer::RegisterObject(context_);
    VGComponent::RegisterObject(context_);
}

VectorGraphics::~VectorGraphics() { Clear(); }

void VectorGraphics::Initialize()
{
    Graphics* graphics = GetSubsystem<Graphics>();

    if (!graphics || !graphics->IsInitialized())
        return;

    //	OpenConsoleWindow();
    graphics_ = graphics;

    initialized_ = true;

// NVG_DEBUG
#if defined(NANOVG_GL3_IMPLEMENTATION)
    vg_ = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
#else
    vg_ = nvgCreateGLES2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
#endif

    if (vg_ == NULL)
        URHO3D_LOGERROR("Could not init nanovg.");
    else
        URHO3D_LOGINFO("Initialized VectorGraphics subsystem");
}

void VectorGraphics::Clear()
{
    if (vg_)
    {

        for (HashMap<int, VGImageData>::ConstIterator i = imagesIDMap_.Begin(); i != imagesIDMap_.End(); ++i)
        {
            nvgDeleteImage(vg_, i->first_);
        }

        imagesMap_.Clear();
        imagesIDMap_.Clear();

#if defined(NANOVG_GL3_IMPLEMENTATION)
        nvgDeleteGL3(vg_);
#else
        nvgDeleteGLES2(vg_);
#endif
        vg_ = nullptr;


     
    }
}

VGFrameBuffer* VectorGraphics::GetCurrentFrameBuffer() 
{ 
    return VGFrameBuffer::Current(); 
}


int VectorGraphics::CreateFont(const char* name, const char* filename)
{

    int index = FindFont(name);
    if (index >= 0)
        return index;

    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();
    Urho3D::SharedPtr<Urho3D::File> fontFile = resourceCache->GetFile(filename);
    if (fontFile != NULL)
    {

        uint8_t* buffer = (uint8_t*)malloc(fontFile->GetSize());
        auto bytesLen = fontFile->Read(buffer, fontFile->GetSize());

        return nvgCreateFontMem(vg_, name, buffer, bytesLen, 1);
    }
    else
    {
        return -1;
    }
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VectorGraphics::CreateFontAtIndex(const char* name, const char* filename, const int fontIndex)
{
    int index = FindFont(name);
    if (index >= 0)
        return index;

    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();
    Urho3D::SharedPtr<Urho3D::File> fontFile = resourceCache->GetFile(filename);
    if (fontFile != NULL)
    {
        uint8_t* buffer = (uint8_t*)malloc(fontFile->GetSize());
        auto bytesLen = fontFile->Read(buffer, fontFile->GetSize());

        return nvgCreateFontMemAtIndex(vg_, name, buffer, bytesLen, 1, fontIndex);
    }
    else
    {
        return -1;
    }
}

// Creates font by loading it from the specified memory chunk.
// Returns handle to the font.
int VectorGraphics::CreateFontMem(const char* name, unsigned char* data, int ndata)
{
    int index = FindFont(name);
    if (index >= 0)
        return index;

    return nvgCreateFontMem(vg_, name, data, ndata, 1);
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VectorGraphics::CreateFontMemAtIndex(const char* name, unsigned char* data, int ndata, const int fontIndex)
{
    int index = FindFont(name);
    if (index >= 0)
        return index;

    return nvgCreateFontMemAtIndex(vg_, name, data, ndata, 1, fontIndex);
}

// Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
int VectorGraphics::FindFont(const char* name) { return nvgFindFont(vg_, name); }


// Creates font by loading it from the disk from specified file name.
// Returns handle to the font.
int VectorGraphics::CreateFont(const String&  name, const String&  filename)
{
    return CreateFont(name.CString(), filename.CString());
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VectorGraphics::CreateFontAtIndex(const String&  name, const String&  filename, const int fontIndex)
{
    return CreateFontAtIndex(name.CString(), filename.CString(), fontIndex);
}

// Creates font by loading it from the specified memory chunk.
// Returns handle to the font.
int VectorGraphics::CreateFontMem(const String&  name, unsigned char* data, int ndata)
{
    return CreateFontMem(name.CString(),data,ndata);
}

// fontIndex specifies which font face to load from a .ttf/.ttc file.
int VectorGraphics::CreateFontMemAtIndex(const String&  name, unsigned char* data, int ndata, const int fontIndex)
{
    return CreateFontMemAtIndex(name.CString(),data,ndata,fontIndex);
}

// Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
int VectorGraphics::FindFont(const String&  name)
{
    return FindFont(name.CString());
}


// Adds a fallback font by handle.
int VectorGraphics::AddFallbackFontId(int baseFont, int fallbackFont)
{
    return nvgAddFallbackFontId(vg_, baseFont, fallbackFont);
}

// Adds a fallback font by name.
int VectorGraphics::AddFallbackFont(const char* baseFont, const char* fallbackFont)
{
    return nvgAddFallbackFont(vg_, baseFont, fallbackFont);
}

// Resets fallback fonts by handle.
void VectorGraphics::ResetFallbackFontsId(int baseFont) { nvgResetFallbackFontsId(vg_, baseFont); }

// Resets fallback fonts by name.
void VectorGraphics::ResetFallbackFonts(const char* baseFont) { nvgResetFallbackFonts(vg_, baseFont); }


// Adds a fallback font by name.
int VectorGraphics::AddFallbackFont(const String&  baseFont, const String&  fallbackFont)
{
    return AddFallbackFont(baseFont.CString(),fallbackFont.CString());
}
// Resets fallback fonts by name.
void VectorGraphics::ResetFallbackFonts(const String&  baseFont)
{
    return ResetFallbackFonts(baseFont.CString());
}

// Creates image by loading it from the disk from specified file name.
// Returns handle to the image.
int VectorGraphics::CreateImage(const String& filename, int imageFlags)
{
    return CreateImage(filename.CString(),imageFlags);
}

int VectorGraphics::CreateImage(const char* filename, int imageFlags)
{
    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();

    int imageID = -1;

    HashMap<String, int>::ConstIterator i = imagesMap_.Find(filename);
    if (i != imagesMap_.End())
    {
        imagesIDMap_[i->second_].ref_count++;
        return i->second_;
    }

    String fileExtention = GetExtension(filename);

    Urho3D::SharedPtr<Urho3D::File> imageFile = resourceCache->GetFile(filename);
    if (imageFile != NULL)
    {

        uint8_t* buffer = (uint8_t*)malloc(imageFile->GetSize() + 1);

        if (buffer != nullptr)
        {

            auto bytesLen = imageFile->Read(buffer, imageFile->GetSize());

            if (fileExtention == ".svg")
            {

                NSVGimage* image = NULL;
                NSVGrasterizer* rast = NULL;
                int w, h;
                buffer[imageFile->GetSize()] = '\0';

                rast = nsvgCreateRasterizer();
                if (rast != nullptr)
                {

                    rast->tessTol = 1.0f;
                    rast->distTol = 1.0f;

                    image = nsvgParse((char*)buffer, "px", 400.0f);
                    if (image != NULL)
                    {
                        w = image->width;
                        h = image->height;

                        unsigned char* out_buffer = (unsigned char*)malloc(w * h * 4);

                        if (out_buffer != NULL)
                        {
                            nsvgRasterize(rast, image, 0.0f, 0.0f, 1, out_buffer, w, h, w * 4);
                            imageID = nvgCreateImageRGBA(vg_, w, h, imageFlags, out_buffer);
                            imagesMap_[filename] = imageID;
                            imagesIDMap_[imageID] = VGImageData(imageID,filename);
                            free(out_buffer);
                        }
                        nsvgDelete(image);
                    }
                    nsvgDeleteRasterizer(rast);
                }
            }
            else
            {

                imageID = nvgCreateImageMem(vg_, imageFlags, buffer, bytesLen);
                imagesMap_[filename] = imageID;
                imagesIDMap_[imageID] = VGImageData(imageID,filename);
            }

            free(buffer);
            return imageID;
        }
    }
    else
    {
        return -1;
    }

    return -1;
}

int VectorGraphics::LoadSVGImage(const String& filename ,float width,float height, int imageFlags)
{
    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();

    int imageID = -1;
    
    String dbFileName = filename + String(width) + String(height) + String(imageFlags);
    
    HashMap<String, int>::ConstIterator i = imagesMap_.Find(dbFileName);
    if (i != imagesMap_.End())
    {
        imagesIDMap_[i->second_].ref_count++;
        return i->second_;
    }

    String fileExtention = GetExtension(filename);

    Urho3D::SharedPtr<Urho3D::File> imageFile = resourceCache->GetFile(filename);
    if (fileExtention == ".svg" && imageFile != NULL)
    {

        uint8_t* buffer = (uint8_t*)malloc(imageFile->GetSize() + 1);

        if (buffer != nullptr)
        {

            auto bytesLen = imageFile->Read(buffer, imageFile->GetSize());

            NSVGimage* image = NULL;
            NSVGrasterizer* rast = NULL;
            int w, h;
            buffer[imageFile->GetSize()] = '\0';

            rast = nsvgCreateRasterizer();
            if (rast != nullptr)
            {

                rast->tessTol = 1.0f;
                rast->distTol = 1.0f;

                image = nsvgParse((char*)buffer,"px", 400);
                if (image != NULL)
                {
                    
                    w = image->width;
                    h = image->height;
                    
                    if(width > 0)
                    {
                        w = width;
                    }
                    
                    if(height > 0 )
                    {
                        h = height;
                    }
                  
                    
                    float svgScaleHeightOnWidth = image->height /image->width;
                    float ScaleHeightOnWidth = h /(float)w;
                    float svgScale = w/image->width;
                    h = h * svgScaleHeightOnWidth / ScaleHeightOnWidth;
       
                    unsigned char* out_buffer = (unsigned char*)malloc(w * h * 4);

                    if (out_buffer != NULL)
                    {
                        nsvgRasterize(rast, image, 0, 0, svgScale, out_buffer, w, h, w * 4);
                        imageID = nvgCreateImageRGBA(vg_, w, h, imageFlags, out_buffer);
                        imagesMap_[dbFileName] = imageID;
                        imagesIDMap_[imageID] = VGImageData(imageID,dbFileName);
                        free(out_buffer);
                    }
                    nsvgDelete(image);
                }
                nsvgDeleteRasterizer(rast);
            }

            free(buffer);
            return imageID;
        }
    }
    else
    {
        return -1;
    }

    return -1;
}


float VectorGraphics::GetSVGHeight(const String& filename)
{
    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();
    String fileExtention = GetExtension(filename);
    
    float height = 0.0f;
    Urho3D::SharedPtr<Urho3D::File> imageFile = resourceCache->GetFile(filename);
    if (fileExtention == ".svg" && imageFile != NULL)
    {
        uint8_t* buffer = (uint8_t*)malloc(imageFile->GetSize() + 1);

        if (buffer != nullptr)
        {

            auto bytesLen = imageFile->Read(buffer, imageFile->GetSize());

            NSVGimage* image = NULL;
            NSVGrasterizer* rast = NULL;
            int w, h;
            buffer[imageFile->GetSize()] = '\0';

            rast = nsvgCreateRasterizer();
            if (rast != nullptr)
            {

                rast->tessTol = 1.0f;
                rast->distTol = 1.0f;

                image = nsvgParse((char*)buffer, "px", 400);
                if (image != NULL)
                {
                    height=  image->height;
                    
                    nsvgDelete(image);
                }
                nsvgDeleteRasterizer(rast);
            }
            free(buffer);
        }
    }
 
    return height;
}

float VectorGraphics::GetSVGWidth(const String& filename)
{
    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();
    String fileExtention = GetExtension(filename);
    
    float width = 0.0f;
    Urho3D::SharedPtr<Urho3D::File> imageFile = resourceCache->GetFile(filename);
    if (fileExtention == ".svg" && imageFile != NULL)
    {
        uint8_t* buffer = (uint8_t*)malloc(imageFile->GetSize() + 1);

        if (buffer != nullptr)
        {

            auto bytesLen = imageFile->Read(buffer, imageFile->GetSize());

            NSVGimage* image = NULL;
            NSVGrasterizer* rast = NULL;
            int w, h;
            buffer[imageFile->GetSize()] = '\0';

            rast = nsvgCreateRasterizer();
            if (rast != nullptr)
            {

                rast->tessTol = 1.0f;
                rast->distTol = 1.0f;

                image = nsvgParse((char*)buffer, "px", 400);
                if (image != NULL)
                {
                    width=  image->width;
                    
                    nsvgDelete(image);
                }
                nsvgDeleteRasterizer(rast);
            }
            free(buffer);
        }
    }
 
    return width;
}

void VectorGraphics::GetSVGSize(const String& filename , float * height, float * width)
{
    ResourceCache* resourceCache = GetSubsystem<ResourceCache>();
    String fileExtention = GetExtension(filename);
    
    Urho3D::SharedPtr<Urho3D::File> imageFile = resourceCache->GetFile(filename);
    if (fileExtention == ".svg" && imageFile != NULL)
    {
        uint8_t* buffer = (uint8_t*)malloc(imageFile->GetSize() + 1);

        if (buffer != nullptr)
        {

            auto bytesLen = imageFile->Read(buffer, imageFile->GetSize());

            NSVGimage* image = NULL;
            NSVGrasterizer* rast = NULL;
            int w, h;
            buffer[imageFile->GetSize()] = '\0';

            rast = nsvgCreateRasterizer();
            if (rast != nullptr)
            {

                rast->tessTol = 1.0f;
                rast->distTol = 1.0f;

                image = nsvgParse((char*)buffer, "px", 400);
                if (image != NULL)
                {
                    if(width != nullptr)
                        *width=  image->width;
                    if(height != nullptr)
                        *height = image->height;
                    nsvgDelete(image);
                }
                nsvgDeleteRasterizer(rast);
            }
            free(buffer);
        }
    }
}


int VectorGraphics::CreateImageMem(int imageFlags, unsigned char* data, int ndata)
{
    int id =  nvgCreateImageMem(vg_, imageFlags, data, ndata);
    imagesIDMap_[id] = VGImageData(id,"__dummyImageName__");
    return id;
}

int VectorGraphics::CreateImageRGBA(int w, int h, int imageFlags, const unsigned char* data)
{
    int id = nvgCreateImageRGBA(vg_, w, h, imageFlags, data);
    imagesIDMap_[id] = VGImageData(id,"__dummyImageName__");
    return id;
}

void VectorGraphics::UpdateImage(int image, const unsigned char* data) { nvgUpdateImage(vg_, image, data); }

void VectorGraphics::ImageSize(int image, int* w, int* h) { nvgImageSize(vg_, image, w, h); }

void VectorGraphics::DeleteImage(int image) 
{ 
    

    HashMap<int, VGImageData>::Iterator i = imagesIDMap_.Find(image);
    if (i != imagesIDMap_.End())
    {
        VGImageData imageData =  i->second_;
        imageData.ref_count --;
        imagesIDMap_[image] = imageData;
        
        if(imageData.ref_count <=0)
        {
            String name = imageData.image_name;
            imagesIDMap_.Erase(i);
            nvgDeleteImage(vg_, image); 
            if (name != "__dummyImageName__")
            {
                imagesMap_.Erase(name);
            }
        }
    }
}

SharedPtr<Texture2D> VectorGraphics::LoadSVGIntoTexture(const String& path)
{

    auto* cache = GetSubsystem<ResourceCache>();
    NSVGimage* image = NULL;
    NSVGrasterizer* rast = NULL;
    int w, h;
    // LOGINFOF("parsing %s\n", svgfile.CString());

    Urho3D::SharedPtr<Urho3D::File> imageFile = cache->GetFile(path);
    char* buffer = (char*)malloc(imageFile->GetSize() + 1);
    auto bytesLen = imageFile->Read(buffer, imageFile->GetSize());
    buffer[imageFile->GetSize()] = '\0';

    image = nsvgParse(buffer, "px", 256.0f);

    if (image == NULL)
    {
        // LOGERROR("Could not open SVG image.\n");
    }

    w = NextPowerOfTwo(image->width);
    h = NextPowerOfTwo(image->height);

    rast = nsvgCreateRasterizer();
    if (rast == NULL)
    {
        // LOGERROR("Could not init rasterizer.\n");
    }

    rast->tessTol = 1.0f;
    rast->distTol = 1.0f;

    SharedPtr<Image> temp_image(new Image(context_));
    temp_image->SetSize(w, h, 4);

    unsigned char* out_buffer = temp_image->GetData();
    nsvgRasterize(rast, image, 0.0f, 0.0f, 1, out_buffer, w, h, w * 4);

    nsvgDeleteRasterizer(rast);
    nsvgDelete(image);
    free(buffer);

    SharedPtr<Texture2D> urho3DTexture(new Texture2D(context_));

    urho3DTexture->SetData(temp_image);
    temp_image.Reset();

    return urho3DTexture;
}

} // namespace Urho3D
