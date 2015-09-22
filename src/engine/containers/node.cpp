// node.cpp

#include "node.h"
#include <iostream>

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
    if( d_sons[key[0] - 'a'] == 0 )
    {
      Node* son = new Node( key[0] );
      d_sons[key[0] - 'a'] = son;
      return son->search( key.substr( 1 ) );
    }
    else
    {
      return d_sons[key[0] - 'a']->search( key.substr( 1 ) );
    }
  }
  if( d_index == -1 )
  {
    d_index = d_current++;
  }
  return d_index;
}

bool Node::has( const std::string& key ) const
{
  if( key.length() == 1 )
  {
    return ( d_sons != 0 && d_sons[key[0] - 'a']
	     && d_sons[key[0] - 'a']->d_index != -1 );
  }
  if( d_sons == 0 )
  {
    return false;
  }
  Node* son = d_sons[key[0] - 'a'];
  if( !son )
  {
    return false;
  }
  return son->has( key.substr( 1 ) );
}

unsigned int Node::current()
{
  return d_current;
}

} // End sgdc namespace
} // End StevensDev namespace
