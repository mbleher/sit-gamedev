// json_entity.h

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
  union
  {
    int i;
    double d;
    std::string* s;
    sgdc::DynamicArray<JsonEntity*>* a;
    bool b;
    sgdc::Map<JsonEntity*>* m;
  } d_data;
  public:
  // CONSTRUCTORS
  JsonEntity();
  JsonEntity( const JsonEntity& copy );
  JsonEntity( int i );
  JsonEntity( double d );
  JsonEntity( std::string& s );
  JsonEntity( sgdc::DynamicArray<JsonEntity*>& a );
  JsonEntity( bool b );
  JsonEntity( sgdc::Map<JsonEntity*>& m );

  // DESTRUCTOR
  ~JsonEntity();

  // ACCESSORS
  EntityTypes type() const;
  int asInt() const;
  double asDouble() const;
  const std::string& asString() const;
  sgdc::DynamicArray<JsonEntity*>& asArray() const;
  bool asBool() const;

  // OPERATORS
  const JsonEntity& operator[]( const std::string& key ) const;
  const JsonEntity& operator[]( int index ) const;
  //JsonEntity& operator[]( const std::string& key ) const;

  // MEMBER FUNCTIONS
  bool isInt() const;
  bool isDouble() const;
  bool isString() const;
  bool isArray() const;
  bool isBool() const;
  bool isObject() const;
};

} // End sgdd namespace
} // End StevensDev namespace

#endif
