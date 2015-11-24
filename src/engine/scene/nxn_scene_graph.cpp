// nxn_scene_graph.cpp

#include "nxn_scene_graph.h"

namespace StevensDev
{
namespace sgds
{
// CONSTRUCTORS

NxNSceneGraph::NxNSceneGraph()
{
}

NxNSceneGraph::NxNSceneGraph( const NxNSceneGraph& copy )
  : d_dimensions( copy.d_dimensions ), d_divisions( copy.d_divisions )
{
}

NxNSceneGraph::NxNSceneGraph( float dimensions, int divisions )
  : d_dimensions( dimensions ), d_divisions( divisions )
{
}


// DESTRUCTOR

NxNSceneGraph::~NxNSceneGraph()
{
}


// MEMBER FUNCTIONS

void NxNSceneGraph::addCollider( ICollider* collider )
{
  d_addedColliders.push( collider );
}

void NxNSceneGraph::removeCollider( ICollider* collider )
{
  d_removedColliders.push( collider );
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( float x, float y,
						    float width,
						    float height ) const
{
  sgdc::DynamicArray<ICollider*> filteredColliders;

  for( unsigned int i = 0; i < d_colliders.length(); ++i )
  {
    if( d_colliders[i]->doesCollide( RectangleBounds( x, y, width, height ) ) )
    {
      filteredColliders.push( d_colliders[i] );
    }
  }

  return filteredColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( float x, float y,
						    float width, float height,
						    unsigned short flags ) const
{
  sgdc::DynamicArray<ICollider*> filteredColliders;

  for( unsigned int i = 0; i < d_colliders.length(); ++i )
  {
    if( d_colliders[i]->doesCollide( RectangleBounds( x, y, width, height ) )
	&& ( flags & d_colliders[i]->flags() ) )
    {
      filteredColliders.push( d_colliders[i] );
    }
  }

  return filteredColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find(
  const RectangleBounds& bounds ) const
{
  sgdc::DynamicArray<ICollider*> filteredColliders;

  for( unsigned int i = 0; i < d_colliders.length(); ++i )
  {
    if( d_colliders[i]->doesCollide( bounds ) )
    {
      filteredColliders.push( d_colliders[i] );
    }
  }

  return filteredColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find(
  const RectangleBounds& bounds, unsigned short flags ) const
{
  sgdc::DynamicArray<ICollider*> filteredColliders;

  for( unsigned int i = 0; i < d_colliders.length(); ++i )
  {
    if( d_colliders[i]->doesCollide( bounds )
	&& ( flags & d_colliders[i]->flags() ) )
    {
      filteredColliders.push( d_colliders[i] );
    }
  }

  return filteredColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( const ICollider* collider )
  const
{
  sgdc::DynamicArray<ICollider*> filteredColliders;

  for( unsigned int i = 0; i < d_colliders.length(); ++i )
  {
    if( d_colliders[i]->doesCollide( collider->bounds() )
	&& d_colliders[i] != collider )
    {
      filteredColliders.push( d_colliders[i] );
    }
  }

  return filteredColliders;
}


// INHERITED FUNCTIONS

void NxNSceneGraph::preTick()
{
}

void NxNSceneGraph::tick( float dtS )
{
}

void NxNSceneGraph::postTick()
{
  for( unsigned int i = 0; i < d_addedColliders.length(); ++i )
  {
    d_colliders.push( d_addedColliders[i] );
  }
  d_addedColliders.clear();

  for( unsigned int i = 0; i < d_addedColliders.length(); ++i )
  {
    bool found = false;

    for( unsigned int j = 0; !found && j < d_colliders.length(); ++j )
    {
      if( d_removedColliders[i] == d_colliders[j] )
      {
	d_colliders.removeAt( j );
	found = true;
      }
    }
  }
  d_removedColliders.clear();
}

} // End sgds namespace
} // End StevensDev namespace
