#include "Game.hpp"

Game::Game() : context_(std::make_shared<GameContext>())
{
    context_->window_->create(sf::VideoMode(1000, 600), "Chess");
    context_->states_->add(std::make_unique<MainMenu>(context_));
}

Game::~Game()
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time time_since_last_frame;

    while (context_->window_->isOpen())
    {
        time_since_last_frame += clock.restart();

        while(time_since_last_frame > fps_)
        {
            time_since_last_frame -= fps_;

            context_->states_->processStateChange();
            context_->states_->getCurrent()->processInput();
            context_->states_->getCurrent()->update(fps_);
            context_->states_->getCurrent()->draw();
        }
    }
}
