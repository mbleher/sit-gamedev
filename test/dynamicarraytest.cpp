// dynamicarraytest.cpp

#include "dynamic_array.h"
#include "counting_allocator.h"
#include "gtest/gtest.h"

TEST( DynamicArray, Constructors )
{
  using namespace StevensDev;
  
  sgdm::CountingAllocator<int> caInt;
  sgdc::DynamicArray<int> daIntAlloc( &caInt );
  ASSERT_EQ( 0, daIntAlloc.length() );
  sgdc::DynamicArray<int> daIntDef;
  ASSERT_EQ( 0, daIntDef.length() );
  sgdc::DynamicArray<int> daIntCopy( daIntDef );
  ASSERT_EQ( 0, daIntCopy.length() );
}

TEST( DynamicArray, PushAt )
{
  using namespace StevensDev;
  
  sgdc::DynamicArray<int> daInt;

  daInt.push( 1 );
  daInt.push( 2 );
  ASSERT_EQ( 1, daInt.at( 0 ) );
  ASSERT_EQ( 2, daInt.at( 1 ) );
  ASSERT_EQ( 2, daInt.length() );
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

  ASSERT_EQ( 4, daInt[0] );
  daInt.removeAt( 0 );
  ASSERT_EQ( 3, daInt[0] );
  ASSERT_EQ( 3, daInt.length() );
  ASSERT_THROW( daInt.removeAt( 4 ), std::out_of_range );
}

TEST( DynamicArray, MemoryLeaks )
{
  using namespace StevensDev;
  
  sgdm::CountingAllocator<int> caInt;
  sgdc::DynamicArray<int>* daInt = new sgdc::DynamicArray<int>( &caInt );

  for( unsigned int i = 0; i < 30; ++i )
  {
    daInt->push( i );
  }
  ASSERT_EQ( 70, caInt.allocationCount() );
  ASSERT_EQ( 30, caInt.releaseCount() );
  ASSERT_EQ( 40, caInt.outstandingCount() );

  delete daInt;
  ASSERT_EQ( 0, caInt.outstandingCount() );
}
