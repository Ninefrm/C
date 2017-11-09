#include "box.h"

Box::Box( Point topleft, Point bottomright, Pixel color ) {
   if ( topleft.x > bottomright.x ) return;
   if ( topleft.y > bottomright.y ) return;

   m_topleft = topleft;
   m_bottomright = bottomright;
   m_color = color;
}

Point Box::topleft() const {
   return m_topleft;
}

Point Box::bottomright() const {
   return m_bottomright;
}

Pixel Box::color() const {
   return m_color;
}

bool Box::eval( const Point& point, Pixel& color ) {

   // check bounding box
   if ( point.x < m_topleft.x     ) return false;
   if ( point.x > m_bottomright.x ) return false;
   if ( point.y < m_topleft.y     ) return false;
   if ( point.y > m_bottomright.y ) return false;

   // return the circle's color
   color = m_color;
   return true;
}

