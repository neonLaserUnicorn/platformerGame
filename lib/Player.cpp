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

void Player::fall()
{
    bool endFalling = false;
    for(int i = 0; i < objectsQuantity; ++i)
    {
        sf::FloatRect toIntersect = {
            mapObjects[i].startX,
            mapObjects[i].startY,
            mapObjects[i].endX - mapObjects[i].startX,
            1.f
        };
        endFalling = _hitbox.intersects(toIntersect) && _hitbox.top+_hitbox.height -1 <= toIntersect.top;
        if(endFalling && _fallSpeed >=0)
        {
            _fallSpeed = 0;
            return;
        }
    }
    if(_fallSpeed < _maxFallSpeed)
        _fallSpeed += 0.01f;    
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
void Player::update()
{
    _hitbox = {
        _pos.x,
        _pos.y - 2,
        _form.getRadius() * 2,
        _form.getRadius() * 2,
    };
    fall();
    move();
}
