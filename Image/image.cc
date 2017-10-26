#include "image.h"
Image::Image(){
  m_width=0;
  m_height=0;
}
Image::Image(int width, int height):Image(){
  if(width<1||height<1)return;
  m_width=width;
  m_height=height;

  m_array.resize(height);
  for(int i=0;i<height;i++){
    m_array[i]=Scanline(width);
  }
}
//acceso
int Image::width(){
  return m_width;
}
int Image::height(){
  return m_height;
}
const Scanline& Image::at(int index) const{
  return m_array[index];
}
const Scanline& Image::operator[](int index) const{
  return m_array[index];
}
//mutators
Scanline& Image::at(int index){
  return m_array[index];
}
Scanline& Image::operator[](int index){
  return m_array[index];
}
bool Image::save(std::string filename){
  std::ofstream fout;
  fout.open(filename);
  if(!fout.is_open())return false;
  //header
  fout<<"P3"<<std::endl;
  fout<<m_width<<std::endl;
  fout<<m_height<<std::endl;
  fout<<"255"<<std::endl;

  //data
  for(int j=0;j<m_height;j++){
    for(int i=0;i<m_width;i++){
      fout<<int(m_array[j][i].red())<<std::endl;
      fout<<int(m_array[j][i].green())<<std::endl;
      fout<<int(m_array[j][i].blue())<<std::endl;
    }
  }
  fout.close();
  return true;
}
bool Image::load(std::string filename){
  std::ifstream fin;
  fin.open(filename);
  if(!fin.is_open()) return false;
  std::string head;
  int width, height, maxlev;
  fin>>head;
  if(head!="P3"){
    fin.close();
    return false;
  }
  fin>>width;
  if(fin.fail()){
    fin.close();
    return false;
  }
  fin>>height;
  if(fin.fail()){
    fin.close();
    return false;
  }
  fin>>maxlev;
  if(fin.fail()){
    fin.close();
    return false;
  }
  if(width<1|| height < 1){
    fin.close();
    return false;
  }
  int red, green, blue;
  *this=Image(width,height);
  while(!fin.eof()){
    for(int j=0;j<height;j++){
      for(int i=0;i<width;i++){
        fin>>red;
        if(fin.fail()){
          fin.close();
          return false;
        }
        fin>>green;
        if(fin.fail()){
          fin.close();
          return false;
        }
        fin>>blue;
        if(fin.fail()){
          fin.close();
          return false;
        }
      }
    }
  }
  return true;
}
