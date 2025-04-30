#pragma once
#include "State/MainMenuState.h"
#include "State/GameState.h"
class StateManager
{
	GameState& gameState;
	MainMenuState& mainMenuState;
	State* currentState;
public:
	StateManager(GameState& gameState, MainMenuState& mainMenuState)
		: gameState(gameState), mainMenuState(mainMenuState) 
	{
		currentState = &mainMenuState;
	}
	void handleInput(const std::string& input) {
		
	}
	void update(const float &dataRate) 
	{
		currentState->update(dataRate);
	}
	void Run(sf::RenderWindow& window)
	{
		sf::Clock clock;
		while (window.isOpen())
		{
			sf::Event event();
			sf::Time deltaTimeTimer = clock.restart();
			double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
			while (const std::optional event = window.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
					window.close();

			}
			currentState->update(deltaTime);
			if (currentState->updateButtons() == States::GAME and currentState->m_identifyingState != States::GAME)
			{
				currentState = &gameState;
			}
			else if (currentState->updateButtons() == States::MENU and currentState->m_identifyingState != States::MENU)
			{
				currentState = &mainMenuState;
			}

			window.clear();
			currentState->RenderWindow(window);
			window.display();
		}
	}
	void render() {
		/*
		gameState.render();
		mainMenuState.render();*/
	}
	void Draw(sf::RenderWindow& window) {
		currentState->RenderWindow(window);
	}
};

