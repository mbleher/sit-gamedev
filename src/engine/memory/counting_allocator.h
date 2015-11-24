// counting_allocator.h
// Implementation of an allocator that keeps track of the number of allocations
// and releases done by allocator and by type

#ifndef INCLUDED_COUNTING_ALLOCATOR
# define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"
#include <iostream>

namespace StevensDev
{
namespace sgdm
{
template<typename T>
class CountingAllocator : public DefaultAllocator<T>
{
  private:
  int d_allocationCount;
    // Number of allocations done by this allocator
  int d_releaseCount;
    // Number of releases done by this allocator
  static int d_totalAllocationCount;
    // Number of allocations done for that type
  static int d_totalReleaseCount;
    // Number of releases done for that type

  public:
  // CONSTRUCTORS
  CountingAllocator();
    // Default constructor
  CountingAllocator( const CountingAllocator<T>& );
    // Copy constructor

  // DESTRUCTOR
  ~CountingAllocator();

  //const CountingAllocator& operator=(const CountingAllocator&);

  // ACCESSORS
  int allocationCount() const;
  int releaseCount() const;
  int outstandingCount() const;

  static int totalAllocationCount();
  static int totalReleaseCount();
  static int totalOutstandingCount();

  // MEMBER FUNCTIONS
  T* get( int count );
    // Returns an array of <count> T.
  void release( T* ptr, int count );
    // Frees <count> T starting from <ptr>.
    
};

template<typename T>
int CountingAllocator<T>::d_totalAllocationCount = 0;

template<typename T>
int CountingAllocator<T>::d_totalReleaseCount = 0;


// CONSTRUCTORS

template<typename T>
inline
CountingAllocator<T>::CountingAllocator() : d_allocationCount( 0 ), d_releaseCount( 0 )
{
}

template<typename T>
inline
CountingAllocator<T>::CountingAllocator( const CountingAllocator<T>& copy )
  : d_allocationCount( copy.allocationCount() ), d_releaseCount( copy.releaseCount() )
{
}


// DESTRUCTOR

template<typename T>
inline
CountingAllocator<T>::~CountingAllocator()
{
}


// ACCESSORS

template<typename T>
inline
int CountingAllocator<T>::allocationCount() const
{
  return d_allocationCount;
}

template<typename T>
inline
int CountingAllocator<T>::releaseCount() const
{
  return d_releaseCount;
}

template<typename T>
inline
int CountingAllocator<T>::outstandingCount() const
{
  return d_allocationCount - d_releaseCount;
}


template<typename T>
inline
int CountingAllocator<T>::totalAllocationCount()
{
  return d_totalAllocationCount;
}

template<typename T>
inline
int CountingAllocator<T>::totalReleaseCount()
{
  return d_totalReleaseCount;
}

template<typename T>
inline
int CountingAllocator<T>::totalOutstandingCount()
{
  return d_totalAllocationCount - d_totalReleaseCount;
}


// FREE OPERATORS

template<typename T>
inline
std::ostream& operator<<( std::ostream& stream, const CountingAllocator<T>& )
{
  return stream << "{ \"allocator\" : counting }";
}


// MEMBER FUNCTIONS

template<typename T>
inline
T* CountingAllocator<T>::get( int count )
{
  d_allocationCount += count;
  d_totalAllocationCount += count;
  return DefaultAllocator<T>::get( count );
}

template<typename T>
inline
void CountingAllocator<T>::release( T* ptr, int count )
{
  d_releaseCount += count;
  d_totalReleaseCount += count;
  DefaultAllocator<T>::release( ptr, count );
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
