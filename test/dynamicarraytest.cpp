// dynamicarraytest.cpp

#include "dynamicarray.h"
#include "counting_allocator.h"
#include <gtest/gtest.h>

TEST(DynamicArray, Constructors)
{
  using namespace StevensDev;
  
  sgdm::CountingAllocator<int> caInt;
  sgdc::DynamicArray<int> daIntAlloc( &caInt );
  ASSERT_EQ( 0, daIntAlloc.getLength() );
  sgdc::DynamicArray<int> daIntDef;
  ASSERT_EQ( 0, daIntDef.getLength() );
  sgdc::DynamicArray<int> daIntCopy( daIntDef );
  ASSERT_EQ( 0, daIntCopy.getLength() );
}

TEST( DynamicArray, PushAt )
{
  using namespace StevensDev;
  
  sgdc::DynamicArray<int> daInt;

  daInt.push( 1 );
  daInt.push( 2 );
  ASSERT_EQ( 1, daInt.at( 0 ) );
  ASSERT_EQ( 2, daInt.at( 1 ) );
  ASSERT_EQ( 2, daInt.getLength() );
}

TEST( DynamicArray, Pop )
{
  using namespace StevensDev;

  sgdc::DynamicArray<int> daInt;

  daInt.push( 1 );
  daInt.push( 2 );
  int elem = daInt.pop();
  ASSERT_EQ( 2, elem );
  daInt.push( 3 );
  elem = daInt.popFront();
  ASSERT_EQ( 1, elem );
  ASSERT_EQ( 3, daInt[0]);
}

TEST( DynamicArray, RemoveAt )
{
  using namespace StevensDev;

  sgdc::DynamicArray<int> daInt;

  for( unsigned int i = 0; i < 5; ++i )
  {
    daInt.pushFront( i );
  }
  ASSERT_EQ( 1, daInt[3] );
  daInt.removeAt( 3 );
  ASSERT_EQ( 0, daInt[3] );
}
