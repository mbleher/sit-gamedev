// scene.cpp

#include "scene.h"
#include "actor_factory.h"
#include "player_controller.h"
#include <iostream>

namespace StevensDev
{
namespace sgds
{
Scene* Scene::d_inst = 0;


// CONSTRUCTORS

Scene::Scene()
  : d_renderer( new sgdr::Renderer() )
{
  time( &d_currentTime );
}


// DESTRUCTOR

Scene::~Scene()
{
  delete d_inst;
  delete d_renderer;
}


// ACCESSORS

Scene& Scene::inst()
{
  if( !d_inst )
  {
    d_inst = new Scene;
  }
  return *d_inst;
}

sgdr::Renderer* Scene::renderer() const
{
  return d_renderer;
}


// MUTATORS

void Scene::setRenderer( sgdr::Renderer* renderer )
{
  d_renderer = renderer;
}


// MEMBER FUNCTIONS

void Scene::tick()
{
  d_renderer->draw();

  for( unsigned int i = 0; i < d_addedTickables.length(); ++i )
  {
    d_tickables.push( d_addedTickables[i] );
  }
  d_addedTickables.clear();
  time_t previousTime = d_currentTime;
  time( &d_currentTime );
  float deltaTime = previousTime - d_currentTime;
  for( unsigned int i = 0; i < d_tickables.length(); ++i )
  {
    d_tickables[i]->preTick();
  }
  for( unsigned int i = 0; i < d_tickables.length(); ++i )
  {
    d_tickables[i]->tick( deltaTime );
  }
  for( unsigned int i = 0; i < d_tickables.length(); ++i )
  {
    d_tickables[i]->postTick();
  }

  for( unsigned int i = 0; i < d_removedTickables.length(); ++i )
  {
    bool found = false;
    for( unsigned int j = 0; !found && j < d_tickables.length(); ++j )
    {
      if( d_removedTickables[i] == d_tickables[j] )
      {
	d_tickables.removeAt( j );
	found = true;
      }
    }
  }
  d_removedTickables.clear();
}

void Scene::addTickable( ITickable* tickable )
{
  d_addedTickables.push( tickable );
}

void Scene::removeTickable( ITickable* tickable )
{
  d_removedTickables.push( tickable );
}

void Scene::setup()
{
  d_renderer->loadTexture( "link", "../textures/link_mini.png" );
  d_renderer->loadTexture( "map", "../textures/dungeonmap_big.png" );

  sgdr::RenderableSprite* map =
    new sgdr::RenderableSprite( d_renderer->getTexture( "map" ) );
  d_renderer->setupWindow( map->width(), map->height() );
  d_renderer->addSprite( map );
  sgds::Actor* link = sgdf::ActorFactory::createActor( "link",
						       sgds::Actor::PLAYER,
						       map->width() / 2 - 17,
						       map->height() - 60 );

  // Walls setup

  

}

} // End sgdc namespace
} // End StevensDev namespace
