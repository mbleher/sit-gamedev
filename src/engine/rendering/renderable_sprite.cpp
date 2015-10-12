// renderable_sprite.cpp

#include "renderable_sprite.h"

namespace StevensDev
{
namespace sgdr
{

RenderableSprite::RenderableSprite( sf::Sprite sprite )
  : d_sprite( sprite )
{
}

RenderableSprite::RenderableSprite( const RenderableSprite& copy )
  : d_sprite( copy.d_sprite )
{
}

RenderableSprite::~RenderableSprite()
{
}

const sf::Sprite& RenderableSprite::sprite() const
{
  return d_sprite;
}

void RenderableSprite::setPosition( float x, float y )
{
  d_sprite.setPosition( x, y );
}

float RenderableSprite::getPositionX() const
{
  return d_sprite.getPosition().x;
}

float RenderableSprite::getPositionY() const
{
  return d_sprite.getPosition().y;
}

void RenderableSprite::move( float x, float y )
{
  d_sprite.move( x, y );
}

} // End sgdr namespace
} // End StevensDev namespace
