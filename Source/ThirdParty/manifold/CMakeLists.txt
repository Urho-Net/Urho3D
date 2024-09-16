set (TARGET_NAME manifold)

file(GLOB_RECURSE MANIFOLD_SOURCE ./src/manifold/*.cpp src/polygon/*.cpp src/cross_section/*.cpp)

set (INCLUDE_DIRS src src/utilities/include src/manifold/include src/collider/include src/polygon/include src/cross_section/include ../glm ../clipper2/CPP/Clipper2Lib/include )

list (APPEND SOURCE_FILES ${MANIFOLD_SOURCE})

# Setup target as STATIC library (as the result we never use EXTRA_LDFLAGS linker flags)
setup_library ()

install_header_files (DIRECTORY include/ DESTINATION ${DEST_INCLUDE_DIR}/ThirdParty/manifold FILES_MATCHING PATTERN *.h BUILD_TREE_ONLY)
