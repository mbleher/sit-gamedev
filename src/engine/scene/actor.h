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
  std::function<void( const sgde::IEvent& event )> d_onPlayerHit;
  std::function<void( const sgde::IEvent& event )> d_onEnemyHit;

  unsigned short d_hp;
  bool d_hasWeapon;
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
  void onPlayerHit( const sgde::IEvent& event );
  void onEnemyHit( const sgde::IEvent& event );


  virtual void preTick();
  virtual void tick( float dtS );
  virtual void postTick();
};
} // End sgds namespace
} // End StevensDev namespace

#endif
