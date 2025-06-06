#include "Map.h"
#include <iostream>
#include <fstream>
#include "TileReader.h"
Map::Map(sf::Vector2f wsize, std::string&filename)
{
    if (tileSheetTexture.loadFromFile(filename))
    {
        std::cout << "Loaded succesfully\n"; 
    }

    WindowSize = wsize;
}
Map::Map(sf::Vector2f wsize)
{
	if (tileSheetTexture.loadFromFile("Assets/Map/Prison/tiles/tilesheet.png"))
	{
		std::cout << "Loaded succesfully\n";
	}
	WindowSize = wsize;
}
Map::~Map()
{
	std::cout << "Map Destroyed" << std::endl;
}
// in initalise we get the 
void Map::Load()
{
	std::cout << "Map Initialized" << std::endl;
    // initialise the tile ids
    totalTilesY=std::stoi(metadata["totalCellsY"]), totalTilesX = std::stoi(metadata["totalCellsX"]);
    tileids.resize(totalTilesY, std::vector<int>(totalTilesX));
    tiles.resize(gridY, std::vector<Tile*>(gridX,nullptr));
    int k = 0;
    for (int i = 0; i < totalTilesY; i++)
    {
        for (int j = 0; j < totalTilesX; j++)
        {
            tileids[i][j] = tileData[k++];
        }
    }
    ClassifyTheTiles();
    Gridify();
}
void Map::ClassifyTheTiles()
{
    TileReader tr;
    tr.loadRMap();
    for (int i = 0; i < tileData.size(); i++)
    {
        int x = (tileData[i] % 24);
        int y = (tileData[i]/24);
        Tiletypes.push_back(tr.grid[y][x]);
    }
}
void Map::Gridify()
{
    float posx = 0, posy = 0;
    float RectWidth = (float)WindowSize.x / (float)gridX;
    float RectHeight = (float)WindowSize.y / (float)gridY;
    for (int i = 0; i < gridY;i++)
    {
        for (int j = 0; j < gridX;j++)
        {
            tiles[i][j] = new Tile();
            tiles[i][j]->m_scale = sf::Vector2f(1.0,1.0f);
            tiles[i][j]->m_boundingRectangle = sf::RectangleShape(sf::Vector2f(RectWidth,RectHeight));
            tiles[i][j]->type = Tiletypes[i*24+j];
            tiles[i][j]->id = tileids[i][j];

            int i1 = (tileids[i][j]) / 24;
            int j1 = (tileids[i][j]) % 24;
            tiles[i][j]->sprite = std::make_unique<sf::Sprite>(tileSheetTexture);
            std::cout << " Hey these are the coordinates" << j1 * 16 << " " << i1 * 16 << std::endl;
            tiles[i][j]->sprite->setTextureRect(sf::IntRect({ j1 * 16,i1 * 16 }, {16,16}));
            tiles[i][j]->sprite->setScale(sf::Vector2f(RectWidth/16.0f,RectHeight/16.0f));
            tiles[i][j]->sprite->setPosition(sf::Vector2f(posx,posy));
            
            posx += RectWidth;
        }
        posx = 0;
        posy += RectHeight;
    
    }
    
}
void Map::Initialize(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open map file: " << filename << std::endl;
        return;
    }

    std::string line;
    // Check if the first line is [Map]
    std::getline(file, line);
    if (line != "[Map]") {
        std::cerr << "Invalid map format: missing [Map] header" << std::endl;
        return;
    }

    // Parse metadata
    
    bool dataFlag = false;

    while (std::getline(file, line)) {
        // Start reading tile data
        if (dataFlag) {
            parseTileData(line);
            continue;
        }

        // Check if we're starting the data section
        if (line == "data=") {
            dataFlag = true;
            continue;
        }

        // Parse key=value pairs
        size_t delimPos = line.find('=');
        if (delimPos != std::string::npos) {
            std::string key = line.substr(0, delimPos);
            std::string value = line.substr(delimPos + 1);
            metadata[key] = value;
        }
    }

    // Apply the metadata to our map object
    if (!applyMetadata(metadata)) {
        return;
    }

    // Validate data length
    if (tileData.size() != static_cast<size_t>(totalTilesX * totalTilesY)) {
        std::cerr << "Map data length mismatch. Expected "
            << totalTilesX * totalTilesY << " but got "
            << tileData.size() << std::endl;
        return;
    }

    return;

}
bool Map::applyMetadata(const std::unordered_map<std::string, std::string>& metadata) {
    try {
        // Set defaults or report errors for missing values
        if (metadata.find("version") != metadata.end()) {
            ///version = std::stoi(metadata.at("version"));
        }
        else {
            std::cerr << "Missing 'version' in map data" << std::endl;
            return false;
        }

        if (metadata.find("tilesheet") != metadata.end()) {
            tilesheet = metadata.at("tilesheet");
        }
        else {
            std::cerr << "Missing 'tilesheet' in map data" << std::endl;
            return false;
        }

        // Extract other properties
        mapName = metadata.count("mapName") ? metadata.at("mapName") : "Unnamed Map";
        mapPositionX = metadata.count("mapPositionX") ? std::stoi(metadata.at("mapPositionX")) : 0;
        mapPositionY = metadata.count("mapPositionY") ? std::stoi(metadata.at("mapPositionY")) : 0;

        // Required properties for map sizing
        if (metadata.find("cellSizeX") != metadata.end()) {
            cellSizeX = std::stoi(metadata.at("cellSizeX"));
        }
        else {
            std::cerr << "Missing 'cellSizeX' in map data" << std::endl;
            return false;
        }

        if (metadata.find("cellSizeY") != metadata.end()) {
            cellSizeY = std::stoi(metadata.at("cellSizeY"));
        }
        else {
            std::cerr << "Missing 'cellSizeY' in map data" << std::endl;
            return false;
        }

        if (metadata.find("totalCellsX") != metadata.end()) {
            totalTilesX = std::stoi(metadata.at("totalCellsX"));
        }
        else {
            std::cerr << "Missing 'totalCellsX' in map data" << std::endl;
            return false;
        }

        if (metadata.find("totalCellsY") != metadata.end()) {
            totalTilesY = std::stoi(metadata.at("totalCellsY"));
        }
        else {
            std::cerr << "Missing 'totalCellsY' in map data" << std::endl;
            return false;
        }

        mapScaleX = metadata.count("mapScaleX") ? std::stof(metadata.at("mapScaleX")) : 1.0f;
        mapScaleY = metadata.count("mapScaleY") ? std::stof(metadata.at("mapScaleY")) : 1.0f;

        if (metadata.find("dataLength") != metadata.end()) {
            dataLength = std::stoi(metadata.at("dataLength"));
        }
        else {
            std::cerr << "Missing 'dataLength' in map data" << std::endl;
            return false;
        }

        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing map metadata: " << e.what() << std::endl;
        return false;
    }
}

void Map::parseTileData(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        // Skip empty tokens
        if (token.empty()) {
            continue;
        }

        try {
            int tileId = std::stoi(token);
            tileData.push_back(tileId);
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing tile ID: " << token << " - " << e.what() << std::endl;
        }
    }
}
void Map::Update(double deltaTime)
{
	//std::cout << "Map Updated" << std::endl;



}


void Map::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < gridY; i++)
    {
        for (int j = 0; j < gridX; j++)
        {
            window.draw(*tiles[i][j]->sprite);
        }
    }
}