#include "State.h"
State::State(std::unique_ptr<std::map<std::string, int>> supportedKeys,
    std::unique_ptr<std::stack<std::unique_ptr<State>>> states)
{
    this->supportedKeys = std::move(supportedKeys);
    this->quit = false;
}

State::~State()
{
}