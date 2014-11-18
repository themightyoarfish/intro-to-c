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
const double PH = 1.57079632;
void Camera::Init(float x, float y, float z)
{
   vector up =  { .x = 0, .y = 1, .z = 0 };
   this->up = up;
   vector trans =  { .x = 0, .y = 0, .z = 0 };
   this->trans = trans;
   vector initial =  { .x = x, .y = y, .z = z };
   this->initial = initial;
   vector rot =  { .x = 0, .y = 0, .z = 0 };
   this->rot = rot;
   vector l =  { .x = 0, . y = 0, .z = -1 };
   this->l = l;
   turn_speed = .05;
   move_speed = 5.;
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

void Camera::print_camera()
{
    std::cout << "Current camera parameters: \n";
    std::cout << "Position: " << trans.x << " " << trans.y << " " << trans.z << std::endl;
    std::cout << "Rotation: " << rot.x << " " << rot.y << " " << rot.z << std::endl;
    std::cout << "LookAt  : " << l.x << " " << l.y << " " << l.z << std::endl;
    std::cout << "ViewUp  : " << up.x << " " << up.y << " " << up.z << std::endl;
}
void Camera::moveUp()
{
   trans.y += move_speed;
}

void Camera::moveDown()
{
   trans.y -= move_speed;
}

void Camera::moveForward()
{
   trans.x += move_speed * sin(rot.y);
   trans.z += move_speed * cos(rot.y);
}

void Camera::moveBackward()
{
   trans.x -= move_speed * sin(rot.y);
   trans.z -= move_speed * cos(rot.y);
}

void Camera::turnLeft()
{
   rot.y -= turn_speed;
}

void Camera::turnRight()
{
   rot.y += turn_speed;
}

void Camera::turnUp()
{
   if(rot.x < PH)
   {
      rot.x += turn_speed;
   }
}

void Camera::turnDown()
{
   if(rot.x < PH)
   {
      rot.x -= turn_speed;
   }
}

void Camera::setTurnSpeed(float s)
{
}

void Camera::setSpeed(float s)
{
}
