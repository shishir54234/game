#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

#include "../Map/Map.h"


template<typename Config>
class Enemy : public Entity
{
	Map<Config>& m_map;
	sf::Texture playerTexture;
	sf::Vector2f size;
	sf::RectangleShape boundingRectangle;
	sf::Text healthText;
	sf::Font font;
	// Attributes
	
public:
	float health = Config::Entity::Enemy::ENEMY_HEALTH;
	sf::Sprite playerSprite;
	Enemy(Map<Config> &map);
	void Initialize(); // <-------- called once
	void Load(); // <------ called once per App start
	void Update(double deltaTime);
	void Shoot();
	void ChangeHealth(float );
	void DrawUpdate();
	void Draw(sf::RenderWindow&);
	
};

