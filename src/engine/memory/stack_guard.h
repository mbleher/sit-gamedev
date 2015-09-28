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
  StackGuard( T* guarded, IAllocator<T>* allocator );

  // DESTRUCTOR
  ~StackGuard();

  // OPERATORS
  T* operator->() const;
  bool operator==( bool rhs ) const;
  bool operator!() const;
  bool operator!=( bool rhs ) const;
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
} // End sgdm namespace
} // End StevensDev namespace

#endif
