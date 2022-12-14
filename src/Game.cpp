#include "header_files/Game.hpp"

// constructor & destructor
Game::Game() { 
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window_;

    while (!this->states_.empty()) {
        delete this->states_.top();
        this->states_.pop();
    }
}

// initialization 
void Game::initWindow()
{
    std::string title = "None";
    std::ifstream ifs("assets/window_init.txt");
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    } else {
        std::cout << "Failed to read window bounds. Bounds set to default." << std::endl;
    }

    ifs.close();

    this->window_ = new sf::RenderWindow(sf::VideoMode(window_bounds.width, window_bounds.height), title);
    this->window_->setFramerateLimit(framerate_limit);
    this->window_->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
    this->states_.push(new GameState(this->window_));
}

// public functions 
void Game::run()
{
    while (this->window_->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states_.empty()) {
        this->states_.top()->update(this->dt_);
    }
}

void Game::updateDt()
{
    // updates the dt variable with the time it takes to update and render one frame
    this->dt_ = this->dtClock_.restart().asSeconds();
}

void Game::render()
{
    this->window_->clear();

    // checks if there are any initialized states and renders the active one
    if (!this->states_.empty()) {
        this->states_.top()->render(this->window_);
    }

    this->window_->display();
}

void Game::updateSFMLEvents()
{
    // checks for events in the SFML window
    while (this->window_->pollEvent(this->event_)) {
        if (this->event_.type == sf::Event::Closed) {
            this->window_->close();
        }
    }  
}