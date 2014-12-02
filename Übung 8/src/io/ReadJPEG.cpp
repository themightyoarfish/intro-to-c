/**
 * @file ReadJPEG.cpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#include "ReadJPEG.hpp"
#include <jpeglib.h>    
#include <jerror.h>
#include <iostream>
#include <string>


namespace asteroids 
{
   ReadJPEG::ReadJPEG(const std::string& filename) 
   {
      m_pixels = NULL;
      m_height = m_width = 0;
      FILE* file = fopen(filename.c_str(), "rb");  //open the file

      //if the jpeg file doesn't load
      if(!file) std::cerr << "Error reading JPEG file " << filename << std::endl;
      else 
      {
         unsigned long data_size;     // length of the file
         unsigned char* rowptr[1];  // pointer to an array
         struct jpeg_decompress_struct info; //for our jpeg info
         struct jpeg_error_mgr err;          //the error handler
         info.err = jpeg_std_error(&err);     
         jpeg_create_decompress(&info);   //fills info structure


         jpeg_stdio_src(&info, file);    
         jpeg_read_header(&info, TRUE);   // read jpeg file header

         jpeg_start_decompress(&info);    // decompress the file

         //set width and height
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
            // Enable jpeg_read_scanlines() to fill our m_pixels array
            rowptr[0] = m_pixels + 3 * info.output_width * info.output_scanline; 
            jpeg_read_scanlines(&info, rowptr, 1);
         }


      }

   }

   ReadJPEG::~ReadJPEG() { 
      // should I free m_pixels here?
   }

} /* namespace asteroids */

