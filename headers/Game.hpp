#ifndef __GAME_H__
#define __GAME_H__

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetManager.hpp"
#include "StateManager.hpp"


struct Context
{
    std::unique_ptr<Engine::AssetManager> assets_;
    std::unique_ptr<Engine::StateManager> states_;
    std::unique_ptr<sf::RenderWindow> window_;

    Context()
    {
        assets_ = std::make_unique<Engine::AssetManager>();
        states_ = std::make_unique<Engine::StateManager>();
        window_ = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
public:
    // Constructor and destructor
    Game();
    ~Game();

    // Member functions
    void run();

private:
    // Private variables    
    std::shared_ptr<Context> context_;
    const sf::Time fps_ = sf::seconds(1.f/60.f); // Constant framerate cap of 60 FPS
};

#endif // __GAME_H__