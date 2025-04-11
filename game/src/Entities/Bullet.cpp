#include "Bullet.h"
void Bullet::Update(float deltaTime)
{
	shape.setPosition(shape.getPosition() + direction * bulletspeed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}


