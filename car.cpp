#include "car.h"
/**
 * @brief Construct a new Car:: Car object
 * 
 */
Car::Car() 
{
    mTextureTile.loadFromFile("rpg_textures.png");
    mCar.setRadius(31);
    mCar.setTexture(&mTextureTile);
    mCar.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mCar.setOrigin(62.f / 2.f, 62.f / 2.f);
    

    mIncrement = sf::Vector2f(4.f, 4.f);

    mPosition.x=0;
    mPosition.y=0;
    mSize.x = 0;
    mSize.y = 0;

    sf::Vector2u defaultWindowSize(800, 600);
    mCar.setPosition(defaultWindowSize.x / 2.f, defaultWindowSize.y / 2.f);
    
}
/**
 * @brief set car bodarys * 
 * @param xPosition x-coordinate of top left position
 * @param yPosition y-coordinate of top left position
 * @param width width of the bondary
 * @param hight hight of the bondary
 */
void Car::setBondary(int xPosition, int yPosition, int width, int hight)
{
    if (xPosition > 0)
        mPosition.x=xPosition;
    if (yPosition > 0)
        mPosition.y=yPosition;
    if (width > 0)
        mSize.x=width;
    if (hight > 0)
        mSize.y = hight;
}

/**
 * @brief update the car
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Car::update(double elapsedTime, sf::RenderWindow& window)
{
    moveCar(elapsedTime, window);
}

/**
 * @brief reposition car on the screen
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Car::moveCar(double elapsedTime, sf::RenderWindow& window)
{
    if (mSize.x == 0 || mSize.y == 0) {
        mSize.x = window.getSize().x;
        mSize.y = window.getSize().y;
    }
    double speed = 120.0;
    sf::Vector2f position = mCar.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position.x -= speed * elapsedTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position.x += speed * elapsedTime;
    }

    int carWidth = 62;
    if (position.x < mPosition.x)
        position.x = mPosition.x;
    if (position.x + carWidth > mPosition.x + mSize.x)
        position.x = mPosition.x + mSize.x - carWidth;

    mCar.setPosition(position.x, position.y);
}


/**
 * @brief Render objects from the scene onto the window
 * 
 * @param window 
 */
void Car::render(sf::RenderWindow& window)
{
    window.draw(mCar);
}