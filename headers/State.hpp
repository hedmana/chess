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

        // Pure virtual methods:
        virtual void init() = 0;
        virtual void processInput() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

        // Virtual methods:
        virtual void pause(){};
        virtual void start(){};
    };
}

#endif // __STATE_H__