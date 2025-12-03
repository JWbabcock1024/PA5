//will itermintatlly generate sprites at the top of the screen at random x coordinates that move down the screen at a steady pace and 
//disapear when they reach the bottom. When the players "car" sprite comes in contact with one the game will end
#ifndef ROADBLOCK_H
#define ROADBLOCK_H
#include <SFML/Graphics.hpp>

class Roadblock
{
public:
    Roadblock();

    void updateRoadblock(double elapsedTime, sf::RenderWindow& window);
    void renderRoadblock(sf::RenderWindow& window);
    void setBondaryRoadblock(int xPosition, int yPosition, int width, int hight);
    sf::Vector2f getPosition() const{return mRoadblock.getPosition();} //   -A
    sf::FloatRect getGlobalBounds() const{return mRoadblock.getGlobalBounds();} //  -A
    void resetPosition(); //    -A

private:

    sf::Texture mTextureTile;
    sf::CircleShape mRoadblock;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;

    void moveRoadblock(double elapsedTime, sf::RenderWindow& window);
   
};

#endif