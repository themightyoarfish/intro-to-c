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
   TriangleMeshFactory* TriangleMeshFactory::instance = NULL;

   TriangleMeshFactory* TriangleMeshFactory::getInstance()
   {
      if (instance != NULL) return instance;
      else return (instance = new TriangleMeshFactory);
   }

   TriangleMesh* TriangleMeshFactory::getMesh(const string &filename) const
   {
      int pos;
      TriangleMesh *m;
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
         std::cerr << "Error: File " << (i == string::npos ? "without extension" : filename.substr())
            << "not readable. " << std::endl;
         return NULL;
      }
   }

} /* namespace asteroids */

