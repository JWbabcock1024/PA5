//will itermintatlly generate sprites at the top of the screen at random x coordinates that move down the screen at a steady pace and 
//disapear when they reach the bottom. When the players "car" sprite comes in contact with one the game will end
#ifndef ROADBLOCK_H
#define ROADBLOCK_H
#include <SFML/Graphics.hpp>
#include "collision.h"

class Roadblock : public Collision
{
public:
    Roadblock();

    void updateRoadblock(double elapsedTime, sf::RenderWindow& window);
    void renderRoadblock(sf::RenderWindow& window);
    void setBondaryRoadblock(int xPosition, int yPosition, int width, int hight);
    bool BarrierCollision(const sf::FloatRect& col);

private:

    sf::Texture mTextureTile;
    sf::CircleShape mRoadblock;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;
    bool touched =false;
    int hitCount=0;

    void moveRoadblock(double elapsedTime, sf::RenderWindow& window);
   
};

#endif