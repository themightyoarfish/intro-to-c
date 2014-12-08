/**
 *  @file Vertex.hpp
 *
 *  @date 05.12.2011
 *  @author Thomas Wiemann
 */

#ifndef __Vertex_HPP__
#define __Vertex_HPP__

#include <iostream>
#include <cmath>

#include "Global.hpp"

namespace asteroids
{

/**
 * @brief   Vector representation with three floats for OpenGL
 *
 */
class Vertex {

public:

	/**
	 * @brief   Construcs a default Vertex object
	 */
	Vertex();

	/**
	 * @brief   Construcs a Vertex object with given values
	 * @param x x-value
	 * @param y y-value
	 * @param z z-value
	 */
	Vertex(float x, float y, float z);

	/**
	 * @brief   Normalize a Vertex
	 */
	void normalize();
  
	/**
	 * @brief   Defines the vector addition
	 * @param vec vector
	 * @return vector
	 */
	Vertex operator+ (const Vertex vec) const;

	/**
	 * @brief   Defines the vector subtraction
	 * @param vec vector
	 * @return vector
	 */
	Vertex operator- (const Vertex vec) const;

	/**
	 * @brief   Construcs the scalar multiplication
	 * @param scale scalar
	 * @return vector
	 */
	Vertex operator* (const float scale) const;

	/**
	 * @brief   Defines the vector multiplication
	 * @param vec vector
	 * @return result (as a float)
	 */
	float  operator* (const Vertex vec) const;

	/**
	 * @brief   Defines the access to a Vertex value
	 * @param index wanted value
	 * @return vectorentry (as a float)
	 */
	float operator[] (const int& index) const;
    
    /**
     * @brief   Defines the access to a Vertex value
     * @param index wanted value
     * @return vectorentry (as a float)
     */
    float& operator[] (const int& index);

	/**
	 * @brief   Defines the fast notation of vector addition
	 * @param v vector
	 */
	void operator+= (Vertex v);

	/**
	 * @brief   The three values of a vector
	 */
	float x, y, z;
};
    
} // namespace cpp2014

#endif
