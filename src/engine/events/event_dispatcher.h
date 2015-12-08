// event_dispatcher.h
// Synchronous event broadcasting system

#ifndef INCLUDED_EVENT_DISPATCHER
# define INCLUDED_EVENT_DISPATCHER

#include "itickable.h"
#include "ievent.h"
#include "dynamic_array.h"
#include <functional>
#include <utility>
#include <string>

namespace StevensDev
{
namespace sgde
{

typedef std::pair<const std::string&,
		  std::function<void( const IEvent& )>*> Listener;

class EventDispatcher : public sgds::ITickable
{
  private:
  // PRIVATE MEMBERS
  sgdc::DynamicArray<Listener*> d_listeners;
    // Listeners currently bound
  sgdc::DynamicArray<Listener*> d_addedListeners;
    // Listeners to be added during post-tick
  sgdc::DynamicArray<Listener*> d_removedListeners;
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
  void add( Listener* listener );
    // Adds a listener
  void remove( Listener* listener );
    // Removes a listener
  void dispatch( const std::string& id, const IEvent& event );
    // Dispatchs an event to all listeners

  // INHERITED FUNCTIONS
  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End sgde namespace
} // End StevensDev namespace

#endif
