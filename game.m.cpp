// game.m.cpp

#include <gtest/gtest.h>

TEST( Trivial, EQ )
{
  ASSERT_EQ( 2, 1 + 1 );
  ASSERT_EQ( 4, 2 * 2 );
}

TEST( Trivial, NE )
{
  ASSERT_NE( 2, 3 );
}

int main( int argc, char **argv )
{
  testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
