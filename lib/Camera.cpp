#include "Camera.h"

Camera::Camera(Player* pl, sf::FloatRect levelBoundries):
    _target(pl), _boundries(levelBoundries)
{
    float width = 640;
    float height = 360;
    if(_boundries.height<height)
        height = _boundries.height;
    if(_boundries.width<width)
        width = _boundries.width;
    _view.reset(sf::FloatRect(0,0,width,height));
    _width = _view.getSize().x/2;
    _height = _view.getSize().y/2;
}

void Camera::update()
{
    sf::Vector2f p = _target->getPosition();
    _left = p.x - _width;
    _right = p.x + _width;
    _top = p.y - _height;
    _bot = p.y + _height;
    _view.setCenter(checkBoundries(p));
    _left = _view.getCenter().x - _width;
    _right = _view.getCenter().x + _width;
    _top = _view.getCenter().y - _height;
    _bot = _view.getCenter().y + _height;
}

sf::Vector2f Camera::checkBoundries(sf::Vector2f newPos)
{
    if(_left < _boundries.left)
        newPos.x = _boundries.left + _width;
    // else if(_right > _boundries.left + _boundries.width)
    //     newPos.x = _boundries.left + _boundries.width - _width;
    if(_bot > _boundries.top + _boundries.height)
        newPos.y = _boundries.top + _boundries.height - _height;
    else if(_top < _boundries.top)
        newPos.y = _boundries.top + _height;
    return newPos;
}