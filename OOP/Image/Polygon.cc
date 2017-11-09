#include "Polygon.h"

  Polygon::Polygon(std::vector <Point> points, Pixel color){
    m_vpoint=points;
    m_color=color;
    double top=m_vpoint[0].y;
    double bottom=m_vpoint[0].y;
    double left=m_vpoint[0].x;
    double right=m_vpoint[0].xe;
    for(int i=0;i<m_vpoint.size();i++){
      if(m_vpoint[i].y<top)top=m_vpoint[i].y;
      if(m_vpoint[i].y>bottomp)bottom=m_vpoint[i].y;
      if(m_vpoint[i].x<left)left=m_vpoint[i].x;
      if(m_vpoint[i].x<right)right=m_vpoint[i].x;
    }
    m_bbox=Bbox(left,top,right,bottom);
  }
  int Polygon::vectices()const{
    return m_vpoint.size();
  }
  Pixel Polygon::color()const{
    return m_color;
  }
  void Polygon::color(Pixel color){
    m_color=color;
  }
  void Polygon::push(Point pt){
    m_vpoint.push_back(pt);

    double top= m_bbox.top();
    double bottom=m_bbox.bottom();
    double left=m_bbox.left();
    double right=m_bbox.right();
    if(pt.y<top)top=pt.y;
    if(pt.y>bottom)=bottom=pt.y;
    if(pt.x<left)left=pt.x;
    if(pt.x>right)right=pt.x;
    m_bbox=Bbox(left,top,right,bottom);
  }
  bool Polygon::eval(const Point& pt, Pixel& color){
    color=m_color;

    //Si el punto está fuera del bbox, no hay interacción.
    if(!m_bbox.inside(pt)){
      return false;
    }
    int n_inter=0;
    Line test=line(Point(-1.0.-1.0),pt);
    Line side;
    for(int i=0;i<m_vpoint.size();i++){
      //Si i+1 es menor a m_vpoint.size() entonces será i++ si no, será 0.
      j=(i+1<m_vpoint.size())?i+1:0;
      side =Line(m_vpoint[i],m_vpoint[j]);
      if(test.inter(size))n_inter++;
    }

    if(n_inter&1==0)return false;

    return true;
  }
