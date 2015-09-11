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

  T* get( int count );
    // FIXME
  void release( T*, int count );
    // FIXME
};

template<typename T>
inline
DefaultAllocator<T>::DefaultAllocator()
{
}

template<typename T>
inline
T* DefaultAllocator<T>::get( int count )
{
  return 0;
}

template<typename T>
inline
void DefaultAllocator<T>::release( T*, int count )
{
  return;
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
