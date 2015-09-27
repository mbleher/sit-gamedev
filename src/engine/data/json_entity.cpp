// json_entity.cpp

#include "json_entity.h"
#include <cassert>

namespace StevensDev
{
namespace sgdd
{

// CONSTRUCTORS

JsonEntity::JsonEntity()
{
}

JsonEntity::JsonEntity( int i )
  : d_type( INT )
{
  d_data.i = i;
}

JsonEntity::JsonEntity( double d )
  : d_type( DOUBLE )
{
  d_data.d = d;
}

JsonEntity::JsonEntity( std::string& s )
  : d_type( STRING )
{
  d_data.s = &s;
}

JsonEntity::JsonEntity(sgdc::DynamicArray<JsonEntity>& a)
  : d_type( ARRAY )
{
  d_data.a = &a;
}

JsonEntity::JsonEntity( bool b )
  : d_type( BOOL )
{
  d_data.b = b;
}

JsonEntity::JsonEntity( sgdc::Map<JsonEntity>& m )
  : d_type( OBJECT )
{
  d_data.m = &m;
}


// DESTRUCTOR

JsonEntity::~JsonEntity()
{
}


// ACCESSORS

JsonEntity::EntityTypes JsonEntity::type() const
{
  return d_type;
}

int JsonEntity::asInt() const
{
  assert( d_type == INT );
  return d_data.i;
}

double JsonEntity::asDouble() const
{
  assert( d_type == DOUBLE );
  return d_data.d;
}

const std::string& JsonEntity::asString() const
{
  assert( d_type == STRING );
  return *d_data.s;
}

sgdc::DynamicArray<JsonEntity>& JsonEntity::asArray() const
{
  assert( d_type == ARRAY );
  return *d_data.a;
}

bool JsonEntity::asBool() const
{
  assert( d_type == BOOL );
  return d_data.b;
}


// OPERATORS

const JsonEntity& JsonEntity::operator[]( const std::string& key ) const
{
  assert( d_type == OBJECT );
  return ( *d_data.m )[key];
}

const JsonEntity& JsonEntity::operator[]( int index ) const
{
  assert( d_type == ARRAY );
  return ( *d_data.a )[index];
}


// MEMBER FUNCTIONS

bool JsonEntity::isInt() const
{
  return d_type == INT;
}

bool JsonEntity::isDouble() const
{
  return d_type == DOUBLE;
}

bool JsonEntity::isString() const
{
  return d_type == STRING;
}

bool JsonEntity::isArray() const
{
  return d_type == ARRAY;
}

bool JsonEntity::isBool() const
{
  return d_type == BOOL;
}

bool JsonEntity::isObject() const
{
  return d_type == OBJECT;
}

} // End sgdd namespace
} // End StevensDev namespace
