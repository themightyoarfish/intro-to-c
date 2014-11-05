#include "objio.h"
#include "mainwindow.h"

#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <glut.h>
#endif

float* vertexBuffer;
int* indexBuffer;
int vertexCount;
int indexCount;

void call_freeply(void)
{
   printf("freeply\n");
	freeObj(&vertexBuffer, &indexBuffer);
}

int main(int argc, char **argv)
{
    /* Parse command line */
    if(argc != 2)
    {
        printf("usage: viewer <obj-file>\n");
        exit(-1);
    }
    
    /* Init glut and main window */
	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Our first frame");
	
    /* Try to load .ply file */
	loadObj(argv[1], &vertexBuffer, &indexBuffer, &vertexCount, &indexCount);
   printf("hello\n");
   /* for (int i = 0; i < vertexCount; i+=3) */ 
   /* { */
      /* printf("%d: (%f,%f,%f)\n",i,vertexBuffer[i],vertexBuffer[i+1],vertexBuffer[i+2]); */
   /* } */

    /* Test if the file was loaded correctly */
    if(vertexBuffer == 0 || indexBuffer == 0 || vertexCount == 0 || indexCount == 0)
    {
        printf("Error parsing %s\n", argv[1]);
        exit(-1);
    }
    
	/* Register callbacks */
	glutDisplayFunc(render);
  	glutReshapeFunc(reshape);
  	glutKeyboardFunc(keyPressed);
  	glutMouseFunc(mouseMoved);
	
	/* Enter GLUT event processing cycle */
	atexit(call_freeply);
	glutMainLoop();
	return 0;

}

