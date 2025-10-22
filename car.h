#ifndef CHERRY_H
#define CHERRY_H
#include <SFML/Graphics.hpp>

class Cherry
{
public:
    Cherry();

    void update(double elapsedTime, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setBondary(int xPosition, int yPosition, int width, int hight);

private:

    sf::Texture mTextureTile;
    sf::CircleShape mCherryPlant;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;

    void moveCherry(double elapsedTime, sf::RenderWindow& window);
   
};
#endif