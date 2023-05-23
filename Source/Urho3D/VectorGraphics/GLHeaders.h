#pragma once

#if defined(URHO3D_ANGLE_METAL)
#if URHO3D_GLES3
#include <angle/GLES2/gl2ext.h>
#include <angle/GLES3/gl3.h>
#else
#include <angle/GLES2/gl2.h>
#include <angle/GLES2/gl2ext.h>
#endif
#elif defined(IOS) || defined(TVOS)
#if URHO3D_GLES3
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#else
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#ifndef URHO3D_GLES2
#define URHO3D_GLES2
#endif
#endif
#elif defined(__ANDROID__) || defined(__arm__) || (defined(__aarch64__) && !defined(APPLE_SILICON)) ||                 \
    defined(__EMSCRIPTEN__)
#if URHO3D_GLES3
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#ifndef URHO3D_GLES2
#define URHO3D_GLES2
#endif
#endif
#else
#include <GLEW/glew.h>
#endif
