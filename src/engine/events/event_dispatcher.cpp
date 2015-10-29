// event_dispatcher.cpp

#include "event_dispatcher.h"

namespace StevensDev
{
namespace sgde
{
EventDispatcher::EventDispatcher()
{
}

EventDispatcher::EventDispatcher( const EventDispatcher& copy )
{
}

EventDispatcher::~EventDispatcher()
{
}

void EventDispatcher::add( std::function<void( const IEvent& )>* listener )
{
  d_listeners.push( listener );
}

void EventDispatcher::remove( std::function<void( const IEvent& )>* listener )
{
  bool found = false;
  for( unsigned int i = 0; !found && i < d_listeners.length(); ++i )
  {
    if( d_listeners[i] == listener )
    {
      found = true;
      d_listeners.removeAt( i );
    }
  }
}

void EventDispatcher::dispatch( const IEvent& event )
{
  for( unsigned int i = 0; i < d_listeners.length(); ++i )
  {
    ( *d_listeners[i] )( event );
  }
}

void EventDispatcher::preTick()
{
  return;
}

void EventDispatcher::tick( float dtS )
{
  return;
}

void EventDispatcher::postTick()
{
  return;
}

} // End sgde namespace
} // End StevensDev namespace
