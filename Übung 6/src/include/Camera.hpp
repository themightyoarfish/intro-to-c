/**
 * @file Camera.hpp
 * 
 * Camera class definition with auxiallary struct.
 * @author Rasmus Diederichsen
 */
#ifndef CAMERA_HPP

#define CAMERA_HPP

#include <string>

/**
 * @struct vector
 *
 * @brief Structure representing a vector.
 */
typedef struct 
{
   float x;
   float y;
   float z;
} vector;

/**
 * @class Camera
 *
 * @brief Class to represent the camera in a GLUT-rendered scene.
 * Contains functions to set position, motion and speed of the camera.
 */
class Camera 
{
   private:
      vector up;		/**< Look up vector */
      vector trans;  	/**< Translatation offset from initial pos */
      vector l;		/**< Look at point */
      vector rot;		/**< Representation of the Euler angles */
      vector initial;	/**< Initial position of the camera */
      float turn_speed;		/**< Tuning speed (in radians) */
      float move_speed;		/**< Move speed in coordinate units */

      /** 
       * Contructor surrogate since C++ has no constructor chaining.
       *
       * @param x x coordinate of camera position.
       * @param y y coordinate of camera position.
       * @param z z coordinate of camera position.
       */
      void Init(float x, float y, float z); 

   public:
      /**
       * the camera sensitivity, i.e. the number of pixels the mouse pointer mus
       * move to be registered as a camera motion.
       */
      static const double CAM_SENSITIVITY;

      /**
       * Default constructor. Will set the camera's position to (0,0,0).
       */
      Camera();

      /**
       * Constructor will set the camera's position to (x,y,z).
       * @param x The x coordinate of the camera's position.
       * @param y The y coordinate of the camera's position.
       * @param z The z coordinate of the camera's position.
       */
      Camera(float x, float y, float z);

      /**
       * Method to translate the camera's current state into a <tt>
       * gluLookAt()</tt> call.
       */
      void apply();

      /**
       * Move the camera upwards (translation).
       */
      void moveUp();

      /**
       * Move the camera upwards (translation).
       */
      void moveDown();

      /**
       * Move the camera forward (translation).
       */
      void moveForward();

      /**
       * Move the camera backward (translation).
       */
      void moveBackward();

      /**
       * Turn the camera left (rotation).
       */
      void turnLeft();

      /**
       * Turn the camera right (rotation).
       */
      void turnRight();

      /**
       * Turn the camera upwards (rotation).
       */
      void turnUp();

      /**
       * Turn the camera downwards (rotation).
       */
      void turnDown();

      /**
       * Adjust the turn speed of the camera.
       *
       * @param s The amount added to rotation radians for turning motions.
       */
      void setTurnSpeed(float s);

      /**
       * Adjust the translation speed of camera.
       * @param s The amount added to the translation vector for translative
       * motions.
       */
      void setSpeed(float s);

      /**
       * Returns a string representation of the camera.
       *
       * @return A string holding this camera's current state.
       */
       std::string to_string();
};
#endif /* end of include guard: CAMERA_HPP */
