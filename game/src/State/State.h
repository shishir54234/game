#pragma once
#include <SFML/Graphics.hpp>
#include "../Entities/Entity.h"
#include <iostream>
#include <vector>
#include <map> 
#include <stack>
enum States
{
	
	MENU=0,
	GAME,
	PAUSE,
	EXIT
};
class State
{
private: 
	
protected:
	
	std::unique_ptr<std::map<std::string, int>> supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	std::vector<sf::Texture> textures;
	sf::Vector2f mousePosScreen;
	sf::Vector2f mousePosWindow;
	sf::Vector2f mousePosView;
	virtual void initKeybinds() = 0;    
public:
	States m_identifyingState;
	State(std::unique_ptr<std::map<std::string, int>> supportedKeys,
		std::unique_ptr<std::stack<std::unique_ptr<State>>> states,  States identifyingState);
	virtual ~State();
	virtual void update(const float& dt) = 0;
	virtual States updateButtons() =0;
	virtual void RenderWindow(sf::RenderWindow& window) =0;
};

