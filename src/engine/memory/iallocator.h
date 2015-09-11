// iallocator.h

#ifndef INCLUDED_IALLOCATOR
# define INCLUDED_IALLOCATOR

namespace StevensDev
{
namespace sgdm
{

template<typename T>
class IAllocator
{
public:
  virtual T* get( int count ) = 0;
    // FIXME: Add function's use and expected behaviour
  virtual void release( T*, int count ) = 0;
    // FIXME: Add function's use and expected behaviour
};

} // End sgdm namespace
} // End StevensDev namespace

#endif
