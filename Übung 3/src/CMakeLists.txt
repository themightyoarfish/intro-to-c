project(Blatt_3 C)
set(CMAKE_C_COMPILER gcc) # why is this cc by default?
set(CMAKE_C_FLAGS "-Wall -Wstrict-prototypes -ansi -pedantic")

# ex 1
add_executable(pointer_test pointer_test.c)

# ex 2
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

# header files
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.c mainwindow.c)
target_link_libraries(main ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
