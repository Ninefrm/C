#include "scanline.h"

ScanLine::ScanLine() {
   m_width = 0;
}

ScanLine::ScanLine( int width ) : ScanLine() {
   if ( width < 1 ) return;
   m_width = width;
   m_array.resize(width);
}

// accessors

int ScanLine::width() {
   return m_width;
}

const Pixel& ScanLine::at( int index ) const {
   return m_array[index];
}

const Pixel& ScanLine::operator[]( int index ) const {
   return m_array[index];
}

bool ScanLine::operator==( const ScanLine& other ) {

  if ( m_width != other.m_width ) return false;

  for ( int i=0; i<m_width; i++ ) {
    if ( m_array[i] != other.m_array[i] ) return false;
  }
  return true;
}

bool ScanLine::operator!=( const ScanLine& other ) {
  return !operator==(other);
}

// mutators

Pixel& ScanLine::at( int index ) {
   return m_array[index];
}

Pixel& ScanLine::operator[]( int index ) {
   return m_array[index];
}

