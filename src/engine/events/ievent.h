// ievent.h
// Payload for messaging from a dispatcher to listeners

#ifndef INCLUDED_IEVENT
# define INCLUDED_IEVENT

#include <string>

namespace StevensDev
{
namespace sgde
{
class IEvent
{
protected:
  std::string d_type;
public:
  IEvent();
  IEvent( const std::string& type );
  ~IEvent();
  virtual const std::string& type() const;
};
} // End sgde namespace
} // End StevensDev namespace

#endif
