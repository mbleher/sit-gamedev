// player_controller.cpp

#include "player_controller.h"
#include "input.h"

#define DIST 3

namespace StevensDev
{
namespace mgc
{
// CONSTRUCTORS

PlayerController::PlayerController()
{
}

PlayerController::PlayerController( const PlayerController& copy )
  : d_sprite( copy.d_sprite )
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::setSprite( sgdr::RenderableSprite* sprite )
{
  d_sprite = sprite;
}

sgdr::RenderableSprite* PlayerController::sprite() const
{
  return d_sprite;
}

void PlayerController::preTick()
{
  sgdi::Input& input = sgdi::Input::inst();
  input.preTick();
}

void PlayerController::tick( float dtS )
{
  sgdi::Input& input = sgdi::Input::inst();
  if( input.isDown( sgdi::Input::InputType::RIGHT_KEY )
      || input.isDown( sgdi::Input::InputType::D_KEY ) )
  {
    d_sprite->move( DIST, 0 );
  }
  if( input.isDown( sgdi::Input::InputType::LEFT_KEY )
      || input.isDown( sgdi::Input::InputType::A_KEY ) )
  {
    d_sprite->move( -DIST, 0 );
  }
  if( input.isDown( sgdi::Input::InputType::UP_KEY )
      || input.isDown( sgdi::Input::InputType::W_KEY ) )
  {
    d_sprite->move( 0, -DIST );
  }
  if( input.isDown( sgdi::Input::InputType::DOWN_KEY )
      || input.isDown( sgdi::Input::InputType::S_KEY ) )
  {
    d_sprite->move( 0, DIST );
  }
}

void PlayerController::postTick()
{
  return;
}

} // End mgc namespace
} // End StevensDev namespace
