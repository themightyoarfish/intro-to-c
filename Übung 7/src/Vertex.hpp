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
#include <iomanip>

#include "Global.hpp"

using namespace std;

namespace cpp2014
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
          * @param   other Vertex to add to this one.
          * @return  The sum of the two.
          */
         Vertex operator+(const Vertex& other) const;

         /**
          * @brief   Defines the vector subtraction
          * @param   other Vertex to subtract from this one.
          * @return  The difference of the two.
          */
         Vertex operator-(const Vertex& other) const;

         /**
          * @brief Defines the negation.
          * @return A negated copy of this Vertex.
          */
         Vertex operator-() const;

         /**
          * @brief   Construcs the scalar division
          * @param   f scalar
          * @return  A scaled vector
          */
         Vertex operator/(float f) const;

         /**
          * @brief   Defines the scalar product
          * @param   v Vertex
          * @return  Scalar product (as a float)
          */
         float operator*(const Vertex& v) const;

         /**
          * @brief   Defines the scaling transformation
          * @param   f The scaling factor
          * @return  A scaled vector
          */
         Vertex operator*(float f) const;

         /**
          * @brief Assignment operator.
          * @param other Vertex whose state this Vertex will assume.
          * @return This Vertex
          */
         Vertex& operator=(const Vertex& other);

         /**
          * @brief   Defines the access to a Vertex value (readonly)
          * @param i Index of the wanted value
          * @return Const reference of entry at position i
          */
         const float& operator[](int i) const;

         /**
          * @brief   Defines the access to a Vertex value (read+write)
          * @param i Index wanted value
          * @return Reference to entry at position i
          */
         float& operator[](int i);

         /**
          * @brief Multiply and assign.
          * @param f Scaling factor
          * @return this Vertex
          */
         Vertex& operator*=(const float f);

         /**
          * @brief Divide and assign.
          * @param f Scaling factor
          * @return this Vertex
          */
         Vertex& operator/=(const float f);

         /**
          * @brief Add and assign.
          * @param other Vertex to add to this one
          * @return this Vertex
          */
         Vertex& operator+=(const Vertex& other);

         /**
          * @brief Subtract and assign.
          * @param other Vertex to subtract from this one
          * @return this Vertex
          */
         Vertex& operator-=(const Vertex& other);

         /**
          * @brief   The three values of a vector
          */
         float x, y, z;

         /**
          * Returns a tring representation of this object.
          * @return A <tt>string</tt> representation.
          */
         std::string to_s() const;
   };

} // namespace cpp2014

#endif
