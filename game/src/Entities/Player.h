#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "../Components/Movement.h"
#include "../Map/Map.h"
#include <SFML/Graphics.hpp>
template<typename Config>
class Player : public Entity
{
	sf::Texture playerTexture;
	float bulletspeed = 1.0f;
	Map<Config>& m_map;
	
	Movement* mvmt;
	float playerSpeed = Config::Entity::Player::PLAYER_SPEED.x;
	float fireRateTimer=0.0f;
	float maxFireRate = 150;
	// Attributes
	Bullet<Config>*AddBullet(sf::Vector2f dir1, 
		const sf::RectangleShape& sha, float bul1);
	void ManageBullets(double &deltaTime);
public:
	float health = 100;
	sf::Sprite playerSprite;
	Player(sf::Vector2f sz, sf::Vector2f position, Map<Config> &map);
	void Initialize(); // <-------- called once
	void Load(); // <------ called once per App start
	Bullet<Config>* Shoot( double );
	void DrawUpdate();
	void Draw(sf::RenderWindow &);
	void Update(double deltaTime);
};

