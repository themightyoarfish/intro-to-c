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
      cout << "Usage: Bitte wie folgt ausführen ./viewer `model-flieger` `anzahl-Asteroiden`" << endl;
      return 0;
   }
}
