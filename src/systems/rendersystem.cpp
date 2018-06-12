#include "systems/rendersystem.h"
#include "components/body.h"
#include "components/physics.h"
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

    entities.each<Physics, Renderable>([this](entityx::Entity entity, Physics& physics, Renderable& renderable) {
        if (physics.body==nullptr)
        {
            //std::cerr << "Null Body!!!!" << std::endl;
        } else
        {
            auto& position = physics.body->GetPosition();
            renderable->setPosition(position.x, position.y);
            target.draw(*renderable.get());
        }
    });
}
