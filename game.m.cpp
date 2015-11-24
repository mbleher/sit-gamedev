// game.m.cpp

#include "scene.h"
#include "player_controller.h"

#define MAPW 512
#define MAPH 446

int main( int argc, char **argv )
{
  using namespace StevensDev;
  
  sgdr::Renderer* renderer = new sgdr::Renderer();
  renderer->loadTexture( "link", "../textures/link_mini.png" );
    // 42x35
  renderer->loadTexture( "map", "../textures/dungeonmap_big.png" );
    // 512x446
  renderer->setupWindow( MAPW, MAPH );

  sgds::Scene& scene = sgds::Scene::inst();
  scene.setRenderer( renderer );

  // FIXME: I should probably not do all of this here
  sgdr::RenderableSprite* link =
    new sgdr::RenderableSprite( renderer->getTexture( "link" ) );
  mgc::PlayerController playerController;
  playerController.setSprite( link );
  playerController.sprite()->setPosition( MAPW / 2 - 17, MAPH - 60 ); 
  renderer->addSprite(
    new sgdr::RenderableSprite( renderer->getTexture( "map" ) ) );
  renderer->addSprite( playerController.sprite() );
  scene.addTickable( &playerController );

  while( renderer->isActive() )
  {
    renderer->draw();
    scene.tick();
  }
  
  return 0;
}
