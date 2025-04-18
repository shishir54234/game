#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Grid.h"
#define MAP_SIZE 600


class Map
{
private:
	const Grid& m_grid;
	MouseTile &m_mouseTile;
	std::vector<std::unique_ptr<sf::Sprite>> m_mapSprites;
	std::vector<int> m_mapids;
public:
	Map(const Grid& grid, MouseTile &mouseTile);
	~Map();
	void Initialize();
	void Load();
	void Update(double deltaTime, const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);

	inline const std::vector<int> GetMapIDs() const { return m_mapids;  };
};

