#ifndef CAMERA_HPP

#define CAMERA_HPP

typedef struct 
{
   float x;
   float y;
   float z;
} vector;

class Camera 
{
   private:
      vector up;		/* Look up vector */
      vector trans;  	/* Translatation offset from initial pos */
      vector l;		/* Look at point */
      vector rot;		/* Representation of the Euler angles */
      vector initial;	/* Initial position of the camera */
      float turn_speed;		/* Tuning speed (in radians) */
      float move_speed;		/* Move speed in coordinate units */
      void Init(float x, float y, float z);
   public:
      static const double CAM_SENSITIVITY;
      Camera();
      Camera(float x, float y, float z);
      void apply();
      void moveUp();
      void moveDown();
      void moveForward();
      void moveBackward();
      void turnLeft();
      void turnRight();
      void turnUp();
      void turnDown();
      void setTurnSpeed(float s);
      void setSpeed(float s);
      void print_camera();
};
#endif /* end of include guard: CAMERA_HPP */
