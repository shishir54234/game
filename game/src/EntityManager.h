#pragma once
#include "Entities/Entity.h"
#include <SFML/Graphics.hpp>
class EntityManager
{
private:
	static std::vector<Entity> m_entities; // Vector to store all entities
public:
	static std::unique_ptr<Entity> createShape(const std::string& type)
	{
		// complete the if else statements
		if (type == "Player")
		{

		}
		else if(type == "Enemy")
		{

		}
		else if (type == "Bullet")
		{

		}

	}
	static void Render(sf::RenderWindow& window)
	{
		for (auto &entity : m_entities)
		{
			entity.Draw(window);
		}
	}

};

