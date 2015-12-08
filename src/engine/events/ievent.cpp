// ievent.cpp

#include "ievent.h"

namespace StevensDev
{
namespace sgde
{

IEvent::IEvent()
{
}

IEvent::IEvent( const std::string& type )
  : d_type( type )
{
}

IEvent::~IEvent()
{
}

const std::string& IEvent::type() const
{
  return d_type;
}

} // End sgde namespace
} // End StevensDev namespace
