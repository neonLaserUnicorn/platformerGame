#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
    float _maxSpeed = 1.f;
    float _speed;
    float _maxFallSpeed = 2.f;
    float _fallSpeed;
    sf::Vector2f _pos;
    sf::CircleShape _form;
public:
    Player();
    void fall();
    void move();
    sf::Drawable& getSprite(){return _form;}
    sf::Vector2f getPosition();
};