// maptest.cpp

#include "map.h"
#include "counting_allocator.h"
#include "gtest/gtest.h"

TEST( Map, Constructors )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  sgdc::Map<int> mapInt( &caInt );

  ASSERT_EQ( 0, mapInt.keys().length() );
}

TEST( Map, Operators )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  sgdc::Map<int> mapInt( &caInt );

  mapInt["test"] = 1;
  ASSERT_EQ( 1, mapInt["test"] );
  mapInt["test"] = 2;
  ASSERT_EQ( 2, mapInt["test"] );
  mapInt["tesaaa"] = 8;
  ASSERT_EQ( 8, mapInt["tesaaa"] );
  ASSERT_EQ( 2, mapInt.keys().length() );
}

TEST( Map, Has )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  sgdc::Map<int> mapInt( &caInt );

  mapInt["test"] = 1;
  ASSERT_TRUE( mapInt.has( "test" ) );
  ASSERT_FALSE( mapInt.has( "nothere" ) );
  ASSERT_FALSE( mapInt.has( "tes" ) );
  ASSERT_FALSE( mapInt.has( "testt" ) );
  mapInt["testt"] = 7;
  ASSERT_TRUE( mapInt.has( "testt" ) );
  ASSERT_EQ( 7, mapInt["testt"] );
}

TEST( Map, AlNumKeys )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  sgdc::Map<int> mapInt( &caInt );

  mapInt["test1"] = 42;
  ASSERT_TRUE( mapInt.has( "test1" ) );
  mapInt["abcdefghijklmnopqrstuvwxyz1234567890"] = 9000;
  ASSERT_TRUE( mapInt.has( "abcdefghijklmnopqrstuvwxyz1234567890" ) );  
}

TEST( Map, Exceptions )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  sgdc::Map<int> mapInt( &caInt );

  ASSERT_THROW( mapInt["ABC"], std::out_of_range );
  ASSERT_THROW( mapInt["-+/*"], std::out_of_range );
}
