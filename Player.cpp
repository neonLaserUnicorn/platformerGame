#include "Player.h"
#include "Objects.h"

Player::Player():
    form(sf::CircleShape(20.f,3))
{
    form.setFillColor(sf::Color::Red);
    pos = {0, 0};
    speed = 0.f;   
}

void Player::fall()
{
    bool endFalling = false;
    sf::FloatRect botCollider = {
        form.getPosition().x,
        form.getRadius() * 2 + form.getPosition().y,
        form.getRadius() * 2,
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
            fallSpeed = 0;
            return;
        }
    }
    if(fallSpeed < maxFallSpeed)
        fallSpeed += 0.01f;
}

void Player::move()
{
    fall();
    bool start_move = false;
    sf::Vector2f _pos = {0,0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        start_move = true;
        if(abs(speed) < maxSpeed)
            speed-=0.01f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        start_move = true;
        if(abs(speed) < maxSpeed)
            speed+=0.01f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&fallSpeed == 0)
    {
        fallSpeed = -maxFallSpeed;
    }
    if(!start_move)
        speed = 0.f;
    _pos = {speed, fallSpeed};
    pos += _pos;
    form.setPosition(pos);
}