#include "AsteroidField.hpp"
#include "math/Randomizer.hpp"
#include "rendering/Asteroid.hpp"

namespace asteroids
{

void deleteAsteroid(Asteroid* a);

AsteroidField::AsteroidField(int quantity, string basePath) :
    m_basePath(basePath)
{
 	// Generate asteroids
	for(int i = 0; i < quantity; i++)
	{
	   TexturedMesh* mesh = static_cast<TexturedMesh*>(TriangleMeshFactory::instance().getMesh(m_basePath + "asteroid.3ds"));
	   asteroids.insert(Asteroid(mesh,Randomizer::instance()->getRandomVertex(2500.),Randomizer::instance()->getRandomNumber(1.,5.)));
	}

}

AsteroidField::~AsteroidField()
{
	//asteroids.for_each(deleteAsteroid);
}

//void deleteAsteroid(Asteroid* a)
//{
//	delete a;
//}


void renderAstroid(Asteroid& a)
{
   a.render();
}

void AsteroidField::render()
{
   asteroids.for_each(renderAstroid);
}


}
