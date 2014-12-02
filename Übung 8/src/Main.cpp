#include "view/MainWindow.hpp"

using namespace std;

#include "io/Read3DS.hpp"
#include "rendering/TexturedMesh.hpp"

int main(int argc, char** argv)
{
    asteroids::MainWindow* mv = new asteroids::MainWindow(string(argv[1]));
    delete mv;
    return 0;
}
