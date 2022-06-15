#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
    float maxSpeed = 1.f;
    float speed;
    float maxFallSpeed = 2.f;
    float fallSpeed;
    sf::Vector2f pos;
    sf::CircleShape form;
public:
    Player();
    void fall();
    void move();
    sf::Drawable& getSprite(){return form;}
};