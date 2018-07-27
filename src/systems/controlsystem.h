#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <entityx/System.h>

class ControlSystem : public entityx::System<ControlSystem>
{
public:
    explicit ControlSystem();

    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
};

#endif