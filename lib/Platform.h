#pragma once
#include "BaseClasses.h"

class Platform: public Object
{
private:
    sf::Vector2f _endPos;
    sf::RectangleShape _form;
public:
    Platform(){};
    Platform(sf::Vector2f pos, sf::Vector2f endPos);
    sf::Drawable& getSprite(){return _form;}
    void collide(Object*){}
};