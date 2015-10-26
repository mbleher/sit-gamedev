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
private:
  RectangleBounds& d_bounds;
  unsigned short d_flags;
public:
  virtual RectangleBounds& bounds() const = 0;
  virtual unsigned short flags() const = 0;
  virtual void setFlags( unsigned short flags ) = 0;
  virtual bool canCollide( unsigned short flags ) const = 0;
  virtual bool doesCollide( const RectangleBounds& candidate ) const = 0;
};
} // End sgds namespace
} // End StevensDev namespace

#endif
