#include <iostream>
#include "image.h"
#include "pixel.h"
#include "point.h"
#include "polygon.h"

using namespace std;

int main() {

   Image img(400,300);

   //Box fig( Point(50,50), Point(150,100), Pixel(0,128,0));

   double d = 0.0001; // pixeles
   Polygon fig;
   fig.color(Pixel(0,128,0));
   fig.push(Point(50+d,150+d));
   fig.push(Point(200+d,50+d));
   fig.push(Point(350+d,150+d));

   Pixel color;
   Point test_point;
   for ( int y=0; y<300; y++ ) {
      for ( int x=0; x<400; x++ ) {

         test_point = Point( double(x), double(y) );

         if ( fig.eval(test_point, color) ) {
            img[y][x] = color;
         }
         else {
            // background
            img[y][x] = Pixel(255,255,255);
         }
      }
   }

   img.save("triangle.ppm");

   return 0;
}

