#ifndef _BOX_H
#define _BOX_H_

#include "pixel.h"
#include "point.h"
#include "shape.h"

// Por default, todo es privado
class Box : public Shape {
   public:
      Box() { };
      Box( Point topleft, Point bottomright, Pixel color=Pixel(255,255,255) );

      // accessors
      Point topleft() const;
      Point bottomright() const;
      Pixel color() const;

      bool eval( const Point& pt, Pixel& color );

   private:
      Point m_topleft;
      Point m_bottomright;
      Pixel  m_color;
};

#endif

