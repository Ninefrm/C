#ifndef _SCANLINE_H
#define _SCANLINE_H

//libreries
#include <vector>
#include "pixel.h"
//

class Scanline{
  public:
    Scanline();
    Scanline(int value);
    //Scanline(const Scanline& copy);
    //acceso
    int size();
    const Pixel& at(int index) const;
    const Pixel& operator[](int index) const;
    //mutators
    int size(int value);
    Pixel& at(int index);
    Pixel& operator[](int index);
    
    bool operator==(const Scanline& other);
    bool operator!=(const Scanline& other);
  private:
    int m_size;
    std::vector<Pixel> m_array;
};
#endif
