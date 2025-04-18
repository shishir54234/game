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
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, std::unique_ptr<GUI::Button>> buttons;

    //Functions
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    MainMenuState(std::unique_ptr<std::map<std::string, int>> supportedKeys
        , std::unique_ptr<std::stack< std::unique_ptr<State>>> states);
    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = NULL);
    void RenderWindow(sf::RenderWindow& window)
};
//void RenderWindow(sf::RenderWindow& window)
