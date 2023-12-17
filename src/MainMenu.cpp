#include "MainMenu.hpp"

MainMenu::MainMenu(std::shared_ptr<GameContext> &context)
    : context_(context), is_play_button_selected_(true), is_play_button_pressed_(false),
      is_quit_button_selected_(false), is_quit_button_pressed_(false)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
    context_->assets_->addFont(MAIN_FONT, "assets/fonts/PlayfairDisplay-Regular.ttf");
    context_->assets_->addFont(TITLE_FONT, "assets/fonts/PlayfairDisplay-ExtraBold.ttf");

    // Title text
    game_title_.setFont(context_->assets_->getFont(TITLE_FONT));
    game_title_.setCharacterSize(100);
    game_title_.setString("Chess");
    game_title_.setOrigin(game_title_.getLocalBounds().width / 2,
                          game_title_.getLocalBounds().height / 2);
    game_title_.setPosition(context_->window_->getSize().x / 2,
                            context_->window_->getSize().y / 3);

    // Play button
    play_button_.setFont(context_->assets_->getFont(MAIN_FONT));
    play_button_.setString("Play");
    play_button_.setOrigin(play_button_.getLocalBounds().width / 2,
                           play_button_.getLocalBounds().height / 2);
    play_button_.setPosition(context_->window_->getSize().x / 2,
                             (context_->window_->getSize().y / 3) + 100);

    // Quit button
    quit_button_.setFont(context_->assets_->getFont(MAIN_FONT));
    quit_button_.setString("Quit");
    quit_button_.setOrigin(quit_button_.getLocalBounds().width / 2,
                           quit_button_.getLocalBounds().height / 2);
    quit_button_.setPosition(context_->window_->getSize().x / 2,
                             (context_->window_->getSize().y / 3) + 150);
}

void MainMenu::processInput()
{
    sf::Event event;
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*(context_->window_));
    sf::FloatRect playRect((play_button_.getPosition().x - play_button_.getGlobalBounds().width / 2),
                           play_button_.getPosition().y,
                           play_button_.getGlobalBounds().width,
                           play_button_.getGlobalBounds().height);
    sf::FloatRect quitRect((quit_button_.getPosition().x - quit_button_.getGlobalBounds().width / 2),
                           quit_button_.getPosition().y,
                           quit_button_.getGlobalBounds().width,
                           quit_button_.getGlobalBounds().height);

    while (context_->window_->pollEvent(event))
    {
        if (playRect.contains(context_->window_->mapPixelToCoords(mouse_pos)))
        {
            is_play_button_selected_ = true;
            is_quit_button_selected_ = false;

            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
            {
                is_play_button_pressed_ = true;
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else if (quitRect.contains(context_->window_->mapPixelToCoords(mouse_pos)))
        {
            is_play_button_selected_ = false;
            is_quit_button_selected_ = true;

            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
            {
                is_quit_button_pressed_ = true;
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                context_->window_->close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                {
                    if (!is_play_button_selected_)
                    {
                        is_play_button_selected_ = true;
                        is_quit_button_selected_ = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!is_quit_button_selected_)
                    {
                        is_play_button_selected_ = false;
                        is_quit_button_selected_ = true;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    if (is_play_button_selected_)
                    {
                        is_play_button_pressed_ = true;
                    }
                    else
                    {
                        is_quit_button_pressed_ = true;
                    }
                    break;
                }
                default:
                {
                    break;
                }
                }
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

void MainMenu::update()
{
    if (is_play_button_selected_)
    {
        play_button_.setFillColor(sf::Color::Yellow);
        quit_button_.setFillColor(sf::Color::White);
    }
    else
    {
        play_button_.setFillColor(sf::Color::White);
        quit_button_.setFillColor(sf::Color::Yellow);
    }

    if (is_play_button_pressed_)
    {
        is_play_button_pressed_ = false;
        context_->states_->add(std::make_unique<Chess>(context_));
    }

    if (is_quit_button_pressed_)
    {
        is_quit_button_pressed_ = false;
        context_->window_->close();
    }
}

void MainMenu::draw()
{
    context_->window_->clear(sf::Color(75, 0, 90));
    context_->window_->draw(game_title_);
    context_->window_->draw(play_button_);
    context_->window_->draw(quit_button_);
    context_->window_->display();
}
