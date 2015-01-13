/**
 * Transformable.h
 *
 *  @date 02.01.2012
 *  @author Thomas Wiemann
 */

#ifndef TRANSFORMABLE_H_
#define TRANSFORMABLE_H_

#include "Renderable.hpp"

#include "math/Quaternion.hpp"
#include "math/Vertex.hpp"

namespace asteroids
{

/**
 * @brief   Base class for all objects that can be transformed, i.e.
 *          moved and rotated.
 */
class Transformable : public Renderable
{
public:
    Transformable();
    virtual ~Transformable();

    /**
     * @brief   Rotates a triangle mesh at the given axis with the given speed
     * @param axis axis to rotate
     * @param speed speed of rotation
     */
    void rotate(int axis, float speed);
    
    /**
     * @brief   Rotate angle degress around the given axis
     */
    void rotate(Vertex<float> axis, float angle);
    

    /**
     * @brief   Moves a triangle mesh at the given axis with the given speed
     * @param axis axis to move
     * @param speed speed of movement
     */
    void move(int axis, float speed);


    /**
     * @brief   Renders the object.
     */
    virtual void render() = 0;

    Vertex<float> getPosition() { return m_position;}

protected:

    /**
     * @brief Computes the 4x4 transformation matrix of this object (needed for OpenGL)
     */
    void computeMatrix();

    /**
     * @brief The transformation matrix for this object
     */
    float   m_transformation[16];

    /**
     * @brief The current orientation of the x axis
     */
    Vertex<float>    m_xAxis;

    /**
     * @brief The current orientation of the y axis
     */
    Vertex<float>    m_yAxis;

    /**
     * @brief The current orientation of the z axis
     */
    Vertex<float>    m_zAxis;


    /**
     * @brief The current position of the mesh object
     */
    Vertex<float>    m_position;

    /**
     * @brief A quaternion representing the current rotation
     */
    Quaternion<float>  m_rotation;


};

}

#endif /* TRANSFORMABLE_H_ */
