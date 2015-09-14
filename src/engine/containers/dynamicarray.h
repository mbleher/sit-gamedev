// dynamicarray.h

#ifndef INCLUDED_DYNAMICARRAY
# define INCLUDED_DYNAMICARRAY

#define INIT_ARRAY_SIZE 10

#include "../memory/iallocator.h"
#include <stdexcept>

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
  unsigned int d_size;

  void doubleArraySize();
  
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

// PRIVATE MEMBER FUNCTIONS

template<typename T>
inline
void DynamicArray<T>::doubleArraySize()
{
  T* newArray;

  unsigned int newSize = d_size * 2;
  d_size = newSize;
  newArray = d_alloc->get( d_size );
  for ( unsigned int i = 0; i < d_length; ++i)
  {
    newArray[i] = d_array[i];
  }
  //d_alloc->release( d_array, d_length );
  d_array = newArray;
}

// CONSTRUCTORS

template<typename T>
inline
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
  : d_alloc( alloc ), d_length( 0 ), d_size( INIT_ARRAY_SIZE )
{
  d_array = alloc->get( INIT_ARRAY_SIZE );
}


// DESTRUCTOR

template<typename T>
inline
DynamicArray<T>::~DynamicArray()
{
//  d_alloc->release( d_array, d_length );
  delete [] d_array;
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
  if( d_length == d_size )
  {
    doubleArraySize();
  }
  d_array[d_length++] = element;
}

template<typename T>
inline
void DynamicArray<T>::pushFront( const T& element )
{
  if( d_length == d_size )
  {
    doubleArraySize();
  }
  for (unsigned int i = d_length++; i > 0; --i)
  {
    d_array[i] = d_array[i - 1];
  }
  d_array[0] = element;
}

template<typename T>
inline
T DynamicArray<T>::pop()
{
  T elem;

  elem = d_array[--d_length];
  d_array[d_length] = 0;
  return elem;
}

template<typename T>
inline
T DynamicArray<T>::popFront()
{
  T elem;

  elem = d_array[0];
  for (unsigned int i = 0; i < d_length; ++i)
  {
    d_array[i] = d_array[i + 1];
  }
  d_array[d_length--] = 0;
  return elem;
}

template<typename T>
inline
T DynamicArray<T>::at( unsigned int index ) const
{
  if( index >= d_length )
  {
    throw std::out_of_range( "index out of range" );
  }
  return d_array[index];
}

template<typename T>
inline
void DynamicArray<T>::removeAt( unsigned int index )
{
  if( index >= d_length )
  {
    throw std::out_of_range( "index out of range" );
  }
  d_array[index] = 0;
}

template<typename T>
inline
void DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
  if( index >= d_length )
  {
    throw std::out_of_range( "index out of range" );
  }
  if( d_length == d_size )
  {
    doubleArraySize();
  }
  for (unsigned int i = d_length++; i > index; --i)
  {
    d_array[i] = d_array[i - 1];
  }
  d_array[index] = element;
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
