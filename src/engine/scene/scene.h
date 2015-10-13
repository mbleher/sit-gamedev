// scene.h

#ifndef INCLUDED_SCENE
# define INCLUDED_SCENE

#include "itickable.h"
#include "dynamic_array.h"
#include "renderer.h"
#include <ctime>

namespace StevensDev
{
namespace sgds
{
class Scene
{
private:
  static Scene* d_inst;
  sgdr::Renderer* d_renderer;
  sgdc::DynamicArray<ITickable*> d_tickables;
  time_t d_currentTime;

  // CONSTRUCTORS
  Scene();
  Scene( const Scene& copy ) = delete;
  Scene& operator=( const Scene& assign ) = delete;
public:

  // DESTRUCTOR
  ~Scene();

  // ACCESSORS
  static Scene& inst();
    // Gets scene instance

  // MUTATORS
  void setRenderer( sgdr::Renderer* renderer );
    // Sets the renderer

  // MEMBER FUNCTIONS
  void tick();
    // Calls the pre-tick, tick and posttick methods on all tickables
  void addTickable( ITickable* tickable );
    // Adds a tickable
  void removeTickable( ITickable* tickable );
    // Removes a tickable
};
} // End sgdc namespace
} // End StevensDev namespace

#endif
