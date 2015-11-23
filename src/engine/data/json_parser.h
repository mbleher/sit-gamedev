// json_parser.h
// Parser for JSON strings

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
    // Pointer to JsonEntity allocator

  // PRIVATE MEMBER FUNCTIONS
  static JsonEntity* parseNumber( const std::string& rawJson,
				  unsigned int& index );
    // Number parsing
  static void parseString( const std::string& rawJson,
			   unsigned int& index,
			   std::string& parsed );
    // String parsing, different from others because
    // we want to use it to retrieve keys in object
    // without creating JsonEntity
  static JsonEntity* parseObject( const std::string& rawJson,
				  unsigned int& index );
    // Object parsing
  static JsonEntity* parseArray( const std::string& rawJson,
				 unsigned int& index );
    // Array parsing
  static JsonEntity* parseBoolean( const std::string& rawJson,
				   unsigned int& index );
    // Boolean parsing
  static void skipWhiteSpaces( const std::string& rawJson,
			       unsigned int& index );
    // Iterate over spaces, tabs and carriage return
  static JsonEntity* fromString( const std::string& rawJson,
				 unsigned int& index );
    // Returns a new JsonEntity from a raw JSON string
public:
  // MEMBER FUNCTIONS
  static JsonEntity* fromString( const std::string& rawJson,
				 sgdm::IAllocator<JsonEntity*>* allocator = 0 );
    // Returns a new JsonEntity from a raw JSON string
};

} // End sgdd namespace
} // End StevensDev namespace

#endif
