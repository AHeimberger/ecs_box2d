#ifndef BODYSYSTEM_H
#define BODYSYSTEM_H

#include <entityx/System.h>

class BodySystem : public entityx::System<BodySystem>
{
public:
  void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
};

#endif