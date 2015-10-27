// rectangleboundstest.cpp

#include "rectangle_bounds.h"
#include "gtest/gtest.h"

TEST( RectangleBounds, Constructors )
{
  using namespace StevensDev;

  sgds::RectangleBounds def;
  ASSERT_EQ( 0, def.x() );

  sgds::RectangleBounds rb( 5, 6, 42, 1337 );
  ASSERT_EQ( 5, rb.x() );

  sgds::RectangleBounds copy( rb );
  ASSERT_EQ( 6, copy.y() );
}

TEST( RectangleBounds, Accessors )
{
  using namespace StevensDev;

  sgds::RectangleBounds rb( 5, 6, 42, 1337 );
  ASSERT_EQ( 5, rb.x() );
  ASSERT_EQ( 6, rb.y() );
  ASSERT_EQ( 42, rb.width() );
  ASSERT_EQ( 1337, rb.height() );
}

TEST( RectangleBounds, Mutators )
{
  using namespace StevensDev;

  sgds::RectangleBounds rb( 5, 6, 42, 1337 );
  rb.setX( 10 );
  ASSERT_EQ( 10, rb.x() );
  rb.setY( 20 );
  ASSERT_EQ( 20, rb.y() );
  rb.setWidth( 30 );
  ASSERT_EQ( 30, rb.width() );
  rb.setHeight( 40 );
  ASSERT_EQ( 40, rb.height() );
  rb.setDimensions( 70, 80 );
  ASSERT_EQ( 70, rb.width() );
  ASSERT_EQ( 80, rb.height() );
  rb.setPosition( 1, 2 );
  ASSERT_EQ( 1, rb.x() );
  ASSERT_EQ( 2, rb.y() );
}

TEST( RectangleBounds, Collisions )
{
  using namespace StevensDev;

  sgds::RectangleBounds a( 0, 0, 1, 1 );
  sgds::RectangleBounds b( 2, 2, 1, 1 );
  ASSERT_FALSE( a.doesCollide( b ) );
  b = sgds::RectangleBounds( 0.5, 0.5, 20, 20 );
  ASSERT_TRUE( a.doesCollide( b ) );
  a = sgds::RectangleBounds( 20.6, 20.6, 10, 10 );
  ASSERT_FALSE( a.doesCollide( b ) );
  a.setX( 20.4 );
  ASSERT_FALSE( a.doesCollide( b ) );
  a.setY( 20.4 );
  ASSERT_TRUE( a.doesCollide( b ) );
}
