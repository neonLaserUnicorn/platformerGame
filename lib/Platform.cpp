#include "Platform.h"
#include  <iostream>

Platform::Platform(sf::Vector2f pos, sf::Vector2f endPos)
{
    this->_pos = pos;
    this->_endPos = endPos;
    this->_form.setFillColor(sf::Color::Cyan);
    _form.setSize(_endPos - _pos);
    _form.setPosition(_pos); 
    _hitbox = {
        _pos,
        _form.getSize(),
    };
}

void Platform::collide(Object* another)
{
    if(another->hitbox().top+another->hitbox().height > this->hitbox().top+2 && another->hitbox().top <  this->hitbox().top +  this->hitbox().height)
    {
        if(another->hitbox().left + another->hitbox().width >= this->hitbox().left && another->hitbox().left < this->hitbox().left)
        {
            std::cout << "Right\n";
            another->setPosition(this->hitbox().left - another->hitbox().width, another->getPosition().y);
        }
        else if(another->hitbox().left <= this->hitbox().left + this->hitbox().width)
        {
            std::cout << "Left\n";
            another->setPosition(this->hitbox().left + this->hitbox().width, another->getPosition().y);
        }
    }
}