#include "MainMenuState.h"
#include <fstream>
void MainMenuState::initFonts()
{

}

void MainMenuState::initKeybinds()
{
    /*std::ifstream ifs("Assets/Font/arial.ttf");
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();*/
}
MainMenuState::MainMenuState(sf::Vector2f &WindowSize , std::unique_ptr<std::map<std::string, int>> supportedKeys
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
void MainMenuState::initVariables()
{

}
void MainMenuState::initBackground()
{

}
void MainMenuState::initButtons()
{
}
void MainMenuState::updateInput(const float& dt)
{
}
void MainMenuState::updateButtons()
{
}
void MainMenuState::update(const float& dt)
{
}
void MainMenuState::renderButtons(sf::RenderTarget* target)
{
}
void MainMenuState::RenderWindow(sf::RenderWindow& window)
{
}
void MainMenuState::endState()
{

}