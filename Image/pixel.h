#ifndef _PIXEL_H
#define _PIXEL_H

//libreries
#include <iostream>
class Pixel{
  public:
    Pixel();
    Pixel(int value);
    Pixel(int red, int green, int blue);

    //acceso
    int red() const;
    int green() const;
    int blue() const;

    //mutators
    void red(int value);
    void green(int value);
    void blue(int value);

    bool operator!=(const Pixel& other);
    bool operator==( const Pixel& other);


  private:
    unsigned char m_red;
    unsigned char m_green;
    unsigned char m_blue;
    friend std::ostream& operator<<(std::ostream& out, const Pixel& Pix);
};
#endif
