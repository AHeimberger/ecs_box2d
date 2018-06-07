#include "systems/rendersystem.h"
#include "components/body.h"
#include "components/renderable.h"
#include <stdio.h>

using namespace entityx;

RenderSystem::RenderSystem(sf::RenderTarget& target) :
    target(target)
{
}

void RenderSystem::update(EntityManager &entities,
                          EventManager &events,
                          double dt)
{
    entities.each<Body, Renderable>([this](entityx::Entity entity, Body& body, Renderable& renderable) {
        renderable->setPosition(body.position);
        target.draw(*renderable.get());
    });
}
