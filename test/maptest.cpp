// maptest.cpp

#include "map.h"
#include "counting_allocator.h"
#include "gtest/gtest.h"

TEST( Map, Constructors )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  sgdc::Map<int> mapInt( &caInt );

  ASSERT_EQ( 0, mapInt.values().length() );
}
