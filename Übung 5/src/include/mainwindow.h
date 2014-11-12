#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

/**
 * @file mainwindow.h
 *
 * @brief Program creates a frame with rendering-context using glut for OpenGl
 *
 * @author Tim Kuehnen
 */


/**
 * @brief renders a 3D-scene
 */
void render(void);

/**
 * @brief call-back function for resizing of the frame
 *
 * @param w width
 * @param h heigth
 */
void reshape(int w, int h);

/**
 * @brief call-back function that realizes Keyboard input and prints pressed key on console
 *
 * @param key pressed key
 * @param x x-positon
 * @param y y-position
 */
void keyPressed(unsigned char key, int x, int y);

/**
 * @brief call-back function that realizes mouse-clicks and prints the postion on console
 *
 * @param x x-Position
 * @param y y-position
 */
void mouseMoved(int x, int y);

/**
 * @brief call-back function that realizes mouse-clicks and prints the postion on console
 *
 * @param button pressed 
 * @param state
 * @param x x-Position
 * @param y y-position
 */
void mousePressed(int button, int state, int x, int y);

#endif
