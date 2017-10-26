#ifndef _TOOLS_H_
#define _TOOLS_H_
#include <iostream>
struct Point{
  Point(){
    x=0.0;
    y=0.0;
  }
  Point(double x, double y){
    this->x=x;
    this->y=y;
  }
  double x;
  double y;
};
struct Line{
  Line(Point a, Point b){
    this->a=a;
    this->b=b;
  }
  Point a;
  Point b;
};
bool line_intersection(Line& l1, Line& l2, Point& pt);
bool bbox_inside(double x, double y, Line& ln);

#endif
