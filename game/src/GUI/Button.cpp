#include "Button.h"
namespace GUI
{
	Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
		sf::Color idleColor = sf::Color(52, 152, 219)
		, sf::Color hoverColor = sf::Color(41, 128, 185)
		, sf::Color ActiveColor = sf::Color(31, 97, 141)) : m_text(*font)
	{
		this->m_buttonstate = button_states::BTN_IDLE;
		this->m_shape.setPosition(sf::Vector2f(x, y));
		this->m_shape.setSize(sf::Vector2f(width, height));


		this->m_font = font;
		this->m_text.setFont(*this->m_font);
		this->m_text.setString(text);
		this->m_text.setFillColor(sf::Color::White);
		this->m_text.setCharacterSize(13);
		

		
		this->m_text.setPosition(sf::Vector2f(
			this->m_shape.getPosition().x + (this->m_shape.getSize().x/ 2.f) - this->m_text.getGlobalBounds().position.x / 2.f,
			this->m_shape.getPosition().y  +(this->m_shape.getSize().y / 2.f) - this->m_text.getGlobalBounds().position.y / 2.f
		));


		this->m_idleColor = idleColor;
		this->m_activeColor = ActiveColor;
		this->m_hoverColor = hoverColor;

		this->m_shape.setFillColor(this->m_idleColor);
	}
	void Button::Update(sf::Vector2f mousePos)
	{
		this->m_buttonstate = button_states::BTN_IDLE;
		//Hover
		if (this->m_shape.getGlobalBounds().contains(mousePos))
		{
			this->m_buttonstate = button_states::BTN_HOVER;
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				this->m_buttonstate = button_states::BTN_PRESSED;
			}
		}
		switch (this->m_buttonstate) 
		{
		case button_states::BTN_PRESSED:
			this->m_shape.setFillColor(this->m_activeColor);
			break;

		case button_states::BTN_HOVER:
			this->m_shape.setFillColor(this->m_hoverColor);
			break;

		case button_states::BTN_IDLE:
			this->m_shape.setFillColor(this->m_idleColor);
			break;
		default: 
			abort();
		}
	}
	void Button::Render(sf::RenderWindow& window)
	{
		window.draw(this->m_shape);
	}
}



