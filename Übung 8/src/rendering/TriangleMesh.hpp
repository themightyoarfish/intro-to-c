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
#include <OpenGL/gl.h>              // Header File For The OpenGL Library
#else 
#include <GL/gl.h>
#endif


#include <iostream>
#include "math/Vertex.hpp"
#include "math/Quaternion.hpp"
#include "Transformable.hpp"

namespace asteroids
{

   /**
    * @brief   A simple triangle mesh. The mesh can be instantiated from
    *          an ASCII .ply-File
    */
   class TriangleMesh : public Transformable
   {
      public:

         /**
          * @brief   Default contructor. Initializes with empty buffers
          */
         TriangleMesh();

         /**
          * @see Transformable::rotate
          */
         void rotate(int axis, float s);

         /**
          * @see Transformable::move
          */
         void move(int axis, float s);

         /**
          * @brief   Renders the mesh
          * @see Renderable::render
          */
         virtual void render();

         /**
          * @brief   Destructor
          */
         ~TriangleMesh();

         /**
          * @brief   Sets the normal buffer of the mesh
          *
          * @param normals The new normal buffer
          */
         void setNormalBuffer(float* normals) { m_normalBuffer = normals;}

         /**
          * @brief   Sets the vertex buffer of the mesh
          *
          * @param vertices  The new vertex buffer
          * @param n         The number of vertices in the mesh
          */
         void setVertexBuffer(float* vertices, int n)
         {
            m_vertexBuffer = vertices;
            m_numVertices = n;
         }

         /**
          * @brief   Sets the index buffer of the mesh
          *
          * @param faces     The new index buffer
          * @param n         The number of faces in the mesh
          */

         void setIndexBuffer(int* faces, int n)
         {
            m_indexBuffer = faces;
            m_numFaces = n;
         }

      protected:


         /**
          * @brief The index buffer containing the triangle definitions
          */
         int*	m_indexBuffer;

         /**
          * @brief The array of vertex definitions
          */
         float*	m_vertexBuffer;

         /***
          * @brief A buffer containing vertex normal information
          */
         float*  m_normalBuffer;

         /**
          * @brief The number of triangles in the mesh
          */
         int	m_numFaces;

         /**
          * @brief The number of vertices in the mesh
          */
         int	m_numVertices;

         void computeMatrix();

         /**
          * @brief The transformation matrix for this object
          */
         float   m_transformation[16];

         /**
          * @brief The current orientation of the x axis
          */
         Vertex    m_xAxis;//hier wurde statt Vector3f der Typ ersetzt

         /**
          * @brief The current orientation of the y axis
          */
         Vertex    m_yAxis;

         /**
          * @brief The current orientation of the z axis
          */
         Vertex    m_zAxis;


         /**
          * @brief The current position of the mesh object
          */
         Vertex    m_position;

         /**
          * @brief A quaternion representing the current rotation
          */
         Quaternion  m_rotation;



   };

} // namespace asteroids

#endif
