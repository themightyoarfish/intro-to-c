/**
 *  @file TriangleMesh.hpp
 *
 *  @date 27.11.2011
 *  @author Thomas Wiemann
 */

#ifndef TRIANGLEMESH_HPP_
#define TRIANGLEMESH_HPP_

#include <string>               // Header for c++ strings
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
              // Header File For The OpenGL Library
#include "Quaternion.hpp"
#include "Global.hpp"
#include "Vertex.hpp"
#include "Matrix.hpp"

#include <iostream>

namespace cpp2014 {
    
/**
 * @brief   A simple triangle mesh. The mesh can be instantiated from
 *          an ASCII .ply-File
 */
class TriangleMesh
{
public:

	/**
	 * @brief   Default contructor. Initializes with empty buffers
	 */
	TriangleMesh();

	/**
	 * @brief   Contructs a triangle mesh from given buffers
	 * @param indexBuffer indexbuffer
	 * @param vertexBuffer vertexbuffer
	 * @param numFaces number of faces
	 * @param numVertices number of vertices
	 */
	TriangleMesh(int* indexBuffer, float* vertexBuffer, int numFaces, int numVertices);

	/**
	 * @brief   Constructs a triangle mesh from the given ASCII
	 *          PLY file
	 * @param filename filename
	 */
	TriangleMesh(std::string filename);

	/**
	 * @brief   Rotates a triangle mesh at the given axis with the given speed
	 * @param axis axis to rotate
	 * @param speed speed of rotation
	 */
	void rotate(int axis, float speed);

	/**
	 * @brief   Moves a triangle mesh at the given axis with the given speed
	 * @param axis axis to move
	 * @param speed speed of movement
	 */
	void move(int axis, float speed);

	/**
	 * @brief   Renders the mesh
	 */
	void render();

	/**
	 * @brief   Destructor
	 */
	~TriangleMesh();

private:

	/**
	 * @brief Computes the 4x4 transformation matrix of this object (needed for OpenGL)
	 */
	void computeMatrix();

	/**
	 * @brief The index buffer containing the triangle definitions
	 */
	int*	m_indexBuffer;

	/**
	 * @brief The array of vertex definitions
	 */
	float*	m_vertexBuffer;

	/**
	 * @brief The number of triangles in the mesh
	 */
	int	m_numFaces;

	/**
	 * @brief The number of vertices in the mesh
	 */
	int	m_numVertices;

	/**
	 * @brief The current orientation of the x axis
	 */
	Vertex	m_xAxis;

	/**
	 * @brief The current orientation of the y axis
	 */
	Vertex	m_yAxis;

	/**
	 * @brief The current orientation of the z axis
	 */
	Vertex	m_zAxis;


	/**
	 * @brief The current position of the mesh object
	 */
	Vertex	m_position;

	/**
	 * @brief A quaternion representing the current rotation
	 */
	Quaternion 	m_rotation;

	/**
	 * @brief The transformation matrix for this object
	 */
	Matrix	m_transformation;
};
    
} // namespace cpp2014

#endif
