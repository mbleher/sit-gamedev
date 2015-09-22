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

  // CONSTRUCTORS
  Node();
    // Default constructor
  Node( char key );
  Node( const Node& );
  ~Node();
  int index() const;
  int search( const std::string& key );
  int search( const std::string& key ) const;
  int remove( const std::string& key );
  bool has( const std::string& key ) const;
  void updateIndexes( int fromIndex, bool first );
  static int alNumToIndex( char c );
  static unsigned int current();
  static void resetCurrent();
};

} // End sgdc namespace
} // End StevensDev namespace

#endif
