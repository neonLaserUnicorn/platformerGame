#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"

class Camera
{
private:
    sf::View _view;
    float _left;
    float _right;
    float _top;
    float _bot;
    float _width;
    float _height;
    Player* _target;
    sf::FloatRect _boundries;
public:
    Camera(Player* pl, sf::FloatRect levelBoundries);
    float left(){return _left;}
    float right(){return _right;}
    float top(){return _top;}
    float bottom(){return _bot;}
    void update();
    sf::Vector2f checkBoundries(sf::Vector2f newPos);
};