#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Object
{
protected:
    sf::Vector2f _pos;
    sf::FloatRect _hitbox;
public:
    Object(){}
    sf::Vector2f getPosition(){return _pos;}
    virtual sf::Drawable& getSprite()=0;
    virtual void collide(Object* another) = 0;
    sf::FloatRect hitbox(){return _hitbox;}
    void setPosition(float x, float y) {_pos = {x, y};}
};

class Movable : public Object
{
protected:
    float _maxSpeed = 1.f;
    float _speed;
    float _maxFallSpeed = 1.f;
    float _fallSpeed;
public:
    Movable(){}
    virtual void update(const std::list<Object*>& objects) = 0;
    virtual void move() = 0;
    virtual void fall(const std::list<Object*>& objects)
    {
        bool endFalling = false;
        for(auto obj : objects)
        {
            sf::FloatRect toIntersect = obj->hitbox();
            endFalling = _hitbox.intersects(toIntersect) && _hitbox.top+_hitbox.height -1 <= toIntersect.top;
            if(endFalling && _fallSpeed >=0)
            {
                _fallSpeed = 0;
                return;
            }
        }
        // for(int i = 0; i < objectsQuantity; ++i)
        // {
        //     sf::FloatRect toIntersect = {
        //         mapObjects[i].startX,
        //         mapObjects[i].startY,
        //         mapObjects[i].endX - mapObjects[i].startX,
        //         1.f
        //     };
        // }
        if(_fallSpeed < _maxFallSpeed)
            _fallSpeed += 0.01f;    
    }
    void setPosition(sf::Vector2f pos){_pos = pos;}
};

class Mortal
{
protected:
    int hp;
    Mortal();
public:
    virtual void damage(int dam) = 0;
};