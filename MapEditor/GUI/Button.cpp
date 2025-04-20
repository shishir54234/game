#include "Button.h"
#include <iostream>


	Button::Button(sf::Vector2f position, const sf::Vector2f& scale) :
		m_position(position), m_scale(scale), 
		isMousePressed(false), isMouseReleased(false)
	{
	}

	Button::~Button()
	{
	}

	void Button::Initialize()
	{

	}

	void Button::Load()
	{
		if (m_texture.loadFromFile("Assets/Button/buttons.png"))
		{
			std::cout << "Button loaded successfully\n"; 
		}
		else {
			abort();
		}
		m_sprite =  new sf::Sprite(m_texture);
		m_sprite->setTextureRect(sf::IntRect({0,0}, {291,64}));
		m_sprite->setPosition(m_position);
		m_sprite->setScale(m_scale);
	}

	void Button::Update(double deltaTime, sf::Vector2f mousePosition)
	{
		m_mousePosition = mousePosition; // Store the actual value, not a pointer

		bool isMousePressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

		// Detect mouse release (was pressed last frame, but not pressed now)
		isMouseReleased = m_wasMousePressedLastFrame && !isMousePressedNow;

		// Store current state for next frame
		m_wasMousePressedLastFrame = isMousePressedNow;
	}

	bool Button::IsPressed()
	{
		// Only check if the mouse was released over the button
		if (isMouseReleased)
		{
			// Get button dimensions
			sf::Vector2u size = m_sprite->getTexture().getSize();
			sf::Vector2f endPosition = m_position + sf::Vector2f(
				size.x * m_scale.x,
				size.y * m_scale.y);

			// Check if mouse is within button bounds
			if (m_mousePosition.x >= m_position.x && m_mousePosition.x <= endPosition.x &&
				m_mousePosition.y >= m_position.y && m_mousePosition.y <= endPosition.y)
			{
				return true;
			}
		}
		return false;
	}

	void Button::Draw(sf::RenderWindow& window)
	{
		window.draw(*m_sprite);
	}
