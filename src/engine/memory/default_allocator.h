// default_allocator.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR
# define INCLUDED_DEFAULT_ALLOCATOR

#include "iallocator.h"

namespace StevensDev
{
namespace sgdm
{
template<typename T>
class DefaultAllocator : public IAllocator<T>
{
public:
  T* get( int count );
    // FIXME
  void release( T*, int count );
    // FIXME
};
} // End sgdm namespace
} // End StevensDev namespace

#endif
