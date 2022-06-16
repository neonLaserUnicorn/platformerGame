#include "Player.h"
#include "Objects.h"

Player::Player():
    _form(sf::CircleShape(20.f,3))
{
    _form.setFillColor(sf::Color::Red);
    _pos = {0, 0};
    _speed = 0.f;   
}

void Player::fall()
{
    bool endFalling = false;
    sf::FloatRect botCollider = {
        _form.getPosition().x,
        _form.getRadius() * 2 + _form.getPosition().y,
        _form.getRadius() * 2,
        2.f
    };
    for(int i = 0; i < objectsQuantity; ++i)
    {
        sf::FloatRect toIntersect = {
            mapObjects[i].startX,
            mapObjects[i].startY,
            mapObjects[i].endX - mapObjects[i].startX,
            2
        };
        endFalling = botCollider.intersects(toIntersect);
        if(endFalling)
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
    fall();
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

sf::Vector2f Player::getPosition(){return this->_pos;}