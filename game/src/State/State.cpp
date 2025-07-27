#include "State.h"

template<typename Config>
State<Config>::State(std::map<std::string, int>* supportedKeys,
    std::stack<State<Config>*>* states, States identifyingState)
{
    this->supportedKeys = std::move(supportedKeys);
    this->quit = false;
	this->m_identifyingState = identifyingState;
}
template<typename Config>
State<Config>::~State()
{
}