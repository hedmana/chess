#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include "State.hpp"

class GameState : public State {
public:
    // CONSTRUCTOR & DESTRUCTOR
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    // PURE VIRTUAL FUNCTIONS
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void updateKeyBinds(const float& dt);
    void endState();
};

#endif // __GAMESTATE_H__