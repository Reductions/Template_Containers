#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <initializer_list>
#include <exception>

#include "../reverse_iterator_base/reverse_iterator_base.h"

namespace tc{

  template <class T, size_t S>
  class array{
    T _content[S];
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef reverse_iterator_base<T*> reverse_iterator;
    typedef reverse_iterator_base<const T*> const_reverse_iterator;

    array();
    array(std::initializer_list<T>);

    size_t size() const;
    bool empty() const;

    T& operator[] (size_t);
    const T& operator[] (size_t) const;
    T& at (size_t);
    const T& at (size_t) const;
    T& front (size_t);
    const T& front (size_t) const;
    T& back (size_t);
    const T& back (size_t) const;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;

    const_iterator cbegin() const;
    const_reverse_iterator crbegin() const;
    const_iterator cend() const;
    const_reverse_iterator crend() const;

    void fill(const T&);
    void swap(array<T,S>&);
  };

  #include "array_code.h"

}

#endif//_ARRAY_H_
