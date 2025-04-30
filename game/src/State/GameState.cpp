#include "GameState.h"

// Constructor
GameState::GameState(std::unique_ptr<std::map<std::string, int>> supportedKeys,
    std::unique_ptr<std::stack<std::unique_ptr<State>>> states,
    sf::RenderWindow& window)
    : State(std::move(supportedKeys), std::move(states), States::GAME),
    player(sf::Vector2f(32.0f, 32.0f), sf::Vector2f(0, 0)),
    map(sf::Vector2f(1920, 1080)),
    bulletSpeed(0.2f)
{
	
    initializeEntities();
    loadResources(window);
}

// Destructor
GameState::~GameState()
{
}

// Initialize all entities
void GameState::initializeEntities()
{
    enemy.Initialize();
    player.Initialize();
    fr.Initialize();
    map.Initialize();
}

// Load all necessary resources
void GameState::loadResources(sf::RenderWindow& window)
{
    player.Load();
    fr.Load();
    grid.Load(window);
    enemy.Load();
    map.Load();
    tileReader.loadRMap("Assets/Map/Prison/tiles/TileClass.rmap");
}
States GameState::updateButtons()
{
	// Check for button presses and update game state accordingly
    return States::GAME;
}
// Called when exiting the state
void GameState::endState()
{
    // Any cleanup when state ends
}

// Start or restart the game
void GameState::startGame()
{
    // Logic to start the game
}
void GameState::initKeybinds()
{

}
//// Update input handling
//void GameState::UpdateInput(const float& dt)
//{
//    // Handle user inputs (WASD, mouse, etc.)
//}

// Main update loop
void GameState::update(const float& deltaTime)
{
    enemy.Update(deltaTime);
    player.Update(deltaTime, enemy);
    fr.Update(deltaTime);
    map.Update(deltaTime);
    //UpdateInput(dt);
    // Update all entities
}

// Render everything to the window
void GameState::RenderWindow(sf::RenderWindow& window)
{
    grid.Draw(window);
    map.Draw(window);
    // Draw entities and HUD
    player.Draw(window);
	enemy.Draw(window);
    fr.Draw(window);
	
}
