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
}

void Scene::addTickable( ITickable* tickable )
{
  d_tickables.push( tickable );
}

void Scene::removeTickable( ITickable* tickable )
{
  for( unsigned int i = 0; i < d_tickables.length(); ++i )
  {
    if( d_tickables[i] == tickable )
    {
      d_tickables.removeAt( i );
      return;
    }
  }
}

} // End sgdc namespace
} // End StevensDev namespace
