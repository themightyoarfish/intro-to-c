###############################################################################
# Declare the minimum cmake version required
###############################################################################
cmake_minimum_required(VERSION 2.8)

###############################################################################
# The name of out project
###############################################################################
project(LSSR)

###############################################################################
# Now you would normally declare additional linker and include directories.
# We don't need this at this moment, just to show you how its done
###############################################################################

#link_directories("${CMAKE_SOURCE_DIR}/lib")
#link_directories("$ENV{HOME}/local/lib")

#include_directories(${CMAKE_SOURCE_DIR}/ext/Eigen)
#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${CMAKE_SOURCE_DIR}/src/lib)

###############################################################################
# With cmake we can define additional compiler flags for different 
# configurations. CMAKE_CXX_FLAGS are for the default case. The debug config
# can be used to generate debug symbols for gdb. The release option uses
# special optimization flags
###############################################################################

set( CMAKE_CXX_FLAGS         "-O3 -Wall -Wno-deprecated-declarations" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3 -msse3 -Wno-deprecated-declarations -Wno-unused" )
set( CMAKE_CXX_FLAGS_DEBUG   "-g -Wall -Wno-deprecated-declarations" )

###############################################################################
# Find required libraries.Right now we need glut and OpenGL. The required 
# options forces this packages to be present. For non-mandatory packages you 
# can leave this flag out. The can then check if they were found by using
# IF(OpenGL_found) etc.
###############################################################################

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)

if(OPENGL_FOUND)
    link_directories(${OpenGL_LIBRARY_DIR})
    include_directories(${OpenGL_INCLUDE_DIR})
endif(OPENGL_FOUND)

if(GLUT_FOUND)
    link_directories(${GLUT_LIBRARY_DIR})
    include_directories(${GLUT_INCLUDE_DIR})
endif(GLUT_FOUND)

###############################################################################
# Variable for the sources of the binary. In larger projects it is often a 
# good idea to use such variables because it is easy to add more source files
# and you can reuse it for several targets (maybe you want to build a library
# some day ;-)
###############################################################################

set(VIEWER_SOURCES
    MainWindow.cpp   
    TriangleMesh.cpp  
    Camera.cpp
    Main.cpp
    Quaternion.cpp
    Vertex.cpp 
    Matrix.cpp
)

###############################################################################
# The executable fpr our project
###############################################################################

add_executable(viewer ${VIEWER_SOURCES})

###############################################################################
# External library dependencys
###############################################################################

target_link_libraries(viewer ${GLUT_LIBRARY} ${OPENGL_LIBRARY})

