// event_dispatcher.h

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
  sgdc::DynamicArray<std::function<void( const IEvent& )>*> d_listeners;
public:
  EventDispatcher();
  EventDispatcher( const EventDispatcher& copy );
  ~EventDispatcher();

  void add( std::function<void( const IEvent& )>* listener );
  void remove( std::function<void( const IEvent& )>* listener );
  void dispatch( const IEvent& );

  void preTick();
  void tick( float dtS );
  void postTick();
};
} // End sgde namespace
} // End StevensDev namespace

#endif
