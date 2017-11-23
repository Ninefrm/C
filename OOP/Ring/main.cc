#include <iostream>
#include "ring.h"
using namespace std;

int main() {

   Ring<int> carray(5);

   cout << "capacity = " << carray.capacity() << endl;
   cout << "size     = " << carray.size() << endl;

   carray.push_back(1);
   carray.push_back(2);
   carray.push_back(3);
   carray.push_back(4);
   carray.push_back(5);
   carray.push_back(6);
   carray.push_back(7);

   cout << "---" << endl;
   cout << "capacity = " << carray.capacity() << endl;
   cout << "size     = " << carray.size() << endl;
   cout << "front    = " << carray.front() << endl;
   cout << "back     = " << carray.back() << endl;

   return 0;
}

