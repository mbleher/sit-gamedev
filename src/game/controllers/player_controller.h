// player_controller.h
// Processes the player inputs

//#include "renderable_sprite.h"
#include "actor.h"
#include "itickable.h"

namespace StevensDev
{
namespace mgc
{
class PlayerController : public sgds::ITickable
{
  private:
  //sgdr::RenderableSprite* d_sprite;
  sgds::Actor* d_actor;
  public:
  // CONSTRUCTORS
  PlayerController();
  PlayerController( const PlayerController& copy );
  // DESTRUCTOR
  ~PlayerController();

  // MUTATORS
  //void setSprite( sgdr::RenderableSprite* sprite );
  void setActor( sgds::Actor* actor );
  // ACCESSORS
  //sgdr::RenderableSprite* sprite() const;
  sgds::Actor* actor() const;

  // INHERITED FUNCTIONS
  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End mgc namespace
} // End StevensDev namespace
