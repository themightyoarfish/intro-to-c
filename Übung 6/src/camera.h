/**
 * @file camera.h
 *
 * @brief Camera management for glut main window
 * @author Thomas Wiemann
 */

#ifndef _camera_h
#define _camera_h

#define PI 3.14159265
#define PH 1.57079632

#define CAM_SENSITY 5

/**
 * @brief 	Helper struct to store 3D points
 */
struct vector
{
    float x;
    float y;
    float z;
};

/**
 * @brief 	Camera representation
 */
struct camera {
    struct vector up;		/* Look up vector */
    struct vector trans;  	/* Translatation offset from initial pos */
    struct vector l;		/* Look at point */
    struct vector rot;		/* Representation of the Euler angles */
    struct vector initial;	/* Initial position of the camera */
    float turn_speed;		/* Tuning speed (in radians) */
    float move_speed;		/* Move speed in coordinate units */
};

/**
 * @brief 	Enum to encode the camera's moving direction
 */
enum direction {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN};


/**
 * @brief 	Initializes the camera at the given position
 *
 * @param cam 			A pointer to a camera struct
 * @param pos			The initial camera position
 * @param rot_speed		The turning / rotation speed of the cam
 * @param move_speed	The moving speed of the cam
 */
void init_camera(
		struct camera *cam, struct vector pos,
		float rot_speed, float move_speed);

/**
 * @brief	Moves the camera in the current x-z plane using
 * 			the internal speed parameters
 *
 * @param cam 	A pointer to a camera struct
 * @param dir	The moving direction
 */
void move_camera(struct camera *cam, enum direction dir);

/**
 * @brief 	Turns the viewer's head
 *
 * @param cam 	A pointer to a camera struct
 * @param dir	The turning direction
 */
void turn_camera(struct camera *cam, enum direction ax);

/**
 * @brief	Converts the internal parameters to a gluLookAt call
 *
 * @param cam 	A pointer to a camera struct
 */
void apply_camera(struct camera *cam);

/**
 * @brief	Prints the current camera parameters to stdout
 */
void print_camera(struct camera *cam);

#endif
