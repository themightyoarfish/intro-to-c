/* Glut header */
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <glut.h>
#endif

/* Standard io header */
#include <stdio.h>

/* Extern declarations of used global variables */
extern float* vertexBuffer;
extern int*   indexBuffer;
extern int    indexCount;
extern float  vertexCount;

void mouseMoved(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        printf("Position x,y: %i,%i\nLeft mousebutton\n", x, y);
    }
    else if(button == GLUT_RIGHT_BUTTON)
    {
        printf("Position x,y: %i,%i\nRight mousebutton\n", x, y);
    }
    else if(button == GLUT_MIDDLE_BUTTON)
    {
        printf("Position x,y: %i,%i\nMiddle mousebutton\n", x, y);
    }
	
}

void keyPressed(unsigned char key, int x, int y)
{
    if(key ==  32)
    {
        printf("SPACE pressed\n");
    }
    else if(key == 9)
    {
        printf("Tabulator pressed\n");
    }
    else if(key > 127)
    {
        
    }
    else printf("%c pressed\n", (char) key);   

}

void reshape(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,10,100000);
	glMatrixMode(GL_MODELVIEW);
}

void render(void)
{
    int i;    

    /* Set camera position and direction */
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -750.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);

    /* Clear backbuffer with black color */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for(i = 0; i < indexCount; i++)
    {
        /* Get position og current triangle in buffer */
        int index = 3 * i;

        /* Get vertex indices of triangle vertices */
        int a = 3 * indexBuffer[index];
        int b = 3 * indexBuffer[index + 1];
        int c = 3 * indexBuffer[index + 2];


        /* Render wireframe model */
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(vertexBuffer[a], vertexBuffer[a + 1], vertexBuffer[a + 2]);
        glVertex3f(vertexBuffer[b], vertexBuffer[b + 1], vertexBuffer[b + 2]);
        glVertex3f(vertexBuffer[c], vertexBuffer[c + 1], vertexBuffer[c + 2]);
        glEnd();
    }
    
    /* Call backbuffer and replace screen contends */
    glutSwapBuffers();
}
