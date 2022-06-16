#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Platform.h"
#include"Objects.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    Player player;

    Platform* plats = new Platform[objectsQuantity];
    for(int i = 0; i < objectsQuantity;++i)
    {
        plats[i] = Platform(sf::Vector2f(mapObjects[i].startX, mapObjects[i].startY),
            sf::Vector2f(mapObjects[i].endX, mapObjects[i].endY));
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.move();
        window.clear();
        window.draw(player.getSprite());
        for(int i = 0; i < objectsQuantity; ++i)
        {
            window.draw(plats[i].getSprite());
        }
        window.display();
    }

    return 0;
}