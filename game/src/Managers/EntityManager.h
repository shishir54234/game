#pragma once
#include <SFML/Graphics.hpp>
#include "../Entities/Bullet.h"
#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../Math.h"

// linked list 

template <typename T>
class EntityCache
{
private: 
	struct Node {
		int id;
		T* entity;
		Node* next;
	};
	int id = 0;

public:
	std::list<Node> cache;
	std::unordered_map < int, typename std::list<Node>::iterator> entityMap;
	void add(T* entity)
	{
		id++;
		entityMap[id] = cache.insert(cache.end(), { id, std::move(entity), nullptr });
	}
	void add(const int& id, T* entity)
	{
		if (entityMap.find(id) == entityMap.end())
		{
			cache.push_back({ entity, nullptr });
			entityMap[id] = --cache.end();
		}
		else
		{
			entityMap[id]->entity = entity;
		}
	}
	T* get(const int& id)
	{
		if (entityMap.find(id) != entityMap.end())
		{
			return entityMap[id]->entity;
		}
		return nullptr; // or throw an exception
	}

	bool remove(const int& id)
	{
		if (entityMap.find(id) != entityMap.end())
		{
			auto it = entityMap[id];
			cache.erase(it);
			entityMap.erase(id);
			return true;
		}
		return false; // or throw an exception
	}
	void update(const float& dt) {
		for (auto& node : cache) {
			if (node.entity) {
				node.entity->Update(dt);
			}
		}
	}
	void Draw(sf::RenderWindow& window) {
		for (auto& node : cache) {
			if (node.entity) {
				node.entity->Draw(window);
			}
		}
	}
	void clear()
	{
		cache.clear();
		entityMap.clear();
	}
	~EntityCache() {
		clear();
	}

};
template <typename Config>
class EntityManager
{
private:
	EntityCache<Bullet<Config>> bulletCache;
	EntityCache<Enemy<Config>> enemyCache;
	EntityCache<Player<Config>> playerCache;
	Math math;
	Map<Config>& m_map;
	sf::Vector2f m_windowSize = { 1920, 1080 }; // Default window size
public:
    EntityManager(Map<Config>& map) : m_map(map) {  
       // Constructor body remains unchanged  
    }

	void add(Bullet<Config>* bullet) {
		bulletCache.add(std::move(bullet));
	}
	void add(Enemy<Config>* enemy) {
		enemyCache.add(std::move(enemy));
	}
	void add(Player<Config>* player) {
		playerCache.add(std::move(player));
	}

	Bullet<Config>* getBullet(const int& id) {
		return bulletCache.get(id);
	}
	Enemy<Config>* getEnemy(const int& id) {
		return enemyCache.get(id);
	}
	Player<Config>* getPlayer(const int& id) {
		return playerCache.get(id);
	}

    void update(const float& dt) {  

		std::vector<int> bulletsToRemove;
		std::vector<int> enemiesToRemove;
		for (auto& bulletNode : bulletCache.cache) {
			if (bulletNode.entity) {
				
				bulletNode.entity->Update(dt);
			}
		}

		
		for (auto& bulletNode : bulletCache.cache) {
			if (bulletNode.entity) {

				sf::FloatRect bounds = bulletNode.entity->getShape();
				std::cout << "Bullet Bounds: " << bounds.position.x << "," << bounds.position.y
					<< "\n";
				
				if (bounds.position.x <= 0 
					|| bounds.position.x + bounds.size.x >= m_windowSize.x 
					|| bounds.position.y <= 0 
					|| bounds.position.y + bounds.size.y >= m_windowSize.y) { // Assuming window height is 600
					bulletsToRemove.push_back(bulletNode.id);
				}
			}
		}
		for (const auto& id : bulletsToRemove) {
			bulletCache.remove(id);
		}

		// Update enemies and check collisions with player
		
		// Update bullets and check collisions with enemies
		for (auto& bulletNode : bulletCache.cache) {
			if (bulletNode.entity) {
				
				for (auto& enemyNode : enemyCache.cache) {
					if (enemyNode.entity and 
						bulletNode.entity->m_team!=Team::ENEMY) {
						sf::FloatRect f = enemyNode.entity->m_boundingRectangle.getGlobalBounds();
						sf::FloatRect f1 = bulletNode.entity->m_sprite.getGlobalBounds();
						


						if (math.DidRectCollide(f,f1)) {


							enemyNode.entity->
								ChangeHealth(bulletNode.entity->
									getDamage());
							bulletsToRemove.push_back(bulletNode.id);
							break;

						}
						
					
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
			for (auto& playerNode : playerCache.cache) {
				if (playerNode.entity) {
					Bullet<Config>*p = playerNode.entity->Shoot(dt);
					this->add(p);
				}
			}
		}
		// Remove bullets and enemies that are marked for deletion
		
		for (const auto& id : enemiesToRemove) {
			enemyCache.remove(id);
		}


       for (auto& Enemy : enemyCache.cache) {  
           if (Enemy.entity) {  
               Enemy.entity->Update(dt);  
           }  
       }  
       for (auto& Bullet : bulletCache.cache) {  
           if (Bullet.entity) {  
               Bullet.entity->Update(dt);  
           }  
       }  
       for (auto& Player : playerCache.cache) {  
           if (Player.entity) {  
               Player.entity->Update(dt);  
           }  
       }  
    }

	void RenderWindow(sf::RenderWindow& window) {
		bulletCache.Draw(window);
		enemyCache.Draw(window);
		playerCache.Draw(window);
	
	}


};

