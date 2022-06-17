#pragma once
#include <SFML/Graphics.hpp>

class Object
{
protected:
    sf::Vector2f _pos;
    sf::FloatRect _hitbox;
public:
    Object(){}
    sf::Vector2f getPosition(){return _pos;}
    virtual sf::Drawable& getSprite()=0;
    virtual void collide(Object* another) = 0;
};

class Movable : public Object
{
protected:
    float _maxSpeed = 1.f;
    float _speed;
    float _maxFallSpeed = 1.f;
    float _fallSpeed;
public:
    Movable(){}
    virtual void update() = 0;
    virtual void move() = 0;
    virtual void fall() = 0;
    void setPosition(sf::Vector2f pos){_pos = pos;}
};