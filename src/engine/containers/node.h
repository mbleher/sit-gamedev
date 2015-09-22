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
    // Constructor
  Node( const Node& );
    // Copy constructor

  // DESTRUCTOR
  ~Node();

  // ACCESSORS
  int index() const;
    // Gets index
  char key() const;
    // Gets key
  static unsigned int current();
    // Gets static index

  // MEMBER FUNCTIONS
  int search( const std::string& key );
  int search( const std::string& key ) const;
    // Looks for the key, returns the index where found or a new index
  int remove( const std::string& key );
    // Removes a key-value
  bool has( const std::string& key ) const;
    // Determines if a key exists in the trie
  void updateIndexes( int fromIndex, bool first );
    // Called after removal, updates indexes since
    // the values were shifted in the array
  static int alNumToIndex( char c );
    // Convert an alphanumeric character to an index between 0 and 35, can throw.
  static void resetCurrent();
    // Resets the static index to 0 (needed in tests).
};

} // End sgdc namespace
} // End StevensDev namespace

#endif
