#include "Button.hpp"

Button::Button(int x, int y, int width, int height, std::string texturePath, std::string text)
    : x_(x), y_(y), width_(width), height_(height), texturePath_(texturePath)
{
    texture_.loadFromFile(texturePath_);
    sprite_.setTexture(texture_);
    sprite_.setScale(width_ / texture_.getSize().x, height_ / texture_.getSize().y);
    sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
    sprite_.setPosition(x_, y_);

    font_.loadFromFile("assets/fonts/Silkscreen-Regular.ttf");
    buttonText_.setFont(font_);
    buttonText_.setFillColor(sf::Color::Black);
    buttonText_.setString(text);
    buttonText_.setCharacterSize(20);
    buttonText_.setOrigin(buttonText_.getLocalBounds().width / 2, buttonText_.getLocalBounds().height / 2);
    buttonText_.setPosition(sprite_.getPosition().x, sprite_.getPosition().y);

}

Button::~Button()
{
}

sf::Sprite& Button::getSprite()
{
    return sprite_;
}

sf::Text& Button::getText()
{
    return buttonText_;
}