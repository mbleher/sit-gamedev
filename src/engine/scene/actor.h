// actor.h

#include "itickable.h"
#include "renderable_sprite.h"

#ifndef INCLUDED_ACTOR
# define INCLUDED_ACTOR

namespace StevensDev
{
namespace sgds
{

class Actor : public ITickable
{
private:
  sgdr::RenderableSprite* d_sprite;
  
public:
  Actor();
  Actor( const Actor& copy );
  Actor( sgdr::RenderableSprite* sprite );
  ~Actor();
  void setSprite( sgdr::RenderableSprite* sprite );
  sgdr::RenderableSprite* sprite() const;
  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End sgds namespace
} // End StevensDev namespace

#endif

