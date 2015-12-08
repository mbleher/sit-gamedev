// event_bus.h
// Singleton wrapper around EventDispatcher

#ifndef INCLUDED_EVENT_BUS
# define INCLUDED_EVENT_BUS

#include "event_dispatcher.h"

namespace StevensDev
{
namespace sgde
{

class EventBus
{
private:
  static EventBus* d_inst;
  static EventDispatcher d_dispatcher;

  EventBus();

  EventBus( const EventBus& copy ) = delete;

public:
  static EventDispatcher& inst();
};

} // End sgde namespace
} // End StevensDev namespace

#endif
