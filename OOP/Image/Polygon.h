#ifndef _POLYGONO_H_
#define _POLYGONO_H_

//libraries
#include <vector>
#include "point.h"
#include "line.h"
#include "bbox.h"
#include "shape.h"

class Polygon:public Shape{
  public:
    Polygon();
    Polygon(std::vector <Point> points, Pixel color);
    ~Polygono(){}

    int vectices()const;
    Pixel color()const;

    void color(Pixel color);
    void push(Point pt);


    bool eval(const Point& pt, Pixel& color);

  private:
    Pixel m_color;
    std::vector <Point> m_vpoint;
}
