#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "Components/FrameRate.h"
#include "Map/Map.h"
#include "Map/Grid.h"
#include "Map/TileReader.h"
#include <iostream>


int main()
{
    // ------------------------------------INIT-------------------------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({1920,1080}), "RPG game",sf::Style::Default);
    // ------------------------------------INIT-------------------------------------------------
    Enemy enemy;
    Player player(32.0f,32.0f);
    FrameRate fr;
    Map map;
	TileReader tileReader;
    //MapLoader mapLoader;
    
    Grid grid;

	
    enemy.Initialize();
    player.Initialize();
    fr.Initialize();
    map.Initialize();
    //  ------------------------------------LOAD--------------
    player.Load();
    fr.Load();
    grid.Load(window);
    enemy.Load();
    map.Load("Assets/Map/Prison/tiles/level1.rmap");
    tileReader.loadRMap("Assets/Map/Prison/tiles/TileClass.rmap");
    // ------------------------------------ENEMY-----------------------------------------------
    
    1
    

    // -------------------------------------HERO--------------------------------------------------------------
    
    // ------------------------------------BULLETS-----------------------------------------------
    // -------------------------------------Calculate direction of the bullet --------------------------------
    /*sf::Vector2f direction = enemy.playerSprite.getPosition() - bullet.getPosition();
    direction = NormalizeVector(direction);*/
    float bulletspeed = 0.2;
    

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
        //------------------------- UPDATE -------------------------------

        sf::Event event();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            
        }
        enemy.Update(deltaTime);
        player.Update(deltaTime,enemy);
		fr.Update(deltaTime);
        map.Update(deltaTime);


        window.clear(sf::Color::Green);
        
        grid.Draw(window);
        map.Draw(window);
		fr.Draw(window);
        player.Draw(window);
        enemy.Draw(window);
        
        window.display();

    }
}