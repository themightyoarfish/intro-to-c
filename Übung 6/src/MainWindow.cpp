/**
 * @file MainWindow.cpp
 *
 * @author Rasmus Diederichsen
 *
 * Contains the MainWindow class implementation.
 */

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
   m_sizeX = 762;
   m_sizeY = 576;
   m_cam = NULL;
   m_mesh = NULL;
   m_oldX = m_oldY = 0;
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
   glutInitWindowSize(m_sizeX,m_sizeY);
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
   this->m_cam = cam;
}
void MainWindow::setMesh(TriangleMesh *mesh)
{
   this->m_mesh = mesh;
}
void MainWindow::render()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   /* Set camera position and direction */
   getInstance()->m_cam->apply();
   if (getInstance()->m_mesh != NULL) 
   {
      getInstance()->m_mesh->render();
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
         getInstance()->m_cam->moveForward();
         break;
      case 's':
         getInstance()->m_cam->moveBackward();
         break;
      case 'd':
         getInstance()->m_cam->turnRight();
         break;
      case 'a':
         getInstance()->m_cam->turnLeft();
         break;
      case 't':
         getInstance()->m_cam->turnUp();
         break;
      case 'g':
         getInstance()->m_cam->turnDown();
         break;
   }
   glutPostRedisplay();
}

void MainWindow::mousePressed(int button, int state, int, int)
{
   getInstance()->m_mouseButton = button;
   getInstance()->m_mouseState = state;
}
void MainWindow::mouseMoved(int x, int y)
{
   /* Difference between old and current mouse position */
   int dx;
   int dy;

   /* Update mouse coordinates */
   dx = x - getInstance()->m_oldX;
   dy = y - getInstance()->m_oldY;


   /* Left button controls camera movement */
   if(getInstance()->m_mouseButton == GLUT_LEFT_BUTTON)
   {
      /* Move cam left or right if x coordinates differ */
      if(fabs(dx) > Camera::CAM_SENSITIVITY)
      {
         if(dx < 0) getInstance()->m_cam->turnRight();
         else getInstance()->m_cam->turnLeft();
      }

      /* Move forward and backward if y coordinates differ */
      if(fabs(dy) > Camera::CAM_SENSITIVITY)
      {
         if(dy > 0) getInstance()->m_cam->moveForward();
         else getInstance()->m_cam->moveBackward();
      }
   }

   /* Right button controls head movement */
   if(getInstance()->m_mouseButton == GLUT_RIGHT_BUTTON)
   {
      if(fabs(dy) > Camera::CAM_SENSITIVITY)
      {
         if(dy > 0) getInstance()->m_cam->turnUp();
         else getInstance()->m_cam->turnDown();
      }

      if(fabs(dx) > Camera::CAM_SENSITIVITY)
      {
         if(dx > 0) getInstance()->m_cam->turnRight();
         else getInstance()->m_cam->turnLeft();
      }
   }

   /* Middle button contols height */
   if(getInstance()->m_mouseButton == GLUT_MIDDLE_BUTTON)
   {
      if(fabs(dy) > Camera::CAM_SENSITIVITY)
      {
         if(dy > 0) getInstance()->m_cam->moveUp();
         else getInstance()->m_cam->moveDown();
      }
   }

   getInstance()->m_oldX = x;
   getInstance()->m_oldY = y;

   glutPostRedisplay();
}

MainWindow::~MainWindow()
{
   delete window;
}
