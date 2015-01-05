/**
 * Fighter.cpp
 *
 */


#include "Fighter.hpp"

namespace asteroids
{

void Fighter::shoot()
{
    // TODO:
    // Create a new bullet with this fighter's position an x-Axis
    // Start a new thread, move the bullet
    // Add it to this fighter's vector of bullets
}


void Fighter::render()
{
    // Render the fighter
    TexturedMesh::render();
   
    // Implement list rendering, remove inactive instances
    // from vector.
}

} // namespace asteroids
