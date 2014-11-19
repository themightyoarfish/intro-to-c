#include "Camera.hpp"
#include <cmath>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <sstream>
#include <string>

const double Camera::CAM_SENSITIVITY = 5.0;
const double PH = 1.57079632;
void Camera::Init(float x, float y, float z)
{
   vector m_up =  { .x = 0, .y = 1, .z = 0 };
   this->m_up = m_up;
   vector m_trans =  { .x = 0, .y = 0, .z = 0 };
   this->m_trans = m_trans;
   vector m_initial =  { .x = x, .y = y, .z = z };
   this->m_initial = m_initial;
   vector m_rot =  { .x = 0, .y = 0, .z = 0 };
   this->m_rot = m_rot;
   vector m_l =  { .x = 0, . y = 0, .z = -1 };
   this->m_l = m_l;
   m_turnSpeed = .05;
   m_moveSpeed = 5.;
}
Camera::Camera()
{
   Init(0.,0.,0.);
}
Camera::Camera(float x, float y, float z)
{
   Init(x,y,z);
}

void Camera::apply()
{
    /* Calc look at vector based on rotation state */
    m_l.x =  m_initial.x + m_trans.x + sin(m_rot.y);
    m_l.z = -m_initial.z - m_trans.z - cos(m_rot.y);
    m_l.y =  m_initial.y + m_trans.y + sin(m_rot.x);

    /* Clear matrix stack */
    glLoadIdentity();
    
    /* Apply transformation */
    gluLookAt(m_initial.x + m_trans.x, m_initial.y + m_trans.y, -m_initial.z - m_trans.z,
              m_l.x, m_l.y, m_l.z,
              m_up.x, m_up.y, m_up.z);

}

std::string Camera::to_string()
{
   std::stringstream s;
   s << "Current camera parameters: \n";
   s << "Position: " << m_trans.x << " " << m_trans.y << " " << m_trans.z << std::endl;
   s << "Rotation: " << m_rot.x << " " << m_rot.y << " " << m_rot.z << std::endl;
   s << "LookAt  : " << m_l.x << " " << m_l.y << " " << m_l.z << std::endl;
   s << "ViewUp  : " << m_up.x << " " << m_up.y << " " << m_up.z << std::endl;
   return s.str();
}
void Camera::moveUp()
{
   m_trans.y += m_moveSpeed;
}

void Camera::moveDown()
{
   m_trans.y -= m_moveSpeed;
}

void Camera::moveForward()
{
   m_trans.x += m_moveSpeed * sin(m_rot.y);
   m_trans.z += m_moveSpeed * cos(m_rot.y);
}

void Camera::moveBackward()
{
   m_trans.x -= m_moveSpeed * sin(m_rot.y);
   m_trans.z -= m_moveSpeed * cos(m_rot.y);
}

void Camera::turnLeft()
{
   m_rot.y -= m_turnSpeed;
}

void Camera::turnRight()
{
   m_rot.y += m_turnSpeed;
}

void Camera::turnUp()
{
   if(m_rot.x < PH) m_rot.x += m_turnSpeed;
}

void Camera::turnDown()
{
   if(m_rot.x < PH) m_rot.x -= m_turnSpeed;
}

void Camera::setTurnSpeed(float s)
{
   if (s > 0) m_turnSpeed = s;
}

void Camera::setSpeed(float s)
{
   if (s > 0) m_moveSpeed = s;
}
