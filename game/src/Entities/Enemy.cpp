#include "Enemy.h"
#include <iostream>

template<typename Config>
Enemy<Config>::Enemy(Map<Config> &map) :
playerSprite(playerTexture), 
healthText(font), m_map(map)
{
    m_scale = Config::Entity::Enemy::ENEMY_SCALE;
	m_size = Config::Entity::Enemy::ENEMY_SIZE;



    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setSize(m_size);
    boundingRectangle.setScale(m_scale);
}
template<typename Config>
void Enemy<Config>::Initialize()
{
}

template<typename Config>
void Enemy<Config>::Load()
{     if (font.openFromFile("Assets/Font/arial.ttf"))
    {
        std::cout << "Arial.ttf font in Assets has been loaded successfully" << std::endl;
        healthText.setFont(font);
        healthText.setCharacterSize(Config::Entity::Enemy::CHAR_SIZE);

        healthText.setString(std::to_string((int)health));
        healthText.setPosition(playerSprite.getPosition());
    }
    else
    {
        std::cout 
            << "Failed to load Arial.ttf font in Assets" 
            << std::endl;
    }
    //sf::Texture enemyTexture("Assets/Enemy/Texture/mage-1-85x94.png");
    if (!playerTexture.loadFromFile("Assets/Enemy/Texture/mage-1-85x94.png"))
    {
        std::cerr << "Error laoading player texture" << std::endl;
    }
    playerSprite.setTexture(playerTexture);
   
    float XIndex = 0;
    float YIndex = 0;
    playerSprite.setTextureRect(sf::IntRect({ (int)XIndex * (int)size.x,
        (int)YIndex * (int)size.y }, 
        { (int)m_size.x,(int)m_size.y }));
    playerSprite.setScale(m_scale);
    playerSprite.setPosition(Config::Entity::Enemy::ENEMY_POSITION);
}
template<typename Config>
void Enemy<Config>::Update(double deltaTime)
{
    if (health > 0) 
    {
        healthText.setPosition(playerSprite.getPosition());
        boundingRectangle.setPosition(playerSprite.getPosition());
    }
    

}
template<typename Config>
void Enemy<Config>::Shoot()
{
}
template<typename Config>
void Enemy<Config>::ChangeHealth(float damage)
{
    health += damage;
    healthText.setString(std::to_string(health));
}

template<typename Config>
void Enemy<Config>::DrawUpdate()
{
}
template<typename Config>
void Enemy<Config>::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

#include "../Settings/Config.h"
template class Enemy<Config>;