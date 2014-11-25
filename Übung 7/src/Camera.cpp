/**
 * Camera.cpp
 *
 *  @date 27.11.2011
 *  @author Thomas Wiemann
 */

#include "Camera.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>         
#include <OpenGL/glu.h>
#else
#ifdef __APPLE__
#include <gl.h>
#else
#include <GL/gl.h>
#endif

#ifdef __APPLE__
#include <glu.h>
#else
#include <GL/glu.h>
#endif

#endif


namespace cpp2014
{

Camera::Camera()
{
    
    // Initially the camera base is aligned with the global coordinate system
    m_baseX     = Vertex(1.0, 0.0, 0.0);
    m_baseY     = Vertex(0.0, 1.0, 0.0);
    m_baseZ     = Vertex(0.0, 0.0, 1.0);
    
    // The iniital offset is zero
    m_offset    = Vertex(0.0, 0.0, 0.0);

    // Initial position is zero
    m_initial   = Vertex(0.0, 0.0, 0.0);
	
    // Setup sane value for turn and move speed
	m_turnSpeed =   0.025;
	m_speed =       0.025;

    // Initial rotation is zero
	m_rotation  = Vertex(0.0, 0.0, 0.0);
}

Camera::Camera(float x, float y, float z)
{
    // Initially the camera base is aligned with the global coordinate system
    m_baseX     = Vertex(1.0, 0.0, 0.0);
    m_baseY     = Vertex(0.0, 1.0, 0.0);
    m_baseZ     = Vertex(0.0, 0.0, 1.0);
    
    // The iniital offset is zero
    m_offset    = Vertex(0.0, 0.0, 0.0);
    
    // Initial position is zero
    m_initial   = Vertex(x, y, z);
    
    // Setup sane value for turn and move speed
    m_turnSpeed =   0.025;
    m_speed =       0.025;
    
    // Initial rotation is zero
    m_rotation  = Vertex(0.0, 0.0, 0.0);
}


void Camera::moveLeft()
{
	m_offset[0] -= m_speed * sin(PH - m_rotation[1]);
	m_offset[2] -= m_speed * cos(PH - m_rotation[1]);
}

void Camera::moveRight()
{
	m_offset[0] += m_speed * sin(PH + m_rotation[1]);
	m_offset[2] += m_speed * cos(PH + m_rotation[1]);
}

void Camera::moveForward()
{
	m_offset[0] += m_speed * sin(m_rotation[1]);
	m_offset[2] += m_speed * cos(m_rotation[1]);
}
void Camera::moveBackward()
{
	m_offset[0] -= m_speed * sin(m_rotation[1]);
	m_offset[2] -= m_speed * cos(m_rotation[1]);
}

void Camera::rollLeft()
{
    Quaternion nq(m_baseZ, -m_turnSpeed);
    m_baseY = nq * m_baseY;
    m_baseX = nq * m_baseX;
}

void Camera::rollRight()
{
    Quaternion nq(m_baseZ, m_turnSpeed);
    m_baseY = nq * m_baseY;
    m_baseX = nq * m_baseX;
}

void Camera::turnUp()
{
    m_rotation[0] -= m_turnSpeed;
    // Transform base
	Quaternion nq(m_baseX, -m_turnSpeed);
	m_baseY = nq * m_baseY;
	m_baseZ = nq * m_baseZ;
}

void Camera::turnDown()
{
	m_rotation[0] += m_turnSpeed;
	// Transform base
	Quaternion nq(m_baseX, m_turnSpeed);
	m_baseY = nq * m_baseY;
	m_baseZ = nq * m_baseZ;
}

void Camera::turnLeft()
{
	m_rotation[1] -= m_turnSpeed;

	//Transform base
	Quaternion nq(m_baseY, m_turnSpeed);
	m_baseX = nq * m_baseX;
	m_baseZ = nq * m_baseZ;
}

void Camera::turnRight()
{
	m_rotation[1] += m_turnSpeed;

    //Transform base
    Quaternion nq(m_baseY, -m_turnSpeed);
    m_baseX = nq * m_baseX;
    m_baseZ = nq * m_baseZ;
}

void Camera::moveUp()
{
	m_offset[1] += m_speed;
}


void Camera::moveDown()
{
	m_offset[1] -= m_speed;
}


void Camera::apply()
{
    // Create position and look at vector
    Vertex lookAt;
    lookAt[0] = m_initial[0] + m_offset[0] + m_baseZ[0];
    lookAt[2] = m_initial[2] + m_offset[2] + m_baseZ[1];
    lookAt[1] = m_initial[1] + m_offset[1] + m_baseZ[2];

    // Clear matrix stack
    glLoadIdentity();

    // Calc transformation matrix
    gluLookAt(m_initial[0] + m_offset[0], m_initial[1] + m_offset[1], m_initial[2] - m_offset[2],
            lookAt[0], lookAt[1], lookAt[2],
            m_baseY[0], m_baseY[1], m_baseY[2]);
}
} // namespace asteroids
