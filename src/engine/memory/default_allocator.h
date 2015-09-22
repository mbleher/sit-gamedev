// default_allocator.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR
# define INCLUDED_DEFAULT_ALLOCATOR

#include "iallocator.h"
#include <cassert>
#include <iostream>

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
  void construct( T* ptr, const T& copy );
    // Construct a T object in-place by copy.
  //void construct( T* ptr, T&& copy );
    // Construct a T object in-place by move.
  void destruct( T* ptr );
    // Call the destructor on an object.
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


// FREE OPERATORS

template<typename T>
inline
std::ostream& operator<<( std::ostream& stream, const DefaultAllocator<T>& )
{
  return stream << "{ \"allocator\" : default }";
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
  assert( ptr );
  delete [] ptr;
  ptr = 0;
}

template<typename T>
inline
void DefaultAllocator<T>::construct( T* ptr, const T& copy )
{
  ptr = new T( copy );
}

/*
template<typename T>
inline
void DefaultAllocator<T>::construct( T* ptr, T&& copy )
{
  ptr = new T( copy );
}
*/
template<typename T>
inline
void DefaultAllocator<T>::destruct( T* ptr )
{
  delete ptr;
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
