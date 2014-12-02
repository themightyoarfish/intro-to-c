#ifndef TRANSFORMABLE_DILCYMZ4

#define TRANSFORMABLE_DILCYMZ4

#include "Renderable.hpp"
#include <OpenGL/gl.h>

namespace asteroids

{
   class Transformable : public Renderable
   {
      protected:
         float m_transformation[16];
         void computeMatrix();
   };
}

#endif /* end of include guard: TRANSFORMABLE_DILCYMZ4 */
