#include "view/MainWindow.hpp"

using namespace std;

#include "io/Read3DS.hpp"
#include "rendering/TexturedMesh.hpp"
/* #include "util/List.hpp" */

/* void putInt(int i) */ 
/* { */
/*    cout << "element is: " << i << endl; */
/* } */
int main(int argc, char** argv)
{
   /* List<int> l; */
   /* for (int i = 0; i < 5; i++) */ 
   /* { */
   /*    l.insert(i); */
   /* } */

   /* l.for_each(putInt); */
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
