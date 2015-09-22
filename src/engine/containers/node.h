// node.h

#ifndef INCLUDED_NODE
# define INCLUDED_NODE

#include <string>

namespace StevensDev
{
namespace sgdc
{
class Node
{
  private:
  char d_key;
  int d_index;
  Node** d_sons;
  static unsigned int d_current;
  public:
  Node();
  Node( char key );
  ~Node();
  int index() const;
  int search( const std::string& key );
  int search( const std::string& key ) const;
  bool has( const std::string& key ) const;
  static int alNumToIndex( char c );
  static unsigned int current();
};

} // End sgdc namespace
} // End StevensDev namespace

#endif
