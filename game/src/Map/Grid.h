#pragma once
#include <iostream>
#include "Tiles/Tile.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "TileReader.h"
class Grid
{
public:
	
	std::vector<std::vector<std::unique_ptr<Tile>>> m_tiles;
	sf::Texture m_tileSheetTexture;
	Grid() {
		m_tiles.resize(10);
		for (size_t i = 0; i < m_tiles.size(); i++)
		{
			m_tiles[i].resize(10);
		}
		if (!m_tileSheetTexture.loadFromFile
		("C:/Users/shahi/source/repos/game/game/Assets/Map/Prison/tiles/tilesheet.png"))
		{ 
			std::cout << "I wasnt able to load this \n"; abort();

		}
		else
		{
			std::cout << "Loaded the tilesheet \n";
		}
	}
	void Load(sf::RenderWindow& window)
	{
		sf::Vector2u sz = window.getSize();
		std::cout << "Windows Size: " << sz.x << " " << sz.y << std::endl;
		float mx = float(sz.x) / float(10);
		float my = float(sz.y) / float(10);

		float sx = mx / float(16);
		float sy = my / float(16);
		//std::cout << "Scale factor for x: " << sx << " y: " << sy << std::endl;
		float posx = 0, posy = 0;
		//for (float i = 0; i < m_tiles.size(); i++)
		//{
		//	for (float j = 0; j < m_tiles[i].size(); j++)
		//	{
		//		//std::cout << "Position: " << posx << " " << posy << std::endl;
		//		m_tiles[i][j] = std::make_unique<Tile>();
		//		m_tiles[i][j]->id = i + j;
		//		m_tiles[i][j]->position = sf::Vector2i(i, j);
		//		m_tiles[i][j]->type = TileType::FLOOR;
		//		m_tiles[i][j]->sprite = std::make_unique<sf::Sprite>(m_tileSheetTexture);
		//		m_tiles[i][j]->sprite->setPosition(sf::Vector2f(posx, posy));
		//		m_tiles[i][j]->sprite->setTextureRect(sf::IntRect({ {(int)j * 16, (int)i * 16}, {16, 16} }));
		//		m_tiles[i][j]->sprite->setScale(sf::Vector2f(sx, sy));
		//		posx += mx;

		//		
		//	}
		//	posx = 0;
		//	posy += my;
		//}

	}
	void Draw(sf::RenderWindow& window)
	{
		for (size_t i = 0; i < m_tiles.size(); i++)
		{
			for (size_t j = 0; j < m_tiles[i].size(); j++)
			{
				if (m_tiles[i][j])
				{
					window.draw(*m_tiles[i][j]->sprite);
				}
			}
		}
	}
};

