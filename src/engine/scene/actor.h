// actor.h

#include "itickable.h"
#include "collidable_bounds.h"
#include "renderable_sprite.h"
#include "event_bus.h"
#include <utility>

#ifndef INCLUDED_ACTOR
# define INCLUDED_ACTOR

namespace StevensDev
{
namespace sgds
{
class Actor : public ITickable
{
public:
enum ActorType
{
  ITEM = 0,
  PLAYER = 1,
  GHOST = 2,
  SOLDIER = 3
};
private:
  sgdr::RenderableSprite* d_sprite;
  ActorType d_type;
  CollidableBounds* d_cBounds;

  std::function<void( const sgde::IEvent& event )> d_onItem;

  unsigned short d_hp;
public:
  Actor();
  Actor( const Actor& copy );
  Actor( sgdr::RenderableSprite* sprite, ActorType type );
  ~Actor();
  void setSprite( sgdr::RenderableSprite* sprite );
  sgdr::RenderableSprite* sprite() const;
  CollidableBounds* cBounds() const;
  void move( float x, float y );

  void onItem( const sgde::IEvent& event );

  virtual void preTick();
  virtual void tick( float dtS );
  virtual void postTick();
};
} // End sgds namespace
} // End StevensDev namespace

#endif
