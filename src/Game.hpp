#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
public:
    // constructor & destructor
    Game();
    virtual ~Game();

    // functions
    void run();
    void update();
    void render();
    void updateSFMLEvents();
private:
    // initialization
    void initWindow();

    // variables
    sf::RenderWindow* window_;
    sf::Event event_;
};

#endif // __GAME_H__