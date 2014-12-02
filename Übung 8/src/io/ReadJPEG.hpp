/**
 * @file ReadJPEG.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#ifndef READJPEG_H

#define READJPEG_H

#include "BitmapReader.hpp"
#include <string>

namespace asteroids 
{
   class ReadJPEG : public BitmapReader
   {
      public:
         ReadJPEG(const std::string& filename);
         ~ReadJPEG();
   };
} /* namespace asteroids */

#endif /* end of include guard: READJPEG_H */
