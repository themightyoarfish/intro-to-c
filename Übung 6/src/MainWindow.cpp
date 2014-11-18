#include "MainWindow.hpp"
#ifdef __APPLE__
#include <glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <iostream>

MainWindow* MainWindow::window = NULL;
MainWindow* MainWindow::getInstance()
{
   if (window == NULL) window = new MainWindow;
   return window;
}

MainWindow::MainWindow()
{
   sizex = 762;
   sizey = 576;
   cam = NULL;
   mesh = NULL;
   old_x = old_y = 0;
   initGlut();
   initCallbacks();
}

void MainWindow::initGlut()
{
   int dummy1 = 0;
   char *dummy2 = NULL;
   glutInit(&dummy1, &dummy2);
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(sizex,sizey);
   glutCreateWindow("Main Window");
}

void MainWindow::initCallbacks()
{
   glutDisplayFunc(render);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyPressed);
   glutMotionFunc(mouseMoved);
   glutMouseFunc(mousePressed);
}
void MainWindow::setCamera(Camera *cam)
{
   this->cam = cam;
}
void MainWindow::setMesh(TriangleMesh *mesh)
{
   this->mesh = mesh;
}
void MainWindow::render()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   /* Set camera position and direction */
   getInstance()->cam->apply();
   if (getInstance()->mesh != NULL) 
   {
      getInstance()->mesh->render();
      glutSwapBuffers();
   }
   else std::cerr << "Error. No mesh to render." << std::endl;
}
void MainWindow::reshape(int w, int h)
{
   if (h == 0) h = 1;

   float ratio =  w * 1.0 / h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, w, h);
   gluPerspective(45,ratio,1,10000);
   glMatrixMode(GL_MODELVIEW);
}
void MainWindow::keyPressed(unsigned char key, int x, int y)
{

   switch(key) {
      case 'w':
         getInstance()->cam->moveForward();
         break;
      case 's':
         getInstance()->cam->moveBackward();
         break;
      case 'd':
         getInstance()->cam->turnRight();
         break;
      case 'a':
         getInstance()->cam->turnLeft();
         break;
      case 't':
         getInstance()->cam->turnUp();
         break;
      case 'g':
         getInstance()->cam->turnDown();
         break;
   }
   glutPostRedisplay();
}

void MainWindow::mousePressed(int button, int state, int, int)
{
   getInstance()->mouse_button = button;
   getInstance()->mouse_state = state;
}
void MainWindow::mouseMoved(int x, int y)
{
   /* Difference between old and current mouse position */
   int dx;
   int dy;

   /* Update mouse coordinates */
   dx = x - getInstance()->old_x;
   dy = y - getInstance()->old_y;


   /* Left button controls camera movement */
   if(getInstance()->mouse_button == GLUT_LEFT_BUTTON)
   {
      /* Move cam left or right if x coordinates differ */
      if(fabs(dx) > Camera::CAM_SENSITIVITY)
      {
         if(dx < 0) getInstance()->cam->turnRight();
         else getInstance()->cam->turnLeft();
      }

      /* Move forward and backward if y coordinates differ */
      if(fabs(dy) > Camera::CAM_SENSITIVITY)
      {
         if(dy > 0) getInstance()->cam->moveForward();
         else getInstance()->cam->moveBackward();
      }
   }

   /* Right button controls head movement */
   if(getInstance()->mouse_button == GLUT_RIGHT_BUTTON)
   {
      if(fabs(dy) > Camera::CAM_SENSITIVITY)
      {
         if(dy > 0) getInstance()->cam->turnUp();
         else getInstance()->cam->turnDown();
      }

      if(fabs(dx) > Camera::CAM_SENSITIVITY)
      {
         if(dx > 0) getInstance()->cam->turnRight();
         else getInstance()->cam->turnLeft();
      }
   }

   /* Middle button contols height */
   if(getInstance()->mouse_button == GLUT_MIDDLE_BUTTON)
   {
      if(fabs(dy) > Camera::CAM_SENSITIVITY)
      {
         if(dy > 0) getInstance()->cam->moveUp();
         else getInstance()->cam->moveDown();
      }
   }

   getInstance()->old_x = x;
   getInstance()->old_y = y;

   glutPostRedisplay();
}

MainWindow::~MainWindow()
{
   delete window;
}
