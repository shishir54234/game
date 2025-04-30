#pragma once

#include "../Entities/Entity.h"
#include "../Entities/Player.h"
#include "../Entities/Enemy.h"
#include "../Components/FrameRate.h"
#include "../Map/Map.h"
#include "../Map/TileReader.h"
#include "../Map/Grid.h"
#include "State.h"

class GameState : public State
{
private:
    // Core game objects
    Player player;
    Enemy enemy;
    FrameRate fr;
    Grid grid;
    Map map;
    TileReader tileReader;

    // Other variables
    float bulletSpeed;

    // Initialization functions
    void initializeEntities(); // done 
    void loadResources(sf::RenderWindow& window); // done

public:
    GameState(std::unique_ptr<std::map<std::string, int>> supportedKeys,
        std::unique_ptr<std::stack<std::unique_ptr<State>>> states,
        sf::RenderWindow& window);
    virtual ~GameState();

    void endState(); // done
    void startGame(); // done
	void initKeybinds() override;
    //void UpdateInput(const float& dt) override;
    States updateButtons();
    void update(const float& dt) override; // done
    void RenderWindow(sf::RenderWindow& window) override;// done
};
