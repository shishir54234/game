#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "MapSaver.h"
#include "MapSelector.h"
#include "GUI/Button.h"
#include "MapData.h"

#include <iostream>


int main()
{
    // ------------------------------------INIT-------------------------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "RPG game", sf::Style::Default);
    float wx = window.getSize().x;
    float wy = window.getSize().y;
    // grid constructor ==> (topleftposition, cellsize, totalCells, scale, color)
    Grid grid1(
        sf::Vector2f(0, 0),
        sf::Vector2i(8, 8),
        sf::Vector2i(44, 10),
        sf::Vector2i(5, 5),
        sf::Color(255, 255, 255, 128),
        2);
	std::cout << "Grid1 Position " << (grid1.GetTopRightBoundary()).x << " "
        << (grid1.GetTopRightBoundary()).y << std::endl;
    Grid grid2(
        grid1.GetBottomLeftBoundary() + sf::Vector2f(0, 50),
        sf::Vector2i(8, 8),
        sf::Vector2i(24, 12),
        sf::Vector2i(6, 4),
        sf::Color(255, 255, 255, 128),
        2);



    // Mouse Tile Constructor ==> grid, tileSize, tileScale, offset
    std::cout << "Grid1 Size " << (grid1.GetSize()).x << " "
        << (grid1.GetSize()).y << std::endl;
    MouseTile mouseTile(
        grid1, 
        sf::Vector2f(8,8),
        grid1.GetScale(),
        grid1.GetPosition());
    
    Map map(grid1,mouseTile);
	MapSelector mapSelector(grid2);
    sf::Vector2f buttonposn = grid2.GetTopRightBoundary() + sf::Vector2f(0, 100);
    Button button(buttonposn, sf::Vector2f(1, 1));
    


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
    button.Load();

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
		button.Update(deltaTime, mousePosition); 
        if (button.IsPressed())
        {
            std::string place = "Assets/Map/prison/tilesheet.png";
           MapData mapData(
               "Assets/Map/prison/tilesheet.png",
                "Level 1",
                grid1.GetPosition().x,
                grid1.GetPosition().y,
                grid1.GetCellSize().x,
                grid1.GetCellSize().y,
                grid1.GetTotalCells().x,
                grid1.GetTotalCells().y,
                grid1.GetScale().x,
                grid1.GetScale().y,
                MAP_SIZE,
                map.GetMapIDs());
           std::vector<int> x = map.GetMapIDs();
           for (auto& y : x)
           {
               std::cout << y << " ";
           }/*
            std::cout << grid1.GetSize().x << std::endl;*/
            mapsaver.Save("TheXFile.rmap", mapData);

            std::cout << "Saved map to file!" << std::endl;
        }
		// -------------------------UPDATE -------------------------------

		// -------------------------DRAW -------------------------------

        window.clear(sf::Color::Black);
        button.Draw(window);
        mapSelector.Draw(window);
        mouseTile.Draw(window);
        grid2.Draw(window);
		grid1.Draw(window);
		
		map.Draw(window);
		

        window.display();

    }
    return 0;
}