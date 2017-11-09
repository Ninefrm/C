#ifndef _LINE_H_
#define _LINE_H_

#include "point.h"
#include "bbox.h"

class Line {
   public:
      Line();
      Line( Point a, Point b );

      bool inter( Line other );
      Point interp( Line other );
      double dist( Point pt );

      bool operator==( Line other );
      bool operator!=( Line other );

   private:
      Point a;
      Point b;
};

#endif

