// move_to_controller.cpp

#include "move_to_controller.h"

namespace StevensDev
{
namespace mgc
{
// CONSTRUCTORS

MoveToController::MoveToController()
{
}

MoveToController::MoveToController( float x, float y )
{
  d_positions.push( new Position( x, y ) );
  d_targetId = 0;
}

MoveToController::MoveToController( const MoveToController& copy )
  : d_positions( copy.d_positions ),
    d_targetId( copy.d_targetId ),
    d_actor( copy.d_actor )
{
}


// DESTRUCTOR

MoveToController::~MoveToController()
{
}

void MoveToController::setActor( sgds::Actor* actor )
{
  d_actor = actor;
}

void MoveToController::addPosition( float x, float y )
{
  d_positions.push( new Position( x, y ) );
}

void MoveToController::preTick()
{
  return;
}

void MoveToController::tick( float dtS )
{
  if( d_actor->sprite()->getPositionX()
      < d_positions[d_targetId]->first )
  {
    d_actor->move( 1, 0 );
    return;
  }
  if( d_actor->sprite()->getPositionX()
      > d_positions[d_targetId]->first )
  {
    d_actor->move( -1, 0 );
    return;
  }
  if( d_actor->sprite()->getPositionY()
      < d_positions[d_targetId]->second )
  {
    d_actor->move( 0, 1 );
    return;
  }
  if( d_actor->sprite()->getPositionY()
      > d_positions[d_targetId]->second )
  {
    d_actor->move( 0, -1 );
    return;
  }
  d_targetId = ( d_targetId + 1 ) % d_positions.length();
  return;
}

void MoveToController::postTick()
{
  return;
}

} // End mgc namespace
} // End StevensDev namespace
