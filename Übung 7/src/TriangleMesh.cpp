/**
 * TriangleMesh.cpp
 *
 *  @date 27.11.2011
 *  @author Thomas Wiemann
 */

#include "TriangleMesh.hpp"

namespace cpp2014 {
   
TriangleMesh::TriangleMesh()
{
	// Init member variables
	m_numFaces      = 0;
	m_numVertices   = 0;
	m_vertexBuffer  = 0;
	m_indexBuffer   = 0;

	// Setup rotation and position
	m_xAxis 		= Vertex(1.0, 0.0, 0.0);
	m_yAxis 		= Vertex(0.0, 1.0, 0.0);
	m_zAxis 		= Vertex(0.0, 0.0, 1.0);
	m_position		= Vertex(0.0, 0.0, 0.0);

	m_rotation.fromAxis(Vertex(0.0, 0.0, 1.0), 0.0f);

    // Set tranformation matrix to unit matrix
    for(int i = 0; i < 16; i++)
    {
        m_transformation[i] = 0.0f;
    }
    m_transformation[0 ] = 1.0f;
    m_transformation[5 ] = 1.0f;
    m_transformation[10] = 1.0f;
    m_transformation[15] = 1.0f;
}

TriangleMesh::TriangleMesh(int* arrow_faces, float* arrow_vertices, int a, int b) 
{
	// Save mesh information and buffers
	m_numFaces      = a;
	m_numVertices   = b;
	m_vertexBuffer  = arrow_vertices;
	m_indexBuffer   = arrow_faces;

	// Setup rotation and position
	m_yAxis 		= Vertex(1.0, 0.0, 0.0);
	m_xAxis 		= Vertex(0.0, 1.0, 0.0);
	m_zAxis 		= Vertex(0.0, 0.0, 1.0);
	m_position		= Vertex(0.0, 0.0, 0.0);
	m_rotation.fromAxis(Vertex(0.0, 0.0, 1.0), 0.0f);

	// Set tranformation matrix to unit matrix
	for(int i = 0; i < 16; i++)
	{
		m_transformation[i] = 0.0f;
	}
	m_transformation[0 ] = 1.0f;
	m_transformation[5 ] = 1.0f;
	m_transformation[10] = 1.0f;
	m_transformation[15] = 1.0f;

}


TriangleMesh::TriangleMesh(std::string filename)
{
	// TODO Implement ply import
}

void TriangleMesh::rotate(int axis, float s)
{

	Quaternion nq;

	// Get the wanted operation and calculate the new coordinates
	switch(axis)
	{
	case PITCH:
		nq.fromAxis(m_yAxis, s);
		m_xAxis = nq * m_xAxis;
		m_zAxis = nq * m_zAxis;
		break;

	case YAW:
		nq.fromAxis(m_xAxis, s);
		m_yAxis = nq * m_yAxis;
		m_zAxis = nq * m_zAxis;
		break;

	case ROLL:
		nq.fromAxis(m_zAxis, s);
		m_yAxis = nq * m_yAxis;
		m_xAxis = nq * m_xAxis;
		break;
	}

	// Update mesh rotation 
	m_rotation = m_rotation * nq;
}

void TriangleMesh::move(int axis, float speed)
{
	Vertex direction;

	// Determine the correct axis of the local system
	switch(axis)
	{
	case ACCEL:
		direction = m_zAxis;
		break;
	case STRAFE:
		direction = m_xAxis;
		break;
	case LIFT:
		direction = m_yAxis;
	}

	// Update mesh position
	m_position = m_position + direction * speed;
}

void TriangleMesh::computeMatrix()
{
	// Compute the transformation matrix for this object
	// according to the current position and rotation
	// state
	m_transformation[0]  = m_yAxis[0];
	m_transformation[1]  = m_yAxis[1];
	m_transformation[2]  = m_yAxis[2];

	m_transformation[4]  = m_xAxis[0];
	m_transformation[5]  = m_xAxis[1];
	m_transformation[6]  = m_xAxis[2];

	m_transformation[8]  = m_zAxis[0];
	m_transformation[9]  = m_zAxis[1];
	m_transformation[10] = m_zAxis[2];

	m_transformation[12] = m_position[0];
	m_transformation[13] = m_position[1];
	m_transformation[14] = m_position[2];


}

void TriangleMesh::render()
{
	// Compute transformation matrix
	computeMatrix();

	// Push old transformation of the OpenGL matrix stack and
	// start rendering the mesh in according to the
	// internal transformation matrix
	glPushMatrix();
	glMultMatrixf(m_transformation.getData());

	// Render mesh
	for(int i = 0; i < m_numFaces; i++)
	{
		// Get position og current triangle in buffer
		int index = 3 * i;

		// Get vertex indices of triangle vertices
		int a = 3 * m_indexBuffer[index];
		int b = 3 * m_indexBuffer[index + 1];
		int c = 3 * m_indexBuffer[index + 2];

		// Render wireframe model
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(m_vertexBuffer[a], m_vertexBuffer[a + 1], m_vertexBuffer[a + 2]);
		glVertex3f(m_vertexBuffer[b], m_vertexBuffer[b + 1], m_vertexBuffer[b + 2]);
		glVertex3f(m_vertexBuffer[c], m_vertexBuffer[c + 1], m_vertexBuffer[c + 2]);
		glEnd();

	}

	// Pop transformation matrix of this object
	// to restore the previous state of the OpenGL
	// matrix stack
	glPopMatrix();
}

TriangleMesh::~TriangleMesh()
{
	// TODO Auto-generated destructor stub
}
    
} // namespace cpp2014

