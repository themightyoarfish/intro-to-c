#include "view/MainWindow.hpp"

using namespace std;

#include "io/Read3DS.hpp"
#include "rendering/TexturedMesh.hpp"
#include "math/Vertex.hpp"
#include "logging/Logger.hpp"
#include <string>
#include <sstream>

int main(int argc, char** argv)
{
   std::string arg("--outfile=");
   for (int i = 0; i < argc; i++) 
   {
      std::string s(argv[i]);
      if (s.compare(0, arg.length(), arg) == 0) 
      {
         asteroids::Logger::instance().setOutputFile(s.substr(s.find("=") + 1));

      }
   }
   asteroids::Logger::instance() << "Started program.";
   asteroids::MainWindow* mv = new asteroids::MainWindow(string(argv[1]));
   delete mv;
   return 0;
}
