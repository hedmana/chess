#ifndef __GAME_CONTEXT_H__
#define __GAME_CONTEXT_H__

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetManager.hpp"
#include "StateManager.hpp"


struct GameContext
{
    std::unique_ptr<Engine::AssetManager> assets_;
    std::unique_ptr<Engine::StateManager> states_;
    std::unique_ptr<sf::RenderWindow> window_;

    GameContext()
    {
        assets_ = std::make_unique<Engine::AssetManager>();
        states_ = std::make_unique<Engine::StateManager>();
        window_ = std::make_unique<sf::RenderWindow>();
    }
};

#endif // __GAME_CONTEXT_H__