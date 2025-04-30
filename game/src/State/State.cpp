#include "State.h"
State::State(std::unique_ptr<std::map<std::string, int>> supportedKeys,
    std::unique_ptr<std::stack<std::unique_ptr<State>>> states, States identifyingState)
{
    this->supportedKeys = std::move(supportedKeys);
    this->quit = false;
	this->m_identifyingState = identifyingState;
}

State::~State()
{
}