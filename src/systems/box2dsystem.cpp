#include "systems/box2dsystem.h"

using namespace entityx;

Box2dSystem::Box2dSystem() :
    world(new b2World(b2Vec2(0, 0)))
{
    world->SetGravity(b2Vec2(0.0, 9.8));
}

void Box2dSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events,
                         double dt)
{
    for (entityx::Entity e : unspawned)
    {
        auto spawn = e.component<Physics>();

        b2Body* body;
        b2BodyDef bodyDef;
        b2FixtureDef fixture;
        b2PolygonShape polygonShape;

        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(200, 0);

        polygonShape.SetAsBox(16, 16);
        fixture.density = 1.0;
        fixture.restitution = 0.3;
        fixture.shape = &polygonShape;
        body = world->CreateBody(&bodyDef);

        body->CreateFixture(&fixture);
        body->SetSleepingAllowed(false);

        spawn->body = body;
    }
    unspawned.clear();

    const int32 velocityIterations = 8;
    const int32 positionIterations = 5;
    world->Step(dt, velocityIterations, positionIterations);
}

void Box2dSystem::configure(entityx::EventManager& events)
{
    events.subscribe<entityx::ComponentAddedEvent<Physics>>(*this);
}

void Box2dSystem::receive(const entityx::ComponentAddedEvent<Physics>& e)
{
    unspawned.push_back(e.entity);
}
