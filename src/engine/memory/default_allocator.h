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

  // MEMBER FUNCTIONS
  T* get( int count );
    // Returns an array of <count> T.
  void release( T* ptr, int count );
    // Frees <count> T starting from memory location <ptr>.
};


// CONSTRUCTORS

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


// DESTRUCTOR

template<typename T>
inline
DefaultAllocator<T>::~DefaultAllocator()
{
}


// MEMBER FUNCTIONS

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
  for( int i = 0; i < count && (ptr + i != 0); ++i, ++ptr )
  {
    delete ptr;
    ptr = 0;
  }
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
