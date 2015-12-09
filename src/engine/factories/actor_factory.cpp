// actor_factory.cpp

#include "actor_factory.h"
#include "scene.h"
#include "player_controller.h"
#include "move_to_controller.h"

namespace StevensDev
{
namespace sgdf
{
sgdc::DynamicArray<sgds::Actor*> ActorFactory::d_actors =
  sgdc::DynamicArray<sgds::Actor*>();

ActorFactory::ActorFactory()
{
}

ActorFactory::~ActorFactory()
{
  for( unsigned int i = 0; i < d_actors.length(); ++i )
  {
    delete d_actors[i];
  }
}

sgds::Actor* ActorFactory::createActor( std::string texture,
					sgds::Actor::ActorType type,
					float initX, float initY )
{
  sgds::Scene& scene = sgds::Scene::inst();
  sgdr::RenderableSprite* sprite =
    new sgdr::RenderableSprite( scene.renderer()->getTexture( texture ) );
  sprite->setPosition( initX, initY );
  sgds::Actor* actor = new sgds::Actor( sprite, type );
  scene.renderer()->addSprite( sprite );
  if( type == sgds::Actor::ActorType::PLAYER )
  {
    mgc::PlayerController* playerController = new mgc::PlayerController();
    playerController->setActor( actor );
    scene.addTickable( playerController );
  }
  else if( type == sgds::Actor::ActorType::SOLDIER
	   || type == sgds::Actor::ActorType::GHOST )
  {
    if( type == sgds::Actor::ActorType::SOLDIER )
    {
      mgc::MoveToController* moveToController =
	new mgc::MoveToController( initX - 15, initY );
      moveToController->addPosition( initX + 15, initY );
      moveToController->setActor( actor );
      scene.addTickable( moveToController );
    }
    else
    {
      static bool first = true;
      if( first )
      {
	mgc::MoveToController* moveToController =
	  new mgc::MoveToController( initX, initY + 90 );
	moveToController->addPosition( initX + 90, initY + 90 );
	moveToController->addPosition( initX + 90, initY );
	moveToController->addPosition( initX, initY );
	moveToController->setActor( actor );
	scene.addTickable( moveToController );
	first = false;
      }
      else
      {
	mgc::MoveToController* moveToController =
	  new mgc::MoveToController( initX, initY + 90 );
	moveToController->addPosition( initX - 90, initY + 90 );
	moveToController->addPosition( initX - 90, initY );
	moveToController->addPosition( initX, initY );
	moveToController->setActor( actor );
	scene.addTickable( moveToController );
      }
    }
  }
  scene.addTickable( actor );
  d_actors.push( actor );
}
} // End sgdf namespace
} // End StevensDev namespace
