// jsonparsertest.cpp

#include "json_parser.h"
#include "gtest/gtest.h"

TEST( JsonParser, Integers )
{
  using namespace StevensDev;

  std::string json = "111";
  sgdd::JsonEntity* integer = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( 111, integer->asInt() );
  json = "-42";
  integer = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( -42, integer->asInt() );
}

TEST( JsonParser, Doubles )
{
  using namespace StevensDev;

  std::string json = "2222222.22";
  sgdd::JsonEntity* d = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( 2222222.22, d->asDouble() );
  json = "-1.2345";
  d = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( -1.2345, d->asDouble() );
}

TEST( JsonParser, Strings )
{
  using namespace StevensDev;

  std::string json = "\"hello\"";
  sgdd::JsonEntity* s = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( "hello", s->asString() );
}

TEST( JsonParser, Booleans )
{
  using namespace StevensDev;

  std::string json = "true";
  sgdd::JsonEntity* b = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_TRUE( b->asBool() );
  json = "false";
  b = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_FALSE( b->asBool() );
}

TEST( JsonParser, Arrays )
{
  using namespace StevensDev;

  std::string json = "[ 1, 2, 3 ]";
  sgdd::JsonEntity* a = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( 1, ( ( *a )[0] ).asInt() );
  ASSERT_EQ( 2, ( ( *a )[1] ).asInt() );
  ASSERT_EQ( 3, ( ( *a )[2] ).asInt() );
}

TEST( JsonParser, MixedArrays )
{
  using namespace StevensDev;

  std::string json = "[ 1, \"two\", 3.0 ]";
  sgdd::JsonEntity* a = sgdd::JsonParser::fromString( json, nullptr );
  ASSERT_EQ( 1, ( ( *a )[0] ).asInt() );
  ASSERT_EQ( "two", ( ( *a )[1] ).asString() );
  ASSERT_EQ( 3.0, ( ( *a )[2] ).asDouble() );
}

/*
TEST( JsonParser, Map )
{
  using namespace StevensDev;

  std::string json = "{ \"name\" : \"Configuration\", \"values\" : [ 1, 3, \"penguin\" ]}";
  //std::string json = "{ \"name\" : \"Configuration\" }";
  sgdd::JsonEntity* m = sgdd::JsonParser::fromString( json, nullptr );

  //std::string penguin = (*m)["values"][2].asString();
  std::cout << m->type() << std::endl;
  std::cout << ( ( *m )["values"] ).type() << std::endl;

  //ASSERT_EQ( "value", ( ( *m )["name"] ).asString() );
  //std::string penguin = ( ( *m )["values"] )[2].asString();
  //ASSERT_EQ( "Configuration", penguin );
}
*/
