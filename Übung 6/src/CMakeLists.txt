cmake_minimum_required(VERSION 2.8)

set( CMAKE_CXX_FLAGS         "-O3 -Wall" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3 -msse3 -Wno-deprecated-declarations -Wno-unused" )
set( CMAKE_CXX_FLAGS_DEBUG   "-g -Wall" )

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

if(OPENGL_FOUND)
    link_directories(${OpenGL_LIBRARY_DIRS})
    include_directories(${OpenGL_INCLUDE_DIRS})
endif(OPENGL_FOUND)

if(GLUT_FOUND)
    link_directories(${GLUT_LIBRARY_DIR})
    include_directories(${GLUT_INCLUDE_DIR})
endif(GLUT_FOUND)

set(VIEWER_SOURCES
   MainWindow.cpp
   Main.cpp
   TriangleMesh.cpp
   Camera.cpp
)

add_executable(viewer ${VIEWER_SOURCES})

###############################################################################
# External library dependencys
###############################################################################

message(STATUS ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
target_link_libraries(viewer ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
target_link_libraries(viewer m)
