
#include "GameState.h"
#include "../Settings/Config.h"
// Constructor
template<typename Config>
GameState<Config>::GameState(
    std::map<std::string, int>* supportedKeys,
    std::stack<State<Config>*>* states,
    sf::RenderWindow& window)
    : State<Config>(std::move(supportedKeys), 
        std::move(states), States::GAME),
    map(sf::Vector2f(1920, 1080)),
    player(sf::Vector2f(32.0f, 32.0f), sf::Vector2f(0, 0),map),
    bulletSpeed(0.2f),
    enemy(map),
	entityManager(map)
{
    initializeEntities();
    loadResources(window);
}

// Destructor
template<typename Config>
GameState<Config>::~GameState()
{// Cleanup if necessary
	// Note: EntityManager handles the cleanup of entities
	// so we don't need to delete player and enemy explicitly.
	
}

// Initialize all entities
template<typename Config>
void GameState<Config>::initializeEntities()
{
    enemy.Initialize();
    player.Initialize();
    fr.Initialize();
    map.Initialize();
}

// Load all necessary resources
template<typename Config>
void GameState<Config>::loadResources(sf::RenderWindow& window)
{
    fr.Load();
    grid.Load(window);
    enemy.Load();
    map.Load();
    tileReader.loadRMap("Assets/Map/Prison/tiles/TileClass.rmap");
    player.Load();
	
	entityManager.add(&player);
	entityManager.add(&enemy);
    

}
template<typename Config>
States GameState<Config>::updateButtons()
{
	// Check for button presses and update game state accordingly
    return States::GAME;
}
// Called when exiting the state
template<typename Config>
void GameState<Config>::endState()
{
    // Any cleanup when state ends
}

// Start or restart the game
template<typename Config>
void GameState<Config>::startGame()
{
    // Logic to start the game
}
template<typename Config>
void GameState<Config>::initKeybinds()
{

}
//// Update input handling
//void GameState::UpdateInput(const float& dt)
//{
//    // Handle user inputs (WASD, mouse, etc.)
//}
// Main update loop
template<typename Config>
void GameState<Config>::update(const float& deltaTime)
{

    fr.Update(deltaTime);
    map.Update(deltaTime);
	entityManager.update(deltaTime);
    //UpdateInput(dt);
    // Update all entities
}

// Render everything to the window
template<typename Config>
void GameState<Config>::RenderWindow(sf::RenderWindow& window)
{
    grid.Draw(window);
    map.Draw(window);
    fr.Draw(window);
    // Draw entities and HUD
	entityManager.RenderWindow(window);
	// Draw any additional UI elements
}


template class GameState<Config>;