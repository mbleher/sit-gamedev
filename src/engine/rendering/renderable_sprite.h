// renderable_sprite.h

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
  RenderableSprite( sf::Sprite sprite );
    // Default constructor
  RenderableSprite( const RenderableSprite& copy );
    // Copy constructor
  ~RenderableSprite();
  const sf::Sprite& sprite() const;
  void setPosition( float x, float y );
    // Sets absolute x/y position
  float getPositionX() const;
    // Gets absolute x position
  float getPositionY() const;
    // Gets absolute y position
  void move( float x, float y );
    // Increments x by x, y by y
};

} // End sgdr namespace
} // End StevensDev namespace
