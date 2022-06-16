#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
private:
    sf::Vector2f pos;
    sf::Vector2f endPos;
    sf::RectangleShape form;
public:
    Platform(){};
    Platform(sf::Vector2f _pos, sf::Vector2f _endPos);
    sf::Drawable& getSprite(){return form;}
};