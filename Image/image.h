#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <vector>
#include "pixel.h"
#include "Scanline.h"
#include <fstream>

class Image{
  public:
    Image();
    Image(int width, int height);
    //acceso
    int width();
    int height();
    const Scanline& at(int index) const;
    const Scanline& operator[](int index) const;
    //mutators
    Scanline& at(int index);
    Scanline& operator[](int index);
    bool save(std::string filename);
    bool load(std::string filename);
  private:
    int m_width;
    int m_height;
    std::vector<Scanline> m_array;
};
#endif
