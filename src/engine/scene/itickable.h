// itickable.h
// Interface for tickable objects

#ifndef INCLUDED_ITICKABLE
# define INCLUDED_ITICKABLE

namespace StevensDev
{
namespace sgds
{
class ITickable
{
public:
  virtual void preTick() = 0;
  virtual void tick( float dtS ) = 0;
  virtual void postTick() = 0;
}; 
} // End sgds namespace
} // End StevensDev namespace

#endif
