#ifndef BOX2DSYSTEM_H
#define BOX2DSYSTEM_H

#include "components/physics.h"
#include <entityx/System.h>
#include <Box2D/Box2D.h>
#include <list>
#include <memory>

class Box2dSystem : public entityx::System<Box2dSystem>, public entityx::Receiver<Box2dSystem>
{
public:
    explicit Box2dSystem();

    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);

    void configure(entityx::EventManager& events) override;
    void receive(const entityx::ComponentAddedEvent<Physics>& e);

private:
    std::unique_ptr<b2World> world;
    std::list<entityx::Entity> unspawned;
};

#endif