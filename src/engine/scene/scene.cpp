// scene.cpp

#include "scene.h"
#include "actor_factory.h"
#include "collidable_bounds.h"

namespace StevensDev
{
namespace sgds
{
Scene* Scene::d_inst = 0;


// CONSTRUCTORS

Scene::Scene()
  : d_renderer( new sgdr::Renderer() ),
    d_graph( new NxNSceneGraph() )
{
  time( &d_currentTime );
}


// DESTRUCTOR

Scene::~Scene()
{
  delete d_inst;
  delete d_renderer;
  delete d_graph;
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

NxNSceneGraph* Scene::graph() const
{
  return d_graph;
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
  float w = map->width();
  float h = map->height();
  sgds::Actor* link = sgdf::ActorFactory::createActor( "link",
						       sgds::Actor::PLAYER,
						       w / 2 - 12,
						       h - 60 );
  d_graph->addCollider( link->cBounds() );

  // Walls setup
  d_graph->addWall( 0, 0, w, 30 );
  d_graph->addWall( 0, 30, 240, 72 );
  d_graph->addWall( 290, 30, w, 72 );
  d_graph->addWall( 40, 72, 170, 219 );
  d_graph->addWall( 360, 72, 491, 219 );
  d_graph->addWall( 0, 281, 73, h );
  d_graph->addWall( 73, 390, 240, h );
  d_graph->addWall( 240, 431, 290, h );
  d_graph->addWall( 290, 377, 455, h );
  d_graph->addWall( 455, 281, w, h );
  d_graph->addWall( 110, 284, 166, 344 );
  d_graph->addWall( 360, 284, 415, 344 );
  d_graph->addWall( 207, 125, 232, 184 );
  d_graph->addWall( 300, 125, 322, 184 );
  addTickable( d_graph );
}

} // End sgdc namespace
} // End StevensDev namespace
