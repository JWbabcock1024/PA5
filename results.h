#ifndef RESULTS_H
#define RESULTS_H

#include "button.h"
#include "states.h"
class Results
{
public:
    Results();
    State handleInput(sf::Event& e, sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
    void score(); //

    void setScore(int score) { mScore.setString("Score: " + std::to_string(score)); }

private:
    sf::Text mResults;
    sf::Text mScore;
    Button mRules;
   // Button mPlayAgain;
    Button mLeave;
    sf::Font mFont;
};

#endif