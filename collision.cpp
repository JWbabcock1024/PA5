#include "collision.h"

bool Collision::checkCollision(const sf::FloatRect& a, const sf::FloatRect& b)
{
    if(a.intersects(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

