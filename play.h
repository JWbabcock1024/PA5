#ifndef PLAY_H
#define PLAY_H
#include "states.h"
#include "button.h"
#include "car.h"
#include "coin.h"
#include "roadblock.h"

class Play
{
public:
    Play();
    State handleInput(sf::Event& e,  sf::RenderWindow& window);
    void update(double elapsedTime, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    //score
    void setScore(int score){
        mCurrentScore = score; //-A
        mScore.setString("Score: " + std::to_string(mCurrentScore)); //-A
    }
    int getScore() const { return mCurrentScore; }

    //reset game fore play again
    void reset(); //-A

private:
    Car mCar;
    Coin mCoin;
    Roadblock mRoadblock;

   // Button mPlayAgain;  
    Button mRules;
    Button mResults;
    Button mExit;
    Button mPlayAgain; //-A

    //area frame
    sf::RectangleShape mFrame;

    //score display
    sf::Text mScore;
    int mCurrentScore = 0;
    sf::Font mFont;

    //lives and hearts
    int mLives = 3; //-A
    sf::Texture mHeartsTex; //-A
    sf::Sprite mHeartSprites[3]; //-A

    //background
    sf::Texture mBackgroundTex; //-A
    sf::Sprite mBackgroundSprite; //-A
    /*
    * movement by time
    */

    //collision
    bool coinCollected(); //-A
    bool hitRoadblock(); //-A

    bool mGameOver = false; //-A
};

#endif