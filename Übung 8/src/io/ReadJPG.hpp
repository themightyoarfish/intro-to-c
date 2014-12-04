/**
 * @file ReadJPG.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#ifndef READJPG_H

#define READJPG_H

#include "BitmapReader.hpp"
#include <string>

using std::string;

namespace asteroids 
{
   /**
    * @class ReadJPG 
    * @brief Reads a jpg image into a char array.
    *
    * Most of the implementation is stolen from http://stackoverflow.com/a/22463461/2397253
    */
   class ReadJPG : public BitmapReader
   {
      public:
         /**
          * @brief Constructor. Sets the Reader to read from a file.
          * @param filename The jpeg file to read from.
          */
         ReadJPG(const string& filename);

         /**
          * @brief Empty destructor. Deallocation of the image buffer must be
          * taken care of by client.
          */
         ~ReadJPG();
   };
} /* namespace asteroids */

#endif /* end of include guard: READJPG_H */
