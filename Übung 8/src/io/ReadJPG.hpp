/**
 * @file ReadJPG.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#ifndef READJPG_H

#define READJPG_H

#include "BitmapReader.hpp"
#include <string>

namespace asteroids 
{
   class ReadJPG : public BitmapReader
   {
      public:
         ReadJPG(const std::string& filename);
         ~ReadJPG();
   };
} /* namespace asteroids */

#endif /* end of include guard: READJPG_H */
