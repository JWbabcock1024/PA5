#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Collision
{
public:
    bool checkCollision(const sf::FloatRect& a, const sf::FloatRect& b);
private:
};


#endif