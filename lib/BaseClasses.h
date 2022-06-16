#pragma once
#include <SFML/Graphics.hpp>

class Object
{
protected:
    sf::Shape* _form;
    sf::Vector2f _pos;
public:
    Object(){}
    sf::Vector2f getPosition(){return _pos;}
    sf::Drawable& getSprite(){return *_form;}
    virtual void collide(Object* another) = 0;
};

class Movable : public Object
{
protected:
    float _maxSpeed = 1.f;
    float _speed;
    float _maxFallSpeed = 2.f;
    float _fallSpeed;
public:
    Movable(){}
    virtual void update() = 0;
    virtual void move() = 0;
    virtual void fall() = 0;
    void setPosition(sf::Vector2f pos){_pos = pos;}
};