#include "TileReader.h"
TileType TileReader::tileTypeFromString(const std::string& str) {
    static const std::unordered_map<std::string, TileType> map = {
        {"FLOOR", TileType::FLOOR},
        {"WALL", TileType::WALL},
        {"GATE", TileType::GATE},
        {"BARELL", TileType::BARELL},
        {"BARELLS", TileType::BARELL},
        {"DOOR", TileType::DOOR},
        {"TRAP", TileType::TRAP},
        {"TRAPDOOR", TileType::TRAPDOOR},
        {"TELEPORT", TileType::TELEPORT},
        {"TELEPORTDOOR", TileType::TELEPORTDOOR},
        {"TRAPDOOROPEN", TileType::TRAPDOOROPEN}
    };
    if (map.find(str) == map.end()) 
    {
        std::cout << "Could not find " << str << std::endl;
        return TileType::FLOOR;
    }
    auto it = map.find(str);
    return it->second;
}
void TileReader::loadRMap(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Failed to open .rmap file\n";
        return;
    }
    else
    {
        std::cout << "So we are able to open the rmap file\n";
    }
    grid.resize(WIDTH, std::vector<TileType>(HEIGHT,TileType::FLOOR));
    std::string line;
    std::regex pattern(R"(\[(\w+)\]=\((\d+),(\d+)\)to\((\d+),(\d+)\))");

    while (std::getline(file, line)) {
        std::cout << "HEY\n";
        std::smatch match;
        if (std::regex_match(line, match, pattern)) {

            std::string typeStr = match[1];
            int x1 = std::stoi(match[2]);
            int y1 = std::stoi(match[3]);
            int x2 = std::stoi(match[4]);
            int y2 = std::stoi(match[5]);
            std::cout << "The whole line dissected is: " << typeStr << " "
                << x1 << " " << y1 << " " << x2 << " " << y2 << " "
                << std::endl;
            TileType type = tileTypeFromString(typeStr);
            tileTypeMap[type] = sf::IntRect{ { (y1) * 16, (x1) * 16 }, { ((y2 - y1 + 1)) * 16, (x2 - x1 + 1) * 16} };
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