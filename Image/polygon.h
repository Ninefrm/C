#ifndef _POLYGON_H_
#define _POLYGON_H_

// libraries
#include <vector>
#include "point.h"
#include "line.h"
#include "pixel.h"
#include "bbox.h"
#include "shape.h"

class Polygon : public Shape {
   public:
      Polygon() { };
      Polygon( std::vector<Point> points, Pixel color );
      ~Polygon() { };

      int vertices() const;
      Pixel color() const;

      void color( Pixel color );
      void push( Point pt );

      // evalúa si un punto está dentro de una figura o no
      bool eval( const Point& pt, Pixel& color );

   private:
      Pixel m_color;
      std::vector<Point> m_vpoint;
      Bbox m_bbox;
};

#endif

