#pragma once
#include <SFML/Graphics.hpp>
enum TileType 
{
	FLOOR,
	WALL,
	GATE, 
	BARELL, 
	DOOR,
	TRAP,
	TRAPDOOR,
	TELEPORT,
	TELEPORTDOOR,
	TRAPDOOROPEN
};
struct Tile
{
	int id = -1;
	sf::Vector2i position;
	TileType type;
	std::unique_ptr<sf::Sprite> sprite;
	sf::Vector2f m_position;// Position of the entity
	sf::RectangleShape m_boundingRectangle; // Bounding box for collision detection
	sf::Vector2f m_scale; // Scale of the entity
	sf::Vector2f m_dimension; // Dimension of the entity
	sf::Vector2f m_size; // Size of the entity
};