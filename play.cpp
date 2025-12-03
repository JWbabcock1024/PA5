#include "play.h"
#include <cmath> //-A
#include <iostream> //-A
Play::Play()
{
    //Frame setup
    mFrame.setSize(sf::Vector2f(580, 400));
    mFrame.setPosition(sf::Vector2f(30, 20));
    mFrame.setOutlineThickness(0);
    mFrame.setOutlineColor(sf::Color::White);

    //set boundaries for car, coin, roadblock
    mCar.setBondary(60, 20, 580, 400);
   // mCoin.setBondaryCoin(60, 20, 580, 400);
   // mRoadblock.setBondaryRoadblock(60, 20, 580, 400);

    //**********************Buttons**********************
    mRules.setPosition(sf::Vector2f(60, 450));
    mRules.setSize(sf::Vector2f(60, 20));
    mRules.setText("Rules");
    mRules.setColorTextNormal(sf::Color::Blue);
    
    
    
    mResults.setPosition(sf::Vector2f(310, 450));
    mResults.setSize(sf::Vector2f(60, 20));
    mResults.setText("Results");
    mResults.setColorTextNormal(sf::Color::Blue);
    

    mExit.setText("Exit");
    mExit.setPosition({580, 450});
    mExit.setSize({60, 20});
    mExit.setColorTextNormal(sf::Color::Blue);

    //Play again button -A
    mPlayAgain.setPosition(sf::Vector2f(220, 450));
    mPlayAgain.setSize(sf::Vector2f(120, 30));
    mPlayAgain.setText("Play Again");
    mPlayAgain.setColorTextNormal(sf::Color::Blue);


    //load font
    if (!mFont.loadFromFile("college.ttf")) {
        std::cout << "Error opening font file\n";
        //-A
    }
    
    //score text
    mScore.setFont(mFont);
    mScore.setCharacterSize(30);
    mScore.setFillColor(sf::Color::Blue);
    mScore.setPosition(sf::Vector2f(490, 10));
    mScore.setString("Score: 0");

    //load background   -A
    if (!mBackgroundTex.loadFromFile("road.png")){
        std::cerr << "Failed to load road.png\n";
    } else {
        mBackgroundSprite.setTexture(mBackgroundTex);

        //center background
        sf::FloatRect bgBounds = mBackgroundSprite.getLocalBounds();
        mBackgroundSprite.setOrigin(bgBounds.width /2.f, bgBounds.height / 2.f);
        mBackgroundSprite.setPosition(mFrame.getPosition().x + mFrame.getSize().x /2.f,
                                      mFrame.getPosition().y + mFrame.getSize().y / 2.f);
        

    }

    //load hearts -A
    if(!mHeartsTex.loadFromFile("hearts.png")){
        std::cerr << "Failed to load hearts.png\n";
    } else {
        for(int i = 0; i < 3; ++i){
            mHeartSprites[i].setTexture(mHeartsTex);
            sf::FloatRect hb = mHeartSprites[i].getLocalBounds();
            mHeartSprites[i].setOrigin(hb.width / 2.f, hb.height / 2.f);
            mHeartSprites[i].setScale(1.f/7.f, 1.f/7.f);
            float spacing = hb.width * 0.15f;
            float hx = mFrame.getPosition().x + mFrame.getSize().x - 150.f -i * spacing;
            float hy = mFrame.getPosition().y + 18.f;
            mHeartSprites[i].setPosition(hx, hy);
        }
    }

    //center play again button  -A
    mPlayAgain.setPosition(sf::Vector2f(mFrame.getPosition().x + mFrame.getSize().x /2.f,
                                        mFrame.getPosition().y + mFrame.getSize().y / 2.f + 60.f));
    
    //initialize lives and score    -A
    mLives = 3;
    mCurrentScore = 0;
    mGameOver = false;

}

State Play::handleInput(sf::Event& e,  sf::RenderWindow& window)
{
    if (mGameOver){ //-A
        //check play again
        if (mPlayAgain.handleInput(e, window)){
            reset(); //-A
            return game;
        }
        //check exit
        if (mExit.handleInput(e, window)){
            return quit;
        }  
        //check score
        if (mResults.handleInput(e, window)){
            return results;
        }
       
        return game;
    }

    if (mRules.handleInput(e, window)){
        return welcome;
    }
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
    if(!mGameOver){ //-A
        mCar.update(elapsedTime, window);
        mCoin.updateCoin(elapsedTime, window);
        mRoadblock.updateRoadblock(elapsedTime, window);

        //update buttons
        mRules.update();
    // mPlayAgain.update();
        mResults.update();
        mExit.update();

        if(coinCollected()){ //-A
            mCurrentScore += 1;
            mScore.setString("Score: " + std::to_string(mCurrentScore));
            // Coin respawn handled by Coin::resetPosition()
        }

        if(hitRoadblock()){ //-A
            mLives = std::max(0, mLives - 1);
            // Roadblock respawn handled by Roadblock::resetPosition()
            if (mLives <= 0){
                mGameOver = true;

                //display results here
            }

        }
    } else {
        mPlayAgain.update();
        mExit.update();
        mResults.update();

    }
}


void Play::render(sf::RenderWindow& window)
{
    window.draw(mFrame);

    //draw background road in frame -A
    if(mBackgroundTex.getSize().x > 0){
        window.draw(mBackgroundSprite);
    }

    mCar.render(window);
    mCoin.renderCoin(window);
    mRoadblock.renderRoadblock(window);


    window.draw(mRules);
  //  window.draw(mPlayAgain);
    window.draw(mResults);
    window.draw(mExit);
    window.draw(mScore);

    //draw updated hearts   -A
    for(int i = 0; i < mLives && i < 3; ++i){
        window.draw(mHeartSprites[i]);
    }

    if (mGameOver) {
        //translucent overlay over frame
        sf::RectangleShape overlay;
        overlay.setSize(mFrame.getSize());
        overlay.setPosition(mFrame.getPosition());
        overlay.setFillColor(sf::Color(0, 0, 0, 160));
        window.draw(overlay);

        //game over
        sf::Text go;
        go.setFont(mFont);
        go.setCharacterSize(40);
        go.setFillColor(sf::Color::Red);
        go.setString("GAME OVER");
        sf::FloatRect gb = go.getLocalBounds();
        go.setOrigin(gb.width / 2.f, gb.height / 2.f);
        go.setPosition(mFrame.getPosition().x + mFrame.getSize().x / 2.f,
                       mFrame.getPosition().y + mFrame.getSize().y / 2.f - 40.f);
        window.draw(go);

        //final score
        sf::Text finalScore;
        finalScore.setFont(mFont);
        finalScore.setCharacterSize(24);
        finalScore.setFillColor(sf::Color::White);
        finalScore.setString("Final Score: " + std::to_string(mCurrentScore));
        sf::FloatRect fsb = finalScore.getLocalBounds();
        finalScore.setOrigin(fsb.width / 2.f, fsb.height / 2.f);
        finalScore.setPosition(mFrame.getPosition().x + mFrame.getSize().x / 2.f,
                               mFrame.getPosition().y + mFrame.getSize().y / 2.f);
        window.draw(finalScore);

        //draw Play Again & Exit buttons
        window.draw(mPlayAgain);
        window.draw(mExit);
        //Results button
        window.draw(mResults);
    }
}

//-A
bool Play::coinCollected(){
    sf::FloatRect carBounds = mCar.getGlobalBounds();
    sf::FloatRect coinBounds = mCoin.getGlobalBounds();
    if (carBounds.intersects(coinBounds)) {
        // use Coin::resetPosition if available
        mCoin.resetPosition();
        return true;
    }
    return false;
}

//-A
bool Play::hitRoadblock(){
    sf::FloatRect carBounds = mCar.getGlobalBounds();
    sf::FloatRect rbBounds = mRoadblock.getGlobalBounds();
    if (carBounds.intersects(rbBounds)) {
        mRoadblock.resetPosition();
        return true;
    }
    return false;
}

//-A
void Play::reset(){
    mLives = 3;
    mCurrentScore = 0;
    mScore.setString("Score: 0");
    mGameOver = false;

    //reposition car, coin, roadblock
    mCar.setBondary(60, 20, 580, 400);
    mCoin.setBondaryCoin(60, 20, 580, 400);
    mRoadblock.setBondaryRoadblock(60, 20, 580, 400);
}