#ifndef __MAIN_H
#define __MAIN_H

/** Vertex buffer for rendering */
float*  rvBuffer = 0;

/** Number of vertices in vertex buffer */
int     rvCount  = 0;

/** Index buffer for rendering */
int*    riBuffer = 0;

/** Number of triangles in index buffer */
int     riCount  = 0;

/** Old positions of mouse (needed for detection of mouse movement) */
int     old_x;
int     old_y;
int     mouse_state;
int     mouse_button;

/** A pointer to a camera */
struct camera* cam;

/**
 * @brief Wrapper function to register free function on exit callback 
 */
void call_freeobj(void);

#endif
