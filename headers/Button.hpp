#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <iostream>

#include <SFML/Graphics.hpp>

class Button {
private:
    int x_;
    int y_;
    int width_;
    int height_;
    std::string texturePath_;
    std::string text_;
    sf::Texture texture_;
    sf::Sprite sprite_;
    sf::Font font_;
    sf::Text buttonText_;

public:
    Button(int x, int y, int width, int height, std::string texturePath, std::string text);
    ~Button();

    sf::Sprite& getSprite();
    sf::Text& getText(); 
};

#endif // __BUTTON_HPP__