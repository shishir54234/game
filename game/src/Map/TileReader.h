#pragma once
#include "SFML/Graphics.hpp"
#include "Tiles/Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <regex>
class TileReader
{
public:
	std::unordered_map<TileType, sf::IntRect> tileTypeMap;
    TileType tileTypeFromString(const std::string& str );

    // Grid to store tile types
    const int WIDTH = 12, HEIGHT = 24;
    std::vector<std::vector<TileType>> grid;
    void loadRMap(const std::string& filename = "C:/Users/shahi/source/repos/game/game/Assets/Map/Prison/tiles/TileClass.rmap");
};

