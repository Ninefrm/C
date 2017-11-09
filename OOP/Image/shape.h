#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "point.h"

class Shape {
   public:
      Shape() { }
      virtual ~Shape() { }

      // evalúa si un punto está dentro de una figura o no
      virtual bool eval( const Point& pt, Pixel& color ) = 0;

   private:
};

#endif

