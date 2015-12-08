// collidable_bounds.cpp

#include "collidable_bounds.h"

namespace StevensDev
{
namespace sgds
{
CollidableBounds::CollidableBounds()
{
}

CollidableBounds::CollidableBounds( float x, float y, float width, float height, unsigned short flags )
{
  d_bounds = RectangleBounds( x, y, width, height );
  d_flags = flags;
}

CollidableBounds::CollidableBounds( const CollidableBounds& copy )
{
  d_bounds = copy.d_bounds;
  d_flags = copy.d_flags;
}

CollidableBounds::~CollidableBounds()
{
}

RectangleBounds& CollidableBounds::bounds()
{
  return d_bounds;
}
const RectangleBounds& CollidableBounds::bounds() const
{
  return d_bounds;
}

unsigned short CollidableBounds::flags()
{
  return d_flags;
}

const unsigned short CollidableBounds::flags() const
{
  return d_flags;
}

void CollidableBounds::setFlags( unsigned short flags )
{
  d_flags = flags;
}

bool CollidableBounds::canCollide( unsigned short flags )
{
  return d_flags & flags;
}

const bool CollidableBounds::canCollide( unsigned short flags ) const
{
  return d_flags & flags;
}

bool CollidableBounds::doesCollide( const RectangleBounds& candidate )
{
  return d_bounds.doesCollide( candidate );
}

const bool CollidableBounds::doesCollide( const RectangleBounds& candidate ) const
{
  return d_bounds.doesCollide( candidate );
}

void CollidableBounds::move( float x, float y )
{
  d_bounds.move( x, y );
}

} // End sgds namespace
} // End StevensDev namespace
