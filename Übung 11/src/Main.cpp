#include "view/MainWindow.hpp"

using namespace std;

int main(int argc, char** argv)
{
   if( argc == 3)
   {
      asteroids::MainWindow* mv = new asteroids::MainWindow(string(argv[1]), string(argv[2]));
      delete mv;
      return 0;
   }
   else
   {
      cout << "Usage: ./viewer <.3ds-File> <number_of_asteroids>" << endl;
      return 0;
   }
}
