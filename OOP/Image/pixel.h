#ifndef _PIXEL_H_
#define _PIXEL_H_

#include <fstream>

class Pixel {
   public:
      Pixel();
      Pixel( int gray );
      Pixel( int red, int green, int blue );

      // accessors
      const unsigned char& r() const;
      const unsigned char& g() const;
      const unsigned char& b() const;
      bool operator==( const Pixel& other );
      bool operator!=( const Pixel& other );

      // mutators
      unsigned char& r();
      unsigned char& g();
      unsigned char& b();

   private:
      unsigned char m_red;
      unsigned char m_green;
      unsigned char m_blue;

      friend std::ostream& operator<<( std::ostream& out, const Pixel& pix );
};


#endif

