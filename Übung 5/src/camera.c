#include <camera.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <glut.h>
#else 
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>

typedef struct vector vector;
typedef struct camera camera;

/* Functions to do multiply with rotation matrix */
void rotateX(vector *v, float angle);
void rotateY(vector *v, float angle);

void init_camera(camera *cam, vector pos,
      float rot_speed, float move_speed)
{
   vector up = { .x = 0, .y = 1, .z = 0 },
          trans = { .x = 0, .y = 0, .z = 0 },
          rot = { .x = 0, .y = 0, .z = 0 },
          look_at = { .x = 0, .y = 0, .z = -1 };
   cam->up = up;
   cam->trans = trans;
   cam->l = look_at;
   cam->rot = rot;
   cam->initial = pos;
   cam->turn_speed = rot_speed;
   cam->move_speed = move_speed;
}

void move_camera(camera *cam, enum direction dir)
{
   /* Vector for direction of gaze */
   vector forward = {.x = 0, .y = 0, .z = 1};
   rotateY(&forward,cam->rot.y);

   /* This vector will be perpendicular, but with the same y-value */
   vector perp  = { .x = -forward.z, 
                           .y = forward.y, 
                           .z = forward.x
                  };

   switch (dir)
   {
      case FORWARD: 
         /* Move camera */
         cam->trans.x += cam->move_speed * forward.x;
         cam->trans.y += cam->move_speed * forward.y;
         cam->trans.z += cam->move_speed * forward.z;
         /* Move view point since its supposed to be at distance 1 */
         /* cam->l.x += cam->move_speed * forward.x; */
         /* cam->l.y += cam->move_speed * forward.y; */
         /* cam->l.z += cam->move_speed * forward.z; */
         break;
      case BACKWARD: 
         cam->trans.x -= cam->move_speed * forward.x;
         cam->trans.y -= cam->move_speed * forward.y;
         cam->trans.z -= cam->move_speed * forward.z;
         /* cam->l.x -= cam->move_speed * forward.x; */
         /* cam->l.y -= cam->move_speed * forward.y; */
         /* cam->l.z -= cam->move_speed * forward.z; */
         break;
      case LEFT: 
         /* Move along perpendicular */
         cam->trans.x -= cam->move_speed * perp.x;
         cam->trans.z -= cam->move_speed * perp.z;
         break;
      case RIGHT: 
         cam->trans.x += cam->move_speed * perp.x;
         cam->trans.z += cam->move_speed * perp.z;
         break;
      case UP: 
         cam->trans.y += cam->move_speed;
         break;
      case DOWN: 
         cam->trans.y -= cam->move_speed;
         break;
   }
}

void turn_camera(camera *cam, enum direction ax)
{
	switch (ax)
	{
		case LEFT:	cam->rot.y += (cam->turn_speed);
						break;

		case RIGHT:	cam->rot.y -= (cam->turn_speed);
						break;

		case UP:		cam->rot.x += (cam->turn_speed);
						break;

		case DOWN:	cam->rot.x -= (cam->turn_speed);
						break;
      default: fprintf(stderr, "turn_camer error: invalid axis %d.\n", ax);
               break;
	}

}

void apply_camera(camera *cam)
{
   glLoadIdentity();
   vector pos;
   pos.x = cam->initial.x + cam->trans.x;
   pos.y = cam->initial.y + cam->trans.y;
   pos.z = cam->initial.z + cam->trans.z; 

   vector forward = { .x = 0, .y = 0, .z = 1. };

   /* lookAt vector can be rotated in xz-plane or up/downwards */
   rotateX(&forward, cam->rot.x);
   rotateY(&forward, cam->rot.y);

   cam->l.x = forward.x + pos.x;
   cam->l.y = forward.y + pos.y;
   cam->l.z = forward.z + pos.z;

   gluLookAt(pos.x, pos.y, pos.z,
         cam->l.x, cam->l.y, cam->l.z,
         cam->up.x, cam->up.y, cam->up.z);
}

void print_camera(camera *cam)
{
   printf("%-20s [%5.4f,%5.4f,%5.4f]\n", "up:",cam->up.x,cam->up.y,cam->up.z);
   printf("%-20s [%5.4f,%5.4f,%5.4f]\n", "trans:",cam->trans.x,cam->trans.y,cam->trans.z);
   printf("%-20s [%5.4f,%5.4f,%5.4f]\n", "l:",cam->l.x,cam->l.y,cam->l.z);
   printf("%-20s [%5.4f,%5.4f,%5.4f]\n", "rot:",cam->rot.x,cam->rot.y,cam->rot.z);
   printf("%-20s [%5.4f,%5.4f,%5.4f]\n", "initial:",cam->initial.x,cam->initial.y,cam->initial.z);
   printf("%-20s %5.4f\n","turn_speed:", cam->turn_speed);
   printf("%-20s %5.4f\n","move_speed:", cam->move_speed);
}

void rotateX(vector *v, float angle)
{
	v->y = (float)cos(angle) * v->y  - (float)sin(angle) * v->z;
	v->z = (float)sin(angle) * v->y  + (float)cos(angle) * v->z;
}

void rotateY(vector *v, float angle)
{
	v->x = (float)cos(angle) * v->x	 - (float)sin(angle) * v->z;
	v->z = -(float)sin(angle) * v->x + (float)cos(angle) * v->z;
}
