#include "MainWindow.hpp"
#include "io/TriangleMeshFactory.hpp"
#include "io/Read3DS.hpp"
#include "rendering/TexturedMesh.hpp"
#include "logging/Logger.hpp"

using std::cout;
using std::endl;

namespace asteroids
{

MainWindow* MainWindow::master = 0;

Camera MainWindow::m_cam;

MainWindow::MainWindow(string filename)
{

	// Save pointer to current instance. Later on we
	// will create a proper singleton here...
	MainWindow::master = this;

    // Init glut main window
    initGlut();
    initGL();

	for(int i = 0; i < 256; i++)
	{
		m_keyStates[i] = false;
		m_specialkeyStates[i] = false;
	}


   /* // Timestamp this point */
   /* Timestamp t; */
   Logger::instance() << "Start loading mesh.";

	// Create a triangle mesh instance
	m_mesh = TriangleMeshFactory::instance().getMesh(filename);

	// Create a sky box. We assume that a model was loaded beforehand
	// to ensure that the base path in texture factory was set correctly.
	// If not set it manually before creating the sky box!!
	string names[6];
	names[0] = "box1.ppm";
	names[1] = "box2.jpg";
	names[2] = "box3.ppm";
	names[3] = "box4.jpg";
	names[4] = "box5.ppm";
	names[5] = "box6.jpg";

   Logger::instance() << "Start rendering.";

   m_skybox = new Skybox(2048, names);

   Logger::instance() << "Finished rendering.";

   /* // print elapsed time */
   /* std::cout << t << std::endl; */

   // Call main loop
   glutMainLoop();
}

MainWindow::~MainWindow()
{
   // Check if objects exists an delete if necessary
   if(m_mesh)
   {
      delete m_mesh;
      m_mesh = 0;
   }

   if(m_skybox)
   {
      delete m_skybox;
      m_skybox = 0;
   }
}


void MainWindow::initGlut()
{
   // Create dummy arguments for command line options
   int dummy_argc = 1;
   char *dummy_argv[1];
   dummy_argv[0] = new char[255];
   dummy_argv[0] = (char*)"Main Window";

   // Initialize glut toolkit
   glutInit(&dummy_argc, dummy_argv);

   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(762, 576);
   glutCreateWindow("3D-Viewer");
   glutSetKeyRepeat(1);

   //Register callback functions
   glutDisplayFunc(MainWindow::callback_render);
   glutReshapeFunc(MainWindow::callback_reshape);
   glutMouseFunc(MainWindow::callback_mouse);
   glutMotionFunc(MainWindow::callback_motion);
   glutKeyboardFunc(MainWindow::callback_key);
   glutKeyboardUpFunc(MainWindow::callback_keyUp);
   glutSpecialFunc(MainWindow::callback_specialkey);
   glutSpecialUpFunc(MainWindow::callback_specialkeyUp);
   glutTimerFunc(15, MainWindow::callback_timer, 0);
   // glutIdleFunc(MainWindow::callback_render);

   // Init OpenGL stuff
   initGL();
}

void MainWindow::initGL()
{
   glMatrixMode(GL_MODELVIEW);
   glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

   // Setup two light sources
   float light0_position[4];
   float light0_ambient[4];
   float light0_diffuse[4];

   float light1_position[4];
   float light1_ambient[4];
   float light1_diffuse[4];

   light0_position[0] =   1.0f; light0_ambient[0] = 0.8f; light0_diffuse[0] = 0.8f;
   light0_position[1] =   1.0f; light0_ambient[1] = 0.8f; light0_diffuse[1] = 0.8f;
   light0_position[2] =   0.0f; light0_ambient[2] = 0.8f; light0_diffuse[2] = 0.8f;
   light0_position[3] =   1.0f; light0_ambient[3] = 0.1f; light0_diffuse[3] = 1.0f;

   light1_position[0] =   0.0f; light1_ambient[0] = 0.1f; light1_diffuse[0] = 0.5f;
   light1_position[1] =  -1.0f; light1_ambient[1] = 0.1f; light1_diffuse[1] = 0.5f;
   light1_position[2] =   0.0f; light1_ambient[2] = 0.1f; light1_diffuse[2] = 0.5f;
   light1_position[3] =   1.0f; light1_ambient[3] = 1.0f; light1_diffuse[3] = 1.0f;

   // Light 1
   glLightfv(GL_LIGHT0, GL_AMBIENT,  light0_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
   glEnable(GL_LIGHT0);

   // Light 2
   glLightfv(GL_LIGHT1, GL_AMBIENT,  light1_ambient);
   glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
   glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
   glEnable(GL_LIGHT1);

   // Enable lighting
   glEnable(GL_LIGHTING);

   // Enable z buffer and gouroud shading
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LESS);
   glShadeModel (GL_SMOOTH);
}


void MainWindow::callback_key(unsigned char key, int x, int y)
{
   // Re-route key callback
   MainWindow::master->keyPressed(key, x, y);
   glutPostRedisplay();
}

void MainWindow::callback_keyUp(unsigned char key, int x, int y)
{
   // Re-route key callback
   MainWindow::master->keyUp(key, x, y);
   glutPostRedisplay();
}

void MainWindow::callback_specialkey(int key, int x, int y)
{
   // Re-route special key callback
   MainWindow::master->specialkeyPressed(key, x, y);
   glutPostRedisplay();
}

void MainWindow::callback_specialkeyUp(int key, int x, int y)
{
   // Re-route special key callback
   MainWindow::master->specialkeyUp(key, x, y);
   glutPostRedisplay();
}

void MainWindow::callback_reshape(int w, int h)
{
   // Re-route reshape callback
   MainWindow::master->reshape(w, h);
}

void MainWindow::callback_render()
{
   // Re-route render callback
   MainWindow::master->render();
}

void MainWindow::callback_mouse(int button, int state, int x, int y)
{
   // Re-route mouse callback
   MainWindow::master->mousePressed(button, state, x, y);
   glutPostRedisplay();
}

void MainWindow::callback_motion(int x, int y)
{
   // Re-route motion callback
   MainWindow::master->mouseMoved(x, y);
   glutPostRedisplay();
}

void MainWindow::callback_timer (int value)
{
   glutPostRedisplay();
   glutTimerFunc(15, callback_timer, 0);
}

void MainWindow::keyPressed(unsigned char key, int x, int y)
{
   // State of key is pressed
   m_keyStates[key] = true;
}

void MainWindow::keyUp (unsigned char key, int x, int y)
{  
   // State of key is unpressed
   m_keyStates[key] = false;
} 

void MainWindow::specialkeyPressed(int key, int x, int y)
{
   // State of key is pressed
   m_specialkeyStates[key] = true;
}

void MainWindow::specialkeyUp(int key, int x, int y)
{
   // State of key is unpressed
   m_specialkeyStates[key] = false;
}

void MainWindow::keyOperations(void)
{
   // Controller for moving and rotation
   if (m_keyStates['q'])
   {
      m_mesh->rotate(ROLL, 0.05);
   }

   if (m_keyStates['e'])
   {
      m_mesh->rotate(ROLL, -0.05);
   }

   if (m_keyStates['a'])
   {
      m_mesh->rotate(YAW, 0.05);
   }

   if (m_keyStates['d'])
   {
      m_mesh->rotate(YAW, -0.05);
   }

   if (m_keyStates['w'])
   {
      m_mesh->rotate(PITCH, 0.05);
   }

   if (m_keyStates['s'])
   {
      m_mesh->rotate(PITCH, -0.05);
   }

   if (m_specialkeyStates[GLUT_KEY_UP])
   {
      m_mesh->move(STRAFE, -10);
   }

   if (m_specialkeyStates[GLUT_KEY_DOWN])
   {
      m_mesh->move(STRAFE, 10);
   }

   if (m_specialkeyStates[GLUT_KEY_LEFT])
   {
      m_mesh->move(LIFT, 5);
   }

   if (m_specialkeyStates[GLUT_KEY_RIGHT])
   {
      m_mesh->move(LIFT, -5);
   }

   if (m_specialkeyStates[GLUT_KEY_PAGE_UP])
   {
      m_mesh->move(ACCEL, 5);
   }

   if (m_specialkeyStates[GLUT_KEY_PAGE_DOWN])
   {
      m_mesh->move(ACCEL, -5);
   }
}

void MainWindow::mousePressed(int button, int state, int x, int y)
{
   // Save state and button id. We need this information
   // when the mouse is moved to call the proper reaction
   // callback of the camera
   m_button      = button;
   m_buttonState = state;

}

void MainWindow::mouseMoved(int x, int y)
{

   // Get number the number of pixel between the last
   // und current mouse position
   int dx = x - m_mouseX;
   int dy = y - m_mouseY;

   // Check which button was pressend and apply action
   if(m_button == GLUT_LEFT_BUTTON)
   {
      moveXY(dx, dy);
   }

   if(m_button == GLUT_RIGHT_BUTTON)
   {
      moveHead(dx, dy);
   }

   if(m_button == GLUT_MIDDLE_BUTTON)
   {
      moveZ(dy);
   }

   // Transform viewport
   m_cam.apply();

   // Save new coodinates
   m_mouseX = x;
   m_mouseY = y;

}

void MainWindow::moveXY(int dx, int dy)
{

   if(fabs(dx) > MOUSE_SENSITY)
   {
      if(dx > 0)
      {
         m_cam.turnRight();
      }

      else
      {
         m_cam.turnLeft();
      }

   }

   if(fabs(dy) > MOUSE_SENSITY)
   {
      if(dy > 0)
      {
         m_cam.moveBackward();
      }

      else
      {
         m_cam.moveForward();
      }
   }
}

void MainWindow::moveZ(int dy)
{

   if(fabs(dy) > MOUSE_SENSITY)
   {
      if(dy > 0)
      {
         m_cam.moveUp();
      }

      else
      {
         m_cam.moveDown();
      }
   }
}

void MainWindow::moveHead(int dx, int dy)
{

   if(fabs(dy) > MOUSE_SENSITY)
   {
      if(dy > 0)
      {
         m_cam.turnUp();
      }

      else
      {
         m_cam.turnDown();
      }
   }

   if(fabs(dx) > MOUSE_SENSITY)
   {
      if(dx > 0)
      {
         m_cam.turnRight();
      }

      else
      {
         m_cam.turnLeft();
      }
   }
}


void MainWindow::reshape(int w, int h)
{
   if(h == 0)
   {
      h = 1;
   }

   float ratio = 1.0* w / h;

   // Reset the coordinate system before modifying
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Set the viewport to be the entire window
   glViewport(0, 0, w, h);

   // Set the correct perspective.
   gluPerspective(45,ratio,1,100000);
   glMatrixMode(GL_MODELVIEW);

   // Set 'LookAt'
   m_cam.apply();
}

void MainWindow::render()
{
   MainWindow::keyOperations();
   // Set black background color
   glClearColor(0.0, 0.0, 0.0, 0.0);

   // Clear bg color and enable depth test (z-Buffer)
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Render objects
   if(m_skybox)
   {
      m_skybox->render();
   }

   if(m_mesh)
   {
      m_mesh->render();
   }



   glFinish();

   // Call back buffer
   glutSwapBuffers();
}

}
