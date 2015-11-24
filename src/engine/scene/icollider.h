// icollider.h
// Interface for objects that can collide

#ifndef INCLUDED_ICOLLIDER
# define INCLUDED_ICOLLIDER

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{
class ICollider
{
private:
  RectangleBounds& d_bounds;
    // Rectangle that represents the boundaries of this object
  unsigned short d_flags;
    // Flags that specify with which objects to collide
public:
  // ACCESSORS
  virtual RectangleBounds& bounds() const = 0;
  virtual unsigned short flags() const = 0;

  // MUTATORS
  virtual void setFlags( unsigned short flags ) = 0;

  // MEMBER FUNCTIONS
  virtual bool canCollide( unsigned short flags ) const = 0;
    // Returns true if the collider flags match the argument
  virtual bool doesCollide( const RectangleBounds& candidate ) const = 0;
    // Returns true if d_bounds collides with candidate
};
} // End sgds namespace
} // End StevensDev namespace

#endif
