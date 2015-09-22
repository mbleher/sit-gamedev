// node.cpp

#include "node.h"
#include <iostream>
#include <stdexcept>

namespace StevensDev
{
namespace sgdc
{

unsigned int Node::d_current = 0;

Node::Node()
  : d_key( '0' ), d_index( -1 ), d_sons( 0 )
{
}

Node::Node( char key )
  : d_key( key ), d_index( -1 ), d_sons( 0 )
{
}

Node::~Node()
{
/*
  if( d_sons != 0 )
  {
    for (unsigned int i = 0; i < 36; ++i)
    {
      if( d_sons[i] != 0 )
      {
	delete d_sons[i];
      }
    }
  }
*/
}

int Node::index() const
{
  return d_index;
}

int Node::search( const std::string& key )
{
  if( key.length() != 0 && d_sons == 0 )
  {
    d_sons = new Node*[36]();
  }
  if( key.length() > 0 )
  {
    if( d_sons[alNumToIndex( key[0] )] == 0 )
    {
      Node* son = new Node( key[0] );
      d_sons[alNumToIndex( key[0] )] = son;
      return son->search( key.substr( 1 ) );
    }
    else
    {
      return d_sons[alNumToIndex( key[0] )]->search( key.substr( 1 ) );
    }
  }
  if( d_index == -1 )
  {
    d_index = d_current++;
  }
  return d_index;
}

int Node::search( const std::string& key ) const
{
  if( key.length() > 0 )
  {
    if( d_sons[alNumToIndex( key[0] )] == 0 )
    {
      Node* son = new Node( key[0] );
      d_sons[alNumToIndex( key[0] )] = son;
      return son->search( key.substr( 1 ) );
    }
    else
    {
      return d_sons[alNumToIndex( key[0] )]->search( key.substr( 1 ) );
    }
  }
  return d_index;
}

int Node::remove( const std::string& key )
{
  if( key.length() > 1 )
  {
    return d_sons[alNumToIndex( key[0] )]->remove( key.substr( 1 ) );
  }
  int index = d_sons[alNumToIndex( key[0] )]->d_index;
  d_sons[alNumToIndex( key[0] )]->d_index = -1;
  return index;
}

bool Node::has( const std::string& key ) const
{
  if( key.length() == 1 )
  {
    return ( d_sons != 0 && d_sons[alNumToIndex( key[0] )]
	     && d_sons[alNumToIndex( key[0] )]->d_index != -1 );
  }
  if( d_sons == 0 )
  {
    return false;
  }
  Node* son = d_sons[alNumToIndex( key[0] )];
  if( !son )
  {
    return false;
  }
  return son->has( key.substr( 1 ) );
}

void Node::updateIndexes( int fromIndex, bool first )
{
  if( first )
  {
    --d_current;
  }
  if( d_index > fromIndex )
  {
    --d_index;
  }

  if( d_sons != 0 )
  {
    for( unsigned int i = 0; i < 36; ++i )
    {
      if( d_sons[i] != 0 )
      {
	d_sons[i]->updateIndexes( fromIndex, false );
      }
    }
  }
}

int Node::alNumToIndex( char c )
{
  if( !( c >= 'a' && c <= 'z' ) && !( c >= '0' && c <= '9' ) )
  {
    throw std::out_of_range( "unsupported key" );
  }
  if( c >= 'a' && c <= 'z' )
    return c - 'a';
  return c - '0' + 26;
}

unsigned int Node::current()
{
  return d_current;
}

void Node::resetCurrent()
{
  d_current = 0;
}

} // End sgdc namespace
} // End StevensDev namespace
