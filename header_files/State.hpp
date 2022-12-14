#ifndef __STATE_H__
#define __STATE_H__

#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {
public:
    // constructor and destructor for State parent class
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void endState() = 0;
private:
    sf::RenderWindow* window_;
    std::vector<sf::Texture> textures_; 
};

#endif // __STATE_H__