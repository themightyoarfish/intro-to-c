/**
 * @file ReadJPG.cpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#include "ReadJPG.hpp"
#include <jpeglib.h>    
#include <jerror.h>
#include <iostream>
#include <string>


using std::cout;
using std::cerr;
using std::endl;

namespace asteroids 
{
   ReadJPG::ReadJPG(const std::string& filename) 
   {
      m_pixels = NULL;
      m_height = m_width = 0;
      FILE* file = fopen(filename.c_str(), "rb");  // open the file
      cout << "ReadJPG: reading jpg file " << filename << endl;

      if(!file) // io error or file not found.
         cerr << "Error reading JPG file " << filename << endl;
      else 
      {
         unsigned long data_size;     // length of the file
         JSAMPROW rowptr[1];  // pointer to an array. jpeg_read_scanlines always wants array of pointers. Should be unsigned char*
         struct jpeg_decompress_struct info; // contains the info about this jpeg
         struct jpeg_error_mgr err;          // error handler
         info.err = jpeg_std_error(&err);     
         jpeg_create_decompress(&info);   // fills info structure

         jpeg_stdio_src(&info, file);    // specify input source
         jpeg_read_header(&info, TRUE);   // read jpeg file header

         jpeg_start_decompress(&info);    // decompress the file

         // set width and height as read from header
         m_width = info.output_width;
         m_height = info.output_height;

         data_size = m_width * m_height * 3;

         //--------------------------------------------
         // read scanlines one at a time & put bytes 
         //    in m_pixels[] array. Assumes an RGB image
         //--------------------------------------------
         m_pixels = new unsigned char[data_size];
         while (info.output_scanline < info.output_height) // loop
         {
            // this advances the row pointer to point to the portion of the
            // array to fill next (with one line of the image)
            rowptr[0] = m_pixels + 3 * info.output_width * info.output_scanline; 
            jpeg_read_scanlines(&info, rowptr, 1);
         }
      }

   }

   ReadJPG::~ReadJPG() { }

} /* namespace asteroids */

