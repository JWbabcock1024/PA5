#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>

class Car
{
public:
    Car();

    void update(double elapsedTime, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setBondary(int xPosition, int yPosition, int width, int hight);
    sf::Vector2f getPosition() const{return mCar.getPosition();}    //   -A
    sf::FloatRect getGlobalBounds() const {return mCar.getGlobalBounds();} //   -A

private:

    sf::Texture mTextureTile;
    sf::CircleShape mCar;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;

    void moveCar(double elapsedTime, sf::RenderWindow& window);
   
};
#endif