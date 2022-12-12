#include "Game.hpp"

// constructor & destructor
Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window_;
}

// initialization
void Game::initWindow()
{
    this->window_ = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML Demo");
}

// functions 
void Game::run()
{
    while (this->window_->isOpen()) {
        this->update();
        this->render();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window_->clear();
    this->window_->display();
}

void Game::updateSFMLEvents()
{
    while (this->window_->pollEvent(this->event_)) {
        if (this->event_.type == sf::Event::Closed) {
            this->window_->close();
        }
    }  
}