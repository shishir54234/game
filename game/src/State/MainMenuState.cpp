#include "MainMenuState.h"
#include <fstream>
void MainMenuState::initFonts()
{
	this->font.openFromFile("Assets/Font/GameButton.ttf");   
	if (!this->font.openFromFile("Assets/Font/GameButton.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
		abort();
	}
}

void MainMenuState::initKeybinds()
{
    /*std::ifstream ifs("Assets/Font/arial.ttf");
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();*/
}
MainMenuState::MainMenuState(sf::Vector2f &WindowSize , 
    std::unique_ptr<std::map<std::string, int>> supportedKeys
    , std::unique_ptr<std::stack< std::unique_ptr<State>>> states)
    : m_WindowSize(WindowSize), State(std::move(supportedKeys), std::move(states),States::MENU), m_background(m_texture)
{
	m_texture.loadFromFile("Assets/Background/MenuBackGround.png");
	m_background.setTexture(m_texture);
	m_background.setTextureRect(sf::IntRect({ 0, 0 }, 
		{ (int)m_texture.getSize().x, (int)m_texture.getSize().y }));
	m_background.setScale(sf::Vector2f(WindowSize.x / m_texture.getSize().x, WindowSize.y / m_texture.getSize().y));
	m_background.setPosition(sf::Vector2f(0, 0));
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
    /*
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);*/
}
void MainMenuState::initVariables()
{

}
void MainMenuState::initBackground()
{

}
void MainMenuState::initButtons()
{
	sf::Vector2f bpsn = sf::Vector2f(m_WindowSize.x/2.f, m_WindowSize.y/2.f);
	this->buttons["PLAY"] = std::make_unique<GUI::Button>(bpsn, sf::Vector2f(200, 50),
        &this->font, "Play");
	bpsn.y += 100;
	this->buttons["EXIT"] = std::make_unique<GUI::Button>(bpsn, sf::Vector2f( 200, 50),
        &this->font, "Exit");
}
void MainMenuState::updateInput(const float& dt)
{
}
States MainMenuState::updateButtons()
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
void MainMenuState::update(const float& dt)
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
void MainMenuState::renderButtons(sf::RenderTarget* target)
{
}
void MainMenuState::RenderWindow(sf::RenderWindow& window)
{
	window.draw(this->m_background);
	this->renderButtons(&window);
	for (auto& it : this->buttons)
	{
		it.second->Render(window);
	}
}
void MainMenuState::endState()
{

}