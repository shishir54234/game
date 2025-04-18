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
	static std::unordered_map<TileType, sf::IntRect> tileTypeMap;
    static TileType tileTypeFromString(const std::string& str) {
        static const std::unordered_map<std::string, TileType> map = {
            {"FLOOR", TileType::FLOOR},
            {"WALL", TileType::WALL},
            {"GATE", TileType::GATE},
            {"BARELL", TileType::BARELL},
            {"DOOR", TileType::DOOR},
            {"TRAP", TileType::TRAP},
            {"TRAPDOOR", TileType::TRAPDOOR},
            {"TELEPORT", TileType::TELEPORT},
            {"TELEPORTDOOR", TileType::TELEPORTDOOR},
            {"TRAPDOOROPEN", TileType::TRAPDOOROPEN}
        };

        auto it = map.find(str);
        return it->second;
    }

    // Grid to store tile types
    static const int WIDTH = 12, HEIGHT = 24;
    static TileType grid[WIDTH][HEIGHT];

    static void loadRMap(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open .rmap file\n";
            return;
        }

        std::string line;
        std::regex pattern(R"(\[(\w+)\]\s+\((\d+),(\d+)\)\s+to\s+\((\d+),(\d+)\))");

        while (std::getline(file, line)) {
            std::smatch match;
            if (std::regex_match(line, match, pattern)) {

                std::string typeStr = match[1];
                int x1 = std::stoi(match[2]);
                int y1 = std::stoi(match[3]);
                int x2 = std::stoi(match[4]);
                int y2 = std::stoi(match[5]);
				std::cout << "The whole line dissected is: " << typeStr<<" "
					<< x1 << " " << y1 << " " << x2 << " " << y2 << " "
                    << std::endl;
                TileType type = tileTypeFromString(typeStr);
                tileTypeMap[type] = sf::IntRect{{ (y1)*16, (x1)*16 }, { ((y2-y1+1))*16, (x2-x1+1)*16}};
                for (int x = x1; x <= x2; ++x) {
                    for (int y = y1; y <= y2; ++y) {
                        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
							grid[x][y] = type; // we classify the tile type
                        }
                    }
                }
            }
        }
    }
};

