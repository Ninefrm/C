#include "polygon.h"

Polygon::Polygon( std::vector<Point> points, Pixel color ) {
   m_vpoint = points;
   m_color = color;

   double top    = m_vpoint[0].y;  // y1
   double bottom = m_vpoint[0].y;  // y2
   double left   = m_vpoint[0].x;  // x1
   double right  = m_vpoint[0].x;  // x2

   for ( size_t i=1; i<m_vpoint.size(); i++ ) {
      if ( m_vpoint[i].y < top    ) top    = m_vpoint[i].y;
      if ( m_vpoint[i].y > bottom ) bottom = m_vpoint[i].y;
      if ( m_vpoint[i].x < left   ) left   = m_vpoint[i].x;
      if ( m_vpoint[i].x > right  ) right  = m_vpoint[i].x;
   }

   m_bbox = Bbox(left,top,right,bottom);
}

int Polygon::vertices() const {
   return m_vpoint.size();
}

Pixel Polygon::color() const {
   return m_color;
}

void Polygon::color( Pixel color ) {
   m_color = color;
}

void Polygon::push( Point pt ) {
   m_vpoint.push_back(pt);

   double top    = m_bbox.top();
   double bottom = m_bbox.bottom();
   double left   = m_bbox.left();
   double right  = m_bbox.right();

   if ( pt.y < top    ) top    = pt.y;
   if ( pt.y > bottom ) bottom = pt.y;
   if ( pt.x < left   ) left   = pt.x;
   if ( pt.x > right  ) right  = pt.x;

   m_bbox = Bbox(left,top,right,bottom);
}

bool Polygon::eval( const Point& pt, Pixel& color ) {

   // color de retorno, ignorar si la funcion regresa false.
   color = m_color;

   // si el punto está fuera del bbox, no hay intersección.
   if ( !m_bbox.inside(pt) ) return false;

   // si el punto está dentro del bbox
   int n_inter = 0;
   int j;
   Line test = Line(Point(-1.0,-1.0),pt);
   Line side;

   for ( size_t i=0; i<m_vpoint.size(); i++ ) {

      // calcula el valor de j, que es i + 1 excepto cuando el indice supera al
      // tamaño del arreglo, en cuyo caso se le asigna el valor de cero.
      j = ( i + 1 < m_vpoint.size() ) ? i + 1 : 0;

      // crea la línea a probar (side)
      side = Line( m_vpoint[i], m_vpoint[j] );

      // si hay intersección, se incrementa el contador de intersecciones.
      if ( test.inter(side) ) n_inter ++;
   }

   // si n_inter es par, el punto pt está fuera del polígono
   //if ( n_inter % 2 == 0 ) return false;
   if ( (n_inter & 1) == 0 ) return false;

   // en caso contrario, está dentro y el método regresa true.
   return true;
}

