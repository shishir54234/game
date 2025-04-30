#pragma once

#include <SFML/Graphics.hpp>
class Movement
{
private:
    sf::Vector2f maxVelocity;
    sf::Vector2f acceleration;
    sf::Vector2f deceleration;
    int current = 1;
    sf::Vector2f velocity;
public:
    Movement(sf::Vector2f vel,sf::Vector2f maxvelocity, sf::Vector2f accelaration,
        sf::Vector2f decelaration);
    /*virtual ~Movement();*/
    const sf::Vector2f& getVelocity() const;
    void move(sf::Sprite&player, const float& dt);
    void update(const float& dt);
};

