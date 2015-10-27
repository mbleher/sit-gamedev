// renderable_sprite.h

#ifndef INCLUDED_RENDERABLE_SPRITE
# define INCLUDED_RENDERABLE_SPRITE

#include <SFML/Graphics.hpp>

namespace StevensDev
{
namespace sgdr
{

class RenderableSprite
{
private:
  sf::Sprite d_sprite;
public:
  // CONSTRUCTORS
  RenderableSprite( const sf::Texture& texture );
    // Default constructor
  RenderableSprite( const RenderableSprite& copy );
    // Copy constructor

  // DESTRUCTOR
  ~RenderableSprite();

  // ACCESSORS
  const sf::Sprite& sprite() const;
  float getPositionX() const;
    // Gets absolute x position
  float getPositionY() const;
    // Gets absolute y position

  // SETTERS
  void setPosition( float x, float y );
    // Sets absolute x/y position
  void move( float x, float y );
    // Increments x by x, y by y
};

} // End sgdr namespace
} // End StevensDev namespace

#endif
