#include "line.h"

Line::Line() {
   a = Point();
   b = Point();
}

Line::Line( Point a, Point b ) {
   this->a = a;
   this->b = b;
}

// dice si la linea 'other' intersecta a esta línea (this)
bool Line::inter( Line other ) {
   double m1, m2, b1, b2;
   double x, y;
   bool v1, v2;

   // hack barato
   Line l1 = Line(a,b);
   Line l2 = Line(other.a, other.b);

   v1 = (l1.a.x == l1.b.x);
   v2 = (l2.a.x == l2.b.x);

   // Líneas paralelas y verticales
   if (v1 && v2) return false;

   if ( v1 ) {
      m2 = (l2.b.y - l2.a.y)/(l2.b.x - l2.a.x);
      b2 = l2.b.y - m2*l2.b.x;

      x = l1.a.x;
      y = m2*x + b2;
   }
   else if ( v2 ) {
      m1 = (l1.b.y - l1.a.y)/(l1.b.x - l1.a.x);
      b1 = l1.b.y - m1*l1.b.x;

      x = l2.a.x;
      y = m1*x + b1;
   }
   else {
      m1 = (l1.b.y - l1.a.y)/(l1.b.x - l1.a.x);
      m2 = (l2.b.y - l2.a.y)/(l2.b.x - l2.a.x);

      // si las pendientes son iguales, líneas paralelas
      if ( m1 == m2 ) return false;

      b1 = l1.b.y - m1*l1.b.x;
      b2 = l2.b.y - m2*l2.b.x;

      x = -(b2 - b1)/(m2 - m1);
      y = m1*x + b1;
   }

   // si el punto no está dentro de alguno de los bounding boxes
   // entonces no hay intersección
   // if ( !bbox_inside(x, y, l1) ) return false;
   // if ( !bbox_inside(x, y, l2) ) return false;

   if ( !Bbox(l1.a,l1.b).inside(x,y) ) return false;
   if ( !Bbox(l2.a,l2.b).inside(x,y) ) return false;

   // pasó todas las pruebas, sí hay intersección
   return true;
}

// regresa el punto de intersección entre esta linea (this) y 'other'
Point Line::interp( Line other ) {
   double m1, m2, b1, b2;
   double x, y;
   bool v1, v2;
   Point inter = Point(NAN,NAN);

   // hack barato
   Line l1 = Line(this->a, this->b);
   Line l2 = Line(other.a, other.b);

   v1 = (l1.a.x == l1.b.x);
   v2 = (l2.a.x == l2.b.x);

   // Líneas paralelas y verticales
   if (v1 && v2) return inter;

   if ( v1 ) {
      m2 = (l2.b.y - l2.a.y)/(l2.b.x - l2.a.x);
      b2 = l2.b.y - m2*l2.b.x;

      x = l1.a.x;
      y = m2*x + b2;
   }
   else if ( v2 ) {
      m1 = (l1.b.y - l1.a.y)/(l1.b.x - l1.a.x);
      b1 = l1.b.y - m1*l1.b.x;

      x = l2.a.x;
      y = m1*x + b1;
   }
   else {
      m1 = (l1.b.y - l1.a.y)/(l1.b.x - l1.a.x);
      m2 = (l2.b.y - l2.a.y)/(l2.b.x - l2.a.x);

      // si las pendientes son iguales, líneas paralelas
      if ( m1 == m2 ) return inter;

      b1 = l1.b.y - m1*l1.b.x;
      b2 = l2.b.y - m2*l2.b.x;

      x = -(b2 - b1)/(m2 - m1);
      y = m1*x + b1;
   }

   // si el punto no está dentro de alguno de los bounding boxes
   // entonces no hay intersección
   if ( !Bbox(l1.a,l1.b).inside(x,y) ) return inter;
   if ( !Bbox(l2.a,l2.b).inside(x,y) ) return inter;


   // regresa el punto de intersección por referencia
   inter = Point(x,y);

   // pasó todas las pruebas, sí hay intersección
   return inter;
}

// distancia de un punto a la línea
double Line::dist( Point pt ) {
   return 0.0;
}

bool Line::operator==( Line other ) {
   if ( a != other.a ) return false;
   if ( b != other.b ) return false;
   return true;
}

bool Line::operator!=( Line other ) {
   return !operator==(other);
}

