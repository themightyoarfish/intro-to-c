#ifdef __APPLE__
#include <glut.h>
#else
#include <GL/glut.h>
#endif

/* Standard io header */
#include <stdio.h>
#include <math.h>

/* Camera manipulation functions */
#include "camera.h"

/* Extern declarations of used global variables */
extern float* rvBuffer;
extern int*   riBuffer;
extern int    riCount;
extern float  rvCount;
extern int    old_x;
extern int    old_y;
extern struct camera* cam;
extern int    mouse_button;
extern int    mouse_state;

void mousePressed(int button, int state, int x, int y)
{
    /* Save mouse and button states */
    mouse_button = button;
    mouse_state = state;
}

void mouseMoved(int x, int y)
{
    /* Difference between old and current mouse position */
    int dx;
    int dy;

    /* Update mouse coordinates */
    dx = x - old_x;
    dy = y - old_y;


    /* Left button controls camera movement */
    if(mouse_button == GLUT_LEFT_BUTTON)
    {
        /* Move cam left or right if x coordinates differ */
        if(fabs(dx) > CAM_SENSITY)
        {
            if(dx < 0)
            {
                turn_camera(cam, RIGHT);
            }
            else
            {
                turn_camera(cam, LEFT);
            }
        }

        /* Move forward and backward if y coordinates differ */
        if(fabs(dy) > CAM_SENSITY)
        {
            if(dy > 0)
            {
                move_camera(cam, FORWARD);
            }
            else
            {
                move_camera(cam, BACKWARD);
            }
        }
    }

    /* Right button controls head movement */
    if(mouse_button == GLUT_RIGHT_BUTTON)
    {
        if(fabs(dy) > CAM_SENSITY)
        {
            if(dy > 0)
            {
                turn_camera(cam, UP);
            }
            else
            {
                turn_camera(cam, DOWN);
            }
        }

        if(fabs(dx) > CAM_SENSITY)
        {
            if(dx > 0)
            {
                turn_camera(cam, RIGHT);
            }
            else
            {
                turn_camera(cam, LEFT);
            }
        }
    }

    /* Middle button contols height */
    if(mouse_button == GLUT_MIDDLE_BUTTON)
    {
        if(fabs(dy) > CAM_SENSITY)
        {
            if(dy > 0)
            {
                printf("UP");
                move_camera(cam, UP);
            }
            else
            {
                printf("DOWN");
                move_camera(cam, DOWN);
            }
        }
    }

    old_x = x;
    old_y = y;

    glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y)
{

   switch(key) {
      case 'd':
         move_camera(cam, RIGHT);
         break;
      case 'a':
         move_camera(cam, LEFT);
         break;
      case 'w':
         move_camera(cam, FORWARD);
         break;
      case 's':
         move_camera(cam, BACKWARD);
         break;
      case 'f':
         turn_camera(cam, LEFT); 
         break;
      case 'h':
         turn_camera(cam, RIGHT);
         break;
      case 't':
         turn_camera(cam, UP);
         break;
      case 'g':
         turn_camera(cam, DOWN);
         break;
   }
   glutPostRedisplay();
}

void reshape(int w, int h)
{
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,10000);
	glMatrixMode(GL_MODELVIEW);
}

void render(void)
{
    int i;

    /* Clear backbuffer with black color */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Set camera position and direction */
    apply_camera(cam);
  
    for(i = 0; i < riCount; i++)
    {
        int index = 3 * i;

        /* Get vertex indices of triangle vertices */
        int a = 3 * riBuffer[index];
        int b = 3 * riBuffer[index + 1];
        int c = 3 * riBuffer[index + 2];


        /* Render wireframe model */
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(rvBuffer[a], rvBuffer[a + 1], rvBuffer[a + 2]);
        glVertex3f(rvBuffer[b], rvBuffer[b + 1], rvBuffer[b + 2]);
        glVertex3f(rvBuffer[c], rvBuffer[c + 1], rvBuffer[c + 2]);
        glEnd();
    }
    
    /* Call backbuffer and replace screen contends */
    glutSwapBuffers();
}
