// game.m.cpp

#include "scene.h"

int main( int argc, char **argv )
{
  using namespace StevensDev;

  sgds::Scene& scene = sgds::Scene::inst();
  scene.setup();

  while( scene.renderer()->isActive() )
  {
    scene.tick();
  }
  
  return 0;
}
