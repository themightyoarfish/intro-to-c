/**
 * Fighter.cpp
 *
 */
#include <iostream>


#include "Fighter.hpp"

namespace asteroids
{

void Fighter::shoot()
{
   Bullet* b = new Bullet(m_position, m_xAxis);
   b->start();
   m_bullets.push_back(b);
}


void Fighter::render()
{
    // Render the fighter
    TexturedMesh::render();
   
    std::vector<Bullet*>::iterator begin = m_bullets.begin();
    while (begin != m_bullets.end()) 
    {
       if ((*begin)->isAlive()) (*begin)->render();
       else m_bullets.erase(begin);
       begin++;
    }
}

} // namespace asteroids
