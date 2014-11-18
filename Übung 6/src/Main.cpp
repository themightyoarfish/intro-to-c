#include "MainWindow.hpp"
#include "Camera.hpp"
#include "TriangleMesh.hpp"
#ifdef __APPLE__
#include <glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;
int main(int argc, const char **argv)
{
   std::string s(argv[1]);
   TriangleMesh mesh(s);
   Camera cam(0.,0.,-1000.);
   cam.print_camera();
   MainWindow::getInstance()->setMesh(&mesh);
   MainWindow::getInstance()->setCamera(&cam);
   glutMainLoop();
   return 0;
}
