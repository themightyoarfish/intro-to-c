/**
 * @file Asteroid.hpp
 * @author Dominik Feldschnieders
 * @author Thomas Wiemann
 */

#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

// Asteroid Project includes
#include "TexturedMesh.hpp"
#include "math/Vertex.hpp"
#include "io/TriangleMeshFactory.hpp"

// Std C++ includes
#include <cstdlib>

namespace asteroids
{
/**
 * @brief  Representation of an asteroid
 */
class Asteroid: public Transformable
{


public:

    /**
     * @brief   Ctor.
     * @param   start_position   Position of the fighter that shoots this Asteroid
     * @param   scale            Scaling factor to vary the asteroid's size
     */
    Asteroid(TriangleMesh* mesh, Vertex<float> start_position, float scale);

    /**
     * @brief   Ctor.
     */
    Asteroid();

    virtual ~Asteroid();

    /**
     * @brief   Renders the asteroid
     */
    virtual void render();

protected:

    /// The mesh struture to represent the asteroid
    TriangleMesh*   m_mesh;

    /// Scaling factor
    float           m_scale;
};

}
#endif /* ASTEROID_HPP_ */
