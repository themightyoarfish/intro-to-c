/**
 *  @file Starfield.hpp
 *
 *  @date 27.11.2011
 *  @author Tim Kühnen
 *  @author Dominik Feldschnieders
 *  @author Henning Strüber
 *  @author Thomas Wiemann
 */

#ifndef STARFIELD_HPP_
#define STARFIELD_HPP_

#include <cmath>
#include <algorithm>
#include <vector>

#include "Asteroid.hpp"
#include "FixedObject.hpp"
#include "math/Vertex.hpp"
#include "util/List.hpp"

using std::for_each;
using std::vector;
using std::generate;

namespace asteroids
{


/**
 * @brief   Representatio of an asteroid field
 */
class AsteroidField : public FixedObject
{
public:


	/**
	 * @brief   Creates an asteroid field with n asteroids in it
	 */
        AsteroidField(int n, string basePath = "");

	/**
	 * @brief   Dtor.
	 */
	virtual ~AsteroidField();

	/**
	 * @brief   Renders all asteroids
	 */
	void render();

private:

   /// The asteroids in the field
   List<Asteroid*> asteroids;

   /// Relative path to look for the asteroid model
   string m_basePath;
};

}

#endif

