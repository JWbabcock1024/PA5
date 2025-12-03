#include "play.h"
Play::Play()
{
    if (!mFont.loadFromFile("college.ttf")) {
        std::cout << "Error opening font file\n";
        exit(2);
    }

    mFrame.setSize(sf::Vector2f(580, 400));
    mFrame.setPosition(sf::Vector2f(30, 20));
    mFrame.setOutlineThickness(0);
    mFrame.setOutlineColor(sf::Color::White);

    mCar.setBondary(60, 20, 580, 400);
    mCoin.setBondaryCoin(60, 20, 580, 400);
    mRoadblock.setBondaryRoadblock(60, 20, 580, 400);

    mRules.setPosition(sf::Vector2f(60, 450));
    mRules.setSize(sf::Vector2f(60, 20));
    mRules.setText("Rules");
    mRules.setColorTextNormal(sf::Color::Blue);
    
    /*
    mPlayAgain.setPosition(sf::Vector2f(220, 450));
    mPlayAgain.setSize(sf::Vector2f(60, 20));
    mPlayAgain.setText("PlayAgain");
    mPlayAgain.setColorTextNormal(sf::Color::Blue);
    */
    
    mResultsButton.setPosition(sf::Vector2f(310, 450));
    mResultsButton.setSize(sf::Vector2f(60, 20));
    mResultsButton.setText("Results");
    mResultsButton.setColorTextNormal(sf::Color::Blue);

    mExit.setText("Exit");
    mExit.setPosition({580, 450});
    mExit.setSize({60, 20});
    mExit.setColorTextNormal(sf::Color::Blue);
    
   
    mScore.setFont(mFont);
    mScore.setCharacterSize(30);
    mScore.setFillColor(sf::Color::Blue);
    //mScore.setPosition(sf::Vector2f(550, 10));
    mScore.setPosition(sf::Vector2f(500, 10));
    mScore.setString("score: 0");
}

State Play::handleInput(sf::Event& e,  sf::RenderWindow& window)
{
    if (mRules.handleInput(e, window)){
        return welcome;
    }
    //if (mPlayAgain.handleInput(e, window)){
    //    return game;
    //}
    if (mResultsButton.handleInput(e, window)){
        return results;
    }
    if (mExit.handleInput(e, window)){
        return quit;
    }  
    return game;
}
void Play::update(double elapsedTime, sf::RenderWindow& window)
{
    if(!gameOver)
    {
        mCar.update(elapsedTime, window);
        mCoin.updateCoin(elapsedTime, window);
        mRoadblock.updateRoadblock(elapsedTime, window);
        if(mRoadblock.BarrierCollision(mCar.getBounds()))
        {
            gameOver = true;
        }
        mCurrentScore = (mCoin.CoinCollision(mCar.getBounds())); // returns the amount of coins collided with / collected
        setScore(mCurrentScore);
    }
    mRules.update();
   // mPlayAgain.update();
    mResultsButton.update();
    mExit.update();
}
void Play::render(sf::RenderWindow& window)
{
    window.draw(mFrame);
    mCar.render(window);
    mCoin.renderCoin(window);
    mRoadblock.renderRoadblock(window);
    window.draw(mRules);
  //  window.draw(mPlayAgain);
    window.draw(mResultsButton);
    window.draw(mExit);
    window.draw(mScore);
}
