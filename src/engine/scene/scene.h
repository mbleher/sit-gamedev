// scene.h
// Singleton that is responsible for all tickable objects

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
    // Single instance of Scene
  sgdr::Renderer* d_renderer;
    // Pointer on renderer responsible for displaying tickables
  sgdc::DynamicArray<ITickable*> d_tickables;
    // Array with current tickables
  sgdc::DynamicArray<ITickable*> d_addedTickables;
    // Array with the tickables to add to the scene
  sgdc::DynamicArray<ITickable*> d_removedTickables;
    // Array with the tickables to remove from the scene
  time_t d_currentTime;
    // Keeps the time to compute the delta for the tick function

  // CONSTRUCTORS
  Scene();
    // Default constructor
  Scene( const Scene& copy ) = delete;
    // Copy constructor
  Scene& operator=( const Scene& assign ) = delete;
    // Assignment operator

  public:
  // DESTRUCTOR
  ~Scene();

  // ACCESSORS
  static Scene& inst();
    // Gets scene instance
  sgdr::Renderer* renderer() const;

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
  void setup();
    // Loads textures, prepares rendering window, create actors
};
} // End sgdc namespace
} // End StevensDev namespace

#endif
