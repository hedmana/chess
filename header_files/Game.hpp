#ifndef __GAME_H__
#define __GAME_H__

#include "GameState.hpp"

class Game {
public:
    // constructor & destructor
    Game();
    virtual ~Game();

    // public functions
    void run();
    void update();
    void updateDt();
    void render();
    void updateSFMLEvents();
private:
    // initialization
    void initWindow();
    void initStates();

    // variables
    sf::RenderWindow* window_;
    sf::Event event_;
    
    /* delta time variable to prevent frame rate dependency in game */
    float dt_;
    sf::Clock dtClock_;

    std::stack<State*> states_;
};

#endif // __GAME_H__