// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_points_gl_3_3_autogen.h:
//   Defines the GL 3.3 entry points.

#ifndef LIBGL_ENTRY_POINTS_GL_3_3_AUTOGEN_H_
#define LIBGL_ENTRY_POINTS_GL_3_3_AUTOGEN_H_

#include <export.h>
#include "angle_gl.h"

namespace gl
{
ANGLE_EXPORT void GL_APIENTRY BindFragDataLocationIndexed(GLuint program,
                                                          GLuint colorNumber,
                                                          GLuint index,
                                                          const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY BindSampler(GLuint unit, GLuint sampler);
ANGLE_EXPORT void GL_APIENTRY ColorP3ui(GLenum type, GLuint color);
ANGLE_EXPORT void GL_APIENTRY ColorP3uiv(GLenum type, const GLuint *color);
ANGLE_EXPORT void GL_APIENTRY ColorP4ui(GLenum type, GLuint color);
ANGLE_EXPORT void GL_APIENTRY ColorP4uiv(GLenum type, const GLuint *color);
ANGLE_EXPORT void GL_APIENTRY DeleteSamplers(GLsizei count, const GLuint *samplers);
ANGLE_EXPORT void GL_APIENTRY GenSamplers(GLsizei count, GLuint *samplers);
ANGLE_EXPORT GLint GL_APIENTRY GetFragDataIndex(GLuint program, const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params);
ANGLE_EXPORT void GL_APIENTRY GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params);
ANGLE_EXPORT void GL_APIENTRY GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params);
ANGLE_EXPORT void GL_APIENTRY GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params);
ANGLE_EXPORT void GL_APIENTRY GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params);
ANGLE_EXPORT void GL_APIENTRY GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params);
ANGLE_EXPORT GLboolean GL_APIENTRY IsSampler(GLuint sampler);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY NormalP3ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY NormalP3uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY QueryCounter(GLuint id, GLenum target);
ANGLE_EXPORT void GL_APIENTRY SamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param);
ANGLE_EXPORT void GL_APIENTRY SamplerParameterIuiv(GLuint sampler,
                                                   GLenum pname,
                                                   const GLuint *param);
ANGLE_EXPORT void GL_APIENTRY SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
ANGLE_EXPORT void GL_APIENTRY SamplerParameterfv(GLuint sampler,
                                                 GLenum pname,
                                                 const GLfloat *param);
ANGLE_EXPORT void GL_APIENTRY SamplerParameteri(GLuint sampler, GLenum pname, GLint param);
ANGLE_EXPORT void GL_APIENTRY SamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param);
ANGLE_EXPORT void GL_APIENTRY SecondaryColorP3ui(GLenum type, GLuint color);
ANGLE_EXPORT void GL_APIENTRY SecondaryColorP3uiv(GLenum type, const GLuint *color);
ANGLE_EXPORT void GL_APIENTRY TexCoordP1ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP1uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP2ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP2uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP3ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP3uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP4ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY TexCoordP4uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY VertexAttribDivisor(GLuint index, GLuint divisor);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP1ui(GLuint index,
                                               GLenum type,
                                               GLboolean normalized,
                                               GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP1uiv(GLuint index,
                                                GLenum type,
                                                GLboolean normalized,
                                                const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP2ui(GLuint index,
                                               GLenum type,
                                               GLboolean normalized,
                                               GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP2uiv(GLuint index,
                                                GLenum type,
                                                GLboolean normalized,
                                                const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP3ui(GLuint index,
                                               GLenum type,
                                               GLboolean normalized,
                                               GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP3uiv(GLuint index,
                                                GLenum type,
                                                GLboolean normalized,
                                                const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP4ui(GLuint index,
                                               GLenum type,
                                               GLboolean normalized,
                                               GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexAttribP4uiv(GLuint index,
                                                GLenum type,
                                                GLboolean normalized,
                                                const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY VertexP2ui(GLenum type, GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexP2uiv(GLenum type, const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY VertexP3ui(GLenum type, GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexP3uiv(GLenum type, const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY VertexP4ui(GLenum type, GLuint value);
ANGLE_EXPORT void GL_APIENTRY VertexP4uiv(GLenum type, const GLuint *value);
}  // namespace gl

#endif  // LIBGL_ENTRY_POINTS_GL_3_3_AUTOGEN_H_
