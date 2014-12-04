#ifndef TRANSFORMABLE_DILCYMZ4

#define TRANSFORMABLE_DILCYMZ4

#include "Renderable.hpp"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

namespace asteroids

{
   /**
    * @class Transformable
    * @brief Abstract base class for <tt>Mesh</tt>es which can be moved &
    * rotated.
    */
   class Transformable : public Renderable
   {
      public:
         /**
          * @brief   Rotate the Transformable
          * @param axis axis of rotation
          * @param speed speed of rotation
          */
         virtual void rotate(int axis, float speed) = 0;

         /**
          * @brief   Move the Transformable along acis
          * @param axis axis to move along
          * @param speed speed of movement
          */
         virtual void move(int axis, float speed) = 0;

      protected:
         /**
          * @brief Array containing the transformation matrix.
          */
         float m_transformation[16];

         /**
          * @brief Method to compute the transformation matrix.
          */
         virtual void computeMatrix() = 0;
   };
}

#endif /* end of include guard: TRANSFORMABLE_DILCYMZ4 */
