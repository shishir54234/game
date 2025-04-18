#pragma once
#include <SFML/Graphics.hpp>
namespace GUI
{
	enum button_states{BTN_IDLE=0, BTN_HOVER, BTN_PRESSED};
	class Button
	{
	public:
		short unsigned m_buttonstate;
		sf::RectangleShape m_shape;
		sf::Font* m_font;
		sf::Text m_text;
		sf::Color m_idleColor; 
		sf::Color m_hoverColor; 
		sf::Color m_activeColor;

		Button(float x, float y, float width, float height, sf::Font* font, std::string text,
			sf::Color idleColor, sf::Color hoverColor, sf::Color ActiveColor);
		~Button();

		//Functions 
		bool AreWePressed(sf::Vector2f mousePos);
		void Update(sf::Vector2f mousePos);
		void Render(sf::RenderWindow& window);

	};
}


