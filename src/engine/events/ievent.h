// ievent.h

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
  virtual const std::string type() const = 0;
};
} // End sgde namespace
} // End StevensDev namespace

#endif
