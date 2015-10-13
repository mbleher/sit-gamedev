// renderable_sprite.cpp

#include "renderable_sprite.h"

namespace StevensDev
{
namespace sgdr
{

// CONSTRUCTORS

RenderableSprite::RenderableSprite( const sf::Texture& texture )
  : d_sprite( texture )
{
}

RenderableSprite::RenderableSprite( const RenderableSprite& copy )
  : d_sprite( copy.d_sprite )
{
}


// DESTRUCTOR

RenderableSprite::~RenderableSprite()
{
}


// ACCESSORS

const sf::Sprite& RenderableSprite::sprite() const
{
  return d_sprite;
}

float RenderableSprite::getPositionX() const
{
  return d_sprite.getPosition().x;
}

float RenderableSprite::getPositionY() const
{
  return d_sprite.getPosition().y;
}


// SETTERS
void RenderableSprite::setPosition( float x, float y )
{
  d_sprite.setPosition( x, y );
}

void RenderableSprite::move( float x, float y )
{
  d_sprite.move( x, y );
}

} // End sgdr namespace
} // End StevensDev namespace
