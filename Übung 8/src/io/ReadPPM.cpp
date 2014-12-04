/**
 * @file ReadPPM.cpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#include "ReadPPM.hpp"
#include <sstream>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ios;

namespace asteroids 
{
   ReadPPM::ReadPPM(const std::string& filename) 
   {
      cout << "ReadPPM: reading ppm file " << filename << endl;
      m_pixels = NULL; // in case shit hits the fan.
      m_height = m_width = 0;
      PPMTYPE type = readHeader(filename); // parse header and recognise file type
      // allocate only if needed.
      if (type != UNDEF) m_pixels = new unsigned char[m_width * m_height * 3];

      switch (type)
      {
         case P3:
            readP3(filename);
            break;
         case P6:
            readP6(filename);
            break;
         default:
            cerr << "ReadPPM: Error. Unknown PPM format." << endl;
            break;
      }
   }

   void ReadPPM::readFirstNonCommentLine(ifstream& stream, char* buffer, const int bufsize)
   {
      do { // read at least one line
         stream.getline(buffer, bufsize);
      } while(stream.good() && (buffer[0] == '#')); // continue while comment
      // now we have read the first non-comment line into the buffer.
   }

   PPMTYPE ReadPPM::readHeader(const string& filename)
   {
      ifstream file(filename.c_str());
      if (file.good()) 
      {
         /* ATTENTION. THIS ERRONEOUSLY ASSUMES THAT EVERYTHING IS SEPARATED BY
             NEWLINES, EXCEPT THE DIMENSIONS. NEED TO FIX THIS. */
         const int bufsize = 70; // Acc. to spec, lines should not be longer
         char buffer[bufsize]; // buffer to hold the line
         readFirstNonCommentLine(file, buffer, bufsize); // fill it
         string magic_number(buffer); // first line must contain magic number
         readFirstNonCommentLine(file, buffer, bufsize);
         string line(buffer); // next one must contain dimensions
         stringstream ss(line); ss >> m_width >> m_height; // get them out
         readFirstNonCommentLine(file, buffer, bufsize);
         file.getline(buffer, bufsize); // skip the max color value. Assume it's 255..
         end_header = file.tellg();
         file.close();

         cout << "ReadPPM: Parsed header of " << filename << ". width=" << m_width 
            <<" height=" << m_height << " magic number is " 
            << magic_number  << endl;

         if (magic_number == "P3") return P3;
         else if (magic_number == "P6") return P6;
      }  return UNDEF;
   }

   void ReadPPM::readP3(const string& filename)
   {
      cout << "ReadPPM: Reading ascii file " << filename << endl;
      ifstream file(filename.c_str());
      if (file.good()) 
      {
         file.seekg(end_header); // go back to where we left off
         // the stream splits on whitespace so the chars can be read one after
         // the other without hassle.
         for(int i = 0; i < m_width * m_height * 3; i++) 
         {
            int c;
            file >> c; // we need to map an ascii number symbol (or more) to the
                       // numerical value, not just use the symbols itself
            m_pixels[i] = (char)c;
         }
         file.close();
      } else { cerr << "ReadPPM: Error, P3 file not good." << endl; } // TODO: Detailed error
   }

   void ReadPPM::readP6(const string& filename)
   {
      cout << "ReadPPM: Reading binary file " << filename << endl;
      ifstream file(filename.c_str(), ios::binary); // open in binary mode
      if (file.good()) 
      {
         file.seekg(end_header); // go back to where we left off
         file.read((char *)m_pixels,m_width * m_height * 3); // not sure if good. dump whole binary blob into array.
         file.close();
      } else { cerr << "ReadPPM: Error, P6 file not good." << endl; } // TODO: Detailed error
   }

   ReadPPM::~ReadPPM() { }

} /* namespace asteroids */
