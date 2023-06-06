#ifndef __GAME_H__
#define __GAME_H__

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "MainMenu.hpp"
#include "GameContext.hpp"

enum AssetID
{
    MAIN_FONT = 0,
    TITLE_FONT = 1
};

class GameEngine
{
private:
    // Private variables    
    std::shared_ptr<GameContext> context_;
    const sf::Time fps_ = sf::seconds(1.f/60.f); // Constant framerate cap of 60 FPS

public:
    // Constructor and destructor
    GameEngine();
    ~GameEngine();

    // Member functions
    void run();
};

#endif // __GAME_H__