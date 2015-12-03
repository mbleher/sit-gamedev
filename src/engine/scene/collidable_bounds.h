// collidable_bounds.h

#ifndef INCLUDED_COLLIDABLE_BOUNDS
# define INCLUDED_COLLIDABLE_BOUNDS

#include "icollider.h"

namespace StevensDev
{
namespace sgds
{
class CollidableBounds : public ICollider
{
public:
  CollidableBounds();
  CollidableBounds( float x, float y, float width, float height, unsigned short flags = 0 );
  CollidableBounds( const CollidableBounds& copy );
  ~CollidableBounds();
  RectangleBounds& bounds();
  const RectangleBounds& bounds() const;
  unsigned short flags();
  const unsigned short flags() const;

  void setFlags( unsigned short flags );
  bool canCollide( unsigned short flags );
  const bool canCollide( unsigned short flags ) const;
  bool doesCollide( const RectangleBounds& candidate );
  const bool doesCollide( const RectangleBounds& candidate ) const;
};

} // End sgds namespace
} // End StevensDev namespace

#endif
