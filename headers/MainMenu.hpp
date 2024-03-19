#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include <memory>
#include <iostream>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include "State.hpp"
#include "Chess.hpp"
#include "GameContext.hpp"
#include "GameEngine.hpp"
#include "Enums.hpp"

// CHILD CLASS RESPONSIBLE FOR THE MAIN MENU. INHERITS FROM THE STATE CLASS.
class MainMenu : public Engine::State
{
private:
    std::shared_ptr<GameContext> context_;
    sf::Text game_title_;
    sf::Text play_button_;
    sf::Text quit_button_;
    sf::Texture texture1_;
    sf::Texture texture2_;
    sf::Sprite icon1_;
    sf::Sprite icon2_;
    bool is_play_button_selected_;
    bool is_play_button_pressed_;
    bool is_quit_button_selected_;
    bool is_quit_button_pressed_;

public:
    MainMenu(std::shared_ptr<GameContext> &context);
    ~MainMenu();

    // Pure virtual methods
    void init() override;
    void processInput() override;
    void update() override;
    void draw() override;
};

#endif // __MAIN_MENU_H__
