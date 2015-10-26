// rectangle_bounds.cpp

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{

// CONSTRUCTORS

RectangleBounds::RectangleBounds()
{
}

RectangleBounds::RectangleBounds( float x, float y, float width, float height )
  : d_x( x ), d_y( y ), d_width( width ), d_height( height )
{
}

RectangleBounds::RectangleBounds( const RectangleBounds& copy )
  : d_x( copy.d_x ), d_y( copy.d_y ),
    d_width( copy.d_width ), d_height( copy.d_height )
{
}


// DESTRUCTOR

RectangleBounds::~RectangleBounds()
{
}


// ACCESSORS

float RectangleBounds::x() const
{
  return d_x;
}

float RectangleBounds::y() const
{
  return d_y;
}

float RectangleBounds::width() const
{
  return d_width;
}

float RectangleBounds::height() const
{
  return d_height;
}


// MUTATORS

void RectangleBounds::setX( float x )
{
  d_x = x;
}

void RectangleBounds::setY( float y )
{
  d_y = y;
}

void RectangleBounds::setWidth( float width )
{
  d_width = width;
}

void RectangleBounds::setHeight( float height )
{
  d_height = height;
}

void RectangleBounds::setDimensions( float width, float height )
{
  d_width = width;
  d_height = height;
}


// MEMBER FUNCTIONS

// Credit to silentmatt.com/rectangle-intersection/
bool RectangleBounds::doesCollide( const RectangleBounds& candidate )
{
  float ax1 = d_x;
  float ay1 = d_y;
  float ax2 = d_x + d_width;
  float ay2 = d_y + d_height;
  float bx1 = candidate.d_x;
  float by1 = candidate.d_y;
  float bx2 = candidate.d_x + candidate.d_width;
  float by2 = candidate.d_y + candidate.d_height;

  return ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1;
}

} // End sgds namespace
} // End StevensDev namespace
