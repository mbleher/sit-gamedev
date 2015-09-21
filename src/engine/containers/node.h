// node.h

#ifndef INCLUDED_NODE
# define INCLUDED_NODE

#include <string>

namespace StevensDev
{
namespace sgdc
{
template<typename T>
class Node
{
  private:
  char d_key;
  int d_index;
  Node<T>** d_sons;
  public:
  Node();
  Node( char key );
  ~Node();
  int index() const;
  Node<T>* addSons( const std::string& key );
};

template<typename T>
inline
Node<T>::Node()
  : d_key( '0' ), d_index( -1 ), d_sons( 0 )
{
}

template<typename T>
inline
Node<T>::Node( char key )
  : d_key( key ), d_index( -1 ), d_sons( 0 )
{
}

template<typename T>
inline
Node<T>::~Node()
{
  if( d_sons != 0 )
  {
    for (unsigned int i = 0; i < 36; ++i)
    {
      delete d_sons[i];
    }
    delete [] d_sons;
  }
}

template<typename T>
inline
int Node<T>::index() const
{
  return d_index;
}

template<typename T>
inline
Node<T>* Node<T>::addSons( const std::string& key )
{
  if( d_sons == 0 )
  {
    d_sons = new Node<T>*[36];
  }
  if( key.length() > 1 )
  {
    Node<T>* son = new Node<T>();
    d_sons[key[0] - 'a'] = son;
    return son->addSons( key.substr( 1 ) );
  }
  return this;
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
