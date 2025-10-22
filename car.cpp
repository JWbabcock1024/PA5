#include "car.h"
/**
 * @brief Construct a new Cherry:: Cherry object
 * 
 */
Cherry::Cherry() 
{
    mTextureTile.loadFromFile("rpg_textures.png");
    mCherryPlant.setRadius(31);
    mCherryPlant.setTexture(&mTextureTile);
    mCherryPlant.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mCherryPlant.setOrigin(62.f / 2.f, 62.f / 2.f);

    mIncrement = sf::Vector2f(4.f, 4.f);

    mPosition.x=0;
    mPosition.y=0;
    mSize.x=0;
    mSize.y = 0;
}
/**
 * @brief Set border for chery to bounce off
 * 
 * @param xPosition x-coordinate of top left position
 * @param yPosition y-coordinate of top left position
 * @param width width of the bondary
 * @param hight hight of the bondary
 */
void Cherry::setBondary(int xPosition, int yPosition, int width, int hight)
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
 * @brief update the chery
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Cherry::update(double elapsedTime, sf::RenderWindow& window)
{
    moveCherry(elapsedTime, window);
}

/**
 * @brief reposition chery on the screen
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Cherry::moveCherry(double elapsedTime, sf::RenderWindow& window)
{
    if (mSize.x == 0 || mSize.y == 0){
        mSize.x = window.getSize().x;
        mSize.y = window.getSize().y;
    }
        
    int cherryX = 62;
    int cherryY = 62;
    double speed = 60;

    if ((mCherryPlant.getPosition().x + (cherryX / 2) > mPosition.x + mSize.x && mIncrement.x > 0) ||
        (mCherryPlant.getPosition().x - (cherryX / 2) < mPosition.x && mIncrement.x < 0))
    {
        // Reverse the direction on X axis
        mIncrement.x = -mIncrement.x;
    }

    if ((mCherryPlant.getPosition().y + (cherryY / 2) > mPosition.y+mSize.y && mIncrement.y > 0) ||
        (mCherryPlant.getPosition().y - (cherryY / 2) < mPosition.y && mIncrement.y < 0))
    {
        // Reverse the direction on Y axis.
        mIncrement.y = -mIncrement.y;
    }

    mCherryPlant.setPosition(
        mCherryPlant.getPosition().x + mIncrement.x*speed*elapsedTime,
        mCherryPlant.getPosition().y + mIncrement.y*speed*elapsedTime);
}

/**
 * @brief Render objects from the scene onto the window
 * 
 * @param window 
 */
void Cherry::render(sf::RenderWindow& window)
{
    window.draw(mCherryPlant);
}