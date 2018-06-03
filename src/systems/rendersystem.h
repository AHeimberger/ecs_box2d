#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>
#include <entityx/System.h>

class RenderSystem : public entityx::System<RenderSystem>
{
public:
   RenderSystem(sf::RenderTarget& target,
                sf::Texture& texture);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:
   sf::RenderTarget& target;

   sf::Texture& texture;
};

#endif // RENDERSYSTEM_H