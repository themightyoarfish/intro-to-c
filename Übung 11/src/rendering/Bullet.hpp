/**
 * @file
 * Bullet.hpp
 *
 */

#ifndef BULLET_HPP_
#define BULLET_HPP_

#include "TriangleMesh.hpp"

#ifdef __APPLE__
#include <OpenGL/glu.h>
#include <glut.h>
#else
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <thread>
#include <chrono>

namespace asteroids
{

/**
 * @brief Renders a Bullet
 */
class Bullet: public TriangleMesh
{

public:

    /**
     * @brief Contructor. Build a bullet on the given Fighter's
     *                      position. The bullet will move on the
     *                      given axis.
     * @param   fighter_position   Position of the fighter that shoots this bullet
     * @param   fighter_axis   Axis the bullet will move on
     */
    Bullet(Vertex<float> fighter_position, Vertex<float> fighter_axis);

    ~Bullet();

    /**
     * @brief Moves the bullet until it's lifetime is over.
     */
	void run();

	/**
	 * @brief Starts bullet movement
	 */
	void start();


	/*
	 * @brief Stops bullet movement
     */
	void stop();
    
    /**
     * @brief Renders the bullet via glutSolidSphere.
     */
	void render();

    /**
     * @brief Returns the status of this bullet.
     * @return false, if the bullet's lifetime is over and true otherwise
     */
	bool isAlive();

private:
    // Lifetime, i.e., how many timesteps the bullet visible
	static const int m_lifetime;
	static const float m_bulletSpeed;

	// True, if the bullet's lifetime isn't over yet
	bool m_alive;

	// Flight direction of the bullet
    Vertex<float> m_fighterAxis;

    std::thread* m_thread;
};

} // namespace asteroids


#endif /* BULLET_HPP_ */
