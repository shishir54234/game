#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>
#include <typeindex>
#include "../Components/Movement.h"
#include "Animation/AnimationComponent.h"
class Entity
{
public:
    AnimationComponent* animationComponent;


    std::unordered_map<std::type_index, std::shared_ptr<void>> m_components;
	std::string name = "Default";
	sf::Vector2f m_position;// Position of the entity
    sf::RectangleShape m_boundingRectangle; // Bounding box for collision detection
	sf::Vector2f m_scale; // Scale of the entity
	sf::Vector2f m_dimension; // Dimension of the entity
	sf::Vector2f m_size; // Size of the entity
	bool alive = true; // Is the entity alive?
	size_t m_id = 0; 
    Entity(sf::Vector2f position = { 0,0 }, sf::Vector2f scale = { 1,1 }, sf::Vector2f size = { 1,1 }
        , sf::Vector2f dimension = { 1,1 }) 
    {
		m_position = position;
		m_scale = scale;
		m_size = size;
		m_dimension = dimension;
    }
    
    template<typename T, typename... Args>
    void add(Args&&... args) {
        m_components[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
    }
    template<typename T>
    T& get() {
        return *std::static_pointer_cast<T>(m_components.at(typeid(T)));
    }

    size_t id() const { return m_id; }
    bool isAlive() const { return alive; }
    void destroy() { alive = false; }
    const std::string& getName() const { return name; }
	virtual void Draw(sf::RenderWindow&)=0;
};

