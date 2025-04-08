#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(
	const Grid &grid,
	const sf::Vector2f& tileSize, 
	const sf::Vector2i& tileScale, const sf::Vector2f&offset)
	: m_grid(grid), m_tileSize(tileSize), m_tileScale(tileScale), 
	m_tile(m_tileSheet), m_offset(offset), m_isMouseOnGrid(false)
{
	
}
MouseTile::~MouseTile()
{
}
void MouseTile::Initialize()
{
	m_tileSheet.loadFromFile("Assets/Map/Prison/tiles/tilesheet.png");
	m_tile.setTexture(m_tileSheet);
	
	m_currentTileID = 11;
	m_tile.setTextureRect(sf::IntRect({ (int)m_currentTileID*(int)m_tileSize.x, 0 }, 
		{ (int)m_tileSize.x, (int)m_tileSize.y }));
	m_tile.setScale((sf::Vector2f)m_tileScale);
	m_tile.setPosition(m_offset);
}
void MouseTile::InitializeFromMapSelector(sf::IntRect rect)
{
	m_tile.setTextureRect(rect);
	m_tile.setScale((sf::Vector2f)m_tileScale);
	m_tile.setPosition(m_offset);
}
void MouseTile::Load()
{
}

void MouseTile::Update(double deltaTime, const sf::Vector2f &mousePosition)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_currentTileID=12; 
		m_tile.setTextureRect(sf::IntRect({ (int)m_currentTileID * (int)m_tileSize.x, 0 },
			{ (int)m_tileSize.x, (int)m_tileSize.y }));
	}
	const sf::Vector2f& gridPosition = m_grid.GetPosition();
	const sf::Vector2f& gridSize = m_grid.GetSize();

	if (mousePosition.x >= gridPosition.x && mousePosition.x < gridPosition.x + gridSize.x &&
		mousePosition.y >= gridPosition.y && mousePosition.y < gridPosition.y + gridSize.y)
	{
		
		
		m_isMouseOnGrid = true;
		//std::cout<<"MousePos" << mousePosition.x << " " << mousePosition.y << std::endl;
		m_tileGridPosition.x = 
			(mousePosition.x - m_offset.x) / (m_tileSize.x * m_tileScale.x);
		m_tileGridPosition.y = 
			(mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);
		
		
	/*	std::cout << "Tile Grid Position " 
		<< m_tileGridPosition.x << " " << m_tileGridPosition.y << std::endl;*/

		m_tilePosition.x
			= m_tileGridPosition.x * (m_tileSize.x * m_tileScale.x) + m_offset.x;
		m_tilePosition.y 
			= m_tileGridPosition.y * (m_tileSize.y * m_tileScale.y) + m_offset.y;

		//std::cout << "Actual Tile Position " << 
		//m_tilePosition.x << " " << m_tilePosition.y << std::endl; 
		m_tile.setPosition(m_tilePosition);
		
	}
	else
	{
		//std::cout << "Not on the grid anymore\n" << std::endl;
		m_isMouseOnGrid = false;
	}

}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}	
/// <summary>
bool MouseTile::IsMouseClickedOnTile(
	sf::Vector2f& tilePosition,
	sf::Vector2i& gridPosition,
	const sf::Vector2f& mousePosition) const
{

	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		const sf::Vector2f& gridSize = m_grid.GetSize();

		if (m_isMouseOnGrid)
		{
			tilePosition = m_tile.getPosition();
			gridPosition = m_tileGridPosition;
			std::cout << "mtile position"
				<< m_tile.getPosition().x << " " << m_tile.getPosition().y << std::endl;
			std::cout << "mtile grid position" <<
				m_tileGridPosition.x << " " << m_tileGridPosition.y << std::endl;
			return true;
		}
	}
	return false;
}












