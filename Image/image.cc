#include "image.h"


Image::Image() {
   m_width = 0;
   m_height = 0;
}

Image::Image( int width, int height ) : Image() {
   if ( width < 1 || height < 1 ) return;

   m_width = width;
   m_height = height;

   m_array.resize(height);
   for ( int i=0; i<height; i++ ) {
      m_array[i] = ScanLine(width);
   }
}

Image::Image( std::string filename ) : Image() {
   if ( !load(filename) ) *this = Image();
}

// accessors
int Image::width() const {
   return m_width;
}

int Image::height() const {
   return m_height;
}

const ScanLine& Image::at( int index ) const {
   return m_array[index];
}

const ScanLine& Image::operator[]( int index ) const {
   return m_array[index];
}

// mutators
ScanLine& Image::at( int index ) {
   return m_array[index];
}

ScanLine& Image::operator[]( int index ) {
   return m_array[index];
}

bool Image::save( std::string filename ) {
   std::ofstream fout;

   fout.open(filename);
   if ( !fout.is_open() ) return false;

   // header
   fout << "P3" << std::endl;
   fout << m_width << std::endl;
   fout << m_height << std::endl;
   fout << "255" << std::endl;

   // data
   for ( int j=0; j<m_height; j++ ) {
      for ( int i=0; i<m_width; i++ ) {
         fout << int(m_array[j][i].r()) << std::endl;
         fout << int(m_array[j][i].g()) << std::endl;
         fout << int(m_array[j][i].b()) << std::endl;
      }
   }

   fout.close();
   return true;
}

bool Image::load( std::string filename ) {
   std::ifstream fin;

   fin.open(filename);
   if ( !fin.is_open() ) return false;

   std::string head;
   int width, height, maxlev;

   // reads the PPM file identifier P3
   fin >> head;
   if ( head != "P3" ) {
      fin.close();
      return false;
   }

   // reads the image width
   fin >> width;
   if ( fin.fail() ) {
      fin.close();
      return false;
   }

   // reads the image height
   fin >> height;
   if ( fin.fail() ) {
      fin.close();
      return false;
   }

   // consumes the next number, the maximum intensity level
   // this value is not required for the Image object, so it is
   // discarded.
   fin >> maxlev;
   if ( fin.fail() ) {
      fin.close();
      return false;
   }

   // check the width and height ranges
   if ( width < 1 || height < 1 ) {
      fin.close();
      return false;
   }

   // calls the constructor for the current (this) object
   *this = Image(width,height);

   // this cycle reads RGB values until all the image is filled.
   int red, green, blue;
   for ( int j=0; j<height; j++ ) {
      for ( int i=0; i<width; i++ ) {

         // reads the red value
         fin >> red;

         // check reading errors
         if ( fin.fail() ) {
            fin.close();
            return false;
         }

         // reads the green value
         fin >> green;

         // check reading errors
         if ( fin.fail() ) {
            fin.close();
            return false;
         }

         // reads the blue value
         fin >> blue;

         // check reading errors
         if ( fin.fail() ) {
            fin.close();
            return false;
         }

         // assigns the RGB values to the current pixel (j,i)
         m_array[j][i] = Pixel(red, green, blue);
      }
   }

   fin.close();
   return true;
}

