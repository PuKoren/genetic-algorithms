cmake_minimum_required (VERSION 2.6)
project(ProgGenetique) 

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
#########################################################
# FIND GLEW
#########################################################
find_package (GLEW REQUIRED)
include_directories (${GLEW_INCLUDE_DIRS})
link_directories (${GLEW_LIBRARY_DIRS})
if (NOT GLEW_FOUND)
    message (ERROR "GLEW not found!")
endif (NOT GLEW_FOUND)

#########################################################
# FIND GLUT
#########################################################
find_package (GLUT REQUIRED)
include_directories (${GLUT_INCLUDE_DIRS})
link_directories (${GLUT_LIBRARY_DIRS})
add_definitions (${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message (ERROR " GLUT not found!")
endif (NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package (OpenGL REQUIRED)
include_directories (${OpenGL_INCLUDE_DIRS})
link_directories (${OpenGL_LIBRARY_DIRS})
add_definitions (${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message (ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)

#INCLUDES & SRC FILES
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB SRCS src/*.cpp)
file(GLOB HDRS include/*.h)

add_executable (${PROJECT_NAME} ${SRCS} ${HDRS})

########################################################
# Linking & stuff
#########################################################
target_link_libraries (${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
