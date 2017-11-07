#ifndef _IMAGE_H_
#define _IMAGE_H_

// libraries
#include <vector>
#include <string>
#include <fstream>
#include "pixel.h"
#include "scanline.h"

class Image {
   public:
      Image();
      Image( int width, int height );
      Image( std::string filename );

      // accessors
      int width() const;
      int height() const;

      const ScanLine& at( int index ) const;
      const ScanLine& operator[]( int index ) const;

      // mutators
      ScanLine& at( int index );
      ScanLine& operator[]( int index );

      bool save( std::string filename );
      bool load( std::string filename );

   //private:
      int m_width;
      int m_height;
      std::vector<ScanLine> m_array;
};

#endif

