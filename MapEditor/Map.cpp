#include "Map.h"
#include <iostream>

Map::Map(const Grid& grid, MouseTile& mouseTile)
	: m_grid(grid), m_mouseTile(mouseTile)
{
	m_mapSprites.resize(MAP_SIZE);
	m_mapids.resize(MAP_SIZE);
}

Map::~Map()
{
}

void Map::Initialize()
{
}


void Map::Load()
{
}
void Map::Update(double deltaTime, const sf::Vector2f& mousePosition)
{
	sf::Vector2f tilePosition;
	sf::Vector2i gridPosition;
	if (m_mouseTile.IsMouseClickedOnTile(tilePosition, gridPosition, mousePosition))
	{
		int i = gridPosition.x + gridPosition.y * m_grid.GetTotalCells().x;
		
		assert(i < MAP_SIZE); 
		auto x = m_mouseTile.GetSprite();
		
		m_mapids[i] = m_mouseTile.GetCurrentTileID();
		(m_mapSprites[i])=std::make_unique<sf::Sprite>(std::move(x));
	}
}



void Map::Draw(sf::RenderWindow& window)
{
	
	for (size_t i = 0; i < m_mapSprites.size(); i++)
	{
		if (m_mapSprites[i])
		{
			/*std::cout << i << std::endl;*/
			window.draw(*m_mapSprites[i].get());
		}
	}
}
