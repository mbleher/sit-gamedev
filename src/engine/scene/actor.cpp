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
  : d_sprite( copy.d_sprite ), d_cBounds( copy.d_cBounds )
{
}

Actor::Actor( sgdr::RenderableSprite* sprite, ActorType type )
  : d_sprite( sprite ), d_type( type )
{
  d_cBounds = new CollidableBounds( sprite->getPositionX(),
				    sprite->getPositionY(),
				    sprite->width(),
				    sprite->height() );
}

Actor::~Actor()
{
  delete d_cBounds;
}

void Actor::setSprite( sgdr::RenderableSprite* sprite )
{
  d_sprite = sprite;
  d_cBounds->bounds().setX( sprite->getPositionX() );
  d_cBounds->bounds().setY( sprite->getPositionY() );
  d_cBounds->bounds().setWidth( sprite->width() );
  d_cBounds->bounds().setHeight( sprite->height() );
}

sgdr::RenderableSprite* Actor::sprite() const
{
  return d_sprite;
}

CollidableBounds* Actor::cBounds() const
{
  return d_cBounds;
}

void Actor::move( float x, float y )
{
  d_sprite->move( x, y );
  d_cBounds->move( x, y );
}

void Actor::preTick()
{
}

void Actor::tick( float dtS )
{
}

void Actor::postTick()
{
}

} // End sgds namespace
} // End StevensDev namespace
