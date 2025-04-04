#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
class Player
{
	std::vector<Bullet> bullets;
	sf::Texture playerTexture;
	sf::Vector2f size;
	float bulletspeed = 1.0f;
	sf::RectangleShape boundingRectangle;
	float width = 32;
	float height = 32;
	float scaleX = 3;
	float scaleY = 3;
	float playerSpeed = 1.0f;
	float fireRateTimer=0.0f;
	float maxFireRate = 150;
	// Attributes
	
public:
	float health = 100;
	sf::Sprite playerSprite;
	Player();
	void Initialize(); // <-------- called once
	void Load(); // <------ called once per App start
	void Shoot( Bullet &);
	void DrawUpdate();
	void Draw(sf::RenderWindow &);
	void Update(double deltaTime, Enemy&);
	
};

