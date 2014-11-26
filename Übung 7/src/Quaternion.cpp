#include "Quaternion.hpp"
#include <sstream>

namespace cpp2014 {
   
   Quaternion::Quaternion(): w(0.), x(0.), y(0.), z(0.) {}


   Quaternion::Quaternion(Vertex vec, float angle)
   {
      *this = fromAxis(vec, angle);
   }

   Quaternion::Quaternion(float x, float y, float z, float w):
      w(w), x(x), y(y), z(z) {}

   Quaternion::Quaternion(float* vec, float w)
   {
      *this = fromAxis(Vertex(vec[0], vec[1], vec[2]), w);
   }
   Quaternion::~Quaternion() {}

   Quaternion Quaternion::fromAxis(Vertex axis, float angle)
   {
      angle /= 2;
      return Quaternion(axis[0] * sin(angle), axis[1] * sin(angle),
            axis[2] * sin(angle), cos(angle));
   }

   Quaternion Quaternion::getConjugate() const
   {
      return Quaternion(-x, -y, -z, w);
   }

   Quaternion Quaternion::operator*(const Quaternion& rq) const
   {
      return Quaternion(w * rq.x + x * rq.w + y * rq.z - z * rq.y,
            w * rq.y + y * rq.w + z * rq.x - x * rq.z,
            w * rq.z + z * rq.w + x * rq.y - y * rq.x,
            w * rq.w - x * rq.x - y * rq.y - z * rq.z);
   }

   Vertex Quaternion::operator*(const Vertex& vec) const
   {
      Vertex vn(vec);
      vn.normalize();

      Quaternion vecQuat, resQuat;
      vecQuat.x = vn[0];
      vecQuat.y = vn[1];
      vecQuat.z = vn[2];
      vecQuat.w = 0.0f;

      resQuat = vecQuat * getConjugate();
      resQuat = *this * resQuat;

      return Vertex(resQuat.x, resQuat.y, resQuat.z);
   }

   std::string Quaternion::to_s() const
   {
      stringstream ss;
      ss << "Quaternion:" << "\n" << x << "\n" << y << "\n" << z << "\n" << w << std::endl;
      return ss.str();
   }

}
