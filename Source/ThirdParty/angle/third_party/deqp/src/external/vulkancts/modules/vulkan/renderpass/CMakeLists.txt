# Render pass tests

include_directories(..)

set(DEQP_VK_RENDER_PASS_SRCS
	vktRenderPassTests.cpp
	vktRenderPassTests.hpp
	vktRenderPassTestsUtil.cpp
	vktRenderPassTestsUtil.hpp
	vktRenderPassMultisampleTests.cpp
	vktRenderPassMultisampleTests.hpp
	vktRenderPassMultisampleResolveTests.cpp
	vktRenderPassMultisampleResolveTests.hpp
	vktRenderPassDepthStencilResolveTests.cpp
	vktRenderPassDepthStencilResolveTests.hpp
	vktRenderPassSampleReadTests.cpp
	vktRenderPassSampleReadTests.hpp
	vktRenderPassSparseRenderTargetTests.cpp
	vktRenderPassSparseRenderTargetTests.hpp
	vktRenderPassSubpassDependencyTests.cpp
	vktRenderPassSubpassDependencyTests.hpp
	vktRenderPassUnusedAttachmentTests.cpp
	vktRenderPassUnusedAttachmentTests.hpp
	)

set(DEQP_VK_RENDER_PASS_LIBS
	tcutil
	vkutil
	)

PCH(DEQP_VK_RENDER_PASS_SRCS ../pch.cpp)

add_library(deqp-vk-render-pass STATIC ${DEQP_VK_RENDER_PASS_SRCS})
target_link_libraries(deqp-vk-render-pass ${DEQP_VK_RENDER_PASS_LIBS})
