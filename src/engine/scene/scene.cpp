// scene.cpp

#include "scene.h"

namespace StevensDev
{
namespace sgds
{
Scene* Scene::d_inst = 0;

Scene::Scene()
  : d_renderer( 0 )
{
  time( &d_currentTime );
}

Scene::~Scene()
{
  delete d_inst;
  delete d_renderer;
}

Scene& Scene::inst()
{
  if( !d_inst )
  {
    d_inst = new Scene;
  }
  return *d_inst;
}

void Scene::setRenderer( sgdr::Renderer* renderer )
{
  d_renderer = renderer;
}

void Scene::tick()
{
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

} // End sgdc namespace
} // End StevensDev namespace
