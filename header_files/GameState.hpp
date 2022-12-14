#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include "State.hpp"

class GameState : public State {
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void endState();
private:
};

#endif // __GAMESTATE_H__