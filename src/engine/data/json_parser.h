// json_parser.h

#ifndef INCLUDED_JSON_PARSER
# define INCLUDED_JSON_PARSER

#include "iallocator.h"
#include "json_entity.h"
#include <stdexcept>
#include <cstdlib>
#include <string>

namespace StevensDev
{
namespace sgdd
{

template<typename T>
class JsonParser
{
private:
  // PRIVATE MEMBER FUNCTIONS
  static void parseNumber( const std::string& rawJson, unsigned int& index );
  static void parseString( const std::string& rawJson, unsigned int& index );
  static void parseObject( const std::string& rawJson, unsigned int& index );
  static void parseArray( const std::string& rawJson, unsigned int& index );
  static bool parseBoolean( const std::string& rawJson, unsigned int& index );
  static void skipWhiteSpaces( const std::string& rawJson,
			       unsigned int& index );
  static JsonEntity* fromString( const std::string& rawJson,
				 sgdm::IAllocator<T>* allocator,
				 unsigned int& index );
public:
  // MEMBER FUNCTIONS
  static JsonEntity* fromString( const std::string& rawJson,
				 sgdm::IAllocator<T>* allocator = 0 );
};

// PRIVATE MEMBER FUNCTIONS

template<typename T>
void JsonParser<T>::parseNumber( const std::string& rawJson,
				 unsigned int& index )
{
  unsigned int start = index;
  bool isNeg = false;
  bool isDouble = false;

  if( rawJson[index] == '-' )
  {
    isNeg = true;
    ++index;
  }
  while( ( rawJson[index] >= '0' && rawJson[index] <= '9' )
	 || ( !isDouble && rawJson[index] == '.' ) )
  {
    if( rawJson[index] == '.' )
    {
      isDouble = true;
    }
    ++index;
  }
  std::cout << "Number parsed: " << rawJson.substr( start, index - start )
	    << std::endl;
}

template<typename T>
void JsonParser<T>::parseString( const std::string& rawJson,
				 unsigned int& index )
{
  unsigned int start = ++index;

  while( rawJson[index] != '\"' )
  {
    ++index;
  }
  std::cout << "String parsed: " << rawJson.substr( start, index - start )
	    << std::endl;
  ++index;
}

template<typename T>
void JsonParser<T>::parseObject( const std::string& rawJson,
				 unsigned int& index )
{
  unsigned int start = index;

  while( rawJson[index] != '}' )
  {
    //skipWhiteSpaces( rawJson, index );
    ++index;
  }
  std::cout << "Object parsed: " << rawJson.substr( start, index - start + 1 )
	    << std::endl;
  ++index;
}

template<typename T>
void JsonParser<T>::parseArray( const std::string& rawJson,
				unsigned int& index )
{
  unsigned int start = index;

  while( rawJson[index] != ']' )
  {
    ++index;
  }
  std::cout << "Array parsed: " << rawJson.substr( start, index - start + 1 )
	    << std::endl;
  ++index;
}

template<typename T>
bool JsonParser<T>::parseBoolean( const std::string& rawJson,
				  unsigned int& index )
{
  unsigned int start = index;
  bool isLegit = false;

  if( rawJson[index] == 't' )
  {
    if( rawJson[++index] == 'r' && rawJson[++index] == 'u'
	&& rawJson[++index] == 'e' )
    {
      isLegit = true;
    }
  }
  else
  {
    if( rawJson[++index] == 'a' && rawJson[++index] == 'l'
	&& rawJson[++index] == 's' && rawJson[++index] == 'e' )
    {
      isLegit = true;
    }
  }
  if( isLegit )
  {
    std::cout << "Bool parsed: "
	      << ( ( rawJson[start] == 't' ) ? "true" : "false" ) << std::endl;
    ++index;
    return rawJson[start] == 't';
  }
  else
  {
    std::string err = "Error parsing JSON at character ";
    // FIXME
    throw std::invalid_argument( err );
    //return false;
  }
}

template<typename T>
void JsonParser<T>::skipWhiteSpaces( const std::string& rawJson, unsigned int& index )
{
  while( rawJson[index] == ' ' )
  {
    ++index;
  }
}

template<typename T>
JsonEntity* JsonParser<T>::fromString( const std::string& rawJson,
				       sgdm::IAllocator<T>* allocator,
				       unsigned int& index )
{
  while( index < rawJson.length() - 1 )
  {
    if( rawJson[index] == '-' || ( rawJson[index] >= '0'
				   && rawJson[index] <= '9' ) )
    {
      std::cout << "Parsing number" << std::endl;
      parseNumber( rawJson, index );
    }
    switch( rawJson[index] )
    {
    case '\'':
    case '\"':
      std::cout << "Parsing string" << std::endl;
      parseString( rawJson, index );
      break;
    case '{':
      std::cout << "Parsing object" << std::endl;
      parseObject( rawJson, index );
      break;
    case '[':
      std::cout << "Parsing array" << std::endl;
      parseArray( rawJson, index );
      break;
    case 't':
    case 'f':
      std::cout << "Parsing boolean" << std::endl;
      parseBoolean( rawJson, index );
      break;
    case ',':
      ++index;
      break;
    case ' ':
      ++index;
      break;
    case '\n':
      ++index;
      break;
    default:
      break;
    }
  }
  std::cout << "Parsing ended correctly" << std::endl;
  return 0;
}


// MEMBER FUNCTIONS

template<typename T>
JsonEntity* JsonParser<T>::fromString( const std::string& rawJson,
				       sgdm::IAllocator<T>* allocator )
{
  unsigned int index = 0;
  return fromString( rawJson, allocator, index );
}

} // End sgdd namespace
} // End StevensDev namespace

#endif
