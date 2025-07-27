#pragma once
#include "../Managers/EntityManager.h"
#include "../Entities/Entity.h"
#include "../Entities/Player.h"
#include "../Entities/Enemy.h"
#include "../Components/FrameRate.h"
#include "../Map/Map.h"
#include "../Map/TileReader.h"
#include "../Map/Grid.h"
#include "State.h"


template<typename Config>
class GameState : public State < Config >
{
private:
    // Core game objects
    Player<Config> player;
    Enemy<Config> enemy;
    FrameRate fr;
    Grid grid;
    Map<Config> map;
    TileReader tileReader;
	EntityManager<Config> entityManager;
    // Other variables
    float bulletSpeed;

    // Initialization functions
    void initializeEntities(); // done 
    void loadResources(sf::RenderWindow& window); // done

public:
    GameState(
        std::map<std::string,int>* supportedKeys,
        std::stack<State<Config>*>* states,
        sf::RenderWindow& window);
    ~GameState();

    void endState(); // done
    void startGame(); // done
	void initKeybinds();
    //void UpdateInput(const float& dt) override;
    States updateButtons();
    void update(const float& dt); // done
    void RenderWindow(sf::RenderWindow& window);// done
};
