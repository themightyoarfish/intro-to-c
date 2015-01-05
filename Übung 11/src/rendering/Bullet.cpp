/**
 * Bullet.cpp
 *
 */

#include "Bullet.hpp"
#include <iostream>
#include <functional>
using namespace std;

namespace asteroids
{

   const int Bullet::m_lifetime = 9000;
   const float Bullet::m_bulletSpeed = 1.;

   Bullet::Bullet(Vertex<float> fighterPosition, Vertex<float> m_fighterAxis)
   {
      m_alive = false;
      this->m_fighterAxis = m_fighterAxis * -1; // xAxis points into wrong direcrion
      this->m_position = fighterPosition;
   }

   Bullet::~Bullet()
   {
      if (m_thread) m_thread->join(); // what happens if I delete before termination? Probably mayhem.
      delete m_thread;
   }

   bool Bullet::isAlive()
   {
      return m_alive;
   }

   void Bullet::stop()
   {
      if (m_thread) m_thread->join();
      m_alive = false;
   }

   void Bullet::start()
   {
      m_thread = new std::thread(&Bullet::run, this);
      m_alive = true;
   }

   void Bullet::run()
   {
      int i = 0;
      while (i++ < m_lifetime) 
      {
         m_position += m_fighterAxis * m_bulletSpeed;
         std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
      m_alive = false;
   }

   void Bullet::render()
   {
      // Compute transformation matrix
      computeMatrix();
      // Push old transformation of the OpenGL matrix stack and
      // start rendering the bullet in according to the
      // internal transformation matrix
      glPushMatrix();
      glMultMatrixf(m_transformation);
      glutSolidSphere(10,16,16);
      // Pop transformation matrix of this object
      // to restore the previous state of the OpenGL
      // matrix stack
      glPopMatrix();
   }

} // namespace asreroids

