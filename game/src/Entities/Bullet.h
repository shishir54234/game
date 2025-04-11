#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Bullet : public Entity
{
public:
    sf::Vector2f direction;
    sf::RectangleShape shape;
    float bulletspeed;
    Bullet(sf::Vector2f dir1, sf::RectangleShape sha, float bul1) :direction(dir1), shape(sha), bulletspeed(bul1) {};
    void Update(float );
	void Draw(sf::RenderWindow& );
};