
set(CLIPPER2_INC_FOLDER ./CPP/Clipper2Lib/include/clipper2)
set(CLIPPER2_SRC_FOLDER ./CPP/Clipper2Lib/src)

set(CLIPPER2_INC
  ${CLIPPER2_INC_FOLDER}/clipper.h
  ${CLIPPER2_INC_FOLDER}/clipper.version.h
  ${CLIPPER2_INC_FOLDER}/clipper.core.h
  ${CLIPPER2_INC_FOLDER}/clipper.engine.h
  ${CLIPPER2_INC_FOLDER}/clipper.export.h
  ${CLIPPER2_INC_FOLDER}/clipper.minkowski.h
  ${CLIPPER2_INC_FOLDER}/clipper.offset.h
  ${CLIPPER2_INC_FOLDER}/clipper.rectclip.h
)

set(CLIPPER2_SRC
  ${CLIPPER2_SRC_FOLDER}/clipper.engine.cpp
  ${CLIPPER2_SRC_FOLDER}/clipper.offset.cpp
  ${CLIPPER2_SRC_FOLDER}/clipper.rectclip.cpp
)

# Define target name
set (TARGET_NAME Clipper2)

# set (INCLUDE_DIRS ./Clipper2Lib/include ./Utils)
# list (APPEND SOURCE_FILES ${CLIPPER2_INC} ${CLIPPER2_SRC} ${CLIPPER2_UTILS_INC} ${CLIPPER2_UTILS_SRC})

set (INCLUDE_DIRS ./CPP/Clipper2Lib/include )
list (APPEND SOURCE_FILES ${CLIPPER2_INC} ${CLIPPER2_SRC})

# Setup target as STATIC library (as the result we never use EXTRA_LDFLAGS linker flags)
setup_library ()

install_header_files (DIRECTORY ./CPP/Clipper2Lib/include/clipper2/ DESTINATION ${DEST_INCLUDE_DIR}/ThirdParty/clipper2 FILES_MATCHING PATTERN *.h BUILD_TREE_ONLY)
# install_header_files (FILES ${CLIPPER2_UTILS_INC} DESTINATION ${DEST_INCLUDE_DIR}/ThirdParty/clipper2)

