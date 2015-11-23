// nxn_scene_graph.h

#ifndef INCLUDED_NXN_SCENE_GRAPH
# define INCLUDED_NXN_SCENE_GRAPH

#include "itickable.h"
#include "dynamic_array.h"
#include "icollider.h"

namespace StevensDev
{
namespace sgds
{
class NxNSceneGraph : public ITickable
{
private:
  float d_dimensions;
  float d_divisions;
  sgdc::DynamicArray<ICollider*> d_colliders;
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
