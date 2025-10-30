#ifndef PLAY_H
#define PLAY_H
#include "states.h"
#include "button.h"
#include "car.h"

class Play
{
public:
    Play();
    State handleInput(sf::Event& e,  sf::RenderWindow& window);
    void update(double elapsedTime, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);


private:
    Car mCar;
   // Button mPlayAgain;  
    Button mRules;
    Button mResults;
    Button mExit;
    sf::RectangleShape mFrame;
};

#endif