#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, const char *argv[])
{
   stringstream ss;
   ss << 'a';
      char i;
   ss >> i;
   printf("%x\n",i);
   return 0;
}
