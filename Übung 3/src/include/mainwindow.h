#ifndef MAINWINDOW_MLTZT4GG

#define MAINWINDOW_MLTZT4GG

/**
 * @brief GLUT callback for rendering the window content.
 */
void render(void);

/**
 * @brief GLUT callback invoked upon changes of window size.
 * @param w The new width.
 * @param h The new height.
 */
void reshape(int w, int h);

/**
 * @brief GLUT callback processing key presses when window has focus.
 * @param key The key pressed.
 * @param x The x coordinate of the mouse at the time of key press.
 * @param y The y coordinate of the mouse at the time of key press.
 */
void keyPressed(unsigned char key, int x, int y);

/** 
 * @brief GLUT callback invoked when mouse is clicked in window.
 * @param button The mouse button clicked.
 * @param x The x coordinate of the mouse at the time of key press.
 * @param y The y coordinate of the mouse at the time of key press.
 */
void mouseMoved(int button, int state, int x, int y);

#endif /* end of include guard: MAINWINDOW_MLTZT4GG */
