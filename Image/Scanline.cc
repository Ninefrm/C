#include "Scanline.h"

Scanline::Scanline(){
  m_size=0;
  std::vector<Pixel> vector;
}
Scanline::Scanline(int value):Scanline(){
  if(value<1)return;
  m_size=value;
  m_array.resize(value);
}
int Scanline::size(){
  return m_size;
}
const Pixel& Scanline::at(int index) const{
  return m_array[index];
}
const Pixel& Scanline::operator[](int index) const{
  return m_array[index];
}
    //mutators
int Scanline::size(int value){
  return m_size;
}
Pixel& Scanline::at(int index){
  return m_array[index];
}
Pixel& Scanline::operator[](int index){
  return m_array[index];
}

//bool Scanline::operator==(const Scanline& other);
//bool Scanline::operator!=(const Scanline& other);
