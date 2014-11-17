#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include "TriangleMesh.hpp"
#include "Camera.hpp"

class MainWindow {
   private:
      MainWindow();
      MainWindow(MainWindow const&) {};
      MainWindow& operator=(MainWindow const&) {};
      Camera *cam;
      TriangleMesh *mesh;
      int sizex, sizey,
          mouse_state, mouse_button,
          old_x, old_y;
      static MainWindow* window;
      void initCallbacks();
      void initGlut();
   public:
      ~MainWindow();
      static MainWindow* getInstance();
      void setCamera(Camera *cam);
      void setMesh(TriangleMesh *mesh);
      static void render();
      static void reshape(int x, int y);
      static void keyPressed(unsigned char key, int x, int y);
      static void mouseMoved(int x, int y);
      static void mousePressed(int button, int state, int x, int y);
};

#endif /* end of include guard: MAINWINDOW_HPP */
