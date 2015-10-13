// renderer.cpp

#include "renderer.h"
#include <iostream>

namespace StevensDev
{
namespace sgdr
{

// CONSTRUCTORS

Renderer::Renderer()
{
}

Renderer::Renderer( const Renderer& copy )
  : d_sprites( copy.d_sprites ), d_textures( copy.d_textures )
{
}

// DESTRUCTOR

Renderer::~Renderer()
{
}


// MEMBER FUNCTIONS

void Renderer::draw()
{
  d_window.clear( sf::Color::Black );
  for( unsigned int i = 0; i < d_sprites.length(); ++i )
  {
    d_window.draw( d_sprites[i]->sprite() );
  }
  d_window.display();
}

void Renderer::addSprite( RenderableSprite* sprite )
{
  d_sprites.push( sprite );
}

void Renderer::removeSprite( RenderableSprite* sprite )
{
  for( unsigned int i = 0; i < d_sprites.length(); ++i )
  {
    if( d_sprites[i] == sprite )
    {
      d_sprites.removeAt( i );
      return;
    }
  }
}

void Renderer::setupWindow( int width, int height )
{
  d_window.create( sf::VideoMode( width, height ), "Game" );
}

bool Renderer::loadTexture( const std::string& name, const std::string& path )
{
  sf::Texture texture;

  if( !texture.loadFromFile( path ) )
  {
    throw std::invalid_argument( "File not found." );
  }
  d_textures[name] = texture;
}

const sf::Texture& Renderer::getTexture( const std::string& name )
{
  return d_textures[name];
}

bool Renderer::isActive()
{
  
  sf::Event event;
  while( d_window.pollEvent( event ) )
  {
    if( event.type == sf::Event::Closed )
    {
      return false;
    }
  }
  return true;
}

} // End sgdr namespace
} // End StevensDev namespace
