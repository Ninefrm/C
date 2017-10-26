#include <iostream>
#include "tools.h"

using namespace std;

void test() {
  Line l1 = Line(Point(-3.12,1.58), Point(2,5) );
  Line l2 = Line(Point(2.0,1.0), Point(-1.0,5.0) );

  Point pt;
  if(line_intersection(l1,l2,pt) != false){
    cout <<"Existe intersección"<<endl;
  }
  else{
    cout<<"No existe una interseccion"<<endl;
  }
}
int main(void){
  test();
  return 0;
}
