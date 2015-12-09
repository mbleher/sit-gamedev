// player_controller.h
// Processes the player inputs

#include "actor.h"
#include "itickable.h"

namespace StevensDev
{
namespace mgc
{
class PlayerController : public sgds::ITickable
{
  private:
  sgds::Actor* d_actor;
  public:
  // CONSTRUCTORS
  PlayerController();
  PlayerController( const PlayerController& copy );
  // DESTRUCTOR
  ~PlayerController();

  // MUTATORS
  void setActor( sgds::Actor* actor );
  // ACCESSORS
  sgds::Actor* actor() const;

  // INHERITED FUNCTIONS
  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End mgc namespace
} // End StevensDev namespace
