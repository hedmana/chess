#include "Chess.hpp"

Chess::Chess(std::shared_ptr<GameContext> &context)
    : context_(context)
{
}

Chess::~Chess()
{
}

void Chess::init()
{
    message_.setFont(context_->assets_->getFont(TITLE_FONT));
    message_.setCharacterSize(60);
    message_.setString("LET'S PLAY CHESS!");
    message_.setOrigin(message_.getLocalBounds().width / 2, 
                        message_.getLocalBounds().height / 2);
    message_.setPosition(context_->window_->getSize().x / 2, 
                        context_->window_->getSize().y / 3);
}

void Chess::processInput()
{
    sf::Event event;
    while (context_->window_->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context_->window_->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case::sf::Keyboard::Enter:
                {
                    quit_ = true;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }   
    }
}

void Chess::update()
{
    if (quit_) 
    {
        context_->states_->popCurrent();
        quit_ = false;
    }
}

void Chess::draw()
{
    context_->window_->clear(sf::Color(0,80,0));
    context_->window_->draw(message_);
    context_->window_->display(); 
}

void Chess::pause()
{
    
}

void Chess::start()
{
    
}

