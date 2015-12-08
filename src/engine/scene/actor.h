// actor.h

#include "itickable.h"
#include "collidable_bounds.h"
#include "renderable_sprite.h"

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
  PLAYER,
  NPC,
  WALL
};
private:
  sgdr::RenderableSprite* d_sprite;
  ActorType d_type;
  CollidableBounds* d_cBounds;
public:
  Actor();
  Actor( const Actor& copy );
  Actor( sgdr::RenderableSprite* sprite, ActorType type );
  ~Actor();
  void setSprite( sgdr::RenderableSprite* sprite );
  sgdr::RenderableSprite* sprite() const;
  CollidableBounds* cBounds() const;
  void move( float x, float y );

  virtual void preTick();
  virtual void tick( float dtS );
  virtual void postTick();
};
} // End sgds namespace
} // End StevensDev namespace

#endif

