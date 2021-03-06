/*
 * Matrix.hpp
 *
 *  @date 26.08.2008
 *  @author Thomas Wiemann (twiemann@uos.de)
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Matrix.hpp"
#include "Vertex.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.141592654
#endif

using namespace std;

namespace cpp2014 {

   /**
    * @brief	A 4x4 matrix class definition for use with the provided
    * 			vertex types.
    */
   class Matrix {

      public:

         /**
          * @brief 	Default constructor. Initializes a identity matrix.
          */
         Matrix();

         /**
          * @brief	Initializes a matrix wit the given data array. Ensure
          * 			that the array has exactly 16 fields.
          */
         Matrix(float* matrix);
         /**
          * @brief 	Copy constructor.
          */
         Matrix(const Matrix& other);

         /**
          * @brief	Constructs a matrix from given axis and angle. Tries to
          * 			avoid a gimbal lock.
          */
         Matrix(Vertex axis, float angle);

         Matrix(const Vertex &position, const Vertex &angles);


         /**
          * Destructor
          */
         ~Matrix();


         /**
          * @brief	Matrix-Matrix multiplication. 
          * @param m The multiplicand.
          * @return This matrix.
          */
         Matrix operator*(const Matrix& m) const;

         /**
          * @brief Matrix-Vector multiplication. V is extended by a fourth zero
          * component.
          * @param v Vector, padded with zero at the end
          * @return The product
          */
         Vertex operator*(const Vertex& v) const;

         /**
          * @brief 	Matrix addition operator. Returns a new matrix
          * @param m Matrix to be assigned.
          * @return Thi matrix.
          */
         Matrix& operator=(const Matrix& m);

         /**
          * @brief 	Matrix addition operator
          * @param m Addend.
          * @return A new matrix which is the sum of this one and the addend.
          */
         Matrix operator+(const Matrix& m) const;

         /**
          * @brief Elementwisely subtract a matrix from this one.
          * @param m Subtrahend
          * @return The difference of this mtrix and the subtrahend.
          */
         Matrix operator-(const Matrix& m) const;

         /**
          * @brief Negate all entries in this matrix.
          * @return A new <tt>Matrix</tt> with entries negated.
          */
         Matrix operator-() const;

         /**
          * @brief	Matrix-Matrix multiplication (array based). Mainly
          * 			defined for compatibility with other math libs.
          * 			ensure that the used array has at least 16 elements
          * 			to avoid memory access violations.
          */

         /// TODO: DEFINE OPERATOR HERE!

         /**
          * THIS MAKES NO SENSE
          * @brief	Multiplication of Matrix and Vertex types
          */

         /* Matrix& operator*(const Vertex& v) const; */

         /**
          * @brief	Sets the given index of the Matrix's data field
          * 			to the provided value.
          *
          * @param	i		Field index of the matrix
          * @param	value	new value
          */
         void set(int i, float value);

         /**
          * @brief	Transposes the current matrix
          */
         void transpose();

         /**
          * @brief	Computes an Euler representation (x, y, z) plus three
          * 			rotation values in rad. Rotations are with respect to
          * 			the x, y, z axes.
          */
         void toPostionAngle(float pose[6]);


         /**
          * @brief	Matrix scaling with self assignment.
          */
         Matrix& operator*=(const float f);

         /**
          * @brief 	Matrix-Matrix multiplication with self assigment.
          */
         Matrix& operator*=(const Matrix& other);

         /**
          * @brief	Returns the internal data array. Unsafe. Will probably
          * 			removed in one of the next versions.
          */
         float* getData();

         /**
          * @brief	Indexed element (reading) access.
          */
         const float& operator[](const int i) const;

         /**
          * @brief  	Writeable index access
          */
         float& operator[](const int i);

         /**
          * @brief   Returns the matrix's determinant
          */
         float det();

         /** 
          * @brief   Inverts the matrix. Success is true if operation was successful
          */
         Matrix inv(bool& success);

         /**
          * Returns a tring representation of this object.
          * @return A <tt>string</tt> representation.
          */
         std::string to_s();

      private:

         /**
          * @brief   Returns a sub matrix without row \ref i and column \ref j.
          */
         void submat(float* submat, int i, int j);

         /**
          * @brief    Calculates the determinant of a 3x3 matrix
          *
          * @param    M  input 3x3 matrix
          * @return   determinant of input matrix
          */
         float det3( const float *M );

         /**
          * @brief	Scales the matrix elemnts by the given factor
          */
         void scale(float f);

         /// Internal data array
         float m[16];

   };


} // namespace cpp2014
#endif /* MATRIX_H_ */
