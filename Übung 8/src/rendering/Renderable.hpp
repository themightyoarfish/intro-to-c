/**
 * @file Renderable.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 04.12.2014
 */

#ifndef RENDERABLE_KG6LA0OJ

#define RENDERABLE_KG6LA0OJ

namespace asteroids {

   /**
    * @class Renderable
    * @brief Abstract class to represent something which can be rendered on screen.
    */
   class Renderable {

      /**
       * @brief Render this object (pure virtual)
       */
      virtual void render () = 0;
   };
}

#endif /* end of include guard: RENDERABLE_KG6LA0OJ */
