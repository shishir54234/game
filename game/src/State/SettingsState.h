#pragma once
#ifndef  SETTINGSSTATE_H
#define SETTINGSSTATE_H
#include "State.h"

#include "../GUI/Button.h"
template<typename Config>
class SettingsState : public State<Config>
{
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;
	std::map<std::string, GUI::Button<Config>*> buttons;
	sf::Vector2f m_WindowSize;
	sf::Text* optionsText;
	std::vector<sf::VideoMode> modes;
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initGui();
	void initText();



	public: 
		SettingsState(sf::Vector2f& WindowSize 
			,sf::RenderWindow* window, 
			std::map<std::string, int>* supportedKeys, 
			std::stack<State<Config>*>* states);


		//Acccessors


		//Functions
		States updateButtons();
		void updateInput(const float& dt);
		void updateGui(const float& dt);
		void update(const float& dt);
		void RenderWindow(sf::RenderWindow& window);
		void renderGui(sf::RenderTarget& target);
};
#endif // ! SETTINGSSTATE_H

