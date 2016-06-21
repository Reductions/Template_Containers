#ifndef _REVERSE_ITERATOR_BASE_H_
#define _REVERSE_ITERATOR_BASE_H_

namespace tc {

  template <class T>
  class reverse_iterator_base {
    T _iter;
  public:
    reverse_iterator_base(const T&);

    operator T() const;

    reverse_iterator_base<T> operator ++();
    reverse_iterator_base<T> operator ++(int);
    reverse_iterator_base<T> operator --();
    reverse_iterator_base<T> operator --(int);

    bool operator== (const reverse_iterator_base<T>&) const;
    bool operator!= (const reverse_iterator_base<T>&) const;
  };


  #include "reverse_iterator_base_code.h"

}

#endif//_REVERSE_ITERATOR_BASE_H_
