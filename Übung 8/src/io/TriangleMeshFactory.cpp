/**
 * @brief TriangleMeshFactory implementation.
 * @file TriangleMeshFactory.cpp
 * @author rdiederichse@uos.de
 */
#include "io/TriangleMeshFactory.hpp"
#include "ReadPLY.hpp"
#include "Read3DS.hpp"
#include "MeshReader.hpp"

using std::string;

namespace asteroids 
{

   TriangleMeshFactory::TriangleMeshFactory() {}
   TriangleMeshFactory* TriangleMeshFactory::instance_ptr = NULL;

   TriangleMeshFactory* TriangleMeshFactory::instance()
   {
      if (instance_ptr != NULL) return instance_ptr;
      else return (instance_ptr = new TriangleMeshFactory);
   }

   TriangleMesh* TriangleMeshFactory::getMesh(const string &filename) const
   {
      unsigned found = filename.find_last_of("/\\");
      string basePath = filename.substr(0, found+1);
      TextureFactory::setBasePath(basePath);

      int pos;
      MeshReader *reader;
      if ((pos = filename.find(".ply")) == (filename.length() - 4)) // .ply extension
      {
         reader = new ReadPLY(filename);
         return reader->getMesh();
      } else if ((pos = filename.find(".3ds")) == (filename.length() - 4)) // .3ds extension
      {
         reader = new Read3DS(filename);
         return reader->getMesh();
      } else  // error
      {
         int i = filename.find_last_of(".");
         std::cerr << "TriangleMeshFactory Error: File " << filename << (i == string::npos ? " without extension" : " of type " + filename.substr(i))
            << " not readable. " << std::endl;
         return NULL;
      }
   }

} /* namespace asteroids */

