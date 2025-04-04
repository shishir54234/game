#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
class MapSelector
{
private:
	sf::Texture m_tilesheet;
	sf::Sprite m_tile;
	int m_currentTileID;
	sf::Vector2i m_tileSize;
	sf::Vector2f m_tileScale;
	sf::Vector2f m_offset;
	std::vector<std::pair<int, sf::Sprite>> tiles;
	sf::Vector2f m_tilePosition;
public:
	MapSelector(const sf::Vector2i& tileSize, const sf::Vector2f& tileScale, const sf::Vector2f& offset);
	~MapSelector();
	void Initialize();
	void Load();
	void Update(double deltaTime, const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
	bool ClickedOnSelector(
		sf::Vector2f& tilePosition,
		sf::Vector2i& gridPosition,
		const sf::Vector2f& mousePosition) const;
	inline const std::vector<std::pair<int, sf::Sprite>>& GetTiles() const { return tiles; };
	inline int GetCurrentTileID() const { return m_currentTileID; };

};

