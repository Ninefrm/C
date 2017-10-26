#include "tools.h"
bool bbox_inside(double x, double y,Line& ln){
  double x_min, x_max, y_min, y_max;
  if(ln.a.x<ln.b.x){
    x_min=ln.a.x;
    x_max=ln.b.x;
  }
  else{
      x_min=ln.b.x;
      x_max=ln.a.x;
  }
  if(ln.a.y<ln.b.y){
      y_min=ln.a.y;
      y_max=ln.b.y;
    }
    else{
        y_min=ln.b.y;
        y_max=ln.a.y;
    }
    std::cout<<"Valor de X: "<<x<<std::endl;
    std::cout<<"Valor de Y: "<<y<<std::endl;
    std::cout<<"Valor x_Max: "<<x_max<<std::endl;
    std::cout<<"Valor y_Max: "<<y_max<<std::endl;
    if(x<x_min||x>x_max)return false;
    if(y<y_min||x>y_max)return false;

    return true;
}

bool line_intersection(Line& l1, Line& l2, Point& pt){
  double m1, m2,b2, b1;
  double x,y;
  bool v1,v2;

  v1=(l1.a.x==l1.b.x);
  v2=(l2.a.x==l2.b.x);

  //lineas verticales
  if(v1 && v2){
    std::cout<<"Lineas verticales"<<std::endl;
    return false;
  }
  if(v1){
    m2=(l2.b.y - l2.a.y)/(l2.b.x-l2.a.x);
    b2=l2.b.y-m2*l2.b.x;

    x=l2.a.x;
    y=m2*x+b2;
  }
  if(v2){
    m1=(l1.b.y - l1.a.y)/(l1.b.x-l1.a.x);
    b1=l1.b.y-m1*l1.b.x;

    x=l2.a.x;
    y=m1*x+b1;
  }
  else{
    m1=(l1.b.y - l1.a.y)/(l1.b.x-l1.a.x);
    m2=(l2.b.y - l2.a.y)/(l2.b.x-l2.a.x);
    if(m1==m2){
      std::cout<<"Pendiente 1 es igual a Pendiente 2"<<std::endl;
      return false;
    }
    b1=l1.b.y-m1*l1.b.x;
    b2=l2.b.y-m2*l2.b.x;

    x=-(b2-b1)/(m2-m1);
    y=m1*x+b1;
  }
  std::cout<<"Comprobacion en Linea 1"<<std::endl;
  if(!bbox_inside(x,y,l1)){
    std::cout<<"Sale en comprobación Linea 1"<<std::endl;
    return false;
  }
  std::cout<<"Comprobacion en Linea 2"<<std::endl;
  if(!bbox_inside(x,y,l2)){
    std::cout<<"Sale en comprobación con Linea 2."<<std::endl;
    return false;
  }
  pt=Point(x,y);
  return true;
}
