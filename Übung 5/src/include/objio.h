#ifndef __OBJIO_HPP__
#define __OBJIO_HPP__

#define BUFFERSIZE 1023

/**
 * @file objio.h
 *
 * @brief OBJ I/O Management
 *
 * @author Thomas Wiemann, Henning Strüber
 */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Loads a ply-File and creates vertex and index buffer arrays.
 *
 * @param file The name of the obj file.
 * @param vertexBuffer Pointer to the created vertex buffer object or NULL
 *                     if the given file could not be parsed
 * @param indexBuffer  Pointer to the created vertex buffer object or NULL
 *                     if the given file could not be parsed
 * @param vertexCount  The number of loaded vertices or 0.
 * @param indexCount   The number of triangles in the ply model or 0.
 */
 void loadObj(
		char* file,
		float** vertexBuffer,
		int** indexBuffer,
		int* vertexCount,
		int* faceCount);

/**
 * @brief Frees the memory used by the given buffer arrays
 *
 * @param vertexBuffer  A pointer to a vertex buffer array
 * @param indexBuffer   A pointer to a index buffer array
 */
void freeObj(float** vertexBuffer, int** indexBuffer);

/**
 * @brief Get the amount of vertices and faces in the given file
 * 
 * @param file          Name of the file to parse
 * @param vertexCount	Pointer to vertexCounter
 * @param indexCount	Pointer to indexCounter
 * 
 * @return 1 if the file is valid, 0 otherwise
 * 
 */
int checkFile(char* file, int* vertexCount, int* indexCount );
#endif
