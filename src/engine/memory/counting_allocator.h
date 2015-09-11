// counting_allocator.h

#ifndef INCLUDED_COUNTING_ALLOCATOR
# define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"

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
  int d_outstandingCount;
  static int d_totalAllocationCount;
  static int d_totalReleaseCount;
  static int d_totalOutstandingCount;
public:
  // CONSTRUCTORS
  CountingAllocator();
  //CountingAllocator(const CountingAllocator&);

  //virtual ~CountingAllocator();

  //const CountingAllocator& operator=(const CountingAllocator&);

  // ACCESSORS
  int const getAllocationCount();
  int const getReleaseCount();
  int const getOutstandingCount();
  static int getTotalAllocationCount();
  static int getTotalReleaseCount();
  static int getTotalOutstandingCount();
};
} // End sgdm namespace
} // End StevensDev namespace

#endif
