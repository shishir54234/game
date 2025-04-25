#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Bullet
{
public:
    sf::Vector2f m_direction;
    sf::RectangleShape m_shape;
    sf::Texture m_texture;
	sf::Sprite m_sprite;
    float m_bulletspeed;
    Bullet(sf::Vector2f dir1, const sf::RectangleShape& sha, float bul1);
    void Update(float );
	void Draw(sf::RenderWindow& );
};