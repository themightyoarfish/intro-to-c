/**
 * TriangleMesh.hpp
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
#include <GL/gl.h>              // Header File For The OpenGL Library
#endif
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
     * @brief   Contructs a traingle mesh from given buffers
     */
    TriangleMesh(int* indexBuffer, float* vertexBuffer, int numFaces, int numVertices)
         : m_indexBuffer(indexBuffer),
           m_vertexBuffer(vertexBuffer),
           m_numFaces(numFaces),
           m_numVertices(numVertices) {}

    /**
     * @brief   Constructs a triangle mesh from the given ASCII
     *          PLY file
     */
    TriangleMesh(std::string filename);

    /**
     * @brief   Destructor
     */
    ~TriangleMesh();

    /**
     * @brief   Renders the mesh
     */
    void render();

private:

    /// The index buffer containing the triangle definitions
    int*        m_indexBuffer;

    /// The array of vertex definitions
    float*      m_vertexBuffer;

    /// The number of triangles in the mesh
    int         m_numFaces;

    /// The number of vertices in the mesh
    int         m_numVertices;

};

#endif /* TRIANGLEMESH_HPP_ */
