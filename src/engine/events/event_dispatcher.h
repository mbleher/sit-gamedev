// event_dispatcher.h
// Synchronous event broadcasting system

#ifndef INCLUDED_EVENT_DISPATCHER
# define INCLUDED_EVENT_DISPATCHER

#include "itickable.h"
#include "ievent.h"
#include "dynamic_array.h"
#include <functional>

namespace StevensDev
{
namespace sgde
{
class EventDispatcher : public sgds::ITickable
{
  private:
  // PRIVATE MEMBERS
  sgdc::DynamicArray<std::function<void( const IEvent& )>*> d_listeners;
    // Listeners currently bound
  sgdc::DynamicArray<std::function<void( const IEvent& )>*> d_addedListeners;
    // Listeners to be added during post-tick
  sgdc::DynamicArray<std::function<void( const IEvent& )>*> d_removedListeners;
    // Listeners to be removed during post-tick
  public:
  // CONSTRUCTORS
  EventDispatcher();
    // Default constructor
  EventDispatcher( const EventDispatcher& copy );
    // Copy constructor

  // DESTRUCTOR
  ~EventDispatcher();

  // MEMBER FUNCTIONS
  void add( std::function<void( const IEvent& )>* listener );
    // Adds a listener
  void remove( std::function<void( const IEvent& )>* listener );
    // Removes a listener
  void dispatch( const IEvent& );
    // Dispatchs an event to all listeners

  // INHERITED FUNCTIONS
  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End sgde namespace
} // End StevensDev namespace

#endif
