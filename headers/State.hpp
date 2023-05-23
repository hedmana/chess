#ifndef __STATE_H__
#define __STATE_H__

#include <SFML/System/Time.hpp>

namespace Engine
{
    // PARENT CLASS FOR IMPLEMENTING GAME STATES
    class State
    {
    public:
        // Constructor and destructor:
        State(){};
        virtual ~State(){};

        // Pure virtual functions:
        virtual void init() = 0;
        virtual void processInput() = 0;
        virtual void update(sf::Time deltaTime) = 0;
        virtual void draw() = 0; 

        // Virtual functions:
        virtual void pause(){};
        virtual void start(){};
    };
}

#endif // __STATE_H__