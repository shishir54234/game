#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
private:
	std::vector<sf::RectangleShape> m_hLine;
	std::vector<sf::RectangleShape> m_vLine;
	sf::Vector2f m_position;
	sf::Vector2i m_scale;
	sf::Vector2i m_tileSize;
	sf::Vector2i m_tileAmount;
	sf::Vector2i m_totalLines;
	int m_lineThickness;


	sf::Vector2f m_size;

	sf::Color m_color;
public:
	Grid(const sf::Vector2f&position, 
		const sf::Vector2i&cellSize,
		const sf::Vector2i& totalCells, 
		const sf::Vector2i& scale, 
		const sf::Color &color,
		int lineThinkness);
	~Grid();
	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow &window);


	inline const sf::Vector2f& GetPosition() const { return m_position; }
	inline const sf::Vector2f& GetSize() const { return m_size; }
	inline const sf::Vector2i& GetScale() const { return m_scale; }

	inline const sf::Vector2i& GetTotalCells() const { return m_tileAmount; }
	inline const sf::Vector2f& GetCellSize() const { return m_size; }
};

