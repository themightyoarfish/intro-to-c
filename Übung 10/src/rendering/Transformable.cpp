/**
 * Transformable.cpp
 *
 *  @date 02.01.2012
 *  @author Thomas Wiemann
 */

#include "Transformable.hpp"

namespace asteroids
{

Transformable::Transformable()
{
    // Setup rotation and position
    m_xAxis         = Vertex<float>(1.0, 0.0, 0.0);
    m_yAxis         = Vertex<float>(0.0, 1.0, 0.0);
    m_zAxis         = Vertex<float>(0.0, 0.0, 1.0);
    m_position      = Vertex<float>(0.0, 0.0, 0.0);

    m_rotation.fromAxis(Vertex<float>(0.0, 0.0, 1.0), 0.0f);

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

void Transformable::rotate(int axis, float s)
{

    Quaternion<float> nq;

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

void Transformable::move(int axis, float speed)
{
    Vertex<float> direction;

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

void Transformable::computeMatrix()
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

Transformable::~Transformable()
{
    // TODO Auto-generated destructor stub
}

}
