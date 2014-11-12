#include <glut.h>
#include <stdio.h>

int last_button = -1;
void render(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
   glVertex3f(-2,-2,-5.0);
   glVertex3f(2,0.0,-5.0);
   glVertex3f(0.0,2,-5.0);

   glEnd();

   glutSwapBuffers();

}

void reshape(int w, int h)
{
   if(h == 0)
      h = 1;
   float ratio = 1.0* w / h;

   glMatrixMode(GL_PROJECTION);

   glLoadIdentity();

   glViewport(0, 0, w, h);

   gluPerspective(45,ratio,1,1000);

   glMatrixMode(GL_MODELVIEW);

}

void keyPressed(unsigned char key, int x, int y)
{
   /* \r escape sequence puts cursor to the start of line, overwriting already printed chars */
   printf("\rThe key pressed was %c. Mouse coordinates are (%d,%d).", 
         key, x, y);
   fflush(stdout);
}

void mouseMoved(int x, int y)
{
   printf("\r(%d,%d)%50s",x,y,"");
   fflush(stdout);
}

void mouseMovedAndClicked(int x, int y)
{
   mouseClicked(last_button,0,x,y);
}

void mouseClicked(int button, int state, int x, int y)
{
   printf("\r(%d,%d)", x, y);
   last_button = button;
   switch(button)
   {
      case GLUT_LEFT_BUTTON:
         printf(" + left button");
         break;
      case GLUT_RIGHT_BUTTON:
         printf(" + right button");
         break;
      case GLUT_MIDDLE_BUTTON:
         printf(" + middle button");
         break;
   }
   printf("%50s","");
   fflush(stdout);
}

