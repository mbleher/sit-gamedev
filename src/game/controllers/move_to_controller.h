// move_to_controller.h
// Moves towards a position until it collides with something, then changes
// direction.

#include "itickable.h"
#include "actor.h"
#include <utility>

namespace StevensDev
{
namespace mgc
{
typedef std::pair<float, float> Position;
class MoveToController : public sgds::ITickable
{
  private:
  sgdc::DynamicArray<Position*> d_positions;
  unsigned short d_targetId;
  sgds::Actor* d_actor;
  public:
  // CONSTRUCTORS
  MoveToController();
  MoveToController( float x, float y );
    // Default constructor
  MoveToController( const MoveToController& copy );
    // Copy constructor
  ~MoveToController();

  void setActor( sgds::Actor* actor );

  void addPosition( float x, float y );

  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End mgc namespace
} // End StevensDev namespace
