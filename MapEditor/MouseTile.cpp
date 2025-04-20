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
	if(m_tileSheet.loadFromFile("Assets/Map/Prison/tiles/tilesheet.png"))
	{
		std::cout << "Loaded succe\n";
		
	}
	else 
	{
		abort();
	}
	m_tile.setTexture(m_tileSheet);
	// 11 the default number
	m_currentTileID = 11;
	m_tile.setTextureRect(sf::IntRect({ (int)m_currentTileID*(int)m_tileSize.x, 0 }, 
		{ (int)m_tileSize.x, (int)m_tileSize.y }));
	m_tile.setScale((sf::Vector2f)m_tileScale);
	m_tile.setPosition(m_offset);
}

// we get the new images bounds in that rect
void MouseTile::InitializeFromMapSelector(sf::IntRect rect)
{
	
	sf::Vector2i pos = rect.position;
	float x = (pos.x) / (rect.size.x);
	float y = (pos.y) / (rect.size.y);
	m_currentTileID = 24 * y + x;
	
	m_tile.setTextureRect(rect);
	sf::Vector2f newSize = sf::Vector2f(m_tileScale.x/2,m_tileScale.y/2);
	m_tile.setScale(newSize);
	m_tile.setPosition(m_offset);
}
void MouseTile::Load()
{
}

void MouseTile::Update(double deltaTime, const sf::Vector2f &mousePosition)
{
	const sf::Vector2f& gridPosition = m_grid.GetPosition();
	const sf::Vector2f& gridSize = m_grid.GetSize();

	if (mousePosition.x >= gridPosition.x && mousePosition.x < gridPosition.x + gridSize.x &&
		mousePosition.y >= gridPosition.y && mousePosition.y < gridPosition.y + gridSize.y)
	{
		
		
		m_isMouseOnGrid = true;
		m_tileGridPosition.x = 
			(mousePosition.x - m_offset.x) / (m_tileSize.x * m_tileScale.x);
		m_tileGridPosition.y = 
			(mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);
		m_tilePosition.x
			= m_tileGridPosition.x * (m_tileSize.x * m_tileScale.x) + m_offset.x;
		m_tilePosition.y 
			= m_tileGridPosition.y * (m_tileSize.y * m_tileScale.y) + m_offset.y;
		m_tile.setPosition(m_tilePosition);
		
	}
	else
	{
		/*std::cout << "Not on the grid anymore\n" << std::endl;*/
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
			/*std::cout << "mtile position"
				<< m_tile.getPosition().x << " " << m_tile.getPosition().y << std::endl;
			std::cout << "mtile grid position" <<
				m_tileGridPosition.x << " " << m_tileGridPosition.y << std::endl;*/
			return true;
		}
	}
	return false;
}












