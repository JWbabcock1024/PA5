/**
 * @file main.cpp
 * @authors  
 * @brief  Main file
 * @version 0.1
 * @date 11/12/2025
 * 
 */

#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
    srand(time(0));  // Seed random number generator
    sf::RenderWindow window(sf::VideoMode(640, 480), "My Game");
    window.setPosition({50,50});
    Game game;
   
    sf::Clock clock; 

    while(window.isOpen())
    {
//std::cout<<"Starting while loop"<<std::endl;
        float dt=clock.restart().asSeconds();
        game.handleInput(window);
        game.update(dt, window);
        game.render(window);
    }

    return 0;
}