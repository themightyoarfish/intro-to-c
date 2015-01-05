/**
 * @file
 * Fighter.hpp
 */


#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_

#include "TexturedMesh.hpp"
#ifdef __APPLE__
#include <OpenGL/glu.h>	
#include <glut.h>	
#else
#include <GL/glu.h>	
#include <GL/glut.h>	
#endif
#include <vector>	
#include "Bullet.hpp"

namespace asteroids
{

/**
 * @brief   Represents a fighter that can shoot bullets.
 */
class Fighter : public TexturedMesh
{

public:
    /**
     * @brief Adds a bullet to the fighter's vector of bullets.
     */
	void shoot();
    
    /**
     * @brief Renders the fighter and calls the bullets' render method.
     */
   	void render();

private:
    // TODO: Add a vector with the bullets this fighter has shot.
	

};

} // namespace asteroids

#endif /* FIGHTER_HPP_ */

