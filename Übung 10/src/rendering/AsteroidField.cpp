#include "AsteroidField.hpp"
#include "math/Randomizer.hpp"
#include "rendering/Asteroid.hpp"

namespace asteroids
{


AsteroidField::AsteroidField(int quantity, string basePath) :
    m_basePath(basePath)
{
 	// Generate asteroids
      #include <iostream>
   std::cout << "quantity=" << quantity << std::endl;
	for(int i = 0; i < quantity; i++)
	{
	   TriangleMesh* mesh = TriangleMeshFactory::instance().getMesh(m_basePath + "asteroid.3ds");
      asteroids.insert(Asteroid(mesh,Randomizer::instance()->getRandomVertex(2500.),Randomizer::instance()->getRandomNumber(1.,5.)));
	}

}

AsteroidField::~AsteroidField()
{
    // TODO: Delete all asteroids
}


static void renderAstroid(Asteroid a)
{
   a.render();
}
void AsteroidField::render()
{
   asteroids.for_each(renderAstroid);
}


}
