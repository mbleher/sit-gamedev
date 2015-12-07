// game.m.cpp

#include "scene.h"
#include "player_controller.h"

#define MAPW 512
#define MAPH 446

int main( int argc, char **argv )
{
  using namespace StevensDev;

  sgds::Scene& scene = sgds::Scene::inst();
  scene.setup();

  /*
  sgdr::RenderableSprite* link =
    new sgdr::RenderableSprite( scene.renderer()->getTexture( "link" ) );

  mgc::PlayerController playerController;
  playerController.setSprite( link );
  playerController.sprite()->setPosition( MAPW / 2 - 17, MAPH - 60 ); 
  scene.renderer()->addSprite( playerController.sprite() );
  scene.addTickable( &playerController );
  */
  while( scene.renderer()->isActive() )
  {
    scene.tick();
  }
  
  return 0;
}
