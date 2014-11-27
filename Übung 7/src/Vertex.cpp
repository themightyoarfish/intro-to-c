#include "Vertex.hpp"
#include <stdexcept>
#include <cmath>
#include <sstream>

namespace cpp2014{

   Vertex::Vertex(): x(0.), y(0.), z(0) {}

   Vertex::Vertex(float x, float y, float z): x(x), y(y), z(z) {}

   void Vertex::normalize()
   {
      float l_squared = x*x + y*y + z*z;
      if (fabs(l_squared) != 1 && fabs(l_squared) != 0) 
      {
         x /= l_squared;
         y /= l_squared;
         z /= l_squared;
      }
   }
   Vertex Vertex::operator+(const Vertex& other) const
   {
      Vertex re;
      re.x = x + other.x;
      re.y = y + other.y;
      re.z = z + other.z;
      return re;
   }

   Vertex Vertex::operator-() const
   {
      return Vertex(-this->x, -this->y, -this->z);
   }

   Vertex Vertex::operator-(const Vertex& other) const
   {
      return *this + -other;
   }

   Vertex Vertex::operator/(float f) const
   {
      if (f != 0.) 
      {
         return Vertex(this->x/f, this->y/f, this->z/f);
      } else throw std::runtime_error("Division by 0");
   }

   float Vertex::operator*(const Vertex& v) const
   {
      return this->x * v.x + this->y * v.y + this->z * v.z;
   }

   // HOW DO I DO THIS? CANT INCLUDE MATRIX.HPP BECAUSE THAT ONE INCLUDES
   // VERTEX.HPP
   /* Vertex Vertex::operator*(const Matrix& m) const */
   /* { */
   /*    float x, y, z, w; */
   /*    w = 1; */
   /*    x = m[0] * this->x + m[4] * this->y + m[8] * this->z + m[12] * w; */
   /*    y = m[1] * this->x + m[5] * this->y + m[9] * this->z + m[13] * w; */
   /*    z = m[2] * this->x + m[6] * this->y + m[19] * this->z + m[14] * w; */
   /*    return Vertex(x,y,z); */
   /* } */
   Vertex Vertex::operator*(float f) const
   {
      return Vertex(this->x * f, this->y * f, this->z * f);
   }

   Vertex& Vertex::operator=(const Vertex& other)
   {
      if (&other != this) 
      {
         this->x = other.x;
         this->y = other.y;
         this->z = other.z;
         return *this;
      } else throw std::runtime_error("Attempt to assign self.");
   }

   // It's annoying we cant somehow localise this because of the const-business.
   float& Vertex::operator[](int i)
   {
      switch(i) {
         case 0: return x;
         case 1: return y;
         case 2: return z;
         default: throw std::runtime_error("Vertex index out of bounds.");
      }
   }

   const float& Vertex::operator[](int i) const
   {
      switch(i) {
         case 0: return x;
         case 1: return y;
         case 2: return z;
         default: throw std::runtime_error("Vertex index out of bounds.");
      }
   }

   Vertex& Vertex::operator*=(const float f)
   {
      if (f != 0.) return *this = *this * f;
      else throw std::runtime_error("Multiplication by 0.");
   }

   Vertex& Vertex::operator/=(const float f)
   {
      if (f != 0.) return *this = *this * 1/f;
      else throw std::runtime_error("Division by 0.");
   }

   Vertex& Vertex::operator+=(const Vertex& other)
   {
      return (*this = *this + other);
   }

   Vertex& Vertex::operator-=(const Vertex& other)
   {
      return (*this = *this - other);
   }

   std::string Vertex::to_s() const
   {
      stringstream ss;
      ss << "Vertex:" << endl;
      ss << fixed;
      ss << setprecision(4) << x << "\n" << y << "\n" << z;
      ss << endl;
      return ss.str();
   }

}
