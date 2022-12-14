#ifndef __GAME_H__
#define __GAME_H__

#include "GameState.hpp"

class Game {
public:
    // CONSTRUCTOR & DESTRUCTOR
    Game();
    virtual ~Game();

    // PUBLIC FUNCTIONS 
    void run();
    void update();
    void updateDt();
    void render();
    void updateSFMLEvents();
private:
    // INITIALIZATION
    void initWindow();
    void initStates();

    // VARIABLES
    sf::RenderWindow* window_;
    sf::Event event_;
    std::stack<State*> states_;
    /* delta time variables to prevent frame rate dependency in game */
    float dt_;
    sf::Clock dtClock_;
};

#endif // __GAME_H__