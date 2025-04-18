#pragma once
#include "../Entities/Entity.h"
#include "State.h"
class GameState: public State
{
private:
	std::unique_ptr<Entity> player;
public: 
	GameState(std::unique_ptr<std::map<std::string, int>> supportedKeys);
	virtual ~GameState();
	void endState();

	void UpdateInput(const float& dt);
	void update(const float& dt);
	void RenderWindow(sf::RenderWindow& window);
};

