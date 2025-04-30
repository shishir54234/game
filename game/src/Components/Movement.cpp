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
void Movement::move(sf::Sprite&player, const float& dt)
{
	sf::Vector2f position = player.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        
        position=(position + sf::Vector2f(velocity.x, 0) * (float)dt);
        int new_current = 1;
        if (new_current != current)
        {
            player.setScale(sf::Vector2f(-player.getScale().x, player.getScale().y));
            current = new_current;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        
        position = (position + sf::Vector2f(-velocity.x, 0) * (float)dt);
        int new_current = -1;
        if (new_current != current)
        {
            player.setScale(sf::Vector2f(-player.getScale().x, player.getScale().y));
            current = new_current;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        position = (position + sf::Vector2f(0, -velocity.y) * (float)dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        position = (position + sf::Vector2f(0, velocity.y) * (float)dt);
    }
    player.setPosition(position);

}
void Movement::update(const float& dt)
{

}
