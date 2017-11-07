#include "bbox.h"


Bbox::Bbox() {
   m_top = 0.0;
   m_bottom = 0.0;
   m_right = 0.0;
   m_left = 0.0;
}

Bbox::Bbox( Point pt1, Point pt2 ) : Bbox() {

   if ( pt1.x > pt2.x ) {
      m_right = pt1.x;
      m_left = pt2.x;
   }
   else {
      m_right = pt2.x;
      m_left = pt1.x;
   }

   if ( pt1.y < pt2.y ) {
      m_top = pt1.y; // el eje y en imágenes está invertido
      m_bottom = pt2.y;
   }
   else {
      m_top = pt2.y;
      m_bottom = pt1.y;
   }
}

Bbox::Bbox( double x1, double y1, double x2, double y2 ) : Bbox() {

   if ( x1 > x2 ) {
      m_right = x1;
      m_left = x2;
   }
   else {
      m_right = x2;
      m_left = x1;
   }

   if ( y1 < y2 ) {
      m_top = y1; // el eje y en imágenes está invertido
      m_bottom = y2;
   }
   else {
      m_top = y2;
      m_bottom = y1;
   }

}

double Bbox::top() const {
   return m_top;
}

double Bbox::bottom() const {
   return m_bottom;
}

double Bbox::right() const {
   return m_right;
}

double Bbox::left() const {
   return m_left;
}

// determina si un punto está dentro del bbox
bool Bbox::inside( Point pt ) const {
   if ( pt.x < m_left ) return false;
   if ( pt.x > m_right ) return false;
   if ( pt.y < m_top ) return false;
   if ( pt.y > m_bottom ) return false;
   return true;
}

// determina si un punto está dentro del bbox
// expresado por sus coordenadas (x,y)
bool Bbox::inside( double x, double y ) const {
   if ( x < m_left ) return false;
   if ( x > m_right ) return false;
   if ( y < m_top ) return false;
   if ( y > m_bottom ) return false;
   return true;
}

// determina si dos objetos Bbox se traslapan
// osea, dice si las cajas están empalmadas o no
bool Bbox::overlap( Bbox other ) const {
   bool overx = false;
   bool overy = false;

   // this
   if ( other.m_left   >= m_left && other.m_left   <= m_right  ) overx = true;
   if ( other.m_right  >= m_left && other.m_right  <= m_right  ) overx = true;
   if ( other.m_top    >= m_top  && other.m_top    <= m_bottom ) overy = true;
   if ( other.m_bottom >= m_top  && other.m_bottom <= m_bottom ) overy = true;

   if ( overx && overy ) return true;
   overx = false;
   overy = false;

   // other
   if ( m_left   >= other.m_left && m_left   <= other.m_right  ) overx = true;
   if ( m_right  >= other.m_left && m_right  <= other.m_right  ) overx = true;
   if ( m_top    >= other.m_top  && m_top    <= other.m_bottom ) overy = true;
   if ( m_bottom >= other.m_top  && m_bottom <= other.m_bottom ) overy = true;

   if ( overx && overy ) return true;

   return false;
}

