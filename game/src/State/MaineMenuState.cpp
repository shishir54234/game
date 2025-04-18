#include "MaineMenuState.h"

void MainMenuState::initFonts()
{

}

void MainMenuState::initKeybinds()
{

}

MainMenuState::MainMenuState(std::unique_ptr<std::map<std::string, int>> supportedKeys
    , std::unique_ptr<std::stack< std::unique_ptr<State>>> states)
    : State(std::move(supportedKeys),std::move(states))
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
    /*
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);*/
}
MainMenuState::~MainMenuState()
{
    
}
void MainMenuState::endState()
{

}