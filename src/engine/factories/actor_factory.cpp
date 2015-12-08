// actor_factory.cpp

#include "actor_factory.h"
#include "scene.h"
#include "player_controller.h"

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
  if ( type == sgds::Actor::ActorType::PLAYER )
  {
    sgdr::RenderableSprite* sprite =
      new sgdr::RenderableSprite( scene.renderer()->getTexture( texture ) );
    sprite->setPosition( initX, initY );
    sgds::Actor* actor = new sgds::Actor( sprite, type );
    scene.renderer()->addSprite( sprite );
    mgc::PlayerController* playerController = new mgc::PlayerController();
    playerController->setActor( actor );
    scene.addTickable( playerController );
    scene.addTickable( actor );
    d_actors.push( actor );
  }
}
} // End sgdf namespace
} // End StevensDev namespace
