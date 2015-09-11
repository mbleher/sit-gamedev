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
  //CountingAllocator(const CountingAllocator&);

  //virtual ~CountingAllocator();

  //const CountingAllocator& operator=(const CountingAllocator&);

  // ACCESSORS
  int getAllocationCount() const;
  int getReleaseCount() const;
  int getOutstandingCount() const;
/*
  static int getTotalAllocationCount();
  static int getTotalReleaseCount();
  static int getTotalOutstandingCount();
*/
};

template<typename T>
inline
CountingAllocator<T>::CountingAllocator() : d_allocationCount( 0 ), d_releaseCount( 0 )
{
}

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

/*
template<typename T>
inline
static int CountingAllocator<T>::getTotalAllocationCount()
{
  return d_totalAllocationCount;
}

template<typename T>
inline
static int CountingAllocator<T>::getReleaseCount()
{
  return d_totalReleaseCount;
}

template<typename T>
inline
static int CountingAllocator<T>::getTotalOutstandingCount()
{
  return d_totalAllocationCount - d_totalReleaseCount;
}
*/
} // End sgdm namespace
} // End StevensDev namespace

#endif
