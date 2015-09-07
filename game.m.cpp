// game.m.cpp

#include <gtest/gtest.h>

TEST(Test, EQ)
{
  ASSERT_EQ( 2, 1 + 1 );
}

int main( int argc, char **argv )
{
  /* FIXME: Add unit tests */
  testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
