#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{

	sf::Texture playerTexture;
	sf::Vector2f size;
	sf::RectangleShape boundingRectangle;
	float width = 85;
	float height = 94;
	float scaleX = 3;
	float scaleY = 3;
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

