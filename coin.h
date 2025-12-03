//will itermintatlly generate sprites at the top of the screen at random x coordinates that move down the screen at a steady pace and 
//disapear when they reach the bottom. When the players "car" sprite comes in contact with one the score will go up one point.
#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include "collision.h"

class Coin : public Collision
{
public:
    Coin();

    void updateCoin(double elapsedTime, sf::RenderWindow& window);
    void renderCoin(sf::RenderWindow& window);
    void setBondaryCoin(int xPosition, int yPosition, int width, int hight);
    int CoinCollision(const sf::FloatRect& col);

private:

    sf::Texture mTextureTile;
    sf::CircleShape mCoin;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;
    bool collected=false;
    int tempScore=0;

    void moveCoin(double elapsedTime, sf::RenderWindow& window);
   
};

#endif