#include "results.h"
Results::Results()
{
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mResults.setFont(mFont);
    //choose the font size based on button size (I choose half)
    mResults.setCharacterSize(60);
    // //set label
    mResults.setString("Results");

    mRules.setPosition(sf::Vector2f(60, 450));
    mRules.setSize(sf::Vector2f(60, 20));
    mRules.setText("Play Again");
    mRules.setColorTextNormal(sf::Color::Blue);
    
    mPlayAgain.setPosition(sf::Vector2f(320, 450));
    mPlayAgain.setSize(sf::Vector2f(60, 20));
    mPlayAgain.setText("Play Again");
    mPlayAgain.setColorTextNormal(sf::Color::Blue);


    mLeave.setPosition(sf::Vector2f(580, 450));
    mLeave.setSize(sf::Vector2f(60, 20));
    mLeave.setText("Quit");
    mLeave.setColorTextNormal(sf::Color::Blue);

}
State Results::handleInput(sf::Event& e,  sf::RenderWindow& window)
{
    if (mPlayAgain.handleInput(e, window)){
        return game;
    }
    if (mRules.handleInput(e, window)){
        return welcome;
    }
    if (mLeave.handleInput(e, window)){
        return quit;
    }
    return results;
}

void Results::update()
{
    mRules.update();
    mPlayAgain.update();
    mLeave.update();  
}
void Results::render(sf::RenderWindow& window)
{
    window.draw(mResults);
    window.draw(mRules);
    window.draw(mPlayAgain);
    window.draw(mLeave);
}