#include <stdio.h>
#include <cassert>

namespace asteroids
{

template<typename T>
Vertex<T>::Vertex()
{
	// Default values
	x = y = z = 0.0;
}

template<typename T>
Vertex<T>::Vertex(T _x, T _y, T _z)
{
	// Set the given values
	x = _x;
	y = _y;
	z = _z; 
}


template<typename T>
T  Vertex<T>::dist(const Vertex<T> &vec)
{

  // Calculate the distance
  Vertex<T> dist(x - vec[0], y - vec[1], z - vec[2]);
  T mag = dist.x * dist.x + dist.y * dist.y + dist.z * dist.z;
  if (fabs(mag - 1.0f) > TOLERANCE)
  { 
	return sqrt(mag);
  }
  else
  {
	return 1.0f;
  }
}

template<typename T>
Vertex<T> Vertex<T>::cross(const Vertex<T> &b)
{
  // Calculate the cross product
  float tx = y * b[2] - z * b[1];
  float ty = z * b[0] - x * b[2];
  float tz = x * b[1] - y * b[0];

  return Vertex<T>(tx, ty, tz);  
}

template<typename T>
void Vertex<T>::normalize()
{
	// Normalize the vector
	T mag2 = x * x + y * y + z * z;
	if (fabs(mag2 - 1.0f) > TOLERANCE)
	{
		T mag = sqrt(mag2);
		x /= mag;
		y /= mag;
		z /= mag;
	}
}

template<typename T>
Vertex<T> Vertex<T>::operator+(const Vertex<T> vec) const
{
	// Add value to value
	T tx = x + vec.x;
	T ty = y + vec.y;
	T tz = z + vec.z;
	return Vertex<T>(tx, ty, tz);
}

template<typename T>
Vertex<T> Vertex<T>::operator-(const Vertex<T> vec) const
{
	// Subtract value from value
	T tx = x - vec.x;
	T ty = y - vec.y;
	T tz = z - vec.z;
	return Vertex<T>(tx, ty, tz);
}

template<typename T>
T Vertex<T>::operator[](const int &index) const
{
	assert(index < 3);
	
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

	return 0;
}

template<typename T>
T Vertex<T>::operator*(const Vertex<T> vec) const
{
  // Calculate the result
  return (x * vec.x + y * vec.y + z * vec.z); 
}

template<typename T>
Vertex<T> Vertex<T>::operator*(T scale) const
{
	// Calculate the result
	T tx = x * scale;
	T ty = y * scale;
	T tz = z * scale;
	return Vertex<T>(tx, ty, tz);
}

template<typename T>
void Vertex<T>::operator+=(Vertex v)
{
	// Add value to value
	x += v.x;
	y += v.y;
	z += v.z;
}

}
