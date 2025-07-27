#include "Movement.h"

Movement::Movement(sf::Vector2f vel, sf::Vector2f maxvelocity, sf::Vector2f accelaration,
	sf::Vector2f decelaration)
{
    this->velocity = vel;
	this->acceleration = accelaration;
	this->deceleration = decelaration;
	this->maxVelocity = maxvelocity;

}
const sf::Vector2f& Movement::getVelocity() const
{
	return velocity;
}

void Movement::update(const float& dt)
{

}
