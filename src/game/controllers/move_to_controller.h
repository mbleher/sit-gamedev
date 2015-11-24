// move_to_controller.h
// Moves towards a position until it collides with something, then changes
// direction.

#include "renderable_sprite.h"

namespace StevensDev
{
namespace mgc
{
class MoveToController
{
  private:
  public:
  // CONSTRUCTORS
  MoveToController();
    // Default constructor
  MoveToController( const MoveToController& copy );
    // Copy constructor
  ~MoveToController();
};
} // End mgc namespace
} // End StevensDev namespace
