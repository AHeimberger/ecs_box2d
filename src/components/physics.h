#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>

struct Physics
{
    Physics(b2Body* body, int initial_x, int initial_y) :
        body(body),
        initial_x(initial_x),
        initial_y(initial_y)
    {}

    b2Body* body;
    int initial_x;
    int initial_y;
};

#endif