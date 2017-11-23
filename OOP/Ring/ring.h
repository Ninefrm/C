#ifndef _RING_H_
#define _RING_H_

// library
#include <vector>

template <typename T>
class Ring {
   public:

      Ring() {
         m_begin = 0;
         m_end = 0;
      }

      Ring( int length ) : Ring() {
         m_capacity = length + 1;
         m_buffer.resize(m_capacity);
      }

      void push_back( const T value ) {

         // ingresa un elemento nuevo al final del arreglo
         m_buffer[m_end] = value;
         m_end ++;
         if ( m_end == m_capacity ) m_end = 0;

         // cuando se desborda el arreglo circular
         if ( m_end == m_begin ) {
            m_begin ++;
            if ( m_begin == m_capacity ) m_begin = 0;
         }
      }

      void push_front( const T value ) {

         // mueve m_begin un elemento hacia atrás
         if ( m_begin > 0 ) m_begin --;
         else m_begin = m_capacity - 1;

         // cuando se desborda el arreglo circular
         if ( m_begin == m_end ) {
            if ( m_end > 0 ) m_end --;
            else m_end = m_capacity - 1;
         }

         // agregar el elemento
         m_buffer[m_begin] = value;
      }

      bool pop_back() {

         // si el arreglo está vacío, regresa false
         if ( m_begin == m_end ) return false;

         // si no está vacío, elimina un elemento ajustando el indice
         if ( m_end > 0 ) m_end --;
         else m_end = m_capacity - 1;

         return true;
      }

      bool pop_front() {

         // si el arreglo está vacío, regresa false
         if ( m_begin == m_end ) return false;

         // si no está vacío, elimina un elemento ajustando el indice
         m_begin ++;
         if ( m_begin == m_capacity ) m_begin = 0;

         return true;
      }

      size_t size() const {
         if ( m_begin == m_end ) return 0;
         else if ( m_begin < m_end ) return m_end - m_begin;
         return m_capacity - m_begin + m_end;
      }

      size_t capacity() const {
         return m_capacity - 1;
      }

      T front() const {
         return m_buffer[m_begin];
      }

      T back() const {
         size_t e = ( m_end > 0 ) ? m_end - 1 : m_capacity - 1;
         return m_buffer[e];
      }

      T& operator[] ( int index ) {
         int idx;

         if ( index < 0 ) {
            // negativos
            // -1 --> m_end - 1
            // -2 --> m_end - 2
            idx = int(m_end);
            idx += index;
            if ( idx < 0 ) idx += m_capacity;
         }
         else {
            // caso: índices positivos
            idx = m_begin + index;
            if ( idx >= m_capacity ) idx -= m_capacity;
         }

         return m_buffer[idx];
      }

   private:
      size_t m_capacity; // capacidad del arreglo circular
      size_t m_size;     // elementos en el arreglo
      size_t m_begin;    // índice del primer elemento del arreglo
      size_t m_end;      // índice del último elemento del arreglo
      std::vector<T> m_buffer;
};

#endif

