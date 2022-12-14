#include "header_files/GameState.hpp"

// CONSTRUCTOR & DESTRUCTOR
GameState::GameState(sf::RenderWindow* window) : State(window)
{
    
}

GameState::~GameState()
{
    
}

// PURE VIRTUAL FUNCTIONS
void GameState::update(const float& dt)
{
    this->updateKeyBinds(dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        std::cout << "GameState!" << std::endl;
    }
}

void GameState::render(sf::RenderTarget* target)
{
    
}

void GameState::updateKeyBinds(const float& dt)
{
    this->checkForQuit();
}

void GameState::endState()
{
    std::cout << "Ending GameState!" << std::endl;   
}