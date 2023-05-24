#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "Game.hpp"

Game::Game() : context_(std::make_shared<Context>())
{
    context_->window_->create(sf::VideoMode(200, 200), "Chess", sf::Style::Close);
    // TODO:
    // * Add first state
}

Game::~Game()
{
}

void Game::run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (context_->window_->isOpen())
    {
        sf::Event event;
        while (context_->window_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                context_->window_->close();
        }

        context_->window_->clear();
        context_->window_->draw(shape);
        context_->window_->display();
    }
}

