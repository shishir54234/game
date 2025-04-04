#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "FrameRate.h"
#include "Map.h"
#include <iostream>


int main()
{
    // ------------------------------------INIT-------------------------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({1920,1080}), "RPG game",sf::Style::Default);
    // ------------------------------------INIT-------------------------------------------------
    Enemy enemy;
    Player player;
    FrameRate fr;
    Map map;
    
    //MapLoader mapLoader;
    


    enemy.Initialize();
    player.Initialize();
    fr.Initialize();
    map.Initialize();
    //  ------------------------------------LOAD--------------
    player.Load();
    fr.Load();
    enemy.Load();
    map.Load("Assets/Map/Prison/tiles/level1.rmap");
    // ------------------------------------ENEMY-----------------------------------------------
    
    
    

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
        map.Draw(window);
		fr.Draw(window);
        player.Draw(window);
        enemy.Draw(window);
        window.display();

    }
}