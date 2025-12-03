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
    void setScore(int score) { mScore.setString("Score: " + std::to_string(score)); }
    int getScore() const { return mCurrentScore; }
    bool gameIsOver(){ return gameOver; }

private:
    Car mCar;
    Coin mCoin;
    Roadblock mRoadblock;
   // Button mPlayAgain;  
    Button mRules;
    Button mResultsButton;
    Button mExit;
    sf::RectangleShape mFrame;
    sf::Text mScore;
    int mCurrentScore = 0;
    sf::Font mFont;
    bool gameOver=false;
};

#endif