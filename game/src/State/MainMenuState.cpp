#include "MainMenuState.h"
#include <fstream>
template<typename Config>
void MainMenuState<Config>::initFonts()
{
	if (!this->font.openFromFile("Assets/Font/PixelifySans-Medium.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
		abort();
	}
	if (!this->TitleFont.openFromFile("Assets/Font/Title_Regular.otf"))
	{
		std::cout << "Error loading font" << std::endl;
		abort();
	}
}

template<typename Config>
void MainMenuState<Config>::initKeybinds()
{
}
template<typename Config>
MainMenuState<Config>::MainMenuState(sf::Vector2f WindowSize ,
    std::map<std::string, int>* supportedKeys
    , std::stack< State<Config>*>* states)
    : m_WindowSize(WindowSize), 
	State<Config>(supportedKeys, states,States::MENU)
	, m_background(m_texture)
{
	this->initFonts();
	this->initBackground();
	this->initTitle();
    this->initKeybinds();
    this->initButtons();
    /*
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);*/
}
template<typename Config>
void MainMenuState<Config>::initTitle()
{
	m_titleText = new sf::Text(this->TitleFont);
	m_titleText->setString("Echoes of Aetheria");
	m_titleText->setCharacterSize(100);
	m_titleText->setFillColor(sf::Color(128, 0, 128));
	m_titleText->setPosition(sf::Vector2f((m_WindowSize.x - m_titleText->getGlobalBounds().size.x) / 2.f,
		(m_WindowSize.y / (3.f) - m_titleText->getGlobalBounds().size.y) / 2.f));
}
template<typename Config>
void MainMenuState<Config>::initVariables()
{

}
template<typename Config>
void MainMenuState<Config>::initBackground()
{
	m_texture.loadFromFile("Assets/Background/LockedDungeon.png");
	m_background.setTexture(m_texture);
	m_background.setTextureRect(sf::IntRect({ 0, 0 },
		{ (int)m_texture.getSize().x, (int)m_texture.getSize().y }));
	m_background.setScale(sf::Vector2f(m_WindowSize.x / m_texture.getSize().x, m_WindowSize.y / m_texture.getSize().y));
	m_background.setPosition(sf::Vector2f(0, 0));

}
template<typename Config>
void MainMenuState<Config>::initButtons()
{
	sf::Vector2f bsz = sf::Vector2f(200, 50);
	sf::Vector2f bpsn = sf::Vector2f(((m_WindowSize.x-bsz.x)/2.f), (m_WindowSize.y - bsz.y)/2.f);
	this->buttons["PLAY"] = std::make_unique<GUI::Button<Config>>(bpsn, bsz,
        &this->font, "Play");
	bpsn.y += 100;
	this->buttons["EXIT"] = std::make_unique<GUI::Button<Config>>(bpsn, bsz,
        &this->font, "Exit");
}
template<typename Config>
void MainMenuState<Config>::updateInput(const float& dt)
{
}
template<typename Config>
States MainMenuState<Config>::updateButtons()
{
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition());
	for (auto& it : this->buttons)
	{
		it.second->Update(mousePos);
	}
	if (this->buttons["PLAY"]->AreWePressed(mousePos))
	{
		return States::GAME;
	}
	else if (this->buttons["EXIT"]->AreWePressed(mousePos))
	{
		return States::EXIT;
	}
	else 
	{
	}
}
template<typename Config>
void MainMenuState<Config>::update(const float& dt)
{
	this->updateButtons();
	/*this->updateInput(dt);
	this->updateButtons();
	for (auto& it : this->buttons)
	{
		it.second->Update(sf::Mouse::getPosition());
	}
	if (this->buttons["PLAY"]->AreWePressed(sf::Mouse::getPosition()))
	{
		std::cout << "Play button pressed" << std::endl;
	}
	if (this->buttons["EXIT"]->AreWePressed(sf::Mouse::getPosition()))
	{
		std::cout << "Exit button pressed" << std::endl;
	}*/
}
template<typename Config>
void MainMenuState<Config>::renderButtons(sf::RenderTarget* target)
{
}
template<typename Config>
void MainMenuState<Config>::RenderWindow(sf::RenderWindow& window)
{
	window.draw(this->m_background);
	window.draw(*m_titleText);
	this->renderButtons(&window);
	for (auto& it : this->buttons)
	{
		it.second->Render(window);
	}
}
template<typename Config>
void MainMenuState<Config>::endState()
{

}
#include "../Settings/Config.h"
template class MainMenuState<Config>;