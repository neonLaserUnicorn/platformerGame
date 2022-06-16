#include "Camera.h"

Camera::Camera(Player* pl, sf::FloatRect levelBoundries):
    _target(pl), _boundries(levelBoundries)
{
    _view.reset(sf::FloatRect(0,0,1280*1.4,720*1.4));
    _width = _view.getSize().x/2;
    _height = _view.getSize().y/2;
}

void Camera::update()
{
    _view.setCenter(checkBoundries(_target->getPosition()));
    _left = _view.getCenter().x - _width;
    _right = _view.getCenter().x + _width;
    _top = _view.getCenter().y - _height;
    _bot = _view.getCenter().y + _height;
}

sf::Vector2f Camera::checkBoundries(sf::Vector2f newPos)
{
    if(_left < _boundries.left)
        newPos.x = _boundries.left + _width;
    else if(_right > _boundries.left + _boundries.width)
        newPos.x = _boundries.left + _boundries.width - _width;
    if(_top < _boundries.top)
        newPos.y = _boundries.top + _top;
    else if(_bot > _boundries.top + _boundries.height)
        newPos.y = _boundries.top + _boundries.height - _height;
    return newPos;
}