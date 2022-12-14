#ifndef __ENTITY_H__
#define __ENTITY_H__

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

class Entity {
public:
    //CONSTRUCTOR & DESTRUCTOR
    Entity();
    virtual ~Entity();

    // PURE VIRTUAL FUNCTIONS
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif // __ENTITY_H__