#ifndef __STATE_MANAGER_H__
#define __STATE_MANAGER_H__

#include <stack>
#include <memory>
#include <iostream>

#include "State.hpp"

namespace Engine
{
// CLASS FOR MANAGING AND NAVIGATING THROUGH THE DIFFERENT GAME STATES
class StateManager
{
public:
    StateManager(){}
    ~StateManager(){}

    void Hello();
private:
};
}

#endif // __STATE_MANAGER_H__