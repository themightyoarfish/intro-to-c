#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

/**
 *  @file  MainWindow.hpp
 *
 *  @date  27.11.2011
 *  @author Thomas Wiemann
 */

/**
 * @brief OpenGL / glut related headers
 */
#ifdef __APPLE__
#include <OpenGL/gl.h>		// Header File For The OpenGL Library
#include <OpenGL/glu.h>		// Header File For The GLu Library
#include <glut.h>		// Header File For The glut toolkit
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>		// Header File For The glut toolkit
#endif

/**
 * @brief Standard C++ headers
 */
#include <iostream>		// Header for standard I/O
#include <string>
#include <map>

using std::string;
using std::map;

/**
 * @brief Project related includes
 */
#include "Camera.hpp"					// Camera class
#include "rendering/Fighter.hpp"
#include "rendering/Skybox.hpp"
#include "math/Global.hpp"
#include "io/Logger.hpp"

#include "rendering/AsteroidField.hpp"
namespace asteroids
{

/**
 * @brief   A simple main window class the wraps a glut window
 */
class MainWindow
{

public:

	/**
	 * @brief   Default constructor. Creates a window at position (100,100)
	 *          with size 762 x 576 pixels.
	 */
	MainWindow(string filename, string quantity_asteroids);

	/**
	 * @brief   Destructor.
	 */
	~MainWindow();

	/**
	 * @brief   A static function used to re-route reshape callbacks to the
	 *          current main window instance.
	 * @param w width
	 * @param h height
	 */
	static void callback_reshape(int w, int h);

	/**
	 * @brief   A static function used to re-route render callbacks to the
	 *          current main window instance.
	 */
	static void callback_render();

	/**
	 * @brief   A static function used to re-route keyboard callbacks to the
	 *          current main window instance.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	static void callback_key(unsigned char key, int x, int y);

	/**
	 * @brief   A static function used to re-route keyboard callbacks to the
	 *          current main window instance.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	static void callback_keyUp(unsigned char key, int x, int y);

	/**
	 * @brief   A static function used to re-route special keyboard callbacks to the
	 *          current main window instance.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	static void callback_specialkey(int key, int x, int y);

	/**
	 * @brief   A static function used to re-route special keyboard callbacks to the
	 *          current main window instance.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	static void callback_specialkeyUp(int key, int x, int y);

	/**
	 * @brief   A static function used to re-route mouse callbacks to the
	 *          current main window instance.
	 * @param button button
	 * @param state state
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	static void callback_mouse(int button, int state, int x, int y);

	/**
	 * @brief   A static function used to re-route motion callbacks to the
	 *          current main window instance.
	 * @param x x-coordinate
	 * @param y y-coordinate
	 */
	static void callback_motion(int x, int y);

        /**
         * @brief   A timer to call the render function
         */
        static void callback_timer(int value);

	/**
	 * @brief   A pointer to the current MainWindow instance.
	 */
	static MainWindow* master;

	/**
	 * @brief   The render function of the main window. All rendering calls
	 *          have to start here
	 */
	void render();

	/**
	 * @brief   The reshape callback function. Handles resizing events from
	 *          the main window, i.e. handles the aspect ratio
	 * @param w width
	 * @param h height
	 */
	void reshape(int w, int h);

	/**
	 * @brief   The keyboard callback method.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	void keyPressed(unsigned char key, int x, int y);

	/**
	 * @brief   The keyboard callback method.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	void keyUp(unsigned char key, int x, int y);

	/**
	 * @brief   The special keyboard callback method.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	void specialkeyPressed(int key, int x, int y);

	/**
	 * @brief   The special keyboard callback method.
	 * @param key key
	 * @param x x-coordinate (mouse)
	 * @param y y-coordinate (mouse)
	 */
	void specialkeyUp(int key, int x, int y);

	/**
	 * @brief   Controller for moving and rotation
	 */
	void keyOperations(void);

	/**
	 * @brief   This function is called whenever the mouse was moved
	 * @param x x-coordinate
	 * @param y y-coordinate
	 */
	void mouseMoved(int x, int y);

	/**
	 * @brief   This function is called when the mouse was clicked
	 * @param button button
	 * @param state state
	 * @param x x-coordinate
	 * @param y y-coordinate
	 */
	void mousePressed(int button, int state, int x, int y);

	/**
	 * @brief The viewer camera
	 */
	static Camera   m_cam;

private:

	/**
	 * @brief   Initializes the glut window
	 */
	void initGlut();

	/**
	 * @brief   Initializes OpenGL
	 */
	void initGL();

	/**
	 * @brief   Moves the camera in the xy plane if dx and / or dy are > MOUSE_SENSITY
	 * @param dx dx
	 * @param dy dy
	 */
	void moveXY(int dx, int dy);

	/**
	 * @brief   Moves the camera in the zx plane dy is > MOUSE_SENSITY
	 * @param dy dy
	 */
	void moveZ(int dy);

	/**
	 * @brief   Turns the camera around the given axes if dx and / or dy are > MOUSE_SENSITY
	 * @param dx dx
	 */
	void moveHead(int dx, int dy);


	AsteroidField* m_asteroidField;
	/**
	 * @brief The displayer triangle mesh
	 */
	Fighter*	m_fighter;

	/**
	 * @brief A skybox for the scene
	 */
	Skybox* m_skybox;

	/**
	 * @brief The last reported x position of the mouse
	 */
	int	m_mouseX;

	/**
	 * @brief The last reported y position
	 */
	int	m_mouseY;

	/**
	 * @brief The last pressend mouse button
	 */
	int	m_button;

	/**
	 * @brief The last reported mouse button state
	 */
	int	m_buttonState;

	/**
	 * @brief The state of the keyboard
         */
	bool			m_keyStates[256];

	/**
	 * @brief The state of the keyboard (for special keys)
         */
	bool			m_specialkeyStates[256];

	/// Logger for timestamped output
	Logger			m_logger;
};

} // namespace asteroids

#endif
