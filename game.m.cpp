// game.m.cpp

#include "scene.h"
#include "input.h"
#include "actor.h"

#include <queue>

#define DIST 3
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
  renderer->loadTexture( "sw", "../textures/master_sword_mini.png" );
    // 30x20
  renderer->setupWindow( MAPW, MAPH );

  std::queue<sgds::Actor*> qa;
  std::queue<sgdr::RenderableSprite*> qs;

  sgds::Scene& scene = sgds::Scene::inst();
  scene.setRenderer( renderer );

  sgdr::RenderableSprite* link =
    new sgdr::RenderableSprite( renderer->getTexture( "link" ) );
  link->setPosition( MAPW / 2 - 17, MAPH - 60 ); 
  renderer->addSprite(
    new sgdr::RenderableSprite( renderer->getTexture( "map" ) ) );
  renderer->addSprite( link );
  sgdi::Input& input = sgdi::Input::inst();

  while( renderer->isActive() )
  {
    renderer->draw();

    input.preTick();
    scene.tick();
    if( input.isDown( sgdi::Input::InputType::RIGHT_KEY ) )
    {
      link->move( DIST, 0 );
      if( link->getPositionX() + 42 > MAPW )
      {
	link->move( -MAPW, 0 );
      }
    }
    if( input.isDown( sgdi::Input::InputType::LEFT_KEY ) )
    {
      link->move( -DIST, 0 );
      if( link->getPositionX() < 0 )
      {
	link->move( MAPW, 0 );
      }
    }
    if( input.isDown( sgdi::Input::InputType::DOWN_KEY ) )
    {
      link->move( 0, DIST );
      if( link->getPositionY() + 35 > MAPH - 25 )
      {
	link->move( 0, -MAPH + 80 );
      }
    }
    if( input.isDown( sgdi::Input::InputType::UP_KEY ) )
    {
      link->move( 0, -DIST );
      if( link->getPositionY() < 30 )
      {
	link->move( 0, MAPH - 50 );
      }
    }
    if( input.isDown( sgdi::Input::InputType::A_KEY ) )
    {
      sgdr::RenderableSprite* sw =
	new sgdr::RenderableSprite( renderer->getTexture( "sw" ) );
      renderer->addSprite( sw );
      qs.push( sw );
      sgds::Actor* swA = new sgds::Actor( sw );
      if ( qa.size() > 10 )
      {
	scene.removeTickable( qa.front() );
	renderer->removeSprite( qs.front() );
	qa.pop();
	qs.pop();
      }
      //scene.removeTickable( &swA );
      qa.push( swA );
      scene.addTickable( swA );
      sw->setPosition( link->getPositionX(), link->getPositionY() + 10 );
    }
  }

  return 0;
}
