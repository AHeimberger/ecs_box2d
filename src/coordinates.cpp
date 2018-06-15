#include "coordinates.h"

namespace sfdd
{
	const float SCALE = 1.f; // 32.f;
}

/// Convert Box2D's vector to SFML vector [Default - scales the vector up by SCALE constants amount]
 sf::Vector2f B2VecToSFVec(const b2Vec2 &vector, bool scaleToPixels)
{
	return sf::Vector2f(vector.x * (scaleToPixels ? sfdd::SCALE : 1.f), vector.y * (scaleToPixels ? sfdd::SCALE : 1.f));
}

float B2ScaleToSFScale(float scalar)
{
    return scalar * sfdd::SCALE;
}
