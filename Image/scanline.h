#ifndef _SCANLINE_H_
#define _SCANLINE_H_

// libraries
#include <vector>
#include "pixel.h"


class ScanLine {
   public:
      ScanLine();
      ScanLine( int width );

      // accessors
      int width();
      const Pixel& at( int index ) const;
      const Pixel& operator[]( int index ) const;
      bool operator==( const ScanLine& other );
      bool operator!=( const ScanLine& other );

      // mutators
      Pixel& at( int index );
      Pixel& operator[]( int index );

   private:
      int m_width;
      std::vector<Pixel> m_array;
};


#endif

