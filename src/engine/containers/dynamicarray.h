// dynamicarray.h

#ifndef INCLUDED_DYNAMICARRAY
# define INCLUDED_DYNAMICARRAY

#include "../memory/iallocator.h"

namespace StevensDev
{
namespace sgdc
{
template<typename T>
class DynamicArray
{
private:
  sgdm::IAllocator<T>* d_alloc;
  T* d_array;
  unsigned int d_length;

public:
  // CONSTRUCTORS
  DynamicArray( sgdm::IAllocator<T>* alloc );
    // Constructor with an allocator for use with memory
  //DynamicArray();
  //DynamicArray( const DynamicArray<T>& );

  // DESTRUCTOR
  ~DynamicArray();

  // ACCESSORS
  unsigned int getLength() const;
    // Number of elements contained

  // MEMBER FUNCTIONS
  void push( const T& element );
    // Adds element to end of collection
  void pushFront( const T& element );
    // Adds element to the front of the collection
  T pop();
    // Removes and retrieves the last element from collection
  T popFront();
    // Removes and retrieves the first element from collection
  T at( unsigned int index ) const;
    // Retrieves an element at a location
  void removeAt( unsigned int index );
    // Removes an element at a location
  void insertAt( unsigned int index, const T& element );
    // Inserts an element at a location
};

// CONSTRUCTORS

template<typename T>
inline
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
  : d_alloc( alloc )
{
}


// DESTRUCTOR

template<typename T>
inline
DynamicArray<T>::~DynamicArray()
{
}


// ACCESSORS

template<typename T>
inline
unsigned int DynamicArray<T>::getLength() const
{
  return d_length;
}


// MEMBER FUNCTIONS

template<typename T>
inline
void DynamicArray<T>::push( const T& element )
{
}

template<typename T>
inline
void DynamicArray<T>::pushFront( const T& element )
{
}

template<typename T>
inline
T DynamicArray<T>::pop()
{
  return 0;
}

template<typename T>
inline
T DynamicArray<T>::popFront()
{
  return 0;
}

template<typename T>
inline
T DynamicArray<T>::at( unsigned int index ) const
{
  return 0;
}

template<typename T>
inline
void DynamicArray<T>::removeAt( unsigned int index )
{
}

template<typename T>
inline
void DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
