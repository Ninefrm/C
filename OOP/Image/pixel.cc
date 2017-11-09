#include "pixel.h"


Pixel::Pixel() {
   m_red = 0;
   m_green = 0;
   m_blue = 0;
}

Pixel::Pixel( int gray ) : Pixel() {
   if ( gray < 0 || gray > 255 ) return;
   m_red = gray;
   m_green = gray;
   m_blue = gray;
}

Pixel::Pixel( int red, int green, int blue ) : Pixel() {
   if ( red   < 0 || red   > 255 ) return;
   if ( green < 0 || green > 255 ) return;
   if ( blue  < 0 || blue  > 255 ) return;
   m_red = red;
   m_green = green;
   m_blue = blue;
}

// accessors

const unsigned char& Pixel::r() const {
  return m_red;
}

const unsigned char& Pixel::g() const {
  return m_green;
}

const unsigned char& Pixel::b() const {
  return m_blue;
}

bool Pixel::operator==( const Pixel& other ) {
   if ( m_red   != other.m_red   ) return false;
   if ( m_green != other.m_green ) return false;
   if ( m_blue  != other.m_blue  ) return false;
   return true;
}

bool Pixel::operator!=( const Pixel& other ) {
   return !operator==(other);
}

// mutators

unsigned char& Pixel::r() {
  return m_red;
}

unsigned char& Pixel::g() {
  return m_green;
}

unsigned char& Pixel::b() {
  return m_blue;
}

//void print( const Pixel& pix ) {
std::ostream& operator<<( std::ostream& out, const Pixel& pix ) {

   out << "<" << int(pix.m_red) << "," << int(pix.m_green);
   out << "," << int(pix.m_blue) << ">";

   return out;
}

