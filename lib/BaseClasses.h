#include <SFML/Graphics.hpp>


class Object
{
protected:
    sf::Drawable* _form;
    sf::Vector2f _pos;
public:
    Object(sf::Drawable* form):
        _form(form){}
    sf::Vector2f
}