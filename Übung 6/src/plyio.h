#ifndef __PLYIO_HPP__
#define __PLYIO_HPP__

/**
 * @file plyio.h
 *
 * @brief PLY I/O Management
 *
 * @author Henning Strüber
 * @author Thomas Wiemann
 */

#ifdef __APPLE__
#include <gl.h>
#else
#include <GL/gl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Loads a ply-File and creates vertex and index buffer arrays.
 *
 * @param file The name of the ply-File.
 * @param vertexBuffer Pointer to the created vertex buffer object or NULL
 *                     if the given file could not be parsed
 * @param indexBuffer  Pointer to the created vertex buffer object or NULL
 *                     if the given file could not be parsed
 * @param vertexCount  The number of loaded vertices or 0.
 * @param indexCount   The number of triangles in the ply model or 0.
 */
 void loadply(
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
void freePLY(float** vertexBuffer, int** indexBuffer);

/**
 * @brief Helper function to parse vertex definitions 
 *
 * @param line          A string containing vertex positions
 * @param buffer        A pointer to current vertex buffer position
 */
void write_vertices_to_buffer(char* line, float* buffer);

/**
 * @brief Helper function to parse face definitions
 *
 * @param line          A string containing face positions
 * @param buffer        A pointer to current index buffer position
 */
void write_indices_to_buffer(char* line, int* buffer);

#endif
