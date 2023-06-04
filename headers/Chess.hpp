#ifndef __CHESS_H__
#define __CHESS_H__

#include <memory>

#include "State.hpp"
#include "GameContext.hpp"
#include "Game.hpp"

// CHILD CLASS RESPONSIBLE FOR THE CHESS BOARD ITSELF. INHERITS FROM THE STATE CLASS.
class Chess : public Engine::State
{
private:
    std::shared_ptr<GameContext> context_;
    sf::Text message_;

    bool quit_ = false;

public:
    Chess(std::shared_ptr<GameContext> &context);
    ~Chess();

    // Pure virtual methods:
    virtual void init() override;
    virtual void processInput() override;
    virtual void update(sf::Time deltaTime) override;
    virtual void draw() override; 

    // Virtual methods:
    virtual void pause() override;
    virtual void start() override;
};

#endif // __CHESS_H__