// default_allocator.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR
# define INCLUDED_DEFAULT_ALLOCATOR

#include "iallocator.h"

namespace StevensDev
{
namespace sgdm
{
template<typename T>
class DefaultAllocator : public IAllocator<T>
{
public:
  // CONSTRUCTORS
  DefaultAllocator();
    // Default constructor
  DefaultAllocator( const DefaultAllocator<T>& );
    // Copy constructor

  // DESTRUCTOR
  ~DefaultAllocator();
  
  T* get( int count );
    // FIXME
  void release( T*, int count );
    // FIXME
};

//CONSTRUCTORS

template<typename T>
inline
DefaultAllocator<T>::DefaultAllocator()
{
}

template<typename T>
inline
DefaultAllocator<T>::DefaultAllocator( const DefaultAllocator<T>& )
{
}

template<typename T>
inline
DefaultAllocator<T>::~DefaultAllocator()
{
}

template<typename T>
inline
T* DefaultAllocator<T>::get( int count )
{
  return new T[count];
}

template<typename T>
inline
void DefaultAllocator<T>::release( T* ptr, int count )
{
  delete ptr;
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
