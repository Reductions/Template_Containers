#ifndef _ARRAY_CODE_H_
#define _ARRAY_CODE_H_

template <class T,size_t S>
array<T,S>::array(){}

template <class T,size_t S>
array<T,S>::array(std::initializer_list<T> list){
  if(list.size() > S)
    throw std::invalid_argument("the list provided is too big");
  auto it = list.begin();
  for (int i = 0; i < S; ++i){
    if (it != list.end())
      _content[i] = *(++it);
    else
      _content[i] = T();
  }
}

template <class T,size_t S>
size_t array<T,S>::size() const{
  return S;
}

template <class T,size_t S>
bool array<T,S>::empty() const{
  return S == 0;
}

#endif//_ARRAY_CODE_H_
