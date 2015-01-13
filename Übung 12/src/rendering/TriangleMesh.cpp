/**
 * TriangleMesh.cpp
 *
 *  @date 27.11.2011
 *  @author Thomas Wiemann
 */

#include "TriangleMesh.hpp"

#include <iostream>
using namespace std;

namespace asteroids
{

TriangleMesh::TriangleMesh()
{
	// Init member variables
	m_numFaces      = 0;
	m_numVertices   = 0;
	m_vertexBuffer  = 0;
	m_indexBuffer   = 0;

}

TriangleMesh::TriangleMesh(const TriangleMesh& other)
{

	m_numFaces = other.m_numFaces;
	m_numVertices = other.m_numVertices;


	// Allocate new buffers (if existing) and copy
	// contends
	if(other.m_vertexBuffer)
	{
		m_vertexBuffer = new float[3 * other.m_numVertices];
		for(int i = 0; i < 3 * other.m_numVertices; i++)
		{
			m_vertexBuffer[i] = other.m_vertexBuffer[i];
		}
	}

	if(other.m_normalBuffer)
	{
		m_normalBuffer = new float[3 * other.m_numVertices];
		for(int i = 0; i < 3 * other.m_numVertices; i++)
		{
			m_normalBuffer[i] = other.m_normalBuffer[i];
		}
	}

	if(other.m_indexBuffer)
	{
		m_indexBuffer = new int[3 * other.m_numFaces];
		for(int i = 0; i < 3 * other.m_numFaces; i++)
		{
			m_indexBuffer[i] = other.m_indexBuffer[i];
		}
	}

}

void TriangleMesh::render()
{
	// Compute transformation matrix
	computeMatrix();

	// Push old transformation of the OpenGL matrix stack and
	// start rendering the mesh in according to the
	// internal transformation matrix
	glPushMatrix();
	glMultMatrixf(m_transformation);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
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
		if(!m_normalBuffer)
		{
		    glBegin(GL_LINE_LOOP);
		}
		else
		{
		    glBegin(GL_TRIANGLES);
		    glNormal3f(m_normalBuffer[a], m_normalBuffer[a + 1], m_normalBuffer[a + 2]);
		}

		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(m_vertexBuffer[a], m_vertexBuffer[a + 1], m_vertexBuffer[a + 2]);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(m_vertexBuffer[b], m_vertexBuffer[b + 1], m_vertexBuffer[b + 2]);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(m_vertexBuffer[c], m_vertexBuffer[c + 1], m_vertexBuffer[c + 2]);
		glColor3f(1.0, 1.0, 1.0);
		glEnd();

	}

	// Pop transformation matrix of this object
	// to restore the previous state of the OpenGL
	// matrix stack
	glPopMatrix();
}

TriangleMesh::~TriangleMesh()
{
	// Delete buffers
	if(m_normalBuffer)
	{
		delete m_normalBuffer;
		m_normalBuffer = 0;
	}

	if(m_vertexBuffer)
	{
		delete m_vertexBuffer;
		m_vertexBuffer = 0;
	}

	if(m_indexBuffer)
	{
		delete m_indexBuffer;
		m_indexBuffer = 0;
	}
}

}
