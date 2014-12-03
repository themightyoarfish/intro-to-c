#ifndef TEXTUREFACTORY_H

#define TEXTUREFACTORY_H

#include "rendering/Texture.hpp"

namespace asteroids 
{
   class TextureFactory 
   {
      public:
         /**
          * @brief Returns a pointer to a textured mesh parsed from a given file. Format
          * is recognized by extension.
          *
          * @param filename The file containing the mesh definition.
          * @return A pointer to the parsed mesh
          */
         Texture* getTexture(const std::string &filename) const;

         /**
          * @brief Method to acquire the singleton instance
          * @return The singleton.
          */
         static TextureFactory* instance();

         /**
          * Set the base path relative to which textures will be loaded.
          * @param basepath.
          */
         void setBasePath(std::string basepath);

      private:
         /**
          * Empty default constructor. Does nothing.
          */
         TextureFactory();

         /**
          * The singleton instance.
          */
         static TextureFactory* instance_ptr;

         /**
          * Copy constructor. Does nothing.
          */
         TextureFactory(const TextureFactory& f) {};

         /**
          * Assignment operator. Does nothing.
          */
         TextureFactory& operator=(const TextureFactory& f) {};

         /**
          * The base path.
          */
         static std::string basepath;
   };
} /* namespace asteroids */

#endif /* end of include guard: TEXTUREFACTORY_H */
