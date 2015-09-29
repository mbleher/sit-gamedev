// stack_guard.h

#ifndef INCLUDED_STACK_GUARD
# define INCLUDED_STACK_GUARD

#include "default_allocator.h"

namespace StevensDev
{
namespace sgdm
{

template<typename T>
class StackGuard
{
  private:
  T* d_guarded;
  IAllocator<T>* d_allocator;
  StackGuard( const StackGuard<T>& guard );

  public:
  // CONSTRUCTORS
  StackGuard( T* guarded );
    // Default constructor
  StackGuard( T* guarded, IAllocator<T>* allocator );
    // Constructor with specified allocator

  // DESTRUCTOR
  ~StackGuard();

  // OPERATORS
  T* operator->() const;
    // Returns guarded pointer
  bool operator==( bool rhs ) const;
    // Standard pointer validation
  bool operator!() const;
    // Returns true if guarded pointer is null
  bool operator!=( bool rhs ) const;
    // Standard pointer validation
  const T& operator[]( const std::string& key ) const;
    // Bracket operator
};

// PRIVATE MEMBER FUNCTIONS

template<typename T>
StackGuard<T>::StackGuard( const StackGuard<T>& guard )
{
}


// CONSTRUCTORS

template<typename T>
StackGuard<T>::StackGuard( T* guarded )
  : d_guarded( guarded ), d_allocator( new DefaultAllocator<T>() )
{
}

template<typename T>
StackGuard<T>::StackGuard( T* guarded, IAllocator<T>* allocator )
  : d_guarded( guarded ), d_allocator( allocator )
{
}


// DESTRUCTOR

template<typename T>
StackGuard<T>::~StackGuard()
{
  d_allocator->destruct( d_guarded );
}


// OPERATORS

template<typename T>
T* StackGuard<T>::operator->() const
{
  return d_guarded;
}

template<typename T>
bool StackGuard<T>::operator==( bool rhs ) const
{
  return rhs != !d_guarded;
}

template<typename T>
bool StackGuard<T>::operator!() const
{
  return !d_guarded;
}

template<typename T>
bool StackGuard<T>::operator!=( bool rhs ) const
{
  return rhs == !d_guarded;
}

template<typename T>
const T& StackGuard<T>::operator[]( const std::string& key ) const
{
  return ( *d_guarded )[key];
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
