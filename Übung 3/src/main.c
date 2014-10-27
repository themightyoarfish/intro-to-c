#include <glut.h>
#include "include/mainwindow.h"
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(320,320);
   glutCreateWindow("test");

   glutMouseFunc(mouseMoved);
   glutKeyboardFunc(keyPressed);

   glutDisplayFunc(render);
   glutReshapeFunc(reshape);

   glutMainLoop();

   return 0;
}

