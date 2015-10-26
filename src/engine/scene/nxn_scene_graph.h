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
  NxNSceneGraph();
  NxNSceneGraph( const NxNSceneGraph& copy );
  NxNSceneGraph( float dimensions, int divisions );
  ~NxNSceneGraph();
  
  void addCollider( ICollider* collider );
  void removeCollider( ICollider* collider );

  sgdc::DynamicArray<ICollider*> find( float x, float y,
				       float width, float height );
  sgdc::DynamicArray<ICollider*> find( float x, float y,
				       float width, float height,
				       unsigned short flags );
  sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds );
  sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds,
				       unsigned short flags );
  sgdc::DynamicArray<ICollider*> find( const ICollider* collider );

  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End sgds namespace
} // End StevensDev namespace

#endif
