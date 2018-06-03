#ifndef BODY_H
#define BODY_H

#include <SFML/Graphics.hpp>

struct Body
{
  Body(const sf::Vector2f &position, const sf::Vector2f &direction, float rotationd = 0.0)
    : position(position), direction(direction), rotationd(rotationd), alpha(0.0) {}

  sf::Vector2f position;
  sf::Vector2f direction;
  float rotation = 0.0, rotationd, alpha;
};

#endif