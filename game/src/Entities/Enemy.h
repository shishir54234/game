#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Enemy : public Entity
{

	sf::Texture playerTexture;
	sf::Vector2f size;
	sf::RectangleShape boundingRectangle;
	sf::Text healthText;
	sf::Font font;
	// Attributes
	
public:
	float health = 100;
	sf::Sprite playerSprite;
	Enemy();
	void Initialize(); // <-------- called once
	void Load(); // <------ called once per App start
	void Update(double deltaTime);
	void Shoot();
	void ChangeHealth(float );
	void DrawUpdate();
	void Draw(sf::RenderWindow&);
	
};

