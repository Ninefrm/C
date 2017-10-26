#include <iostream>
#include "tools.h"

using namespace std;

void test() {
  Line l1 = Line(Point(1.28,2.76), Point(0.49,3.96) );
  Line l2 = Line(Point(2,6), Point(2,0) );

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
