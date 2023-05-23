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
#pragma once

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#endif
#include "../ThirdParty/nanovg/nanovg.h"
#include "../Core/Object.h"
#include "../Graphics/Texture2D.h"
#include "VGCanvas.h"
#include "VGEvents.h"
#include "VGFrameBuffer.h"
#include "VGElement.h"
#include "VGComponent.h"

#include "GLHeaders.h"


struct NVGcontext;
struct NVGLUframebuffer;

#if defined(_WINDOWS)
#undef RGB
#undef CreateFont
#undef CreateFontA
#endif

namespace Urho3D
{
	class Graphics;
	class VertexBuffer;
	class Cursor;
	class ResourceCache;
	class Timer;
	class UIBatch;
	class UIElement;
	class XMLElement;
	class XMLFile;


    typedef struct VGImageData
    {
        
        int ref_count;
        int image_id;
        String image_name;
        
        VGImageData()
        {
            ref_count = 0;
            image_id = 0;
            image_name = "";
        }
        
        VGImageData(int id,String name)
        {
            ref_count = 1;
            image_id = id;
            image_name = name;
        }
        
    }VGImageData;

class URHO3D_API VectorGraphics : public Object
    {
    URHO3D_OBJECT(VectorGraphics, Object);

public:
	VectorGraphics(Context* context);
	virtual ~VectorGraphics();
	/// Initialize when screen mode initially set.
	void Initialize();
	void Clear();
	NVGcontext * GetNVGContext() { return vg_; }

    VGFrameBuffer* GetCurrentFrameBuffer();
	//
    // Text
    //
    // VectorGraphics allows you to load .ttf files and use the font to render text.
    //
    // The appearance of the text can be defined by setting the current text style
    // and by specifying the fill color. Common text and font settings such as
    // font size, letter spacing and text align are supported. Font blur allows you
    // to create simple text effects such as drop shadows.
    //
    // At render time the font face can be set based on the font handles or name.
    //
    // Font measure functions return values in local space, the calculations are
    // carried in the same resolution as the final rendering. This is done because
    // the text glyph positions are snapped to the nearest pixels sharp rendering.
    //
    // The local space means that values are not rotated or scale as per the current
    // transformation. For example if you set font size to 12, which would mean that
    // line height is 16, then regardless of the current scaling and rotation, the
    // returned line height is always 16. Some measures may vary because of the scaling
    // since aforementioned pixel snapping.
    //
    // While this may sound a little odd, the setup allows you to always render the
    // same way regardless of scaling. I.e. following works regardless of scaling:
    //
    //		const char* txt = "Text me up.";
    //		nvgTextBounds(vg, x,y, txt, NULL, bounds);
    //		nvgBeginPath(vg);
    //		nvgRoundedRect(vg, bounds[0],bounds[1], bounds[2]-bounds[0], bounds[3]-bounds[1]);
    //		nvgFill(vg);
    //
    // Note: currently only solid color fill is supported for text.

    // Creates font by loading it from the disk from specified file name.
    // Returns handle to the font.
    int CreateFont(const char* name, const char* filename);

    // fontIndex specifies which font face to load from a .ttf/.ttc file.
    int CreateFontAtIndex(const char* name, const char* filename, const int fontIndex);

    // Creates font by loading it from the specified memory chunk.
    // Returns handle to the font.
    int CreateFontMem(const char* name, unsigned char* data, int ndata);

    // fontIndex specifies which font face to load from a .ttf/.ttc file.
    int CreateFontMemAtIndex(const char* name, unsigned char* data, int ndata, const int fontIndex);

    // Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
    int FindFont(const char* name);
        
    // Creates font by loading it from the disk from specified file name.
    // Returns handle to the font.
    int CreateFont(const String&  name, const String&  filename);

    // fontIndex specifies which font face to load from a .ttf/.ttc file.
    int CreateFontAtIndex(const String&  name, const String&  filename, const int fontIndex);
        
    // Creates font by loading it from the specified memory chunk.
        // Returns handle to the font.
    int CreateFontMem(const String&  name, unsigned char*  data, int ndata);

    // fontIndex specifies which font face to load from a .ttf/.ttc file.
    int CreateFontMemAtIndex(const String&  name, unsigned char* data, int ndata, const int fontIndex);

    // Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
    int FindFont(const String&  name);
            


    // Adds a fallback font by handle.
    int AddFallbackFontId(int baseFont, int fallbackFont);

    // Adds a fallback font by name.
    int AddFallbackFont(const char* baseFont, const char* fallbackFont);

    // Resets fallback fonts by handle.
    void ResetFallbackFontsId(int baseFont);

    // Resets fallback fonts by name.
    void ResetFallbackFonts(const char* baseFont);
        
    // Adds a fallback font by name.
    int AddFallbackFont(const String&  baseFont, const String&  fallbackFont);
    // Resets fallback fonts by name.
    void ResetFallbackFonts(const String&  baseFont);


	//
    // Images
    //
    // VectorGraphics allows you to load jpg, png, psd, tga, pic and gif files to be used for rendering.
    // In addition you can upload your own image. The image loading is provided by stb_image.
    // The parameter imageFlags is combination of flags defined in NVGimageFlags.

    // Creates image by loading it from the disk from specified file name.
    // Returns handle to the image.
    int CreateImage(const char* filename, int imageFlags);
        
    // Creates image by loading it from the disk from specified file name.
    // Returns handle to the image.
    int CreateImage(const String& filename, int imageFlags);

    // Creates image by loading it from the specified chunk of memory.
    // Returns handle to the image.
    int CreateImageMem(int imageFlags, unsigned char* data, int ndata);
        
    int LoadSVGImage(const String& filename,float width,float height, int imageFlags);
        
    float GetSVGHeight(const String& filename);
    float GetSVGWidth(const String& filename);
    void GetSVGSize(const String& filename , float * height, float * width);
    // Creates image from specified image data.
    // Returns handle to the image.
    int CreateImageRGBA(int w, int h, int imageFlags, const unsigned char* data);

    // Updates image data specified by image handle.
    void UpdateImage(int image, const unsigned char* data);

    // Returns the dimensions of a created image.
    void ImageSize(int image, int* w, int* h);

    // Deletes created image.
    void DeleteImage(int image);

    SharedPtr<Texture2D> LoadSVGIntoTexture(const String& path);

protected:

	/// Initialized flag.
	bool initialized_;
	/// Graphics subsystem.
	WeakPtr<Graphics> graphics_;

	/// nanovg context
	NVGcontext* vg_;

private:
    HashMap<String, int> imagesMap_;
    HashMap<int,VGImageData> imagesIDMap_;

    HashMap<String, int> fontsMap_;
    HashMap<int, String> fontsIDMap_;
};
}

