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
  : d_listeners( copy.d_listeners ),
    d_addedListeners( copy.d_addedListeners ),
    d_removedListeners( copy.d_removedListeners )
{
}

EventDispatcher::~EventDispatcher()
{
}

void EventDispatcher::add( Listener* listener )
{
  d_addedListeners.push( listener );
}

void EventDispatcher::remove( Listener* listener )
{
  d_removedListeners.push( listener );
}

void EventDispatcher::dispatch( const std::string& id, const IEvent& event )
{
  for( unsigned int i = 0; i < d_listeners.length(); ++i )
  {
    if( id == d_listeners[i]->first )
    {
      ( *( d_listeners[i]->second ) )( event );
    }
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
  for( unsigned int i = 0; i < d_addedListeners.length(); ++i )
  {
    d_listeners.push( d_addedListeners[i] );
  }
  d_addedListeners.clear();
  for( unsigned int i = 0; i < d_removedListeners.length(); ++i )
  {
    bool found = false;
    for( unsigned int j = 0; !found && j < d_listeners.length(); ++j )
    {
      if( d_listeners[j] == d_removedListeners[i] )
      {
	found = true;
	d_listeners.removeAt( j );
      }
    }
  }
  d_removedListeners.clear();
}

} // End sgde namespace
} // End StevensDev namespace
