#ifndef __STATE_MANAGER_H__
#define __STATE_MANAGER_H__

#include <stack>
#include <memory>

#include "State.hpp"

namespace Engine
{
    // CLASS FOR MANAGING AND NAVIGATING THROUGH THE DIFFERENT GAME STATES
    class StateManager
    {
    private:
        // Private variables
        std::stack<std::unique_ptr<State>> state_stack_;
        std::unique_ptr<State> new_state_;
        bool add_;
        bool replace_;
        bool remove_;

    public:
        // Constructor and destructor
        StateManager();
        ~StateManager();

        // Member functions
        void add(std::unique_ptr<State> to_add, bool replace = false);
        void popCurrent();
        void processStateChange();
        std::unique_ptr<State> &getCurrent();
    };
}

#endif // __STATE_MANAGER_H__