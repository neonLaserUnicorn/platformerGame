#include "Player.h"
#include "Objects.h"
#include <iostream>

Player::Player():
    _form(sf::CircleShape(20.f,5))
{
    _form.setFillColor(sf::Color::Red);
    _pos = {0, 0};
    _speed = 0.f;   
}


void Player::move()
{
    bool start_move = false;
    sf::Vector2f dpos = {0,0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        start_move = true;
        if(abs(_speed) < _maxSpeed)
            _speed-=0.01f;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        start_move = true;
        if(abs(_speed) < _maxSpeed)
            _speed+=0.01f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&_fallSpeed == 0)
    {
        _fallSpeed = -_maxFallSpeed;
    }
    if(!start_move)
        _speed = 0.f;
    dpos = {_speed, _fallSpeed};
    _pos += dpos;
    _form.setPosition(_pos);
}
void Player::update(const std::list<Object*>& objects)
{
    _hitbox = {
        _pos.x,
        _pos.y - 2,
        _form.getRadius() * 2,
        _form.getRadius() * 2,
    };
    fall(objects);
    move();
}

void Player::collide(Object* another)
{
    if(another->hitbox().intersects(this->hitbox()))
    {
        another->collide(this);
    }
}