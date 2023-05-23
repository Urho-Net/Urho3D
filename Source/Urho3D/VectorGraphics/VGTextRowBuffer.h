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
#include "../ThirdParty/nanovg/nanovg.h"
#include "GLHeaders.h"
#include "VectorGraphics.h"
#include <vector>

struct NVGcontext;
struct NVGLUframebuffer;

namespace Urho3D
{

class URHO3D_API VGTextRow : public Object
{
    URHO3D_OBJECT(VGTextRow, Object);

public:
    explicit VGTextRow(Context* context)
        : Object(context)
    {
    }

    explicit VGTextRow(Context* context, const String& txt, float width_, float min_, float max_)
        : Object(context)
    {
        text = txt;
        width = width_;
        minx = min_;
        maxx = max_;
    }

    /// Destruct.
    ~VGTextRow() {}

    const String& GetText() { return text; }

    void SetText(const String& str) { text = str; }

    float GetWidth() { return width; }

    void SetWidth(float w) { width = w; }

    float GetMin() { return minx; }

    void SetMin(float m) { minx = m; }

    float GetMax() { return maxx; }

    void SetMax(float m) { maxx = m; }

private:
    String text;      // Pointer to the input text where the row starts.
    float width;      // Logical width of the row.
    float minx, maxx; // Actual bounds of the row. Logical with and bounds can differ because of kerning and some parts
                      // over extending.
};

class URHO3D_API VGTextRowBuffer : public Object
{
    URHO3D_OBJECT(VGTextRowBuffer, Object);

public:
    explicit VGTextRowBuffer(Context* context)
        : Object(context)
    {
    }

    /// Destruct.
    ~VGTextRowBuffer()
    {
        for (VGTextRow* row : textRows_)
        {
            delete row;
        }

        textRows_.clear();
    }

    void Clear()
    {
        for (VGTextRow* row : textRows_)
        {
            delete row;
        }

        textRows_.clear();
    }

    void AddRow(VGTextRow* row) { textRows_.push_back(row); }

    unsigned int GetSize() { return textRows_.size(); }

    // data should be allocated on the calling side
    const String& GetRowData(int index, float* data)
    {
        if (index < textRows_.size())
        {
            data[0] = textRows_[index]->GetWidth();
            data[1] = textRows_[index]->GetMin();
            data[2] = textRows_[index]->GetMax();
            return textRows_[index]->GetText();
        }
        else
        {
            return String::EMPTY;
        }
    }

    const String& GetRowText(int index)
    {
        if (index < textRows_.size())
        {
            return textRows_[index]->GetText();
        }
        else
        {
            return String::EMPTY;
        }
    }

    float GetRowMin(int index)
    {
        if (index < textRows_.size())
        {
            return textRows_[index]->GetMin();
        }
        else
        {
            return 0.0f;
        }
    }

    float GetRowMax(int index)
    {
        if (index < textRows_.size())
        {
            return textRows_[index]->GetMax();
        }
        else
        {
            return 0.0f;
        }
    }

    float GetRowWidth(int index)
    {
        if (index < textRows_.size())
        {
            return textRows_[index]->GetWidth();
        }
        else
        {
            return 0.0f;
        }
    }

    std::vector<VGTextRow*> textRows_;
};


}
