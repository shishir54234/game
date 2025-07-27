#pragma once
#include <SFML/Graphics.hpp>


#include <string>
namespace GUI
{
	template<typename Config>
	class Button
	{
	public:
		short unsigned m_buttonstate;
		sf::Vector2f m_pos;
		sf::Vector2f m_sz;
		sf::RectangleShape m_shape;
		sf::Font* m_font;
		sf::Text m_text;
		sf::Color m_idleColor; 
		sf::Color m_hoverColor; 
		sf::Color m_activeColor;
		sf::Sprite m_sprite;
		sf::Texture m_texture;

		Button(sf::Vector2f pos, sf::Vector2f sz, sf::Font* font, std::string text,
			sf::Color idleColor = Config::Graphics::Button::IDLE_COLOR
			, sf::Color hoverColor = Config::Graphics::Button::HOVER_COLOR
			, sf::Color ActiveColor = Config::Graphics::Button::ACTIVE_COLOR) 
			: m_pos(pos), m_sz(sz), m_text(*font), m_sprite(m_texture)
		{
			m_texture.loadFromFile(Config::Graphics::Button::BULLET_DIM_PATH);
			m_sprite.setTexture(m_texture);

			m_sprite.setTextureRect(sf::IntRect({ 0, 0 },
				{ (int)m_texture.getSize().x, (int)m_texture.getSize().y }));
			m_sprite.setPosition(pos);
			m_sprite.setScale(sf::Vector2f(sz.x / m_texture.getSize().x,
				sz.y / m_texture.getSize().y));
			this->m_buttonstate = Config::button_states::BTN_IDLE;
			this->m_shape.setPosition(pos);
			this->m_shape.setSize(sz);

			this->m_font = font;
			this->m_text.setFont(*this->m_font);
			this->m_text.setString(text);
			this->m_text.setFillColor(sf::Color::White);
			this->m_text.setCharacterSize(13);
			this->m_text.setStyle(sf::Text::Bold);


			this->m_text.setPosition(sf::Vector2f(
				this->m_shape.getPosition().x + (this->m_shape.getSize().x / 2.f) - (this->m_text.getGlobalBounds().size.x / 2.f),
				this->m_shape.getPosition().y + (this->m_shape.getSize().y / 2.f) - (this->m_text.getGlobalBounds().size.y / 2.f)
			));


			this->m_idleColor = Config::Graphics::Button::IDLE_COLOR;
			this->m_activeColor = Config::Graphics::Button::ACTIVE_COLOR;
			this->m_hoverColor = Config::Graphics::Button::HOVER_COLOR;

			this->m_shape.setFillColor(this->m_idleColor);

			this->m_buttonstate = Config::button_states::BTN_IDLE;
		}
		/*~Button();*/

		//Functions 
		bool AreWePressed(sf::Vector2f mousePos) {
		

			if (this->m_buttonstate ==
				Config::button_states::BTN_HOVER)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					return true;
				}
			}
			return false;
		
		
		}
		void Update(sf::Vector2f mousePos) {
			if (this->m_shape.getGlobalBounds().contains(mousePos))
			{
				if (this->m_buttonstate ==
					Config::button_states::BTN_IDLE)
				{
					m_texture.loadFromFile(Config::Graphics::Button::BUTTON_LIT_PATH);
					m_sprite.setTexture(m_texture);

					m_sprite.setTextureRect(sf::IntRect({ 0, 0 },
						{ (int)m_texture.getSize().x, (int)m_texture.getSize().y }));
					m_sprite.setPosition(m_pos);
					m_sprite.setScale(sf::Vector2f(m_sz.x
						/ m_texture.getSize().x, m_sz.y / m_texture.getSize().y));
				}
				this->m_buttonstate =
					Config::button_states::BTN_HOVER;
			}
			else
			{
				if (this->m_buttonstate
					== Config::button_states::BTN_HOVER)
				{
					m_texture.loadFromFile(Config::Graphics::Button::BULLET_DIM_PATH);
					m_sprite.setTexture(m_texture);

					m_sprite.setTextureRect(sf::IntRect({ 0, 0 },
						{ (int)m_texture.getSize().x, (int)m_texture.getSize().y }));
					m_sprite.setPosition(m_pos);
					m_sprite.setScale(sf::Vector2f(m_sz.x / m_texture.getSize().x, m_sz.y / m_texture.getSize().y));
				}
				this->m_buttonstate =
					Config::button_states::BTN_IDLE;
			}
		
		}
		void Render(sf::RenderWindow& window) {
			window.draw(this->m_sprite);
			window.draw(this->m_text);

		}

	};
}


