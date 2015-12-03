// icollider.h

#ifndef INCLUDED_ICOLLIDER
# define INCLUDED_ICOLLIDER

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{
class ICollider
{
protected:
  RectangleBounds d_bounds;
  unsigned short d_flags;
public:
  // ACCESSORS
  virtual RectangleBounds& bounds() = 0;
  virtual const RectangleBounds& bounds() const = 0;
  virtual unsigned short flags() = 0;
  virtual const unsigned short flags() const = 0;

  // MUTATORS
  virtual void setFlags( unsigned short flags ) = 0;

  // MEMBER FUNCTIONS
  virtual bool canCollide( unsigned short flags ) = 0;
  virtual const bool canCollide( unsigned short flags ) const = 0;
    // Returns true if the collider flags match the argument
  virtual bool doesCollide( const RectangleBounds& candidate ) = 0;
  virtual const bool doesCollide( const RectangleBounds& candidate ) const = 0;
    // Returns true if d_bounds collides with candidate
};
} // End sgds namespace
} // End StevensDev namespace

#endif
