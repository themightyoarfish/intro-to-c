
namespace asteroids
{

template<typename T>
Quaternion<T>::Quaternion()
{
	// Default Quaternion
	x = 1.0;
	y = 0.0;
	z = 0.0;
	w = 0.0; 
}

template<typename T>
Quaternion<T>::~Quaternion()
{
	// Do nothing
}

template<typename T>
Quaternion<T>::Quaternion(Vertex<T> vec, T angle)
{
	// Calculate the quaternion
	fromAxis(vec, angle);
}

template<typename T>
Quaternion<T>::Quaternion(T _x, T _y, T _z, T _angle)
{
	// Set the values
	x = _x;
	y = _y;
	z = _z;
	w = _angle;
}

template<typename T>
Quaternion<T>::Quaternion(T* vec, T _w)
{
	// Set the values
	x = vec[0];
	y = vec[1];
	z = vec[2];
	w = _w;
}

template<typename T>
void Quaternion<T>::fromAxis(Vertex<T> axis, T angle)
{
	T sinAngle;
	angle *= 0.5f;

	// Create a copy of the given vector and normalize the new vector
	Vertex<T> vn(axis.x, axis.y, axis.z);
	vn.normalize();
 
	// Calculate the sinus of the given angle
	sinAngle = sin(angle);
 
	// Get the quaternion
	x = (vn.x * sinAngle);
	y = (vn.y * sinAngle);
	z = (vn.z * sinAngle);
	w = cos(angle);
}

template<typename T>
Quaternion<T> Quaternion<T>::getConjugate()
{
	// Conjugate the given quaternion
	return Quaternion(-x, -y, -z, w);
}

template<typename T>
Quaternion<T> Quaternion<T>::operator* (const Quaternion rq)
{
	// Calculate the new quaternion
	return Quaternion(w * rq.x + x * rq.w + y * rq.z - z * rq.y,
				w * rq.y + y * rq.w + z * rq.x - x * rq.z,
				w * rq.z + z * rq.w + x * rq.y - y * rq.x,
				w * rq.w - x * rq.x - y * rq.y - z * rq.z);
}

template<typename T>
Vertex<T> Quaternion<T>::operator* (Vertex<T> vec)
{
	// Copy the vector and normalize the new vector
	Vertex<T> vn(vec);
	vn.normalize();

	// Fill the first quaternion and...
	Quaternion<T> vecQuat, resQuat;
	vecQuat.x = vn.x;
	vecQuat.y = vn.y;
	vecQuat.z = vn.z;
	vecQuat.w = 0.0f;

	// calculate the new quaternion
	resQuat = vecQuat * getConjugate();
	resQuat = *this * resQuat;
  	return (Vertex<T>(resQuat.x, resQuat.y, resQuat.z));
}

} // namespace asteroids
