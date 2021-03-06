/* Glut header */
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
    /* Empty stub. Insert Code here */
    mouse_button = button;
    mouse_state = state;
}

void mouseMoved(int x, int y)
{
    /* Empty stub. Insert Code here. Keep glut call on last line */
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
    
    apply_camera(cam);

  
    for(i = 0; i < riCount; i++)
    {
        /* Get position og current triangle in buffer */
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
