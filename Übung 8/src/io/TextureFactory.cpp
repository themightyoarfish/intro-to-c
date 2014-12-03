/**
 * @file TextureFactory.cpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 03.12.2014
 */

#include "TextureFactory.hpp"
#include "BitmapReader.hpp"
#include "ReadPPM.hpp"
#include "ReadJPG.hpp"
#include "ReadTGA.hpp"
#include <iostream>
#include <cstddef>

namespace asteroids 
{

   TextureFactory::TextureFactory() {}
   TextureFactory* TextureFactory::instance_ptr = NULL;
   std::string TextureFactory::basepath = "";

   TextureFactory* TextureFactory::instance()
   {
      if (instance_ptr != NULL) return instance_ptr;
      else return (instance_ptr = new TextureFactory);
   }

   Texture* TextureFactory::getTexture(const string &filename) const
   {
      int pos;
      BitmapReader *reader;
      if ((pos = filename.find(".ppm")) == (filename.length() - 4)) // .ppm extension
      {
         reader = new ReadPPM(filename);
         return new Texture(reader->getPixels(), reader->getWidth(), reader->getHeight());
      } else if ((pos = filename.find(".jpg")) == (filename.length() - 4)) // .jpg extension
      {
         reader = new ReadJPG(filename);
         return new Texture(reader->getPixels(), reader->getWidth(), reader->getHeight());
      } else if ((pos = filename.find(".tga")) == (filename.length() - 4)) 
      {
         reader = new ReadTGA(filename);
         return new Texture(reader->getPixels(), reader->getWidth(), reader->getHeight());
      } else  // error
      {
         int i = filename.find_last_of(".");
         std::cerr << "TextureFactory Error: File " << filename << (i == string::npos ? " without extension" : " of type " + filename.substr(i))
            << " not readable. " << std::endl;
         return NULL;
      }
   }

   void TextureFactory::setBasePath(string basepath)
   {
      TextureFactory::basepath = basepath;
      std::cout << "Basepath is " << basepath << std::endl;
   }

   
} /* namespace asteroids */
