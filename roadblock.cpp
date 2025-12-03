//will itermintatlly generate sprites at the top of the screen at random x coordinates that move down the screen at a steady pace and 
//disapear when they reach the bottom. When the players "car" sprite comes in contact with one the game will end
#include "roadblock.h"
/**
 * @brief Construct a new Car:: Car object
 * 
 */
Roadblock::Roadblock() 
{
    mTextureTile.loadFromFile("roadblock.png");
    mRoadblock.setRadius(45);
    mRoadblock.setTexture(&mTextureTile);
    //mRoadblock.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mRoadblock.setOrigin(45,45);
    

    mIncrement = sf::Vector2f(4.f, 4.f);

    mPosition.x=0;
    mPosition.y=0;
    mSize.x = 0;
    mSize.y = 0;

    sf::Vector2u defaultWindowSize(800, 600);
    mRoadblock.setPosition(defaultWindowSize.x / 2.f, defaultWindowSize.y - 10.f);
    
}
/**
 * @brief set car bodarys * 
 * @param xPosition x-coordinate of top left position
 * @param yPosition y-coordinate of top left position
 * @param width width of the bondary
 * @param hight hight of the bondary
 */
void Roadblock::setBondaryRoadblock(int xPosition, int yPosition, int width, int hight)
{
    if (xPosition > 0)
        mPosition.x=xPosition;
    if (yPosition > 0)
        mPosition.y=yPosition;
    if (width > 0)
        mSize.x=width;
    if (hight > 0)
        mSize.y = hight;

    
    float startX = mPosition.x + (mSize.x > 0 ? mSize.x / 2.f : 0.f);
    float startY = mPosition.y + mRoadblock.getRadius() + 5.f;
    mRoadblock.setPosition(startX, startY);
}

/**
 * @brief update the car
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Roadblock::updateRoadblock(double elapsedTime, sf::RenderWindow& window)
{
    moveRoadblock(elapsedTime, window);
}

/**
 * @brief reposition car on the screen
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Roadblock::moveRoadblock(double elapsedTime, sf::RenderWindow& window)
{
    if (mSize.x == 0 || mSize.y == 0) {
        mSize.x = window.getSize().x;
        mSize.y = window.getSize().y;
    }
    double speed = 120.0;
    sf::Vector2f position = mRoadblock.getPosition();

    
    position.y += static_cast<float>(speed * elapsedTime);

    
    float diameter = mRoadblock.getRadius() * 2.f;
    if (position.x - mRoadblock.getRadius() < mPosition.x)
        position.x = mPosition.x + mRoadblock.getRadius();
    if (position.x + mRoadblock.getRadius() > mPosition.x + mSize.x)
        position.x = mPosition.x + mSize.x - mRoadblock.getRadius();

    
    if (position.y - mRoadblock.getRadius() > mPosition.y + mSize.y) {
        position.y = mPosition.y + mRoadblock.getRadius() + 2.f;
        if (mSize.x > diameter) {
            int randX = mPosition.x + (std::rand() % (mSize.x - static_cast<int>(diameter)));
            position.x = static_cast<float>(randX) + mRoadblock.getRadius();
        } else {
            position.x = mPosition.x + mRoadblock.getRadius();
        }
    }

    mRoadblock.setPosition(position);
}


/**
 * @brief Render objects from the scene onto the window
 * 
 * @param window 
 */
void Roadblock::renderRoadblock(sf::RenderWindow& window)
{
    window.draw(mRoadblock);
}

void Roadblock::resetPosition(){ // -A
    float startY = mPosition.y + mRoadblock.getRadius() + 2.f;
    if (mSize.x > 0) {
        int randX = mPosition.x + (std::rand() % (mSize.x - (int)(mRoadblock.getRadius()*2)));
        mRoadblock.setPosition(randX + mRoadblock.getRadius(), startY);
    } else {
        mRoadblock.setPosition(mPosition.x + mRoadblock.getRadius(), startY);
    }
}