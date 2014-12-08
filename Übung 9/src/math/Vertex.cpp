#include "Vertex.hpp"
#include <stdio.h>
#include <string>
#include "exceptions/DivisionByZeroException.hpp"
#include "exceptions/OutOfBoundsException.hpp"

namespace asteroids {
    
Vertex::Vertex()
{
	// Default values
	x = y = z = 0.0;
}


Vertex::Vertex(float _x, float _y, float _z)
{
	// Set the given values
	x = _x;
	y = _y;
	z = _z; 
}

void Vertex::normalize()
{
	// Normalize the vector
	float mag2 = x * x + y * y + z * z;
	if (fabs(mag2 - 1.0f) > TOLERANCE)
	{
		float mag = sqrt(mag2);
      // to_string is c++ 11
      if (mag == .0f) 
         throw DivisionByZeroException("Vector to normalise has 0 length.");
      x /= mag;
      y /= mag;
      z /= mag;
   }
}

Vertex Vertex::operator+(const Vertex vec) const
{
   // Add value to value
   float tx = x + vec.x;
   float ty = y + vec.y;
   float tz = z + vec.z;
   return Vertex(tx, ty, tz);
}

Vertex Vertex::operator-(const Vertex vec) const
{
   // Subtract value from value
   float tx = x - vec.x;
   float ty = y - vec.y;
   float tz = z - vec.z;
   return Vertex(tx, ty, tz);
}


float Vertex::operator[](const int &index) const
{

   // Get the wanted value
   if(index == 0)
   {
      return x;
   }

   if(index == 1)
   {
      return y;
   }

   if(index == 2)
   {
      return z;
   }

   // to_string is c++ 11
   throw OutOfBoundsException("Wrong index " + std::to_string(index));
}


float& Vertex::operator[](const int &index)
{

   if(index == 0)
   {
      return x;
   }

   if(index == 1)
   {
      return y;
   }

   if(index == 2)
   {
      return z;
   }

   throw OutOfBoundsException("Wrong index " + std::to_string(index));
}




float Vertex::operator*(const Vertex vec) const
{
   // Calculate the result
   return (x * vec.x + y * vec.y + z * vec.z); 
}

Vertex Vertex::operator*(float scale) const
{
   // Calculate the result
   float tx = x * scale;
   float ty = y * scale;
   float tz = z * scale;
   return Vertex(tx, ty, tz);
}

void Vertex::operator+=(Vertex v)
{
   // Add value to value
   x += v.x;
   y += v.y;
   z += v.z;
}

} // namespace cpp2014
