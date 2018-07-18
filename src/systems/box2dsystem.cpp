#include "systems/box2dsystem.h"

using namespace entityx;

Box2dSystem::Box2dSystem(sf::RenderTarget& target) :
    target(target),
    world(new b2World(b2Vec2(0, 0))),
    unspawned(),
    showDebugDraw(false),
    debugDraw(target)
{
    world->SetGravity(b2Vec2(0.0, 9.8));
    world->SetDebugDraw(&debugDraw);
    debugDraw.SetFlags(b2Draw::e_shapeBit | b2Draw::e_aabbBit);
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

        bodyDef.type = spawn->body_type==BodyType::Dynamic ? b2_dynamicBody : b2_staticBody;
        bodyDef.position.Set(spawn->initial_x, spawn->initial_y);

        polygonShape.SetAsBox(spawn->width, spawn->height);
        fixture.density = 1.0;
        fixture.restitution = 0.3;
        fixture.shape = &polygonShape;
        body = world->CreateBody(&bodyDef);
        body->ResetMassData();

        body->CreateFixture(&fixture);
        body->SetSleepingAllowed(false);

        spawn->body = body;
    }
    unspawned.clear();

    const int32 velocityIterations = 8;
    const int32 positionIterations = 5;
    world->Step(dt, velocityIterations, positionIterations);
    if (showDebugDraw)
        world->DrawDebugData();
}

void Box2dSystem::configure(entityx::EventManager& events)
{
    events.subscribe<entityx::ComponentAddedEvent<Physics>>(*this);
    events.subscribe<ChangeBox2dDebugOutput>(*this);
}

void Box2dSystem::receive(const entityx::ComponentAddedEvent<Physics>& e)
{
    unspawned.push_back(e.entity);
}

void Box2dSystem::receive(const ChangeBox2dDebugOutput& e)
{
    showDebugDraw = e.showBox2dDebug;
}
