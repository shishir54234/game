#include "Enemy.h"
#include <iostream>
Enemy::Enemy() :playerSprite(playerTexture), healthText(font)
{

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setSize(sf::Vector2f(width, height));
    boundingRectangle.setScale({ scaleX,scaleY });
}
void Enemy::Initialize()
{
    size = sf::Vector2f(85, 94);
}
void Enemy::Load()
{     if (font.openFromFile("Assets/Font/arial.ttf"))
    {
        std::cout << "Arial.ttf font in Assets has been loaded successfully" << std::endl;
        healthText.setFont(font);
        healthText.setCharacterSize(18);
        healthText.setString(std::to_string((int)health));
        healthText.setPosition(playerSprite.getPosition());
    }
    else
    {
        std::cout << "Failed to load Arial.ttf font in Assets" << std::endl;
    }
    //sf::Texture enemyTexture("Assets/Enemy/Texture/mage-1-85x94.png");
    if (!playerTexture.loadFromFile("Assets/Enemy/Texture/mage-1-85x94.png"))
    {
        std::cerr << "Error laoading player texture" << std::endl;
    }
    playerSprite.setTexture(playerTexture);

    float XIndex = 0;
    float YIndex = 0;
    playerSprite.setTextureRect(sf::IntRect({ (int)XIndex * (int)size.x,(int)YIndex * (int)size.y }, { (int)size.x,(int)size.y }));
    playerSprite.setScale({ 3.0f,3.0f });
    playerSprite.setPosition(sf::Vector2f(400, 100));
}

void Enemy::Update(double deltaTime)
{
    if (health > 0) 
    {
        healthText.setPosition(playerSprite.getPosition());
        boundingRectangle.setPosition(playerSprite.getPosition());
    }
    

}

void Enemy::Shoot()
{
}
void Enemy::ChangeHealth(float damage)
{
    health += damage;
    healthText.setString(std::to_string(health));
}
void Enemy::DrawUpdate()
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
    if (health > 0)
    {
        window.draw(playerSprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }
}

