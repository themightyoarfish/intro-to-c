#include "Summer.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, const char *argv[])
{
   std::vector<int> v {1,2,3,4,5};
   Summer s = std::for_each(v.begin(), v.end(), Summer());
   std::cout << "Sum is " << s.sum << std::endl;

   return 0;
}
