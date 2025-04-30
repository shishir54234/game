#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include <iostream>


int main()
{
    // ------------------------------------INIT-------------------------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({1920,1080}), "RPG game",sf::Style::Default);
	//window.setVerticalSyncEnabled(true);
	GameState gameState(std::make_unique<std::map<std::string, int>>(), 
        std::make_unique<std::stack<std::unique_ptr<State>>>(), window);
	sf::Vector2f WindowSize = sf::Vector2f((float)window.getSize().x, (float)window.getSize().y );
	MainMenuState mainMenuState(WindowSize,
        std::make_unique<std::map<std::string, int>>(), 
        std::make_unique<std::stack<std::unique_ptr<State>>>());
	StateManager stateManager(gameState, mainMenuState);
	stateManager.Run(window);
}