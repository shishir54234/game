#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Grid.h"
class MapSelector
{
private:
	Grid& m_grid;
	int m_currentTileID;
	//MouseTile m_mouseTile;
	sf::Vector2f m_offset;
	std::vector<std::unique_ptr<sf::Sprite>> tiles;
	sf::Vector2f m_tilePosition;
	sf::Texture m_tilesheetTexture;

	
public:
	MapSelector(Grid& grid);
	~MapSelector();
	void Initialize();
	void Load();
	void Update(double deltaTime, const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
	void AddTilesToVector();
	bool ClickedOnSelector(
		sf::Vector2f& tilePosition,
		sf::Vector2i& gridPosition,
		const sf::Vector2f& mousePosition) const;
	//inline const std::vector<std::pair<int, sf::Sprite>>& GetTiles() const { return tiles; };
	inline int GetCurrentTileID() const { return m_currentTileID; };

};

