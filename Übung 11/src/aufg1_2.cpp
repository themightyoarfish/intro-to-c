#include <functional> // for bind2nd, equal_to, modulus
#include <iostream> 
#include <vector>
#include <iterator> // for ostream_iterator
#include <algorithm> // for remove_if
#include <ext/functional> // non-standard gnu extension for compose1

using namespace std;
int main(int argc, const char *argv[])
{
  vector<int> v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(2);
  v.push_back(8);
  v.push_back(5);
  v.push_back(7);
  
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  // This takes the binary modulus function (g), binds its second argument to 2,
  // binds the second argument of equal_to (f) to 0 and builds a unary function
  // object which given x returns f(g(x)) = equal_to(modulus(x,2),0), meaning it
  // determines whether x is even.
  vector<int>::iterator new_end = 
    remove_if(v.begin(), v.end(), 
              __gnu_cxx::compose1(bind2nd(equal_to<int>(), 0), // namespaces were missing
                       bind2nd(modulus<int>(), 2)));
  
  // wrong iterator as second argument was used. Since remove_if alters the
  // sequence it iterates by replacing the discarded elements by their
  // respective next element which is accepted. As such one must use the
  // returned iterator which points after the last element up to which the
  // sequence is valid.
  copy(v.begin(), new_end, ostream_iterator<int>(cout, " ")); 
  cout << endl;
   
   return 0;
}
