#include <iostream>
#include "tools.h"

using namespace std;

void test() {
  Line l1 = Line(Point(-4.0,2.0), Point(4.0,2.0) );
  Line l2 = Line(Point(0.0,0.0), Point(4.0,0.0) );

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
