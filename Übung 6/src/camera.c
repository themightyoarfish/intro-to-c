#include <stdio.h>
#include <math.h>
#ifdef __APPLE__
#include <glut.h>
#else
#include <GL/glut.h>
#endif

#include "camera.h"


void init_camera(struct camera *cam, struct vector pos, float turn_speed, float move_speed)
{
    /* Init pos */
    cam->initial.x = pos.x;
    cam->initial.y = pos.y;
    cam->initial.z = pos.z;
    cam->trans.x = 0.0f;
    cam->trans.y = 0.0f;
    cam->trans.z = 0.0f;

    
    /* Init look up vector */
    cam->up.x  = 0.0f;
    cam->up.y  = 1.0f;
    cam->up.z  = 0.0f;
    
    /* Init look at vector */
    cam->l.x   = 0.0f;
    cam->l.y   = 0.0f;
    cam->l.z   = 0.0f;
    
    /* Init rotation angles */
    cam->rot.x = 0.0f;
    cam->rot.y = 0.0f;
    cam->rot.z = 0.0f;
    
    /* Set speed parameters */
    cam->turn_speed = turn_speed;
    cam->move_speed = move_speed;
}


void move_camera(struct camera *cam, enum direction dir)
{
    switch(dir)
    {
        case FORWARD:
            cam->trans.x += cam->move_speed * sin(cam->rot.y);
            cam->trans.z += cam->move_speed * cos(cam->rot.y);
            break;
        case BACKWARD:
            cam->trans.x -= cam->move_speed * sin(cam->rot.y);
            cam->trans.z -= cam->move_speed * cos(cam->rot.y);
            break;
        case LEFT:
            cam->trans.x -= cam->move_speed * sin(PH - cam->rot.y);
            cam->trans.z -= cam->move_speed * cos(PH - cam->rot.y);
            break;
        case RIGHT:
            cam->trans.x += cam->move_speed * sin(PH + cam->rot.y);
            cam->trans.z += cam->move_speed * cos(PH + cam->rot.y);
            break;
        case UP:
            cam->trans.y += cam->move_speed;
            break;
        case DOWN:
            cam->trans.y -= cam->move_speed;
            break;
    }
}


void turn_camera(struct camera *cam, enum direction dir)
{
    if(dir == UP)
    {
        if(cam->rot.x < PH)
        {
            cam->rot.x -= cam->turn_speed;
        }
    }
    else if(dir == DOWN)
    {
        if(cam->rot.x < PH)
        {
            cam->rot.x += cam->turn_speed;
        }
    }
    else if(dir == LEFT)
    {
        cam->rot.y -= cam->turn_speed;
    }

    else if(dir == RIGHT)
    {
        cam->rot.y += cam->turn_speed;
    }
}

void apply_camera(struct camera *cam)
{
    /* Calc look at vector based on rotation state */
    cam->l.x =  cam->initial.x + cam->trans.x + sin(cam->rot.y);
    cam->l.z = -cam->initial.z - cam->trans.z - cos(cam->rot.y);
    cam->l.y =  cam->initial.y + cam->trans.y + sin(cam->rot.x);

    /* Clear matrix stack */
    glLoadIdentity();
    
    /* Apply transformation */
    gluLookAt(cam->initial.x + cam->trans.x, cam->initial.y + cam->trans.y, -cam->initial.z - cam->trans.z,
              cam->l.x, cam->l.y, cam->l.z,
              cam->up.x, cam->up.y, cam->up.z);

    /* print_camera(cam); */
}

void print_camera(struct camera *cam)
{
    printf("Current camera parameters: \n");
    printf("-> Position: %.3f %.3f %.3f\n", cam->trans.x, cam->trans.y, cam->trans.z);
    printf("-> Rotation: %.3f %.3f %.3f\n", cam->rot.x, cam->rot.y, cam->rot.z);
    printf("-> LookAt  : %.3f %.3f %.3f\n", cam->l.x, cam->l.y, cam->l.z);
    printf("-> ViewUp  : %.3f %.3f %.3f\n\n\n", cam->up.x, cam->up.y, cam->up.z);
}
