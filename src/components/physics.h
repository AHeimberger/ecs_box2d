#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>

enum class BodyType { Dynamic, Static };

struct Physics
{
    Physics(b2Body* body, float initial_x, float initial_y, float width, float height, BodyType body_type) :
        body(body),
        initial_x(initial_x),
        initial_y(initial_y),
        width(width),
        height(height),
        body_type(body_type)
    {}

    b2Body* body;
    float initial_x;
    float initial_y;
    float width;
    float height;
    BodyType body_type;
};

#endif