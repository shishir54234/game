#include "Map.h"
#include <iostream>

Map::Map() : sprite(tileSheetTexture)
{
}
Map::~Map()
{
	std::cout << "Map Destroyed" << std::endl;
}
void Map::Initialize()
{
	std::cout << "Map Initialized" << std::endl;
}

void Map::Load(std::string filename)
{
 //   mapLoader.Load(filename, md);
	//mapSprites.resize(md.dataLength,sprite);

 //   if (!md.tilesheet.empty() && md.tilesheet.front() == '"' && md.tilesheet.back() == '"') {
 //       md.tilesheet = md.tilesheet.substr(1, md.tilesheet.size() - 2);
 //   }
 //   std::string fullPath = std::filesystem::absolute(md.tilesheet).string();
 //   std::cout << "Resolved absolute path: " << fullPath << std::endl;
 //   
 //   if (!tileSheetTexture.loadFromFile(fullPath))
 //   {
 //       std::cout << "ERROR: Could not load tilesheet.png" << std::endl;
 //       // Optionally, you might want to throw an exception or handle the error
 //   }
	//
 //    std::cout << "TileSheet Loaded Successfully" << std::endl;
 //    std::cout << "Texture Size: " << tileSheetTexture.getSize().x << " x " << tileSheetTexture.getSize().y << std::endl;
 //    sprite.setTexture(tileSheetTexture);
 //    sprite.setPosition(sf::Vector2f(100, 100));
 //    sprite.setScale({ 3.0f,3.0f });
 //    totalTilesonWidth
	//	 = tileSheetTexture.getSize().x / md.tileWidth;
 //    assert(totalTilesonWidth > 0);
 //    
	// totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;
	// totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
 //    sprite.setTextureRect(sf::IntRect({ 0, 0 },
	//	 { md.tileWidth, md.tileHeight }));
 //    tiles.resize(totalTilesX, std::vector<Tile>(totalTilesY));
	// // Adding the differnt tiles to the sprites array
	// for (int y = 0; y < totalTilesY; y++)
	// {
	//	 for (int x = 0; x < totalTilesX; x++)
	//	 {


	//		 tiles[x][y].id = (x+(totalTilesX)*y);
	//		 tiles[x][y].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);
	//	 }
	// }
	// for (int i = 0; i < mapSprites.size(); i++)
 //    {
 //            int index = md.data[i];
 //            int x = i % 3; int y = i / 3;
	//		 int i1 = index % totalTilesonWidth;
	//		 int i2 = index / totalTilesonWidth;
 //            mapSprites[i].setTexture(tileSheetTexture);

 //            mapSprites[i].setTextureRect(sf::IntRect({ 
 //                tiles[i1][i2].position.x,tiles[i1][i2].position.y}, {md.tileWidth,md.tileHeight}));
 //           
 //            mapSprites[i].setScale(sf::Vector2f(5, 5));
 //            mapSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * 5, 100 + y * md.tileHeight * 5));
 //    
 //    }

}

void Map::Update(double deltaTime)
{
	//std::cout << "Map Updated" << std::endl;
}


void Map::Draw(sf::RenderWindow& window)
{
    // Additional debug information
   /**/

    /*window.draw(sprite);*/
    for (size_t i = 0; i < mapSprites.size(); i++)
        window.draw(mapSprites[i]);
}