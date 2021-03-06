// iallocator.h
// Interface for allocator

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
  virtual void release( T*, int count ) = 0;
  virtual void construct( T*, const T& copy ) = 0;
  //virtual void construct( T*, T&& copy ) = 0;
  virtual void destruct( T* ) = 0;
};

} // End sgdm namespace
} // End StevensDev namespace

#endif
