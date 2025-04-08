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
	m_width = width;
	m_height = height;
    for (int y = 0; y < 1; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            int i = x + y * 10;
         
            
            sf::Sprite sprite(m_tilesheetTexture); // Use the stored texture
            
           
            sprite.setTextureRect(sf::IntRect({ x*width, y*height }, { width, height }));
            sf::Vector2f pos;
            
			int g1 = m_grid.GetScale().x; int g2 = m_grid.GetScale().y;
            pos.x = m_grid.GetOffset().x + x * m_grid.m_tileSize.x * (g1);
            pos.y = m_grid.GetOffset().y + y * m_grid.m_tileSize.y * (g2);

            std::cout << "Index " << i << " " << pos.x << " " << pos.y << std::endl;
            sprite.setPosition(pos);
			sprite.setScale(sf::Vector2f(g1/2,g2/2)); // Set the scale of the sprite to match the grid scale
            // we need to fit in 
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

}
sf::IntRect MapSelector::GetClickedRect(
    const sf::Vector2f& mousePosition) const
{
    // only called after Clicked on Selector returns true
    
     int gx = (mousePosition.x - m_grid.GetPosition().x) / (m_grid.GetCellSize().x * m_grid.GetScale().x);
     int gy = (mousePosition.y - m_grid.GetPosition().y) / (m_grid.GetCellSize().y * m_grid.GetScale().y);


     int i = gx + 10 * gy;
     return sf::IntRect({ gx * m_width, gy * m_height }, { m_width, m_height });
    
}
bool MapSelector::ClickedOnSelector(
    const sf::Vector2f& mousePosition) const
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        const sf::Vector2f& gridPosition = m_grid.GetPosition();
        const sf::Vector2f& gridSize = m_grid.GetSize();
        if (mousePosition.x >= gridPosition.x && mousePosition.x < gridPosition.x + gridSize.x &&
            mousePosition.y >= gridPosition.y && mousePosition.y < gridPosition.y + gridSize.y)
        {
			std::cout << "Clicked on selector\n";
            return true;
        }
    }
    
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
