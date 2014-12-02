/**
 * @brief Contains Factory for mesh generation.
 *
 * @file TriangleMeshFactory.hpp
 * @author rdiederichse@uos.de
 */
#ifndef TRIANGLEMESHFACTORY_H

#define TRIANGLEMESHFACTORY_H

#include "rendering/TriangleMesh.hpp"

namespace asteroids 
{
   /**
    * @class TriangleMeshFactory
    * @brief Singleton Factory class to encapsulate parsing meshes from different file
    * types.
    */
   class TriangleMeshFactory 
   {
      public:
         /**
          * @brief Returns a pointer to a mesh parsed from a given file. Format
          * is recognized by extension.
          *
          * @param filename The file containing the mesh definition.
          * @return A pointer to the parsed mesh
          */
         TriangleMesh* getMesh(const std::string &filename) const;

         /**
          * @brief Method to acquire the singleton instance
          * @return The singleton.
          */
         static TriangleMeshFactory* getInstance();

      private:
         /**
          * Empty default constructor. Does nothing.
          */
         TriangleMeshFactory();

         /**
          * The singleton instance.
          */
         static TriangleMeshFactory* instance;

         /**
          * Copy constructor. Does nothing.
          */
         TriangleMeshFactory(const TriangleMeshFactory& f) {};

         /**
          * Assignment operator. Does nothing.
          */
         TriangleMeshFactory& operator=(const TriangleMesh& f) {};
   };
} /* namespace asteroids */
#endif /* end of include guard: TRIANGLEMESHFACTORY_H */
