// json_parser.cpp

#include "json_parser.h"

namespace StevensDev
{
namespace sgdd
{

sgdm::IAllocator<JsonEntity*>* JsonParser::d_alloc = 0;

// PRIVATE MEMBER FUNCTIONS

JsonEntity* JsonParser::parseNumber( const std::string& rawJson,
				     unsigned int& index )
{
  unsigned int start = index;
  //bool isNeg = false;
  bool isDouble = false;

  if( rawJson[index] == '-' )
  {
    //isNeg = true;
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
  if( isDouble )
  {
    return new JsonEntity(
      atof( rawJson.substr( start, index - start ).c_str() ) );
  }
  return new JsonEntity(
    atoi( rawJson.substr( start, index - start ).c_str() ) );
}

void JsonParser::parseString( const std::string& rawJson,
			      unsigned int& index,
			      std::string& parsed )
{
  if( rawJson[index] != '\"' )
  {
    // FIXME: throw exception
  }
  else
  {
    ++index;
  }
  unsigned int start = index;

  while( rawJson[index] != '\"' )
  {
    ++index;
  }
  parsed = rawJson.substr( start, index - start );
  ++index;
}

JsonEntity* JsonParser::parseObject( const std::string& rawJson,
			      unsigned int& index )
{
  unsigned int start = index;
  sgdc::Map<JsonEntity*> map; 
  std::string key;

  skipWhiteSpaces( rawJson, index );
  while( rawJson[index] != '}' )
  {
    parseString( rawJson, index, key );
    skipWhiteSpaces( rawJson, index );
    if( rawJson[index++] != ':' )
    {
      // FIXME: throw exception
      ;
    }
    skipWhiteSpaces( rawJson, index );
    unsigned int endValue;
    switch( rawJson[index] )
    {
    case '[':
      endValue = rawJson.find( ']', index ) + 1;
      break;
    case '{':
      endValue = rawJson.find( '}', index ) + 1;
      break;
    default:
      endValue = rawJson.find( ',', index ) + 1;
    }
    JsonEntity* value = 0;
    if( endValue != 0 )
    {
      value = fromString( rawJson.substr( index, endValue - index ),
			  d_alloc );
      map[key] = value;
      index = endValue;
    }
    else
    {
      value = fromString( rawJson.substr( index ),
			  d_alloc );
      map[key] = value;
      index = rawJson.find( '}', index );
    }
    skipWhiteSpaces( rawJson, index );
  }
  ++index;
  return new JsonEntity( map );
}

JsonEntity* JsonParser::parseArray( const std::string& rawJson,
			     unsigned int& index )
{
  if( rawJson[index] != '[' )
  {
    // FIXME: throw exception
  }
  else
  {
    ++index;
  }
  sgdc::DynamicArray<JsonEntity*> array;
  JsonEntity* elem = 0;
  unsigned int endElem;

  skipWhiteSpaces( rawJson, index );
  while( rawJson[index] != ']' )
  {
    endElem = rawJson.find( ',', index ) + 1;
    if( endElem != 0 )
    {
      elem = fromString( rawJson.substr( index, endElem - index ),
			 d_alloc );
      index = endElem;
    }
    else
    {
      elem = fromString( rawJson.substr( index ),
			 d_alloc );
      index = rawJson.find( ']', index );
    }
    array.push( elem );
    skipWhiteSpaces( rawJson, index );
  }
  ++index;
  return new JsonEntity( array );
}

JsonEntity* JsonParser::parseBoolean( const std::string& rawJson,
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
    ++index;
    return new JsonEntity( rawJson[start] == 't' );
  }
  else
  {
    std::string err = "Error parsing JSON at character ";
    // FIXME
    throw std::invalid_argument( err );
  }
}

void JsonParser::skipWhiteSpaces( const std::string& rawJson,
				  unsigned int& index )
{
  while( rawJson[index] == ' ' )
  {
    ++index;
  }
}

JsonEntity* JsonParser::fromString( const std::string& rawJson,
				    unsigned int& index )
{
  std::string parsed;

  while( index < rawJson.length() )
  {
    if( rawJson[index] == '-' || ( rawJson[index] >= '0'
				   && rawJson[index] <= '9' ) )
    {
      return parseNumber( rawJson, index );
    }
    switch( rawJson[index] )
    {
    case '\'':
    case '\"':
      parseString( rawJson, index, parsed );
      return new JsonEntity( parsed );
    case '{':
      ++index;
      return parseObject( rawJson, index );
      break;
    case '[':
      ++index;
      return parseArray( rawJson, index );
      break;
    case 't':
    case 'f':
      return new JsonEntity( parseBoolean( rawJson, index ) );
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
  return 0;
}


// MEMBER FUNCTIONS

JsonEntity* JsonParser::fromString( const std::string& rawJson,
				    sgdm::IAllocator<JsonEntity*>* allocator )
{
  unsigned int index = 0;

  if( allocator )
  {
    d_alloc = allocator;
  }
  else
  {
    d_alloc = new sgdm::DefaultAllocator<JsonEntity*>();
  }
  return fromString( rawJson, index );
}

} // End sgdd namespace
} // End StevensDev namespace
