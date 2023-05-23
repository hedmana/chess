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
            virtual void Init() = 0;
            virtual void ProcessInput() = 0;
            virtual void Update(sf::Time deltaTime) = 0;
            virtual void Draw() = 0; 

            // Virtual methods:
            virtual void Pause(){};
            virtual void Start(){};
    };
}

#endif // __STATE_H__