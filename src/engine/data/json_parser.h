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

class JsonParser
{
private:
  static sgdm::IAllocator<JsonEntity*>* d_alloc;

  // PRIVATE MEMBER FUNCTIONS
  static JsonEntity* parseNumber( const std::string& rawJson,
				  unsigned int& index );
  static void parseString( const std::string& rawJson,
			   unsigned int& index,
			   std::string& parsed );
  static JsonEntity* parseObject( const std::string& rawJson,
				  unsigned int& index );
  static JsonEntity* parseArray( const std::string& rawJson,
				 unsigned int& index );
  static JsonEntity* parseBoolean( const std::string& rawJson,
				   unsigned int& index );
  static void skipWhiteSpaces( const std::string& rawJson,
			       unsigned int& index );
  static JsonEntity* fromString( const std::string& rawJson,
				 unsigned int& index );
public:
  // MEMBER FUNCTIONS
  static JsonEntity* fromString( const std::string& rawJson,
				 sgdm::IAllocator<JsonEntity*>* allocator = 0 );
};

} // End sgdd namespace
} // End StevensDev namespace

#endif
