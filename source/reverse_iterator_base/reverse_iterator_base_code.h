#ifndef _REVERSE_ITERATOR_BASE_CODE_H_
#define _REVERSE_ITERATOR_BASE_CODE_H_

template <class T>
reverse_iterator_base<T>::reverse_iterator_base(const T& iter):
  _iter(iter){};

template <class T>
reverse_iterator_base<T>::operator T() const{
  return _iter;
}

template <class T>
reverse_iterator_base<T> reverse_iterator_base<T>::operator++(){
  --_iter;
  return *this;
}

template <class T>
reverse_iterator_base<T> reverse_iterator_base<T>::operator++(int){
  auto copy = *this;
  --_iter;
  return copy;
}

template <class T>
reverse_iterator_base<T> reverse_iterator_base<T>::operator--(){
  ++_iter;
  return *this;
}

template <class T>
reverse_iterator_base<T> reverse_iterator_base<T>::operator--(int){
  auto copy = *this;
  ++_iter;
  return copy;
}
template <class T>
bool reverse_iterator_base<T>::
operator== (const reverse_iterator_base<T>& other) const{
  return _iter == other._iter;
}

template <class T>
bool reverse_iterator_base<T>::
operator!= (const reverse_iterator_base<T>& other) const{
  return _iter != other._iter;
}

#endif//_REVERSE_ITERATOR_BASE_CODE_H_
