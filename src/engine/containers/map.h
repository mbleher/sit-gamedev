// map.h

#ifndef INCLUDED_MAP
# define INCLUDED_MAP

#include "dynamic_array.h"
#include "node.h"
#include <string>
#include <iostream>

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
  Node d_root;
  
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
  const DynamicArray<std::string>& keys() const;
    // Gets Key array
  const DynamicArray<T>& values() const;
    // Gets Value array

  // OPERATORS
  T& operator[]( const std::string& key );
  const T& operator[]( const std::string& key ) const;

  // MEMBER FUNCTIONS
  bool has( const std::string& key );
    // Determines if a key exists in the map
  T remove( const std::string& key );
    // Removes a key-value
};

// CONSTRUCTORS

template<typename T>
inline
Map<T>::Map( sgdm::IAllocator<T>* alloc )
  : d_alloc( alloc ), d_root()
{
}

template<typename T>
inline
Map<T>::Map()
  : d_root()
{
  sgdm::DefaultAllocator<T>* alloc = new sgdm::DefaultAllocator<T>();

  d_alloc = alloc;
}

template<typename T>
inline
Map<T>::Map( const Map<T>& copy )
  : d_alloc( copy.d_alloc ), d_keys( copy.d_keys ),
    d_values( copy.d_values ), d_root( copy.d_root )
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
const DynamicArray<std::string>& Map<T>::keys() const
{
  return d_keys;
}

template<typename T>
inline
const DynamicArray<T>& Map<T>::values() const
{
  return d_values;
}


// OPERATORS

template<typename T>
inline
T& Map<T>::operator[]( const std::string& key )
{
  unsigned int before = Node::current();
  unsigned int index = d_root.search( key );
  unsigned int after = Node::current();

  if( before != after )
  {
    T tmp;
    d_values.push( tmp );
    d_keys.push( key );
  }
  return d_values[index];
}

template<typename T>
inline
const T& Map<T>::operator[]( const std::string& key ) const
{
  unsigned int index = d_root.search( key );

  return d_values[index];
}


// FREE OPERATORS

template<typename T>
inline
std::ostream& operator<<( std::ostream& stream, const Map<T>& map )
{
  stream << "{\n";
  for( unsigned int i = 0; i < map.keys().length(); ++i )
  {
    stream << "\t\"" << map.keys().at( i ) << "\": "
	   << "\t" << map[map.keys().at( i )];
    if( i != map.keys().length() - 1 )
    {
      stream << ",\n";
    }
  }
  stream << "\n}\n";
  return stream;
}

// MEMBER FUNCTIONS

template<typename T>
inline
bool Map<T>::has( const std::string& key )
{
  return d_root.has( key );
}

template<typename T>
inline
T Map<T>::remove( const std::string& key )
{
  bool found = false;
  for( unsigned int i = 0; i < d_keys.length() && !found; ++i )
  {
    if( d_keys[i].compare( key ) == 0 )
    {
      d_keys.removeAt( i );
      found = true;
    }
  }
  if( found )
  {
    int index = d_root.remove( key );
    d_root.updateIndexes( index, true );
    return d_values.removeAt( index );
  }
  return 0;
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
