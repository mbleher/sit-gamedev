// actor.cpp

#include "actor.h"
#include "scene.h"
#include "dynamic_array.h"


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
			 std::placeholders::_1 ) )
{
}

Actor::Actor( sgdr::RenderableSprite* sprite, ActorType type )
  : d_sprite( sprite ), d_type( type ),
    d_onItem( std::bind( &Actor::onItem, this,
			 std::placeholders::_1 ) )
{
  sgde::EventDispatcher& dispatcher = sgde::EventBus::inst();
  dispatcher.add( "item", &d_onItem );
  if( type == PLAYER )
  {
    d_hp = 3;
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
  d_cBounds->move( x, y );
  sgdc::DynamicArray<ICollider*> array = scene.graph()->find( d_cBounds );
  if( array.length() > 0 )
  {
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
