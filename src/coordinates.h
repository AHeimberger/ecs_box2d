#ifndef COORDINATES_H
#define COORDINATES_H

#include <Box2D/Common/b2Math.h>
#include <SFML/System/Vector2.hpp>

sf::Vector2f B2VecToSFVec(const b2Vec2 &vector, bool scaleToPixels = true);
float B2ScaleToSFScale(float scalar);

#endif