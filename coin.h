//will itermintatlly generate sprites at the top of the screen at random x coordinates that move down the screen at a steady pace and 
//disapear when they reach the bottom. When the players "car" sprite comes in contact with one the score will go up one point.
#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>

class Coin
{
public:
    Coin();

    void updateCoin(double elapsedTime, sf::RenderWindow& window);
    void renderCoin(sf::RenderWindow& window);
    void setBondaryCoin(int xPosition, int yPosition, int width, int hight);

private:

    sf::Texture mTextureTile;
    sf::CircleShape mCoin;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;

    void moveCoin(double elapsedTime, sf::RenderWindow& window);
   
};

#endif