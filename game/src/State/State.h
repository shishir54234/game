#pragma once
#include <SFML/Graphics.hpp>
#include "../Entities/Entity.h"
#include <iostream>
#include <vector>
#include <map>
class State
{
private: 
	
protected:
	std::unique_ptr<std::map<std::string, int>> supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	std::vector<sf::Texture> textures;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	virtual void initKeybinds() = 0;    
public:
	State(std::unique_ptr<std::map<std::string, int>> supportedKeys,
		std::unique_ptr<std::stack<std::unique_ptr<State>>> states);
	virtual ~State();
	virtual void update(const float& dt) = 0;
	virtual void RenderWindow(sf::RenderWindow& window) =0;
};

