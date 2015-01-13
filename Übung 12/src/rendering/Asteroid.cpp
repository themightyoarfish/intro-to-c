#include "Asteroid.hpp"
#include "math/Randomizer.hpp"

namespace asteroids
{

Asteroid::Asteroid(TexturedMesh* mesh, Vertex<float> start_position, float scale)
{   
    // Save initial position
    m_position  = start_position;
    m_mesh      = mesh;
    m_scale     = scale;

    //Randomize Heading
    rotate(PITCH, Randomizer::instance()->getRandomNumber(0, 3.14159265));
    rotate(YAW  , Randomizer::instance()->getRandomNumber(0, 3.14159265));
    rotate(ROLL  , Randomizer::instance()->getRandomNumber(0, 3.14159265));

}


Asteroid& Asteroid::operator=( Asteroid& other )
{
	if(&other != this)
	{
		m_position = other.m_position;
		m_mesh = new TexturedMesh(*other.m_mesh);
		m_scale = other.m_scale;
	}
	return *this;
}


Asteroid::Asteroid(const Asteroid& other)
{
	m_position = other.m_position;
	m_mesh = new TexturedMesh(*other.m_mesh);
	m_scale = other.m_scale;
}

Asteroid::Asteroid()
{
    m_mesh = 0;
}


void Asteroid::render()
{
    // Compute transformation matrix
    computeMatrix();

    // Push matrix and set transformation and scaling
    glPushMatrix();
    glMultMatrixf(m_transformation);
    glScalef(m_scale, m_scale, m_scale);
    if(m_mesh)
    {
        m_mesh->render();
    }
    glPopMatrix();
}

Asteroid::~Asteroid()
{
    if (m_mesh)
    {
         //delete m_mesh;
    }
}

} // namespace asteroids
