// actor.cpp

#include "actor.h"

namespace StevensDev
{
namespace sgds
{
Actor::Actor()
{
}

Actor::Actor( const Actor& copy )
  : d_sprite( copy.d_sprite )
{
}

Actor::Actor( sgdr::RenderableSprite* sprite )
  : d_sprite( sprite )
{
}

Actor::~Actor()
{
}

void Actor::setSprite( sgdr::RenderableSprite* sprite )
{
  d_sprite = sprite;
}

sgdr::RenderableSprite* Actor::sprite() const
{
  return d_sprite;
}

void Actor::preTick()
{
}

void Actor::tick( float dtS )
{
  d_sprite->move( 0, 2 );
}

void Actor::postTick()
{
}

} // End sgds namespace
} // End StevensDev namespace
