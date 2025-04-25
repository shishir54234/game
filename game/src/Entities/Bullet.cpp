#include "Bullet.h"
#include "Math.h"
Bullet::Bullet(sf::Vector2f dir1, const sf::RectangleShape& sha, float bul1)
    : m_direction(dir1), m_shape(sha), m_bulletspeed(bul1), m_sprite(m_texture)
{
    if (!m_texture.loadFromFile("Assets/Bullet/Arrow.png"))
    {
        std::cout << "Error loading bullet texture" << std::endl;
        abort();
    }
    else
    {
        std::cout << "Loaded the Bullet succesfully\n"; 
    }
    m_sprite.setTexture(m_texture);

    m_sprite.setPosition(m_shape.getPosition());
    m_sprite.setTextureRect(sf::IntRect({ 0,0 }, { 367,41 }));
    m_sprite.setScale(sf::Vector2f(0.1f, 0.5f));
    sf::Angle angle= sf::degrees(std::atan2(m_direction.y, m_direction.x) * 180 / 3.14f);
	m_sprite.setRotation(angle);

};

void Bullet::Update(float deltaTime)
{
	m_sprite.setPosition(m_sprite.getPosition() + m_direction * m_bulletspeed*deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	/*
	window.draw(m_shape);*/
	
	window.draw(m_sprite);
}


