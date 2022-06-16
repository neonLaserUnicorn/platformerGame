#include "Platform.h"

Platform::Platform(sf::Vector2f _pos, sf::Vector2f _endPos):
    pos(_pos), endPos(_endPos)
{
    form.setFillColor(sf::Color::Cyan);
    form.setSize(endPos - pos);
    form.setPosition(pos);
}