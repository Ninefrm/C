#ifndef _BBOX_H_
#define _BBOX_H_

#include "point.h"

class Bbox {
   public:
      Bbox();
      Bbox( Point pt1, Point pt2 );
      Bbox( double x1, double y1, double x2, double y2 );

      double top() const;
      double bottom() const;
      double right() const;
      double left() const;

      bool inside( Point pt ) const;
      bool inside( double x, double y ) const;
      bool overlap( Bbox other ) const;

   private:
      double m_top;
      double m_bottom;
      double m_right;
      double m_left;
};

#endif

