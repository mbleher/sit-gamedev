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
  d_colliders.push( collider );
}

void NxNSceneGraph::removeCollider( ICollider* collider )
{
  bool found = false;

  for( unsigned int i = 0; !found && i < d_colliders.length(); ++i )
  {
    if( collider == d_colliders[i] )
    {
      d_colliders.removeAt( i );
      found = true;
    }
  }
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
	&& flags == d_colliders[i]->flags() )
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
	&& flags == d_colliders[i]->flags() )
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
}

} // End sgds namespace
} // End StevensDev namespace
