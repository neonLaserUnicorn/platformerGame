#include "Platform.h"

Platform::Platform(sf::Vector2f pos, sf::Vector2f endPos)
{
    this->_pos = pos;
    this->_endPos = endPos;
    this->_form.setFillColor(sf::Color::Cyan);
    _form.setSize(_endPos - _pos);
    _form.setPosition(_pos); 
}