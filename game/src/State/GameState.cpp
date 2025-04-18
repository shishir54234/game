#include "GameState.h"
GameState::GameState(std::unique_ptr<std::map<std::string, int>> supportedKeys):
	State()
{
	this->initKeybinds();
}
GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Ending Game State\n"; 
}

void GameState::UpdateInput(const float& dt)
{
	
	
}

void GameState::update(const float& dt)
{

}
void GameState::RenderWindow(sf::RenderWindow& window)
{

}