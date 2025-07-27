#pragma once
#include "Tiles/Tile.h"
#include "MapLoader.h"
#include "MapData.h"
#include <SFML/Graphics.hpp>
#include "Tiles/Tile.h"
template<typename Config>
class Map
{
	private:
		std::unordered_map<std::string, std::string> metadata;
		std::vector<std::vector<Tile*>> tiles;
		std::vector<std::vector<int>> tileids;
		int totalTilesY, totalTilesX;
		int curViewStartX, curViewStartY;
		int curViewEndX, curViewEndY;
		int gridX = 22, gridY = 9;


	sf::Texture tileSheetTexture;
	
	int totalTiles;
	int totalTilesonWidth; 
	inline bool isCollidable(TileType type) const {
		return type == TileType::WALL || type == TileType::TRAP;
	}
	TileType getTileAt(int x, int y) const {
		if (x < 0 || y < 0 || y >= tiles.size() || x >= tiles[0].size()) {
			return TileType::WALL; // treat out-of-bounds as wall
		}
		return tiles[y][x]->type;
	}

	bool isWalkable(int x, int y) const {
		return !isCollidable(getTileAt(x, y));
	}

	bool isWalkable(sf::Vector2f worldPosition) const {
		int tileX = static_cast<int>(worldPosition.x /totalTilesX);
		int tileY = static_cast<int>(worldPosition.y / totalTilesY);
		return isWalkable(tileX, tileY);
	}
	std::vector<int> tileData;
	MapLoader mapLoader;
	MapData md;
	std::vector<sf::Sprite> mapSprites;
	std::vector<TileType> Tiletypes;
	
	std::string tilesheet;
	std::string mapName;
	std::string dataLength;
	int mapPositionX, mapPositionY;
	int cellSizeX, cellSizeY;
	int mapScaleX, mapScaleY;
	sf::Vector2f WindowSize;
		bool applyMetadata(const std::unordered_map<std::string, std::string>& metadata);
		void parseTileData(const std::string& line);
		
		void ClassifyTheTiles();
		void Gridify();
	public:
		Map(sf::Vector2f wsize, std::string& filename);
		Map(sf::Vector2f wsize);
		~Map();
		
	void Load(); // <-------- called once
	void Initialize(std::string filename= "C:/Users/shahi/source/repos/game/MapEditor/TheXFile.rmap"); // <------ called once per App start
	void Update(double deltaTime);
	void Draw(sf::RenderWindow&);
};

