#include "Camera.hpp"
#include <cmath>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <iostream>

const double Camera::CAM_SENSITIVITY = 5.0;
void Camera::Init(float x, float y, float z)
{
   vector up = { .x = 0, .y = 1, .z = 0 };
   vector trans = { .x = 0, .y = 0, .z = 0 };
   vector initial = { .x = x, .y = y, .z = z };
   vector rot = { .x = 0, .y = 0, .z = 0 };
   vector l = { .x = 0, . y = 0, .z = -1 };
   turn_speed = 10.0;
   move_speed = 0.5;
   std::cout << "Init()" << std::endl;
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
   std::cout << "apply()" << std::endl;
    /* Calc look at vector based on rotation state */
    l.x =  initial.x + trans.x + sin(rot.y);
    l.z = -initial.z - trans.z - cos(rot.y);
    l.y =  initial.y + trans.y + sin(rot.x);

    /* Clear matrix stack */
    glLoadIdentity();
    
    /* Apply transformation */
    gluLookAt(initial.x + trans.x, initial.y + trans.y, -initial.z - trans.z,
              l.x, l.y, l.z,
              up.x, up.y, up.z);

}

void Camera::moveUp()
{
}

void Camera::moveDown()
{
}

void Camera::moveForward()
{
}

void Camera::moveBackward()
{
}

void Camera::turnLeft()
{
}

void Camera::turnRight()
{
}

void Camera::turnUp()
{
}

void Camera::turnDown()
{
}

void Camera::setTurnSpeed(float s)
{
}

void Camera::setSpeed(float s)
{
}
