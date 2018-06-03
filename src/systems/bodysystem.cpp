#include "systems/bodysystem.h"
#include "components/body.h"

void BodySystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) {
    const float fdt = static_cast<float>(dt);
    es.each<Body>([fdt](entityx::Entity entity, Body &body) {
      body.position += body.direction * fdt;
      body.rotation += body.rotationd * fdt;
      body.alpha = std::min(1.0f, body.alpha + fdt);
    });
  };
