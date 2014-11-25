/**
 *  @file Quaternion.hpp
 *
 *  @date 05.12.2011
 *  @author Thomas Wiemann
 */

#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__

#include "Global.hpp"
#include "Vertex.hpp"

#include <iostream>
#include <cmath>

namespace cpp2014
{

/**
 * @brief   Quaternion representation for OpenGL. Based on: 
 *          http://gpwiki.org/index.php/OpenGL:Tutorials:Using_Quaternions_to_represent_rotation
 *
 */
class Quaternion {

public:

	/**
	 * @brief   Construcs a default quaternion object
	 */
	Quaternion();

	/**
	 * @brief   Destructor
	 */
	~Quaternion();

	/**
	 * @brief   Construcs (with fromAxis()) a quaternion with a given Vertex and an angle
	 * @param vec vector
	 * @param angle angle
	 */
	Quaternion(Vertex vec, float angle);

	/**
	 * @brief   Constructs a quaternion with three given values and an angle
	 * @param x x-value
	 * @param y y-value
	 * @param z z-value
	 * @param w angle
	 */
	Quaternion(float x, float y, float z, float w);

	/**
	 * @brief   Constructs a quaternion with a given float-pointer and an angle
	 * @param vec vector(pointer)
	 * @param w angle
	 */
	Quaternion(float* vec, float w);
  
	/**
	 * @brief   Calculates a quaternion with a given vector and an angle
	 * @param axis vector
	 * @param angle angle
	 */
	static Quaternion fromAxis(Vertex axis, float angle);
 
	/**
	 * @brief   Conjugates a quaternion
	 * @return quaternion (conjugate)
	 */
   Quaternion getConjugate() const;

   /**
    * @brief   Defines the quaternion-quaternion multiplication
    * @param rq quaternion
    * @return quaternion
    */
   Quaternion operator*(const Quaternion &rq) const;

   /**
    * @brief   Defines the vector-quaternion multiplication
    * @param vec vector
    * @return vector
    */
   Vertex operator*(const Vertex& vec) const;

   /**
    * @brief Returns a tring representation of this object.
    * @return A <tt>string</tt> representation.
    */
   std::string to_s() const;

private:

   /**
    * @brief   Value of angle, x, y and z
    */
   float w, x, y, z;
};

} // namespace cpp2014

#endif

