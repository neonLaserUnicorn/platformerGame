#include "Platform.h"

Platform::Platform(sf::Vector2f pos, sf::Vector2f endPos):
    _pos(pos), _endPos(endPos)
{
    _form.setFillColor(sf::Color::Cyan);
    _form.setSize(_endPos - _pos);
    _form.setPosition(_pos);
}