/**
 * Camera.cpp
 *
 *  @date 27.11.2011
 *  @author Thomas Wiemann
 */

#include "Camera.hpp"

#include <OpenGL/gl.h>      /* Header File For The OpenGL32 Library */
#include <OpenGL/glu.h>     /* Header File For The GLu32 Library */

namespace asteroids
{

Camera::Camera()
    : m_baseX(1.0, 0.0, 0.0), m_baseY(0.0, 1.0, 0.0), m_baseZ(0.0, 0.0, 1.0)
{
	m_px =          0.0;
	m_py =          0.0;
	m_pz =          0.0;

	m_ix =          0.0;
	m_iy =          20.0;
	m_iz =          100.0;
	m_turnSpeed =   0.02;
	m_speed =       20;

	m_rotX =        0.0;
	m_rotY =        0.0;

}

Camera::Camera(float x, float y, float z)
     : m_baseX(1.0, 0.0, 0.0), m_baseY(0.0, 1.0, 0.0), m_baseZ(0.0, 0.0, 1.0)
{
	m_px = 0.0;
	m_py = 0.0;
	m_pz = 0.0;
	m_lx = m_ly = 0.0;
	m_lz = 0.0;
	m_speed = m_turnSpeed = 0.2;
	m_ix = x;
	m_iy = y;
	m_iz = z;

	m_rotX = 0.0;
	m_rotY = 0.0;
}

void Camera::moveLeft()
{
	m_px -= m_speed * sin(PH - m_rotY);
	m_pz -= m_speed * cos(PH - m_rotY);
}

void Camera::moveRight()
{
	m_px += m_speed * sin(PH + m_rotY);
	m_pz += m_speed * cos(PH + m_rotY);
}

void Camera::moveForward()
{
	m_px += m_speed * sin(m_rotY);
	m_pz += m_speed * cos(m_rotY);
}
void Camera::moveBackward()
{
	m_px -= m_speed * sin(m_rotY);
	m_pz -= m_speed * cos(m_rotY);
}

void Camera::turnUp()
{
	if(m_rotX < PH) 
	{
		m_rotX -= m_turnSpeed;

		// Transform base
//		Quaternion nq(m_baseX, -m_turnSpeed);
//		m_baseY = nq * m_baseY;
//		m_baseZ = nq * m_baseZ;
	}
}

void Camera::turnDown()
{
	if(m_rotX > -PH)
	{
		m_rotX += m_turnSpeed;

		//Transform base
//		Quaternion nq(m_baseX, m_turnSpeed);
//		m_baseY = nq * m_baseY;
//		m_baseZ = nq * m_baseZ;
	}
}

void Camera::turnLeft()
{
	m_rotY -= m_turnSpeed;

	//Transform base
	Quaternion nq(m_baseY, m_turnSpeed);
	m_baseX = nq * m_baseX;
	m_baseZ = nq * m_baseZ;
}

void Camera::turnRight()
{
	m_rotY += m_turnSpeed;

    //Transform base
    Quaternion nq(m_baseY, -m_turnSpeed);
    m_baseX = nq * m_baseX;
    m_baseZ = nq * m_baseZ;
}

void Camera::moveUp()
{
	m_py += m_speed;
}


void Camera::moveDown()
{
	m_py -= m_speed;
}

#include <iostream>
using namespace std;

void Camera::applyRotationOnly()
{
    float lx =   sin(m_rotY);
    float lz = - cos(m_rotY);
    float ly =   sin(m_rotX);

    glLoadIdentity();
    gluLookAt(lx, ly, lz, 0, 0, 0, 0.0, 1.0, 0.0);
}

void Camera::apply()
{
    // Create position and look at vector
    m_lx = m_ix + m_px + sin(m_rotY);
    m_lz = m_iz - m_pz - cos(m_rotY);
    m_ly = m_iy + m_py + sin(m_rotX);

    // Clear matrix stack
    glLoadIdentity();

    // Calc transformation matrix
    gluLookAt(m_ix + m_px, m_iy + m_py, m_iz - m_pz,
            m_lx, m_ly, m_lz,
            0.0, 1.0, 0.0);
}

} // namespace asteroids
