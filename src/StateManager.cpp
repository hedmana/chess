#include "StateManager.hpp"

namespace Engine
{
    StateManager::StateManager() : add_(false), replace_(false), remove_(false)
    {
    }
    
    StateManager::~StateManager()
    {
    }

    void StateManager::add(std::unique_ptr<State> to_add, bool replace)
    {
        add_ = true;
        new_state_ = std::move(to_add);

        replace_ = replace;
    }
    
    void StateManager::popCurrent()
    {
        remove_ = true;
    }
    
    void StateManager::processStateChange()
    {
        if(remove_ && (!state_stack_.empty()))
        {
            state_stack_.pop();

            if(!state_stack_.empty())
            {
                state_stack_.top()->start();
            }

            remove_ = false;
        }

        if(add_)
        {
            if(replace_ && (!state_stack_.empty()))
            {
                state_stack_.pop();
                replace_ = false;
            }

            if(!state_stack_.empty())
            {
                state_stack_.top()->pause();
            }

            state_stack_.push(std::move(new_state_));
            add_ = false;
        }
    }
    
    std::unique_ptr<State>& StateManager::getCurrent()
    {
        return state_stack_.top();
    }
}