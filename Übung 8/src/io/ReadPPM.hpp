/**
 * @file ReadPPM.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#ifndef READPPM_H

#define READPPM_H

#include "BitmapReader.hpp"
#include <fstream>

using std::ifstream;

namespace asteroids 
{
   class ReadPPM : public BitmapReader
   {
      private:
         void readline(ifstream& stream, char* buffer, const int bufsize);
      public:
         ReadPPM(const std::string& filename);
         ~ReadPPM();
   };
} /* namespace asteroids */

#endif /* end of include guard: READPPM_H */
