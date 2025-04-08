#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "MapSaver.h"
#include "MapSelector.h"
#include <iostream>


int main()
{
    // ------------------------------------INIT-------------------------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "RPG game", sf::Style::Default);
    // grid constructor ==> (topleftposition, cellsize, totalCells, scale, color)
    Grid grid1(
        sf::Vector2f(0, 0),
        sf::Vector2i(8, 8),
        sf::Vector2i(10, 5),
        sf::Vector2i(10, 10),
        sf::Color(255, 255, 255, 128),
        2);
	std::cout << "Grid1 Position " << (grid1.GetTopRightBoundary()).x << " "
        << (grid1.GetTopRightBoundary()).y << std::endl;
    Grid grid2(
        grid1.GetTopRightBoundary() + sf::Vector2f(50,0),
        sf::Vector2i(8, 8),
        sf::Vector2i(10, 5),
        sf::Vector2i(10, 10),
        sf::Color(255, 255, 255, 128),
        2);



    // Mouse Tile Constructor ==> grid, tileSize, tileScale, offset
    MouseTile mouseTile(
        grid1, 
        grid1.GetSize(),
        grid1.GetScale(),
        grid1.GetOffset());
    
    Map map(grid1,mouseTile);
	MapSelector mapSelector(grid2);

    MapSaver mapsaver;
    // ------------------------------------INIT-------------------------------------------------
    grid1.Initialize();
    grid2.Initialize();
    mouseTile.Initialize();
	map.Initialize();
	mapSelector.Initialize();





  
    //  ------------------------------------LOAD--------------
    grid1.Load();
	grid2.Load();
	mapSelector.Load();
    /*
    mouseTile.Load();*/
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
        if (mapSelector.ClickedOnSelector(mousePosition))
        {
			sf::IntRect rect = mapSelector.GetClickedRect(mousePosition);
            mouseTile.InitializeFromMapSelector(rect);
            std::cout << "Initialised this\n"; 
        }
        
        
	    mouseTile.Update(deltaTime, mousePosition);
        map.Update(deltaTime, mousePosition);
        grid1.Update(deltaTime);
		grid2.Update(deltaTime);
		// -------------------------UPDATE -------------------------------

		// -------------------------DRAW -------------------------------

        window.clear(sf::Color::Black);
        mapSelector.Draw(window);
        grid2.Draw(window);
		grid1.Draw(window);
		mouseTile.Draw(window);
		map.Draw(window);
		

        window.display();

    }
    return 0;
}