// json_entity.h
// Helper class for JsonParser, represents all different types of JSON objects

#ifndef INCLUDED_JSON_ENTITY
# define INCLUDED_JSON_ENTITY

#include "dynamic_array.h"
#include "map.h"
#include <string>

namespace StevensDev
{
namespace sgdd
{

class JsonEntity
{
  public:
  enum EntityTypes
  {
    INT,
    DOUBLE,
    STRING,
    ARRAY,
    BOOL,
    OBJECT
  };

  private:
  EntityTypes d_type;
    // Enumeration, represents which type this Entity is
  union
  {
    int i;
    double d;
    std::string* s;
    sgdc::DynamicArray<JsonEntity*>* a;
    bool b;
    sgdc::Map<JsonEntity*>* m;
  } d_data;
    // Union that stores the value of the Entity
  public:
  // CONSTRUCTORS
  JsonEntity();
    // Default constructor
  JsonEntity( const JsonEntity& copy );
    // Copy constructor
  JsonEntity( int i );
    // Int constructor
  JsonEntity( double d );
    // Double constructor
  JsonEntity( std::string& s );
    // String constructor
  JsonEntity( sgdc::DynamicArray<JsonEntity*>& a );
    // Array constructor
  JsonEntity( bool b );
    // Boolean constructor
  JsonEntity( sgdc::Map<JsonEntity*>& m );
    // Map constructor

  // DESTRUCTOR
  ~JsonEntity();

  // ACCESSORS
  EntityTypes type() const;
    // Gets JsonEntity type
  int asInt() const;
    // Returns JsonEntity as Integer
  double asDouble() const;
    // Returns JsonEntity as Double
  const std::string& asString() const;
    // Returns JsonEntity as String
  sgdc::DynamicArray<JsonEntity*>& asArray() const;
    // Returns JsonEntity as Array
  bool asBool() const;
    // Returns JsonEntity as Boolean

  // OPERATORS
  const JsonEntity& operator[]( const std::string& key ) const;
    // Returns value assigned to key (only on Object)
  const JsonEntity& operator[]( int index ) const;
    // Returns value at index (only on Array)

  // MEMBER FUNCTIONS
  bool isInt() const;
  bool isDouble() const;
  bool isString() const;
  bool isArray() const;
  bool isBool() const;
  bool isObject() const;
    // Returns true if JsonEntity is of this type
};

} // End sgdd namespace
} // End StevensDev namespace

#endif
