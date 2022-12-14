#ifndef __STATE_H__
#define __STATE_H__

#include "Entity.hpp"

class State {
public:
    // CONSTRUCTOR & DESTRUCTOR
    State(sf::RenderWindow* window);
    virtual ~State();

    // FUNCTIONS
    const bool& getQuit() const;
    virtual void checkForQuit();

    // PURE VIRTUAL FUNCTIONS 
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void updateKeyBinds(const float& dt) = 0;
    virtual void endState() = 0;
private:
    sf::RenderWindow* window_;
    std::vector<sf::Texture> textures_;
    bool quitState_; 
};

#endif // __STATE_H__