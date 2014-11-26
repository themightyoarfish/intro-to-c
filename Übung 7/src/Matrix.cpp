/*
 * Matrix.hpp
 *
 *  @date 26.08.2008
 *  @author Thomas Wiemann (twiemann@uos.de)
 */
#include "Matrix.hpp"
#include <sstream>
#include <stdexcept>

namespace cpp2014
{

   Matrix::Matrix()
   {
      for(int i = 0; i < 16; i++) m[i] = 0;
      m[0] = m[5] = m[10] = m[15] = 1;
   }


   Matrix::Matrix(float* matrix)
   {
      for(int i = 0; i < 16; i++) m[i] = matrix[i];
   }


   Matrix::Matrix(const Matrix& other)
   {
      for(int i = 0; i < 16; i++) m[i] = other[i];
   }

   Matrix::Matrix(Vertex axis, float angle)
   {
      // Check for gimbal lock
      if(fabs(angle) < 0.0001)
      {

         bool invert_z = axis[2] < 0;

         //Angle to yz-plane
         float pitch = atan2(axis[2], axis[0]) - M_PI_2;
         if(pitch < 0.0f) pitch += 2.0f * M_PI;

         if(axis[0] == 0.0f && axis[2] == 0.0) pitch = 0.0f;

         //Transform axis into yz-plane
         axis[0] =  axis[0] * cos(pitch) + axis[2] * sin(pitch);
         axis[2] = -axis[0] * sin(pitch) + axis[2] * cos(pitch);

         //Angle to y-Axis
         float yaw = atan2(axis[1], axis[2]);
         if(yaw < 0) yaw += 2 * M_PI;

         Matrix m1, m2, m3;

         if(invert_z) yaw = -yaw;

         cout << "YAW: " << yaw << " PITCH: " << pitch << endl;

         if(fabs(yaw)   > 0.0001){
            m2 = Matrix(Vertex(1.0, 0.0, 0.0), yaw);
            m3 = m3 * m2;
         }

         if(fabs(pitch) > 0.0001){
            m1 = Matrix(Vertex(0.0, 1.0, 0.0), pitch);
            m3 = m3 * m1;
         }

         for(int i = 0; i < 16; i++) m[i] = m3[i];

      } else {
         float c = cos(angle);
         float s = sin(angle);
         float t = 1.0f - c;
         float tmp1, tmp2;

         // Normalize axis
         Vertex a(axis);
         a.normalize();

         m[ 0] = c + a[0] * a[0] * t;
         m[ 5] = c + a[1] * a[1] * t;
         m[10] = c + a[2] * a[2] * t;

         tmp1 = a[0] * a[1] * t;
         tmp2 = a[2] * s;
         m[ 4] = tmp1 + tmp2;
         m[ 1] = tmp1 - tmp2;

         tmp1 = a[0] * a[2] * t;
         tmp2 = a[1] * s;
         m[ 8] = tmp1 - tmp2;
         m[ 2] = tmp1 + tmp2;

         tmp1 = a[1] * a[2] * t;
         tmp2 = a[0] * s;
         m[ 9] = tmp1 + tmp2;
         m[ 6] = tmp1 - tmp2;

         m[ 3] = m[ 7] = m[11] = 0.0;
         m[12] = m[13] = m[14] = 0.0;
         m[15] = 1.0;
      }
   }


   Matrix::Matrix(const Vertex &position, const Vertex &angles)
   {
      float sx = sin(angles[0]);
      float cx = cos(angles[0]);
      float sy = sin(angles[1]);
      float cy = cos(angles[1]);
      float sz = sin(angles[2]);
      float cz = cos(angles[2]);

      m[0]  = cy*cz;
      m[1]  = sx*sy*cz + cx*sz;
      m[2]  = -cx*sy*cz + sx*sz;
      m[3]  = 0.0;
      m[4]  = -cy*sz;
      m[5]  = -sx*sy*sz + cx*cz;
      m[6]  = cx*sy*sz + sx*cz;
      m[7]  = 0.0;
      m[8]  = sy;
      m[9]  = -sx*cy;
      m[10] = cx*cy;

      m[11] = 0.0;

      m[12] = position[0];
      m[13] = position[1];
      m[14] = position[2];
      m[15] = 1;
   }

   Matrix::~Matrix() { }

   /**
    * @brief	Transposes the current matrix
    */
   void Matrix::transpose()
   {
      float m_tmp[16];
      m_tmp[0]  = m[0];
      m_tmp[4]  = m[1];
      m_tmp[8]  = m[2];
      m_tmp[12] = m[3];
      m_tmp[1]  = m[4];
      m_tmp[5]  = m[5];
      m_tmp[9]  = m[6];
      m_tmp[13] = m[7];
      m_tmp[2]  = m[8];
      m_tmp[6]  = m[9];
      m_tmp[10] = m[10];
      m_tmp[14] = m[11];
      m_tmp[3]  = m[12];
      m_tmp[7]  = m[13];
      m_tmp[11] = m[14];
      m_tmp[15] = m[15];
      for(int i = 0; i < 16; i++) m[i] = m_tmp[i];
   }

   /**
    * @brief	Computes an Euler representation (x, y, z) plus three
    * 			rotation values in rad. Rotations are with respect to
    * 			the x, y, z axes.
    */
   void Matrix::toPostionAngle(float pose[6])
   {
      if(pose != 0){
         float _trX, _trY;
         if(m[0] > 0.0) {
            pose[4] = asin(m[8]);
         } else {
            pose[4] = (float)M_PI - asin(m[8]);
         }
         // rPosTheta[1] =  asin( m[8]);      // Calculate Y-axis angle

         float  C    =  cos( pose[4] );
         if ( fabs( C ) > 0.005 )  {          // Gimball lock?
            _trX      =  m[10] / C;          // No, so get X-axis angle
            _trY      =  -m[9] / C;
            pose[3]  = atan2( _trY, _trX );
            _trX      =  m[0] / C;           // Get Z-axis angle
            _trY      = -m[4] / C;
            pose[5]  = atan2( _trY, _trX );
         } else {                             // Gimball lock has occurred
            pose[3] = 0.0;                   // Set X-axis angle to zero
            _trX      =  m[5];  //1          // And calculate Z-axis angle
            _trY      =  m[1];  //2
            pose[5]  = atan2( _trY, _trX );
         }

         pose[0] = m[12];
         pose[1] = m[13];
         pose[2] = m[14];
      }
   }


   float Matrix::det()
   {
      float det, result = 0, i = 1.0;
      float Msub3[9];
      int    n;
      for ( n = 0; n < 4; n++, i *= -1.0 ) {
         submat( Msub3, 0, n );
         det     = det3( Msub3 );
         result += m[n] * det * i;
      }
      return( result );
   }

   Matrix Matrix::inv(bool& success)
   {
      Matrix Mout;
      float  mdet = det();
      if ( fabs( mdet ) < 0.00000000000005 ) {
         cout << "Error matrix inverting! " << mdet << endl;
         return Mout;
      }
      float  mtemp[9];
      int     i, j, sign;
      for ( i = 0; i < 4; i++ ) {
         for ( j = 0; j < 4; j++ ) {
            sign = 1 - ( (i +j) % 2 ) * 2;
            submat( mtemp, i, j );
            Mout[i+j*4] = ( det3( mtemp ) * sign ) / mdet;
         }
      }
      return Mout;
   }


   /**
    * @brief   Returns a sub matrix without row \ref i and column \ref j.
    */
   void Matrix::submat(float* submat, int i, int j)
   {
      int di, dj, si, sj;
      // loop through 3x3 submatrix
      for( di = 0; di < 3; di ++ ) {
         for( dj = 0; dj < 3; dj ++ ) {
            // map 3x3 element (destination) to 4x4 element (source)
            si = di + ( ( di >= i ) ? 1 : 0 );
            sj = dj + ( ( dj >= j ) ? 1 : 0 );
            // copy element
            submat[di * 3 + dj] = m[si * 4 + sj];
         }
      }
   }

   /**
    * @brief    Calculates the determinant of a 3x3 matrix
    *
    * @param    M  input 3x3 matrix
    * @return   determinant of input matrix
    */
   float Matrix::det3( const float *M )
   {
      float det;
      det = (double)(  M[0] * ( M[4]*M[8] - M[7]*M[5] )
            - M[1] * ( M[3]*M[8] - M[6]*M[5] )
            + M[2] * ( M[3]*M[7] - M[6]*M[4] ));
      return ( det );
   }


   void Matrix::scale(float f)
   {
      if (f != 0.0) 
      {
         int i;
         for (i = 0; i < 16; i++) m[i] *= f;
      }
   }
   float& Matrix::operator[](const int i)
   {
      return m[i];
   }

   const float& Matrix::operator[](const int i) const
   {
      return m[i];
   }

   Matrix Matrix::operator+(const Matrix& m) const
   {
      Matrix re;
      int i;
      for (i = 0; i < 15; i++) 
      {
         re[i] = this->m[i] + m[i];
      }
      return re;
   }

   Matrix Matrix::operator-() const
   {
      Matrix re;
      int i;
      for (i = 0; i < 15; i++) 
      {
         re[i] = -this->m[i];
      }
      return re;
   }

   Matrix Matrix::operator-(const Matrix& m) const
   {
      return *this + -m;
   }

   Matrix Matrix::operator*(const Matrix& m) const
   {
      Matrix re;
      int i,j,k;
      for (i = 0; i < 15; i++) re[i] = 0;
      for (i = 0; i < 4; i++) 
      {
         for (j = 0; j < 4; j++) 
         {
            for (k = 0; k < 4; k++) 
            {
               re[i*4+j] += this->m[i*4+k] * m[k*4+j];
            }
         }
      }
      return re;
   }

   Vertex Matrix::operator*(const Vertex& v) const
   {
      int x, y, z;
      x = y = z = 0;
      int i;
      for (i = 0; i < 4; i++) 
      {
         x += m[i] * v[0] + m[i + 1] * v[1] + m[i + 2] * v[2];
         y += m[4 + i] * v[0] + m[4 + i + 1] * v[1] + m[4 + i + 2] * v[2];
         z += m[8 + i] * v[0] + m[8 + i + 1] * v[1] + m[8 + i + 2] * v[2];
      }
      return Vertex(x,y,z);
   }

   Matrix& Matrix::operator*=(const float f)
   {
      this->scale(f);
      return *this;
   }

   float* Matrix::getData()
   {
      return m;
   }

   Matrix& Matrix::operator=(const Matrix& m)
   {
      if (&m != this) 
      {
         int i;
         for (i = 0; i < 15; i++) 
         {
            this->m[i] = m[i];
         }
         return *this;
      } else throw runtime_error("Attempt to assign self.");
   }

   Matrix& Matrix::operator*=(const Matrix& other)
   {
      *this = *this * other;
      return *this;
   }

   std::string Matrix::to_s()
   {
      stringstream ss;
      ss << "Matrix:" << endl;
      ss << fixed;
      for(int i = 0; i < 16; i++){
         ss << setprecision(4) << (*this)[i] << " ";
         if(i % 4 == 3) ss << " " <<  endl;
      }
      ss << endl;
      return ss.str();
   }
} // namespace cpp2014

