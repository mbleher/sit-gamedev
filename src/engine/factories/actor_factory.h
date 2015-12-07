// actor_factory.h

#ifndef INCLUDED_ACTOR_FACTORY
# define INCLUDED_ACTOR_FACTORY

#include "dynamic_array.h"
#include "actor.h"
#include <string>

namespace StevensDev
{
namespace sgdf
{
class ActorFactory
{
private:
  static sgdc::DynamicArray<sgds::Actor*> d_actors;
public:
  ActorFactory();
  ~ActorFactory();
  static sgds::Actor* createActor( std::string texture, sgds::Actor::ActorType type,
				   float initX, float initY );
};
} // End sgdf namespace
} // End StevensDev namespace

#endif
