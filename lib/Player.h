#pragma once
#include "BaseClasses.h"
class Player : public Movable
{
private:
    sf::CircleShape _form;
public:
    Player();
    void fall();
    void move();
    void update();
    void collide(Object* another){}
    sf::Drawable& getSprite(){return _form;}
};