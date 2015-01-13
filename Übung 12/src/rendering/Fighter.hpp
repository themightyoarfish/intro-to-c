/**
 * @file
 * Fighter.hpp
 */


#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_

#include "TexturedMesh.hpp"
#include <OpenGL/glu.h>	
#include <glut.h>	
#include <vector>	
#include <list>
#include <thread>

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
    
    /**
     * @brief Start the engine!
     */
    void run();
    
    /**
     * @brief Calculates the new course
     * @param dest current destination
     */
    void calculate(Vertex<float> dest);
    
    /**
     * @brief Getter-method for the autopilot state
     * @return the autopilot state
     */
    bool getAutopilotState();
    
    Fighter();
    
    /**
     * @brief Start the autopilot
     * @param list list with the coordinates
     */
    void navigate(std::list<Vertex<float> > list);
    
    
private:
    // A vector with the bullets this fighter has shot.
	list<Bullet*> m_bullets;
    
    // List with the coordinates for the autopilot
    std::list<Vertex<float> > m_navigationList;
    
    // Iterator for the list
    std::list<Vertex<float> >::iterator m_iter;
    
    // state of the autopilot
    bool m_autopilot;

    
    // A thread for auto piloting
    std::thread m_thread;

};

} // namespace asteroids

#endif /* FIGHTER_HPP_ */

