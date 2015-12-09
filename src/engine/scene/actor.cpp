// actor.cpp

#include "actor.h"
#include "scene.h"
#include "dynamic_array.h"
#include "event_bus.h"

namespace StevensDev
{
namespace sgds
{
Actor::Actor()
{
}

Actor::Actor( const Actor& copy )
  : d_sprite( copy.d_sprite ), d_cBounds( copy.d_cBounds ),
    d_onItem( std::bind( &Actor::onItem, this,
			 std::placeholders::_1 ) ),
    d_onPlayerHit( std::bind( &Actor::onPlayerHit, this,
			      std::placeholders::_1 ) ),
    d_onEnemyHit( std::bind( &Actor::onEnemyHit, this,
			      std::placeholders::_1 ) ),
    d_hasWeapon( copy.d_hasWeapon )
{
}

Actor::Actor( sgdr::RenderableSprite* sprite, ActorType type )
  : d_sprite( sprite ), d_type( type ),
    d_onItem( std::bind( &Actor::onItem, this,
			 std::placeholders::_1 ) ),
    d_onPlayerHit( std::bind( &Actor::onPlayerHit, this,
			      std::placeholders::_1 ) ),
    d_onEnemyHit( std::bind( &Actor::onEnemyHit, this,
			      std::placeholders::_1 ) ),
    d_hasWeapon( false )
{
  sgde::EventDispatcher& dispatcher = sgde::EventBus::inst();
  dispatcher.add( "item", &d_onItem );
  dispatcher.add( "playerHit", &d_onPlayerHit );
  dispatcher.add( "enemyHit", &d_onEnemyHit );
  if( type == PLAYER )
  {
    d_hp = 10;
  }

  d_cBounds = new CollidableBounds( sprite->getPositionX(),
				    sprite->getPositionY(),
				    sprite->width(),
				    sprite->height(),
				    type );
}

Actor::~Actor()
{
  delete d_cBounds;
}

void Actor::setSprite( sgdr::RenderableSprite* sprite )
{
  Scene& scene = Scene::inst();
  float prevX = d_sprite->getPositionX();
  float prevY = d_sprite->getPositionY();

  scene.renderer()->removeSprite( d_sprite );
  d_sprite = sprite;
  d_sprite->setPosition( prevX, prevY );
  scene.renderer()->addSprite( d_sprite );
  d_cBounds->bounds().setX( sprite->getPositionX() );
  d_cBounds->bounds().setY( sprite->getPositionY() );
  d_cBounds->bounds().setWidth( sprite->width() );
  d_cBounds->bounds().setHeight( sprite->height() );
}

sgdr::RenderableSprite* Actor::sprite() const
{
  return d_sprite;
}

CollidableBounds* Actor::cBounds() const
{
  return d_cBounds;
}

void Actor::move( float x, float y )
{
  Scene& scene = Scene::inst();
  sgde::EventDispatcher& dispatcher = sgde::EventBus::inst();
  d_cBounds->move( x, y );
  sgdc::DynamicArray<ICollider*> array = scene.graph()->find( d_cBounds );
  if( array.length() > 0 )
  {
    for( unsigned int i = 0; i < array.length(); ++i )
    {
      if( array[i]->flags() == 3 )
      {
	if( !d_hasWeapon )
	{
	  sgde::IEvent event( "playerHit" );
	  dispatcher.dispatch( event );
	}
	else
	{
	  sgde::IEvent event( "enemyHit" );
	  dispatcher.dispatch( event );
	}
      }
    }
    d_cBounds->move( -x, -y );
  }
  else
  {
    d_sprite->move( x, y );
    
    if( d_cBounds->bounds().x() < 0 )
    {
      move( scene.graph()->mapWidth(), 0 );
    }
    else if( d_cBounds->bounds().x() > scene.graph()->mapWidth() )
    {
      move( - scene.graph()->mapWidth(), 0 );
    }
  }
}

void Actor::onItem( const sgde::IEvent& event )
{
  static bool first = true;
  Scene& scene = Scene::inst();

  if( first && d_type == PLAYER )
  {    
    setSprite( new sgdr::RenderableSprite(
		 scene.renderer()->getTexture( "link" ) ) );
    d_hasWeapon = true;
    first = false;
  }
  else
  {
    if( d_type == ITEM )
    {
      scene.renderer()->removeSprite( d_sprite );
      scene.removeTickable( this );
    }
  }
}

void Actor::onPlayerHit( const sgde::IEvent& event )
{
  Scene& scene = Scene::inst();
  if( d_type == PLAYER )
  {
    if( --d_hp == 0 )
    {
      scene.renderer()->removeSprite( d_sprite );
      scene.removeTickable( this );
    }
  }
}

void Actor::onEnemyHit( const sgde::IEvent& event )
{
  Scene& scene = Scene::inst();
  if( d_type == SOLDIER )
  {
    scene.graph()->removeCollider( d_cBounds );
    scene.renderer()->removeSprite( d_sprite );
    scene.removeTickable( this );
  }
}

void Actor::preTick()
{
}

void Actor::tick( float dtS )
{
}

void Actor::postTick()
{
}

} // End sgds namespace
} // End StevensDev namespace
