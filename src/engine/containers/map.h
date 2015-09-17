// map.h

#ifndef INCLUDED_MAP
# define INCLUDED_MAP

#include "dynamicarray.h"
#include <string>

namespace StevensDev
{
namespace sgdc
{
template<typename T>
class Map
{  
  private:
  sgdm::IAllocator<T>* d_alloc;
  DynamicArray<std::string> d_keys;
  DynamicArray<T> d_values;
  
  public:
  // CONSTRUCTORS
  Map( sgdm::IAllocator<T>* alloc );
    // Constructor with a specified allocator
  Map();
    // Default constructor (default allocator)
  Map( const Map<T>& );
    // Copy constructor

  // DESTRUCTOR
  ~Map();

  // ACCESSORS
  const DynamicArray<std::string>& getKeys() const;
    // Gets Key array
  const DynamicArray<T>& getValues() const;
    // Gets Value array

  // OPERATORS
  T& operator[]( const std::string& key );
  const T& operator[]( const std::string& key ) const;

  // MEMBER FUNCTIONS
  bool has( std::string& key ) const;
    // Determines if a key exists in the map
  T remove( std::string& key );
    // Removes a key-value
};

// CONSTRUCTORS

template<typename T>
inline
Map<T>::Map( sgdm::IAllocator<T>* alloc ) : d_alloc ( alloc )
{
}

template<typename T>
inline
Map<T>::Map()
{
  sgdm::DefaultAllocator<T>* alloc = new sgdm::DefaultAllocator<T>();

  d_alloc = alloc;
}

template<typename T>
inline
Map<T>::Map( const Map<T>& copy )
  : d_alloc( copy.d_alloc ), d_keys( copy.d_keys ), d_values( copy.d_values )
{
}


// DESTRUCTOR

template<typename T>
inline
Map<T>::~Map()
{
}


// ACCESSORS

template<typename T>
inline
const DynamicArray<std::string>& Map<T>::getKeys() const
{
  return d_keys;
}

template<typename T>
inline
const DynamicArray<T>& Map<T>::getValues() const
{
  return d_values;
}


// OPERATORS

template<typename T>
inline
T& Map<T>::operator[]( const std::string& key )
{
  // FIXME
  return 0;
}

template<typename T>
inline
const T& Map<T>::operator[]( const std::string& key ) const
{
  // FIXME
  return 0;
}


// MEMBER FUNCTIONS

template<typename T>
inline
bool Map<T>::has( std::string& key ) const
{
  return false;
}

template<typename T>
inline
T Map<T>::remove( std::string& key )
{
  return 0;
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
