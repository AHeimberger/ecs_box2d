#include "systems/controlsystem.h"
#include "components/control.h"
#include "components/physics.h"
#include <SFML/Window.hpp>

using namespace entityx;

ControlSystem::ControlSystem()
{
}

void ControlSystem::update(EntityManager &entities,
                         EventManager &events,
                         double dt)
{
    entities.each<Control, Physics>([this](Entity entity, Control& control, Physics& physics) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            physics.body->ApplyLinearImpulseToCenter(b2Vec2(0.0, -control.upthrust), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            physics.body->ApplyLinearImpulseToCenter(b2Vec2(-control.sidethrust, 0.0), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            physics.body->ApplyLinearImpulseToCenter(b2Vec2(control.sidethrust, 0.0), true);
        }
    });
}