#pragma once
#include <SFML/Graphics.hpp>
#include "State/GameState.h"
#include "State/MainMenuState.h"
#include "StateManager.h"
#include "Settings/Config.h"

template<typename Config>
void run() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), 
        "RPG game", sf::Style::Default, sf::State::Fullscreen);

    std::map<std::string, int> supportedKeys, supportedKeysMainMenuState;
    std::stack<State<Config>*> states, statesmainMenuState;

    GameState<Config> gameState(&supportedKeys, &states, window);
    sf::Vector2f WindowSize((float)window.getSize().x, (float)window.getSize().y);
    MainMenuState<Config> mainMenuState(WindowSize, &supportedKeysMainMenuState, &statesmainMenuState);

    StateManager<Config> stateManager(gameState, mainMenuState);
    stateManager.Run(window);
}
