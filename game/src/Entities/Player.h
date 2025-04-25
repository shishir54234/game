#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "../Components/Movement.h"
#include <SFML/Graphics.hpp>
struct BulletLinkedList
{
	std::unique_ptr<Bullet> bullet;
	BulletLinkedList* next;
	BulletLinkedList(std::unique_ptr<Bullet> b) : bullet(std::move(b)), next(nullptr) {}
	BulletLinkedList(std::unique_ptr<Bullet> b, BulletLinkedList* b1) : bullet(std::move(b)), next(b1) {}
};
class Player: public Entity
{
	BulletLinkedList* bullets= nullptr;
	sf::Texture playerTexture;
	float bulletspeed = 1.0f;

	/*float width = 32;
	float height = 32;

	float scaleX = 3;
	float scaleY = 3;
*/

	Movement* mvmt;
	float playerSpeed = 1.0f;
	float fireRateTimer=0.0f;
	float maxFireRate = 150;
	// Attributes
	void AddBullet(sf::Vector2f dir1, const sf::RectangleShape& sha, float bul1);
	void ManageBullets(double &deltaTime, Enemy& enemy);
public:
	float health = 100;
	sf::Sprite playerSprite;
	Player(sf::Vector2f sz, sf::Vector2f position);
	void Initialize(); // <-------- called once
	void Load(); // <------ called once per App start
	void Shoot( Bullet &);
	void DrawUpdate();
	void Draw(sf::RenderWindow &);
	void Update(double deltaTime, Enemy&);
};

