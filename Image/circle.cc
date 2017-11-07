#include "circle.h"

Circle::Circle() {
   m_radius = 0.0;
}

Circle::Circle( Point center, double radius, Pixel color ) : Circle() {
   if ( radius < 0.0 ) return;
   m_center = center;
   m_radius = radius;
   m_color = color;

   m_topleft.x = m_center.x - radius;
   m_topleft.y = m_center.y - radius;
   m_bottomright.x = m_center.x + radius;
   m_bottomright.y = m_center.y + radius;
}

Point Circle::center() const {
   return m_center;
}

double Circle::radius() const {
   return m_radius;
}

Pixel Circle::color() const {
   return m_color;
}

bool Circle::eval( const Point& point, Pixel& color ) {
   double distance2;

   // check bounding box
   if ( point.x < m_topleft.x     ) return false;
   if ( point.x > m_bottomright.x ) return false;
   if ( point.y < m_topleft.y     ) return false;
   if ( point.y > m_bottomright.y ) return false;

   // check figure
   distance2  = (point.y - m_center.y)*(point.y - m_center.y);
   distance2 += (point.x - m_center.x)*(point.x - m_center.x);
   if ( distance2 > m_radius*m_radius ) return false;

   // return the circle's color
   color = m_color;
   return true;
}

