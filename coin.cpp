//will itermintatlly generate sprites at the top of the screen at random x coordinates that move down the screen at a steady pace and 
//disapear when they reach the bottom. When the players "car" sprite comes in contact with one the score will go up one point.

#include "coin.h"
/**
 * @brief Construct a new Car:: Car object
 * 
 */
Coin::Coin() 
{
    float r = 31.f;
    mTextureTile.loadFromFile("coin.png");
    mCoin.setRadius(r);
    mCoin.setTexture(&mTextureTile);
    //mCoin.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mCoin.setOrigin(r,r);
    

    mIncrement = sf::Vector2f(4.f, 4.f);

    mPosition.x=0;
    mPosition.y=0;
    mSize.x = 0;
    mSize.y = 0;

    sf::Vector2u defaultWindowSize(800, 600);
    mCoin.setPosition(defaultWindowSize.x / 2.f, defaultWindowSize.y - 10.f);
    
}
/**
 * @brief set car bodarys * 
 * @param xPosition x-coordinate of top left position
 * @param yPosition y-coordinate of top left position
 * @param width width of the bondary
 * @param hight hight of the bondary
 */
void Coin::setBondaryCoin(int xPosition, int yPosition, int width, int hight)
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
    float startY = mPosition.y + mCoin.getRadius() + 5.f;
    mCoin.setPosition(startX, startY);
}

/**
 * @brief update the car
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Coin::updateCoin(double elapsedTime, sf::RenderWindow& window)
{
    moveCoin(elapsedTime, window);
}

/**
 * @brief reposition car on the screen
 * 
 * @param elapsedTime time since last update
 * @param window 
 */
void Coin::moveCoin(double elapsedTime, sf::RenderWindow& window)
{
    if (mSize.x == 0 || mSize.y == 0) {
        mSize.x = window.getSize().x;
        mSize.y = window.getSize().y;
    }
    double speed = 120.0;
    sf::Vector2f position = mCoin.getPosition();

    
    position.y += static_cast<float>(speed * elapsedTime);

    
    float diameter = mCoin.getRadius() * 2.f;
    if (position.x - mCoin.getRadius() < mPosition.x)
        position.x = mPosition.x + mCoin.getRadius();
    if (position.x + mCoin.getRadius() > mPosition.x + mSize.x)
        position.x = mPosition.x + mSize.x - mCoin.getRadius();

    
    if (position.y - mCoin.getRadius() > mPosition.y + mSize.y) {
        position.y = mPosition.y + mCoin.getRadius() + 2.f;
        collected=false;
        if (mSize.x > diameter) {
            int randX = mPosition.x + (std::rand() % (mSize.x - static_cast<int>(diameter)));
            position.x = static_cast<float>(randX) + mCoin.getRadius();
        } else {
            position.x = mPosition.x + mCoin.getRadius();
        }
    }

    mCoin.setPosition(position);
}


/**
 * @brief Render objects from the scene onto the window
 * 
 * @param window 
 */
void Coin::renderCoin(sf::RenderWindow& window)
{
    window.draw(mCoin);
}

int Coin::CoinCollision(const sf::FloatRect& col)
{
   // mCar.getGlobalBounds(mCar.getBounds(),mCoin.getBounds())

    if (!collected && checkCollision(mCoin.getGlobalBounds(), col))
    {
        tempScore++;
        //std::cout << "score" << tempScore << std::endl;
        collected = true;
    }
    
    return tempScore;
}
