#include "header_files/State.hpp"

// CONSTRUCTOR & DESTRUCTOR
State::State(sf::RenderWindow* window) : window_(window)
{
    this->quitState_ = false;
}

State::~State()
{
    
}

// FUNCTIONS
const bool& State::getQuit() const
{
    return this->quitState_;
}

void State::checkForQuit()
{
    /* sets the quitState_ variable to true if exit button is pressed */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->quitState_ = true;
    }
}
