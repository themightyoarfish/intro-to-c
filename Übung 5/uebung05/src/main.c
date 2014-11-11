#include "main.h"
#include "mainwindow.h"
#include "camera.h"
#include "objio.h"

/* Glut header */
#ifdef __APPLE__
#include <glut.h>
#else
#include <GL/gl.h>
#endif

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
    loadObj(argv[1], &rvBuffer, &riBuffer, &rvCount, &riCount);
    
    printf("%d %d\n", rvCount, riCount);

    /* Test if the file was loaded correctly */
    if(rvBuffer == 0 || riBuffer == 0 || rvCount == 0 || riCount == 0)
    {
        printf("Error parsing %s\n", argv[1]);
        exit(-1);
    }

    /* Define initial camera position */
    struct vector pos;
    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = -1000.0;

    /* Init camera parameters */
    cam = malloc(sizeof(struct camera));
    init_camera(cam, pos, 0.5f, 20.0f);
    print_camera(cam);

    /* Register callbacks */
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutMotionFunc(mouseMoved);
    glutMouseFunc(mousePressed);
	
    /* Enter GLUT event processing cycle */
    atexit(call_freeobj);
    glutMainLoop();
    return 0;

}

void call_freeobj(void)
{
    
    freeObj(&rvBuffer, &riBuffer);
}
