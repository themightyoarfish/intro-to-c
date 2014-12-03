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
   class Transformable : public Renderable
   {
      public:
         /**
          * @brief   Rotate the Transformable
          * @param axis axis of rotation
          * @param speed speed of rotation
          */
         virtual void rotate(int axis, float speed);

         /**
          * @brief   Move the Transformable along acis
          * @param axis axis to move along
          * @param speed speed of movement
          */
         virtual void move(int axis, float speed);


      protected:
         float m_transformation[16];
         void computeMatrix();
   };
}

#endif /* end of include guard: TRANSFORMABLE_DILCYMZ4 */
