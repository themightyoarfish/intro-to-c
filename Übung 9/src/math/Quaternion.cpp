#include "Quaternion.hpp"
#include "exceptions/DivisionByZeroException.hpp"

namespace asteroids
{

   Quaternion::Quaternion()
   {
      // Default Quaternion
      x = 1.0;
      y = 0.0;
      z = 0.0;
      w = 0.0; 
   }

   Quaternion::~Quaternion()
   {
      // Do nothing
   }

   Quaternion::Quaternion(Vertex vec, float angle)
   {
      // Calculate the quaternion
      fromAxis(vec, angle);
   }

   Quaternion::Quaternion(float _x, float _y, float _z, float _angle)
   {
      // Set the values
      x = _x;
      y = _y;
      z = _z;
      w = _angle;
   }

   Quaternion::Quaternion(float* vec, float _w)
   {
      // Set the values
      x = vec[0];
      y = vec[1];
      z = vec[2];
      w = _w;
   }

   void Quaternion::fromAxis(Vertex axis, float angle)
   {
      float sinAngle;
      angle *= 0.5f;

      // Create a copy of the given vector and normalize the new vector
      Vertex vn(axis.x, axis.y, axis.z);
      try
      {
         vn.normalize();
      } catch (DivisionByZeroException &divex)
      {
         std::cout << divex.what() << std::endl;
      }

      // Calculate the sinus of the given angle
      sinAngle = sin(angle);

      // Get the quaternion
      x = (vn.x * sinAngle);
      y = (vn.y * sinAngle);
      z = (vn.z * sinAngle);
      w = cos(angle);
   }

   Quaternion Quaternion::getConjugate()
   {
      // Conjugate the given quaternion
      return Quaternion(-x, -y, -z, w);
   }


   Quaternion Quaternion::operator* (const Quaternion rq)
   {
      // Calculate the new quaternion
      return Quaternion(w * rq.x + x * rq.w + y * rq.z - z * rq.y,
            w * rq.y + y * rq.w + z * rq.x - x * rq.z,
            w * rq.z + z * rq.w + x * rq.y - y * rq.x,
            w * rq.w - x * rq.x - y * rq.y - z * rq.z);
   }

   Vertex Quaternion::operator* (Vertex vec)
   {
      // Copy the vector and normalize the new vector
      Vertex vn(vec);
      try
      {
         vn.normalize();
      } catch (DivisionByZeroException &divex)
      {
         std::cout << divex.what() << std::endl;
      }

      // Fill the first quaternion and...
      Quaternion vecQuat, resQuat;
      vecQuat.x = vn.x;
      vecQuat.y = vn.y;
      vecQuat.z = vn.z;
      vecQuat.w = 0.0f;

      // calculate the new quaternion
      resQuat = vecQuat * getConjugate();
      resQuat = *this * resQuat;
      return (Vertex(resQuat.x, resQuat.y, resQuat.z));
   }

}
