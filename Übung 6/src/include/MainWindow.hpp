/**
 * @file MainWindow.hpp
 *
 * @brief Contains MainWindow class to represent a <tt>GLUT</tt> window.
 * @author Rasmus Diederichsen
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "TriangleMesh.hpp"
#include "Camera.hpp"

/**
 * @class MainWindow
 *
 * @brief Class to represent a <tt>GLUT</tt> window with associated methods.
 * There can be but one instance of this class at a time, hence it is made a
 * singleton.
 */
class MainWindow {

   private:

      /**
       * Private default constructor.
       */
      MainWindow();

      /**
       * Private copy constructor.
       */
      MainWindow(MainWindow const&) {};

      /**
       * Private =-operator to prevent instance creation by assignment.
       */
      MainWindow& operator=(MainWindow const&) {};

      Camera *m_cam; /**< The camera for this window.  */

      TriangleMesh *m_mesh; /**< The model (.ply) rendered in this window.  */

      int m_sizeX, m_sizeY, /**< The window size */ 
          m_mouseState, m_mouseButton, /**< last pressed buttons */ 
          m_oldX, m_oldY;/**< last recorded mouse pointer * coordniates.  */

      static MainWindow* window; /**< The singleton object.  */

      /**
       * Initialises the callbacks for <tt>GLUT</tt>.
       */
      void initCallbacks();

      /**
       * Initialises <tt>GLUT</tt> framework.
       */
      void initGlut();

   public:
      /**
       * Destructor. Deletes the singleton object.
       */
      ~MainWindow();

      /**
       * Acquire the singleton object of this class.
       * @return The singleton object.
       */
      static MainWindow* getInstance();

      /**
       * Set the camera for this window.
       * @param cam Pointer to a {@link Camera} for this window.
       */
      void setCamera(Camera *cam);

      /**
       * Set the model rendered in this window.
       * @param mesh Pointer to a {@link TriangleMesh} for this window.
       */
      void setMesh(TriangleMesh *mesh);

      /**
       * Start the rendering process.
       */
      static void render();

      /**
       * Resize the window.
       * @param x The new horizontal size.
       * @param y The new vertical size.
       */
      static void reshape(int x, int y);

      /**
       * Callback for key presses.
       * @param key The key pressed.
       * @param x The current mouse pointer position.
       * @param y The current mouse pointer position.
       */
      static void keyPressed(unsigned char key, int x, int y);

      /**
       * Callback for passive mouse motion.
       * @param x The current x position.
       * @param y The current y position.
       */
      static void mouseMoved(int x, int y);

      /**
       * Callback for mouse clicks.
       * @param button The mouse button pressed.
       * @param state The state of the button (pressed, release etc.).
       * @param x The current x position.
       * @param y The current y position.
       */
      static void mousePressed(int button, int state, int x, int y);
};

#endif /* end of include guard: MAINWINDOW_HPP */
