#include "Bullet.h"
#include "Math.h"
template<typename Config>
Bullet<Config>::Bullet(Team team, sf::Vector2f dir1, const sf::RectangleShape& sha,  float bul1)
    : m_team(team), m_direction(dir1), m_shape(sha), m_bulletspeed(bul1), m_sprite(m_texture)
{
    if (!m_texture.loadFromFile(Config::Entity::Bullet::BULLET_TEXTURE_PATH))
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
    m_sprite.setTextureRect(Config::Entity::Bullet::BULLET_TEXTURE_RECT);
    m_sprite.setScale(Config::Entity::Bullet
        ::BULLET_SCALE);
    sf::Angle angle= sf::degrees(std::atan2(m_direction.y, m_direction.x) * 180 / 3.14f);
	m_sprite.setRotation(angle);

};
template<typename Config>
void Bullet<Config>::Update(float deltaTime)
{
	m_sprite.setPosition(m_sprite.getPosition() + m_direction * m_bulletspeed*deltaTime);
}
template<typename Config>
void Bullet<Config>::Draw(sf::RenderWindow& window)
{
	/*
	window.draw(m_shape);*/
	
	window.draw(m_sprite);
}


#include "../Settings/Config.h"
template class Bullet<Config>;

