#include "view/MainWindow.hpp"
#include "io/Read3DS.hpp"
#include "rendering/TexturedMesh.hpp"
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include "util/PathPlanner.hpp"
#include "math/Vertex.hpp"

int main(int argc, char** argv)
{
   asteroids::PathPlanner p("../wc.map");
   p.getPath(asteroids::Vertex<float>(0,0,0),"foo","bar");
   asteroids::MainWindow* mv = new asteroids::MainWindow(string(argv[1]), string(argv[2]), string(argv[3]), string(argv[4]));
   delete mv;
   return 0;
}
