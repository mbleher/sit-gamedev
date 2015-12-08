// event_bus.cpp

#include "event_bus.h"

namespace StevensDev
{
namespace sgde
{

EventBus* EventBus::d_inst = 0;
EventDispatcher EventBus::d_dispatcher;

EventBus::EventBus()
{
}

EventDispatcher& EventBus::inst()
{
  if( !d_inst )
  {
    d_inst = new EventBus;
  }

  return d_dispatcher;
}

} // End sgde namespace
} // End StevensDev namespace
