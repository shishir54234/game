#pragma once
#include "Tiles/Tile.h"
#include "MapLoader.h"
#include "MapData.h"
#include <SFML/Graphics.hpp>


class Map
{
	sf::Texture tileSheetTexture;
	sf::Sprite sprite;
	int totalTiles;
	int totalTilesonWidth; int totalTilesY,totalTilesX;
	std::vector<std::vector<Tile>> tiles;
	

	MapLoader mapLoader;
	MapData md;
	std::vector<sf::Sprite> mapSprites;
	public:
		Map();
		~Map();
	void Initialize(); // <-------- called once
	void Load(std::string filename); // <------ called once per App start
	void Update(double deltaTime);
	void Draw(sf::RenderWindow&);
};

