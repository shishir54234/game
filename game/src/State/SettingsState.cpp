#include "SettingsState.h"

template<typename Config>
void SettingsState<Config>::initVariables() {

}
template<typename Config>
void SettingsState<Config>::initBackground() {
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->m_WindowSize.x), 
			static_cast<float>(this->m_WindowSize.y)
		)
	);
	if (!this->backgroundTexture.
		loadFromFile("Assets/Background/SettingsBackground.png")) {
		std::cout << "Error loading background texture" << std::endl;
		abort();
	}

}

template<typename Config>

void SettingsState<Config>::initFonts() {

}
template<typename Config>

void SettingsState<Config>::initKeybinds() {



}
template<typename Config>

void SettingsState<Config>::initGui() {

}




template<typename Config>
void SettingsState<Config>::initText() {


}
template<typename Config>
void SettingsState<Config>::update(const float& dt) {
	this->updateInput(dt);
	this->updateGui(dt);
	this->updateButtons();
}
template<typename Config>
void SettingsState<Config>::updateInput(const float& dt) {

}
template<typename Config>
void SettingsState<Config>::updateGui(const float& dt) {
}

template<typename Config>
States SettingsState<Config>::updateButtons() {

	return States::PAUSE;
}


template<typename Config>
void SettingsState<Config>::renderGui(sf::RenderTarget& target) {
	
}




template<typename Config>
SettingsState<Config>::SettingsState(sf::Vector2f& WindowSize ,
	sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, 
	std::stack<State<Config>*>* states)
	: State<Config>(supportedKeys, states, States::PAUSE), 
	m_WindowSize(WindowSize), 
	background(sf::Vector2f(WindowSize.x, WindowSize.y))
{

}


template<typename Config>
void SettingsState<Config>::RenderWindow(sf::RenderWindow& window) {
	window.draw(this->background);
	for (auto& it : this->buttons) {
		it.second->Render(window);
	}
	if (this->optionsText) {
		window.draw(*this->optionsText);
	}
}
#include "../Settings/Config.h"
template class SettingsState<Config>;