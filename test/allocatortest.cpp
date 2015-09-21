// allocatortest.cpp

#include "counting_allocator.h"
#include "gtest/gtest.h"

TEST( CountingAllocator, Constructors )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  ASSERT_EQ( 0, caInt.allocationCount() );
  ASSERT_EQ( 0, caInt.releaseCount() );
  ASSERT_EQ( 0, caInt.outstandingCount() );

  sgdm::CountingAllocator<int> caIntCopy( caInt );
  ASSERT_EQ( 0, caIntCopy.allocationCount() );
  ASSERT_EQ( 0, caIntCopy.releaseCount() );
  ASSERT_EQ( 0, caIntCopy.outstandingCount() );
}

TEST( CountingAllocator, Get )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  int* intArray = caInt.get( 5 );
  
  ASSERT_EQ( 5, caInt.allocationCount() );
  ASSERT_EQ( 5, caInt.outstandingCount() );
  caInt.release( intArray, 5 );
}

TEST( CountingAllocator, Release )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> caInt;
  int* intArray = caInt.get( 5 );
  
  caInt.release( intArray, 5 );
  ASSERT_EQ( 5, caInt.allocationCount() );
  ASSERT_EQ( 5, caInt.releaseCount() );
  ASSERT_EQ( 0, caInt.outstandingCount() );
}

TEST( CountingAllocator, Static )
{
  using namespace StevensDev;

  sgdm::CountingAllocator<long> caLong1;
  sgdm::CountingAllocator<long> caLong2;

  long* longArray1 = caLong1.get( 2 );
  long* longArray2 = caLong2.get( 5 );

  ASSERT_EQ( 7, sgdm::CountingAllocator<long>::totalAllocationCount() );
  ASSERT_EQ( 7, sgdm::CountingAllocator<long>::totalOutstandingCount() );

  caLong1.release( longArray1, 2 );
  ASSERT_EQ( 5, sgdm::CountingAllocator<long>::totalOutstandingCount() );
  caLong2.release( longArray2, 5 );
  ASSERT_EQ( 0, sgdm::CountingAllocator<long>::totalOutstandingCount() );
}

