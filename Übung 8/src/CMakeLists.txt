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

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/ext/load3ds)
include_directories(${CMAKE_SOURCE_DIR}/ext/load3ds/math3d++)

link_directories("${CMAKE_SOURCE_DIR}/lib")

###############################################################################
# With cmake we can define additional compiler flags for different 
# configurations. CMAKE_CXX_FLAGS are for the default case. The debug config
# can be used to generate debug symbols for gdb. The release option uses
# special optimization flags
###############################################################################

set( CMAKE_CXX_FLAGS         "-O3 -Wall -Wno-char-subscripts" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3 -msse3 -Wno-char-subscripts -Wno-deprecated-declarations -Wno-unused -Wcpp" )
set( CMAKE_CXX_FLAGS_DEBUG   "-g -Wall -Wno-char-subscripts"  )

###############################################################################
# Find required libraries.Right now we need glut and OpenGL. The required 
# options forces this packages to be present. For non-mandatory packages you 
# can leave this flag out. The can then check if they were found by using
# IF(OpenGL_found) etc.
###############################################################################

FIND_PACKAGE(SDL REQUIRED)
if(SDL_FOUND)
	include_directories(${SDL_INCLUDE_DIR})
endif(SDL_FOUND)

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)

if(OPENGL_FOUND)
    link_directories(${OpenGL_INCLUDE_DIRS})
    include_directories(${OpenGL_LIBRARY_DIRS})
endif(OPENGL_FOUND)

###############################################################################
# Compile external libraries
###############################################################################

add_subdirectory(ext/load3ds)

###############################################################################
# Variable for the sources of the binary. In larger projects it is often a 
# good idea to use such variables because it is easy to add more source files
# and you can reuse it for several targets (maybe you want to build a library
# some day ;-)
###############################################################################

set(VIEWER_SOURCES
	io/Read3DS.cpp
	io/ReadPLY.cpp
   io/ReadPPM.cpp
	io/ReadTGA.cpp
   io/ReadJPG.cpp
	io/PLYTraits.cpp
	io/TextureFactory.cpp
	io/TriangleMeshFactory.cpp
    	view/MainWindow.cpp   
    	view/Camera.cpp
    	rendering/TriangleMesh.cpp
	rendering/Texture.cpp 
	rendering/Skybox.cpp
	rendering/Transformable.cpp
	rendering/TexturedMesh.cpp
    	math/Quaternion.cpp
    	math/Vertex.cpp
    	Main.cpp
)

###############################################################################
# The executable fpr our project
###############################################################################

add_executable(viewer ${VIEWER_SOURCES} ${C3DSREADER_SOURCES})

###############################################################################
# External library dependencies
###############################################################################

target_link_libraries(viewer ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
target_link_libraries(viewer c3dsreader) 
target_link_libraries(viewer ${SDL_LIBRARY} jpeg)


