#include "Grid.h"
#include "MouseTile.h"
#include <iostream>

Grid::Grid(const sf::Vector2f& position
	, const sf::Vector2i& cellSize
	, const sf::Vector2i& totalCells,
	const sf::Vector2i& scale, 
	const sf::Color &color,
	int lineThickness)
	: m_position(position), m_tileSize(cellSize), 
	m_tileAmount(totalCells), m_scale(scale), 
	m_color(color), m_lineThickness(lineThickness)
{
	m_totalLines = sf::Vector2i(m_tileAmount.x + 1, m_tileAmount.y + 1);
	
	m_vLine.resize(m_totalLines.x);
	m_hLine.resize(m_totalLines.y);
	m_size = sf::Vector2f
	((m_tileAmount.x * m_tileSize.x * m_scale.x) + m_lineThickness
		, m_tileAmount.y * m_tileSize.y * m_scale.y);
}

Grid::~Grid()
{
	m_hLine.clear();
	m_vLine.clear();
}

void Grid::Initialize()
{
	
	for (size_t i = 0; i < m_totalLines.x; i++)
	{
		m_vLine[i].setSize(sf::Vector2f(m_lineThickness, m_size.y));
		m_vLine[i].setFillColor(m_color);
		m_vLine[i].setPosition(m_position + sf::Vector2f(i * m_tileSize.x * m_scale.x, 0));
	}
	for (size_t i = 0; i < m_totalLines.y; i++)
	{
		m_hLine[i].setSize(sf::Vector2f(m_size.x, m_lineThickness));
		m_hLine[i].setFillColor(m_color);
		m_hLine[i].setPosition(m_position + sf::Vector2f(0, i * m_tileSize.y * m_scale.y));
	}
}


void Grid::Load()
{

}

void Grid::Update(double deltaTime)
{
}


void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_totalLines.y; i++)
		window.draw(m_hLine[i]);

	for (size_t i = 0; i < m_totalLines.x; i++)
		window.draw(m_vLine[i]);
}



