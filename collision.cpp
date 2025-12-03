#include "collision.h"

/**
 * @brief checks collision
 * 
 * @param a first item
 * @param b second item
 * @return true if intersected
 * @return false if not intersected
 */
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

