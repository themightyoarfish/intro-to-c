/**
 * TriangleMesh.cpp
 *
 *  @date 27.11.2011
 *  @author Thomas Wiemann
 */

#include "TriangleMesh.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

TriangleMesh::TriangleMesh()
{
    m_numFaces      = 0;
    m_numVertices   = 0;
    m_vertexBuffer  = 0;
    m_indexBuffer   = 0;

}

TriangleMesh::TriangleMesh(std::string filename)
{
    // Initialize buffers
    m_numFaces      = 0;
    m_numVertices   = 0;
    m_vertexBuffer  = 0;
    m_indexBuffer   = 0;

    // Try to open file for reading
    ifstream file(filename.c_str());
    if(file.good())
    {
        string ply_tag;
        file >> ply_tag;

        // Check PLY-TAG
        if(ply_tag != "ply")
        {
            cout << "Error reading " << filename << ". "
                 << "Not a valid .ply file" << endl;
            return;
        }

        // Parse header
        while(file.good())
        {
            // Parse elements
            string line;
            file >> line;

            // Parse lines
            string tag;
            stringstream ss(line);
            ss >> tag;

            if(tag == "comment")
            {
                continue;
            }
            else if(tag == "vertex")
            {
                file >> m_numVertices;
                continue;
            }
            else if(tag == "face")
            {
                file >> m_numFaces;
            }
            else if(tag == "end_header")
            {
                break;
            }
            else if(tag == "format")
            {
                string format_tag;
                file >> format_tag;
                if(format_tag != "ascii")
                {
                    cout << "Error parsing header. No ASCII data." << endl;
                    m_numFaces = 0;
                    m_numVertices = 0;
                    break;
                }
            }
            else
            {
                continue;
            }
        }

        // Allocate buffer memory
        m_vertexBuffer = new float[3 * m_numVertices];
        m_indexBuffer = new int[3 * m_numFaces];

        // Read vertex definitions
        for(int i = 0; i < m_numVertices && file.good(); i++)
        {
            float x, y, z;
            file >> x >> y >> z;
            m_vertexBuffer[3 * i]     = x;
            m_vertexBuffer[3 * i + 1] = y;
            m_vertexBuffer[3 * i + 2] = z;
        }

        // Read face definitions
        for(int i = 0; i < m_numFaces && file.good(); i++)
        {
            float n, x, y, z;
            file >> n >> x >> y >> z;

            m_indexBuffer[3 * i]     = x;
            m_indexBuffer[3 * i + 1] = y;
            m_indexBuffer[3 * i + 2] = z;
        }
    }
    else
    {
        cout << "Error: Could not open file '" << filename << "'." << endl;
    }

    // Close file
    file.close();



}

void TriangleMesh::render()
{
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
}

TriangleMesh::~TriangleMesh()
{
    // Delete buffers
    if(m_vertexBuffer)
    {
        delete[] m_vertexBuffer;
        m_vertexBuffer = 0;
    }
    if(m_indexBuffer)
    {
        delete[] m_indexBuffer;
        m_indexBuffer = 0;
    }
}

