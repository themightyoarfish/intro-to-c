/**
 * Bullet.cpp
 *
 */

#include "Bullet.hpp"

namespace asteroids
{

Bullet::Bullet(Vertex<float> fighter_position, Vertex<float> m_fighterAxis)
{
    // TODO: Implement Ctor logic
}

Bullet::~Bullet()
{
	
}

bool Bullet::isAlive()
{
	return m_alive;
}

void Bullet::stop()
{
    // TODO: Implement thread stop logic
}

void Bullet::start()
{
	// TODO: Implement thread start logic
}

void Bullet::run()
{
    // RUN RUN RUN ...
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

