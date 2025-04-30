#pragma once
#include <iostream>
#include "State.h"
#include "../GUI/Button.h"
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>
class MainMenuState: public State
{
private:
    sf::Texture m_texture;
	sf::Sprite m_background;
    sf::Font font;
	sf::Vector2f m_WindowSize;
    std::map<std::string, std::unique_ptr<GUI::Button>> buttons;

    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    MainMenuState(sf::Vector2f &WindowSize,
        std::unique_ptr<std::map<std::string, int>> supportedKeys
        , std::unique_ptr<std::stack< std::unique_ptr<State>>> states);
    void endState();

    void updateInput(const float& dt);
    States updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = NULL);
    void RenderWindow(sf::RenderWindow& window);
};
//void RenderWindow(sf::RenderWindow& window)
