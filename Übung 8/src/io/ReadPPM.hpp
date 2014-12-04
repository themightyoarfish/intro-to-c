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
   /**
    * @enum PPMTYPE
    * @brief Constants for PPM types.
    */
   enum PPMTYPE { 
      P3, ///< Ascii file
      P6,  ///< Binary file
      UNDEF ///< Unknown type (should lead to error)
   };

   /**
    * @class ReadPPM 
    * @brief A reader for ppm images.
    */
   class ReadPPM : public BitmapReader
   {
      private:
         /**
          * @brief Reads linewise from a ppm file as long as the current line starts
          * with a '#'. 
          *
          * After the method has run, the stream's current line will
          * be the first non-comment line after the position for which the
          * method was called.
          * @param stream The input file stream to read from.
          * @param buffer Char buffer to place the bytes or chars in.
          * @param bufsize The length of the buffer.
          */
         void readFirstNonCommentLine(ifstream& stream, char* buffer, const int bufsize);

         /**
          * @brief Parses a ppm header. Sets the members <tt>m_width</tt>,
          * <tt>m_height</tt> and reads the magic number.
          * @param filename The name of the file.
          * @return The type of the file (binary or ascii). One of
          * <tt>PPMTYPE</tt>
          * @see ReadPPM::PPMTYPE
          */
         PPMTYPE readHeader(const std::string& filename);

         /**
          * The position right after the header. Seeking to this position and
          * then reading will read everything except the header.
          */
         ifstream::pos_type end_header;

         /**
          * @brief Read an ascii ppm file.
          * @param filename The name of the file.
          */
         void readP3(const std::string& filename);

         /**
          * @brief Read a binary ppm file.
          * @param filename The name of the file.
          */
         void readP6(const std::string& filename);
      public:

         /**
          * @brief Construct a PPM reader to read from a given file.
          * @param filename The name of the file.
          */
         ReadPPM(const std::string& filename);

         /**
          * @brief Empty destructor. Deallocation of the image buffer must be
          * taken are of by the client.
          */
         ~ReadPPM();
   };
} /* namespace asteroids */

#endif /* end of include guard: READPPM_H */
