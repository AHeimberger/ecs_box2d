#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>
#include <entityx/System.h>

class RenderSystem : public entityx::System<RenderSystem>
{
public:
   explicit RenderSystem(sf::RenderTarget& target);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:
   sf::RenderTarget& target;
};

#endif // RENDERSYSTEM_H