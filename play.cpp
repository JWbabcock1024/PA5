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
    
    mResults.setPosition(sf::Vector2f(310, 450));
    mResults.setSize(sf::Vector2f(60, 20));
    mResults.setText("Results");
    mResults.setColorTextNormal(sf::Color::Blue);
    std::cout << "t" << std::endl;

    mExit.setText("Exit");
    mExit.setPosition({580, 450});
    mExit.setSize({60, 20});
    mExit.setColorTextNormal(sf::Color::Blue);
    
   
    mScore.setFont(mFont);
    mScore.setCharacterSize(30);
    mScore.setFillColor(sf::Color::Blue);
    mScore.setPosition(sf::Vector2f(550, 10));
    mScore.setString("Score: 0");
    std::cout << "ttt" << std::endl;
}

State Play::handleInput(sf::Event& e,  sf::RenderWindow& window)
{
    if (mRules.handleInput(e, window)){
        return welcome;
    }
    //if (mPlayAgain.handleInput(e, window)){
    //    return game;
    //}
    if (mResults.handleInput(e, window)){
        return results;
    }
    if (mExit.handleInput(e, window)){
        return quit;
    }  
    return game;
}
void Play::update(double elapsedTime, sf::RenderWindow& window)
{
    mCar.update(elapsedTime, window);
    mCoin.updateCoin(elapsedTime, window);
    mRoadblock.updateRoadblock(elapsedTime, window);
    mRules.update();
   // mPlayAgain.update();
    mResults.update();
    mExit.update();
    std::cout << "it loaded" << std::endl;
}
void Play::render(sf::RenderWindow& window)
{
    std::cout << "1" << std::endl;
    window.draw(mFrame);
    std::cout << "2" << std::endl;
    mCar.render(window);
    std::cout << "3" << std::endl;
    mCoin.renderCoin(window);
    std::cout << "4" << std::endl;
    mRoadblock.renderRoadblock(window);
    std::cout << "5" << std::endl;
    window.draw(mRules);
    std::cout << "6" << std::endl;
  //  window.draw(mPlayAgain);
    window.draw(mResults);
    std::cout << "7" << std::endl;
    window.draw(mExit);
    std::cout << "8" << std::endl;
    window.draw(mScore);
    std::cout << "it loaded again" << std::endl;
}
