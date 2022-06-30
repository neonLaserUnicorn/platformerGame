#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Platform.h"
#include"Objects.h"
#include"Camera.h"
#include<list>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    Player player;
    Camera camera(&player, sf::FloatRect(0, 50, 10000, 350));
    std::list<Object*> visibleObjects;
    for(int i = 0; i < objectsQuantity;++i)
    {
        visibleObjects.push_back(new Platform(sf::Vector2f(mapObjects[i].startX, mapObjects[i].startY),
            sf::Vector2f(mapObjects[i].endX, mapObjects[i].endY)));
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        camera.update();
        player.update(visibleObjects);
        window.setView(camera.getView());
        window.clear();
        window.draw(player.getSprite());
        for(auto obj : visibleObjects)
        {
            player.collide(obj);
            window.draw(obj->getSprite());
        }
        window.display();
    }

    return 0;
}