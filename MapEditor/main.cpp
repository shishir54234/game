#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "MapSaver.h"

#include <iostream>


int main()
{
    // ------------------------------------INIT-------------------------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "RPG game", sf::Style::Default);
    Grid grid(
        sf::Vector2f(100, 50),
        sf::Vector2i(16, 16),
        sf::Vector2i(10, 5),
        sf::Vector2i(10, 10),
        sf::Color(255, 255, 255, 128),
        2);

    MouseTile mouseTile(grid, sf::Vector2i(16, 16), 
        sf::Vector2f(10, 10),
        sf::Vector2f(100,50));
    
    Map map(grid,mouseTile);

    MapSaver mapsaver;
    // ------------------------------------INIT-------------------------------------------------
    grid.Initialize();
    mouseTile.Initialize();
	map.Initialize();
    //MapLoader mapLoader;





  
    //  ------------------------------------LOAD--------------
    grid.Load();
    mouseTile.Load();
    map.Load();

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
            /*if (event->is<sf::Event::MouseLeft>())
            {
                std::cout << "Event handled\n";
                 sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
                 
            }*/
        }
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        
        
		mouseTile.Update(deltaTime, mousePosition);
        map.Update(deltaTime, mousePosition);
        grid.Update(deltaTime);

		// -------------------------UPDATE -------------------------------

		// -------------------------DRAW -------------------------------

        window.clear(sf::Color::Black);
		grid.Draw(window);
		mouseTile.Draw(window);
		map.Draw(window);
        window.display();

    }
    return 0;
}