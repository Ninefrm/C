#ifndef _RING_H_
#define _RING_H_

//Library
#include <vector>

template <typename T>
class Ring{
  public:
    Ring(){
      m_begin = 0;
      m_end = 0;
    }
    void push_back(const T value);
    void push_front(const T value);

    T pop_back();
    T pop_front();
    T& operator[](int index);


  private:
    int m_begin;
    int m_end;
    std::vector<T> m_buffer;
};
#endif
