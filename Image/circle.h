#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "pixel.h"
#include "point.h"
#include "shape.h"

// Por default, todo es privado
class Circle : public Shape {
   public:
      Circle();
      Circle( Point center, double radius, Pixel color=Pixel(255,255,255) );

      // accessors
      Point center() const;
      double radius() const;
      Pixel color() const;

      bool eval( const Point& pt, Pixel& color );

   private:
      Point  m_center;
      double m_radius;
      Pixel  m_color;

      // bounding box
      Point m_topleft; // top-left
      Point m_bottomright; // bottom-right
};

#endif

