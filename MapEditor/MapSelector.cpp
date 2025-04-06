#include "MapSelector.h"  
#include <iostream>  
#include <cassert>  

MapSelector::MapSelector(Grid& grid) :
    m_grid(grid)
{
}

MapSelector::~MapSelector()
{
}

void MapSelector::AddTilesToVector()
{
    // we need to get the Tiles from the tilesheet and then we add it
    int width = 16, height = 16;
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            int i = x + y * 10;
         
            
            sf::Sprite sprite(m_tilesheetTexture); // Use the stored texture
            
           
            sprite.setTextureRect(sf::IntRect({ x*width, y*height }, { width, height }));
            sf::Vector2f pos;
            pos.x = m_grid.GetOffset().x + x * m_grid.m_tileSize.x;
            pos.y = m_grid.GetOffset().y + y * m_grid.m_tileSize.y;
            std::cout << pos.x << " " << pos.y << std::endl;
			int g1 = m_grid.GetScale().x; int g2 = m_grid.GetScale().y;
			sprite.setScale(sf::Vector2f(g1,g2)); // Set the scale of the sprite to match the grid scale
            // we need to fit in 
           sprite.setPosition(pos);
            tiles.push_back(( std::make_unique<sf::Sprite>(std::move(sprite)) ));
        }
    }
    if (tiles.empty())
    {
        abort();
    }
}

void MapSelector::Initialize()
{
	m_tilesheetTexture.loadFromFile("Assets/Map/Prison/tiles/tilesheet.png");
}

void MapSelector::Load()
{
    AddTilesToVector(); // we add the tiles to the vector
}

void MapSelector::Update(double deltaTime, const sf::Vector2f& mousePosition)
{
    //// have to add drag drop as well, 
    //// so that we can select the tile and drag it to the map
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    //{
    //    sf::Vector2f tilePosition;
    //    sf::Vector2i gridPosition;
    //    if (ClickedOnSelector(tilePosition, gridPosition, mousePosition))
    //    {
    //        int i = gridPosition.x + gridPosition.y * 10;
    //        assert(i < tiles.size());
    //        m_currentTileID = tiles[i].first;
    //        std::cout << "Current Tile ID " << m_currentTileID << std::endl;
    //    }
    //}
}

bool MapSelector::ClickedOnSelector(sf::Vector2f& tilePosition,
    sf::Vector2i& gridPosition,
    const sf::Vector2f& mousePosition) const
{
    return false;
}

void MapSelector::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < tiles.size(); i++)
    {
        /*if(tiles[i].second!=NULL)*/
            window.draw(*tiles[i].get());
        
    }

}
