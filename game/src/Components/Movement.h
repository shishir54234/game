#pragma once

#include <SFML/Graphics.hpp>
#include "../Map/Map.h"
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
	template<typename Config>
    void move(sf::Sprite& player, Map<Config>& map, const float& dt) {
        {
            sf::Vector2f position = player.getPosition();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {

                position = (position + sf::Vector2f(velocity.x, 0) * (float)dt);
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
            // how do we check if this position is even possible? we call the check with the map 



            player.setPosition(position);

        }


    
    
    }
    void update(const float& dt);
};


