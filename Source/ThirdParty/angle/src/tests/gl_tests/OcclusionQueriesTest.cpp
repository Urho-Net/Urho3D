//
// Copyright 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "platform/FeaturesMtl.h"
#include "test_utils/ANGLETest.h"
#include "util/EGLWindow.h"
#include "util/random_utils.h"
#include "util/test_utils.h"

using namespace angle;

using OcclusionQueryTestParams = std::tuple<angle::PlatformParameters, bool>;

struct PrintToStringParamName
{
    std::string operator()(const ::testing::TestParamInfo<OcclusionQueryTestParams> &info) const
    {
        ::std::stringstream ss;
        ss << (std::get<1>(info.param) ? "OverrideFeaturesOn_" : "") << std::get<0>(info.param);
        return ss.str();
    }
};

class OcclusionQueriesTest : public ANGLETestWithParam<OcclusionQueryTestParams>
{
  protected:
    OcclusionQueriesTest() : mProgram(0), mRNG(1)
    {
        setWindowWidth(128);
        setWindowHeight(128);
        setConfigRedBits(8);
        setConfigGreenBits(8);
        setConfigBlueBits(8);
        setConfigAlphaBits(8);
        setConfigDepthBits(24);
    }

    void testSetUp() override
    {
        mProgram = CompileProgram(essl1_shaders::vs::Simple(), essl1_shaders::fs::Red());
        ASSERT_NE(0u, mProgram);
    }

    void testTearDown() override { glDeleteProgram(mProgram); }

    void overrideFeaturesMetal(FeaturesMtl *features) override
    {
        if (::testing::get<1>(GetParam()))
        {
            features->overrideFeatures({"allow_buffer_read_write"}, false);
        }
    }

    GLuint mProgram;
    RNG mRNG;
};

TEST_P(OcclusionQueriesTest, IsOccluded)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 &&
                       !IsGLExtensionEnabled("GL_EXT_occlusion_query_boolean"));

    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // draw a quad at depth 0.3
    glEnable(GL_DEPTH_TEST);
    glUseProgram(mProgram);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.3f);
    glUseProgram(0);

    EXPECT_GL_NO_ERROR();

    GLuint query = 0;
    glGenQueriesEXT(1, &query);
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(),
             0.8f);  // this quad should be occluded by first quad
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    EXPECT_GL_NO_ERROR();

    swapBuffers();

    GLuint ready = GL_FALSE;
    while (ready == GL_FALSE)
    {
        angle::Sleep(0);
        glGetQueryObjectuivEXT(query, GL_QUERY_RESULT_AVAILABLE_EXT, &ready);
    }

    GLuint result = GL_TRUE;
    glGetQueryObjectuivEXT(query, GL_QUERY_RESULT_EXT, &result);

    EXPECT_GL_NO_ERROR();

    glDeleteQueriesEXT(1, &query);

    EXPECT_GL_FALSE(result);
}

TEST_P(OcclusionQueriesTest, IsNotOccluded)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 &&
                       !IsGLExtensionEnabled("GL_EXT_occlusion_query_boolean"));

    // TODO(syoussefi): Using render pass ops to clear the framebuffer attachment results in
    // AMD/Windows misbehaving in this test.  http://anglebug.com/3286
    ANGLE_SKIP_TEST_IF(IsWindows() && IsAMD() && IsVulkan());

    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    EXPECT_GL_NO_ERROR();

    GLuint query = 0;
    glGenQueriesEXT(1, &query);
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f);  // this quad should not be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    EXPECT_GL_NO_ERROR();

    swapBuffers();

    GLuint result = GL_TRUE;
    glGetQueryObjectuivEXT(query, GL_QUERY_RESULT_EXT, &result);  // will block waiting for result

    EXPECT_GL_NO_ERROR();

    glDeleteQueriesEXT(1, &query);

    EXPECT_GL_TRUE(result);
}

TEST_P(OcclusionQueriesTest, ClearNotCounted)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 &&
                       !IsGLExtensionEnabled("GL_EXT_occlusion_query_boolean"));

    // TODO(syoussefi): Using render pass ops to clear the framebuffer attachment results in
    // AMD/Windows misbehaving in this test.  http://anglebug.com/3286
    ANGLE_SKIP_TEST_IF(IsWindows() && IsAMD() && IsVulkan());

    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    EXPECT_GL_NO_ERROR();

    GLuint query[2] = {0};
    glGenQueriesEXT(2, query);

    // First query
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[0]);
    // Full screen clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // View port clear
    glViewport(0, 0, getWindowWidth() / 2, getWindowHeight());
    glScissor(0, 0, getWindowWidth() / 2, getWindowHeight());
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    EXPECT_GL_NO_ERROR();

    // Second query
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[1]);

    // View port clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // View port clear
    glViewport(0, 0, getWindowWidth() / 2, getWindowHeight());
    glScissor(0, 0, getWindowWidth() / 2, getWindowHeight());
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // this quad should not be occluded
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f, 0.5f);

    // Clear again
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // this quad should not be occluded
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f, 1.0);

    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    EXPECT_GL_NO_ERROR();

    swapBuffers();

    GLuint result[2] = {GL_TRUE, GL_TRUE};
    glGetQueryObjectuivEXT(query[0], GL_QUERY_RESULT_EXT,
                           &result[0]);  // will block waiting for result
    glGetQueryObjectuivEXT(query[1], GL_QUERY_RESULT_EXT,
                           &result[1]);  // will block waiting for result
    EXPECT_GL_NO_ERROR();

    glDeleteQueriesEXT(2, query);

    EXPECT_GL_FALSE(result[0]);
    EXPECT_GL_TRUE(result[1]);
}

TEST_P(OcclusionQueriesTest, MultiQueries)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 &&
                       !IsGLExtensionEnabled("GL_EXT_occlusion_query_boolean"));

    // TODO(syoussefi): Using render pass ops to clear the framebuffer attachment results in
    // AMD/Windows misbehaving in this test.  http://anglebug.com/3286
    ANGLE_SKIP_TEST_IF(IsWindows() && IsAMD() && IsVulkan());

    GLuint query[5] = {};
    glGenQueriesEXT(5, query);

    // First query
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[0]);

    EXPECT_GL_NO_ERROR();

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    EXPECT_GL_NO_ERROR();

    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f);  // this quad should not be occluded

    EXPECT_GL_NO_ERROR();

    // A flush shound't clear the query result
    glFlush();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), -2, 0.25f);  // this quad should be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);
    // First query ends

    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f,
             0.25f);  // this quad should not be occluded

    // Second query
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[1]);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.9f,
             0.25f);  // this quad should be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    // Third query
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[2]);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.9f,
             0.5f);  // this quad should not be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);
    // ------------
    glFlush();

    glViewport(0, 0, getWindowWidth() / 2, getWindowHeight());
    glScissor(0, 0, getWindowWidth() / 2, getWindowHeight());
    glEnable(GL_SCISSOR_TEST);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.9f,
             0.5f);  // this quad should not be occluded

    // Fourth query: begin query then end then begin again
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[3]);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.9f,
             1);  // this quad should not be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[3]);
    EXPECT_GL_NO_ERROR();
    // glClear should not be counted toward query);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    // Fifth query spans across frames
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query[4]);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f,
             0.25f);  // this quad should not be occluded

    swapBuffers();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.9f,
             0.5f);  // this quad should not be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    GLuint result = GL_TRUE;
    glGetQueryObjectuivEXT(query[0], GL_QUERY_RESULT_EXT,
                           &result);  // will block waiting for result
    EXPECT_GL_NO_ERROR();
    EXPECT_GL_TRUE(result);

    glGetQueryObjectuivEXT(query[1], GL_QUERY_RESULT_EXT,
                           &result);  // will block waiting for result
    EXPECT_GL_NO_ERROR();
    EXPECT_GL_FALSE(result);

    glGetQueryObjectuivEXT(query[2], GL_QUERY_RESULT_EXT,
                           &result);  // will block waiting for result
    EXPECT_GL_NO_ERROR();
    EXPECT_GL_TRUE(result);

    glGetQueryObjectuivEXT(query[3], GL_QUERY_RESULT_EXT,
                           &result);  // will block waiting for result
    EXPECT_GL_NO_ERROR();
    EXPECT_GL_FALSE(result);

    glGetQueryObjectuivEXT(query[4], GL_QUERY_RESULT_EXT,
                           &result);  // will block waiting for result
    EXPECT_GL_NO_ERROR();
    EXPECT_GL_TRUE(result);

    glDeleteQueriesEXT(5, query);
}

TEST_P(OcclusionQueriesTest, Errors)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 &&
                       !IsGLExtensionEnabled("GL_EXT_occlusion_query_boolean"));

    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    EXPECT_GL_NO_ERROR();

    GLuint query  = 0;
    GLuint query2 = 0;
    glGenQueriesEXT(1, &query);

    EXPECT_GL_FALSE(glIsQueryEXT(query));
    EXPECT_GL_FALSE(glIsQueryEXT(query2));

    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, 0);  // can't pass 0 as query id
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, query);
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT,
                    query2);  // can't initiate a query while one's already active
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    EXPECT_GL_TRUE(glIsQueryEXT(query));
    EXPECT_GL_FALSE(glIsQueryEXT(query2));  // have not called begin

    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.8f);  // this quad should not be occluded
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT);      // no active query for this target
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT,
                    query);  // can't begin a query as a different type than previously used
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT,
                    query2);  // have to call genqueries first
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    glGenQueriesEXT(1, &query2);
    glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT, query2);  // should be ok now
    EXPECT_GL_TRUE(glIsQueryEXT(query2));

    drawQuad(mProgram, essl1_shaders::PositionAttrib(),
             0.3f);                  // this should draw in front of other quad
    glDeleteQueriesEXT(1, &query2);  // should delete when query becomes inactive
    glEndQueryEXT(GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT);  // should not incur error; should delete
                                                            // query + 1 at end of execution.
    EXPECT_GL_NO_ERROR();

    swapBuffers();

    EXPECT_GL_NO_ERROR();

    GLuint ready = GL_FALSE;
    glGetQueryObjectuivEXT(query2, GL_QUERY_RESULT_AVAILABLE_EXT,
                           &ready);  // this query is now deleted
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    EXPECT_GL_NO_ERROR();
}

// Test that running multiple simultaneous queries from multiple EGL contexts returns the correct
// result for each query.  Helps expose bugs in ANGLE's virtual contexts.
TEST_P(OcclusionQueriesTest, MultiContext)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 &&
                       !IsGLExtensionEnabled("GL_EXT_occlusion_query_boolean"));

    // TODO(cwallez@chromium.org): Suppression for http://anglebug.com/3080
    ANGLE_SKIP_TEST_IF(IsWindows() && IsNVIDIA() && IsVulkan());

    // Test skipped because the D3D backends cannot support simultaneous queries on multiple
    // contexts yet.  Same with the Vulkan backend.
    const angle::PlatformParameters platform = ::testing::get<0>(GetParam());
    ANGLE_SKIP_TEST_IF(platform == ES2_D3D9() || platform == ES2_D3D11() ||
                       platform == ES3_D3D11() || platform == ES2_VULKAN());

    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // draw a quad at depth 0.5
    glEnable(GL_DEPTH_TEST);
    drawQuad(mProgram, essl1_shaders::PositionAttrib(), 0.5f);

    EGLWindow *window = getEGLWindow();

    EGLDisplay display = window->getDisplay();
    EGLConfig config   = window->getConfig();
    EGLSurface surface = window->getSurface();

    EGLint contextAttributes[] = {
        EGL_CONTEXT_MAJOR_VERSION_KHR,
        platform.majorVersion,
        EGL_CONTEXT_MINOR_VERSION_KHR,
        platform.minorVersion,
        EGL_NONE,
    };

    const size_t passCount = 5;
    struct ContextInfo
    {
        EGLContext context;
        GLuint program;
        GLuint query;
        bool visiblePasses[passCount];
        bool shouldPass;
    };

    ContextInfo contexts[] = {
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {false, false, false, false, false},
            false,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {false, true, false, true, false},
            true,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {false, false, false, false, false},
            false,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {true, true, false, true, true},
            true,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {false, true, true, true, true},
            true,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {true, false, false, true, false},
            true,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {false, false, false, false, false},
            false,
        },
        {
            EGL_NO_CONTEXT,
            0,
            0,
            {false, false, false, false, false},
            false,
        },
    };

    for (auto &context : contexts)
    {
        context.context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttributes);
        ASSERT_NE(context.context, EGL_NO_CONTEXT);

        eglMakeCurrent(display, surface, surface, context.context);

        context.program = CompileProgram(essl1_shaders::vs::Simple(), essl1_shaders::fs::Red());
        ASSERT_NE(context.program, 0u);

        glDepthMask(GL_FALSE);
        glEnable(GL_DEPTH_TEST);

        glGenQueriesEXT(1, &context.query);
        glBeginQueryEXT(GL_ANY_SAMPLES_PASSED_EXT, context.query);

        ASSERT_GL_NO_ERROR();
    }

    for (size_t pass = 0; pass < passCount; pass++)
    {
        for (const auto &context : contexts)
        {
            eglMakeCurrent(display, surface, surface, context.context);

            float depth = context.visiblePasses[pass] ? mRNG.randomFloatBetween(0.0f, 0.4f)
                                                      : mRNG.randomFloatBetween(0.6f, 1.0f);
            drawQuad(context.program, essl1_shaders::PositionAttrib(), depth);

            EXPECT_GL_NO_ERROR();
        }
    }

    for (const auto &context : contexts)
    {
        eglMakeCurrent(display, surface, surface, context.context);
        glEndQueryEXT(GL_ANY_SAMPLES_PASSED_EXT);

        GLuint result = GL_TRUE;
        glGetQueryObjectuivEXT(context.query, GL_QUERY_RESULT_EXT, &result);

        EXPECT_GL_NO_ERROR();

        GLuint expectation = context.shouldPass ? GL_TRUE : GL_FALSE;
        EXPECT_EQ(expectation, result);
    }

    eglMakeCurrent(display, surface, surface, window->getContext());

    for (auto &context : contexts)
    {
        eglDestroyContext(display, context.context);
        context.context = EGL_NO_CONTEXT;
    }
}

const angle::PlatformParameters platforms[] = {
    ES2_D3D9(),   ES2_D3D11(),    ES3_D3D11(),    ES2_OPENGL(), ES2_METAL(),
    ES3_OPENGL(), ES2_OPENGLES(), ES3_OPENGLES(), ES2_VULKAN(),
};

// Use this to select which configurations (e.g. which renderer, which GLES major version) these
// tests should be run against.
INSTANTIATE_TEST_SUITE_P(
    ,
    OcclusionQueriesTest,
    testing::Combine(testing::ValuesIn(::angle::FilterTestParams(platforms, ArraySize(platforms))),
                     testing::Values(false)),
    PrintToStringParamName());

// Simulate missing buffer read-write features in Metal.
INSTANTIATE_TEST_SUITE_P(OverrideFeatures,
                         OcclusionQueriesTest,
                         testing::Combine(testing::Values(ES2_METAL()), testing::Values(true)),
                         PrintToStringParamName());