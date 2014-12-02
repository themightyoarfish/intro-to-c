/**
 * Read3DS.hpp
 *
 *  @date 10.12.2011
 *  @author Thomas Wiemann
 */

#ifndef READ3DS_HPP_
#define READ3DS_HPP_

#include "rendering/TriangleMesh.hpp"
#include "rendering/TexturedMesh.hpp"
#include "rendering/Materials.hpp"

#include "TextureFactory.hpp"

#include <string>
#include <vector>

#include "MeshReader.hpp"
using std::vector;
using std::string;

namespace asteroids
{

   class Read3DS : public MeshReader
   {
      public:
         Read3DS(std::string filename);

         TriangleMesh* getMesh();

         void getMesh(TexturedMesh &texMesh);

         virtual ~Read3DS();

      private:

         void readSimpleMesh();
         void readTexturedMesh();

         string m_filename;
   };

}
#endif /* READ3DS_HPP_ */
