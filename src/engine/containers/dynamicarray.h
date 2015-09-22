// dynamicarray.h

#ifndef INCLUDED_DYNAMICARRAY
# define INCLUDED_DYNAMICARRAY

#define INIT_ARRAY_SIZE 10

#include "default_allocator.h"
#include <stdexcept>
#include <iostream>

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

  // PRIVATE MEMBER FUNCTIONS
  void doubleArraySize();
    // Doubles the size of the array.
  // Rationale: I chose to start from an initial array size of 10, then,
  // each time you exceed the current size, it doubles. That way, we avoid
  // reallocating and moving data around too many times if we ever need to
  // store a lot of elements.
  
  public:
  // CONSTRUCTORS
  DynamicArray( sgdm::IAllocator<T>* alloc );
    // Constructor with an allocator for use with memory
  DynamicArray();
    // Default constructor
  DynamicArray( const DynamicArray<T>& );
    // Copy constructor

  // DESTRUCTOR
  ~DynamicArray();

  // ACCESSORS
  unsigned int length() const;
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
  T& operator[]( int index );
    // Retrieves an element at a location
  T& operator[]( int index ) const;
    // Retrieves an element at a location
  T removeAt( unsigned int index );
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
  for ( unsigned int i = 0; i < d_length; ++i )
  {
    newArray[i] = d_array[i];
  }
  d_alloc->release( d_array, d_size / 2 );
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

template<typename T>
inline
DynamicArray<T>::DynamicArray()
  : d_length( 0 ), d_size ( INIT_ARRAY_SIZE )
{
  sgdm::DefaultAllocator<T>* alloc = new sgdm::DefaultAllocator<T>();

  d_alloc = alloc;
  d_array = alloc->get( INIT_ARRAY_SIZE );
}

template<typename T>
inline
DynamicArray<T>::DynamicArray( const DynamicArray<T>& copy )
  : d_length( copy.d_length ), d_size( copy.d_size ), d_alloc( copy.d_alloc )
{
  d_array = d_alloc->get( d_size );
  for( unsigned int i = 0; i < copy.length(); ++i )
  {
    push( copy[i] );
  }
}

// DESTRUCTOR

template<typename T>
inline
DynamicArray<T>::~DynamicArray()
{
  d_alloc->release( d_array, d_size );
}


// ACCESSORS

template<typename T>
inline
unsigned int DynamicArray<T>::length() const
{
  return d_length;
}


// FREE OPERATORS

template<typename T>
inline
std::ostream& operator<<( std::ostream& stream, const DynamicArray<T>& dynArray )
{
  unsigned int i;

  stream << "array:[" << std::endl;
  for( i = 0; i < dynArray.getLength() - 1; ++i )
  {
    stream << "\t{\"value\":" << dynArray[i] << "}," << std::endl;
  }
  stream << "\t{\"value\":" << dynArray[i] << "}\n]";
  return stream;
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
  for ( unsigned int i = d_length++; i > 0; --i )
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
  for ( unsigned int i = 0; i < d_length; ++i )
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
T& DynamicArray<T>::operator[]( int index ) const
{
  return d_array[index];
}

template<typename T>
inline
T& DynamicArray<T>::operator[]( int index )
{
  return d_array[index];
}

template<typename T>
inline
T DynamicArray<T>::removeAt( unsigned int index )
{
  if( index >= d_length )
  {
    throw std::out_of_range( "index out of range" );
  }
  T tmp = d_array[index];
  for ( unsigned int i = index; i < d_length - 1; ++i )
  {
    d_array[i] = d_array[i + 1];
  }
  d_length--;
  return tmp;
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
  for ( unsigned int i = d_length++; i > index; --i )
  {
    d_array[i] = d_array[i - 1];
  }
  d_array[index] = element;
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
