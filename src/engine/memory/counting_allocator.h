// counting_allocator.h

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
  int d_releaseCount;
  static int d_totalAllocationCount;
  static int d_totalReleaseCount;

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
  int getAllocationCount() const;
  int getReleaseCount() const;
  int getOutstandingCount() const;

  static int getTotalAllocationCount();
  static int getTotalReleaseCount();
  static int getTotalOutstandingCount();

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
  : d_allocationCount( copy.getAllocationCount() ), d_releaseCount( copy.getReleaseCount() )
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
int CountingAllocator<T>::getAllocationCount() const
{
  return d_allocationCount;
}

template<typename T>
inline
int CountingAllocator<T>::getReleaseCount() const
{
  return d_releaseCount;
}

template<typename T>
inline
int CountingAllocator<T>::getOutstandingCount() const
{
  return d_allocationCount - d_releaseCount;
}


template<typename T>
inline
int CountingAllocator<T>::getTotalAllocationCount()
{
  return d_totalAllocationCount;
}

template<typename T>
inline
int CountingAllocator<T>::getTotalReleaseCount()
{
  return d_totalReleaseCount;
}

template<typename T>
inline
int CountingAllocator<T>::getTotalOutstandingCount()
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
