// nxn_scene_graph.h
// Grid that holds all the colliders

#ifndef INCLUDED_NXN_SCENE_GRAPH
# define INCLUDED_NXN_SCENE_GRAPH

#include "itickable.h"
#include "dynamic_array.h"
#include "icollider.h"
#include "collidable_bounds.h"

namespace StevensDev
{
namespace sgds
{
class NxNSceneGraph : public ITickable
{
  private:
  float d_dimensions;
    // Dimensions of the scene
  float d_divisions;
    // Number of divisions for the grid
  sgdc::DynamicArray<ICollider*> d_colliders;
    // Array of colliders to compare
  sgdc::DynamicArray<ICollider*> d_addedColliders;
    // Array of colliders to be added during post-tick
  sgdc::DynamicArray<ICollider*> d_removedColliders;
    // Array of colliders to be removed during post-tick
  sgdc::DynamicArray<CollidableBounds*> d_walls;
  public:
  // CONSTRUCTORS
  NxNSceneGraph();
    // Default constructor
  NxNSceneGraph( const NxNSceneGraph& copy );
    // Copy constructor
  NxNSceneGraph( float dimensions, int divisions );
    // Constructor

  // DESTRUCTOR
  ~NxNSceneGraph();

  // MEMBER FUNCTIONS
  void addCollider( ICollider* collider );
  void removeCollider( ICollider* collider );

  void addWall( float x1, float y1, float x2, float y2 );

  sgdc::DynamicArray<ICollider*> find( float x, float y,
				       float width, float height ) const;
  sgdc::DynamicArray<ICollider*> find( float x, float y,
				       float width, float height,
				       unsigned short flags ) const;
  sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds ) const;
  sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds,
				       unsigned short flags ) const;
  sgdc::DynamicArray<ICollider*> find( const ICollider* collider ) const;

  // INHERITED FUNCTIONS
  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End sgds namespace
} // End StevensDev namespace

#endif
