#pragma once  
#include <SFML/Graphics.hpp>  
#include "Entity.h"  
#include "Team.h"  

template<typename Config = void> // Provide a default template argument  
class Bullet  
{  
public:  
   sf::Vector2f m_direction;  
   sf::RectangleShape m_shape;  
   sf::Texture m_texture;  
   sf::Sprite m_sprite;  
   Team m_team;  
   int m_damage = 10; // Damage dealt by the bullet  

   // getters  
   int getDamage() const { return m_damage; }  
   sf::Vector2f getDirection() const { return m_direction; }  
   sf::FloatRect getShape() const { return m_sprite.getGlobalBounds(); }  

   // functions  
   float m_bulletspeed;  
   Bullet(Team team, sf::Vector2f dir1, const sf::RectangleShape& sha, float bul1);  
   void Update(float);  
   void Draw(sf::RenderWindow&);  
};  