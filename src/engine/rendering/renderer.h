// renderer.h
// Responsible for rendering the sprites and handling the graphic window

#ifndef INCLUDED_RENDERER
# define INCLUDED_RENDERER

#include "dynamic_array.h"
#include "map.h"
#include "renderable_sprite.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <stdexcept>

namespace StevensDev
{
namespace sgdr
{
class Renderer
{
  private:
  sf::RenderWindow d_window;
    // Where to render the sprites
  sgdc::DynamicArray<RenderableSprite*> d_sprites;
    // Array of sprites
  sgdc::Map<sf::Texture> d_textures;
    // Map that holds textures
  public:
  // CONSTRUCTORS
  Renderer();
    // Default constructor
  Renderer( const Renderer& copy );
    // Copy constructor

  // DESTRUCTOR
  ~Renderer();

  // MEMBER FUNCTIONS
  void draw();
    // Draws the sprites
  void addSprite( RenderableSprite* sprite );
    // Adds a sprite
  void removeSprite( RenderableSprite* sprite );
    // Removes a sprite
  void setupWindow( int width, int height );
    // Setups a window 
  bool loadTexture( const std::string& name, const std::string& path );
    // Loads a Texture into the array
  const sf::Texture& getTexture( const std::string& name );
    // Gets a Texture from the array
  bool isActive();
    // Returns false once the window is ready to be destroyed
};
} // End sgdr namespace
} // End StevensDev namespace

#endif
